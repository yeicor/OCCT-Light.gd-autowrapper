from pathlib import Path

from tree_sitter import Node


def extract_includes(node: Node, source: bytes) -> set[str]:
    """
    Extract all #include directives from the source code.

    Returns:
        Set of included file paths (as they appear in #include statements)
    """
    includes: set[str] = set()

    def walk(current_node: Node):
        # Look for preprocessor include directives
        if current_node.type == "preproc_include":
            # The include path is typically in a string node
            for child in current_node.children:
                if child.type in ("string_literal", "system_lib_string"):
                    include_text = source[child.start_byte : child.end_byte].decode(
                        "utf8", "ignore"
                    )
                    # Remove quotes
                    include_text = include_text.strip("'\"<>")
                    if include_text:
                        includes.add(include_text)

        # Recurse into children
        for child in current_node.children:
            walk(child)

    walk(node)
    return includes


def resolve_include_path(
    include_statement: str, current_file: Path, search_paths: list[Path] | None = None
) -> Path | None:
    """
    Attempt to resolve an include statement to an actual file path.

    Args:
        include_statement: The include path as it appears in the #include directive
        current_file: The file containing the #include
        search_paths: Additional search paths for includes (defaults to current file's directory)

    Returns:
        Resolved Path if found, None otherwise
    """
    if search_paths is None:
        search_paths = [current_file.parent]

    # Try each search path
    for search_path in search_paths:
        candidate = search_path / include_statement
        if candidate.exists() and candidate.is_file():
            return candidate.resolve()

    return None


def build_file_include_graph(header_files: list[Path]) -> dict[Path, set[Path]]:
    """
    Build a graph of file-to-file dependencies based on #include directives.

    Args:
        header_files: List of header file paths to analyze

    Returns:
        Dict mapping each file to the set of files it includes (that are in header_files)
    """
    from tree_sitter import Language, Parser
    from tree_sitter_cpp import language as cpp_language

    graph: dict[Path, set[Path]] = {f: set() for f in header_files}
    file_set = {f.resolve() for f in header_files}
    parser = Parser(Language(cpp_language()))

    for header_file in header_files:
        source = header_file.read_bytes()
        root = parser.parse(source).root_node
        includes = extract_includes(root, source)

        for include in includes:
            # Try to resolve the include relative to the current file
            resolved = resolve_include_path(include, header_file, [header_file.parent])
            if resolved and resolved in file_set:
                graph[header_file].add(resolved)

    return graph
