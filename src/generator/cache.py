import json
import threading
from pathlib import Path

from generator.console import show_warning
from generator.schema import Generate


class GenerationCache:
    """Manages caching of generated chunks to avoid regeneration."""

    def __init__(self, output_dir: Path):
        self.cache_file = output_dir / "src" / "autowrapper" / ".autowrapper_cache.json"
        self._data: dict[str, dict] = {}
        self._lock = threading.Lock()
        self._load()

    def _load(self) -> None:
        """Load cache from disk if it exists."""
        if not self.cache_file.exists():
            return
        try:
            content = self.cache_file.read_text(encoding="utf-8")
            self._data = json.loads(content)
        except (OSError, json.JSONDecodeError):
            self._data = {}

    def get_cached_hashes(self) -> set[str]:
        """Get set of chunk hashes that are cached."""
        with self._lock:
            return set(self._data.keys())

    def get_generate_for_hash(self, chunk_hash: str) -> Generate | None:
        """Get cached Generate object for a chunk hash."""
        with self._lock:
            if chunk_hash not in self._data:
                return None
            data = self._data[chunk_hash]

        try:
            return Generate.model_validate(data)
        except Exception as e:
            show_warning(f"Failed to deserialize cached Generate for {chunk_hash}: {e}")
            return None

    def add_successful_chunk(self, chunk_hash: str, generate: Generate) -> None:
        """Mark a chunk as successfully generated."""
        with self._lock:
            self._data[chunk_hash] = generate.model_dump()
            self._save_unlocked()

    def save(self) -> None:
        """Persist cache to disk."""
        with self._lock:
            self._save_unlocked()

    def _save_unlocked(self) -> None:
        self.cache_file.parent.mkdir(parents=True, exist_ok=True)
        try:
            self.cache_file.write_text(
                json.dumps(self._data, indent=2), encoding="utf-8"
            )
        except OSError:
            show_warning(f"Failed to save cache file: {self.cache_file}")
