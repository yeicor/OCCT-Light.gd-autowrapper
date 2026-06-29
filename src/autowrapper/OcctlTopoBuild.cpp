#include "OcctlTopoBuild.h"

#include "occtl/occtl_topo_build.h"

#include <vector>

void OcctlTopoBuild::_bind_methods() {
    BIND_CONSTANT(OCCTL_TOPO_MAKE_VERTEX_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_MAKE_EDGE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_MAKE_WIRE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_EDGES_TO_WIRES_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_WIRE_OFFSET_2D_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_WIRE_FIX_DEGENERATE_EDGES_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_FACE_CHAMFER_2D_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_WIRE_CHAMFER_2D_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_MAKE_FACE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_MAKE_FACE_FROM_WIRES_AUTO_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_MAKE_SHELL_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_MAKE_SOLID_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_MAKE_COMPOUND_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_MAKE_COMPSOLID_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_MATERIAL_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_JOINT_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_SELECT_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_SELECT_METADATA_FILTER_VERSION_1);
    BIND_CONSTANT(OCCTL_SELECT_DISTANCE_TO_NODE_SORT_VERSION_1);
    BIND_CONSTANT(OCCTL_SELECT_GROUP_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_SELECT_GROUP_VIEW_VERSION_1);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_wire_offset_2d_join_t", "OCCTL_TOPO_WIRE_OFFSET_2D_JOIN_ARC", OCCTL_TOPO_WIRE_OFFSET_2D_JOIN_ARC);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_wire_offset_2d_join_t", "OCCTL_TOPO_WIRE_OFFSET_2D_JOIN_TANGENT", OCCTL_TOPO_WIRE_OFFSET_2D_JOIN_TANGENT);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_wire_offset_2d_join_t", "OCCTL_TOPO_WIRE_OFFSET_2D_JOIN_INTERSECTION", OCCTL_TOPO_WIRE_OFFSET_2D_JOIN_INTERSECTION);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_wire_offset_2d_join_t", "OCCTL_TOPO_WIRE_OFFSET_2D_JOIN_RESERVED_FUTURE", OCCTL_TOPO_WIRE_OFFSET_2D_JOIN_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_offset_join_type_t", "OCCTL_OFFSET_JOIN_ARC", OCCTL_OFFSET_JOIN_ARC);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_offset_join_type_t", "OCCTL_OFFSET_JOIN_TANGENT", OCCTL_OFFSET_JOIN_TANGENT);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_offset_join_type_t", "OCCTL_OFFSET_JOIN_INTERSECTION", OCCTL_OFFSET_JOIN_INTERSECTION);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_offset_join_type_t", "OCCTL_OFFSET_JOIN_RESERVED_FUTURE", OCCTL_OFFSET_JOIN_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_joint_kind_t", "OCCTL_JOINT_RIGID", OCCTL_JOINT_RIGID);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_joint_kind_t", "OCCTL_JOINT_REVOLUTE", OCCTL_JOINT_REVOLUTE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_joint_kind_t", "OCCTL_JOINT_LINEAR", OCCTL_JOINT_LINEAR);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_joint_kind_t", "OCCTL_JOINT_CYLINDRICAL", OCCTL_JOINT_CYLINDRICAL);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_joint_kind_t", "OCCTL_JOINT_BALL", OCCTL_JOINT_BALL);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_joint_kind_t", "OCCTL_JOINT_RESERVED_FUTURE", OCCTL_JOINT_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_bbox_mode_t", "OCCTL_SELECT_BBOX_INTERSECTS", OCCTL_SELECT_BBOX_INTERSECTS);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_bbox_mode_t", "OCCTL_SELECT_BBOX_INSIDE", OCCTL_SELECT_BBOX_INSIDE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_bbox_mode_t", "OCCTL_SELECT_BBOX_CONTAINS_CENTER", OCCTL_SELECT_BBOX_CONTAINS_CENTER);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_bbox_mode_t", "OCCTL_SELECT_BBOX_MODE_RESERVED_FUTURE", OCCTL_SELECT_BBOX_MODE_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_axis_t", "OCCTL_SELECT_AXIS_X", OCCTL_SELECT_AXIS_X);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_axis_t", "OCCTL_SELECT_AXIS_Y", OCCTL_SELECT_AXIS_Y);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_axis_t", "OCCTL_SELECT_AXIS_Z", OCCTL_SELECT_AXIS_Z);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_axis_t", "OCCTL_SELECT_AXIS_RESERVED_FUTURE", OCCTL_SELECT_AXIS_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_axis_position_t", "OCCTL_SELECT_AXIS_POSITION_MIN", OCCTL_SELECT_AXIS_POSITION_MIN);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_axis_position_t", "OCCTL_SELECT_AXIS_POSITION_MAX", OCCTL_SELECT_AXIS_POSITION_MAX);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_axis_position_t", "OCCTL_SELECT_AXIS_POSITION_CENTER", OCCTL_SELECT_AXIS_POSITION_CENTER);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_axis_position_t", "OCCTL_SELECT_AXIS_POSITION_RESERVED_FUTURE", OCCTL_SELECT_AXIS_POSITION_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_normal_mode_t", "OCCTL_SELECT_NORMAL_PARALLEL", OCCTL_SELECT_NORMAL_PARALLEL);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_normal_mode_t", "OCCTL_SELECT_NORMAL_ANTIPARALLEL", OCCTL_SELECT_NORMAL_ANTIPARALLEL);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_normal_mode_t", "OCCTL_SELECT_NORMAL_EITHER", OCCTL_SELECT_NORMAL_EITHER);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_normal_mode_t", "OCCTL_SELECT_NORMAL_MODE_RESERVED_FUTURE", OCCTL_SELECT_NORMAL_MODE_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_measure_kind_t", "OCCTL_SELECT_MEASURE_EDGE_LENGTH", OCCTL_SELECT_MEASURE_EDGE_LENGTH);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_measure_kind_t", "OCCTL_SELECT_MEASURE_WIRE_LENGTH", OCCTL_SELECT_MEASURE_WIRE_LENGTH);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_measure_kind_t", "OCCTL_SELECT_MEASURE_FACE_AREA", OCCTL_SELECT_MEASURE_FACE_AREA);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_measure_kind_t", "OCCTL_SELECT_MEASURE_SURFACE_AREA", OCCTL_SELECT_MEASURE_SURFACE_AREA);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_measure_kind_t", "OCCTL_SELECT_MEASURE_VOLUME", OCCTL_SELECT_MEASURE_VOLUME);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_measure_kind_t", "OCCTL_SELECT_MEASURE_KIND_RESERVED_FUTURE", OCCTL_SELECT_MEASURE_KIND_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_sort_key_t", "OCCTL_SELECT_SORT_NONE", OCCTL_SELECT_SORT_NONE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_sort_key_t", "OCCTL_SELECT_SORT_AXIS_COORDINATE", OCCTL_SELECT_SORT_AXIS_COORDINATE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_sort_key_t", "OCCTL_SELECT_SORT_MEASURE", OCCTL_SELECT_SORT_MEASURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_sort_key_t", "OCCTL_SELECT_SORT_DISTANCE_TO_POINT", OCCTL_SELECT_SORT_DISTANCE_TO_POINT);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_sort_key_t", "OCCTL_SELECT_SORT_NAME", OCCTL_SELECT_SORT_NAME);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_sort_key_t", "OCCTL_SELECT_SORT_UID", OCCTL_SELECT_SORT_UID);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_sort_key_t", "OCCTL_SELECT_SORT_DISTANCE_TO_NODE", OCCTL_SELECT_SORT_DISTANCE_TO_NODE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_sort_key_t", "OCCTL_SELECT_SORT_KEY_RESERVED_FUTURE", OCCTL_SELECT_SORT_KEY_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_sort_direction_t", "OCCTL_SELECT_SORT_ASCENDING", OCCTL_SELECT_SORT_ASCENDING);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_sort_direction_t", "OCCTL_SELECT_SORT_DESCENDING", OCCTL_SELECT_SORT_DESCENDING);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_sort_direction_t", "OCCTL_SELECT_SORT_DIRECTION_RESERVED_FUTURE", OCCTL_SELECT_SORT_DIRECTION_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_group_key_t", "OCCTL_SELECT_GROUP_KIND", OCCTL_SELECT_GROUP_KIND);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_group_key_t", "OCCTL_SELECT_GROUP_AXIS_COORDINATE", OCCTL_SELECT_GROUP_AXIS_COORDINATE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_group_key_t", "OCCTL_SELECT_GROUP_CURVE_KIND", OCCTL_SELECT_GROUP_CURVE_KIND);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_group_key_t", "OCCTL_SELECT_GROUP_SURFACE_KIND", OCCTL_SELECT_GROUP_SURFACE_KIND);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_group_key_t", "OCCTL_SELECT_GROUP_NAME", OCCTL_SELECT_GROUP_NAME);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_group_key_t", "OCCTL_SELECT_GROUP_COLOR", OCCTL_SELECT_GROUP_COLOR);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_select_group_key_t", "OCCTL_SELECT_GROUP_KEY_RESERVED_FUTURE", OCCTL_SELECT_GROUP_KEY_RESERVED_FUTURE);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_make_vertex_info_init", "info"), &OcctlTopoBuild::topo_make_vertex_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_make_edge_info_init", "info"), &OcctlTopoBuild::topo_make_edge_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_make_wire_info_init", "info"), &OcctlTopoBuild::topo_make_wire_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edges_to_wires_options_init", "options"), &OcctlTopoBuild::topo_edges_to_wires_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_wire_offset_2d_options_init", "options"), &OcctlTopoBuild::topo_wire_offset_2d_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_wire_fix_degenerate_options_init", "options"), &OcctlTopoBuild::topo_wire_fix_degenerate_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_face_chamfer_2d_options_init", "options"), &OcctlTopoBuild::topo_face_chamfer_2d_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_wire_chamfer_2d_options_init", "options"), &OcctlTopoBuild::topo_wire_chamfer_2d_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_make_face_info_init", "info"), &OcctlTopoBuild::topo_make_face_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_make_face_from_wires_auto_options_init", "options"), &OcctlTopoBuild::topo_make_face_from_wires_auto_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_make_shell_info_init", "info"), &OcctlTopoBuild::topo_make_shell_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_make_solid_info_init", "info"), &OcctlTopoBuild::topo_make_solid_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_make_compound_info_init", "info"), &OcctlTopoBuild::topo_make_compound_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_make_vertex", "graph", "info", "out_vertex"), &OcctlTopoBuild::topo_make_vertex, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("topo_make_edge", "graph", "info", "out_edge"), &OcctlTopoBuild::topo_make_edge, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("topo_make_wire", "graph", "info", "out_wire"), &OcctlTopoBuild::topo_make_wire, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edges_to_wires", "graph", "options"), &OcctlTopoBuild::topo_edges_to_wires, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("topo_wire_offset_2d", "graph", "options", "out_wire"), &OcctlTopoBuild::topo_wire_offset_2d, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("topo_curves_to_wire", "graph", "curve_ids", "out_wire"), &OcctlTopoBuild::topo_curves_to_wire);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_wire_fix_degenerate", "graph", "options", "out_removed"), &OcctlTopoBuild::topo_wire_fix_degenerate, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("topo_face_chamfer_2d", "graph", "options", "out_face"), &OcctlTopoBuild::topo_face_chamfer_2d, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("topo_wire_chamfer_2d", "graph", "options", "out_wire"), &OcctlTopoBuild::topo_wire_chamfer_2d, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("topo_make_face", "graph", "info", "out_face"), &OcctlTopoBuild::topo_make_face, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("topo_make_face_from_wires_auto", "graph", "options", "out_face"), &OcctlTopoBuild::topo_make_face_from_wires_auto, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("topo_make_shell", "graph", "info", "out_shell"), &OcctlTopoBuild::topo_make_shell, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("topo_make_solid", "graph", "info", "out_solid"), &OcctlTopoBuild::topo_make_solid, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("topo_make_compound", "graph", "info", "out_compound"), &OcctlTopoBuild::topo_make_compound, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("topo_make_compsolid_info_init", "info"), &OcctlTopoBuild::topo_make_compsolid_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_make_compsolid", "graph", "info", "out_compsolid"), &OcctlTopoBuild::topo_make_compsolid, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("topo_remove", "graph", "id"), &OcctlTopoBuild::topo_remove);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_remove_subgraph", "graph", "id"), &OcctlTopoBuild::topo_remove_subgraph);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_begin_batch", "graph"), &OcctlTopoBuild::graph_begin_batch);
    godot::ClassDB::bind_method(godot::D_METHOD("batch_commit", "batch"), &OcctlTopoBuild::batch_commit);
    godot::ClassDB::bind_method(godot::D_METHOD("batch_abort", "batch"), &OcctlTopoBuild::batch_abort);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_replace_edge_curve", "graph", "edge", "curve_id"), &OcctlTopoBuild::topo_replace_edge_curve);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_replace_face_surface", "graph", "face", "surface_id"), &OcctlTopoBuild::topo_replace_face_surface);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_replace_coedge_pcurve", "graph", "coedge", "pcurve_id"), &OcctlTopoBuild::topo_replace_coedge_pcurve);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_add_pcurve", "graph", "edge", "face", "pcurve_id", "first", "last", "orientation"), &OcctlTopoBuild::topo_add_pcurve);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_shell_add_face", "graph", "shell", "face", "orientation"), &OcctlTopoBuild::topo_shell_add_face);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_shell_remove_face", "graph", "shell", "face"), &OcctlTopoBuild::topo_shell_remove_face);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_face_add_holes", "graph", "face", "holes"), &OcctlTopoBuild::topo_face_add_holes);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_face_remove_holes", "graph", "face", "holes"), &OcctlTopoBuild::topo_face_remove_holes);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_solid_add_shell", "graph", "solid", "shell", "orientation"), &OcctlTopoBuild::topo_solid_add_shell);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_solid_remove_shell", "graph", "solid", "shell"), &OcctlTopoBuild::topo_solid_remove_shell);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_compound_add_child", "graph", "compound", "child", "orientation"), &OcctlTopoBuild::topo_compound_add_child);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_compound_remove_child", "graph", "compound", "child"), &OcctlTopoBuild::topo_compound_remove_child);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_split", "graph", "edge", "parameter", "out_edge1", "out_edge2"), &OcctlTopoBuild::topo_edge_split);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_add_internal_vertex", "graph", "edge", "vertex"), &OcctlTopoBuild::topo_edge_add_internal_vertex);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_remove_vertex", "graph", "edge", "vertex"), &OcctlTopoBuild::topo_edge_remove_vertex);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_continuity", "graph", "edge", "faceA", "faceB", "out_continuity"), &OcctlTopoBuild::topo_edge_continuity);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_has_continuity", "graph", "edge", "faceA", "faceB", "out_has_continuity"), &OcctlTopoBuild::topo_edge_has_continuity);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_max_continuity", "graph", "edge", "out_continuity"), &OcctlTopoBuild::topo_edge_max_continuity);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_coedge_orientation", "graph", "coedge", "out_orientation"), &OcctlTopoBuild::topo_coedge_orientation);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_find_coedge_on_face", "graph", "edge", "face", "out_coedge"), &OcctlTopoBuild::topo_edge_find_coedge_on_face);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_find_coedge_on_face_oriented", "graph", "edge", "face", "orientation", "out_coedge"), &OcctlTopoBuild::topo_edge_find_coedge_on_face_oriented);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_vertex_point_in_usage", "graph", "vertex", "parent", "out_point"), &OcctlTopoBuild::topo_vertex_point_in_usage);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_vertex_pcurve_parameter", "graph", "vertex", "coedge", "out_u"), &OcctlTopoBuild::topo_vertex_pcurve_parameter);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_has_polygon3d", "graph", "edge", "out_has_polygon3d"), &OcctlTopoBuild::topo_edge_has_polygon3d);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_coedge_has_polygon_on_surface", "graph", "coedge", "out_has_polygon_on_surface"), &OcctlTopoBuild::topo_coedge_has_polygon_on_surface);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_face_uv_bounds_restricted", "graph", "face", "umin", "umax", "vmin", "vmax", "u", "v", "out_point", "out_d1u", "out_d1v"), &OcctlTopoBuild::topo_face_uv_bounds_restricted);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_set_vertex_point", "graph", "vertex", "point"), &OcctlTopoBuild::topo_set_vertex_point);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_set_vertex_tolerance", "graph", "vertex", "tol"), &OcctlTopoBuild::topo_set_vertex_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_set_edge_tolerance", "graph", "edge", "tol"), &OcctlTopoBuild::topo_set_edge_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_set_face_tolerance", "graph", "face", "tol"), &OcctlTopoBuild::topo_set_face_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_set_edge_param_range", "graph", "edge", "first", "last"), &OcctlTopoBuild::topo_set_edge_param_range);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_set_edge_same_parameter", "graph", "edge", "flag"), &OcctlTopoBuild::topo_set_edge_same_parameter);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_set_edge_same_range", "graph", "edge", "flag"), &OcctlTopoBuild::topo_set_edge_same_range);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_set_edge_is_degenerate", "graph", "edge", "flag"), &OcctlTopoBuild::topo_set_edge_is_degenerate);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_set_edge_is_closed", "graph", "edge", "flag"), &OcctlTopoBuild::topo_set_edge_is_closed);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_set_wire_is_closed", "graph", "wire", "flag"), &OcctlTopoBuild::topo_set_wire_is_closed);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_set_shell_is_closed", "graph", "shell", "flag"), &OcctlTopoBuild::topo_set_shell_is_closed);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_set_face_natural_restriction", "graph", "face", "flag"), &OcctlTopoBuild::topo_set_face_natural_restriction);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_set_coedge_param_range", "graph", "coedge", "first", "last"), &OcctlTopoBuild::topo_set_coedge_param_range);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_set_coedge_uv_box", "graph", "coedge", "uv_lo", "uv_hi"), &OcctlTopoBuild::topo_set_coedge_uv_box);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_clear_cached", "graph", "node", "ref"), &OcctlTopoBuild::graph_clear_cached);
    godot::ClassDB::bind_method(godot::D_METHOD("select_options_init", "options"), &OcctlTopoBuild::select_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("select_group_options_init", "options"), &OcctlTopoBuild::select_group_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("select_group_view_init", "view"), &OcctlTopoBuild::select_group_view_init);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_bbox_get", "graph", "node", "out_bbox"), &OcctlTopoBuild::graph_bbox_get);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_obb_get", "graph", "node", "out_obb"), &OcctlTopoBuild::graph_obb_get);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_face_uv_bounds_get", "graph", "face", "out_uv_bounds"), &OcctlTopoBuild::graph_face_uv_bounds_get);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_measure_get", "graph", "node", "kind", "out_value"), &OcctlTopoBuild::graph_measure_get);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_mass_properties_get", "graph", "node", "out_properties"), &OcctlTopoBuild::graph_mass_properties_get);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_edge_curve_kind_get", "graph", "edge", "out_kind"), &OcctlTopoBuild::graph_edge_curve_kind_get);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_face_surface_kind_get", "graph", "face", "out_kind"), &OcctlTopoBuild::graph_face_surface_kind_get);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_descendant_vertices_get", "graph", "node"), &OcctlTopoBuild::graph_descendant_vertices_get);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_descendant_edges_get", "graph", "node"), &OcctlTopoBuild::graph_descendant_edges_get);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_descendant_faces_get", "graph", "node"), &OcctlTopoBuild::graph_descendant_faces_get);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_descendants_get", "graph", "node", "descendant_kind"), &OcctlTopoBuild::graph_descendants_get);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_adjacent_faces_get", "graph", "face"), &OcctlTopoBuild::graph_adjacent_faces_get);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_adjacent_edges_get", "graph", "edge"), &OcctlTopoBuild::graph_adjacent_edges_get);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_pair_distance_get", "graph", "first", "second", "out_distance"), &OcctlTopoBuild::graph_pair_distance_get);
    godot::ClassDB::bind_method(godot::D_METHOD("select_iter_create", "graph", "options"), &OcctlTopoBuild::select_iter_create, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("select_tagged_iter_create", "graph", "options", "tag"), &OcctlTopoBuild::select_tagged_iter_create, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("select_iter_next", "iter", "out_node"), &OcctlTopoBuild::select_iter_next);
    godot::ClassDB::bind_method(godot::D_METHOD("select_iter_free", "iter"), &OcctlTopoBuild::select_iter_free);
    godot::ClassDB::bind_method(godot::D_METHOD("select_group_iter_create", "graph", "select_options", "group_options"), &OcctlTopoBuild::select_group_iter_create, DEFVAL(Variant()), DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("select_group_iter_next", "iter", "out_view"), &OcctlTopoBuild::select_group_iter_next);
    godot::ClassDB::bind_method(godot::D_METHOD("select_group_iter_free", "iter"), &OcctlTopoBuild::select_group_iter_free);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_clone", "source"), &OcctlTopoBuild::graph_clone);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_compact", "graph"), &OcctlTopoBuild::graph_compact);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_remove_with_replacement", "graph", "node", "replacement"), &OcctlTopoBuild::topo_remove_with_replacement);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_remove_ref", "graph", "ref_id"), &OcctlTopoBuild::topo_remove_ref);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_remove_rep", "graph", "rep_id"), &OcctlTopoBuild::topo_remove_rep);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_cleanup_removed_refs", "graph"), &OcctlTopoBuild::topo_cleanup_removed_refs);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_set_edge_start_vertex", "graph", "edge", "vertex"), &OcctlTopoBuild::topo_set_edge_start_vertex);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_set_edge_end_vertex", "graph", "edge", "vertex"), &OcctlTopoBuild::topo_set_edge_end_vertex);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_set_ref_orientation", "graph", "ref_id", "orientation"), &OcctlTopoBuild::topo_set_ref_orientation);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_set_ref_location", "graph", "ref_id", "transform"), &OcctlTopoBuild::topo_set_ref_location);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_set_wire_ref_is_outer", "graph", "ref_id", "flag"), &OcctlTopoBuild::topo_set_wire_ref_is_outer);
}

void OcctlTopoBuild::topo_make_vertex_info_init(const Ref<OcctlTopoMakeVertexInfo>& info) { // NOLINT
    occtl_topo_make_vertex_info_t _info_val = {};
    ::occtl_topo_make_vertex_info_init(&_info_val);
    ::occtl_topo_make_vertex_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

void OcctlTopoBuild::topo_make_edge_info_init(const Ref<OcctlTopoMakeEdgeInfo>& info) { // NOLINT
    occtl_topo_make_edge_info_t _info_val = {};
    ::occtl_topo_make_edge_info_init(&_info_val);
    ::occtl_topo_make_edge_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

void OcctlTopoBuild::topo_make_wire_info_init(const Ref<OcctlTopoMakeWireInfo>& info) { // NOLINT
    occtl_topo_make_wire_info_t _info_val = {};
    ::occtl_topo_make_wire_info_init(&_info_val);
    ::occtl_topo_make_wire_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

void OcctlTopoBuild::topo_edges_to_wires_options_init(const Ref<OcctlTopoEdgesToWiresOptions>& options) { // NOLINT
    occtl_topo_edges_to_wires_options_t _options_val = {};
    ::occtl_topo_edges_to_wires_options_init(&_options_val);
    ::occtl_topo_edges_to_wires_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

void OcctlTopoBuild::topo_wire_offset_2d_options_init(const Ref<OcctlTopoWireOffset2dOptions>& options) { // NOLINT
    occtl_topo_wire_offset_2d_options_t _options_val = {};
    ::occtl_topo_wire_offset_2d_options_init(&_options_val);
    ::occtl_topo_wire_offset_2d_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

void OcctlTopoBuild::topo_wire_fix_degenerate_options_init(const Ref<OcctlTopoWireFixDegenerateEdgesOptions>& options) { // NOLINT
    occtl_topo_wire_fix_degenerate_edges_options_t _options_val = {};
    ::occtl_topo_wire_fix_degenerate_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

void OcctlTopoBuild::topo_face_chamfer_2d_options_init(const Ref<OcctlTopoFaceChamfer2dOptions>& options) { // NOLINT
    occtl_topo_face_chamfer_2d_options_t _options_val = {};
    ::occtl_topo_face_chamfer_2d_options_init(&_options_val);
    ::occtl_topo_face_chamfer_2d_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

void OcctlTopoBuild::topo_wire_chamfer_2d_options_init(const Ref<OcctlTopoWireChamfer2dOptions>& options) { // NOLINT
    occtl_topo_wire_chamfer_2d_options_t _options_val = {};
    ::occtl_topo_wire_chamfer_2d_options_init(&_options_val);
    ::occtl_topo_wire_chamfer_2d_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

void OcctlTopoBuild::topo_make_face_info_init(const Ref<OcctlTopoMakeFaceInfo>& info) { // NOLINT
    occtl_topo_make_face_info_t _info_val = {};
    ::occtl_topo_make_face_info_init(&_info_val);
    ::occtl_topo_make_face_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

void OcctlTopoBuild::topo_make_face_from_wires_auto_options_init(const Ref<OcctlTopoMakeFaceFromWiresAutoOptions>& options) { // NOLINT
    occtl_topo_make_face_from_wires_auto_options_t _options_val = {};
    ::occtl_topo_make_face_from_wires_auto_options_init(&_options_val);
    ::occtl_topo_make_face_from_wires_auto_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

void OcctlTopoBuild::topo_make_shell_info_init(const Ref<OcctlTopoMakeShellInfo>& info) { // NOLINT
    occtl_topo_make_shell_info_t _info_val = {};
    ::occtl_topo_make_shell_info_init(&_info_val);
    ::occtl_topo_make_shell_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

void OcctlTopoBuild::topo_make_solid_info_init(const Ref<OcctlTopoMakeSolidInfo>& info) { // NOLINT
    occtl_topo_make_solid_info_t _info_val = {};
    ::occtl_topo_make_solid_info_init(&_info_val);
    ::occtl_topo_make_solid_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

void OcctlTopoBuild::topo_make_compound_info_init(const Ref<OcctlTopoMakeCompoundInfo>& info) { // NOLINT
    occtl_topo_make_compound_info_t _info_val = {};
    ::occtl_topo_make_compound_info_init(&_info_val);
    ::occtl_topo_make_compound_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlTopoBuild::topo_make_vertex(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoMakeVertexInfo>& info, const Ref<OcctlNodeId>& out_vertex) { // NOLINT
    occtl_topo_make_vertex_info_t _info_c = {};
    const occtl_topo_make_vertex_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_vertex_val = {};
    occtl_status_t _status = ::occtl_topo_make_vertex(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_vertex_val);
    if (out_vertex.is_valid()) out_vertex->copy_from_c(_out_vertex_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_make_edge(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoMakeEdgeInfo>& info, const Ref<OcctlNodeId>& out_edge) { // NOLINT
    occtl_topo_make_edge_info_t _info_c = {};
    const occtl_topo_make_edge_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_edge_val = {};
    occtl_status_t _status = ::occtl_topo_make_edge(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_edge_val);
    if (out_edge.is_valid()) out_edge->copy_from_c(_out_edge_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_make_wire(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoMakeWireInfo>& info, const Ref<OcctlNodeId>& out_wire) { // NOLINT
    occtl_topo_make_wire_info_t _info_c = {};
    const occtl_topo_make_wire_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_wire_val = {};
    occtl_status_t _status = ::occtl_topo_make_wire(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_wire_val);
    if (out_wire.is_valid()) out_wire->copy_from_c(_out_wire_val);
    return static_cast<int>(_status);
}

PackedInt64Array OcctlTopoBuild::topo_edges_to_wires(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoEdgesToWiresOptions>& options) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_topo_edges_to_wires_options_t _options_c = {};
    const occtl_topo_edges_to_wires_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_status_t _err = ::occtl_topo_edges_to_wires(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt64Array(); }
    std::vector<occtl_node_id_t> _out_wires_buf(_out_count_cnt);
    _err = ::occtl_topo_edges_to_wires(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, _out_wires_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_wires_buf[_i].bits);
    return _result;
}

int OcctlTopoBuild::topo_wire_offset_2d(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoWireOffset2dOptions>& options, const Ref<OcctlNodeId>& out_wire) { // NOLINT
    occtl_topo_wire_offset_2d_options_t _options_c = {};
    const occtl_topo_wire_offset_2d_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_node_id_t _out_wire_val = {};
    occtl_status_t _status = ::occtl_topo_wire_offset_2d(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_wire_val);
    if (out_wire.is_valid()) out_wire->copy_from_c(_out_wire_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_curves_to_wire(const Ref<OcctlGraphHandle>& graph, const PackedInt64Array& curve_ids, const Ref<OcctlNodeId>& out_wire) { // NOLINT
    occtl_node_id_t _out_wire_val = {};
    occtl_status_t _status = ::occtl_topo_curves_to_wire(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), reinterpret_cast<const occtl_rep_id_t*>(static_cast<const void*>(curve_ids.ptr())), static_cast<size_t>(curve_ids.size()), &_out_wire_val);
    if (out_wire.is_valid()) out_wire->copy_from_c(_out_wire_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_wire_fix_degenerate(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoWireFixDegenerateEdgesOptions>& options, const Ref<OcctlSize>& out_removed) { // NOLINT
    occtl_topo_wire_fix_degenerate_edges_options_t _options_c = {};
    const occtl_topo_wire_fix_degenerate_edges_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    size_t _out_removed_val = {};
    occtl_status_t _status = ::occtl_topo_wire_fix_degenerate(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_removed_val);
    if (out_removed.is_valid()) out_removed->copy_from_c(_out_removed_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_face_chamfer_2d(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoFaceChamfer2dOptions>& options, const Ref<OcctlNodeId>& out_face) { // NOLINT
    occtl_topo_face_chamfer_2d_options_t _options_c = {};
    const occtl_topo_face_chamfer_2d_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_node_id_t _out_face_val = {};
    occtl_status_t _status = ::occtl_topo_face_chamfer_2d(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_face_val);
    if (out_face.is_valid()) out_face->copy_from_c(_out_face_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_wire_chamfer_2d(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoWireChamfer2dOptions>& options, const Ref<OcctlNodeId>& out_wire) { // NOLINT
    occtl_topo_wire_chamfer_2d_options_t _options_c = {};
    const occtl_topo_wire_chamfer_2d_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_node_id_t _out_wire_val = {};
    occtl_status_t _status = ::occtl_topo_wire_chamfer_2d(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_wire_val);
    if (out_wire.is_valid()) out_wire->copy_from_c(_out_wire_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_make_face(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoMakeFaceInfo>& info, const Ref<OcctlNodeId>& out_face) { // NOLINT
    occtl_topo_make_face_info_t _info_c = {};
    const occtl_topo_make_face_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_face_val = {};
    occtl_status_t _status = ::occtl_topo_make_face(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_face_val);
    if (out_face.is_valid()) out_face->copy_from_c(_out_face_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_make_face_from_wires_auto(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoMakeFaceFromWiresAutoOptions>& options, const Ref<OcctlNodeId>& out_face) { // NOLINT
    occtl_topo_make_face_from_wires_auto_options_t _options_c = {};
    const occtl_topo_make_face_from_wires_auto_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_node_id_t _out_face_val = {};
    occtl_status_t _status = ::occtl_topo_make_face_from_wires_auto(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_face_val);
    if (out_face.is_valid()) out_face->copy_from_c(_out_face_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_make_shell(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoMakeShellInfo>& info, const Ref<OcctlNodeId>& out_shell) { // NOLINT
    occtl_topo_make_shell_info_t _info_c = {};
    const occtl_topo_make_shell_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_shell_val = {};
    occtl_status_t _status = ::occtl_topo_make_shell(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_shell_val);
    if (out_shell.is_valid()) out_shell->copy_from_c(_out_shell_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_make_solid(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoMakeSolidInfo>& info, const Ref<OcctlNodeId>& out_solid) { // NOLINT
    occtl_topo_make_solid_info_t _info_c = {};
    const occtl_topo_make_solid_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_solid_val = {};
    occtl_status_t _status = ::occtl_topo_make_solid(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_solid_val);
    if (out_solid.is_valid()) out_solid->copy_from_c(_out_solid_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_make_compound(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoMakeCompoundInfo>& info, const Ref<OcctlNodeId>& out_compound) { // NOLINT
    occtl_topo_make_compound_info_t _info_c = {};
    const occtl_topo_make_compound_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_compound_val = {};
    occtl_status_t _status = ::occtl_topo_make_compound(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_compound_val);
    if (out_compound.is_valid()) out_compound->copy_from_c(_out_compound_val);
    return static_cast<int>(_status);
}

void OcctlTopoBuild::topo_make_compsolid_info_init(const Ref<OcctlTopoMakeCompsolidInfo>& info) { // NOLINT
    occtl_topo_make_compsolid_info_t _info_val = {};
    ::occtl_topo_make_compsolid_info_init(&_info_val);
    ::occtl_topo_make_compsolid_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlTopoBuild::topo_make_compsolid(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoMakeCompsolidInfo>& info, const Ref<OcctlNodeId>& out_compsolid) { // NOLINT
    occtl_topo_make_compsolid_info_t _info_c = {};
    const occtl_topo_make_compsolid_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_compsolid_val = {};
    occtl_status_t _status = ::occtl_topo_make_compsolid(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_compsolid_val);
    if (out_compsolid.is_valid()) out_compsolid->copy_from_c(_out_compsolid_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_remove(const Ref<OcctlGraphHandle>& graph, int64_t id) { // NOLINT
    occtl_status_t _status = ::occtl_topo_remove(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(id)});
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_remove_subgraph(const Ref<OcctlGraphHandle>& graph, int64_t id) { // NOLINT
    occtl_status_t _status = ::occtl_topo_remove_subgraph(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(id)});
    return static_cast<int>(_status);
}

int OcctlTopoBuild::graph_begin_batch(const Ref<OcctlGraphHandle>& graph) { // NOLINT
    occtl_batch_t* _out_batch_val = nullptr;
    occtl_status_t _status = ::occtl_graph_begin_batch(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_batch_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::batch_commit(int64_t batch) { // NOLINT
    occtl_status_t _status = ::occtl_batch_commit(reinterpret_cast<occtl_batch_t*>(static_cast<uintptr_t>(static_cast<int64_t>(batch))));
    return static_cast<int>(_status);
}

int OcctlTopoBuild::batch_abort(int64_t batch) { // NOLINT
    occtl_status_t _status = ::occtl_batch_abort(reinterpret_cast<occtl_batch_t*>(static_cast<uintptr_t>(static_cast<int64_t>(batch))));
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_replace_edge_curve(const Ref<OcctlGraphHandle>& graph, int64_t edge, int64_t curve_id) { // NOLINT
    occtl_status_t _status = ::occtl_topo_replace_edge_curve(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, occtl_rep_id_t{static_cast<uint64_t>(curve_id)});
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_replace_face_surface(const Ref<OcctlGraphHandle>& graph, int64_t face, int64_t surface_id) { // NOLINT
    occtl_status_t _status = ::occtl_topo_replace_face_surface(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, occtl_rep_id_t{static_cast<uint64_t>(surface_id)});
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_replace_coedge_pcurve(const Ref<OcctlGraphHandle>& graph, int64_t coedge, int64_t pcurve_id) { // NOLINT
    occtl_status_t _status = ::occtl_topo_replace_coedge_pcurve(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(coedge)}, occtl_rep_id_t{static_cast<uint64_t>(pcurve_id)});
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_add_pcurve(const Ref<OcctlGraphHandle>& graph, int64_t edge, int64_t face, int64_t pcurve_id, double first, double last, int orientation) { // NOLINT
    occtl_status_t _status = ::occtl_topo_add_pcurve(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, occtl_node_id_t{static_cast<uint64_t>(face)}, occtl_rep_id_t{static_cast<uint64_t>(pcurve_id)}, first, last, static_cast<occtl_orientation_t>(orientation));
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_shell_add_face(const Ref<OcctlGraphHandle>& graph, int64_t shell, int64_t face, int orientation) { // NOLINT
    occtl_status_t _status = ::occtl_topo_shell_add_face(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(shell)}, occtl_node_id_t{static_cast<uint64_t>(face)}, static_cast<occtl_orientation_t>(orientation));
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_shell_remove_face(const Ref<OcctlGraphHandle>& graph, int64_t shell, int64_t face) { // NOLINT
    occtl_status_t _status = ::occtl_topo_shell_remove_face(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(shell)}, occtl_node_id_t{static_cast<uint64_t>(face)});
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_face_add_holes(const Ref<OcctlGraphHandle>& graph, int64_t face, const PackedInt64Array& holes) { // NOLINT
    occtl_status_t _status = ::occtl_topo_face_add_holes(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, reinterpret_cast<const occtl_node_id_t*>(static_cast<const void*>(holes.ptr())), static_cast<size_t>(holes.size()));
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_face_remove_holes(const Ref<OcctlGraphHandle>& graph, int64_t face, const PackedInt64Array& holes) { // NOLINT
    occtl_status_t _status = ::occtl_topo_face_remove_holes(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, reinterpret_cast<const occtl_node_id_t*>(static_cast<const void*>(holes.ptr())), static_cast<size_t>(holes.size()));
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_solid_add_shell(const Ref<OcctlGraphHandle>& graph, int64_t solid, int64_t shell, int orientation) { // NOLINT
    occtl_status_t _status = ::occtl_topo_solid_add_shell(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(solid)}, occtl_node_id_t{static_cast<uint64_t>(shell)}, static_cast<occtl_orientation_t>(orientation));
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_solid_remove_shell(const Ref<OcctlGraphHandle>& graph, int64_t solid, int64_t shell) { // NOLINT
    occtl_status_t _status = ::occtl_topo_solid_remove_shell(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(solid)}, occtl_node_id_t{static_cast<uint64_t>(shell)});
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_compound_add_child(const Ref<OcctlGraphHandle>& graph, int64_t compound, int64_t child, int orientation) { // NOLINT
    occtl_status_t _status = ::occtl_topo_compound_add_child(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(compound)}, occtl_node_id_t{static_cast<uint64_t>(child)}, static_cast<occtl_orientation_t>(orientation));
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_compound_remove_child(const Ref<OcctlGraphHandle>& graph, int64_t compound, int64_t child) { // NOLINT
    occtl_status_t _status = ::occtl_topo_compound_remove_child(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(compound)}, occtl_node_id_t{static_cast<uint64_t>(child)});
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_edge_split(const Ref<OcctlGraphHandle>& graph, int64_t edge, double parameter, const Ref<OcctlNodeId>& out_edge1, const Ref<OcctlNodeId>& out_edge2) { // NOLINT
    occtl_node_id_t _out_edge1_val = {};
    occtl_node_id_t _out_edge2_val = {};
    occtl_status_t _status = ::occtl_topo_edge_split(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, parameter, &_out_edge1_val, &_out_edge2_val);
    if (out_edge1.is_valid()) out_edge1->copy_from_c(_out_edge1_val);
    if (out_edge2.is_valid()) out_edge2->copy_from_c(_out_edge2_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_edge_add_internal_vertex(const Ref<OcctlGraphHandle>& graph, int64_t edge, int64_t vertex) { // NOLINT
    occtl_status_t _status = ::occtl_topo_edge_add_internal_vertex(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, occtl_node_id_t{static_cast<uint64_t>(vertex)});
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_edge_remove_vertex(const Ref<OcctlGraphHandle>& graph, int64_t edge, int64_t vertex) { // NOLINT
    occtl_status_t _status = ::occtl_topo_edge_remove_vertex(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, occtl_node_id_t{static_cast<uint64_t>(vertex)});
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_edge_continuity(const Ref<OcctlGraphHandle>& graph, int64_t edge, int64_t faceA, int64_t faceB, const Ref<OcctlInt32>& out_continuity) { // NOLINT
    occtl_shape_continuity_t _out_continuity_val = {};
    occtl_status_t _status = ::occtl_topo_edge_continuity(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, occtl_node_id_t{static_cast<uint64_t>(faceA)}, occtl_node_id_t{static_cast<uint64_t>(faceB)}, &_out_continuity_val);
    if (out_continuity.is_valid()) out_continuity->copy_from_c(_out_continuity_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_edge_has_continuity(const Ref<OcctlGraphHandle>& graph, int64_t edge, int64_t faceA, int64_t faceB, const Ref<OcctlInt32>& out_has_continuity) { // NOLINT
    int32_t _out_has_continuity_val = {};
    occtl_status_t _status = ::occtl_topo_edge_has_continuity(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, occtl_node_id_t{static_cast<uint64_t>(faceA)}, occtl_node_id_t{static_cast<uint64_t>(faceB)}, &_out_has_continuity_val);
    if (out_has_continuity.is_valid()) out_has_continuity->copy_from_c(_out_has_continuity_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_edge_max_continuity(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlInt32>& out_continuity) { // NOLINT
    occtl_shape_continuity_t _out_continuity_val = {};
    occtl_status_t _status = ::occtl_topo_edge_max_continuity(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, &_out_continuity_val);
    if (out_continuity.is_valid()) out_continuity->copy_from_c(_out_continuity_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_coedge_orientation(const Ref<OcctlGraphHandle>& graph, int64_t coedge, const Ref<OcctlInt32>& out_orientation) { // NOLINT
    occtl_orientation_t _out_orientation_val = {};
    occtl_status_t _status = ::occtl_topo_coedge_orientation(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(coedge)}, &_out_orientation_val);
    if (out_orientation.is_valid()) out_orientation->copy_from_c(_out_orientation_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_edge_find_coedge_on_face(const Ref<OcctlGraphHandle>& graph, int64_t edge, int64_t face, const Ref<OcctlNodeId>& out_coedge) { // NOLINT
    occtl_node_id_t _out_coedge_val = {};
    occtl_status_t _status = ::occtl_topo_edge_find_coedge_on_face(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, occtl_node_id_t{static_cast<uint64_t>(face)}, &_out_coedge_val);
    if (out_coedge.is_valid()) out_coedge->copy_from_c(_out_coedge_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_edge_find_coedge_on_face_oriented(const Ref<OcctlGraphHandle>& graph, int64_t edge, int64_t face, int orientation, const Ref<OcctlNodeId>& out_coedge) { // NOLINT
    occtl_node_id_t _out_coedge_val = {};
    occtl_status_t _status = ::occtl_topo_edge_find_coedge_on_face_oriented(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, occtl_node_id_t{static_cast<uint64_t>(face)}, static_cast<occtl_orientation_t>(orientation), &_out_coedge_val);
    if (out_coedge.is_valid()) out_coedge->copy_from_c(_out_coedge_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_vertex_point_in_usage(const Ref<OcctlGraphHandle>& graph, int64_t vertex, int64_t parent, const Ref<OcctlPoint3>& out_point) { // NOLINT
    occtl_point3_t _out_point_val = {};
    occtl_status_t _status = ::occtl_topo_vertex_point_in_usage(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(vertex)}, occtl_node_id_t{static_cast<uint64_t>(parent)}, &_out_point_val);
    if (out_point.is_valid()) out_point->copy_from_c(_out_point_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_vertex_pcurve_parameter(const Ref<OcctlGraphHandle>& graph, int64_t vertex, int64_t coedge, const Ref<OcctlDouble>& out_u) { // NOLINT
    double _out_u_val = {};
    occtl_status_t _status = ::occtl_topo_vertex_pcurve_parameter(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(vertex)}, occtl_node_id_t{static_cast<uint64_t>(coedge)}, &_out_u_val);
    if (out_u.is_valid()) out_u->copy_from_c(_out_u_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_edge_has_polygon3d(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlInt32>& out_has_polygon3d) { // NOLINT
    int32_t _out_has_polygon3d_val = {};
    occtl_status_t _status = ::occtl_topo_edge_has_polygon3d(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, &_out_has_polygon3d_val);
    if (out_has_polygon3d.is_valid()) out_has_polygon3d->copy_from_c(_out_has_polygon3d_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_coedge_has_polygon_on_surface(const Ref<OcctlGraphHandle>& graph, int64_t coedge, const Ref<OcctlInt32>& out_has_polygon_on_surface) { // NOLINT
    int32_t _out_has_polygon_on_surface_val = {};
    occtl_status_t _status = ::occtl_topo_coedge_has_polygon_on_surface(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(coedge)}, &_out_has_polygon_on_surface_val);
    if (out_has_polygon_on_surface.is_valid()) out_has_polygon_on_surface->copy_from_c(_out_has_polygon_on_surface_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_face_uv_bounds_restricted(const Ref<OcctlGraphHandle>& graph, int64_t face, double umin, double umax, double vmin, double vmax, double u, double v, const Ref<OcctlPoint3>& out_point, const Ref<OcctlVector3>& out_d1u, const Ref<OcctlVector3>& out_d1v) { // NOLINT
    occtl_point3_t _out_point_val = {};
    occtl_vector3_t _out_d1u_val = {};
    occtl_vector3_t _out_d1v_val = {};
    occtl_status_t _status = ::occtl_topo_face_uv_bounds_restricted(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, umin, umax, vmin, vmax, u, v, &_out_point_val, &_out_d1u_val, &_out_d1v_val);
    if (out_point.is_valid()) out_point->copy_from_c(_out_point_val);
    if (out_d1u.is_valid()) out_d1u->copy_from_c(_out_d1u_val);
    if (out_d1v.is_valid()) out_d1v->copy_from_c(_out_d1v_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_set_vertex_point(const Ref<OcctlGraphHandle>& graph, int64_t vertex, const Ref<OcctlPoint3>& point) { // NOLINT
    occtl_status_t _status = ::occtl_topo_set_vertex_point(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(vertex)}, point->to_c());
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_set_vertex_tolerance(const Ref<OcctlGraphHandle>& graph, int64_t vertex, double tol) { // NOLINT
    occtl_status_t _status = ::occtl_topo_set_vertex_tolerance(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(vertex)}, tol);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_set_edge_tolerance(const Ref<OcctlGraphHandle>& graph, int64_t edge, double tol) { // NOLINT
    occtl_status_t _status = ::occtl_topo_set_edge_tolerance(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, tol);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_set_face_tolerance(const Ref<OcctlGraphHandle>& graph, int64_t face, double tol) { // NOLINT
    occtl_status_t _status = ::occtl_topo_set_face_tolerance(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, tol);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_set_edge_param_range(const Ref<OcctlGraphHandle>& graph, int64_t edge, double first, double last) { // NOLINT
    occtl_status_t _status = ::occtl_topo_set_edge_param_range(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, first, last);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_set_edge_same_parameter(const Ref<OcctlGraphHandle>& graph, int64_t edge, int flag) { // NOLINT
    occtl_status_t _status = ::occtl_topo_set_edge_same_parameter(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, flag);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_set_edge_same_range(const Ref<OcctlGraphHandle>& graph, int64_t edge, int flag) { // NOLINT
    occtl_status_t _status = ::occtl_topo_set_edge_same_range(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, flag);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_set_edge_is_degenerate(const Ref<OcctlGraphHandle>& graph, int64_t edge, int flag) { // NOLINT
    occtl_status_t _status = ::occtl_topo_set_edge_is_degenerate(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, flag);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_set_edge_is_closed(const Ref<OcctlGraphHandle>& graph, int64_t edge, int flag) { // NOLINT
    occtl_status_t _status = ::occtl_topo_set_edge_is_closed(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, flag);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_set_wire_is_closed(const Ref<OcctlGraphHandle>& graph, int64_t wire, int flag) { // NOLINT
    occtl_status_t _status = ::occtl_topo_set_wire_is_closed(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(wire)}, flag);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_set_shell_is_closed(const Ref<OcctlGraphHandle>& graph, int64_t shell, int flag) { // NOLINT
    occtl_status_t _status = ::occtl_topo_set_shell_is_closed(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(shell)}, flag);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_set_face_natural_restriction(const Ref<OcctlGraphHandle>& graph, int64_t face, int flag) { // NOLINT
    occtl_status_t _status = ::occtl_topo_set_face_natural_restriction(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, flag);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_set_coedge_param_range(const Ref<OcctlGraphHandle>& graph, int64_t coedge, double first, double last) { // NOLINT
    occtl_status_t _status = ::occtl_topo_set_coedge_param_range(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(coedge)}, first, last);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_set_coedge_uv_box(const Ref<OcctlGraphHandle>& graph, int64_t coedge, const Ref<OcctlPoint2>& uv_lo, const Ref<OcctlPoint2>& uv_hi) { // NOLINT
    occtl_status_t _status = ::occtl_topo_set_coedge_uv_box(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(coedge)}, uv_lo->to_c(), uv_hi->to_c());
    return static_cast<int>(_status);
}

int OcctlTopoBuild::graph_clear_cached(const Ref<OcctlGraphHandle>& graph, int64_t node, int64_t ref) { // NOLINT
    occtl_status_t _status = ::occtl_graph_clear_cached(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node)}, occtl_ref_id_t{static_cast<uint64_t>(ref)});
    return static_cast<int>(_status);
}

void OcctlTopoBuild::select_options_init(const Ref<OcctlSelectOptions>& options) { // NOLINT
    occtl_select_options_t _options_val = {};
    ::occtl_select_options_init(&_options_val);
    ::occtl_select_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

void OcctlTopoBuild::select_group_options_init(const Ref<OcctlSelectGroupOptions>& options) { // NOLINT
    occtl_select_group_options_t _options_val = {};
    ::occtl_select_group_options_init(&_options_val);
    ::occtl_select_group_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

void OcctlTopoBuild::select_group_view_init(const Ref<OcctlSelectGroupView>& view) { // NOLINT
    occtl_select_group_view_t _view_val = {};
    ::occtl_select_group_view_init(&_view_val);
    ::occtl_select_group_view_init(&_view_val);
    if (view.is_valid()) view->copy_from_c(_view_val);
}

int OcctlTopoBuild::graph_bbox_get(const Ref<OcctlGraphHandle>& graph, int64_t node, const Ref<OcctlSelectBbox>& out_bbox) { // NOLINT
    occtl_select_bbox_t _out_bbox_val = {};
    occtl_status_t _status = ::occtl_graph_bbox_get(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node)}, &_out_bbox_val);
    if (out_bbox.is_valid()) out_bbox->copy_from_c(_out_bbox_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::graph_obb_get(const Ref<OcctlGraphHandle>& graph, int64_t node, const Ref<OcctlGraphObb>& out_obb) { // NOLINT
    occtl_graph_obb_t _out_obb_val = {};
    occtl_status_t _status = ::occtl_graph_obb_get(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node)}, &_out_obb_val);
    if (out_obb.is_valid()) out_obb->copy_from_c(_out_obb_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::graph_face_uv_bounds_get(const Ref<OcctlGraphHandle>& graph, int64_t face, const Ref<OcctlGraphUvBounds>& out_uv_bounds) { // NOLINT
    occtl_graph_uv_bounds_t _out_uv_bounds_val = {};
    occtl_status_t _status = ::occtl_graph_face_uv_bounds_get(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, &_out_uv_bounds_val);
    if (out_uv_bounds.is_valid()) out_uv_bounds->copy_from_c(_out_uv_bounds_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::graph_measure_get(const Ref<OcctlGraphHandle>& graph, int64_t node, int kind, const Ref<OcctlDouble>& out_value) { // NOLINT
    double _out_value_val = {};
    occtl_status_t _status = ::occtl_graph_measure_get(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node)}, static_cast<occtl_select_measure_kind_t>(kind), &_out_value_val);
    if (out_value.is_valid()) out_value->copy_from_c(_out_value_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::graph_mass_properties_get(const Ref<OcctlGraphHandle>& graph, int64_t node, const Ref<OcctlGraphMassProperties>& out_properties) { // NOLINT
    occtl_graph_mass_properties_t _out_properties_val = {};
    occtl_status_t _status = ::occtl_graph_mass_properties_get(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node)}, &_out_properties_val);
    if (out_properties.is_valid()) out_properties->copy_from_c(_out_properties_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::graph_edge_curve_kind_get(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlInt32>& out_kind) { // NOLINT
    occtl_curve_kind_t _out_kind_val = {};
    occtl_status_t _status = ::occtl_graph_edge_curve_kind_get(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, &_out_kind_val);
    if (out_kind.is_valid()) out_kind->copy_from_c(_out_kind_val);
    return static_cast<int>(_status);
}

int OcctlTopoBuild::graph_face_surface_kind_get(const Ref<OcctlGraphHandle>& graph, int64_t face, const Ref<OcctlInt32>& out_kind) { // NOLINT
    occtl_surface_kind_t _out_kind_val = {};
    occtl_status_t _status = ::occtl_graph_face_surface_kind_get(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, &_out_kind_val);
    if (out_kind.is_valid()) out_kind->copy_from_c(_out_kind_val);
    return static_cast<int>(_status);
}

PackedInt64Array OcctlTopoBuild::graph_descendant_vertices_get(const Ref<OcctlGraphHandle>& graph, int64_t node) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_graph_descendant_vertices_get(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt64Array(); }
    std::vector<occtl_node_id_t> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_graph_descendant_vertices_get(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_buf_buf[_i].bits);
    return _result;
}

PackedInt64Array OcctlTopoBuild::graph_descendant_edges_get(const Ref<OcctlGraphHandle>& graph, int64_t node) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_graph_descendant_edges_get(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt64Array(); }
    std::vector<occtl_node_id_t> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_graph_descendant_edges_get(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_buf_buf[_i].bits);
    return _result;
}

PackedInt64Array OcctlTopoBuild::graph_descendant_faces_get(const Ref<OcctlGraphHandle>& graph, int64_t node) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_graph_descendant_faces_get(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt64Array(); }
    std::vector<occtl_node_id_t> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_graph_descendant_faces_get(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_buf_buf[_i].bits);
    return _result;
}

PackedInt64Array OcctlTopoBuild::graph_descendants_get(const Ref<OcctlGraphHandle>& graph, int64_t node, int descendant_kind) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_graph_descendants_get(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node)}, static_cast<occtl_node_kind_t>(descendant_kind), nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt64Array(); }
    std::vector<occtl_node_id_t> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_graph_descendants_get(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node)}, static_cast<occtl_node_kind_t>(descendant_kind), _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_buf_buf[_i].bits);
    return _result;
}

PackedInt64Array OcctlTopoBuild::graph_adjacent_faces_get(const Ref<OcctlGraphHandle>& graph, int64_t face) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_graph_adjacent_faces_get(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt64Array(); }
    std::vector<occtl_node_id_t> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_graph_adjacent_faces_get(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_buf_buf[_i].bits);
    return _result;
}

PackedInt64Array OcctlTopoBuild::graph_adjacent_edges_get(const Ref<OcctlGraphHandle>& graph, int64_t edge) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_graph_adjacent_edges_get(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt64Array(); }
    std::vector<occtl_node_id_t> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_graph_adjacent_edges_get(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_buf_buf[_i].bits);
    return _result;
}

int OcctlTopoBuild::graph_pair_distance_get(const Ref<OcctlGraphHandle>& graph, int64_t first, int64_t second, const Ref<OcctlDouble>& out_distance) { // NOLINT
    double _out_distance_val = {};
    occtl_status_t _status = ::occtl_graph_pair_distance_get(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(first)}, occtl_node_id_t{static_cast<uint64_t>(second)}, &_out_distance_val);
    if (out_distance.is_valid()) out_distance->copy_from_c(_out_distance_val);
    return static_cast<int>(_status);
}

Ref<OcctlSelectIterHandle> OcctlTopoBuild::select_iter_create(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSelectOptions>& options) { // NOLINT
    occtl_select_options_t _options_c = {};
    const occtl_select_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_select_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_select_iter_create(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlSelectIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlSelectIterHandle>(); }
    Ref<OcctlSelectIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

Ref<OcctlSelectIterHandle> OcctlTopoBuild::select_tagged_iter_create(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSelectOptions>& options, const String& tag) { // NOLINT
    occtl_select_options_t _options_c = {};
    const occtl_select_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_select_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_select_tagged_iter_create(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, tag.utf8().get_data(), static_cast<size_t>(tag.utf8().length()), &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlSelectIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlSelectIterHandle>(); }
    Ref<OcctlSelectIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

int OcctlTopoBuild::select_iter_next(const Ref<OcctlSelectIterHandle>& iter, const Ref<OcctlNodeId>& out_node) { // NOLINT
    occtl_node_id_t _out_node_val = {};
    occtl_status_t _status = ::occtl_select_iter_next(reinterpret_cast<occtl_select_iter_t*>(static_cast<uintptr_t>(iter.is_valid() ? iter->get_handle() : 0)), &_out_node_val);
    if (out_node.is_valid()) out_node->copy_from_c(_out_node_val);
    return static_cast<int>(_status);
}

void OcctlTopoBuild::select_iter_free(const Ref<OcctlSelectIterHandle>& iter) { // NOLINT
    ::occtl_select_iter_free(reinterpret_cast<occtl_select_iter_t*>(static_cast<uintptr_t>(iter.is_valid() ? iter->release() : 0)));
}

Ref<OcctlSelectGroupIterHandle> OcctlTopoBuild::select_group_iter_create(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSelectOptions>& select_options, const Ref<OcctlSelectGroupOptions>& group_options) { // NOLINT
    occtl_select_options_t _select_options_c = {};
    const occtl_select_options_t* _select_options_ptr = nullptr;
    if (select_options.is_valid()) { _select_options_c = select_options->to_c(); _select_options_ptr = &_select_options_c; }
    occtl_select_group_options_t _group_options_c = {};
    const occtl_select_group_options_t* _group_options_ptr = nullptr;
    if (group_options.is_valid()) { _group_options_c = group_options->to_c(); _group_options_ptr = &_group_options_c; }
    occtl_select_group_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_select_group_iter_create(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _select_options_ptr, _group_options_ptr, &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlSelectGroupIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlSelectGroupIterHandle>(); }
    Ref<OcctlSelectGroupIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

int OcctlTopoBuild::select_group_iter_next(const Ref<OcctlSelectGroupIterHandle>& iter, const Ref<OcctlSelectGroupView>& out_view) { // NOLINT
    occtl_select_group_view_t _out_view_val = {};
    ::occtl_select_group_view_init(&_out_view_val);
    occtl_status_t _status = ::occtl_select_group_iter_next(reinterpret_cast<occtl_select_group_iter_t*>(static_cast<uintptr_t>(iter.is_valid() ? iter->get_handle() : 0)), &_out_view_val);
    if (out_view.is_valid()) out_view->copy_from_c(_out_view_val);
    return static_cast<int>(_status);
}

void OcctlTopoBuild::select_group_iter_free(const Ref<OcctlSelectGroupIterHandle>& iter) { // NOLINT
    ::occtl_select_group_iter_free(reinterpret_cast<occtl_select_group_iter_t*>(static_cast<uintptr_t>(iter.is_valid() ? iter->release() : 0)));
}

Ref<OcctlGraphHandle> OcctlTopoBuild::graph_clone(const Ref<OcctlGraphHandle>& source) { // NOLINT
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_status_t _status = ::occtl_graph_clone(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(source.is_valid() ? source->get_handle() : 0)), &_out_graph_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

int OcctlTopoBuild::graph_compact(const Ref<OcctlGraphHandle>& graph) { // NOLINT
    occtl_status_t _status = ::occtl_graph_compact(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)));
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_remove_with_replacement(const Ref<OcctlGraphHandle>& graph, int64_t node, int64_t replacement) { // NOLINT
    occtl_status_t _status = ::occtl_topo_remove_with_replacement(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node)}, occtl_node_id_t{static_cast<uint64_t>(replacement)});
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_remove_ref(const Ref<OcctlGraphHandle>& graph, int64_t ref_id) { // NOLINT
    occtl_status_t _status = ::occtl_topo_remove_ref(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_ref_id_t{static_cast<uint64_t>(ref_id)});
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_remove_rep(const Ref<OcctlGraphHandle>& graph, int64_t rep_id) { // NOLINT
    occtl_status_t _status = ::occtl_topo_remove_rep(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(rep_id)});
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_cleanup_removed_refs(const Ref<OcctlGraphHandle>& graph) { // NOLINT
    occtl_status_t _status = ::occtl_topo_cleanup_removed_refs(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)));
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_set_edge_start_vertex(const Ref<OcctlGraphHandle>& graph, int64_t edge, int64_t vertex) { // NOLINT
    occtl_status_t _status = ::occtl_topo_set_edge_start_vertex(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, occtl_node_id_t{static_cast<uint64_t>(vertex)});
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_set_edge_end_vertex(const Ref<OcctlGraphHandle>& graph, int64_t edge, int64_t vertex) { // NOLINT
    occtl_status_t _status = ::occtl_topo_set_edge_end_vertex(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, occtl_node_id_t{static_cast<uint64_t>(vertex)});
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_set_ref_orientation(const Ref<OcctlGraphHandle>& graph, int64_t ref_id, int orientation) { // NOLINT
    occtl_status_t _status = ::occtl_topo_set_ref_orientation(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_ref_id_t{static_cast<uint64_t>(ref_id)}, static_cast<occtl_orientation_t>(orientation));
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_set_ref_location(const Ref<OcctlGraphHandle>& graph, int64_t ref_id, const Ref<OcctlTransform>& transform) { // NOLINT
    occtl_status_t _status = ::occtl_topo_set_ref_location(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_ref_id_t{static_cast<uint64_t>(ref_id)}, transform->to_c());
    return static_cast<int>(_status);
}

int OcctlTopoBuild::topo_set_wire_ref_is_outer(const Ref<OcctlGraphHandle>& graph, int64_t ref_id, int flag) { // NOLINT
    occtl_status_t _status = ::occtl_topo_set_wire_ref_is_outer(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_ref_id_t{static_cast<uint64_t>(ref_id)}, flag);
    return static_cast<int>(_status);
}
