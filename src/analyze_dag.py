#!/usr/bin/env python3
"""
DAG Analysis Tool

Analyzes the dependency graph of extracted chunks and generates reports
with statistics, visualizations, and parallelizability analysis.

Usage:
    python analyze_dag.py <header_files...> [options]

Examples:
    python analyze_dag.py "include/**/*.h"
    python analyze_dag.py a.h b.h c.h --output analysis/
    python analyze_dag.py "*.h" --mermaid --dot --report --detailed
"""

import os
from pathlib import Path

import typer
from rich.console import Console
from rich.progress import track

from chunker import (
    build_dependency_graph,
    extract_chunks_with_deps,
    print_dependency_report,
    print_parallelization_analysis,
    save_graphviz,
    save_mermaid,
)

console = Console()


def main(
    header_globs: list[str] = typer.Argument(
        ...,
        help="One or more header file globs to analyze",
    ),
    output_dir: Path = typer.Option(
        Path(os.getenv("DAG_ANALYSIS_OUTPUT_DIR", "/tmp/dag_analysis")),
        "--output",
        "-o",
        help="Output directory for analysis files",
    ),
    mermaid: bool = typer.Option(
        True,
        "--mermaid/--no-mermaid",
        help="Generate Mermaid diagram",
    ),
    dot: bool = typer.Option(
        True,
        "--dot/--no-dot",
        help="Generate Graphviz DOT file",
    ),
    report: bool = typer.Option(
        True,
        "--report/--no-report",
        help="Generate text report",
    ),
    detailed: bool = typer.Option(
        False,
        "--detailed/--no-detailed",
        help="Include detailed chunk information in report",
    ),
    parallelization: bool = typer.Option(
        True,
        "--parallelization/--no-parallelization",
        help="Analyze parallelization potential",
    ),
    max_chunk_bytes: int = typer.Option(
        26000,
        "--max-chunk-bytes",
        help="Maximum size for a chunk in bytes",
    ),
) -> None:
    """
    Analyze chunk dependencies and generate visualization/statistics.
    """
    if not header_globs:
        console.print("[red]Error: At least one header glob required[/red]")
        raise typer.Exit(1)

    # Resolve all header globs to actual files
    all_header_files: list[Path] = []
    for glob_pattern in header_globs:
        pattern_path = Path(glob_pattern)
        if pattern_path.is_file():
            all_header_files.append(pattern_path.resolve())
            continue

        matches = sorted(Path().glob(glob_pattern))
        if not matches:
            console.print(
                f"[yellow]Warning: No files matched pattern '{glob_pattern}'[/yellow]"
            )
            continue

        for match in matches:
            if match.is_file():
                all_header_files.append(match.resolve())

    if not all_header_files:
        console.print("[red]Error: No header files matched the provided patterns[/red]")
        raise typer.Exit(1)

    console.print(
        f"\n[bold cyan]Analyzing {len(all_header_files)} header files...[/bold cyan]"
    )

    # Extract chunks from all files
    all_chunks = []
    for header_file in track(
        all_header_files,
        description="Extracting chunks...",
        console=console,
    ):
        try:
            chunks, _ = extract_chunks_with_deps(
                header_file, max_chunk_bytes=max_chunk_bytes
            )
            all_chunks.extend(chunks)
        except Exception as e:
            console.print(f"[red]Error processing {header_file}: {e}[/red]")
            continue

    if not all_chunks:
        console.print("[red]Error: No chunks extracted from any files[/red]")
        raise typer.Exit(1)

    console.print(f"[green]✓ Extracted {len(all_chunks)} chunks[/green]\n")

    # Build dependency graph
    try:
        graph = build_dependency_graph(all_chunks, all_header_files)
    except Exception as e:
        console.print(f"[red]Error building dependency graph: {e}[/red]")
        raise typer.Exit(1)

    # Create output directory
    output_dir.mkdir(parents=True, exist_ok=True)

    # Generate reports
    console.print("[bold cyan]Generating analysis...[/bold cyan]\n")

    if report:
        print_dependency_report(graph, detailed=detailed)

    if parallelization:
        print_parallelization_analysis(graph)

    # Generate visualizations
    files_created = []

    if mermaid:
        try:
            mermaid_path = output_dir / "dag.mermaid"
            save_mermaid(graph, mermaid_path)
            files_created.append(("Mermaid diagram", mermaid_path))
        except Exception as e:
            console.print(f"[red]Error generating Mermaid: {e}[/red]")

    if dot:
        try:
            dot_path = output_dir / "dag.dot"
            save_graphviz(graph, dot_path)
            files_created.append(("Graphviz DOT", dot_path))

            # Provide helpful commands
            png_path = dot_path.with_suffix(".png")
            svg_path = dot_path.with_suffix(".svg")
            console.print("\n[bold]To generate visualizations:[/bold]")
            console.print(f"  [cyan]dot -Tpng {dot_path} -o {png_path}[/cyan]")
            console.print(f"  [cyan]dot -Tsvg {dot_path} -o {svg_path}[/cyan]")

        except Exception as e:
            console.print(f"[red]Error generating Graphviz: {e}[/red]")


if __name__ == "__main__":
    typer.run(main)
