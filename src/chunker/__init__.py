"""
Chunker module for extracting and analyzing code chunks with dependency tracking.

This module provides functionality to:
1. Extract code chunks from header files
2. Identify symbol dependencies (declarations and usages)
3. Track file-level dependencies from #include directives
4. Build a DAG for potential parallelization
5. Generate statistics and visualizations
6. Schedule dynamic parallel processing while respecting dependencies
"""

from .chunk import Chunk, ChunkDependencies, DependencyGraph
from .core import build_dependency_graph, extract_chunks_with_deps
from .includes import build_file_include_graph, extract_includes
from .parallel import DynamicTaskScheduler, RoundRobinWorkQueue
from .stats import (
    DAGStats,
    analyze_parallelizability,
    compute_stats,
    print_dependency_report,
    print_parallelization_analysis,
    save_graphviz,
    save_mermaid,
    to_graphviz_dot,
    to_mermaid,
)
from .symbols import walk_and_collect_symbols

__all__ = [
    "Chunk",
    "ChunkDependencies",
    "DependencyGraph",
    "DAGStats",
    "DynamicTaskScheduler",
    "RoundRobinWorkQueue",
    "extract_chunks_with_deps",
    "build_dependency_graph",
    "build_file_include_graph",
    "extract_includes",
    "walk_and_collect_symbols",
    "compute_stats",
    "print_dependency_report",
    "print_parallelization_analysis",
    "analyze_parallelizability",
    "to_mermaid",
    "to_graphviz_dot",
    "save_mermaid",
    "save_graphviz",
]


def extract_chunks(header, max_chunk_bytes=4000):
    """
    Extract chunks from a header file (backward compatible API).

    This is a simple wrapper that maintains backward compatibility with the
    previous chunker.py module API.
    """
    chunks, _ = extract_chunks_with_deps(header, max_chunk_bytes)
    return chunks
