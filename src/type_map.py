"""C to Godot type mapping for the deterministic autowrapper."""

import re

# ---------------------------------------------------------------
# Known opaque handle types → their free function
# ---------------------------------------------------------------
HANDLE_TYPES: dict[str, str] = {
    "occtl_graph_t": "occtl_graph_free",
    "occtl_node_iter_t": "occtl_node_iter_free",
    "occtl_select_iter_t": "occtl_select_iter_free",
    "occtl_select_group_iter_t": "occtl_select_group_iter_free",
}

# Map handle type → header that declares its free function.
# (The opaque forward declaration may live in a types header, but the
# free function lives in the main API header.)
HANDLE_FREE_HEADERS: dict[str, str] = {
    "occtl_graph_t": "occtl/occtl_topo.h",
    "occtl_node_iter_t": "occtl/occtl_topo.h",
    "occtl_select_iter_t": "occtl/occtl_topo_build.h",
    "occtl_select_group_iter_t": "occtl/occtl_topo_build.h",
}

# ---------------------------------------------------------------
# Registry of known free functions for all opaque handle types.
# When a new opaque _t type is encountered, it's added to this
# map with a generic free function if none is known.
# ---------------------------------------------------------------
HANDLE_FREE_FUNCTIONS: dict[str, str] = {
    "occtl_graph_t": "occtl_graph_free",
    "occtl_node_iter_t": "occtl_node_iter_free",
    "occtl_select_iter_t": "occtl_select_iter_free",
    "occtl_select_group_iter_t": "occtl_select_group_iter_free",
}


# ---------------------------------------------------------------
# AUTOMATIC HANDLE DETECTION
# Types ending in _t that are NOT in VALUE_STRUCT_TYPES,
# UINT64_ID_TYPES, ENUM_TYPES, or CPP_TO_GODOT_TYPE
# can be treated as opaque handles if they follow the
# occtl_*_t naming convention for opaque pointers.
# ---------------------------------------------------------------
def is_auto_handle_type(c_type: str) -> bool:
    """Check if a C type looks like an opaque handle type."""
    base = c_type.strip()
    if not base.endswith("_t"):
        return False
    if base in HANDLE_TYPES or base in UINT64_ID_TYPES or base in CPP_TO_GODOT_TYPE:
        return False
    if base in VALUE_STRUCT_TYPES:
        return False
    if base in ENUM_TYPES:
        return False
    if base in CALLBACK_TYPES:
        return False
    # Must match occtl_*_t pattern
    if not base.startswith("occtl_"):
        return False
    return True


# ---------------------------------------------------------------
# Single-field wrappers: structs whose only semantic content is a
# single uint64_t field named "bits".  Represented as int64_t in
# Godot so callers can pass them around as integers.
# ---------------------------------------------------------------
UINT64_ID_TYPES: set[str] = {
    "occtl_node_id_t",
    "occtl_uid_t",
    "occtl_ref_id_t",
    "occtl_ref_uid_t",
    "occtl_rep_uid_t",
    "occtl_rep_id_t",
    "occtl_joint_id_t",
}


# ---------------------------------------------------------------
# Value-struct types → dedicated Godot RefCounted classes.
# Each gets to_c() / from_c() generated automatically from
# its field list.
# ---------------------------------------------------------------
VALUE_STRUCT_TYPES: set[str] = {
    # Geometric primitives - all get RefCounted wrappers
    "occtl_point2_t",
    "occtl_point3_t",
    "occtl_vector2_t",
    "occtl_vector3_t",
    "occtl_direction2_t",
    "occtl_direction3_t",
    "occtl_transform_t",
    "occtl_aabb3_t",
    "occtl_color_rgba_t",
    "occtl_axis1_placement_t",
    "occtl_axis2_placement_t",
    "occtl_axis2_placement2d_t",
    "occtl_axis3_placement_t",
    "occtl_error_t",
    "occtl_runtime_init_info_t",
    "occtl_bool_options_t",
    "occtl_mesh_options_t",
    "occtl_mesh_from_buffers_options_t",
    "occtl_mesh_triangle_components_options_t",
    "occtl_mesh_triangle_plane_components_options_t",
    "occtl_mesh_triangle_sphere_components_options_t",
    "occtl_mesh_triangle_cylinder_components_options_t",
    "occtl_prim_box_info_t",
    "occtl_prim_sphere_info_t",
    "occtl_prim_cylinder_info_t",
    "occtl_prim_cone_info_t",
    "occtl_prim_torus_info_t",
    "occtl_prim_wedge_info_t",
    "occtl_prim_halfspace_info_t",
    "occtl_triangulation_view_t",
    "occtl_polygon3d_view_t",
    "occtl_polygon_on_tri_view_t",
    "occtl_mesh_triangle_buffers_view_t",
    "occtl_mesh_triangle_analysis_view_t",
    "occtl_mesh_triangle_components_view_t",
    "occtl_mesh_triangle_component_triangles_view_t",
    "occtl_mesh_triangle_component_boundary_view_t",
    "occtl_mesh_triangle_component_boundary_chains_view_t",
    "occtl_mesh_component_boundary_polylines_view_t",
    "occtl_mesh_triangle_component_summary_t",
    "occtl_mesh_triangle_component_summaries_view_t",
    "occtl_mesh_triangle_plane_component_t",
    "occtl_mesh_triangle_plane_components_view_t",
    "occtl_mesh_triangle_sphere_component_t",
    "occtl_mesh_triangle_sphere_components_view_t",
    "occtl_mesh_triangle_cylinder_component_t",
    "occtl_mesh_triangle_cylinder_components_view_t",
    "occtl_mesh_triangle_component_boundary_edge_t",
    "occtl_mesh_triangle_component_boundary_chain_t",
    "occtl_mesh_component_boundary_polyline_t",
    "occtl_edge_view_t",
    "occtl_coedge_view_t",
    "occtl_face_view_t",
    "occtl_vertex_view_t",
    "occtl_wire_view_t",
    "occtl_shell_view_t",
    "occtl_solid_view_t",
    "occtl_compound_view_t",
    "occtl_metadata_key_view_t",
    "occtl_geom_circle_t",
    "occtl_geom_ellipse_t",
    "occtl_geom_hyperbola_t",
    "occtl_geom_parabola_t",
    "occtl_geom2d_line_t",
    "occtl_geom2d_circle_t",
    "occtl_geom2d_ellipse_t",
    "occtl_geom2d_hyperbola_t",
    "occtl_geom2d_parabola_t",
    "occtl_geom_plane_t",
    "occtl_geom_cylindrical_surface_t",
    "occtl_geom_spherical_surface_t",
    "occtl_geom_conical_surface_t",
    "occtl_geom_toroidal_surface_t",
    "occtl_topo_check_issue_t",
}


# ---------------------------------------------------------------
# Typedef aliases: "alias -> canonical"
# These types are pure C typedefs of other types (not struct/enum
# definitions), so they don't have their own CStruct/CEnum.  Map
# them to their canonical type for uniform handling.
# ---------------------------------------------------------------
TYPEDEF_CANONICAL_MAP: dict[str, str] = {
    "occtl_geom_line_t": "occtl_axis1_placement_t",
}

# ---------------------------------------------------------------
# Callback typedefs — function pointer types that need Callable bridge.
# ---------------------------------------------------------------
CALLBACK_TYPES: set[str] = {
    "occtl_node_visitor_t",
    "occtl_ref_visitor_t",
    "occtl_rep_visitor_t",
    "occtl_metadata_visitor_t",
}


def is_callback_type(c_type: str) -> bool:
    return c_type.strip() in CALLBACK_TYPES


# ---------------------------------------------------------------
# Size parameter name patterns — these params should be hidden
# from GDScript when they follow an array pointer.
# ---------------------------------------------------------------
SIZE_PARAM_NAMES: set[str] = {
    "count",
    "size",
    "len",
    "length",
    "num",
    "capacity",
    "cap",
    "n",
}


def is_size_param(name: str) -> bool:
    """Check if a parameter name suggests it's a size/count parameter."""
    return name.strip().lower() in SIZE_PARAM_NAMES


# ---------------------------------------------------------------
# Enum types → treat as int in Godot (not Ref<T> wrappers).
# These are typedefs for enums, not structs.
# ---------------------------------------------------------------
ENUM_TYPES: set[str] = {
    "occtl_curve2d_tangency_qualifier_t",
    "occtl_curve_kind_t",
    "occtl_geom_continuity_t",
    "occtl_heal_mode_t",
    "occtl_io_gltf_transform_format_t",
    "occtl_io_obj_coordinate_system_t",
    "occtl_io_ply_coordinate_system_t",
    "occtl_io_step_length_unit_t",
    "occtl_io_step_schema_t",
    "occtl_io_vrml_coordinate_system_t",
    "occtl_io_vrml_representation_t",
    "occtl_io_vrml_writer_version_t",
    "occtl_joint_kind_t",
    "occtl_node_kind_t",
    "occtl_offset_join_type_t",
    "occtl_orientation_t",
    "occtl_prim_brake_side_t",
    "occtl_prim_cylindrical_hole_kind_t",
    "occtl_prim_extrude_until_side_t",
    "occtl_prim_feat_combine_t",
    "occtl_prim_offset_mode_t",
    "occtl_prim_pipe_mode_t",
    "occtl_prim_pipe_transition_t",
    "occtl_prim_until_kind_t",
    "occtl_ref_kind_t",
    "occtl_relation_kind_t",
    "occtl_rep_kind_t",
    "occtl_select_axis_position_t",
    "occtl_select_axis_t",
    "occtl_select_bbox_mode_t",
    "occtl_select_group_key_t",
    "occtl_select_measure_kind_t",
    "occtl_select_normal_mode_t",
    "occtl_select_sort_direction_t",
    "occtl_select_sort_key_t",
    "occtl_shape_continuity_t",
    "occtl_status_t",
    "occtl_surface_filling_style_t",
    "occtl_surface_kind_t",
    "occtl_surface_point_grid_mode_t",
    "occtl_text_font_aspect_t",
    "occtl_text_halign_t",
    "occtl_text_valign_t",
    "occtl_topo_check_severity_t",
    "occtl_topo_explorer_traversal_t",
    "occtl_topo_filling_continuity_t",
    "occtl_topo_hlr_mode_t",
    "occtl_topo_point_class_t",
    "occtl_topo_split_keep_t",
    "occtl_topo_wire_offset_2d_join_t",
}


# ---------------------------------------------------------------
# Primitive type mapping
# ---------------------------------------------------------------
CPP_TO_GODOT_TYPE: dict[str, str] = {
    "void": "void",
    "bool": "bool",
    "int": "int",
    "int32_t": "int",
    "uint32_t": "int",
    "uint16_t": "int",
    "uint8_t": "int",
    "int64_t": "int64_t",
    "uint64_t": "int64_t",
    "size_t": "int",
    "float": "float",
    "double": "double",
    "const char*": "String",
    "char*": "String",
}


# ---------------------------------------------------------------
# Godot Variant types that can be used as properties
# ---------------------------------------------------------------
GODOT_VARIANT_TYPE: dict[str, str] = {
    "void": "NIL",
    "bool": "BOOL",
    "int": "INT",
    "int64_t": "INT",
    "float": "FLOAT",
    "double": "FLOAT",
    "String": "STRING",
    "Vector2": "VECTOR2",
    "Vector3": "VECTOR3",
    "Transform3D": "TRANSFORM3D",
    "AABB": "AABB",
    "Color": "COLOR",
    "Dictionary": "DICTIONARY",
    "Array": "ARRAY",
    "PackedByteArray": "PACKED_BYTE_ARRAY",
    "PackedFloat64Array": "PACKED_FLOAT64_ARRAY",
    "Object": "OBJECT",
}


# ---------------------------------------------------------------
# Helper: convert a C type name to a Godot class name
# ---------------------------------------------------------------
def c_type_to_godot_class(c_type: str) -> str:
    """Convert occtl_point3_t → OcctlPoint3, occtl_transform_t → OcctlTransform, etc."""
    name = c_type.strip()
    name = _resolve_typedef(name)
    name = re.sub(r"^(const|volatile)\s+", "", name)
    name = re.sub(r"_t\s*\**$", "", name)
    parts = re.split(r"[_\s]+", name)
    return "".join(p.capitalize() for p in parts)


# ---------------------------------------------------------------
# Map a godot param type string to its Variant::Type enum value.
# ---------------------------------------------------------------
def param_type_to_variant_type(godot_type: str) -> str:
    """Map a Godot parameter type string to Variant::Type enum name.
    e.g. 'int' → 'INT', 'Ref<OcctlPoint3>' → 'OBJECT', etc."""
    if godot_type in GODOT_VARIANT_TYPE:
        return GODOT_VARIANT_TYPE[godot_type]
    # Ref<T> types map to OBJECT
    if godot_type.startswith("Ref<"):
        return "OBJECT"
    # Fallback
    return "NIL"


# ---------------------------------------------------------------
# Determine how a C parameter maps to Godot
# ---------------------------------------------------------------
def _resolve_typedef(base: str) -> str:
    """Resolve a type alias to its canonical type (no-op for non-aliases)."""
    while base in TYPEDEF_CANONICAL_MAP:
        base = TYPEDEF_CANONICAL_MAP[base]
    return base


def is_value_struct_type(c_type: str) -> bool:
    """Check if a C type is a value struct that has a generated RefCounted wrapper."""
    base = c_type.strip()
    if base in CPP_TO_GODOT_TYPE:
        return False
    if base in HANDLE_TYPES or base in ENUM_TYPES or base in UINT64_ID_TYPES:
        return False
    if base in VALUE_STRUCT_TYPES:
        return True
    # Fallback: any _t type not in exclusion sets is treated as a value struct
    # so that the generated code calls ->to_c() on it.
    if base.endswith("_t"):
        return True
    # Unknown types that look like struct pointers
    return False


def _is_known_type(base: str) -> bool:
    """Check if a C type name is known to the type system."""
    base = _resolve_typedef(base)
    return (
        base in HANDLE_TYPES
        or base in VALUE_STRUCT_TYPES
        or base in UINT64_ID_TYPES
        or base in ENUM_TYPES
        or base in CPP_TO_GODOT_TYPE
        or is_auto_handle_type(base)
        or base.endswith(">")
    )  # template types


def is_opaque_ptr_t_type(c_type: str) -> bool:
    """Check if a C type is an opaque _t pointer type (no struct definition).

    These types end with _t but are NOT in VALUE_STRUCT_TYPES (they have
    no generated wrapper class). They should be passed as int64_t in Godot
    and reinterpret_cast back to their C pointer type.
    """
    base = c_type.strip()
    if not base.endswith("_t"):
        return False
    if base in HANDLE_TYPES or base in UINT64_ID_TYPES or base in CPP_TO_GODOT_TYPE:
        return False
    if base in VALUE_STRUCT_TYPES:
        return False
    if base in ENUM_TYPES:
        return False
    # Resolve typedefs: a typedef pointing to a known value struct
    # (e.g. occtl_geom_line_t → occtl_axis1_placement_t) is NOT opaque.
    resolved = _resolve_typedef(base)
    if resolved != base:
        return is_opaque_ptr_t_type(resolved)
    return True


def godot_param_type(c_type: str) -> str:
    """Map a C parameter type to the Godot wrapper type."""
    base = c_type.strip()
    # Strip trailing cv-qualifiers on pointers (e.g. "const T* const" -> "const T*")
    base = re.sub(r"\s+(const|volatile)\s*$", "", base)

    # Handle pointers
    ptr_match = re.match(r"^(\w[\w\s]*)\s*\*+$", base)
    if ptr_match:
        inner = ptr_match.group(1).strip()
        # Strip leading 'const'/'volatile' qualifiers for type lookup
        inner_clean = re.sub(r"^(const|volatile)\s+", "", inner).strip()
        typed = _resolve_typedef(inner_clean)
        if typed in HANDLE_TYPES:
            return f"Ref<{c_type_to_godot_class(typed)}Handle>"
        if typed in UINT64_ID_TYPES:
            return "int64_t"
        if is_opaque_ptr_t_type(typed):
            return "int64_t"
        if is_value_struct_type(typed):
            return f"Ref<{c_type_to_godot_class(typed)}>"
        if typed in ENUM_TYPES:
            return "int"
        if typed in ("void",) or inner in ("void",):
            return "int64_t"
        if typed in ("const char", "char") or inner in ("const char", "char"):
            return "String"
        if typed in ("uint8_t",) or inner in ("uint8_t",):
            return "PackedByteArray"
        if typed in ("double",) or inner in ("double",):
            return "PackedFloat64Array"
        if typed in ("float",) or inner in ("float",):
            return "PackedFloat32Array"
        if typed in ("int32_t", "uint32_t", "int") or inner in (
            "int32_t",
            "uint32_t",
            "int",
        ):
            return "PackedInt32Array"
        if typed in ("int64_t", "uint64_t") or inner in ("int64_t", "uint64_t"):
            return "PackedInt64Array"
        if typed == "occtl_point3_t" or inner == "occtl_point3_t":
            # For simplicity, we use Array of OcctlPoint3 for structured arrays
            return "Array"
        if typed == "occtl_point2_t" or inner == "occtl_point2_t":
            return "Array"
        if typed in CPP_TO_GODOT_TYPE:
            return CPP_TO_GODOT_TYPE[typed]
        # Unknown pointer type — error
        raise ValueError(f"Unknown pointer type: {base} (inner: {inner})")

    # Direct type mapping
    typed = _resolve_typedef(base)
    if typed in CPP_TO_GODOT_TYPE:
        return CPP_TO_GODOT_TYPE[typed]
    if typed in HANDLE_TYPES:
        return f"Ref<{c_type_to_godot_class(typed)}Handle>"
    if typed in UINT64_ID_TYPES:
        return "int64_t"
    if is_opaque_ptr_t_type(typed):
        return "int64_t"
    if is_value_struct_type(typed):
        return f"Ref<{c_type_to_godot_class(typed)}>"
    if typed in ENUM_TYPES:
        return "int"
    if is_auto_handle_type(typed):
        return f"Ref<{c_type_to_godot_class(typed)}Handle>"

    raise ValueError(f"Unknown C type: {base}")


def godot_return_type(c_type: str) -> str:
    """Map C return type to Godot return type."""
    return godot_param_type(c_type)


def param_in_type(c_type: str) -> str | None:
    """Return the non-const pointer type if this is an out-parameter, else None."""
    base = c_type.strip()
    if base == "void*":
        return None
    ptr_match = re.match(r"^(\w[\w\s]*)\s*\*+$", base)
    if ptr_match:
        inner = ptr_match.group(1).strip()
        typed = _resolve_typedef(inner)
        if typed in HANDLE_TYPES:
            return typed
        if typed in VALUE_STRUCT_TYPES:
            return typed
        if typed in UINT64_ID_TYPES:
            return typed
        if typed.endswith("_t"):
            return typed
        if typed in ("void", "char"):
            return None
        return typed
    return None


def is_out_param(c_type: str, name: str, parent_return_type: str) -> bool:
    """Heuristic: a non-const pointer parameter is an out-parameter
    when the function's return type is occtl_status_t or void."""
    base = c_type.strip()
    # Strip trailing cv-qualifiers (e.g. "T* const" -> "T*")
    base_stripped = re.sub(r"\s+(const|volatile)\s*$", "", base)
    # const T** is an out-param (writes a borrowed pointer, data is const)
    if base_stripped.endswith("**") and base.startswith("const "):
        return True
    if base.startswith("const "):
        return False
    if base_stripped == "const char*":
        return False
    if base_stripped == "char*":
        return False
    if base_stripped.endswith("**"):
        return True
    ptr_match = re.match(r"^(\w[\w\s]*)\s*\*+$", base_stripped)
    if ptr_match:
        inner = ptr_match.group(1).strip()
        if inner in ("void", "char"):
            return False
        # Handle types (occtl_graph_t*) are context objects, not out-params
        if inner in HANDLE_TYPES:
            return False
        if inner in UINT64_ID_TYPES:
            return True
        if inner.endswith("_t"):
            if inner in CPP_TO_GODOT_TYPE or inner in ENUM_TYPES:
                # Standard _t types (uint8_t, int32_t, enum _t types) — continue to normal checks
                pass
            elif (
                _resolve_typedef(inner) in VALUE_STRUCT_TYPES
                or inner in UINT64_ID_TYPES
            ):
                return True
            elif is_auto_handle_type(inner):
                # Auto-detected opaque _t types are like handles
                return False
            else:
                # Opaque _t types (not in VALUE_STRUCT_TYPES) are like handles
                return False
        if inner.endswith(">"):
            return True
        if name.startswith("out_"):
            return True
        if parent_return_type.strip() in ("occtl_status_t", "void"):
            return True
        return False
    return False
