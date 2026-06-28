"""Generate simple RefCounted wrapper classes for primitive and UID out-param types.

Each generated class wraps a single C value (uint32_t, occtl_node_id_t, etc.)
with get_value/set_value for Godot and copy_from_c for C++.

These classes are reused across all wrapper functions. For example, any function
with a uint32_t* out-param uses Ref<OcctlUint32>.
"""

from pathlib import Path
from xml.sax.saxutils import escape

# Primitive type descriptors:
#   (C_type, wrapper_class, godot_prop_type, c_to_godot_cast, godot_to_c_cast)
# For UID types (structs with a single .bits uint64 field):
#   (C_type, wrapper_class, "int64_t", ".bits", ".bits = static_cast<uint64_t>(v)")
OUT_PARAM_TYPES: list[tuple[str, str, str, str, str]] = [
    # (C_type, class_name, godot_type, c_to_godot, godot_to_c)
    # Primitive types
    ("uint32_t", "OcctlUint32", "int64_t",
     "static_cast<int64_t>(_value)", "static_cast<uint32_t>(v)"),
    ("int32_t", "OcctlInt32", "int64_t",
     "static_cast<int64_t>(_value)", "static_cast<int32_t>(v)"),
    ("uint8_t", "OcctlUint8", "int64_t",
     "static_cast<int64_t>(_value)", "static_cast<uint8_t>(v)"),
    ("size_t", "OcctlSize", "int64_t",
     "static_cast<int64_t>(_value)", "static_cast<size_t>(v)"),
    ("int", "OcctlInt32", "int64_t",
     "static_cast<int64_t>(_value)", "static_cast<int>(v)"),
    ("int64_t", "OcctlInt64", "int64_t",
     "static_cast<int64_t>(_value)", "static_cast<int64_t>(v)"),
    ("uint64_t", "OcctlUint64", "int64_t",
     "static_cast<int64_t>(_value)", "static_cast<uint64_t>(v)"),
    ("double", "OcctlDouble", "double",
     "_value", "v"),
    ("float", "OcctlDouble", "double",
     "static_cast<double>(_value)", "static_cast<float>(v)"),
    ("bool", "OcctlBool", "bool",
     "_value", "v"),
]


# For UID types (structs with a single .bits uint64 field):
UID_TYPES: list[tuple[str, str, str]] = [
    ("occtl_node_id_t", "OcctlNodeId", "int64_t"),
    ("occtl_uid_t", "OcctlUid", "int64_t"),
    ("occtl_ref_id_t", "OcctlRefId", "int64_t"),
    ("occtl_ref_uid_t", "OcctlRefUid", "int64_t"),
    ("occtl_rep_uid_t", "OcctlRepUid", "int64_t"),
    ("occtl_rep_id_t", "OcctlRepId", "int64_t"),
    ("occtl_joint_id_t", "OcctlJointId", "int64_t"),
]

# String out-param types.
STRING_TYPES: list[str] = [
    "OcctlString",
    "OcctlStringArray",
]

OUT_PARAM_STRING_TYPES: dict[str, str] = {
    "const char": "OcctlString",
    "const char*": "OcctlString",
}

OUT_PARAM_STRING_ARRAY_TYPES: dict[str, str] = {
    "const char**": "OcctlStringArray",
}

OUT_PARAM_BYTE_ARRAY_TYPES: dict[str, str] = {
    "uint8_t*": "OcctlByteArray",
}


def _prim_header_name(cls: str) -> str:
    return f"{cls}.h"


def _uid_include(c_type: str) -> str:
    """Return the OCCT-Light header that declares this UID type."""
    if c_type in ("occtl_node_id_t", "occtl_joint_id_t", "occtl_ref_uid_t", "occtl_rep_uid_t", "occtl_ref_id_t"):
        return "occtl/occtl_topo_types.h"
    if c_type in ("occtl_rep_id_t",):
        return "occtl/occtl_core.h"
    return "occtl/occtl_core.h"


def _prim_header(c_type: str, cls: str, godot_type: str, is_uid: bool) -> str:
    guard = f"{cls.upper()}_H"
    includes = (
        "#include <godot_cpp/classes/ref.hpp>\n"
        "#include <godot_cpp/core/class_db.hpp>\n"
        "#include <cstdint>\n"
    )
    if is_uid:
        includes += f'#include "{_uid_include(c_type)}"\n'
    return (
        f"#ifndef {guard}\n"
        f"#define {guard}\n"
        f"\n"
        f"{includes}"
        f"\n"
        f"using namespace godot;\n"
        f"\n"
        f"class {cls} : public godot::RefCounted {{\n"
        f"    GDCLASS({cls}, godot::RefCounted)\n"
        f"    {c_type} _value{{}};\n"
        f"protected:\n"
        f"    static void _bind_methods();\n"
        f"public:\n"
        f"    {godot_type} get_value() const;\n"
        f"    void set_value({godot_type} v);\n"
        f"    void copy_from_c(const {c_type}& v);\n"
        f"}};\n"
        f"\n"
        f"#endif // {guard}\n"
    )


def _prim_source(c_type: str, cls: str, godot_type: str, is_uid: bool) -> str:
    hdr = _prim_header_name(cls)
    if is_uid:
        getter = f"static_cast<int64_t>(_value.bits)"
        setter = f"_value.bits = static_cast<uint64_t>(v)"
        copy_from_c = f"_value.bits = v.bits;"
    else:
        getter = f"static_cast<{godot_type}>(_value)" if godot_type not in ("double", "bool") else f"_value"
        setter = f"_value = static_cast<{c_type}>(v)"
        copy_from_c = f"_value = v;"
    vt = "INT" if godot_type == "int64_t" else "FLOAT" if godot_type == "double" else "BOOL"
    return (
        f'#include "{hdr}"\n'
        f"\n"
        f"{godot_type} {cls}::get_value() const {{\n"
        f"    return {getter};\n"
        f"}}\n"
        f"\n"
        f"void {cls}::set_value({godot_type} v) {{\n"
        f"    {setter};\n"
        f"}}\n"
        f"\n"
        f"void {cls}::copy_from_c(const {c_type}& v) {{\n"
        f"    {copy_from_c}\n"
        f"}}\n"
        f"\n"
        f"void {cls}::_bind_methods() {{\n"
        f'    godot::ClassDB::bind_method(godot::D_METHOD("get_value"), &{cls}::get_value);\n'
        f'    godot::ClassDB::bind_method(godot::D_METHOD("set_value", "v"), &{cls}::set_value);\n'
        f'    ADD_PROPERTY(PropertyInfo(Variant::{vt}, "value"), "set_value", "get_value");\n'
        f"}}\n"
    )


def _prim_doc_xml(c_type: str, cls: str, godot_type: str) -> str:
    vt = "INT" if godot_type == "int64_t" else "FLOAT" if godot_type == "double" else "BOOL"
    return (
        '<?xml version="1.0" encoding="UTF-8" ?>\n'
        f'<class name="{cls}" inherits="RefCounted" version="4.0" '
        'xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" '
        'xsi:noNamespaceSchemaLocation="https://raw.githubusercontent.com/godotengine/godot/master/doc/class.xsd">\n'
        f"\t<brief_description>Out-parameter wrapper for {c_type}.</brief_description>\n"
        "\t<description>\n"
        f"\t\tReusable typed wrapper for {c_type} out-parameters.\n"
        "\t</description>\n"
        "\t<tutorials>\n\t</tutorials>\n"
        "\t<methods>\n"
        '\t\t<method name="get_value">\n'
        f'\t\t\t<return type="{godot_type}" />\n'
        "\t\t\t<description>Getter for value.</description>\n"
        "\t\t</method>\n"
        '\t\t<method name="set_value">\n'
        '\t\t\t<return type="void" />\n'
        f'\t\t\t<argument index="0" name="v" type="{godot_type}" />\n'
        "\t\t\t<description>Setter for value.</description>\n"
        "\t\t</method>\n"
        "\t</methods>\n"
        f'\t<members>\n'
        f'\t\t<member name="value" type="{godot_type}" setter="set_value" getter="get_value">The wrapped {c_type} value.</member>\n'
        f'\t</members>\n'
        "</class>\n"
    )


def generate_out_prim_headers() -> list[tuple[str, str]]:
    """Generate .h files for all primitive, UID, string, and byte-array wrappers."""
    files: list[tuple[str, str]] = []
    for c_type, cls, godot_type, c_to_godot, godot_to_c in OUT_PARAM_TYPES:
        files.append((_prim_header_name(cls), _prim_header(c_type, cls, godot_type, False)))
    for c_type, cls, godot_type in UID_TYPES:
        files.append((_prim_header_name(cls), _prim_header(c_type, cls, godot_type, True)))
    files.append(("OcctlString.h", STRING_H_CONTENT))
    files.append(("OcctlStringArray.h", STRING_ARRAY_H_CONTENT))
    files.append(("OcctlByteArray.h", BYTE_ARRAY_H_CONTENT))
    return files


def generate_out_prim_sources() -> list[tuple[str, str]]:
    """Generate .cpp files for all primitive, UID, string, and byte-array wrappers."""
    files: list[tuple[str, str]] = []
    for c_type, cls, godot_type, c_to_godot, godot_to_c in OUT_PARAM_TYPES:
        files.append((f"{cls}.cpp", _prim_source(c_type, cls, godot_type, False)))
    for c_type, cls, godot_type in UID_TYPES:
        files.append((f"{cls}.cpp", _prim_source(c_type, cls, godot_type, True)))
    files.append(("OcctlString.cpp", STRING_CPP_CONTENT))
    files.append(("OcctlStringArray.cpp", STRING_ARRAY_CPP_CONTENT))
    files.append(("OcctlByteArray.cpp", BYTE_ARRAY_CPP_CONTENT))
    return files


def generate_out_prim_doc_xml() -> list[tuple[str, str]]:
    """Generate XML doc files for all primitive and UID out-param wrappers."""
    files: list[tuple[str, str]] = []
    for c_type, cls, godot_type, c_to_godot, godot_to_c in OUT_PARAM_TYPES:
        files.append((f"{cls}.xml", _prim_doc_xml(c_type, cls, godot_type)))
    for c_type, cls, godot_type in UID_TYPES:
        files.append((f"{cls}.xml", _prim_doc_xml(c_type, cls, godot_type)))
    # String types
    files.append(("OcctlString.xml", _string_doc_xml()))
    files.append(("OcctlStringArray.xml", _string_array_doc_xml()))
    # ByteArray type
    files.append(("OcctlByteArray.xml", _byte_array_doc_xml()))
    return files


# ---------------------------------------------------------------------------
# OcctlString — wraps a single Godot String for const char* out-params
# ---------------------------------------------------------------------------

STRING_H_CONTENT = """\
#ifndef OCCTLSTRING_H
#define OCCTLSTRING_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/string.hpp>

using namespace godot;

class OcctlString : public godot::RefCounted {
    GDCLASS(OcctlString, godot::RefCounted)
    String _value{};
protected:
    static void _bind_methods();
public:
    String get_value() const;
    void set_value(const String& v);
    void copy_from_c(const char* v);
};

#endif // OCCTLSTRING_H
"""

STRING_CPP_CONTENT = """\
#include "OcctlString.h"

String OcctlString::get_value() const {
    return _value;
}

void OcctlString::set_value(const String& v) {
    _value = v;
}

void OcctlString::copy_from_c(const char* v) {
    _value = v ? String(v) : String();
}

void OcctlString::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_value"), &OcctlString::get_value);
    godot::ClassDB::bind_method(godot::D_METHOD("set_value", "v"), &OcctlString::set_value);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "value"), "set_value", "get_value");
}
"""


def _string_doc_xml() -> str:
    return (
        '<?xml version="1.0" encoding="UTF-8" ?>\n'
        '<class name="OcctlString" inherits="RefCounted" version="4.0" '
        'xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" '
        'xsi:noNamespaceSchemaLocation="https://raw.githubusercontent.com/godotengine/godot/master/doc/class.xsd">\n'
        '\t<brief_description>Out-parameter wrapper for const char*.</brief_description>\n'
        '\t<description>\n'
        '\t\tReusable typed wrapper for const char* out-parameters.\n'
        '\t</description>\n'
        '\t<tutorials>\n\t</tutorials>\n'
        '\t<methods>\n'
        '\t\t<method name="get_value">\n'
        '\t\t\t<return type="String" />\n'
        '\t\t\t<description>Getter for value.</description>\n'
        '\t\t</method>\n'
        '\t\t<method name="set_value">\n'
        '\t\t\t<return type="void" />\n'
        '\t\t\t<argument index="0" name="v" type="String" />\n'
        '\t\t\t<description>Setter for value.</description>\n'
        '\t\t</method>\n'
        '\t</methods>\n'
        '\t<members>\n'
        '\t\t<member name="value" type="String" setter="set_value" getter="get_value">The wrapped string value.</member>\n'
        '\t</members>\n'
        '</class>\n'
    )


# ---------------------------------------------------------------------------
# OcctlStringArray — wraps a PackedStringArray for const char** out-params
# ---------------------------------------------------------------------------

STRING_ARRAY_H_CONTENT = """\
#ifndef OCCTLSTRINGARRAY_H
#define OCCTLSTRINGARRAY_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/packed_string_array.hpp>

using namespace godot;

class OcctlStringArray : public godot::RefCounted {
    GDCLASS(OcctlStringArray, godot::RefCounted)
    PackedStringArray _value{};
protected:
    static void _bind_methods();
public:
    PackedStringArray get_strings() const;
    void set_strings(const PackedStringArray& v);
    int64_t get_count() const;
    void copy_from_c(const PackedStringArray& v);
};

#endif // OCCTLSTRINGARRAY_H
"""

STRING_ARRAY_CPP_CONTENT = """\
#include "OcctlStringArray.h"

PackedStringArray OcctlStringArray::get_strings() const {
    return _value;
}

void OcctlStringArray::set_strings(const PackedStringArray& v) {
    _value = v;
}

int64_t OcctlStringArray::get_count() const {
    return static_cast<int64_t>(_value.size());
}

void OcctlStringArray::copy_from_c(const PackedStringArray& v) {
    _value = v;
}

void OcctlStringArray::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_strings"), &OcctlStringArray::get_strings);
    godot::ClassDB::bind_method(godot::D_METHOD("set_strings", "v"), &OcctlStringArray::set_strings);
    godot::ClassDB::bind_method(godot::D_METHOD("get_count"), &OcctlStringArray::get_count);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_STRING_ARRAY, "strings"), "set_strings", "get_strings");
}
"""


def _string_array_doc_xml() -> str:
    return (
        '<?xml version="1.0" encoding="UTF-8" ?>\n'
        '<class name="OcctlStringArray" inherits="RefCounted" version="4.0" '
        'xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" '
        'xsi:noNamespaceSchemaLocation="https://raw.githubusercontent.com/godotengine/godot/master/doc/class.xsd">\n'
        '\t<brief_description>Out-parameter wrapper for const char** (string arrays).</brief_description>\n'
        '\t<description>\n'
        '\t\tReusable typed wrapper for const char** string-array out-parameters.\n'
        '\t</description>\n'
        '\t<tutorials>\n\t</tutorials>\n'
        '\t<methods>\n'
        '\t\t<method name="get_strings">\n'
        '\t\t\t<return type="PackedStringArray" />\n'
        '\t\t\t<description>Getter for the string array.</description>\n'
        '\t\t</method>\n'
        '\t\t<method name="set_strings">\n'
        '\t\t\t<return type="void" />\n'
        '\t\t\t<argument index="0" name="v" type="PackedStringArray" />\n'
        '\t\t\t<description>Setter for the string array.</description>\n'
        '\t\t</method>\n'
        '\t\t<method name="get_count">\n'
        '\t\t\t<return type="int" />\n'
        '\t\t\t<description>Number of strings in the array.</description>\n'
        '\t\t</method>\n'
        '\t</methods>\n'
        '\t<members>\n'
        '\t\t<member name="strings" type="PackedStringArray" setter="set_strings" getter="get_strings">The wrapped string array.</member>\n'
        '\t</members>\n'
        '</class>\n'
    )


# ---------------------------------------------------------------------------
# OcctlByteArray — wraps a PackedByteArray for uint8_t* buffer out-params
# ---------------------------------------------------------------------------

BYTE_ARRAY_H_CONTENT = """\
#ifndef OCCTLBYTEARRAY_H
#define OCCTLBYTEARRAY_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/packed_byte_array.hpp>

using namespace godot;

class OcctlByteArray : public godot::RefCounted {
    GDCLASS(OcctlByteArray, godot::RefCounted)
    PackedByteArray _value{};
protected:
    static void _bind_methods();
public:
    PackedByteArray get_value() const;
    void set_value(const PackedByteArray& v);
    int64_t size() const;
    void copy_from_c(const PackedByteArray& v);
};

#endif // OCCTLBYTEARRAY_H
"""

BYTE_ARRAY_CPP_CONTENT = """\
#include "OcctlByteArray.h"

PackedByteArray OcctlByteArray::get_value() const {
    return _value;
}

void OcctlByteArray::set_value(const PackedByteArray& v) {
    _value = v;
}

int64_t OcctlByteArray::size() const {
    return static_cast<int64_t>(_value.size());
}

void OcctlByteArray::copy_from_c(const PackedByteArray& v) {
    _value = v;
}

void OcctlByteArray::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_value"), &OcctlByteArray::get_value);
    godot::ClassDB::bind_method(godot::D_METHOD("set_value", "v"), &OcctlByteArray::set_value);
    godot::ClassDB::bind_method(godot::D_METHOD("size"), &OcctlByteArray::size);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_BYTE_ARRAY, "value"), "set_value", "get_value");
}
"""


def _byte_array_doc_xml() -> str:
    return (
        '<?xml version="1.0" encoding="UTF-8" ?>\n'
        '<class name="OcctlByteArray" inherits="RefCounted" version="4.0" '
        'xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" '
        'xsi:noNamespaceSchemaLocation="https://raw.githubusercontent.com/godotengine/godot/master/doc/class.xsd">\n'
        '\t<brief_description>Out-parameter wrapper for uint8_t* (byte buffers).</brief_description>\n'
        '\t<description>\n'
        '\t\tReusable typed wrapper for uint8_t* buffer out-parameters.\n'
        '\t</description>\n'
        '\t<tutorials>\n\t</tutorials>\n'
        '\t<methods>\n'
        '\t\t<method name="get_value">\n'
        '\t\t\t<return type="PackedByteArray" />\n'
        '\t\t\t<description>Getter for the byte buffer.</description>\n'
        '\t\t</method>\n'
        '\t\t<method name="set_value">\n'
        '\t\t\t<return type="void" />\n'
        '\t\t\t<argument index="0" name="v" type="PackedByteArray" />\n'
        '\t\t\t<description>Setter for the byte buffer.</description>\n'
        '\t\t</method>\n'
        '\t\t<method name="size">\n'
        '\t\t\t<return type="int" />\n'
        '\t\t\t<description>Number of bytes in the buffer.</description>\n'
        '\t\t</method>\n'
        '\t</methods>\n'
        '\t<members>\n'
        '\t\t<member name="value" type="PackedByteArray" setter="set_value" getter="get_value">The wrapped byte buffer.</member>\n'
        '\t</members>\n'
        '</class>\n'
    )
