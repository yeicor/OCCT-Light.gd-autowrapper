"""Deterministic OCCT-Light.gd autowrapper — generates Godot C++ bindings.

Usage: uv run src/main.py <headers_dir> -o <output_dir>

Parses all C headers in the given directory, then generates:
  - Value-type RefCounted classes for defined structs
  - Handle RefCounted classes for opaque pointer types
  - Per-header wrapper classes (functions, constants, enums)
  - module.h/module.cpp for GDExtension registration
  - XML doc files
  - GDScript test files
"""

import re
import shutil
import sys
from pathlib import Path

from gen_docs import generate_all_docs
from gen_handles import (
    generate_handle_doc_xml,
    generate_handle_header,
    generate_handle_source,
)
from gen_module import generate_module_cpp, generate_module_h
from gen_tests import generate_all_tests
from gen_values import (
    collect_value_types,
    generate_value_type_doc_xml,
    generate_value_type_header,
    generate_value_type_source,
)
from gen_wrapper import (
    generate_wrapper_doc_xml,
    generate_wrapper_header,
    generate_wrapper_source,
    _wrapper_class_name,
)
from parser import CField, CStruct, HeaderParser, ParsedHeader
from type_map import (
    CPP_TO_GODOT_TYPE,
    ENUM_TYPES,
    HANDLE_TYPES,
    UINT64_ID_TYPES,
    VALUE_STRUCT_TYPES,
    _resolve_typedef,
    c_type_to_godot_class,
)


def _synthesize_missing_value_structs(
    parsed_headers: list[ParsedHeader],
    collected: list[CStruct],
) -> None:
    """Synthesize CStruct entries for types in VALUE_STRUCT_TYPES that the
    parser failed to extract (tree-sitter edge cases)."""
    from type_map import VALUE_STRUCT_TYPES, c_type_to_godot_class as _ctg
    collected_names = {s.type_name for s in collected}
    import re
    for ph in parsed_headers:
        header_text = ph.header_path.read_text() if ph.header_path else ""
        for vt in sorted(VALUE_STRUCT_TYPES):
            if vt in collected_names:
                continue
            # Find the last '{...} TYPE_NAME;' pattern by finding the closing
            # brace position first, then scanning backwards for a matching '{'.
            closing = re.search(r'\}\s*' + re.escape(vt) + r'\s*;', header_text)
            if not closing:
                continue
            end_pos = closing.start()
            # Walk backwards from end_pos to find the matching opening brace
            brace_depth = 0
            body_start = -1
            for i in range(end_pos - 1, -1, -1):
                ch = header_text[i]
                if ch == '}':
                    brace_depth += 1
                elif ch == '{':
                    if brace_depth == 0:
                        body_start = i + 1
                        break
                    brace_depth -= 1
            if body_start < 0:
                continue
            body = header_text[body_start:end_pos]
            # Verify this is a typedef struct
            prefix = header_text[max(0, body_start - 80):body_start].strip()
            if not prefix.endswith('struct') and 'typedef' not in prefix:
                # Check if the whole typedef is before the brace
                before_text = header_text[max(0, body_start - 200):body_start]
                if 'typedef' not in before_text or 'struct' not in before_text:
                    continue
            body = re.sub(r'/\*.*?\*/', '', body, flags=re.DOTALL)
            body = re.sub(r'//.*', '', body)
            fields: list[CField] = []
            for line in body.split(";"):
                line = line.strip()
                if not line or line.startswith("{") or line.endswith("}"):
                    continue
                if "struct" in line or "enum" in line:
                    if "{" in line:
                        continue
                line = line.rstrip(",")
                parts = line.rsplit(None, 1)
                if len(parts) == 2:
                    ftype, fname = parts
                    fname = fname.lstrip("*")
                    arr_m = re.match(r'(\w+)\[(\d+)\]', fname)
                    arr_size = 0
                    if arr_m:
                        fname = arr_m.group(1)
                        arr_size = int(arr_m.group(2))
                    fields.append(CField(type_name=ftype.strip(), name=fname.strip(), array_size=arr_size))
            if not fields:
                continue
            s = CStruct(
                name=vt, type_name=vt,
                is_opaque=False, fields=fields,
                header_path=ph.header_path,
                header_include=ph.header_include,
                doc_comment="Synthesized",
            )
            collected.append(s)
            print(f"  [synthesized] {vt} -> {_ctg(vt)}")


def _collect_handle_structs(parsed_headers: list[ParsedHeader]) -> list[CStruct]:
    """Collect opaque structs from parsed headers that are HANDLE_TYPES."""
    handles: list[CStruct] = []
    seen: set[str] = set()
    for ph in parsed_headers:
        for s in ph.structs:
            if s.is_opaque and s.type_name in HANDLE_TYPES:
                if s.type_name not in seen:
                    seen.add(s.type_name)
                    handles.append(s)
    return handles


def _write_if_changed(path: Path, content: str) -> bool:
    """Write content to path only if it differs, returns True if written."""
    if path.exists():
        existing = path.read_text()
        if existing == content:
            return False
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(content)
    return True


def main() -> None:
    import argparse

    parser = argparse.ArgumentParser(
        description="Generate Godot C++ bindings for OCCT-Light C headers"
    )
    parser.add_argument(
        "headers_dir",
        type=Path,
        help="Directory containing OCCT-Light C headers (e.g. OCCT-Light/include/occtl)",
    )
    parser.add_argument(
        "-o", "--output-dir",
        type=Path,
        default=Path("."),
        help="Output directory (parent project root, e.g. ..)",
    )
    parser.add_argument(
        "--skip-docs",
        action="store_true",
        help="Skip generating XML doc files",
    )
    parser.add_argument(
        "--skip-tests",
        action="store_true",
        help="Skip generating GDScript test files",
    )
    args = parser.parse_args()

    headers_dir: Path = args.headers_dir
    output_dir: Path = args.output_dir.resolve()
    autowrapper_dir = output_dir / "src" / "autowrapper"

    if not headers_dir.is_dir():
        print(f"Error: headers directory not found: {headers_dir}", file=sys.stderr)
        sys.exit(1)

    # Collect header files (skip viz and umbrella)
    header_files: list[Path] = []
    for f in sorted(headers_dir.glob("occtl*.h")):
        if f.name in ("occtl_viz.h", "occtl.h"):
            continue
        header_files.append(f)

    if not header_files:
        print("Error: no header files found", file=sys.stderr)
        sys.exit(1)

    print(f"Found {len(header_files)} header files to process")

    # Parse all headers
    hparser = HeaderParser()
    parsed_headers: list[ParsedHeader] = []
    for hf in header_files:
        try:
            ph = hparser.parse(hf)
            parsed_headers.append(ph)
            print(f"  Parsed {hf.name}: "
                  f"{len(ph.constants)} constants, "
                  f"{len(ph.enums)} enums, "
                  f"{len(ph.structs)} structs, "
                  f"{len(ph.functions)} functions")

        except Exception as e:
            print(f"  Warning: failed to parse {hf.name}: {e}")

    if not parsed_headers:
        print("Error: no headers successfully parsed", file=sys.stderr)
        sys.exit(1)

    # Collect value types and handle structs
    all_value_structs = collect_value_types(parsed_headers)
    all_handle_structs = _collect_handle_structs(parsed_headers)

    # Synthesize value structs that the parser missed (tree-sitter edge cases)
    _synthesize_missing_value_structs(parsed_headers, all_value_structs)

    # Populate VALUE_STRUCT_TYPES for type_map lookups
    from type_map import VALUE_STRUCT_TYPES
    for s in all_value_structs:
        VALUE_STRUCT_TYPES.add(s.type_name)

    print(f"\nValue types: {len(all_value_structs)}")
    for s in all_value_structs:
        print(f"  {s.type_name} -> {c_type_to_godot_class(s.type_name)}")
    print(f"Handle types: {len(all_handle_structs)}")
    for s in all_handle_structs:
        print(f"  {s.type_name} -> {c_type_to_godot_class(s.type_name)}Handle")

    # Build a type map for cross-references
    all_types_map: dict[str, CStruct] = {}
    for s in all_value_structs:
        all_types_map[s.type_name] = s
    for s in all_handle_structs:
        all_types_map[s.type_name] = s

    # --- Generate files ---
    autowrapper_dir.mkdir(parents=True, exist_ok=True)

    wrapper_names: list[str] = []
    value_type_names: list[str] = []
    handle_class_names: list[str] = []

    written_count = 0

    # 1. Value type classes (generate for all non-opaque structs that aren't handles)
    for s in all_value_structs:
        if s.type_name in HANDLE_TYPES or s.is_opaque:
            continue
        cls = c_type_to_godot_class(s.type_name)
        value_type_names.append(cls)

        hdr = generate_value_type_header(s)
        src = generate_value_type_source(s, all_types_map)
        if _write_if_changed(autowrapper_dir / f"{cls}.h", hdr):
            written_count += 1
        if _write_if_changed(autowrapper_dir / f"{cls}.cpp", src):
            written_count += 1

    # 2. Handle classes
    for s in all_handle_structs:
        if s.type_name not in HANDLE_TYPES:
            continue
        cls = c_type_to_godot_class(s.type_name) + "Handle"
        handle_class_names.append(cls)

        hdr = generate_handle_header(s)
        src = generate_handle_source(s, "", "")
        if _write_if_changed(autowrapper_dir / f"{cls}.h", hdr):
            written_count += 1
        if _write_if_changed(autowrapper_dir / f"{cls}.cpp", src):
            written_count += 1

    # 3. Wrapper classes (one per header)
    for ph in parsed_headers:
        cls = _wrapper_class_name(ph.header_include)
        wrapper_names.append(cls)

        # Collect value type includes needed by this wrapper
        value_includes: list[str] = []
        for f in ph.functions:
            for p in f.params:
                from type_map import is_out_param
                base = p.type_name.strip()
                base = re.sub(r'\s+(const|volatile)\s*$', '', base)  # strip trailing cv
                base = base.rstrip("* \t")
                base_clean = re.sub(r'^(const|volatile)\s+', '', base).strip()
                resolved = _resolve_typedef(base_clean)
                if resolved.endswith("_t") and resolved not in ENUM_TYPES and resolved not in UINT64_ID_TYPES and resolved not in CPP_TO_GODOT_TYPE:
                    if resolved in HANDLE_TYPES:
                        incl = f"{c_type_to_godot_class(resolved)}Handle.h"
                    elif resolved in VALUE_STRUCT_TYPES or resolved in all_types_map:
                        incl = f"{c_type_to_godot_class(resolved)}.h"
                    else:
                        continue
                    if incl not in value_includes:
                        value_includes.append(incl)
        for c in ph.constants:
            pass
        for e in ph.enums:
            pass

        hdr = generate_wrapper_header(ph, value_includes)
        src = generate_wrapper_source(ph)
        if _write_if_changed(autowrapper_dir / f"{cls}.h", hdr):
            written_count += 1
        if _write_if_changed(autowrapper_dir / f"{cls}.cpp", src):
            written_count += 1

    # 4. module.h / module.cpp
    mhdr = generate_module_h(wrapper_names, value_type_names, handle_class_names)
    msrc = generate_module_cpp(wrapper_names, value_type_names, handle_class_names)
    if _write_if_changed(autowrapper_dir / "module.h", mhdr):
        written_count += 1
    if _write_if_changed(autowrapper_dir / "module.cpp", msrc):
        written_count += 1

    print(f"\nWritten {written_count} C++ source files to {autowrapper_dir}")

    # 5. Clean up orphan files (files that should no longer exist)
    expected_files: set[str] = set()
    for cls in value_type_names + wrapper_names + handle_class_names:
        expected_files.add(f"{cls}.h")
        expected_files.add(f"{cls}.cpp")
    expected_files.add("module.h")
    expected_files.add("module.cpp")
    orphan_count = 0
    for f in autowrapper_dir.iterdir():
        if f.suffix in (".h", ".cpp") and f.name not in expected_files:
            f.unlink()
            orphan_count += 1
    if orphan_count:
        print(f"Removed {orphan_count} orphan files from {autowrapper_dir}")

    # 6. XML docs
    if not args.skip_docs:
        doc_files = generate_all_docs(parsed_headers, all_value_structs, all_handle_structs, output_dir)
        print(f"Written {len(doc_files)} doc XML files")

    # 7. GDScript tests
    if not args.skip_tests:
        test_files = generate_all_tests(parsed_headers, output_dir)
        print(f"Written {len(test_files)} GDScript test files")

    # 8. Clean old cache file
    cache_file = autowrapper_dir / ".autowrapper_cache.json"
    if cache_file.exists():
        cache_file.unlink()
        print("Removed old .autowrapper_cache.json")

    print("\nDone!")


if __name__ == "__main__":
    main()
