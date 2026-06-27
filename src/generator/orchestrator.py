import concurrent.futures
import queue
import re
import signal
import threading
import time
from dataclasses import dataclass, field
from pathlib import Path
from typing import Callable, TypeVar

from pydantic import ValidationError
from rich.console import Console
from rich.progress import (
    BarColumn,
    MofNCompleteColumn,
    Progress,
    SpinnerColumn,
    TaskProgressColumn,
    TextColumn,
    TimeElapsedColumn,
    TimeRemainingColumn,
)

from chunker import Chunk, DynamicTaskScheduler
from generator.build import BuildFailure, analyze_build_failure, run_build
from generator.cache import GenerationCache
from generator.console import (
    console,
    show_build_failure,
    show_build_success,
    show_info,
    show_warning,
)
from generator.llm import LLMConfig, Translator
from generator.merged_output import MergedOutput
from generator.prompts import build_user_prompt, load_system_prompt
from generator.schema import Generate, GenerateWithClass
from generator.utils import chunk_hash, filter_chunks, get_chunk_label
from generator.worker_msg import WorkerOutput
from generator.worktree import WorktreeManager
from generator.writer import GeneratedFiles, WrapperWriter

T = TypeVar("T")


class ErrorContainer:
    """Container to hold exception reference for shared access across threads."""

    def __init__(self):
        self.error: Exception | None = None
        self.cancelled: bool = False


@dataclass(frozen=True, slots=True)
class GenerationConfig:
    output_dir: Path
    include_patterns: list[str]
    exclude_patterns: list[str]
    stream_output: bool
    llm: LLMConfig
    header_files: list[Path] = field(default_factory=list)
    build_after_each_chunk: bool = True
    chunk_retry_limit: int = 10
    build_timeout_seconds: int = 600
    validate_command: str = (
        '/usr/bin/env bash -c "GODOT_VERSION=system ./validate.sh <ERROR_FILE>"'
    )
    use_cache: bool = True
    skip_failed_chunks: bool = False
    workers: int = 1
    skip_build_verification_on_cache_restore: bool = False


@dataclass(frozen=True, slots=True)
class _ChunkState:
    chunk: Chunk
    output: Generate
    scope: str | None
    # condition_directive and condition_expression are now stored inside the output items directly.


def _process_chunk_with_retries(
    worktree_path: Path,
    *,
    config: GenerationConfig,
    translator: Translator,
    writer: WrapperWriter,
    states: list[_ChunkState],
    chunk: Chunk,
    chunk_index: int,
    total_chunks: int,
    successful_chunk_hashes: set[str],
    merged_output: MergedOutput,
    wrapper_class_name: str | None = None,
    cache: "GenerationCache | None" = None,
    console: "Console | None" = None,
    global_lock: "threading.Lock | None" = None,
    error_container: "ErrorContainer | None" = None,
) -> None:
    last_build_failure: BuildFailure | None = None
    translator._chunk_label = get_chunk_label(chunk)[:60]

    for attempt in range(1, config.chunk_retry_limit + 1):
        # Check for cancellation at the start of each retry attempt
        if error_container and error_container.cancelled:
            return

        try:
            # Check for cancellation before translation
            if error_container and error_container.cancelled:
                return
            # On first attempt, do full translation with reasoning. On retries, just regenerate JSON from error feedback.
            if attempt == 1:
                prompt = build_user_prompt(chunk, wrapper_class_name=wrapper_class_name)
                # Set chunk label in translator for message headers
                generated = translator.translate(prompt)
            else:
                # Retry: regenerate JSON based on error feedback already in conversation history
                generated = translator.regenerate_json()
        except (ValidationError, ValueError):
            if config.skip_failed_chunks:
                if console:
                    console.print(
                        f"⊘ Chunk {chunk_index + 1}/{total_chunks} [{translator._chunk_label}] failed to parse; skipping",
                        style="yellow",
                    )
                else:
                    show_warning(
                        f"Chunk {chunk_index + 1}/{total_chunks} [{translator._chunk_label}] failed to parse; skipping"
                    )
                return
            raise

        trial_states = list(states)
        trial_states.append(
            _ChunkState(
                chunk=chunk,
                output=generated,
                scope=chunk.scope,
            )
        )
        _write_intermediate(writer, trial_states, merged_output)

        if not config.build_after_each_chunk:
            _finalize_chunk_generation(
                states,
                chunk,
                generated,
                successful_chunk_hashes,
                cache,
                global_lock,
            )
            return

        # Create error file for this build attempt
        error_file = worktree_path / f".build_errors_{attempt}.txt"
        # Check for cancellation before build
        if error_container and error_container.cancelled:
            return
        build_result = run_build(
            worktree_path,
            config.validate_command,
            config.build_timeout_seconds,
            error_file,
        )
        if error_container and error_container.cancelled:
            return
        if build_result.success:
            translator.append_tool_result("build", True, "")
            chunk_label = get_chunk_label(chunk)[:60]
            show_build_success(chunk_label=chunk_label)
            _finalize_chunk_generation(
                states, chunk, generated, successful_chunk_hashes, cache, None
            )
            return

        last_build_failure = analyze_build_failure(error_file)
        error_feedback = last_build_failure.feedback_for_llm()
        translator.append_tool_result("build", False, error_feedback)
        chunk_label = get_chunk_label(chunk)[:60]
        show_build_failure(
            attempt, config.chunk_retry_limit, error_feedback, chunk_label=chunk_label
        )

    if _retry_previous_chunk_if_unique_match(
        worktree_path,
        config=config,
        translator=translator,
        writer=writer,
        states=states,
        failing_chunk=chunk,
        build_failure=last_build_failure,
        total_chunks=total_chunks,
        successful_chunk_hashes=successful_chunk_hashes,
        merged_output=merged_output,
        cache=cache,
        console=console,
    ):
        return

    if config.skip_failed_chunks:
        if console:
            console.print(
                f"⊘ Chunk {chunk_index + 1}/{total_chunks} failed; skipping",
                style="yellow",
            )
        else:
            chunk_label = get_chunk_label(chunk)[:60]
            show_warning(
                f"Chunk {chunk_index + 1}/{total_chunks} [{chunk_label}] failed after all retries; skipping"
            )
        return

    details = (
        last_build_failure.feedback_for_llm()
        if last_build_failure
        else "No build error details found."
    )
    error_msg = (
        f"Unable to generate a buildable result for chunk {chunk_index + 1}/{total_chunks} "
        f"after {config.chunk_retry_limit} attempts.\n\n{details}"
    )
    if console:
        console.print(f"✗ {error_msg.split(chr(10))[0]}", style="red bold")
    raise RuntimeError(error_msg)


def _finalize_chunk_generation(
    states: list[_ChunkState],
    chunk: Chunk,
    generated: Generate,
    successful_chunk_hashes: set[str],
    cache: "GenerationCache | None" = None,
    global_lock: "threading.Lock | None" = None,
) -> None:
    """Finalize chunk generation by adding to states, hashing, and caching."""
    states.append(
        _ChunkState(
            chunk=chunk,
            output=generated,
            scope=chunk.scope,
        )
    )
    chunk_hash_val = chunk_hash(chunk)
    successful_chunk_hashes.add(chunk_hash_val)
    if cache:
        cache.add_successful_chunk(chunk_hash_val, generated)


def _retry_previous_chunk_if_unique_match(
    worktree_path: Path,
    *,
    config: GenerationConfig,
    translator: Translator,
    writer: WrapperWriter,
    states: list[_ChunkState],
    failing_chunk: Chunk,
    build_failure: "BuildFailure | None",
    total_chunks: int,
    successful_chunk_hashes: set[str],
    merged_output: MergedOutput,
    cache: "GenerationCache | None" = None,
    console: "Console | None" = None,
) -> bool:
    if not states or build_failure is None:
        return False

    candidate = build_failure.first_symbol_candidate()
    if not candidate:
        return False

    regex = re.compile(rf"\b{re.escape(candidate)}\b")
    matches = [i for i, s in enumerate(states) if regex.search(s.chunk.code)]
    if len(matches) != 1:
        return False

    target_idx = matches[0]
    target_state = states[target_idx]
    feedback = build_failure.feedback_for_llm()

    if console:
        console.print(
            f"↻ Retrying chunk {target_idx + 1}/{total_chunks} (symbol: {candidate})",
            style="yellow",
        )
    else:
        target_chunk_label = get_chunk_label(failing_chunk)[:60]
        show_warning(
            f"Retrying previously generated chunk {target_idx + 1}/{total_chunks} [{target_chunk_label}] "
            f"due to unique symbol match: {candidate}"
        )

    def on_first_attempt() -> None:
        translator.append_tool_result(
            "analyze",
            True,
            f"Symbol '{candidate}' is unique source of build failure.\n\n{feedback}",
        )

    return _attempt_chunk_regeneration(
        worktree_path,
        config=config,
        translator=translator,
        writer=writer,
        states=states,
        target_idx=target_idx,
        target_state=target_state,
        successful_chunk_hashes=successful_chunk_hashes,
        merged_output=merged_output,
        cache=cache,
        on_first_attempt=on_first_attempt,
    )


def _attempt_chunk_regeneration(
    worktree_path: Path,
    *,
    config: GenerationConfig,
    translator: Translator,
    writer: WrapperWriter,
    states: list[_ChunkState],
    target_idx: int,
    target_state: _ChunkState,
    successful_chunk_hashes: set[str],
    merged_output: MergedOutput,
    cache: "GenerationCache | None" = None,
    on_first_attempt: Callable[[], None] | None = None,
) -> bool:
    """Common logic for regenerating a chunk and retrying the build.

    Returns True if the build succeeds, False otherwise.
    """
    for attempt in range(1, config.chunk_retry_limit + 1):
        if attempt == 1 and on_first_attempt:
            on_first_attempt()

        prompt = build_user_prompt(target_state.chunk)
        regenerated = translator.translate(prompt)

        trial_states = list(states)
        trial_states[target_idx] = _ChunkState(
            chunk=target_state.chunk,
            output=regenerated,
            scope=target_state.scope,
        )

        _write_intermediate(writer, trial_states, merged_output)

        error_file = worktree_path / ".build_errors_retry.txt"
        build_result = run_build(
            worktree_path,
            config.validate_command,
            config.build_timeout_seconds,
            error_file,
        )
        if build_result.success:
            translator.append_tool_result("build", True, "")
            states[target_idx] = trial_states[target_idx]
            chunk_hash_val = chunk_hash(target_state.chunk)
            successful_chunk_hashes.add(chunk_hash_val)
            if cache:
                cache.add_successful_chunk(chunk_hash_val, regenerated)
            return True

        build_failure = analyze_build_failure(error_file)
        translator.append_feedback(
            "The build failed: focus on fixing or working around the build errors from the previous attempt before continuing."
        )
        feedback = build_failure.feedback_for_llm()
        translator.append_tool_result("build", False, feedback)

    return False


def _write_intermediate(
    writer: "WrapperWriter", states: list[_ChunkState], merged_output: MergedOutput
) -> None:
    outputs: list[GenerateWithClass] = []
    for state in states:
        output = GenerateWithClass.from_generate(
            state.output,
            scope=state.scope,
            header_include=state.chunk.header_include,
        )
        outputs.append(output)

    merged = merged_output.get_merged_with_class(outputs)
    writer.write(merged)


def generate_wrappers_from_chunks_with_scheduler(
    config: GenerationConfig,
    chunks: list[Chunk],
    scheduler: DynamicTaskScheduler,
) -> GeneratedFiles:
    filtered = filter_chunks(chunks, config.include_patterns, config.exclude_patterns)
    if not filtered:
        raise ValueError("No chunks matched the current filters")

    show_info(f"Processing {len(filtered)} chunks with {config.workers} workers")

    cache = GenerationCache(config.output_dir) if config.use_cache else None

    total_chunks = len(filtered)

    main_translator = Translator(
        config=config.llm,
        system_prompt=load_system_prompt(),
        header_files=config.header_files,
        output_dir=config.output_dir,
        show_console_output=config.stream_output,
        workers=config.workers,
    )
    main_translator.clear_history()

    # Derive wrapper class name early so we can pass it to the LLM
    from generator.writer import derive_class_name

    wrapper_class_name = derive_class_name(config.header_files)

    wt_manager = WorktreeManager(config.output_dir, config.workers)
    merged_output = MergedOutput(
        config.output_dir, wt_manager.copy_lock, config.header_files
    )

    worker_indices = queue.Queue()
    for i in range(config.workers):
        worker_indices.put(i)

    global_lock = threading.Lock()

    def process_chunk(chunk_idx: int):
        chunk = filtered[chunk_idx]
        chunk_hash_val = chunk_hash(chunk)
        chunk_label = get_chunk_label(chunk)[:60]
        worker_idx = worker_indices.get()

        local_cache = cache
        conflict_feedback = None

        try:
            while True:
                # Check if an error has already occurred or cancellation requested - exit immediately
                if error_container.error is not None or error_container.cancelled:
                    with global_lock:
                        scheduler.mark_complete(chunk_idx)
                        progress.update(task, advance=1)
                    return

                with global_lock:
                    completed, _ = scheduler.get_progress()
                    processed_count = completed + 1
                    show_info(
                        f"[{processed_count}/{total_chunks}] Generating chunk: {chunk_label}..."
                    )

                added_hashes = []
                used_cache = False
                all_from_cache = False

                # Check cache first
                if local_cache:
                    cached = local_cache.get_generate_for_hash(chunk_hash_val)
                    if cached:
                        output = GenerateWithClass.from_generate(
                            cached,
                            scope=chunk.scope,
                            header_include=chunk.header_include,
                        )
                        merged_output.add(
                            WorkerOutput(
                                chunk_hash=chunk_hash_val,
                                generated=output,
                                build_success=True,
                            )
                        )
                        added_hashes.append(chunk_hash_val)
                        used_cache = True
                        all_from_cache = True

                if not used_cache:
                    # Use retry logic for generation with builds
                    states: list[_ChunkState] = []
                    successful_chunk_hashes: set[str] = set()

                    with wt_manager.run_task(worker_idx) as worktree_path:
                        writer = WrapperWriter(worktree_path, config.header_files)
                        # Create translator for this chunk with history from main
                        translator = Translator(
                            config=config.llm,
                            system_prompt=load_system_prompt(),
                            header_files=config.header_files,
                            output_dir=config.output_dir,
                            show_console_output=config.stream_output,
                            workers=config.workers,
                        )
                        with global_lock:
                            translator._message_history = list(
                                main_translator._message_history
                            )

                        if conflict_feedback:
                            translator.append_feedback(conflict_feedback)

                        # Process with retries
                        _process_chunk_with_retries(
                            worktree_path,
                            config=config,
                            translator=translator,
                            writer=writer,
                            states=states,
                            chunk=chunk,
                            chunk_index=chunk_idx,
                            total_chunks=total_chunks,
                            successful_chunk_hashes=successful_chunk_hashes,
                            merged_output=merged_output,
                            wrapper_class_name=wrapper_class_name,
                            cache=cache,
                            console=None,
                            global_lock=global_lock,
                            error_container=error_container,
                        )

                    # Add successful outputs to merged results
                    # Skip merging if cancellation was requested
                    if not (error_container and error_container.cancelled):
                        for state in states:
                            output = GenerateWithClass.from_generate(
                                state.output,
                                scope=state.scope,
                                header_include=state.chunk.header_include,
                            )
                            h = chunk_hash(state.chunk)
                            merged_output.add(
                                WorkerOutput(
                                    chunk_hash=h,
                                    generated=output,
                                    build_success=True,
                                )
                            )
                            added_hashes.append(h)

                        merged_output.write()

                # Skip verification build if all chunks are from cache and flag is set
                if all_from_cache and config.skip_build_verification_on_cache_restore:
                    break  # Trust the cache, proceed to next chunk

                # Check for cancellation before verification build
                if error_container and error_container.cancelled:
                    break

                # Verify the final merge with a build
                with wt_manager.run_task(worker_idx) as worktree_path:
                    writer = WrapperWriter(worktree_path, config.header_files)
                    writer.write(merged_output.get_merged_with_class())
                    error_file = worktree_path / ".build_errors_final.txt"
                    build_result = run_build(
                        worktree_path,
                        config.validate_command,
                        config.build_timeout_seconds,
                        error_file,
                    )

                    if build_result.success:
                        break  # Merge is good!

                    # Build failed after merge. There's a conflict!
                    build_failure = analyze_build_failure(error_file)
                    conflict_feedback = (
                        "The generated chunk caused a build conflict when merged with previously "
                        "generated wrappers. Please resolve the conflict based on the following "
                        f"compiler errors:\n\n{build_failure.feedback_for_llm()}"
                    )

                    # Remove what we added and retry generation (without cache this time)
                    for h in added_hashes:
                        merged_output.remove(h)

                    # Revert the output directory to its clean state before we try again
                    merged_output.write()

                    local_cache = None  # Force generation with full context on retry

                    if config.stream_output:
                        show_warning(
                            f"Conflict detected after merging chunk {chunk_idx + 1} [{chunk_label}]. Retrying...\n{conflict_feedback}"
                        )

            with global_lock:
                scheduler.mark_complete(chunk_idx)
                progress.update(task, advance=1)

        except Exception as e:
            # Store error and signal other workers to stop
            with global_lock:
                if error_container.error is None:
                    error_container.error = e
                scheduler.mark_complete(chunk_idx)
                progress.update(task, advance=1)
            raise
        finally:
            worker_indices.put(worker_idx)

    progress = Progress(
        SpinnerColumn(),  # Animated spinner
        TextColumn("[progress.description]{task.description}"),
        BarColumn(bar_width=None),  # Full-width bar
        TaskProgressColumn(),  # Percentage (e.g., 50%)
        MofNCompleteColumn(),  # Steps completed (e.g., 5/10)
        "•",
        TimeElapsedColumn(),  # Time since start
        TimeRemainingColumn(),  # Estimated time left
        console=console,
    )
    with progress:
        task = progress.add_task("[cyan]Generating code...", total=total_chunks)

        # Shared container to store first error for fail-fast
        error_container = ErrorContainer()

        def handle_interrupt(signum, frame):
            """Signal handler for aggressive cancellation."""
            if not error_container.cancelled:
                error_container.cancelled = True
                show_warning("\nCancellation requested...")
            else:
                # If already cancelled and user pressed Ctrl+C again, exit immediately
                import os

                os._exit(130)

        # Set up signal handler for Ctrl+C
        original_handler = signal.signal(signal.SIGINT, handle_interrupt)

        try:
            with concurrent.futures.ThreadPoolExecutor(
                max_workers=config.workers
            ) as executor:
                futures = []
                submitted_tasks: set[int] = (
                    set()
                )  # Track submitted tasks to prevent duplicates

                try:
                    while not scheduler.is_complete():
                        ready_chunks = []
                        with global_lock:
                            # Check for cancellation or error before scheduling new tasks
                            if (
                                error_container.error is not None
                                or error_container.cancelled
                            ):
                                break

                            ready_chunks = scheduler.get_ready_tasks()

                            for chunk_idx in ready_chunks:
                                # Only submit if not already submitted (prevents race condition duplicates)
                                if chunk_idx not in submitted_tasks:
                                    scheduler.mark_in_progress(chunk_idx)
                                    submitted_tasks.add(chunk_idx)
                                    futures.append(
                                        executor.submit(process_chunk, chunk_idx)
                                    )

                        if not ready_chunks:
                            with global_lock:
                                stats = scheduler.get_status_summary()
                            if stats["pending"] > 0 and stats["in_progress"] == 0:
                                raise ValueError(
                                    "Deadlock: tasks pending but none ready"
                                )
                            time.sleep(0.1)

                    # If cancellation was requested, don't wait for futures - cancel immediately
                    if error_container.cancelled:
                        raise KeyboardInterrupt("User requested cancellation")

                    # Wait for all futures, but stop on first error
                    for future in concurrent.futures.as_completed(futures):
                        try:
                            future.result()
                        except Exception:
                            pass  # Error already captured in error_container.error

                    # If an error occurred, raise it to stop processing
                    if error_container.error is not None:
                        raise error_container.error
                finally:
                    # Ensure executor shuts down without waiting for threads
                    executor.shutdown(wait=False)
        finally:
            # Restore original signal handler
            signal.signal(signal.SIGINT, original_handler)

    if not error_container.cancelled:
        generated = merged_output.write()
        return generated
    else:
        raise KeyboardInterrupt("Generation cancelled by user")
