"""Tree-sitter C header parser for the deterministic autowrapper.

Extracts constants, enums, structs, functions, and doc comments from
OCCT-Light C header files.
"""

import re
from dataclasses import dataclass, field
from pathlib import Path

from tree_sitter import Language, Node, Parser
from tree_sitter_cpp import language as cpp_language

# ---------------------------------------------------------------
# Data model
# ---------------------------------------------------------------


@dataclass
class CField:
    type_name: str
    name: str
    array_size: int = 0


@dataclass
class CDeclaration:
    name: str
    header_path: Path
    header_include: str
    doc_comment: str = ""
    guard_directive: str = ""  # e.g. "#ifdef", "#ifndef"
    guard_expression: str = ""


@dataclass
class CConstant(CDeclaration):
    value: str = ""


@dataclass
class CEnumValue:
    name: str
    value: int


@dataclass
class CEnum(CDeclaration):
    enum_name: str = ""  # full typedef name e.g. occtl_status_t
    values: list[CEnumValue] = field(default_factory=list)


@dataclass
class CStruct(CDeclaration):
    is_opaque: bool = False
    fields: list[CField] = field(default_factory=list)
    type_name: str = ""  # the typedef name e.g. occtl_point3_t


@dataclass
class CParameter:
    type_name: str
    name: str
    is_out: bool = False
    default_value: str = ""


@dataclass
class CFunction(CDeclaration):
    return_type: str = ""
    params: list[CParameter] = field(default_factory=list)


@dataclass
class ParsedHeader:
    header_path: Path
    header_include: str
    constants: list[CConstant] = field(default_factory=list)
    enums: list[CEnum] = field(default_factory=list)
    structs: list[CStruct] = field(default_factory=list)
    functions: list[CFunction] = field(default_factory=list)
    all_types: set[str] = field(default_factory=set)


# ---------------------------------------------------------------
# Parser
# ---------------------------------------------------------------

# Node types that represent declarations
_FUNC_MACRO = "OCCTL_API"  # we look for function_declarator in declarations with this


def _node_text(node: Node, source: bytes) -> str:
    return source[node.start_byte : node.end_byte].decode("utf-8", "ignore").strip()


def _extract_comment(node: Node, source: bytes) -> str:
    """Return the comment text immediately preceding *node* in the source."""
    # Walk backwards through siblings and previous named children
    prev = node.prev_named_sibling
    if prev and prev.type == "comment":
        text = _node_text(prev, source)
        return _strip_comment_markers(text)
    # Check prev sibling of parent
    parent = node.parent
    if parent:
        prev = parent.prev_named_sibling
        if prev and prev.type == "comment":
            text = _node_text(prev, source)
            return _strip_comment_markers(text)
    return ""


def _strip_comment_markers(text: str) -> str:
    """Strip /* */ and // comment markers."""
    lines = []
    for line in text.split("\n"):
        line = line.strip()
        if line.startswith("/**"):
            line = line[3:].strip()
        elif line.startswith("/*"):
            line = line[2:].strip()
        elif line.startswith("*"):
            line = line[1:].strip()
        elif line.startswith("//"):
            line = line[2:].strip()
        if line.endswith("*/"):
            line = line[:-2].strip()
        if line:
            lines.append(line)
    return " ".join(lines)


def _extract_guard_info(node: Node, source: bytes) -> tuple[str, str]:
    """Walk up ancestors to find enclosing preprocessor guard."""
    guard_directive = ""
    guard_expression = ""
    parent = node.parent
    while parent:
        if parent.type in ("preproc_ifdef", "preproc_ifndef", "preproc_if"):
            guard_directive = {
                "preproc_ifdef": "#ifdef",
                "preproc_ifndef": "#ifndef",
                "preproc_if": "#if",
            }.get(parent.type, "")
            # first named child is the condition
            for child in parent.named_children:
                if child.type in ("identifier", "preproc_defined"):
                    guard_expression = _node_text(child, source)
                    break
            break
        parent = parent.parent
    return guard_directive, guard_expression


class HeaderParser:
    """Parse a single C header file using tree-sitter."""

    def __init__(self):
        self._parser = Parser(Language(cpp_language()))

    def parse(self, header_path: Path) -> ParsedHeader:
        source = header_path.read_bytes()
        root = self._parser.parse(source).root_node
        header_include = header_path.name

        result = ParsedHeader(
            header_path=header_path,
            header_include=header_include,
        )

        named = list(root.named_children)
        errors: list[str] = []
        i = 0
        while i < len(named):
            node = named[i]
            if node.type == "comment":
                i += 1
                continue
            elif node.type == "preproc_include":
                i += 1
                continue
            elif node.type == "preproc_def":
                const = self._parse_define(node, source, header_path, header_include)
                if const:
                    result.constants.append(const)
            elif node.type == "type_definition":
                parsed = self._parse_typedef(node, source, header_path, header_include)
                for s in parsed.structs:
                    result.structs.append(s)
                for e in parsed.enums:
                    result.enums.append(e)
            elif node.type == "declaration":
                func, struct = self._parse_declaration(
                    node, source, header_path, header_include
                )
                if func:
                    result.functions.append(func)
                if struct:
                    result.structs.append(struct)
            elif node.type in ("preproc_ifdef", "preproc_ifndef", "preproc_if"):
                # Recurse into guard blocks
                sub_items = self._parse_guarded_block(
                    node, source, header_path, header_include
                )
                result.constants.extend(sub_items.constants)
                result.enums.extend(sub_items.enums)
                result.structs.extend(sub_items.structs)
                result.functions.extend(sub_items.functions)
            elif node.type == "linkage_specification":
                # extern "C" block – recurse into declaration list
                for child in node.named_children:
                    if child.type == "declaration_list":
                        sub = self._parse_as_root(
                            child, source, header_path, header_include
                        )
                        result.constants.extend(sub.constants)
                        result.enums.extend(sub.enums)
                        result.structs.extend(sub.structs)
                        result.functions.extend(sub.functions)
            elif node.type == "preproc_else":
                # parse the else branch
                for subchild in node.named_children:
                    sub = self._parse_as_root(
                        subchild, source, header_path, header_include
                    )
                    result.constants.extend(sub.constants)
                    result.enums.extend(sub.enums)
                    result.structs.extend(sub.structs)
                    result.functions.extend(sub.functions)
            elif node.type == "preproc_call":
                # Other preprocessor calls (e.g. #pragma) - skip
                i += 1
                continue
            elif node.type == "preproc_function_def":
                # Function-like macros - skip
                i += 1
                continue
            elif node.type == "preproc_directive":
                # Other preprocessor directives (e.g. #undef, #error) - skip
                i += 1
                continue
            elif node.type == "function_definition":
                # C++ inline function definitions - skip (these are in C++ convenience headers)
                i += 1
                continue
            elif node.type == "ERROR":
                errors.append(
                    f"Parse error at line {node.start_point.row + 1}: '{_node_text(node, source)}'"
                )
            else:
                errors.append(
                    f"Unhandled node type '{node.type}' at line {node.start_point.row + 1}: '{_node_text(node, source)[:80]}'"
                )
            i += 1

        if errors:
            msg = "\n".join(f"  [ERROR] {header_path.name}: {err}" for err in errors)
            raise RuntimeError(f"Parser encountered unsupported constructs:\n{msg}")

        return result

    def _parse_as_root(
        self, node: Node, source: bytes, header_path: Path, header_include: str
    ) -> ParsedHeader:
        """Parse a subtree as if it were a root node."""
        result = ParsedHeader(header_path=header_path, header_include=header_include)
        errors: list[str] = []
        for child in node.named_children:
            if child.type == "comment":
                continue
            if child.type == "preproc_include":
                continue
            if child.type == "preproc_def":
                const = self._parse_define(child, source, header_path, header_include)
                if const:
                    result.constants.append(const)
            elif child.type == "type_definition":
                parsed = self._parse_typedef(child, source, header_path, header_include)
                result.structs.extend(parsed.structs)
                result.enums.extend(parsed.enums)
            elif child.type == "declaration":
                func, struct = self._parse_declaration(
                    child, source, header_path, header_include
                )
                if func:
                    result.functions.append(func)
                if struct:
                    result.structs.append(struct)
            elif child.type == "linkage_specification":
                for decl_list in child.named_children:
                    if decl_list.type == "declaration_list":
                        sub = self._parse_as_root(
                            decl_list, source, header_path, header_include
                        )
                        result.constants.extend(sub.constants)
                        result.enums.extend(sub.enums)
                        result.structs.extend(sub.structs)
                        result.functions.extend(sub.functions)
            elif child.type == "preproc_call":
                # #pragma and similar - skip
                continue
            elif child.type == "preproc_function_def":
                # Function-like macros - skip
                continue
            elif child.type == "preproc_directive":
                # Other preprocessor directives (e.g. #undef, #error) - skip
                continue
            elif child.type == "function_definition":
                # C++ inline function definitions - skip
                continue
            elif child.type in ("preproc_ifdef", "preproc_ifndef", "preproc_if"):
                sub = self._parse_guarded_block(
                    child, source, header_path, header_include
                )
                result.constants.extend(sub.constants)
                result.enums.extend(sub.enums)
                result.structs.extend(sub.structs)
                result.functions.extend(sub.functions)
            elif child.type == "preproc_else":
                for subchild in child.named_children:
                    sub = self._parse_as_root(
                        subchild, source, header_path, header_include
                    )
                    result.constants.extend(sub.constants)
                    result.enums.extend(sub.enums)
                    result.structs.extend(sub.structs)
                    result.functions.extend(sub.functions)
            elif child.type == "ERROR":
                errors.append(
                    f"Parse error at line {child.start_point.row + 1}: '{_node_text(child, source)}'"
                )
            elif child.type in (
                "identifier",
                "binary_expression",
                "preproc_defined",
                "preproc_arg",
                "unary_expression",
                "number_literal",
                "string_literal",
            ):
                continue
            else:
                errors.append(
                    f"Unhandled node type '{child.type}' at line {child.start_point.row + 1}: '{_node_text(child, source)[:80]}'"
                )
        if errors:
            msg = "\n".join(f"  [ERROR] {err}" for err in errors)
            raise RuntimeError(f"Parser encountered unsupported constructs:\n{msg}")
        return result

    def _parse_define(
        self, node: Node, source: bytes, header_path: Path, header_include: str
    ) -> CConstant | None:
        """Parse a #define directive."""
        text = _node_text(node, source)
        m = re.match(r"#\s*define\s+(\w+)\s*(.*)", text)
        if not m:
            return None
        name = m.group(1)
        value = m.group(2).strip()
        if not value or value.startswith("(") and value.endswith(")"):
            pass
        # Filter out function-like macros
        if "(" in name:
            return None
        guard_d, guard_e = _extract_guard_info(node, source)
        doc = _extract_comment(node, source)
        return CConstant(
            name=name,
            value=value,
            header_path=header_path,
            header_include=header_include,
            doc_comment=doc,
            guard_directive=guard_d,
            guard_expression=guard_e,
        )

    def _parse_typedef(
        self, node: Node, source: bytes, header_path: Path, header_include: str
    ) -> ParsedHeader:
        """Parse a typedef declaration."""
        result = ParsedHeader(header_path=header_path, header_include=header_include)
        text = _node_text(node, source)

        # Find the last identifier before ';' - that's the typedef name
        all_ids = re.findall(r"\b(\w+)\b", text.rstrip(";").strip())
        if not all_ids:
            return result
        typedef_name = all_ids[-1]
        doc = _extract_comment(node, source)
        guard_d, guard_e = _extract_guard_info(node, source)

        # Strip comments for keyword detection (doc comments may contain "enum")
        text_stripped = re.sub(r"/\*.*?\*/", "", text, flags=re.DOTALL)
        text_stripped = re.sub(r"//.*", "", text_stripped)

        # Check for enum typedef
        if re.search(r"\benum\b", text_stripped) and "{" in text_stripped:
            values = []
            # Extract enum body
            body_m = re.search(r"\{(.*?)\}", text, re.DOTALL)
            if body_m:
                body = body_m.group(1)
                # Strip C comments from enum body
                body = re.sub(r"/\*.*?\*/", "", body, flags=re.DOTALL)
                body = re.sub(r"//.*", "", body)
                for entry in body.split(","):
                    entry = entry.strip()
                    if not entry:
                        continue
                    parts = entry.split("=", 1)
                    ename = parts[0].strip()
                    assert ename, f"Empty enum value name in {text}"
                    evalue = -1
                    if len(parts) > 1:
                        try:
                            evalue = int(parts[1].strip(), 0)
                        except ValueError:
                            pass
                    if ename:
                        values.append(CEnumValue(name=ename, value=evalue))
            enum_name = typedef_name
            # Extract the C tag name if any
            tag_m = re.search(r"enum\s+(\w+)\s*\{", text)
            if tag_m:
                pass
            result.enums.append(
                CEnum(
                    name=enum_name,
                    enum_name=enum_name,
                    values=values,
                    header_path=header_path,
                    header_include=header_include,
                    doc_comment=doc,
                    guard_directive=guard_d,
                    guard_expression=guard_e,
                )
            )
            return result

        # Check for struct typedef with body
        if "struct" in text and "{" in text:
            fields = self._extract_struct_fields(text)
            result.structs.append(
                CStruct(
                    name=typedef_name,
                    type_name=typedef_name,
                    is_opaque=False,
                    fields=fields,
                    header_path=header_path,
                    header_include=header_include,
                    doc_comment=doc,
                    guard_directive=guard_d,
                    guard_expression=guard_e,
                )
            )
            return result

        # Forward declaration: typedef struct X X_t;
        if "struct" in text and "{" not in text:
            result.structs.append(
                CStruct(
                    name=typedef_name,
                    type_name=typedef_name,
                    is_opaque=True,
                    fields=[],
                    header_path=header_path,
                    header_include=header_include,
                    doc_comment=doc,
                    guard_directive=guard_d,
                    guard_expression=guard_e,
                )
            )
            return result

        # Check for callback typedef: typedef ret (CALL* name)(params);
        # e.g. typedef occtl_status_t(OCCTL_CALL* occtl_node_visitor_t)(occtl_node_id_t node, void* user_data);
        if re.search(r"\([^)]*\*\s*\w+\s*\)\s*\(", text_stripped):
            # Function pointer typedef (callback) - already handled downstream
            # via CALLBACK_TYPES set. Nothing to generate.
            return result

        # Check for simple typedef alias: typedef existing_type new_name;
        # e.g. typedef occtl_axis1_placement_t occtl_geom_line_t;
        if len(all_ids) >= 2:
            match = re.match(r"typedef\s+(.+)\s+(\w+)\s*;", text_stripped)
            if match:
                # Simple alias - already handled downstream via
                # TYPEDEF_CANONICAL_MAP and similar mechanisms.
                # No CStruct needed since it's the same C type.
                return result

        raise RuntimeError(
            f"Unrecognized typedef pattern at line {node.start_point.row + 1}: {text[:120]}..."
        )

    def _extract_struct_fields(self, text: str) -> list[CField]:
        """Extract fields from a struct definition text."""
        fields = []
        body_m = re.search(r"\{(.*?)\}", text, re.DOTALL)
        if not body_m:
            return fields
        body = body_m.group(1)
        # Strip C comments from the body
        body = re.sub(r"/\*.*?\*/", "", body, flags=re.DOTALL)
        body = re.sub(r"//.*", "", body)
        # Split by semicolons, handle nested structs
        for line in body.split(";"):
            line = line.strip()
            if not line or line.startswith("{") or line.endswith("}"):
                continue
            # Skip if this is a nested struct/enum definition
            if "struct" in line or "enum" in line:
                if "{" in line:
                    continue
            # Extract type and name
            line = line.rstrip(",")
            parts = line.rsplit(None, 1)
            if len(parts) == 2:
                ftype, fname = parts
                fname = fname.lstrip("*")
                # Handle array types like m[12]
                arr_m = re.match(r"(\w+)\[(\d+)\]", fname)
                arr_size = 0
                if arr_m:
                    fname = arr_m.group(1)
                    arr_size = int(arr_m.group(2))
                assert ftype.strip(), f"Empty field type in {text}"
                assert fname.strip(), (
                    f"Empty field name in struct field with type '{ftype}'"
                )
                fields.append(
                    CField(
                        type_name=ftype.strip(), name=fname.strip(), array_size=arr_size
                    )
                )
            elif len(parts) == 1 and parts[0]:
                pass
        return fields

    def _parse_declaration(
        self, node: Node, source: bytes, header_path: Path, header_include: str
    ) -> tuple[CFunction | None, CStruct | None]:
        """Parse a declaration node - might be a function or a standalone struct."""
        text = _node_text(node, source).strip()
        if not text:
            return None, None

        doc = _extract_comment(node, source)
        guard_d, guard_e = _extract_guard_info(node, source)

        # Check if this is a standalone struct definition (not typedef)
        if text.startswith("struct ") and "{" in text:
            m = re.match(r"struct\s+(\w+)\s*\{", text)
            if m:
                name = m.group(1)
                fields = self._extract_struct_fields(text)
                return None, CStruct(
                    name=name,
                    type_name=name,
                    is_opaque=False,
                    fields=fields,
                    header_path=header_path,
                    header_include=header_include,
                    doc_comment=doc,
                    guard_directive=guard_d,
                    guard_expression=guard_e,
                )

        # Check for typedef struct with body (tree-sitter may emit as declaration)
        if text.startswith("typedef struct ") and "{" in text:
            all_ids = re.findall(r"\b(\w+)\b", text.rstrip(";").strip())
            typedef_name = all_ids[-1] if all_ids else None
            if typedef_name:
                fields = self._extract_struct_fields(text)
                return None, CStruct(
                    name=typedef_name,
                    type_name=typedef_name,
                    is_opaque=False,
                    fields=fields,
                    header_path=header_path,
                    header_include=header_include,
                    doc_comment=doc,
                    guard_directive=guard_d,
                    guard_expression=guard_e,
                )

        # Check for function declaration with OCCTL_API
        if "OCCTL_API" in text:
            decl = text
            # Remove OCCTL_API, OCCTL_CALL macros and __declspec
            decl = re.sub(r"\bOCCTL_API\b", "", decl)
            decl = re.sub(r"\bOCCTL_CALL\b", "", decl)
            decl = re.sub(r"__declspec\s*\([^)]*\)", "", decl)
            decl = re.sub(r"\bGDE_EXPORT\b", "", decl)
            decl = re.sub(r'\bextern\s+"C"\b', "", decl)
            decl = re.sub(r"\bOCCTL_NO_EXPORT\b", "", decl)
            decl = decl.strip().rstrip(";").strip()

            # Parse: return_type name(params)
            m = re.match(
                r"^(const\s+\S+\s*\*?|\S+(?:\s*\*)?)\s+(\w+)\s*\((.*)\)\s*$",
                decl,
                re.DOTALL,
            )
            if m:
                ret_type = m.group(1).strip()
                func_name = m.group(2).strip()
                params_str = m.group(3).strip()

                params = []
                if params_str and params_str != "void":
                    for p in params_str.split(","):
                        p = p.strip()
                        if not p:
                            continue
                        # Split on last whitespace for "type name"
                        parts = p.rsplit(None, 1)
                        if len(parts) == 2:
                            ptype, pname = parts
                        else:
                            ptype = parts[0]
                            pname = ""
                        assert ptype.strip(), (
                            f"Empty parameter type for function {func_name}"
                        )
                        # Check for default value
                        default_value = ""
                        if "=" in p:
                            eq_idx = p.index("=")
                            # Extract the default value part
                            default_value = p[eq_idx + 1 :].strip()
                            # Remove trailing commas
                            default_value = default_value.rstrip(",")
                            # Re-parse the type+name without the default
                            p_before_default = p[:eq_idx].strip()
                            parts = p_before_default.rsplit(None, 1)
                            if len(parts) == 2:
                                ptype, pname = parts
                            else:
                                ptype = parts[0]
                                pname = ""

                        assert ptype.strip(), (
                            f"Empty parameter type for function {func_name}"
                        )
                        params.append(
                            CParameter(
                                type_name=ptype.strip(),
                                name=pname.strip(),
                                default_value=default_value.strip(),
                            )
                        )

                return CFunction(
                    name=func_name,
                    return_type=ret_type,
                    params=params,
                    header_path=header_path,
                    header_include=header_include,
                    doc_comment=doc,
                    guard_directive=guard_d,
                    guard_expression=guard_e,
                ), None

        return None, None

    def _parse_guarded_block(
        self, node: Node, source: bytes, header_path: Path, header_include: str
    ) -> ParsedHeader:
        """Parse a preprocessor guarded block."""
        result = ParsedHeader(header_path=header_path, header_include=header_include)
        errors: list[str] = []
        for child in node.named_children:
            if child.type == "comment":
                continue
            if child.type == "preproc_include":
                continue
            if child.type == "preproc_def":
                const = self._parse_define(child, source, header_path, header_include)
                if const:
                    result.constants.append(const)
            elif child.type == "type_definition":
                parsed = self._parse_typedef(child, source, header_path, header_include)
                result.structs.extend(parsed.structs)
                result.enums.extend(parsed.enums)
            elif child.type == "declaration":
                func, struct = self._parse_declaration(
                    child, source, header_path, header_include
                )
                if func:
                    result.functions.append(func)
                if struct:
                    result.structs.append(struct)
            elif child.type in ("preproc_ifdef", "preproc_ifndef", "preproc_if"):
                sub = self._parse_guarded_block(
                    child, source, header_path, header_include
                )
                result.constants.extend(sub.constants)
                result.enums.extend(sub.enums)
                result.structs.extend(sub.structs)
                result.functions.extend(sub.functions)
            elif child.type == "linkage_specification":
                for ls_child in child.named_children:
                    if ls_child.type == "declaration_list":
                        sub = self._parse_as_root(
                            ls_child, source, header_path, header_include
                        )
                        result.constants.extend(sub.constants)
                        result.enums.extend(sub.enums)
                        result.structs.extend(sub.structs)
                        result.functions.extend(sub.functions)
            elif child.type == "preproc_call":
                continue
            elif child.type == "preproc_function_def":
                continue
            elif child.type == "preproc_directive":
                continue
            elif child.type == "function_definition":
                continue
            elif child.type == "preproc_else":
                for subchild in child.named_children:
                    sub = self._parse_as_root(
                        subchild, source, header_path, header_include
                    )
                    result.constants.extend(sub.constants)
                    result.enums.extend(sub.enums)
                    result.structs.extend(sub.structs)
                    result.functions.extend(sub.functions)
            elif child.type == "ERROR":
                errors.append(
                    f"Parse error at line {child.start_point.row + 1}: '{_node_text(child, source)}'"
                )
            elif child.type in (
                "identifier",
                "binary_expression",
                "preproc_defined",
                "preproc_arg",
                "unary_expression",
                "number_literal",
                "string_literal",
            ):
                # Preprocessor condition expression parts inside #if blocks - skip
                continue
            else:
                errors.append(
                    f"Unhandled node type '{child.type}' in guarded block at line {child.start_point.row + 1}: '{_node_text(child, source)[:80]}'"
                )
        if errors:
            msg = "\n".join(f"  [ERROR] {err}" for err in errors)
            raise RuntimeError(f"Parser encountered unsupported constructs:\n{msg}")
        return result
