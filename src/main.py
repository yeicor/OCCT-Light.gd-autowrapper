import os
import sys
from pathlib import Path

import typer
from rich.progress import track

from chunker import (
    DynamicTaskScheduler,
    build_dependency_graph,
    extract_chunks_with_deps,
)
from generator.console import console, show_warning
from generator.llm import LLMConfig
from generator.orchestrator import (
    GenerationConfig,
    generate_wrappers_from_chunks_with_scheduler,
)


def main(
    header_globs: list[str] = typer.Argument(
        ...,
        help="One or more header file globs to process together.",
    ),
    output_dir: Path = typer.Option(
        Path("generated"), "--output", "-o", resolve_path=True
    ),
    include: list[str] | None = typer.Option(None, "--include"),
    exclude: list[str] | None = typer.Option(None, "--exclude"),
    max_chunk_bytes: int = typer.Option(26000, "--max-chunk-bytes", min=1000),
    model: str = typer.Option(
        os.getenv(
            "WRAPPER_MODEL",
            "Jackrong/Qwen3.5-9B-Claude-4.6-Opus-Reasoning-Distilled-GGUF:Q4_K_M",
        ),
        "--model",
    ),
    base_url: str = typer.Option(
        os.getenv("OPENAI_BASE_URL", "http://localhost:8080/v1"), "--base-url"
    ),
    api_key: str = typer.Option(os.getenv("OPENAI_API_KEY", "none"), "--api-key"),
    temperature: float = typer.Option(1.0, "--temperature", min=0.0, max=2.0),
    max_output_tokens: int = typer.Option(25000, "--max-output-tokens", min=1000),
    max_history_bytes: int = typer.Option(50000 * 3, "--max-history-bytes", min=10000),
    reasoning_timeout_seconds: float = typer.Option(
        300.0, "--reasoning-timeout", min=1.0
    ),
    stream_output: bool = typer.Option(True, "--stream/--no-stream"),
    workers: int = typer.Option(
        min(4, os.cpu_count() or 1),
        "--workers",
        "-w",
        help="Number of parallel workers",
    ),
    skip_build_verification_on_cache: bool = typer.Option(
        True,
        "--skip-build-verification-on-cache/--no-skip-build-verification-on-cache",
        help="Skip final build verification when restoring from cache (assume cache was already validated)",
    ),
) -> None:
    """Process header files and generate Godot C++ wrappers using dynamic scheduling."""
    if not header_globs:
        raise typer.BadParameter("At least one header glob is required.")

    # Expand all glob patterns into concrete file paths
    all_header_files: list[Path] = []
    for glob_pattern in header_globs:
        pattern_path = Path(glob_pattern)
        if pattern_path.is_file():
            all_header_files.append(pattern_path.resolve())
            continue

        matches = sorted(Path().glob(glob_pattern))
        if not matches:
            raise typer.BadParameter(f"No headers matched for pattern: {glob_pattern}")

        for match in matches:
            if match.is_file():
                all_header_files.append(match.resolve())

    if not all_header_files:
        raise typer.BadParameter("No header files matched the provided patterns.")

    llm_config = LLMConfig(
        model=model,
        base_url=base_url,
        api_key=api_key,
        temperature=temperature,
        max_completion_tokens=max_output_tokens,
        max_history_bytes=max_history_bytes
        - max_output_tokens * 4,  # rough token to byte estimate
        reasoning_timeout_seconds=reasoning_timeout_seconds,
    )

    # Extract all chunks from all header files
    all_chunks = []
    for header_file in track(
        all_header_files,
        description="Extracting chunks from headers...",
        console=console,
    ):
        chunks, _ = extract_chunks_with_deps(
            header_file, max_chunk_bytes=max_chunk_bytes
        )
        all_chunks.extend(chunks)

    if not all_chunks:
        raise ValueError("No chunks extracted from any headers")

    # Build dependency graph
    dependency_graph = build_dependency_graph(all_chunks, all_header_files)

    # Create scheduler
    chunk_ids = list(range(len(all_chunks)))
    scheduler = DynamicTaskScheduler(chunk_ids, dependency_graph)

    # Create configuration
    config = GenerationConfig(
        output_dir=output_dir,
        include_patterns=include or [],
        exclude_patterns=exclude or [],
        stream_output=stream_output,
        llm=llm_config,
        header_files=all_header_files,
        workers=workers,
        skip_build_verification_on_cache_restore=skip_build_verification_on_cache,
    )

    # Process chunks through scheduler
    try:
        _generated = generate_wrappers_from_chunks_with_scheduler(
            config, all_chunks, scheduler
        )
    except KeyboardInterrupt:
        show_warning("\nGeneration cancelled by user.")
        sys.exit(130)  # Standard exit code for SIGINT


if __name__ == "__main__":
    typer.run(main)
