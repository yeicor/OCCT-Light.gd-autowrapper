from pathlib import Path

from tree_sitter import Language, Node, Parser
from tree_sitter_cpp import language as cpp_language

from .chunk import Chunk, DependencyGraph
from .includes import build_file_include_graph
from .symbols import walk_and_collect_symbols

_CLASS_NODES = {"class_specifier", "struct_specifier", "union_specifier"}
_SCOPE_NAME_NODES = {"type_identifier", "identifier"}
_MERGE_TO_NEXT_NODES = {"comment", "#ifndef", "#ifdef"}
_MERGE_SEQUENCE_PAIRS = {("preproc_def", "preproc_def")}


def extract_chunks_with_deps(
    header: str | Path, max_chunk_bytes: int = 4000
) -> tuple[list[Chunk], dict[str, dict]]:
    """
    Extract chunks from a header file and collect symbol information.

    Returns:
        (chunks, symbols) where symbols maps symbol names to declarations/usages
    """
    source = Path(header).read_bytes()
    header_path = Path(header)
    header_include = header_path.name
    parser = Parser(Language(cpp_language()))
    root = parser.parse(source).root_node

    spans: list[tuple[int, int, str | None, bool, str]] = []
    for child in root.named_children:
        spans.extend(_split_node(child, source, max_chunk_bytes, None, False))

    if not spans:
        text = source.decode("utf8", "ignore").strip()
        chunks = (
            [
                Chunk(
                    index=0,
                    code=text,
                    file=header_path,
                    header_include=header_include,
                )
            ]
            if text
            else []
        )
        symbols = {}
    else:
        spans.sort(key=lambda item: (item[0], item[1]))
        spans = _merge_sequential_spans(spans, source, max_chunk_bytes)
        chunks = []
        last_end = 0

        for start, end, scope, merge_to_next, _node_type in spans:
            if end <= last_end:
                continue
            if merge_to_next:
                continue

            text = source[last_end:end].decode("utf8", "ignore").strip()
            chunk_size = end - last_end

            if chunk_size > max_chunk_bytes:
                raise ValueError(
                    f"Chunk exceeds max_chunk_bytes ({chunk_size} > {max_chunk_bytes}):\n{text}"
                )

            last_end = end
            if text:
                chunks.append(
                    Chunk(
                        index=len(chunks),
                        code=text,
                        scope=scope,
                        file=header_path,
                        header_include=header_include,
                    )
                )

        tail = source[last_end:].decode("utf8", "ignore").strip()
        if tail:
            tail_size = len(source) - last_end
            if tail_size > max_chunk_bytes:
                raise ValueError(
                    f"Chunk exceeds max_chunk_bytes ({tail_size} > {max_chunk_bytes}):\n{tail}"
                )
            chunks.append(
                Chunk(
                    index=len(chunks),
                    code=tail,
                    file=header_path,
                    header_include=header_include,
                )
            )

        symbols = walk_and_collect_symbols(root, source)

    return chunks, symbols


def build_dependency_graph(
    all_chunks: list[Chunk], header_files: list[Path]
) -> DependencyGraph:
    """
    Build a dependency graph using byte offsets for efficient chunk mapping.

    For each file:
    1. Extract type declarations and usages with byte positions
    2. Map byte positions to chunks using binary search
    3. Create dependencies: usages depend on declarations
    """
    graph = DependencyGraph(chunks=all_chunks)

    # Build file-level dependencies
    file_deps = build_file_include_graph(header_files)
    graph.file_dependencies = file_deps

    # Group chunks by file
    chunks_by_file: dict[Path, list[Chunk]] = {}
    for chunk in all_chunks:
        if chunk.file is not None:
            if chunk.file not in chunks_by_file:
                chunks_by_file[chunk.file] = []
            chunks_by_file[chunk.file].append(chunk)

    # For each file, build intra-file dependencies using byte offsets
    for file_path in chunks_by_file:
        source = file_path.read_bytes()
        parser = Parser(Language(cpp_language()))
        root = parser.parse(source).root_node

        symbols = walk_and_collect_symbols(root, source)
        file_chunks = chunks_by_file[file_path]

        # Build a byte offset -> chunk index mapping
        # Each chunk has a byte range in the source file
        def byte_to_chunk_index(byte_offset: int) -> int:
            """Find which chunk contains a byte offset using the chunk's code content."""
            cumulative = 0
            for chunk in file_chunks:
                chunk_size = len(chunk.code.encode("utf8"))
                if byte_offset < cumulative + chunk_size:
                    return chunk.index
                cumulative += chunk_size
            return file_chunks[-1].index if file_chunks else -1

        # Build declarations map: symbol -> set of chunk indices that declare it
        declared_in_chunk: dict[str, set[int]] = {}
        for symbol_name, info in symbols.items():
            if info["declarations"]:
                for decl_info in info["declarations"]:
                    byte_offset = decl_info["byte"]
                    chunk_idx = byte_to_chunk_index(byte_offset)
                    if chunk_idx >= 0:
                        if symbol_name not in declared_in_chunk:
                            declared_in_chunk[symbol_name] = set()
                        declared_in_chunk[symbol_name].add(chunk_idx)
                        graph.dependencies[chunk_idx].declared_symbols.add(symbol_name)

        # Build usage dependencies
        for symbol_name, info in symbols.items():
            if info["usages"] and symbol_name in declared_in_chunk:
                for usage_info in info["usages"]:
                    byte_offset = usage_info["byte"]
                    chunk_idx = byte_to_chunk_index(byte_offset)
                    if chunk_idx >= 0:
                        graph.dependencies[chunk_idx].used_symbols.add(symbol_name)
                        # Add dependency: usage chunk depends on all chunks that declare this symbol
                        for decl_chunk_idx in declared_in_chunk[symbol_name]:
                            if decl_chunk_idx != chunk_idx:
                                graph.add_symbol_dependency(chunk_idx, decl_chunk_idx)

    # Add cross-file dependencies from includes
    for from_file, to_files in file_deps.items():
        from_chunks = chunks_by_file.get(from_file, [])
        for to_file in to_files:
            to_chunks = chunks_by_file.get(to_file, [])
            # All chunks in from_file depend on all chunks in to_file
            for from_chunk in from_chunks:
                for to_chunk in to_chunks:
                    if from_chunk.index != to_chunk.index:
                        graph.add_symbol_dependency(from_chunk.index, to_chunk.index)

    return graph


def _merge_sequential_spans(
    spans: list[tuple[int, int, str | None, bool, str]],
    source: bytes,
    max_chunk_bytes: int,
) -> list[tuple[int, int, str | None, bool, str]]:
    if not _MERGE_SEQUENCE_PAIRS:
        return spans

    non_merge_positions = [
        i for i, (_, _, _, merge, _node_type) in enumerate(spans) if not merge
    ]

    last_end = 0
    for current, nxt in zip(non_merge_positions, non_merge_positions[1:]):
        current_type = spans[current][4]
        next_type = spans[nxt][4]
        if (current_type, next_type) in _MERGE_SEQUENCE_PAIRS:
            start, end, scope, _merge, node_type = spans[current]
            next_start, next_end, next_scope, next_merge, next_node_type = spans[nxt]
            merged_size = next_end - last_end
            if merged_size <= max_chunk_bytes:
                spans[current] = (start, next_end, scope, True, node_type)
            else:
                last_end = end
        else:
            last_end = spans[current][1]
    return spans


def _split_node(
    node: Node,
    source: bytes,
    max_chunk_bytes: int,
    scope: str | None,
    merge_to_next: bool,
) -> list[tuple[int, int, str | None, bool, str]]:
    next_scope = scope
    if node.type in _CLASS_NODES:
        next_scope = _scope_name(node, source) or scope
    node_merge_to_next = merge_to_next or node.type in _MERGE_TO_NEXT_NODES
    size = node.end_byte - node.start_byte
    children = [
        child for child in node.named_children if child.end_byte > child.start_byte
    ]
    if size <= max_chunk_bytes or not children:
        return [
            (node.start_byte, node.end_byte, next_scope, node_merge_to_next, node.type)
        ]
    spans: list[tuple[int, int, str | None, bool, str]] = []
    for child in children:
        spans.extend(
            _split_node(child, source, max_chunk_bytes, next_scope, node_merge_to_next)
        )
    return spans


def _scope_name(node: Node, source: bytes) -> str | None:
    for child in node.children:
        if child.type in _SCOPE_NAME_NODES:
            name = (
                source[child.start_byte : child.end_byte]
                .decode("utf8", "ignore")
                .strip()
            )
            if name:
                return name
    return None
