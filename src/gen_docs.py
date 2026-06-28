"""Generate XML documentation files for all autowrapper-generated classes.

Delegates to the per-class generators in gen_values.py, gen_handles.py,
and gen_wrapper.py.
"""

from pathlib import Path

from gen_handles import generate_handle_doc_xml
from gen_values import generate_value_type_doc_xml
from gen_wrapper import generate_wrapper_doc_xml
from parser import CStruct, ParsedHeader
from type_map import HANDLE_TYPES, VALUE_STRUCT_TYPES


def generate_all_docs(
    parsed_headers: list[ParsedHeader],
    value_structs: list[CStruct],
    handle_structs: list[CStruct],
    output_dir: Path,
) -> list[str]:
    """Generate all XML doc files and write them to output_dir/doc_classes/.

    Returns list of filenames written.
    """
    doc_dir = output_dir / "doc_classes"
    doc_dir.mkdir(parents=True, exist_ok=True)

    written: list[str] = []

    # Wrapper docs
    for ph in parsed_headers:
        xml = generate_wrapper_doc_xml(ph)
        from gen_wrapper import _wrapper_class_name
        fname = f"{_wrapper_class_name(ph.header_include)}.xml"
        (doc_dir / fname).write_text(xml, encoding="utf-8")
        written.append(fname)

    # Value type docs (skip native-mapped types)
    for s in value_structs:
        if s.type_name in VALUE_STRUCT_TYPES:
            xml = generate_value_type_doc_xml(s)
            from type_map import c_type_to_godot_class
            fname = f"{c_type_to_godot_class(s.type_name)}.xml"
            (doc_dir / fname).write_text(xml, encoding="utf-8")
            written.append(fname)

    # Handle docs
    for s in handle_structs:
        if s.type_name in HANDLE_TYPES:
            xml = generate_handle_doc_xml(s)
            from type_map import c_type_to_godot_class
            fname = f"{c_type_to_godot_class(s.type_name)}Handle.xml"
            (doc_dir / fname).write_text(xml, encoding="utf-8")
            written.append(fname)

    return written
