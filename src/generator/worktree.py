"""Worktree manager - one-way fresh copy, no sync back."""

import shutil
import threading
import time
from contextlib import contextmanager
from pathlib import Path
from typing import Iterator


class WorktreeManager:
    """Isolated worktrees for parallel workers - one-way copy only (no sync back)."""

    def __init__(self, output_dir: str | Path, num_workers: int):
        self.output_dir = Path(output_dir).resolve()
        self.base_dir = self.output_dir / ".autowrapper"
        self.num_workers = num_workers
        self.lock = threading.Lock()
        self.copy_lock = threading.Lock()  # Separate lock for source directory reads
        self.base_dir.mkdir(parents=True, exist_ok=True)
        for i in range(num_workers):
            (self.base_dir / f"wt{i}").mkdir(exist_ok=True)

    @contextmanager
    def run_task(self, worker_index: int) -> Iterator[Path]:
        """Get fresh worktree with one-way copy (no sync back)."""
        if not (0 <= worker_index < self.num_workers):
            raise ValueError(f"Invalid worker index {worker_index}")

        wt_path = self.base_dir / f"wt{worker_index}"

        # Fresh copy from main (one-way only)
        with self.lock:
            if wt_path.exists():
                shutil.rmtree(wt_path)
            wt_path.mkdir(parents=True, exist_ok=True)

        def ignore_patterns(directory, contents):
            ignored = set()
            gitignore_path = Path(directory) / ".gitignore"
            if gitignore_path.exists():
                with open(gitignore_path) as f:
                    for line in f:
                        line = line.strip()
                        if line and not line.startswith("#"):
                            ignored.add(line)
            ignored.add(".autowrapper")
            for name in contents:
                if name.startswith(".") or name in ignored:
                    ignored.add(name)
            return ignored

        # Lock the source directory while copying to prevent race conditions
        # where files are being added/removed during copy
        max_retries = 3
        retry_count = 0
        last_error = None

        while retry_count < max_retries:
            try:
                with self.copy_lock:
                    # Use dirs_exist_ok=True since we created the directory above
                    shutil.copytree(
                        self.output_dir,
                        wt_path,
                        ignore=ignore_patterns,
                        dirs_exist_ok=True,
                    )
                # Success - break out of retry loop
                break
            except (FileNotFoundError, OSError) as e:
                last_error = e
                retry_count += 1
                if retry_count < max_retries:
                    # Clear the partial copy and try again
                    try:
                        shutil.rmtree(wt_path)
                        wt_path.mkdir(parents=True, exist_ok=True)
                    except Exception:
                        pass
                    # Small delay before retry to let source directory stabilize
                    time.sleep(0.01 * retry_count)
                else:
                    # All retries exhausted - raise the error
                    raise last_error from e

        try:
            yield wt_path
        finally:
            # NO sync back - worker returns data, not files
            pass
