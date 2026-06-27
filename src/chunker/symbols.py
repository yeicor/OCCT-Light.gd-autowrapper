from tree_sitter import Node


def _is_keyword(name: str) -> bool:
    """Check if a name is a C++ keyword."""
    keywords = {
        "alignas", "alignof", "and", "and_eq", "asm", "atomic_cancel", "atomic_commit",
        "atomic_noexcept", "auto", "bitand", "bitor", "bool", "break", "case", "catch",
        "char", "char8_t", "char16_t", "char32_t", "class", "compl", "concept", "const",
        "consteval", "constexpr", "constinit", "const_cast", "continue", "co_await",
        "co_return", "co_yield", "decltype", "default", "delete", "do", "double",
        "dynamic_cast", "else", "enum", "explicit", "export", "extern", "false", "float",
        "for", "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace",
        "new", "noexcept", "not", "not_eq", "nullptr", "operator", "or", "or_eq",
        "private", "protected", "public", "register", "reinterpret_cast", "requires",
        "return", "short", "signed", "sizeof", "static", "static_assert", "static_cast",
        "struct", "switch", "synchronized", "template", "this", "thread_local", "throw",
        "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using",
        "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq",
    }
    return name in keywords


def extract_identifier_name(node: Node, source: bytes) -> str:
    """Extract the text content of an identifier node."""
    return source[node.start_byte : node.end_byte].decode("utf8", "ignore").strip()


def walk_and_collect_symbols(
    node: Node, source: bytes
) -> dict[str, dict[str, list]]:
    """
    Walk AST and collect type declarations and usages with byte offset information.
    
    Returns symbols with byte offsets (start_byte) so we can map them to chunks.
    
    Returns a dict: {
        "symbol_name": {
            "declarations": [{"byte": start_byte, "node": node}, ...],
            "usages": [{"byte": start_byte, "node": node}, ...]
        }
    }
    """
    symbols: dict[str, dict[str, list]] = {}

    def walk(current_node: Node):
        # Track struct/class/union/enum declarations
        if current_node.type in ("struct_specifier", "class_specifier", "union_specifier", "enum_specifier"):
            # Get the type name from the type_identifier child
            for child in current_node.children:
                if child.type == "type_identifier":
                    name = extract_identifier_name(child, source)
                    if name and not _is_keyword(name):
                        if name not in symbols:
                            symbols[name] = {"declarations": [], "usages": []}
                        symbols[name]["declarations"].append({
                            "byte": child.start_byte,
                            "node": child
                        })
                    break  # Only take the first type_identifier (the type name)
        
        # Track type_identifier usages (in function parameters, variable declarations, etc.)
        # But NOT in type definitions or struct specifiers (those are declarations)
        elif current_node.type == "type_identifier":
            parent = current_node.parent
            # Skip if this is part of a type definition or struct/class/union/enum specifier
            if parent and parent.type not in ("struct_specifier", "class_specifier", "union_specifier", 
                                               "enum_specifier", "type_definition"):
                name = extract_identifier_name(current_node, source)
                if name and not _is_keyword(name):
                    if name not in symbols:
                        symbols[name] = {"declarations": [], "usages": []}
                    symbols[name]["usages"].append({
                        "byte": current_node.start_byte,
                        "node": current_node
                    })

        # Recurse into children
        for child in current_node.children:
            walk(child)

    walk(node)
    return symbols
