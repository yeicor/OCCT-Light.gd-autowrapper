"""Generate Godot RefCounted wrapper classes for OCCT-Light value structs.

Each C struct like occtl_point3_t gets a dedicated Godot class (OcctlPoint3)
with typed fields and to_c()/from_c() conversion helpers.
"""

import re
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
        inner = t[:-1].strip().replace("const ", "", 1).strip()
        if inner in UINT64_ID_TYPES:
            return "PackedInt64Array"
        if inner in VALUE_STRUCT_TYPES:
            return "Array"
        if inner == "double":
            return "PackedFloat64Array"
        if inner == "float":
            return "PackedFloat32Array"
        if inner in ("int32_t", "uint32_t", "int"):
            return "PackedInt32Array"
        if inner in ("int64_t", "uint64_t"):
            return "PackedInt64Array"
        if inner == "uint8_t":
            return "PackedByteArray"
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


# Factory methods for value types: maps class_name → list of
# (method_name, [(param_name, param_type)], [assignment_lines])
FACTORY_METHODS: dict[str, list[tuple[str, list[tuple[str, str]], list[str]]]] = {
    "OcctlPoint3": [
        (
            "from_vector3",
            [("v", "Vector3")],
            [
                "instance->x = v.x;",
                "instance->y = v.y;",
                "instance->z = v.z;",
            ],
        ),
    ],
    "OcctlPoint2": [
        (
            "from_vector2",
            [("v", "Vector2")],
            [
                "instance->x = v.x;",
                "instance->y = v.y;",
            ],
        ),
    ],
    "OcctlDirection3": [
        (
            "from_vector3",
            [("v", "Vector3")],
            [
                "instance->x = v.x;",
                "instance->y = v.y;",
                "instance->z = v.z;",
            ],
        ),
    ],
    "OcctlDirection2": [
        (
            "from_vector2",
            [("v", "Vector2")],
            [
                "instance->x = v.x;",
                "instance->y = v.y;",
            ],
        ),
    ],
    "OcctlVector3": [
        (
            "from_vector3",
            [("v", "Vector3")],
            [
                "instance->x = v.x;",
                "instance->y = v.y;",
                "instance->z = v.z;",
            ],
        ),
    ],
    "OcctlVector2": [
        (
            "from_vector2",
            [("v", "Vector2")],
            [
                "instance->x = v.x;",
                "instance->y = v.y;",
            ],
        ),
    ],
    "OcctlTransform": [
        (
            "from_transform3d",
            [("t", "Transform3D")],
            [
                "instance->m.resize(12);",
                "instance->m[0] = t.basis[0].x;",
                "instance->m[1] = t.basis[0].y;",
                "instance->m[2] = t.basis[0].z;",
                "instance->m[3] = t.origin.x;",
                "instance->m[4] = t.basis[1].x;",
                "instance->m[5] = t.basis[1].y;",
                "instance->m[6] = t.basis[1].z;",
                "instance->m[7] = t.origin.y;",
                "instance->m[8] = t.basis[2].x;",
                "instance->m[9] = t.basis[2].y;",
                "instance->m[10] = t.basis[2].z;",
                "instance->m[11] = t.origin.z;",
            ],
        ),
    ],
    "OcctlAabb3": [
        (
            "from_aabb",
            [("a", "AABB")],
            [
                "{ auto _c = occtl_point3_t{}; _c.x = a.position.x; _c.y = a.position.y; _c.z = a.position.z; instance->min = OcctlPoint3::from_c(_c); }",
                "{ auto _c = occtl_point3_t{}; _c.x = a.position.x + a.size.x; _c.y = a.position.y + a.size.y; _c.z = a.position.z + a.size.z; instance->max = OcctlPoint3::from_c(_c); }",
            ],
        ),
    ],
    "OcctlColorRgba": [
        (
            "from_color",
            [("c", "Color")],
            [
                "instance->r = c.r;",
                "instance->g = c.g;",
                "instance->b = c.b;",
                "instance->a = c.a;",
            ],
        ),
    ],
    "OcctlAxis1Placement": [
        (
            "from_components",
            [("point", "Vector3"), ("direction", "Vector3")],
            [
                "{ auto _loc = occtl_point3_t{}; _loc.x = point.x; _loc.y = point.y; _loc.z = point.z; instance->location = OcctlPoint3::from_c(_loc); }",
                "{ auto _dir = occtl_direction3_t{}; _dir.x = direction.x; _dir.y = direction.y; _dir.z = direction.z; instance->direction = OcctlDirection3::from_c(_dir); }",
            ],
        ),
    ],
    "OcctlAxis2Placement": [
        (
            "from_components",
            [("point", "Vector3"), ("z_dir", "Vector3"), ("x_dir", "Vector3")],
            [
                "{ auto _loc = occtl_point3_t{}; _loc.x = point.x; _loc.y = point.y; _loc.z = point.z; instance->location = OcctlPoint3::from_c(_loc); }",
                "{ auto _x = occtl_direction3_t{}; _x.x = x_dir.x; _x.y = x_dir.y; _x.z = x_dir.z; instance->x_dir = OcctlDirection3::from_c(_x); }",
                "{ auto _ref = occtl_direction3_t{}; _ref.x = z_dir.x; _ref.y = z_dir.y; _ref.z = z_dir.z; instance->x_dir_ref = OcctlDirection3::from_c(_ref); }",
            ],
        ),
    ],
    "OcctlAxis3Placement": [
        (
            "from_components",
            [("point", "Vector3"), ("z_dir", "Vector3"), ("x_dir", "Vector3")],
            [
                "{ auto _loc = occtl_point3_t{}; _loc.x = point.x; _loc.y = point.y; _loc.z = point.z; instance->location = OcctlPoint3::from_c(_loc); }",
                "{ auto _x = occtl_direction3_t{}; _x.x = x_dir.x; _x.y = x_dir.y; _x.z = x_dir.z; instance->x_dir = OcctlDirection3::from_c(_x); }",
                "{ auto _y = occtl_direction3_t{}; _y.x = point.x; _y.y = point.y; _y.z = point.z; instance->y_dir = OcctlDirection3::from_c(_y); }",
                "{ auto _z = occtl_direction3_t{}; _z.x = z_dir.x; _z.y = z_dir.y; _z.z = z_dir.z; instance->z_dir = OcctlDirection3::from_c(_z); }",
            ],
        ),
    ],
    "OcctlAxis2Placement2d": [
        (
            "from_components",
            [("point", "Vector2"), ("z_dir", "Vector2"), ("x_dir", "Vector2")],
            [
                "(void)z_dir;",  # unused - 2D struct has no z-dir field, kept for API consistency
                "{ auto _loc = occtl_point2_t{}; _loc.x = point.x; _loc.y = point.y; instance->location = OcctlPoint2::from_c(_loc); }",
                "{ auto _x = occtl_direction2_t{}; _x.x = x_dir.x; _x.y = x_dir.y; instance->x_dir = OcctlDirection2::from_c(_x); }",
            ],
        ),
    ],
    "OcctlError": [
        (
            "from_values",
            [("status", "int"), ("message", "String")],
            [
                "instance->status = status;",
                "instance->message = message;",
            ],
        ),
    ],
}


# To-methods for value types: maps class_name → list of
# (method_name, return_type, [implementation_lines])
# These generate `to_*()` methods that convert from the value type to a
# Godot-native type.

# Godot type → parameter name mapping for auto-derived from_* factories.
_TO_REVERSE_PARAM_NAME: dict[str, str] = {
    "Vector3": "v",
    "Vector2": "v",
    "Transform3D": "t",
    "AABB": "a",
    "Color": "c",
}


def _reverse_to_method_body_assignments(
    body_lines: list[str], ret_type: str
) -> list[str] | None:
    """Try to reverse a TO_METHOD body into factory body assignments.

    Given a to_*() body like:
        Vector3 result;
        result.x = x;
        result.y = y;
        result.z = z;
        return result;

    Produces assignments for the reverse factory:
        instance->x = v.x;
        instance->y = v.y;
        instance->z = v.z;

    Returns None if the body cannot be reversed (too complex).
    """
    param_name = _TO_REVERSE_PARAM_NAME.get(ret_type)
    if param_name is None:
        return None

    lines = []
    for line in body_lines:
        stripped = line.strip()
        # Skip declaration lines (contain the return type name)
        if stripped.startswith(ret_type) and "result" in stripped:
            continue
        # Skip return statements
        if stripped.startswith("return "):
            continue
        # Skip empty lines
        if not stripped:
            continue
        # Handle: result.X = Y;
        m = re.match(r"^result\.(\w+)\s*=\s*(\w+);?", stripped)
        if m:
            field = m.group(1)
            c_field = m.group(2)
            lines.append(f"instance->{c_field} = {param_name}.{field};")
            continue
        # Handle: result.basis[i][j] = field;
        m = re.match(
            r"^result\.basis\[(\d+)\]\[(\d+)\]\s*=\s*(\w+)\[(\d+)\];?", stripped
        )
        if m:
            arr_name = m.group(3)
            idx = m.group(4)
            i = m.group(1)
            j = m.group(2)
            lines.append(f"instance->{arr_name}[{idx}] = {param_name}.basis[{i}][{j}];")
            continue
        # Handle: result.origin.X = field;
        m = re.match(r"^result\.origin\.(\w+)\s*=\s*(\w+)\[(\d+)\];?", stripped)
        if m:
            comp = m.group(1)
            arr_name = m.group(2)
            idx = m.group(3)
            lines.append(f"instance->{arr_name}[{idx}] = {param_name}.origin.{comp};")
            continue
        # Handle: return Type(r, g, b, a);
        m = re.match(r"^return\s+\w+\s*\((.*)\)\s*;?", stripped)
        if m:
            args = [a.strip() for a in m.group(1).split(",")]
            if ret_type == "Color" and len(args) == 4:
                lines.append(f"instance->r = {param_name}.r;")
                lines.append(f"instance->g = {param_name}.g;")
                lines.append(f"instance->b = {param_name}.b;")
                lines.append(f"instance->a = {param_name}.a;")
                continue
            # Cannot reverse complex constructors
            return None
        # Cannot reverse this line
        return None

    if not lines:
        return None
    return lines


TO_METHODS: dict[str, list[tuple[str, str, list[str]]]] = {
    "OcctlPoint3": [
        (
            "to_vector3",
            "Vector3",
            [
                "Vector3 result;",
                "result.x = x;",
                "result.y = y;",
                "result.z = z;",
                "return result;",
            ],
        ),
    ],
    "OcctlVector3": [
        (
            "to_vector3",
            "Vector3",
            [
                "Vector3 result;",
                "result.x = x;",
                "result.y = y;",
                "result.z = z;",
                "return result;",
            ],
        ),
    ],
    "OcctlDirection3": [
        (
            "to_vector3",
            "Vector3",
            [
                "Vector3 result;",
                "result.x = x;",
                "result.y = y;",
                "result.z = z;",
                "return result;",
            ],
        ),
    ],
    "OcctlPoint2": [
        (
            "to_vector2",
            "Vector2",
            [
                "Vector2 result;",
                "result.x = x;",
                "result.y = y;",
                "return result;",
            ],
        ),
    ],
    "OcctlVector2": [
        (
            "to_vector2",
            "Vector2",
            [
                "Vector2 result;",
                "result.x = x;",
                "result.y = y;",
                "return result;",
            ],
        ),
    ],
    "OcctlDirection2": [
        (
            "to_vector2",
            "Vector2",
            [
                "Vector2 result;",
                "result.x = x;",
                "result.y = y;",
                "return result;",
            ],
        ),
    ],
    "OcctlTransform": [
        (
            "to_transform3d",
            "Transform3D",
            [
                "Transform3D result;",
                "result.basis[0][0] = m[0];",
                "result.basis[0][1] = m[1];",
                "result.basis[0][2] = m[2];",
                "result.origin.x = m[3];",
                "result.basis[1][0] = m[4];",
                "result.basis[1][1] = m[5];",
                "result.basis[1][2] = m[6];",
                "result.origin.y = m[7];",
                "result.basis[2][0] = m[8];",
                "result.basis[2][1] = m[9];",
                "result.basis[2][2] = m[10];",
                "result.origin.z = m[11];",
                "return result;",
            ],
        ),
    ],
    "OcctlAabb3": [
        (
            "to_aabb",
            "AABB",
            [
                "AABB result;",
                "result.position = Vector3(min->get_x(), min->get_y(), min->get_z());",
                "result.size = Vector3(max->get_x() - min->get_x(), max->get_y() - min->get_y(), max->get_z() - min->get_z());",
                "return result;",
            ],
        ),
    ],
    "OcctlColorRgba": [
        (
            "to_color",
            "Color",
            [
                "return Color(r, g, b, a);",
            ],
        ),
    ],
    "OcctlAxis1Placement": [
        (
            "to_transform3d",
            "Transform3D",
            [
                "Transform3D result;",
                "{",
                "    const double zx = direction->get_x(), zy = direction->get_y(), zz = direction->get_z();",
                "    double xd_x, xd_y, xd_z;",
                "    const double azx = std::fabs(zx), azy = std::fabs(zy), azz = std::fabs(zz);",
                "    if (azx <= azy && azx <= azz) {",
                "        xd_x = 0.0; xd_y = zz; xd_z = -zy;",
                "    } else if (azy <= azx && azy <= azz) {",
                "        xd_x = -zz; xd_y = 0.0; xd_z = zx;",
                "    } else {",
                "        xd_x = zy; xd_y = -zx; xd_z = 0.0;",
                "    }",
                "    const double x_len = std::sqrt(xd_x * xd_x + xd_y * xd_y + xd_z * xd_z);",
                "    if (x_len < 1e-15) return Transform3D();",
                "    const double inv_x = 1.0 / x_len;",
                "    xd_x *= inv_x; xd_y *= inv_x; xd_z *= inv_x;",
                "    const double yd_x = zy * xd_z - zz * xd_y;",
                "    const double yd_y = zz * xd_x - zx * xd_z;",
                "    const double yd_z = zx * xd_y - zy * xd_x;",
                "    Basis basis;",
                "    basis.rows[0] = Vector3(xd_x, xd_y, xd_z);",
                "    basis.rows[1] = Vector3(yd_x, yd_y, yd_z);",
                "    basis.rows[2] = Vector3(zx, zy, zz);",
                "    result.set_basis(basis);",
                "    result.set_origin(Vector3(location->get_x(), location->get_y(), location->get_z()));",
                "}",
                "return result;",
            ],
        ),
    ],
    "OcctlAxis2Placement": [
        (
            "to_transform3d",
            "Transform3D",
            [
                "Transform3D result;",
                "{",
                "    const double x_x = x_dir->get_x(), x_y = x_dir->get_y(), x_z = x_dir->get_z();",
                "    const double dot = x_x * x_dir_ref->get_x() + x_y * x_dir_ref->get_y() + x_z * x_dir_ref->get_z();",
                "    double y_x = x_dir_ref->get_x() - dot * x_x;",
                "    double y_y = x_dir_ref->get_y() - dot * x_y;",
                "    double y_z = x_dir_ref->get_z() - dot * x_z;",
                "    const double y_len = std::sqrt(y_x * y_x + y_y * y_y + y_z * y_z);",
                "    if (y_len < 1e-15) return Transform3D();",
                "    const double inv_y = 1.0 / y_len;",
                "    y_x *= inv_y; y_y *= inv_y; y_z *= inv_y;",
                "    const double z_x = x_y * y_z - x_z * y_y;",
                "    const double z_y = x_z * y_x - x_x * y_z;",
                "    const double z_z = x_x * y_y - x_y * y_x;",
                "    Basis basis;",
                "    basis.rows[0] = Vector3(x_x, x_y, x_z);",
                "    basis.rows[1] = Vector3(y_x, y_y, y_z);",
                "    basis.rows[2] = Vector3(z_x, z_y, z_z);",
                "    result.set_basis(basis);",
                "    result.set_origin(Vector3(location->get_x(), location->get_y(), location->get_z()));",
                "}",
                "return result;",
            ],
        ),
    ],
    "OcctlAxis3Placement": [
        (
            "to_transform3d",
            "Transform3D",
            [
                "Transform3D result;",
                "{",
                "    Basis basis;",
                "    basis.rows[0] = Vector3(x_dir->get_x(), x_dir->get_y(), x_dir->get_z());",
                "    basis.rows[1] = Vector3(y_dir->get_x(), y_dir->get_y(), y_dir->get_z());",
                "    basis.rows[2] = Vector3(z_dir->get_x(), z_dir->get_y(), z_dir->get_z());",
                "    result.set_basis(basis);",
                "    result.set_origin(Vector3(location->get_x(), location->get_y(), location->get_z()));",
                "}",
                "return result;",
            ],
        ),
    ],
}


_AUTOWRAPPER_WARNING = (
    "// ---------------------------------------------------------------------------\n"
    "// This file was auto-generated by the OCCT-Light.gd-autowrapper.\n"
    "// DO NOT EDIT IT DIRECTLY. Make changes to the Python generator instead.\n"
    "// ---------------------------------------------------------------------------"
)


def generate_value_type_header(struct: CStruct) -> str:
    """Generate the .h file for a value type class."""
    cls = c_type_to_godot_class(struct.type_name)
    c_type = struct.type_name
    guard = f"{cls.upper()}_H"

    lines = [
        _AUTOWRAPPER_WARNING,
        "",
        f"#ifndef {guard}",
        f"#define {guard}",
        "",
        "#include <godot_cpp/classes/ref.hpp>",
        "#include <godot_cpp/core/class_db.hpp>",
        "#include <godot_cpp/variant/utility_functions.hpp>",
        "#include <godot_cpp/variant/string.hpp>",
        "#include <godot_cpp/variant/vector3.hpp>",
        "#include <godot_cpp/variant/vector2.hpp>",
        "#include <godot_cpp/variant/transform3d.hpp>",
        "#include <godot_cpp/variant/aabb.hpp>",
        "#include <godot_cpp/variant/color.hpp>",
        "#include <cstdint>",
        "#include <cmath>",
        "#include <vector>",
        f'#include "occtl/{struct.header_include}"',
        "",
    ]

    # Add includes for sub-value type fields
    added_includes = set()
    for field in struct.fields:
        ft = field.type_name.strip()
        base = ft.rstrip("* \t").replace("const ", "", 1).strip()
        if base in VALUE_STRUCT_TYPES or is_value_struct_type(base):
            sub_cls = c_type_to_godot_class(base)
            if sub_cls != cls and sub_cls not in added_includes:
                lines.append(f'#include "{sub_cls}.h"')
                added_includes.add(sub_cls)

    lines.extend(
        [
            "",
            "using namespace godot;",
            "",
            f"class {cls} : public godot::RefCounted {{",
            f"    GDCLASS({cls}, godot::RefCounted)",
            "protected:",
            "    static void _bind_methods();",
            "public:",
        ]
    )

    # Fields
    for field in struct.fields:
        gt = _field_godot_type(field)
        clean = _field_clean_name(field)
        if _field_is_array(field):
            # Use PackedFloat64Array for double arrays, Array for others
            arr_type = (
                "PackedFloat64Array" if field.type_name.strip() == "double" else "Array"
            )
            lines.append(f"    {arr_type} {clean};")
        else:
            lines.append(f"    {gt} {clean};")

        t = field.type_name.strip()
        if t.endswith("*") and not t.startswith("const ") and not t.endswith("**"):
            t = "const " + t
        if t.startswith("const ") and t.endswith("*") and gt == "Array":
            # Add a mutable cache for structured arrays
            inner = t[len("const ") : -1].strip()
            lines.append(f"    mutable std::vector<{inner}> _cache_{clean};")

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
    # Static factory methods (explicit + auto-derived from TO_METHODS)
    if cls in FACTORY_METHODS:
        lines.append("")
        for method_name, params, _ in FACTORY_METHODS[cls]:
            param_decls = ", ".join(f"{pt} {pn}" for pn, pt in params)
            lines.append(
                f"    static Ref<{cls}> {method_name}({param_decls}); // NOLINT"
            )
    # Auto-derive from_* factory methods from TO_METHODS entries not already in FACTORY_METHODS
    if cls in TO_METHODS:
        explicit_factory_names = {name for name, _, _ in FACTORY_METHODS.get(cls, [])}
        for method_name, ret_type, body in TO_METHODS[cls]:
            from_name = "from_" + method_name[len("to_") :]
            if from_name in explicit_factory_names:
                continue  # Already has explicit factory
            # Try to auto-derive
            param_name = _TO_REVERSE_PARAM_NAME.get(ret_type)
            if (
                param_name is not None
                and _reverse_to_method_body_assignments(body, ret_type) is not None
            ):
                lines.append(
                    f"    static Ref<{cls}> {from_name}(const {ret_type}& {param_name}); // NOLINT (auto-derived)"
                )
    # To-methods (convert to Godot native type)
    if cls in TO_METHODS:
        for method_name, ret_type, _ in TO_METHODS[cls]:
            lines.append(f"    {ret_type} {method_name}() const;")
    lines.append("};")  # class close
    lines.append("")
    lines.append(f"#endif // {guard}")
    lines.append("")

    return "\n".join(lines)


def generate_value_type_source(struct: CStruct, all_types: dict[str, CStruct]) -> str:
    """Generate the .cpp file for a value type class."""
    cls = c_type_to_godot_class(struct.type_name)
    c_type = struct.type_name

    lines = [
        _AUTOWRAPPER_WARNING,
        "",
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
        lines.append(
            f'    godot::ClassDB::bind_method(godot::D_METHOD("get_{clean}"), &{cls}::get_{clean});'
        )
        lines.append(
            f'    godot::ClassDB::bind_method(godot::D_METHOD("set_{clean}", "val"), &{cls}::set_{clean});'
        )
        lines.append(
            f'    ADD_PROPERTY(PropertyInfo(Variant::{vt}, "{clean}"), "set_{clean}", "get_{clean}");'
        )
    # Factory methods (explicit + auto-derived from TO_METHODS)
    if cls in FACTORY_METHODS:
        for method_name, params, _ in FACTORY_METHODS[cls]:
            param_str = ", ".join(f'"{pn}"' for pn, _ in params)
            if param_str:
                param_str = ", " + param_str
            lines.append(
                f'    godot::ClassDB::bind_static_method("{cls}", godot::D_METHOD("{method_name}"{param_str}), &{cls}::{method_name});'
            )
    # Auto-derived factory methods from TO_METHODS
    if cls in TO_METHODS:
        explicit_factory_names = {name for name, _, _ in FACTORY_METHODS.get(cls, [])}
        for method_name, ret_type, body in TO_METHODS[cls]:
            from_name = "from_" + method_name[len("to_") :]
            if from_name in explicit_factory_names:
                continue
            param_name = _TO_REVERSE_PARAM_NAME.get(ret_type)
            if param_name is None:
                continue
            rev = _reverse_to_method_body_assignments(body, ret_type)
            if rev is None:
                continue
            lines.append(
                f'    godot::ClassDB::bind_static_method("{cls}", godot::D_METHOD("{from_name}", "{param_name}"), &{cls}::{from_name});'
            )
    if cls in TO_METHODS:
        for method_name, ret_type, _ in TO_METHODS[cls]:
            lines.append(
                f'    godot::ClassDB::bind_method(godot::D_METHOD("{method_name}"), &{cls}::{method_name});'
            )
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
            gt = _field_godot_type(field)
            if gt.startswith("Packed"):
                inner = t[len("const ") : -1].strip()
                # Check if inner is a UINT64_ID struct type — needs cast from int64_t*
                if inner in UINT64_ID_TYPES and gt == "PackedInt64Array":
                    lines.append(
                        f"    result.{clean} = reinterpret_cast<const {inner}*>({clean}.ptr());"
                    )
                elif inner == "uint32_t" and gt == "PackedInt32Array":
                    lines.append(
                        f"    result.{clean} = reinterpret_cast<const uint32_t*>({clean}.ptr());"
                    )
                elif inner == "uint64_t" and gt == "PackedInt64Array":
                    lines.append(
                        f"    result.{clean} = reinterpret_cast<const uint64_t*>({clean}.ptr());"
                    )
                else:
                    lines.append(f"    result.{clean} = {clean}.ptr();")
            elif gt == "Array":
                inner = t[len("const ") : -1].strip()
                sub_cls = c_type_to_godot_class(inner)
                lines.append(f"    _cache_{clean}.resize({clean}.size());")
                lines.append(f"    for (int _i = 0; _i < {clean}.size(); _i++) {{")
                lines.append(f"        Ref<{sub_cls}> _item = {clean}[_i];")
                lines.append(
                    f"        if (_item.is_valid()) _cache_{clean}[_i] = _item->to_c();"
                )
                lines.append(f"        else _cache_{clean}[_i] = {{}};")
                lines.append(f"    }}")
                lines.append(f"    result.{clean} = _cache_{clean}.data();")
            else:
                lines.append(
                    f"    // const pointer field {clean}: not convertible (type {gt})"
                )
        elif t.endswith("*"):
            inner = t[:-1].strip()
            if inner in UINT64_ID_TYPES:
                lines.append(
                    f"    // pointer to {inner} field not directly representable"
                )
            elif _is_value_struct(inner):
                lines.append(
                    f"    // value pointer field {clean}: use .to_c() and address"
                )
            elif inner == "char":
                lines.append(
                    f"    result.{clean} = const_cast<char*>(({clean}).utf8().get_data());"
                )
            else:
                lines.append(
                    f"    result.{clean} = reinterpret_cast<{t}>(static_cast<uintptr_t>({clean}));"
                )
        elif t in ("occtl_status_t",):
            lines.append(f"    result.{clean} = static_cast<{t}>({clean});")
        elif _is_uint64_id(t):
            lines.append(f"    result.{clean}.bits = static_cast<uint64_t>({clean});")
        elif _is_value_struct(t):
            sub_cls = c_type_to_godot_class(t)
            lines.append(f"    result.{clean} = {clean}->to_c();")
        elif _field_is_array(field):
            size = _field_array_size(field)
            lines.append(
                f"    for (int _i = 0; _i < {size}; _i++) result.{clean}[_i] = {clean}[_i];"
            )
        elif t in (
            "double",
            "float",
            "bool",
            "int32_t",
            "uint32_t",
            "uint16_t",
            "int64_t",
            "uint64_t",
            "size_t",
            "int",
        ):
            lines.append(f"    result.{clean} = {clean};")
        elif _is_enum_type(t):
            lines.append(f"    result.{clean} = static_cast<{t}>({clean});")
        else:
            raise ValueError(
                f"Unhandled type '{t}' in to_c() for field '{clean}' of {c_type}"
            )
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
            lines.append(
                f"    r->{clean} = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.{clean}));"
            )
        elif t.startswith("const ") and t.endswith("*"):
            gt = _field_godot_type(field)
            if gt.startswith("Packed") or gt == "Array":
                lines.append(f"    // array field {clean} is not populated from C")
            else:
                inner = t[len("const ") : -1].strip()
                if _is_uint64_id(inner):
                    lines.append(
                        f"    if (val.{clean}) r->{clean} = static_cast<int64_t>(val.{clean}->bits);"
                    )
                elif inner in VALUE_STRUCT_TYPES:
                    sub_cls = c_type_to_godot_class(inner)
                    lines.append(
                        f"    if (val.{clean}) r->{clean} = {sub_cls}::from_c(*val.{clean});"
                    )
                elif inner == "char":
                    lines.append(
                        f"    if (val.{clean}) r->{clean} = String(val.{clean});"
                    )
                else:
                    lines.append(
                        f"    r->{clean} = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.{clean}));"
                    )
        elif t.endswith("*") and not t.startswith("const"):
            inner = t[:-1].strip()
            if inner == "char":
                lines.append(f"    r->{clean} = String(val.{clean});")
            elif _is_value_struct(inner):
                sub_cls = c_type_to_godot_class(inner)
                lines.append(f"    r->{clean} = {sub_cls}::from_c(*val.{clean});")
            elif _is_uint64_id(inner):
                lines.append(
                    f"    r->{clean} = static_cast<int64_t>(val.{clean}->bits);"
                )
            else:
                lines.append(
                    f"    r->{clean} = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.{clean}));"
                )
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
            lines.append(
                f"    for (int _i = 0; _i < {size}; _i++) r->{clean}[_i] = val.{clean}[_i];"
            )
        elif t in (
            "double",
            "float",
            "bool",
            "int32_t",
            "uint32_t",
            "uint16_t",
            "int64_t",
            "uint64_t",
            "size_t",
            "int",
        ):
            lines.append(f"    r->{clean} = val.{clean};")
        elif _is_enum_type(t):
            lines.append(f"    r->{clean} = static_cast<int>(val.{clean});")
        else:
            raise ValueError(
                f"Unhandled type '{t}' in from_c() for field '{clean}' of {c_type}"
            )
    lines.append("    return r;")
    lines.append("}")
    lines.append("")

    # copy_from_c() — instance method, modifies in-place
    lines.append(f"void {cls}::copy_from_c(const {c_type}& val) {{")
    for field in struct.fields:
        t = field.type_name.strip()
        clean = _field_clean_name(field)
        if t == "const void*":
            lines.append(
                f"    {clean} = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.{clean}));"
            )
        elif t.startswith("const ") and t.endswith("*"):
            gt = _field_godot_type(field)
            if gt.startswith("Packed") or gt == "Array":
                lines.append(f"    // array field {clean} is not populated from C")
            else:
                inner = t[len("const ") : -1].strip()
                if _is_uint64_id(inner):
                    lines.append(
                        f"    if (val.{clean}) {clean} = static_cast<int64_t>(val.{clean}->bits);"
                    )
                elif inner in VALUE_STRUCT_TYPES:
                    sub_cls = c_type_to_godot_class(inner)
                    lines.append(
                        f"    if (val.{clean}) {clean} = {sub_cls}::from_c(*val.{clean});"
                    )
                elif inner == "char":
                    lines.append(f"    if (val.{clean}) {clean} = String(val.{clean});")
                else:
                    lines.append(
                        f"    {clean} = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.{clean}));"
                    )
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
                lines.append(
                    f"    {clean} = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.{clean}));"
                )
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
            lines.append(
                f"    for (int _i = 0; _i < {size}; _i++) {clean}[_i] = val.{clean}[_i];"
            )
        elif t in (
            "double",
            "float",
            "bool",
            "int32_t",
            "uint32_t",
            "uint16_t",
            "int64_t",
            "uint64_t",
            "size_t",
            "int",
        ):
            lines.append(f"    {clean} = val.{clean};")
        elif _is_enum_type(t):
            lines.append(f"    {clean} = static_cast<int>(val.{clean});")
        else:
            raise ValueError(
                f"Unhandled type '{t}' in copy_from_c() for field '{clean}' of {c_type}"
            )
    lines.append("}")
    lines.append("")

    # Factory method implementations (explicit + auto-derived from TO_METHODS)
    if cls in FACTORY_METHODS:
        for method_name, params, assignments in FACTORY_METHODS[cls]:
            param_decls = ", ".join(f"{pt} {pn}" for pn, pt in params)
            lines.append(f"Ref<{cls}> {cls}::{method_name}({param_decls}) {{")
            lines.append(f"    Ref<{cls}> instance;")
            lines.append(f"    instance.instantiate();")
            for assignment in assignments:
                lines.append(f"    {assignment}")
            lines.append("    return instance;")
            lines.append("}")
            lines.append("")

    # Auto-derived from_* factory methods from TO_METHODS
    if cls in TO_METHODS:
        explicit_factory_names = {name for name, _, _ in FACTORY_METHODS.get(cls, [])}
        for method_name, ret_type, body in TO_METHODS[cls]:
            from_name = "from_" + method_name[len("to_") :]
            if from_name in explicit_factory_names:
                continue  # Already has explicit factory
            param_name = _TO_REVERSE_PARAM_NAME.get(ret_type)
            if param_name is None:
                continue
            rev_assignments = _reverse_to_method_body_assignments(body, ret_type)
            if rev_assignments is None:
                continue
            lines.append(
                f"Ref<{cls}> {cls}::{from_name}(const {ret_type}& {param_name}) {{"
            )
            lines.append(f"    Ref<{cls}> instance;")
            lines.append(f"    instance.instantiate();")
            # For array-based fields (e.g. Transform's m vector), prepend resize
            # Detect by looking for instance->field[idx] = ... assignments
            _resized: set[str] = set()
            for assn in rev_assignments:
                m_r = re.match(r"instance->(\w+)\[(\d+)\]", assn)
                if m_r and m_r.group(1) not in _resized:
                    _resized.add(m_r.group(1))
                    # No resize needed for raw arrays - std::vector would need it
            for assn in rev_assignments:
                lines.append(f"    {assn}")
            lines.append("    return instance;")
            lines.append("}")
            lines.append("")

    # To-method implementations
    if cls in TO_METHODS:
        for method_name, ret_type, body in TO_METHODS[cls]:
            lines.append(f"{ret_type} {cls}::{method_name}() const {{")
            for line in body:
                lines.append(f"    {line}")
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
        methods.append(f"\t\t\t\tReturns the [member {clean}] value.")
        methods.append("\t\t\t</description>")
        methods.append("\t\t</method>")
        methods.append(f'\t\t<method name="set_{clean}">')
        methods.append(f'\t\t\t<return type="void" />')
        methods.append(f'\t\t\t<argument index="0" name="val" type="{gt}" />')
        methods.append("\t\t\t<description>")
        methods.append(f"\t\t\t\tSets the [member {clean}] value.")
        methods.append("\t\t\t</description>")
        methods.append("\t\t</method>")

    # Factory method doc entries
    if cls in FACTORY_METHODS:
        for method_name, params, _ in FACTORY_METHODS[cls]:
            methods.append(f'\t\t<method name="{method_name}">')
            methods.append(f'\t\t\t<return type="RefCounted" />')
            for i, (pn, pt) in enumerate(params):
                methods.append(
                    f'\t\t\t<argument index="{i}" name="{pn}" type="{pt}" />'
                )
            methods.append("\t\t\t<description>")
            methods.append(
                f"\t\t\t\tConstructs a [{cls}] from Godot-native components."
            )
            for pn, pt in params:
                methods.append(f"\t\t\t\t[param {pn}] Input {pt} value.")
            methods.append(f"\t\t\t\t[return] A new [{cls}] with fields populated.")
            methods.append("\t\t\t</description>")
            methods.append("\t\t</method>")

    # To-method doc entries
    if cls in TO_METHODS:
        for method_name, ret_type, _ in TO_METHODS[cls]:
            methods.append(f'\t\t<method name="{method_name}">')
            methods.append(f'\t\t\t<return type="{ret_type}" />')
            methods.append("\t\t\t<description>")
            methods.append(f"\t\t\t\tConverts this [{cls}] to a [{ret_type}].")
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
