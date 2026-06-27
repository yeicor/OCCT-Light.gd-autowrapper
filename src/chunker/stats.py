"""
DAG statistics and visualization module.

Provides analysis of chunk dependencies to evaluate parallelizability
and generate visualizations (Mermaid, Graphviz DOT).
"""

from collections import defaultdict
from dataclasses import dataclass
from pathlib import Path
from typing import DefaultDict

from .chunk import DependencyGraph


@dataclass
class DAGStats:
    """Statistics about the dependency graph."""

    total_chunks: int
    total_edges: int
    independent_chunks: int
    max_depth: int
    avg_dependencies_per_chunk: float
    max_dependencies: int
    parallelizable_ratio: float
    critical_path_length: int
    strongly_connected_components: int
    ignored_cycle_count: int = 0

    def __str__(self) -> str:
        """Return human-readable statistics."""
        return f"""
DAG Statistics
==============
Total Chunks: {self.total_chunks}
Total Dependency Edges: {self.total_edges}
Independent Chunks: {self.independent_chunks} ({self.parallelizable_ratio:.1%})
Maximum Dependencies (single chunk): {self.max_dependencies}
Average Dependencies per Chunk: {self.avg_dependencies_per_chunk:.2f}
Max Depth (longest dependency chain): {self.max_depth}
Critical Path Length: {self.critical_path_length}
Strongly Connected Components: {self.strongly_connected_components}
"""


def compute_stats(graph: DependencyGraph) -> DAGStats:
    """Compute statistics about the dependency graph."""
    chunks = graph.chunks
    dependencies = graph.dependencies
    total_chunks = len(chunks)

    if total_chunks == 0:
        return DAGStats(
            total_chunks=0,
            total_edges=0,
            independent_chunks=0,
            max_depth=0,
            avg_dependencies_per_chunk=0,
            max_dependencies=0,
            parallelizable_ratio=0,
            critical_path_length=0,
            strongly_connected_components=0,
            ignored_cycle_count=0,
        )

    # Count edges and independent chunks
    total_edges = 0
    independent_chunks = 0
    max_dependencies = 0
    dependency_counts = []

    for chunk_id, deps in dependencies.items():
        dep_count = len(deps.depends_on_chunks)
        dependency_counts.append(dep_count)
        total_edges += dep_count
        max_dependencies = max(max_dependencies, dep_count)

        if dep_count == 0:
            independent_chunks += 1

    avg_dependencies = sum(dependency_counts) / total_chunks if total_chunks > 0 else 0
    parallelizable_ratio = independent_chunks / total_chunks if total_chunks > 0 else 0

    # Compute max depth (longest dependency chain)
    # This works correctly because cycles are not added to the graph
    max_depth = _compute_max_depth(dependencies, total_chunks)

    # Compute critical path length
    critical_path = _compute_critical_path(dependencies, total_chunks)

    # Count SCCs (simplified: just checking if graph is a DAG)
    sccs = _count_strongly_connected_components(dependencies, total_chunks)

    return DAGStats(
        total_chunks=total_chunks,
        total_edges=total_edges,
        independent_chunks=independent_chunks,
        max_depth=max_depth,
        avg_dependencies_per_chunk=avg_dependencies,
        max_dependencies=max_dependencies,
        parallelizable_ratio=parallelizable_ratio,
        critical_path_length=critical_path,
        strongly_connected_components=sccs,
    )


def _compute_max_depth(dependencies: dict, total_chunks: int) -> int:
    """
    Compute the longest dependency chain (max depth in DAG).

    Works correctly even if cycles were detected, because cycles
    are not added to the graph structure (they're tracked separately).
    """
    memo: dict[int, int] = {}

    def depth(chunk_id: int) -> int:
        if chunk_id in memo:
            return memo[chunk_id]

        if chunk_id not in dependencies:
            memo[chunk_id] = 0
            return 0

        deps = dependencies[chunk_id].depends_on_chunks
        if not deps:
            memo[chunk_id] = 0
            return 0

        max_dep_depth = max(depth(dep) for dep in deps)
        result = max_dep_depth + 1
        memo[chunk_id] = result
        return result

    max_d = 0
    for chunk_id in range(total_chunks):
        max_d = max(max_d, depth(chunk_id))

    return max_d


def _compute_critical_path(dependencies: dict, total_chunks: int) -> int:
    """
    Compute critical path length (longest dependency chain from sources to sinks).
    
    The critical path is the longest chain of dependencies you must follow.
    For example: A depends on B, B depends on C => path length is 3 chunks
    """
    if total_chunks == 0:
        return 0
    
    # Build a memoization dict for longest path from each node
    memo: dict[int, int] = {}
    
    def longest_chain_from(chunk_id: int) -> int:
        """Return longest chain starting from chunk_id (including itself)."""
        if chunk_id in memo:
            return memo[chunk_id]
        
        deps = dependencies[chunk_id].depends_on_chunks
        if not deps:
            # This chunk has no dependencies - it's a leaf in the dependency tree
            memo[chunk_id] = 1
            return 1
        
        # Find the longest path through all dependencies
        max_dep_path = max(longest_chain_from(dep) for dep in deps)
        result = 1 + max_dep_path
        memo[chunk_id] = result
        return result
    
    # Find the longest chain starting from any chunk
    return max(longest_chain_from(chunk_id) for chunk_id in range(total_chunks))




def _longest_path_from(node: int, dependencies: dict, total_chunks: int) -> int:
    """Compute longest path starting from a node following dependencies."""
    memo: dict[int, int] = {}

    def path_len(chunk_id: int) -> int:
        if chunk_id in memo:
            return memo[chunk_id]

        if chunk_id not in dependencies:
            memo[chunk_id] = 1
            return 1

        # Follow the dependency chain: what does this chunk depend on?
        dependencies_of_chunk = dependencies[chunk_id].depends_on_chunks
        if not dependencies_of_chunk:
            memo[chunk_id] = 1
            return 1

        # Find the longest path through our dependencies
        max_path = max(path_len(dep) for dep in dependencies_of_chunk)
        result = max_path + 1
        memo[chunk_id] = result
        return result

    return path_len(node)


def _count_strongly_connected_components(dependencies: dict, total_chunks: int) -> int:
    """Count strongly connected components (simplified for DAG context)."""
    # For a DAG, this is just the number of nodes since no cycles exist
    # But we compute it properly anyway using Kosaraju's algorithm
    if total_chunks == 0:
        return 0

    # First DFS to get finish times
    visited = set()
    finish_order = []

    def dfs1(node: int):
        visited.add(node)
        if node in dependencies:
            for neighbor in dependencies[node].depends_on_chunks:
                if neighbor not in visited:
                    dfs1(neighbor)
        finish_order.append(node)

    for chunk_id in range(total_chunks):
        if chunk_id not in visited:
            dfs1(chunk_id)

    # Build reverse graph
    reverse_deps: DefaultDict[int, set[int]] = defaultdict(set)
    for chunk_id, deps in dependencies.items():
        for dep in deps.depends_on_chunks:
            reverse_deps[dep].add(chunk_id)

    # Second DFS on reverse graph in finish order
    visited.clear()
    scc_count = 0

    def dfs2(node: int):
        visited.add(node)
        if node in reverse_deps:
            for neighbor in reverse_deps[node]:
                if neighbor not in visited:
                    dfs2(neighbor)

    for node in reversed(finish_order):
        if node not in visited:
            dfs2(node)
            scc_count += 1

    return scc_count


def _extract_connected_components(graph: DependencyGraph) -> list[set[int]]:
    """Extract weakly connected components from the dependency graph."""
    visited = set()
    components = []

    def dfs(chunk_id: int, component: set[int]):
        """DFS to find all chunks in a component."""
        if chunk_id in visited:
            return
        visited.add(chunk_id)
        component.add(chunk_id)

        # Follow outgoing edges
        for dep in graph.dependencies[chunk_id].depends_on_chunks:
            if dep not in visited:
                dfs(dep, component)

        # Follow incoming edges
        for dependent in graph.dependencies[chunk_id].depended_by_chunks:
            if dependent not in visited:
                dfs(dependent, component)

    for chunk_id in range(len(graph.chunks)):
        if chunk_id not in visited:
            component: set[int] = set()
            dfs(chunk_id, component)
            if component:
                components.append(component)

    # Sort by size (largest first)
    components.sort(key=len, reverse=True)
    return components


def to_mermaid(
    graph: DependencyGraph, show_files: bool = True, per_component: bool = True
) -> str:
    """
    Generate Mermaid diagram code for the DAG.

    Args:
        graph: The dependency graph
        show_files: Whether to show file names
        per_component: If True, generate separate diagrams for each connected component

    Returns:
        Mermaid diagram code (multiple diagrams if per_component=True)
    """
    if not per_component or len(graph.chunks) < 20:
        # Small graph or per_component disabled: single diagram
        return _to_mermaid_single(graph, show_files)

    # Large graph: extract and visualize components separately
    components = _extract_connected_components(graph)
    diagrams = []

    for i, component in enumerate(components):
        diagrams.append(f"## Component {i + 1} ({len(component)} chunks)")
        diagrams.append("")
        diagrams.append(_to_mermaid_component(graph, component, show_files))
        diagrams.append("")

    return "\n".join(diagrams)


def _to_mermaid_single(graph: DependencyGraph, show_files: bool) -> str:
    """Generate a single Mermaid diagram for the entire graph."""
    lines = ["graph TD"]

    chunks = graph.chunks
    dependencies = graph.dependencies

    # Add nodes
    for chunk in chunks:
        label = f"C{chunk.index}"
        if show_files and chunk.file:
            file_name = chunk.file.name
            label = f"{label}[{file_name}]"
        if chunk.scope:
            label = f"{label}::{chunk.scope}"

        # Escape special characters
        label = label.replace('"', '\\"')
        lines.append(f'    {chunk.index}["{label}"]')

    # Add edges
    for chunk_id, deps in dependencies.items():
        for dep_id in deps.depends_on_chunks:
            lines.append(f"    {dep_id} --> {chunk_id}")

    return "\n".join(lines)


def _to_mermaid_component(
    graph: DependencyGraph, component: set[int], show_files: bool
) -> str:
    """Generate Mermaid diagram for a single connected component."""
    lines = ["graph TD"]

    chunks = graph.chunks
    dependencies = graph.dependencies

    # Add nodes in component
    for chunk_id in sorted(component):
        chunk = chunks[chunk_id]
        label = f"C{chunk.index}"
        if show_files and chunk.file:
            file_name = chunk.file.name
            label = f"{label}[{file_name}]"
        if chunk.scope:
            label = f"{label}::{chunk.scope}"

        label = label.replace('"', '\\"')
        lines.append(f'    {chunk.index}["{label}"]')

    # Add edges within component
    for chunk_id in component:
        deps = dependencies[chunk_id]
        for dep_id in deps.depends_on_chunks:
            if dep_id in component:
                lines.append(f"    {dep_id} --> {chunk_id}")

    return "\n".join(lines)


def to_graphviz_dot(
    graph: DependencyGraph, show_files: bool = True, per_component: bool = True
) -> str:
    """
    Generate Graphviz DOT code for the DAG.

    Args:
        graph: The dependency graph
        show_files: Whether to show file names
        per_component: If True, generate separate files for each connected component

    Returns:
        DOT code (multiple graphs if per_component=True)
    """
    if not per_component or len(graph.chunks) < 20:
        # Small graph or per_component disabled: single diagram
        return _to_graphviz_single(graph, show_files)

    # Large graph: extract and visualize components separately
    components = _extract_connected_components(graph)
    outputs = []

    for i, component in enumerate(components):
        outputs.append(f"# Component {i + 1} ({len(component)} chunks)")
        outputs.append(_to_graphviz_component(graph, component, show_files, i + 1))
        outputs.append("")

    return "\n".join(outputs)


def _to_graphviz_single(graph: DependencyGraph, show_files: bool) -> str:
    """Generate a single Graphviz diagram for the entire graph."""
    lines = ["digraph ChunkDependencies {", "    rankdir=LR;", "    node [shape=box];"]

    chunks = graph.chunks
    dependencies = graph.dependencies

    # Add nodes
    for chunk in chunks:
        label = f"C{chunk.index}"
        if show_files and chunk.file:
            file_name = chunk.file.name
            label = f"{label}\\n{file_name}"
        if chunk.scope:
            label = f"{label}\\n{chunk.scope}"

        # Escape special characters for DOT
        label = label.replace('"', '\\"')
        lines.append(f'    {chunk.index} [label="{label}"];')

    # Add edges
    for chunk_id, deps in dependencies.items():
        for dep_id in deps.depends_on_chunks:
            lines.append(f"    {dep_id} -> {chunk_id};")

    lines.append("}")
    return "\n".join(lines)


def _to_graphviz_component(
    graph: DependencyGraph, component: set[int], show_files: bool, comp_num: int
) -> str:
    """Generate Graphviz diagram for a single connected component."""
    lines = [
        f"digraph Component{comp_num} {{",
        "    rankdir=LR;",
        "    node [shape=box];",
    ]

    chunks = graph.chunks
    dependencies = graph.dependencies

    # Add nodes in component
    for chunk_id in sorted(component):
        chunk = chunks[chunk_id]
        label = f"C{chunk.index}"
        if show_files and chunk.file:
            file_name = chunk.file.name
            label = f"{label}\\n{file_name}"
        if chunk.scope:
            label = f"{label}\\n{chunk.scope}"

        label = label.replace('"', '\\"')
        lines.append(f'    {chunk.index} [label="{label}"];')

    # Add edges within component
    for chunk_id in component:
        deps = dependencies[chunk_id]
        for dep_id in deps.depends_on_chunks:
            if dep_id in component:
                lines.append(f"    {dep_id} -> {chunk_id};")

    lines.append("}")
    return "\n".join(lines)


def print_dependency_report(graph: DependencyGraph, detailed: bool = False) -> None:
    """Print a comprehensive dependency analysis report."""
    stats = compute_stats(graph)

    print("\n" + "=" * 70)
    print("CHUNK DEPENDENCY ANALYSIS")
    print("=" * 70)
    print(stats)

    # Report on ignored cycles if any were detected
    if graph.ignored_cycles:
        print(
            f"\n⚠️  {len(graph.ignored_cycles)} cycle(s) detected and ignored during graph construction:"
        )
        for from_id, to_id in sorted(graph.ignored_cycles)[:10]:
            print(f"  - Chunk {from_id} → Chunk {to_id} (would create cycle)")
        if len(graph.ignored_cycles) > 10:
            print(f"  ... and {len(graph.ignored_cycles) - 10} more")
    else:
        print("\n✓ No circular dependencies detected")

    if detailed:
        print("\n" + "-" * 70)
        print("CHUNK DETAILS")
        print("-" * 70)

        for chunk in graph.chunks:
            deps = graph.dependencies[chunk.index]
            print(f"\nChunk {chunk.index}:")
            print(f"  File: {chunk.file.name if chunk.file else 'unknown'}")
            if chunk.scope:
                print(f"  Scope: {chunk.scope}")
            print(
                f"  Declares: {deps.declared_symbols if deps.declared_symbols else '(none)'}"
            )
            print(f"  Uses: {deps.used_symbols if deps.used_symbols else '(none)'}")
            print(
                f"  Depends on ({len(deps.depends_on_chunks)}): {deps.depends_on_chunks if deps.depends_on_chunks else '(none)'}"
            )
            print(
                f"  Depended by ({len(deps.depended_by_chunks)}): {deps.depended_by_chunks if deps.depended_by_chunks else '(none)'}"
            )

    print("\n" + "=" * 70)


def save_mermaid(
    graph: DependencyGraph,
    output_path: Path,
    show_files: bool = True,
    per_component: bool = True,
) -> None:
    """
    Save Mermaid diagram(s) to file(s).

    If per_component=True and graph is large, generates one file per connected component.
    """
    components = _extract_connected_components(graph) if per_component else []

    # Multiple files, one per component
    output_dir = output_path.parent
    base_name = output_path.stem

    for i, component in enumerate(components):
        component_path = output_dir / f"{base_name}_comp{i + 1}.mermaid"
        content = _to_mermaid_component(graph, component, show_files)
        component_path.write_text(content)
    print(f"✓ Mermaid components saved to {output_dir}")


def save_graphviz(
    graph: DependencyGraph,
    output_path: Path,
    show_files: bool = True,
    per_component: bool = True,
) -> None:
    """
    Save Graphviz DOT file(s).

    If per_component=True and graph is large, generates one file per connected component.
    """
    components = _extract_connected_components(graph) if per_component else []

    # Multiple files, one per component
    output_dir = output_path.parent
    base_name = output_path.stem

    for i, component in enumerate(components):
        component_path = output_dir / f"{base_name}_comp{i + 1}.dot"
        content = _to_graphviz_component(graph, component, show_files, i + 1)
        component_path.write_text(content)
        _png_path = component_path.with_suffix(".png")
    print(f"✓ Graphviz components saved to {output_dir}")
    print("  To render: dot -Tpng <component_path> -o <png_path>")


def analyze_parallelizability(graph: DependencyGraph) -> dict:
    """
    Analyze potential for parallelization.

    Note: Cycles are detected and prevented from being added to the graph,
    but are tracked in graph.ignored_cycles for reporting.
    """
    stats = compute_stats(graph)

    # Calculate speedup potential with unlimited parallelism
    # P = critical path length (must be done serially)
    # S = sum of all work (if perfectly parallelized)
    # Speedup = S / P
    theoretical_speedup = (
        stats.total_chunks / stats.critical_path_length
        if stats.critical_path_length > 0
        else 1
    )

    # Calculate efficiency
    efficiency = (
        (1 / stats.critical_path_length) if stats.critical_path_length > 0 else 1
    )

    return {
        "parallelizable_percentage": stats.parallelizable_ratio * 100,
        "independent_chunks": stats.independent_chunks,
        "critical_path_length": stats.critical_path_length,
        "theoretical_max_speedup": theoretical_speedup,
        "theoretical_efficiency": efficiency,
        "bottleneck_chunks": _find_bottleneck_chunks(graph, stats),
        "ignored_cycles": len(graph.ignored_cycles),
        "ignored_cycle_edges": list(graph.ignored_cycles),
    }


def _find_bottleneck_chunks(graph: DependencyGraph, stats: DAGStats) -> list[int]:
    """
    Find chunks that are on the critical path.

    Works correctly even with ignored cycles because:
    - Cycles are not added to the graph structure
    - Critical path is computed on the resulting DAG
    """
    if stats.critical_path_length == 0:
        return []

    # Find all chunks that are on some critical path
    in_degree_in_deps = {}
    for chunk_id in range(stats.total_chunks):
        in_degree_in_deps[chunk_id] = len(
            graph.dependencies[chunk_id].depended_by_chunks
        )

    # Sources (in-degree = 0)
    sources = [c for c in range(stats.total_chunks) if in_degree_in_deps[c] == 0]

    bottlenecks = set()

    def find_critical_from_source(source: int):
        depth = _compute_max_depth(graph.dependencies, stats.total_chunks)
        memo: dict[int, int] = {}

        def get_depth(chunk_id: int) -> int:
            if chunk_id in memo:
                return memo[chunk_id]
            if chunk_id not in graph.dependencies:
                memo[chunk_id] = 0
                return 0
            deps = graph.dependencies[chunk_id].depends_on_chunks
            if not deps:
                memo[chunk_id] = 0
                return 0
            max_dep = max(get_depth(d) for d in deps)
            memo[chunk_id] = max_dep + 1
            return memo[chunk_id]

        def mark_critical(chunk_id: int, target_depth: int):
            if get_depth(chunk_id) == target_depth:
                bottlenecks.add(chunk_id)
                for dep in graph.dependencies[chunk_id].depends_on_chunks:
                    mark_critical(dep, target_depth - 1)

        mark_critical(source, depth)

    for source in sources:
        find_critical_from_source(source)

    return sorted(bottlenecks)


def print_parallelization_analysis(graph: DependencyGraph) -> None:
    """Print detailed parallelization analysis."""
    analysis = analyze_parallelizability(graph)

    print("\n" + "=" * 70)
    print("PARALLELIZATION POTENTIAL")
    print("=" * 70)
    print(f"\nParallelizable Chunks: {analysis['parallelizable_percentage']:.1f}%")
    print(f"Independent Chunks: {analysis['independent_chunks']}")
    print(f"Critical Path Length: {analysis['critical_path_length']} chunks")
    print(
        f"Theoretical Maximum Speedup: {analysis['theoretical_max_speedup']:.2f}x "
        f"(on infinite cores)"
    )
    print(
        f"Theoretical Efficiency: {analysis['theoretical_efficiency']:.1%} "
        f"(work parallelization ratio)"
    )

    if analysis["ignored_cycles"] > 0:
        print(
            f"\n⚠️  {len(analysis['ignored_cycle_edges'])} cycle(s) detected and ignored:"
        )
        for from_id, to_id in analysis["ignored_cycle_edges"][:5]:
            print(f"  - Chunk {from_id} → Chunk {to_id} (would create cycle)")
        if len(analysis["ignored_cycle_edges"]) > 5:
            print(f"  ... and {len(analysis['ignored_cycle_edges']) - 5} more")
        print("\nAnalysis continues using DAG (cycles excluded).")

    if analysis["bottleneck_chunks"]:
        print(
            f"\nBottleneck Chunks (on critical path): {analysis['bottleneck_chunks'][:10]}"
        )
        if len(analysis["bottleneck_chunks"]) > 10:
            print(f"  ... and {len(analysis['bottleneck_chunks']) - 10} more")
    else:
        print("\n✓ No bottlenecks detected - good parallelization potential!")

    print("=" * 70)
