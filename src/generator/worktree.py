"""Worktree manager - uses main output dir directly for CMake-based projects.

CMake stores absolute SOURCE_PATH at configure time, so copying to a worktree
directory has no effect — the build always looks at the original source paths.
Instead of an expensive (and useless) copy, this returns the real output
directory so that generated files are written directly where the build expects
them.
"""

import threading
from contextlib import contextmanager
from pathlib import Path
from typing import Iterator


class WorktreeManager:
    """Worktree manager that uses the main output dir directly.

    For CMake-based projects the worktree copy is wasteful because CMake bakes
    absolute paths at configure time.  Generated files are written directly to
    *output_dir* / ``src/autowrapper/``, which is exactly where the build looks
    for them.
    """

    def __init__(self, output_dir: str | Path, num_workers: int):
        self.output_dir = Path(output_dir).resolve()
        self.copy_lock = threading.Lock()  # Kept for API compatibility

    @contextmanager
    def run_task(self, worker_index: int) -> Iterator[Path]:
        """Yield the main output directory directly (no copy)."""
        # Ensure the autowrapper output directory exists
        (self.output_dir / "src" / "autowrapper").mkdir(parents=True, exist_ok=True)
        (self.output_dir / "doc_classes" / "autowrapper").mkdir(
            parents=True, exist_ok=True
        )
        (self.output_dir / "demo" / "tests").mkdir(parents=True, exist_ok=True)
        yield self.output_dir
