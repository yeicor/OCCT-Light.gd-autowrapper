"""Generate Godot RefCounted wrapper classes for OCCT-Light value structs.

Each C struct like occtl_point3_t gets a dedicated Godot class (OcctlPoint3)
with typed fields and to_c()/from_c() conversion helpers.
"""

from pathlib import Path
from xml.sax.saxutils import escape

from parser import CField, CStruct, ParsedHeader
from type_map import (
    ENUM_TYPES,
    HANDLE_TYPES,
    UINT64_ID_TYPES,
    VALUE_STRUCT_TYPES,
    c_type_to_godot_class,
    godot_param_type,
    is_value_struct_type,
    param_type_to_variant_type,
)


def _is_enum_type(c_type: str) -> bool:
    return c_type.strip() in ENUM_TYPES


def _is_uint64_id(c_type: str) -> bool:
    return c_type.strip() in UINT64_ID_TYPES


def _is_value_struct(c_type: str) -> bool:
    return is_value_struct_type(c_type)


def _field_godot_type(field: CField) -> str:
    t = field.type_name.strip()
    if field.array_size > 0:
        arr_type = "PackedFloat64Array" if t == "double" else "Array"
        return arr_type
    if t in ("occtl_status_t",):
        return "int"
    if t in ("int32_t", "uint32_t", "uint16_t", "size_t", "int"):
        return "int"
    if t in ("int64_t", "uint64_t"):
        return "int64_t"
    if t == "double":
        return "double"
    if t == "float":
        return "float"
    if t == "bool":
        return "bool"
    if t == "const char*":
        return "String"
    if t == "const void*":
        return "int64_t"
    if t.endswith("**"):
        return "int64_t"
    if t.endswith("*"):
        inner = t[:-1].strip().replace('const ', '', 1).strip()
        if inner in UINT64_ID_TYPES:
            return "int64_t"
        if inner in VALUE_STRUCT_TYPES:
            return f"Ref<{c_type_to_godot_class(inner)}>"
        return "int64_t"
    if _is_uint64_id(t):
        return "int64_t"
    if _is_value_struct(t):
        return f"Ref<{c_type_to_godot_class(t)}>"
    if t.endswith("_t"):
        return "int"
    raise ValueError(f"Unknown field type '{t}' in struct field '{field.name}'")


def _field_is_array(field: CField) -> bool:
    return field.array_size > 0


def _field_array_size(field: CField) -> int:
    return field.array_size


def _field_clean_name(field: CField) -> str:
    return field.name.split("[")[0].strip()


def generate_value_type_header(struct: CStruct) -> str:
    """Generate the .h file for a value type class."""
    cls = c_type_to_godot_class(struct.type_name)
    c_type = struct.type_name
    guard = f"{cls.upper()}_H"

    lines = [
        f"#ifndef {guard}",
        f"#define {guard}",
        "",
        "#include <godot_cpp/classes/ref.hpp>",
        "#include <godot_cpp/core/class_db.hpp>",
        "#include <godot_cpp/variant/utility_functions.hpp>",
        "#include <cstdint>",
        f'#include "occtl/{struct.header_include}"',
        "",
    ]

    # Add includes for sub-value type fields
    added_includes = set()
    for field in struct.fields:
        ft = field.type_name.strip()
        base = ft.rstrip("* \t").replace('const ', '', 1).strip()
        if base in VALUE_STRUCT_TYPES or is_value_struct_type(base):
            sub_cls = c_type_to_godot_class(base)
            if sub_cls != cls and sub_cls not in added_includes:
                lines.append(f'#include "{sub_cls}.h"')
                added_includes.add(sub_cls)

    lines.extend([
        "",
        "using namespace godot;",
        "",
        f"class {cls} : public godot::RefCounted {{",
        f"    GDCLASS({cls}, godot::RefCounted)",
        "protected:",
        "    static void _bind_methods();",
        "public:",
    ])

    # Fields
    for field in struct.fields:
        gt = _field_godot_type(field)
        clean = _field_clean_name(field)
        if _field_is_array(field):
            # Use PackedFloat64Array for double arrays, Array for others
            arr_type = "PackedFloat64Array" if field.type_name.strip() == "double" else "Array"
            lines.append(f"    {arr_type} {clean};")
        else:
            lines.append(f"    {gt} {clean};")

    lines.append("")
    # Getters and setters
    for field in struct.fields:
        gt = _field_godot_type(field)
        clean = _field_clean_name(field)
        lines.append(f"    {gt} get_{clean}() const;")
        lines.append(f"    void set_{clean}({gt} val);")
    lines.append("")
    lines.append(f"    {c_type} to_c() const;")
    lines.append(f"    static Ref<{cls}> from_c(const {c_type}& val);")
    lines.append(f"    void copy_from_c(const {c_type}& val);")
    lines.append("};")
    lines.append("")
    lines.append(f"#endif // {guard}")
    lines.append("")

    return "\n".join(lines)


def generate_value_type_source(struct: CStruct, all_types: dict[str, CStruct]) -> str:
    """Generate the .cpp file for a value type class."""
    cls = c_type_to_godot_class(struct.type_name)
    c_type = struct.type_name

    lines = [
        f'#include "{cls}.h"',
        "",
    ]

    # Collect unique includes for sub-value types
    for field in struct.fields:
        t = field.type_name.strip()
        if _is_value_struct(t):
            sub_cls = c_type_to_godot_class(t)
            lines.append(f'#include "{sub_cls}.h"')
        elif t.rstrip("*").strip() in VALUE_STRUCT_TYPES:
            inner = t.rstrip("*").strip()
            sub_cls = c_type_to_godot_class(inner)
            lines.append(f'#include "{sub_cls}.h"')

    # Deduplicate includes
    seen = set()
    deduped = []
    for line in lines:
        if line.startswith("#include") and line in seen:
            continue
        if line.startswith("#include"):
            seen.add(line)
        deduped.append(line)
    lines = deduped
    lines.append("")

    # Getters and setters (before _bind_methods since it takes their address)
    for field in struct.fields:
        gt = _field_godot_type(field)
        clean = _field_clean_name(field)
        lines.append(f"{gt} {cls}::get_{clean}() const {{ return {clean}; }}")
        lines.append(f"void {cls}::set_{clean}({gt} val) {{ {clean} = val; }}")
        lines.append("")

    # _bind_methods
    lines.append(f"void {cls}::_bind_methods() {{")
    for field in struct.fields:
        gt = _field_godot_type(field)
        clean = _field_clean_name(field)
        vt = param_type_to_variant_type(gt)
        lines.append(f'    godot::ClassDB::bind_method(godot::D_METHOD("get_{clean}"), &{cls}::get_{clean});')
        lines.append(f'    godot::ClassDB::bind_method(godot::D_METHOD("set_{clean}", "val"), &{cls}::set_{clean});')
        lines.append(f'    ADD_PROPERTY(PropertyInfo(Variant::{vt}, "{clean}"), "set_{clean}", "get_{clean}");')
    lines.append("}")
    lines.append("")

    # to_c()
    lines.append(f"{c_type} {cls}::to_c() const {{")
    lines.append(f"    {c_type} result = {{}};")
    for field in struct.fields:
        t = field.type_name.strip()
        clean = _field_clean_name(field)
        if t == "const void*":
            lines.append(f"    result.{clean} = nullptr;")
        elif t.startswith("const ") and t.endswith("*"):
            lines.append(f"    // const pointer field {clean}: not convertible")
        elif t.endswith("*"):
            inner = t[:-1].strip()
            if inner in UINT64_ID_TYPES:
                lines.append(f"    // pointer to {inner} field not directly representable")
            elif _is_value_struct(inner):
                lines.append(f"    // value pointer field {clean}: use .to_c() and address")
            elif inner == "char":
                lines.append(f"    result.{clean} = const_cast<char*>(({clean}).utf8().get_data());")
            else:
                lines.append(f"    result.{clean} = reinterpret_cast<{t}>(static_cast<uintptr_t>({clean}));")
        elif t in ("occtl_status_t",):
            lines.append(f"    result.{clean} = static_cast<{t}>({clean});")
        elif _is_uint64_id(t):
            lines.append(f"    result.{clean}.bits = static_cast<uint64_t>({clean});")
        elif _is_value_struct(t):
            sub_cls = c_type_to_godot_class(t)
            lines.append(f"    result.{clean} = {clean}->to_c();")
        elif _field_is_array(field):
            size = _field_array_size(field)
            lines.append(f"    for (int _i = 0; _i < {size}; _i++) result.{clean}[_i] = {clean}[_i];")
        elif t in ("double", "float", "bool", "int32_t", "uint32_t", "uint16_t", "int64_t", "uint64_t", "size_t", "int"):
            lines.append(f"    result.{clean} = {clean};")
        elif _is_enum_type(t):
            lines.append(f"    result.{clean} = static_cast<{t}>({clean});")
        else:
            raise ValueError(f"Unhandled type '{t}' in to_c() for field '{clean}' of {c_type}")
    lines.append("    return result;")
    lines.append("}")
    lines.append("")

    # from_c()
    lines.append(f"Ref<{cls}> {cls}::from_c(const {c_type}& val) {{")
    lines.append(f"    Ref<{cls}> r;")
    lines.append(f"    r.instantiate();")
    for field in struct.fields:
        t = field.type_name.strip()
        clean = _field_clean_name(field)
        if t == "const void*":
            lines.append(f"    r->{clean} = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.{clean}));")
        elif t.startswith("const ") and t.endswith("*"):
            inner = t[len("const "):-1].strip()
            if _is_uint64_id(inner):
                lines.append(f"    r->{clean} = static_cast<int64_t>(val.{clean}->bits);")
            elif inner in VALUE_STRUCT_TYPES:
                sub_cls = c_type_to_godot_class(inner)
                lines.append(f"    r->{clean} = {sub_cls}::from_c(*val.{clean});")
            elif inner == "char":
                lines.append(f"    r->{clean} = String(val.{clean});")
            else:
                lines.append(f"    r->{clean} = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.{clean}));")
        elif t.endswith("*") and not t.startswith("const"):
            inner = t[:-1].strip()
            if inner == "char":
                lines.append(f"    r->{clean} = String(val.{clean});")
            elif _is_value_struct(inner):
                sub_cls = c_type_to_godot_class(inner)
                lines.append(f"    r->{clean} = {sub_cls}::from_c(*val.{clean});")
            elif _is_uint64_id(inner):
                lines.append(f"    r->{clean} = static_cast<int64_t>(val.{clean}->bits);")
            else:
                lines.append(f"    r->{clean} = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.{clean}));")
        elif t == "const char*":
            lines.append(f"    r->{clean} = String(val.{clean});")
        elif t in ("occtl_status_t",):
            lines.append(f"    r->{clean} = static_cast<int>(val.{clean});")
        elif _is_uint64_id(t):
            lines.append(f"    r->{clean} = static_cast<int64_t>(val.{clean}.bits);")
        elif _is_value_struct(t):
            sub_cls = c_type_to_godot_class(t)
            lines.append(f"    r->{clean} = {sub_cls}::from_c(val.{clean});")
        elif _field_is_array(field):
            size = _field_array_size(field)
            arr_type = "PackedFloat64Array" if t == "double" else "Array"
            lines.append(f"    r->{clean}.resize({size});")
            lines.append(f"    for (int _i = 0; _i < {size}; _i++) r->{clean}[_i] = val.{clean}[_i];")
        elif t in ("double", "float", "bool", "int32_t", "uint32_t", "uint16_t", "int64_t", "uint64_t", "size_t", "int"):
            lines.append(f"    r->{clean} = val.{clean};")
        elif _is_enum_type(t):
            lines.append(f"    r->{clean} = static_cast<int>(val.{clean});")
        else:
            raise ValueError(f"Unhandled type '{t}' in from_c() for field '{clean}' of {c_type}")
    lines.append("    return r;")
    lines.append("}")
    lines.append("")

    # copy_from_c() — instance method, modifies in-place
    lines.append(f"void {cls}::copy_from_c(const {c_type}& val) {{")
    for field in struct.fields:
        t = field.type_name.strip()
        clean = _field_clean_name(field)
        if t == "const void*":
            lines.append(f"    {clean} = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.{clean}));")
        elif t.startswith("const ") and t.endswith("*"):
            inner = t[len("const "):-1].strip()
            if _is_uint64_id(inner):
                lines.append(f"    {clean} = static_cast<int64_t>(val.{clean}->bits);")
            elif inner in VALUE_STRUCT_TYPES:
                sub_cls = c_type_to_godot_class(inner)
                lines.append(f"    {clean} = {sub_cls}::from_c(*val.{clean});")
            elif inner == "char":
                lines.append(f"    {clean} = String(val.{clean});")
            else:
                lines.append(f"    {clean} = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.{clean}));")
        elif t.endswith("*") and not t.startswith("const"):
            inner = t[:-1].strip()
            if inner == "char":
                lines.append(f"    {clean} = String(val.{clean});")
            elif _is_value_struct(inner):
                sub_cls = c_type_to_godot_class(inner)
                lines.append(f"    {clean} = {sub_cls}::from_c(*val.{clean});")
            elif _is_uint64_id(inner):
                lines.append(f"    {clean} = static_cast<int64_t>(val.{clean}->bits);")
            else:
                lines.append(f"    {clean} = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.{clean}));")
        elif t == "const char*":
            lines.append(f"    {clean} = String(val.{clean});")
        elif t in ("occtl_status_t",):
            lines.append(f"    {clean} = static_cast<int>(val.{clean});")
        elif _is_uint64_id(t):
            lines.append(f"    {clean} = static_cast<int64_t>(val.{clean}.bits);")
        elif _is_value_struct(t):
            sub_cls = c_type_to_godot_class(t)
            lines.append(f"    {clean} = {sub_cls}::from_c(val.{clean});")
        elif _field_is_array(field):
            size = _field_array_size(field)
            arr_type = "PackedFloat64Array" if t == "double" else "Array"
            lines.append(f"    {clean}.resize({size});")
            lines.append(f"    for (int _i = 0; _i < {size}; _i++) {clean}[_i] = val.{clean}[_i];")
        elif t in ("double", "float", "bool", "int32_t", "uint32_t", "uint16_t", "int64_t", "uint64_t", "size_t", "int"):
            lines.append(f"    {clean} = val.{clean};")
        elif _is_enum_type(t):
            lines.append(f"    {clean} = static_cast<int>(val.{clean});")
        else:
            raise ValueError(f"Unhandled type '{t}' in copy_from_c() for field '{clean}' of {c_type}")
    lines.append("}")
    lines.append("")

    return "\n".join(lines)


def generate_value_type_doc_xml(struct: CStruct) -> str:
    """Generate XML doc for a value type class."""
    cls = c_type_to_godot_class(struct.type_name)
    methods = []
    for field in struct.fields:
        gt = _field_godot_type(field)
        clean = _field_clean_name(field)
        methods.append(f'\t\t<method name="get_{clean}">')
        methods.append(f'\t\t\t<return type="{gt}" />')
        methods.append("\t\t\t<description>")
        methods.append(f"\t\t\t\tGetter for {clean}.")
        methods.append("\t\t\t</description>")
        methods.append("\t\t</method>")
        methods.append(f'\t\t<method name="set_{clean}">')
        methods.append(f'\t\t\t<return type="void" />')
        methods.append(f'\t\t\t<argument index="0" name="val" type="{gt}" />')
        methods.append("\t\t\t<description>")
        methods.append(f"\t\t\t\tSetter for {clean}.")
        methods.append("\t\t\t</description>")
        methods.append("\t\t</method>")

    methods_xml = "\n".join(methods)
    return (
        '<?xml version="1.0" encoding="UTF-8" ?>\n'
        f'<class name="{cls}" inherits="RefCounted" version="4.0" '
        'xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" '
        'xsi:noNamespaceSchemaLocation="https://raw.githubusercontent.com/godotengine/godot/master/doc/class.xsd">\n'
        "\t<brief_description>"
        f"Value type wrapper for {struct.type_name}."
        "\t</brief_description>\n"
        "\t<description>"
        f"Auto-generated wrapper for the C struct {struct.type_name}."
        "\t</description>\n"
        "\t<tutorials>\n\t</tutorials>\n"
        "\t<methods>\n"
        f"{methods_xml}\n"
        "\t</methods>\n"
        "</class>\n"
    )


def collect_value_types(parsed_headers: list[ParsedHeader]) -> list[CStruct]:
    """Collect all defined (non-opaque) value struct types."""
    structs = []
    seen = set()
    for ph in parsed_headers:
        for s in ph.structs:
            if not s.is_opaque and s.type_name:
                if s.type_name not in seen:
                    seen.add(s.type_name)
                    structs.append(s)
    return structs
