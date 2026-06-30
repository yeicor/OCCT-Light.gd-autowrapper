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


# ---------------------------------------------------------------
# Pointer+count array pair detection for struct fields
# ---------------------------------------------------------------


def _singularize(name: str) -> str:
    """Simple singularization of English words for field name matching."""
    # -ies -> -y (e.g., multiplicities -> multiplicity)
    if name.endswith("ies") and len(name) > 3:
        return name[:-3] + "y"
    # Strip trailing 's' (e.g., poles -> pole, knots -> knot, weights -> weight)
    if name.endswith("s") and len(name) > 1:
        return name[:-1]
    return name


# Manual overrides for pointer+count pairs that the name-based heuristic can't detect.
# Maps struct_type_name -> {pointer_field_clean_name: count_field_clean_name}
# These cover cases like `weights` sharing `pole_count`, `multiplicities` sharing `knot_count`,
# and other patterns where the pointer name doesn't singularize to the count field's base name.
_PTR_SIZE_PAIR_OVERRIDES: dict[str, dict[str, str]] = {
    # ---- Curve B-spline create info ----
    "occtl_curve_bspline_create_info_t": {
        "weights": "pole_count",
        "multiplicities": "knot_count",
    },
    # ---- Curve Bezier create info ----
    "occtl_curve_bezier_create_info_t": {
        "weights": "pole_count",
    },
    # ---- 2D Curve B-spline create info ----
    "occtl_curve2d_bspline_create_info_t": {
        "weights": "pole_count",
        "multiplicities": "knot_count",
    },
    # ---- 2D Curve Bezier create info ----
    "occtl_curve2d_bezier_create_info_t": {
        "weights": "pole_count",
    },
    # ---- Curve B-spline result view ----
    "occtl_curve_bspline_t": {
        "weights": "pole_count",
        "multiplicities": "knot_count",
    },
    # ---- 2D Curve B-spline result view ----
    "occtl_curve2d_bspline_t": {
        "weights": "pole_count",
        "multiplicities": "knot_count",
    },
    # ---- Surface B-spline create info ----
    "occtl_surface_bspline_create_info_t": {
        "poles": "u_pole_count",
        "weights": "u_pole_count",
        "u_multiplicities": "u_knot_count",
        "v_multiplicities": "v_knot_count",
    },
    # ---- Surface B-spline result view ----
    "occtl_surface_bspline_t": {
        "poles": "u_pole_count",
        "weights": "u_pole_count",
        "u_multiplicities": "u_knot_count",
        "v_multiplicities": "v_knot_count",
    },
    # ---- Surface Bezier create info ----
    "occtl_surface_bezier_create_info_t": {
        "poles": "u_pole_count",
        "weights": "u_pole_count",
    },
    # ---- Triangulation view (normals/uvs share node_count) ----
    "occtl_triangulation_view_t": {
        "normals": "node_count",
        "uvs": "node_count",
    },
    # ---- Polygon3D view (parameters share node_count) ----
    "occtl_polygon3d_view_t": {
        "parameters": "node_count",
    },
    # ---- Polygon on tri view (node_indices and parameters share node_count) ----
    "occtl_polygon_on_tri_view_t": {
        "node_indices": "node_count",
        "parameters": "node_count",
    },
    # ---- Triangle analysis view (normals/adjacency share triangle_count) ----
    "occtl_mesh_triangle_analysis_view_t": {
        "triangle_normals": "triangle_count",
        "triangle_adjacency": "triangle_count",
    },
    # ---- Triangle components view ----
    "occtl_mesh_triangle_components_view_t": {
        "triangle_component_ids": "triangle_count",
        "component_sizes": "component_count",
    },
    # ---- Pipe shell interpolated law info ----
    "occtl_prim_pipe_shell_interpolated_law_info_t": {
        "parameters": "sample_count",
        "scales": "sample_count",
    },
}


def _is_ptrsize_compatible_inner(inner: str) -> bool:
    """Check if a C type (stripped of const/*) is suitable for array wrapping."""
    from type_map import INPUT_PTR_SIZE_ARRAY_TYPES

    if inner in INPUT_PTR_SIZE_ARRAY_TYPES:
        return True
    if inner in VALUE_STRUCT_TYPES:
        return True
    if _is_uint64_id(inner):
        return True
    return False


def _find_field_ptr_size_pairs(struct: CStruct) -> dict[str, str]:
    """Find (pointer_field_clean_name -> count_field_clean_name) pairs.

    For const pointer fields with a companion size_t count field,
    return the mapping from pointer field name to count field name.
    Uses name-based heuristics first, then manual overrides, then a
    second-pass for unpaired pointers with compatible element types.
    """
    size_fields: dict[str, CField] = {}
    ptr_fields: list[tuple[str, CField]] = []

    for field in struct.fields:
        t = field.type_name.strip()
        clean = _field_clean_name(field)
        if t == "size_t":
            size_fields[clean] = field
        elif t.startswith("const ") and t.endswith("*") and not t.endswith("**"):
            inner = t[len("const ") : -1].strip()
            if inner not in ("char", "void"):
                ptr_fields.append((clean, field))

    pairs: dict[str, str] = {}

    # --- Pass 1: Check manual overrides ---
    overrides = _PTR_SIZE_PAIR_OVERRIDES.get(struct.type_name, {})
    for pclean, sclean in overrides.items():
        # Verify both fields actually exist in the struct
        if pclean in {c for c, _ in ptr_fields} and sclean in size_fields:
            pairs[pclean] = sclean

    # --- Pass 2: Name-based heuristic for remaining pointers ---
    remaining_ptr = [(c, f) for c, f in ptr_fields if c not in pairs]
    for clean, _field in remaining_ptr:
        singular = _singularize(clean)
        candidates = [
            f"{singular}_count",
            f"{clean}_count",
            f"{singular}_size",
            f"{clean}_size",
            f"{singular}_len",
            f"{clean}_len",
        ]
        for cand in candidates:
            if cand in size_fields:
                pairs[clean] = cand
                break

    # --- Pass 3: Broader heuristic for remaining unpaired pointers ---
    # For pointer fields whose element type is suitable for arrays, try to find
    # ANY size_t field (paired or unpaired) where the count field's clean name
    # contains the singularized pointer name.
    remaining_ptr = [(c, f) for c, f in ptr_fields if c not in pairs]
    for clean, field in remaining_ptr:
        inner = _pair_element_type(field)
        if inner is None or not _is_ptrsize_compatible_inner(inner):
            continue
        singular = _singularize(clean)
        # Try to find a size_t field whose name contains the singular form
        for sclean in size_fields:
            if sclean in pairs.values():
                continue  # Already paired with someone else — don't share unless override
            if singular in sclean or clean in sclean:
                pairs[clean] = sclean
                break

    return pairs


def _pair_element_type(field: CField) -> str | None:
    """Get the C element type for a paired pointer field, or None if not a const pointer."""
    t = field.type_name.strip()
    if t.startswith("const ") and t.endswith("*") and not t.endswith("**"):
        return t[len("const ") : -1].strip()
    return None


def _pair_godot_array_type(element_type: str) -> str:
    """Map a C element type to the Godot array type for paired pointer fields."""
    from type_map import INPUT_PTR_SIZE_ARRAY_TYPES

    if element_type in INPUT_PTR_SIZE_ARRAY_TYPES:
        return INPUT_PTR_SIZE_ARRAY_TYPES[element_type]
    # Value struct types not in INPUT_PTR_SIZE_ARRAY_TYPES
    if element_type in VALUE_STRUCT_TYPES or is_value_struct_type(element_type):
        return "Array"
    if _is_uint64_id(element_type):
        return "PackedInt64Array"
    # Fallback for unknown pointer types
    return "int64_t"


def _field_godot_type(field: CField, pairs: dict[str, str] | None = None) -> str:
    t = field.type_name.strip()
    if pairs is None:
        pairs = {}

    # Check if this is a paired const pointer field (array type)
    if t.startswith("const ") and t.endswith("*") and not t.endswith("**"):
        clean = _field_clean_name(field)
        if clean in pairs:
            inner = t[len("const ") : -1].strip()
            return _pair_godot_array_type(inner)

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
            return "int64_t"
        if inner in VALUE_STRUCT_TYPES:
            return f"Ref<{c_type_to_godot_class(inner)}>"
        if inner in (
            "double",
            "float",
            "int32_t",
            "uint32_t",
            "int",
            "int64_t",
            "uint64_t",
            "uint8_t",
        ):
            return "int64_t"
        return "int64_t"
    if _is_uint64_id(t):
        return "int64_t"
    if _is_value_struct(t):
        return f"Ref<{c_type_to_godot_class(t)}>"
    if t.endswith("_t"):
        return "int"
    raise ValueError(f"Unknown field type '{t}' in struct field '{field.name}'")


def _is_ptr_field(field: CField) -> bool:
    """Check if this C field is a pointer type (const char*, const void*, T*, etc.)."""
    t = field.type_name.strip()
    return (t.endswith("*") and not t.endswith("**")) or t in (
        "const char*",
        "const void*",
    )


def _is_const_ptr_field(field: CField) -> bool:
    """Check if this C field is a const pointer (const char*, const T*)."""
    t = field.type_name.strip()
    return t.startswith("const ") and t.endswith("*") and not t.endswith("**")


def _is_editable_ptr_field(field: CField) -> bool:
    """Check if this is a non-const pointer field (mutable output pointer)."""
    t = field.type_name.strip()
    return t.endswith("*") and not t.startswith("const ") and not t.endswith("**")


def _field_is_array(field: CField) -> bool:
    return field.array_size > 0


def _field_array_size(field: CField) -> int:
    return field.array_size


def _field_clean_name(field: CField) -> str:
    return field.name.split("[")[0].strip()


def _godot_type_to_variant_type(gt: str) -> str:
    """Map a Godot type string (e.g. "double", "Ref<OcctlPoint3>") to Variant::Type enum value."""
    mapping = {
        "double": "FLOAT",
        "float": "FLOAT",
        "int": "INT",
        "int64_t": "INT",
        "bool": "BOOL",
        "String": "STRING",
        "PackedFloat64Array": "PACKED_FLOAT64_ARRAY",
        "PackedInt32Array": "PACKED_INT32_ARRAY",
        "PackedInt64Array": "PACKED_INT64_ARRAY",
        "PackedByteArray": "PACKED_BYTE_ARRAY",
        "PackedFloat32Array": "PACKED_FLOAT32_ARRAY",
        "PackedStringArray": "PACKED_STRING_ARRAY",
        "Array": "ARRAY",
    }
    if gt in mapping:
        return mapping[gt]
    if gt.startswith("Ref<") and gt.endswith(">"):
        return "OBJECT"
    raise ValueError(f"Unknown Godot type '{gt}' for Variant mapping")


# Factory methods for value types: maps class_name → list of
# (method_name, [(param_name, param_type)], [assignment_lines])
FACTORY_METHODS: dict[str, list[tuple[str, list[tuple[str, str]], list[str]]]] = {
    "OcctlPoint3": [
        (
            "from_vector3",
            [("v", "Vector3")],
            [
                "instance->_c_struct.x = v.x;",
                "instance->_c_struct.y = v.y;",
                "instance->_c_struct.z = v.z;",
            ],
        ),
    ],
    "OcctlPoint2": [
        (
            "from_vector2",
            [("v", "Vector2")],
            [
                "instance->_c_struct.x = v.x;",
                "instance->_c_struct.y = v.y;",
            ],
        ),
    ],
    "OcctlDirection3": [
        (
            "from_vector3",
            [("v", "Vector3")],
            [
                "instance->_c_struct.x = v.x;",
                "instance->_c_struct.y = v.y;",
                "instance->_c_struct.z = v.z;",
            ],
        ),
    ],
    "OcctlDirection2": [
        (
            "from_vector2",
            [("v", "Vector2")],
            [
                "instance->_c_struct.x = v.x;",
                "instance->_c_struct.y = v.y;",
            ],
        ),
    ],
    "OcctlVector3": [
        (
            "from_vector3",
            [("v", "Vector3")],
            [
                "instance->_c_struct.x = v.x;",
                "instance->_c_struct.y = v.y;",
                "instance->_c_struct.z = v.z;",
            ],
        ),
    ],
    "OcctlVector2": [
        (
            "from_vector2",
            [("v", "Vector2")],
            [
                "instance->_c_struct.x = v.x;",
                "instance->_c_struct.y = v.y;",
            ],
        ),
    ],
    "OcctlTransform": [
        (
            "from_transform3d",
            [("t", "Transform3D")],
            [
                "instance->_c_struct.m[0] = t.basis[0].x;",
                "instance->_c_struct.m[1] = t.basis[0].y;",
                "instance->_c_struct.m[2] = t.basis[0].z;",
                "instance->_c_struct.m[3] = t.origin.x;",
                "instance->_c_struct.m[4] = t.basis[1].x;",
                "instance->_c_struct.m[5] = t.basis[1].y;",
                "instance->_c_struct.m[6] = t.basis[1].z;",
                "instance->_c_struct.m[7] = t.origin.y;",
                "instance->_c_struct.m[8] = t.basis[2].x;",
                "instance->_c_struct.m[9] = t.basis[2].y;",
                "instance->_c_struct.m[10] = t.basis[2].z;",
                "instance->_c_struct.m[11] = t.origin.z;",
            ],
        ),
    ],
    "OcctlAabb3": [
        (
            "from_aabb",
            [("a", "AABB")],
            [
                "instance->_c_struct.min.x = a.position.x; instance->_c_struct.min.y = a.position.y; instance->_c_struct.min.z = a.position.z;",
                "instance->_c_struct.max.x = a.position.x + a.size.x; instance->_c_struct.max.y = a.position.y + a.size.y; instance->_c_struct.max.z = a.position.z + a.size.z;",
            ],
        ),
    ],
    "OcctlColorRgba": [
        (
            "from_color",
            [("c", "Color")],
            [
                "instance->_c_struct.r = c.r;",
                "instance->_c_struct.g = c.g;",
                "instance->_c_struct.b = c.b;",
                "instance->_c_struct.a = c.a;",
            ],
        ),
    ],
    "OcctlAxis1Placement": [
        (
            "from_components",
            [("point", "Vector3"), ("direction", "Vector3")],
            [
                "instance->_c_struct.location.x = point.x; instance->_c_struct.location.y = point.y; instance->_c_struct.location.z = point.z;",
                "instance->_c_struct.direction.x = direction.x; instance->_c_struct.direction.y = direction.y; instance->_c_struct.direction.z = direction.z;",
            ],
        ),
    ],
    "OcctlAxis2Placement": [
        (
            "from_components",
            [("point", "Vector3"), ("z_dir", "Vector3"), ("x_dir", "Vector3")],
            [
                "instance->_c_struct.location.x = point.x; instance->_c_struct.location.y = point.y; instance->_c_struct.location.z = point.z;",
                "instance->_c_struct.x_dir.x = x_dir.x; instance->_c_struct.x_dir.y = x_dir.y; instance->_c_struct.x_dir.z = x_dir.z;",
                "instance->_c_struct.x_dir_ref.x = z_dir.x; instance->_c_struct.x_dir_ref.y = z_dir.y; instance->_c_struct.x_dir_ref.z = z_dir.z;",
            ],
        ),
    ],
    "OcctlAxis3Placement": [
        (
            "from_components",
            [("point", "Vector3"), ("z_dir", "Vector3"), ("x_dir", "Vector3")],
            [
                "instance->_c_struct.location.x = point.x; instance->_c_struct.location.y = point.y; instance->_c_struct.location.z = point.z;",
                "instance->_c_struct.x_dir.x = x_dir.x; instance->_c_struct.x_dir.y = x_dir.y; instance->_c_struct.x_dir.z = x_dir.z;",
                "instance->_c_struct.y_dir.x = point.x; instance->_c_struct.y_dir.y = point.y; instance->_c_struct.y_dir.z = point.z;",
                "instance->_c_struct.z_dir.x = z_dir.x; instance->_c_struct.z_dir.y = z_dir.y; instance->_c_struct.z_dir.z = z_dir.z;",
            ],
        ),
    ],
    "OcctlAxis2Placement2d": [
        (
            "from_components",
            [("point", "Vector2"), ("z_dir", "Vector2"), ("x_dir", "Vector2")],
            [
                "(void)z_dir;",  # unused - 2D struct has no z-dir field, kept for API consistency
                "instance->_c_struct.location.x = point.x; instance->_c_struct.location.y = point.y;",
                "instance->_c_struct.x_dir.x = x_dir.x; instance->_c_struct.x_dir.y = x_dir.y;",
            ],
        ),
    ],
    "OcctlError": [
        (
            "from_values",
            [("status", "int"), ("message", "String")],
            [
                "instance->_c_struct.status = static_cast<occtl_status_t>(status);",
                "instance->_message_holder = message.utf8(); instance->_c_struct.message = instance->_message_holder.get_data();",
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
        # Handle: result.X = Y; or result.X = _c_struct.Y;
        m = re.match(r"^result\.(\w+)\s*=\s*(?:_c_struct\.)?(\w+);?", stripped)
        if m:
            field = m.group(1)
            c_field = m.group(2)
            lines.append(f"instance->_c_struct.{c_field} = {param_name}.{field};")
            continue
        # Handle: result.basis[i][j] = _c_struct.field[n];
        m = re.match(
            r"^result\.basis\[(\d+)\]\[(\d+)\]\s*=\s*(?:_c_struct\.)?(\w+)\[(\d+)\];?",
            stripped,
        )
        if m:
            arr_name = m.group(3)
            idx = m.group(4)
            i = m.group(1)
            j = m.group(2)
            lines.append(
                f"instance->_c_struct.{arr_name}[{idx}] = {param_name}.basis[{i}][{j}];"
            )
            continue
        # Handle: result.origin.X = _c_struct.field[N];
        m = re.match(
            r"^result\.origin\.(\w+)\s*=\s*(?:_c_struct\.)?(\w+)\[(\d+)\];?", stripped
        )
        if m:
            comp = m.group(1)
            arr_name = m.group(2)
            idx = m.group(3)
            lines.append(
                f"instance->_c_struct.{arr_name}[{idx}] = {param_name}.origin.{comp};"
            )
            continue
        # Handle: return Type(r, g, b, a);
        m = re.match(r"^return\s+\w+\s*\((.*)\)\s*;?", stripped)
        if m:
            args = [a.strip() for a in m.group(1).split(",")]
            if ret_type == "Color" and len(args) == 4:
                lines.append(f"instance->_c_struct.r = {param_name}.r;")
                lines.append(f"instance->_c_struct.g = {param_name}.g;")
                lines.append(f"instance->_c_struct.b = {param_name}.b;")
                lines.append(f"instance->_c_struct.a = {param_name}.a;")
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
                "result.x = _c_struct.x;",
                "result.y = _c_struct.y;",
                "result.z = _c_struct.z;",
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
                "result.x = _c_struct.x;",
                "result.y = _c_struct.y;",
                "result.z = _c_struct.z;",
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
                "result.x = _c_struct.x;",
                "result.y = _c_struct.y;",
                "result.z = _c_struct.z;",
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
                "result.x = _c_struct.x;",
                "result.y = _c_struct.y;",
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
                "result.x = _c_struct.x;",
                "result.y = _c_struct.y;",
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
                "result.x = _c_struct.x;",
                "result.y = _c_struct.y;",
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
                "result.basis[0][0] = _c_struct.m[0];",
                "result.basis[0][1] = _c_struct.m[1];",
                "result.basis[0][2] = _c_struct.m[2];",
                "result.origin.x = _c_struct.m[3];",
                "result.basis[1][0] = _c_struct.m[4];",
                "result.basis[1][1] = _c_struct.m[5];",
                "result.basis[1][2] = _c_struct.m[6];",
                "result.origin.y = _c_struct.m[7];",
                "result.basis[2][0] = _c_struct.m[8];",
                "result.basis[2][1] = _c_struct.m[9];",
                "result.basis[2][2] = _c_struct.m[10];",
                "result.origin.z = _c_struct.m[11];",
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
                "result.position = Vector3(_c_struct.min.x, _c_struct.min.y, _c_struct.min.z);",
                "result.size = Vector3(_c_struct.max.x - _c_struct.min.x, _c_struct.max.y - _c_struct.min.y, _c_struct.max.z - _c_struct.min.z);",
                "return result;",
            ],
        ),
    ],
    "OcctlColorRgba": [
        (
            "to_color",
            "Color",
            [
                "return Color(_c_struct.r, _c_struct.g, _c_struct.b, _c_struct.a);",
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
                "    const double zx = _c_struct.direction.x, zy = _c_struct.direction.y, zz = _c_struct.direction.z;",
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
                "    result.set_origin(Vector3(_c_struct.location.x, _c_struct.location.y, _c_struct.location.z));",
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
                "    const double x_x = _c_struct.x_dir.x, x_y = _c_struct.x_dir.y, x_z = _c_struct.x_dir.z;",
                "    const double dot = x_x * _c_struct.x_dir_ref.x + x_y * _c_struct.x_dir_ref.y + x_z * _c_struct.x_dir_ref.z;",
                "    double y_x = _c_struct.x_dir_ref.x - dot * x_x;",
                "    double y_y = _c_struct.x_dir_ref.y - dot * x_y;",
                "    double y_z = _c_struct.x_dir_ref.z - dot * x_z;",
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
                "    result.set_origin(Vector3(_c_struct.location.x, _c_struct.location.y, _c_struct.location.z));",
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
                "    basis.rows[0] = Vector3(_c_struct.x_dir.x, _c_struct.x_dir.y, _c_struct.x_dir.z);",
                "    basis.rows[1] = Vector3(_c_struct.y_dir.x, _c_struct.y_dir.y, _c_struct.y_dir.z);",
                "    basis.rows[2] = Vector3(_c_struct.z_dir.x, _c_struct.z_dir.y, _c_struct.z_dir.z);",
                "    result.set_basis(basis);",
                "    result.set_origin(Vector3(_c_struct.location.x, _c_struct.location.y, _c_struct.location.z));",
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
    pairs = _find_field_ptr_size_pairs(struct)

    # Collect includes for variant types needed by paired array fields
    extra_variant_includes: set[str] = set()
    for field in struct.fields:
        t = field.type_name.strip()
        clean = _field_clean_name(field)
        if clean in pairs:
            gt = _field_godot_type(field, pairs)
            if gt == "PackedFloat64Array":
                extra_variant_includes.add(
                    "<godot_cpp/variant/packed_float64_array.hpp>"
                )
            elif gt == "PackedFloat32Array":
                extra_variant_includes.add(
                    "<godot_cpp/variant/packed_float32_array.hpp>"
                )
            elif gt == "PackedInt32Array":
                extra_variant_includes.add("<godot_cpp/variant/packed_int32_array.hpp>")
            elif gt == "PackedInt64Array":
                extra_variant_includes.add("<godot_cpp/variant/packed_int64_array.hpp>")
            elif gt == "PackedByteArray":
                extra_variant_includes.add("<godot_cpp/variant/packed_byte_array.hpp>")

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
    # Add extra includes for paired array types
    for inc in sorted(extra_variant_includes):
        lines.append(f"#include {inc}")

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

    # Store the real C struct directly
    lines.append(f"    {c_type} _c_struct;")
    # Shadow string holders for pointer-type fields (e.g., const char*)
    # Shadow value holders for const pointer to value struct / uint64_id
    # For paired pointer+count fields: std::vector buffer instead of single holder
    for field in struct.fields:
        t = field.type_name.strip()
        clean = _field_clean_name(field)
        if t == "const char*":
            lines.append(f"    mutable godot::CharString _{clean}_holder;")
        elif t.startswith("const ") and t.endswith("*") and not t.endswith("**"):
            inner = t[len("const ") : -1].strip()
            if clean in pairs:
                # Paired pointer+count — use std::vector buffer
                lines.append(f"    mutable std::vector<{inner}> _{clean}_buffer;")
            elif inner in VALUE_STRUCT_TYPES:
                lines.append(f"    mutable {inner} _{clean}_holder;")
            elif inner in UINT64_ID_TYPES:
                lines.append(f"    mutable {inner} _{clean}_holder;")

    lines.append("")
    # Getters and setters
    for field in struct.fields:
        gt = _field_godot_type(field, pairs)
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
    lines.append("};")
    lines.append(f"#endif // {guard}")
    lines.append("")

    return "\n".join(lines)


def _generate_paired_ptr_setter_lines(
    inner: str, clean: str, pair_count_name: str, is_primary: bool
) -> list[str]:
    """Generate setter body lines for a paired pointer field (array setter).

    Args:
        inner: C element type (e.g. "occtl_point3_t", "double")
        clean: Field clean name
        pair_count_name: Name of the paired count field
        is_primary: True if this pointer "owns" the count (its setter updates the count).
                    Secondary pointers (sharing a count) don't update the count.

    Returns list of C++ lines (indented one level) for the setter body.
    """
    lines = []
    buf = f"_{clean}_buffer"
    ptr = f"_c_struct.{clean}"
    cnt = f"_c_struct.{pair_count_name}"

    if is_primary:
        # Primary pointer: resize buffer and update the count
        if _is_value_struct(inner):
            sub_cls = c_type_to_godot_class(inner)
            lines.append(f"    {buf}.resize(val.size());")
            lines.append(f"    for (int _i = 0; _i < val.size(); _i++) {{")
            lines.append(f"        Ref<{sub_cls}> _elem = val[_i];")
            lines.append(f"        {buf}[_i] = _elem->_c_struct;")
            lines.append(f"    }}")
        elif _is_uint64_id(inner):
            lines.append(f"    {buf}.resize(val.size());")
            lines.append(f"    for (int _i = 0; _i < val.size(); _i++) {{")
            lines.append(f"        {buf}[_i].bits = static_cast<uint64_t>(val[_i]);")
            lines.append(f"    }}")
        else:
            lines.append(f"    {buf}.resize(val.size());")
            lines.append(f"    for (int _i = 0; _i < val.size(); _i++) {{")
            lines.append(f"        {buf}[_i] = val[_i];")
            lines.append(f"    }}")
        lines.append(f"    {ptr} = {buf}.empty() ? nullptr : {buf}.data();")
        lines.append(f"    {cnt} = val.size();")
    else:
        # Secondary pointer (shares count with another pointer):
        # Match the current count; adapt the user's array to fit.
        lines.append(f"    size_t _cnt = {cnt};")
        lines.append(f"    {buf}.resize(_cnt);")
        lines.append(
            f"    size_t _n = static_cast<size_t>(val.size()) < _cnt ? static_cast<size_t>(val.size()) : _cnt;"
        )
        if _is_value_struct(inner):
            sub_cls = c_type_to_godot_class(inner)
            lines.append(f"    for (size_t _i = 0; _i < _n; _i++) {{")
            lines.append(f"        Ref<{sub_cls}> _elem = val[_i];")
            lines.append(f"        {buf}[_i] = _elem->_c_struct;")
            lines.append(f"    }}")
            # Zero-init remaining elements if val was smaller
            lines.append(
                f"    for (size_t _i = _n; _i < _cnt; _i++) {{ {buf}[_i] = {{}}; }}"
            )
        elif _is_uint64_id(inner):
            lines.append(f"    for (size_t _i = 0; _i < _n; _i++) {{")
            lines.append(f"        {buf}[_i].bits = static_cast<uint64_t>(val[_i]);")
            lines.append(f"    }}")
            lines.append(
                f"    for (size_t _i = _n; _i < _cnt; _i++) {{ {buf}[_i].bits = 0; }}"
            )
        else:
            lines.append(f"    for (size_t _i = 0; _i < _n; _i++) {{")
            lines.append(f"        {buf}[_i] = val[_i];")
            lines.append(f"    }}")
            lines.append(
                f"    for (size_t _i = _n; _i < _cnt; _i++) {{ {buf}[_i] = {{}}; }}"
            )
        lines.append(f"    {ptr} = {buf}.empty() ? nullptr : {buf}.data();")
        # Do NOT update the count (it's owned by the primary pointer)

    return lines


def _generate_paired_ptr_getter_lines(
    inner: str, clean: str, pair_count_name: str
) -> list[str]:
    """Generate getter body lines for a paired pointer field (array getter).

    Returns list of C++ lines (indented one level) for the getter body.
    """
    lines = []
    ptr = f"_c_struct.{clean}"
    cnt = f"_c_struct.{pair_count_name}"

    if _is_value_struct(inner):
        sub_cls = c_type_to_godot_class(inner)
        gt = "Array"
        lines.append(f"    {gt} _result;")
        lines.append(f"    if ({ptr} != nullptr && {cnt} > 0) {{")
        lines.append(f"        _result.resize({cnt});")
        lines.append(f"        for (int _i = 0; _i < static_cast<int>({cnt}); _i++) {{")
        lines.append(f"            _result[_i] = {sub_cls}::from_c({ptr}[_i]);")
        lines.append(f"        }}")
        lines.append(f"    }}")
    elif _is_uint64_id(inner):
        gt = "PackedInt64Array"
        lines.append(f"    {gt} _result;")
        lines.append(f"    if ({ptr} != nullptr && {cnt} > 0) {{")
        lines.append(f"        _result.resize({cnt});")
        lines.append(f"        for (int _i = 0; _i < static_cast<int>({cnt}); _i++) {{")
        lines.append(f"            _result[_i] = static_cast<int64_t>({ptr}[_i].bits);")
        lines.append(f"        }}")
        lines.append(f"    }}")
    else:
        # Scalar: double, int32_t, etc.
        # Determine the packed array type from the inner C type
        gt = _pair_godot_array_type(inner)
        lines.append(f"    {gt} _result;")
        lines.append(f"    if ({ptr} != nullptr && {cnt} > 0) {{")
        lines.append(f"        _result.resize({cnt});")
        lines.append(f"        for (int _i = 0; _i < static_cast<int>({cnt}); _i++) {{")
        lines.append(f"            _result[_i] = {ptr}[_i];")
        lines.append(f"        }}")
        lines.append(f"    }}")

    lines.append(f"    return _result;")
    return lines


def _generate_paired_count_setter_lines(
    ptr_cleans: list[str], count_clean: str
) -> list[str]:
    """Generate setter body lines for a paired count field.

    When setting the count, resize ALL buffers that share this count
    (adopting existing data from the C pointer if the buffer was empty).
    """
    lines = []
    cnt = f"_c_struct.{count_clean}"
    lines.append(f"    size_t _old = {cnt};")
    for pc in ptr_cleans:
        buf = f"_{pc}_buffer"
        ptr = f"_c_struct.{pc}"
        lines.append(
            f"    if (_{pc}_buffer.empty() && {ptr} != nullptr && _old > 0) {{"
        )
        lines.append(f"        {buf}.assign({ptr}, {ptr} + _old);")
        lines.append(f"    }}")
        lines.append(f"    {buf}.resize(val);")
        lines.append(f"    {ptr} = {buf}.empty() ? nullptr : {buf}.data();")
    lines.append(f"    {cnt} = val;")
    return lines


def generate_value_type_source(struct: CStruct, all_types: dict[str, CStruct]) -> str:
    """Generate the .cpp file for a value type class."""
    cls = c_type_to_godot_class(struct.type_name)
    c_type = struct.type_name
    pairs = _find_field_ptr_size_pairs(struct)
    # Build reverse map: count_field_clean -> list of ptr_field_clean (supporting shared counts)
    count_to_ptrs: dict[str, list[str]] = {}
    for pk, pv in pairs.items():
        count_to_ptrs.setdefault(pv, []).append(pk)
    # For each count, the first pointer IN STRUCT FIELD ORDER is "primary" (owns the count).
    # All others are "secondary" (share the count without updating it).
    count_primary: dict[str, str] = {}  # count_name -> primary_ptr_name
    for field in struct.fields:
        clean = _field_clean_name(field)
        if clean in pairs:
            cnt_name = pairs[clean]
            if cnt_name not in count_primary:
                count_primary[cnt_name] = clean

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
        gt = _field_godot_type(field, pairs)
        clean = _field_clean_name(field)
        t = field.type_name.strip()

        # ---- Check if this is a paired count field (size_t paired with a pointer) ----
        if t == "size_t" and clean in count_to_ptrs:
            ptr_cleans = count_to_ptrs[clean]
            lines.append(
                f"{gt} {cls}::get_{clean}() const {{ return static_cast<int>(_c_struct.{clean}); }}"
            )
            setter_lines = _generate_paired_count_setter_lines(ptr_cleans, clean)
            lines.append(f"void {cls}::set_{clean}({gt} val) {{")
            lines.extend(setter_lines)
            lines.append(f"}}")
            continue

        # ---- Check if this is a paired pointer field (const T* with size_t count) ----
        if (
            t.startswith("const ")
            and t.endswith("*")
            and not t.endswith("**")
            and clean in pairs
        ):
            inner = t[len("const ") : -1].strip()
            pair_count_name = pairs[clean]
            # Determine if this is the primary pointer for this count
            is_primary = count_primary.get(pair_count_name) == clean

            # Getter (array)
            getter_lines = _generate_paired_ptr_getter_lines(
                inner, clean, pair_count_name
            )
            lines.append(f"{gt} {cls}::get_{clean}() const {{")
            lines.extend(getter_lines)
            lines.append(f"}}")

            # Setter (array)
            setter_lines = _generate_paired_ptr_setter_lines(
                inner, clean, pair_count_name, is_primary
            )
            lines.append(f"void {cls}::set_{clean}({gt} val) {{")
            lines.extend(setter_lines)
            lines.append(f"}}")
            continue

        # ---- Original getter/setter logic (for non-paired fields) ----
        if _field_is_array(field):
            # Array field: copy from/to _c_struct
            size = _field_array_size(field)
            lines.append(f"{gt} {cls}::get_{clean}() const {{")
            lines.append(f"    {gt} _result;")
            lines.append(f"    _result.resize({size});")
            lines.append(
                f"    for (int _i = 0; _i < {size}; _i++) _result[_i] = _c_struct.{clean}[_i];"
            )
            lines.append(f"    return _result;")
            lines.append(f"}}")
            lines.append(f"void {cls}::set_{clean}({gt} val) {{")
            lines.append(
                f"    for (int _i = 0; _i < {size} && _i < val.size(); _i++) _c_struct.{clean}[_i] = val[_i];"
            )
            lines.append(f"}}")
        elif t == "const char*":
            # const char*: getter returns String, setter stores shadow and updates pointer
            lines.append(
                f"{gt} {cls}::get_{clean}() const {{ return String(_c_struct.{clean}); }}"
            )
            lines.append(
                f"void {cls}::set_{clean}({gt} val) {{ _{clean}_holder = val.utf8(); _c_struct.{clean} = _{clean}_holder.get_data(); }}"
            )
        elif t == "const void*":
            lines.append(
                f"{gt} {cls}::get_{clean}() const {{ return static_cast<int64_t>(reinterpret_cast<uintptr_t>(_c_struct.{clean})); }}"
            )
            lines.append(
                f"void {cls}::set_{clean}({gt} val) {{ _c_struct.{clean} = reinterpret_cast<const void*>(static_cast<uintptr_t>(static_cast<int64_t>(val))); }}"
            )
        elif t.startswith("const ") and t.endswith("*") and not t.endswith("**"):
            # Const pointer: store shadow copy for settable types
            inner = t[len("const ") : -1].strip()
            if inner == "char":
                lines.append(
                    f"{gt} {cls}::get_{clean}() const {{ return String(_c_struct.{clean}); }}"
                )
                lines.append(
                    f"void {cls}::set_{clean}({gt} val) {{ _{clean}_holder = val.utf8(); _c_struct.{clean} = _{clean}_holder.get_data(); }}"
                )
            elif _is_uint64_id(inner):
                inner_cls = c_type_to_godot_class(inner)
                lines.append(
                    f"{gt} {cls}::get_{clean}() const {{ return _c_struct.{clean} ? static_cast<int64_t>(_c_struct.{clean}->bits) : 0; }}"
                )
                lines.append(
                    f"void {cls}::set_{clean}({gt} val) {{ _{clean}_holder.bits = static_cast<uint64_t>(val); _c_struct.{clean} = &_{clean}_holder; }}"
                )
            elif _is_value_struct(inner):
                sub_cls = c_type_to_godot_class(inner)
                lines.append(
                    f"{gt} {cls}::get_{clean}() const {{ return _c_struct.{clean} ? Ref<{sub_cls}>({sub_cls}::from_c(*_c_struct.{clean})) : Ref<{sub_cls}>(); }}"
                )
                lines.append(
                    f"void {cls}::set_{clean}({gt} val) {{ if (val.is_valid()) {{ _{clean}_holder = val->_c_struct; _c_struct.{clean} = &_{clean}_holder; }} }}"
                )
            else:
                lines.append(
                    f"{gt} {cls}::get_{clean}() const {{ return static_cast<int64_t>(reinterpret_cast<uintptr_t>(_c_struct.{clean})); }}"
                )
                lines.append(
                    f"void {cls}::set_{clean}({gt} val) {{ _c_struct.{clean} = reinterpret_cast<{t}>(static_cast<uintptr_t>(static_cast<int64_t>(val))); }}"
                )
        elif t.endswith("*") and not t.endswith("**"):
            # Non-const pointer (mutable output)
            inner = t[:-1].strip()
            if inner == "char":
                # char* - currently stored as String, settable
                lines.append(
                    f"{gt} {cls}::get_{clean}() const {{ return String(_c_struct.{clean}); }}"
                )
                lines.append(
                    f"void {cls}::set_{clean}({gt} val) {{ _{clean}_holder = val.utf8(); _c_struct.{clean} = const_cast<char*>(_{clean}_holder.get_data()); }}"
                )
            elif _is_value_struct(inner):
                sub_cls = c_type_to_godot_class(inner)
                lines.append(
                    f"{gt} {cls}::get_{clean}() const {{ return {sub_cls}::from_c(*_c_struct.{clean}); }}"
                )
                lines.append(
                    f"void {cls}::set_{clean}({gt} val) {{ if (val.is_valid()) *_c_struct.{clean} = val->_c_struct; }}"
                )
            elif _is_uint64_id(inner):
                lines.append(
                    f"{gt} {cls}::get_{clean}() const {{ return static_cast<int64_t>(_c_struct.{clean}->bits); }}"
                )
                lines.append(
                    f"void {cls}::set_{clean}({gt} val) {{ _c_struct.{clean}->bits = static_cast<uint64_t>(val); }}"
                )
            else:
                lines.append(
                    f"{gt} {cls}::get_{clean}() const {{ return static_cast<int64_t>(reinterpret_cast<uintptr_t>(_c_struct.{clean})); }}"
                )
                lines.append(
                    f"void {cls}::set_{clean}({gt} val) {{ _c_struct.{clean} = reinterpret_cast<{t}>(static_cast<uintptr_t>(static_cast<int64_t>(val))); }}"
                )
        elif t in ("occtl_status_t",):
            lines.append(
                f"{gt} {cls}::get_{clean}() const {{ return static_cast<int>(_c_struct.{clean}); }}"
            )
            lines.append(
                f"void {cls}::set_{clean}({gt} val) {{ _c_struct.{clean} = static_cast<{t}>(val); }}"
            )
        elif _is_uint64_id(t):
            lines.append(
                f"{gt} {cls}::get_{clean}() const {{ return static_cast<int64_t>(_c_struct.{clean}.bits); }}"
            )
            lines.append(
                f"void {cls}::set_{clean}({gt} val) {{ _c_struct.{clean}.bits = static_cast<uint64_t>(val); }}"
            )
        elif _is_value_struct(t):
            sub_cls = c_type_to_godot_class(t)
            lines.append(
                f"{gt} {cls}::get_{clean}() const {{ return {sub_cls}::from_c(_c_struct.{clean}); }}"
            )
            lines.append(
                f"void {cls}::set_{clean}({gt} val) {{ if (val.is_valid()) _c_struct.{clean} = val->_c_struct; }}"
            )
        elif _is_enum_type(t):
            lines.append(
                f"{gt} {cls}::get_{clean}() const {{ return static_cast<int>(_c_struct.{clean}); }}"
            )
            lines.append(
                f"void {cls}::set_{clean}({gt} val) {{ _c_struct.{clean} = static_cast<{t}>(val); }}"
            )
        else:
            # Primitive types: double, float, bool, int32_t, etc.
            lines.append(
                f"{gt} {cls}::get_{clean}() const {{ return _c_struct.{clean}; }}"
            )
            lines.append(
                f"void {cls}::set_{clean}({gt} val) {{ _c_struct.{clean} = val; }}"
            )

    # ===== _bind_methods =====
    lines.append(f"void {cls}::_bind_methods() {{")
    # Bind field getters and setters
    for field in struct.fields:
        clean = _field_clean_name(field)
        gt = _field_godot_type(field, pairs)
        vt = _godot_type_to_variant_type(gt)
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

    # to_c() — direct access to the stored C struct
    lines.append(f"{c_type} {cls}::to_c() const {{")
    lines.append(f"    return _c_struct;")
    lines.append(f"}}")
    lines.append("")

    # from_c() — construct a Ref from a C struct value
    lines.append(f"Ref<{cls}> {cls}::from_c(const {c_type}& val) {{")
    lines.append(f"    Ref<{cls}> r;")
    lines.append(f"    r.instantiate();")
    lines.append(f"    r->_c_struct = val;")
    lines.append(f"    return r;")
    lines.append(f"}}")
    lines.append("")

    # copy_from_c() — replace _c_struct in-place
    lines.append(f"void {cls}::copy_from_c(const {c_type}& val) {{")
    lines.append(f"    _c_struct = val;")
    lines.append(f"}}")
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
    pairs = _find_field_ptr_size_pairs(struct)
    methods = []
    for field in struct.fields:
        gt = _field_godot_type(field, pairs)
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
