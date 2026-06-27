from dataclasses import dataclass, field
from pathlib import Path
from typing import Optional


@dataclass(frozen=True, slots=True)
class Chunk:
    """A code chunk extracted from a source file with scope information."""

    index: int
    code: str
    scope: Optional[str] = None
    file: Optional[Path] = None
    header_include: Optional[str] = None

    @property
    def annotated(self) -> str:
        """Get the chunk code with metadata comments."""
        scope = f"class/struct {self.scope}" if self.scope else "global scope"
        lines = [
            f"// <wrapping_helper>This code chunk belongs to {scope}</wrapping_helper>"
        ]
        lines.append(self.code)
        return "\n".join(lines)


@dataclass
class ChunkDependencies:
    """Tracks symbol dependencies between chunks."""

    chunk_id: int
    declared_symbols: set[str] = field(default_factory=set)
    used_symbols: set[str] = field(default_factory=set)
    depends_on_chunks: set[int] = field(default_factory=set)
    depended_by_chunks: set[int] = field(default_factory=set)


@dataclass
class DependencyGraph:
    """DAG of chunk dependencies for parallelization."""

    chunks: list[Chunk]
    dependencies: dict[int, ChunkDependencies] = field(default_factory=dict)
    file_dependencies: dict[Path, set[Path]] = field(default_factory=dict)
    ignored_cycles: set[tuple[int, int]] = field(default_factory=set)

    def __post_init__(self) -> None:
        """Initialize dependency tracking for all chunks."""
        for chunk in self.chunks:
            if chunk.index not in self.dependencies:
                self.dependencies[chunk.index] = ChunkDependencies(chunk_id=chunk.index)

    def add_symbol_dependency(self, from_chunk_id: int, to_chunk_id: int) -> None:
        """
        Add a dependency edge from one chunk to another.

        Gracefully handles cycles by detecting them and skipping the edge
        that would create the cycle, while still tracking that a cycle was found.
        This prevents false negatives while avoiding circular dependencies.
        """
        if from_chunk_id == to_chunk_id:
            return

        # Check if adding this edge would create a cycle
        # A cycle would exist if to_chunk_id can already reach from_chunk_id
        if self._would_create_cycle(from_chunk_id, to_chunk_id):
            # Record that we ignored a cycle edge
            self.ignored_cycles.add((from_chunk_id, to_chunk_id))
            return

        # Safe to add the edge
        self.dependencies[from_chunk_id].depends_on_chunks.add(to_chunk_id)
        self.dependencies[to_chunk_id].depended_by_chunks.add(from_chunk_id)

    def _would_create_cycle(self, from_chunk_id: int, to_chunk_id: int) -> bool:
        """
        Check if adding edge from->to would create a cycle.

        This does a DFS from to_chunk_id to see if it can reach from_chunk_id.
        If it can, adding from->to would create a cycle.
        """
        visited: set[int] = set()

        def can_reach(start: int, target: int) -> bool:
            if start == target:
                return True
            if start in visited:
                return False
            visited.add(start)
            for dep in self.dependencies[start].depends_on_chunks:
                if can_reach(dep, target):
                    return True
            return False

        return can_reach(to_chunk_id, from_chunk_id)

    def has_cycles(self) -> bool:
        """Check if any cycles were detected during graph construction."""
        return len(self.ignored_cycles) > 0

    def add_file_dependency(self, from_file: Path, to_file: Path) -> None:
        """Add a file-level dependency (e.g., from includes)."""
        if from_file not in self.file_dependencies:
            self.file_dependencies[from_file] = set()
        self.file_dependencies[from_file].add(to_file)

    def get_chunk_dependencies(self, chunk_id: int) -> set[int]:
        """Get all chunks that a given chunk depends on."""
        return self.dependencies[chunk_id].depends_on_chunks.copy()

    def topological_order(self) -> list[int]:
        """Return chunk IDs in topological order for sequential processing."""
        visited: set[int] = set()
        order: list[int] = []

        def visit(chunk_id: int) -> None:
            if chunk_id in visited:
                return
            visited.add(chunk_id)
            for dep in self.dependencies[chunk_id].depends_on_chunks:
                visit(dep)
            order.append(chunk_id)

        for chunk_id in range(len(self.chunks)):
            visit(chunk_id)
        return order
