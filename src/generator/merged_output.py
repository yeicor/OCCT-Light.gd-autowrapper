"""Minimal merged writer - single lock, accumulate outputs, write once."""

import threading
from pathlib import Path

from generator.schema import GenerateWithClass
from generator.worker_msg import WorkerOutput
from generator.writer import GeneratedFiles, WrapperWriter


class MergedOutput:
    """Thread-safe accumulator for worker outputs."""

    def __init__(
        self,
        output_dir: Path,
        copy_lock: threading.Lock,
        header_files: list[Path] | None = None,
    ):
        self.lock = threading.RLock()
        self.outputs: dict[str, GenerateWithClass] = {}
        self.output_dir = output_dir
        self.copy_lock = copy_lock
        self.header_files = header_files or []

    def add(self, worker_output: WorkerOutput) -> None:
        """Thread-safe: add worker output (dedup by hash)."""
        with self.lock:
            if worker_output.chunk_hash not in self.outputs:
                self.outputs[worker_output.chunk_hash] = worker_output.generated

    def remove(self, chunk_hash: str) -> None:
        """Thread-safe: remove worker output."""
        with self.lock:
            self.outputs.pop(chunk_hash, None)

    def get_hashes(self) -> set[str]:
        """Thread-safe: get all seen chunk hashes."""
        with self.lock:
            return set(self.outputs.keys())

    def get_merged_with_class(
        self, extra_outputs: list[GenerateWithClass] | None = None
    ) -> GenerateWithClass:
        """Get merged output, optionally including extra outputs (e.g. from current worker)."""
        with self.lock:
            merged_items = []
            for output in self.outputs.values():
                merged_items.extend(output.to_generate)

            if extra_outputs:
                for ext in extra_outputs:
                    merged_items.extend(ext.to_generate)

            return GenerateWithClass(to_generate=merged_items)

    def write(self) -> GeneratedFiles:
        """Write all accumulated outputs to files while holding the copy lock.

        This serializes writes with worktree copies to prevent race conditions
        where files are being removed while workers are copying them.

        Returns the GeneratedFiles with paths and counts.
        """
        with self.copy_lock:
            with self.lock:
                merged = self.get_merged_with_class()
                writer = WrapperWriter(self.output_dir, self.header_files)
                return writer.write(merged)
