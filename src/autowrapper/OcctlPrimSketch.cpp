#include "OcctlPrimSketch.h"

#include "occtl/occtl_prim_sketch.h"

void OcctlPrimSketch::_bind_methods() {
    BIND_CONSTANT(OCCTL_PRIM_POLYLINE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_REGULAR_POLYGON_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_RECTANGLE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_CIRCLE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_ELLIPSE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_PLANAR_FACE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_CONVEX_HULL_2D_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_TRACE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_CONSTRAINED_EDGE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_ARC_3PT_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_ARC_CENTER_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_SPLINE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_PLANE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_DISK_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_SLOT_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_TUBE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_HELIX_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_FILLET_2D_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_FULL_ROUND_2D_INFO_VERSION_1);
    godot::ClassDB::bind_method(godot::D_METHOD("polyline_info_init", "info"), &OcctlPrimSketch::polyline_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_polyline", "graph", "info", "out_wire"), &OcctlPrimSketch::make_polyline, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("regular_polygon_info_init", "info"), &OcctlPrimSketch::regular_polygon_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_regular_polygon", "graph", "info", "out_wire"), &OcctlPrimSketch::make_regular_polygon, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("rectangle_info_init", "info"), &OcctlPrimSketch::rectangle_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_rectangle", "graph", "info", "out_wire"), &OcctlPrimSketch::make_rectangle, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("circle_info_init", "info"), &OcctlPrimSketch::circle_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_circle", "graph", "info", "out_wire"), &OcctlPrimSketch::make_circle, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("ellipse_info_init", "info"), &OcctlPrimSketch::ellipse_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_ellipse", "graph", "info", "out_wire"), &OcctlPrimSketch::make_ellipse, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("planar_face_info_init", "info"), &OcctlPrimSketch::planar_face_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_planar_face", "graph", "info", "out_face"), &OcctlPrimSketch::make_planar_face, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("convex_hull_2d_info_init", "info"), &OcctlPrimSketch::convex_hull_2d_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_convex_hull_2d", "graph", "info", "out_node"), &OcctlPrimSketch::make_convex_hull_2d, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("trace_info_init", "info"), &OcctlPrimSketch::trace_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_trace", "graph", "info", "out_face"), &OcctlPrimSketch::make_trace, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("constrained_edge_info_init", "info"), &OcctlPrimSketch::constrained_edge_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_constrained_edge", "graph", "info", "out_edge"), &OcctlPrimSketch::make_constrained_edge, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("arc_3pt_info_init", "info"), &OcctlPrimSketch::arc_3pt_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_arc_3pt", "graph", "info", "out_wire"), &OcctlPrimSketch::make_arc_3pt, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("arc_center_info_init", "info"), &OcctlPrimSketch::arc_center_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_arc_center", "graph", "info", "out_wire"), &OcctlPrimSketch::make_arc_center, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("spline_info_init", "info"), &OcctlPrimSketch::spline_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_spline", "graph", "info", "out_wire"), &OcctlPrimSketch::make_spline, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("plane_info_init", "info"), &OcctlPrimSketch::plane_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_plane", "graph", "info", "out_face"), &OcctlPrimSketch::make_plane, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("disk_info_init", "info"), &OcctlPrimSketch::disk_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_disk", "graph", "info", "out_face"), &OcctlPrimSketch::make_disk, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("slot_info_init", "info"), &OcctlPrimSketch::slot_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_slot", "graph", "info", "out_wire"), &OcctlPrimSketch::make_slot, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("tube_info_init", "info"), &OcctlPrimSketch::tube_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_tube", "graph", "info", "out_solid"), &OcctlPrimSketch::make_tube, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("helix_info_init", "info"), &OcctlPrimSketch::helix_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_helix", "graph", "info", "out_wire"), &OcctlPrimSketch::make_helix, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("fillet_2d_info_init", "info"), &OcctlPrimSketch::fillet_2d_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_fillet_2d", "graph", "info", "out_face"), &OcctlPrimSketch::make_fillet_2d, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("full_round_2d_info_init", "info"), &OcctlPrimSketch::full_round_2d_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_full_round_2d", "graph", "info", "out_face"), &OcctlPrimSketch::make_full_round_2d, DEFVAL(Variant()));
}

void OcctlPrimSketch::polyline_info_init(const Ref<OcctlPrimPolylineInfo>& info) { // NOLINT
    occtl_prim_polyline_info_t _info_val = {};
    ::occtl_prim_polyline_info_init(&_info_val);
    ::occtl_prim_polyline_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSketch::make_polyline(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimPolylineInfo>& info, const Ref<OcctlNodeId>& out_wire) { // NOLINT
    occtl_prim_polyline_info_t _info_c = {};
    const occtl_prim_polyline_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_wire_val = {};
    occtl_status_t _status = ::occtl_prim_make_polyline(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_wire_val);
    if (out_wire.is_valid()) out_wire->copy_from_c(_out_wire_val);
    return static_cast<int>(_status);
}

void OcctlPrimSketch::regular_polygon_info_init(const Ref<OcctlPrimRegularPolygonInfo>& info) { // NOLINT
    occtl_prim_regular_polygon_info_t _info_val = {};
    ::occtl_prim_regular_polygon_info_init(&_info_val);
    ::occtl_prim_regular_polygon_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSketch::make_regular_polygon(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimRegularPolygonInfo>& info, const Ref<OcctlNodeId>& out_wire) { // NOLINT
    occtl_prim_regular_polygon_info_t _info_c = {};
    const occtl_prim_regular_polygon_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_wire_val = {};
    occtl_status_t _status = ::occtl_prim_make_regular_polygon(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_wire_val);
    if (out_wire.is_valid()) out_wire->copy_from_c(_out_wire_val);
    return static_cast<int>(_status);
}

void OcctlPrimSketch::rectangle_info_init(const Ref<OcctlPrimRectangleInfo>& info) { // NOLINT
    occtl_prim_rectangle_info_t _info_val = {};
    ::occtl_prim_rectangle_info_init(&_info_val);
    ::occtl_prim_rectangle_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSketch::make_rectangle(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimRectangleInfo>& info, const Ref<OcctlNodeId>& out_wire) { // NOLINT
    occtl_prim_rectangle_info_t _info_c = {};
    const occtl_prim_rectangle_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_wire_val = {};
    occtl_status_t _status = ::occtl_prim_make_rectangle(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_wire_val);
    if (out_wire.is_valid()) out_wire->copy_from_c(_out_wire_val);
    return static_cast<int>(_status);
}

void OcctlPrimSketch::circle_info_init(const Ref<OcctlPrimCircleInfo>& info) { // NOLINT
    occtl_prim_circle_info_t _info_val = {};
    ::occtl_prim_circle_info_init(&_info_val);
    ::occtl_prim_circle_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSketch::make_circle(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimCircleInfo>& info, const Ref<OcctlNodeId>& out_wire) { // NOLINT
    occtl_prim_circle_info_t _info_c = {};
    const occtl_prim_circle_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_wire_val = {};
    occtl_status_t _status = ::occtl_prim_make_circle(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_wire_val);
    if (out_wire.is_valid()) out_wire->copy_from_c(_out_wire_val);
    return static_cast<int>(_status);
}

void OcctlPrimSketch::ellipse_info_init(const Ref<OcctlPrimEllipseInfo>& info) { // NOLINT
    occtl_prim_ellipse_info_t _info_val = {};
    ::occtl_prim_ellipse_info_init(&_info_val);
    ::occtl_prim_ellipse_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSketch::make_ellipse(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimEllipseInfo>& info, const Ref<OcctlNodeId>& out_wire) { // NOLINT
    occtl_prim_ellipse_info_t _info_c = {};
    const occtl_prim_ellipse_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_wire_val = {};
    occtl_status_t _status = ::occtl_prim_make_ellipse(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_wire_val);
    if (out_wire.is_valid()) out_wire->copy_from_c(_out_wire_val);
    return static_cast<int>(_status);
}

void OcctlPrimSketch::planar_face_info_init(const Ref<OcctlPrimPlanarFaceInfo>& info) { // NOLINT
    occtl_prim_planar_face_info_t _info_val = {};
    ::occtl_prim_planar_face_info_init(&_info_val);
    ::occtl_prim_planar_face_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSketch::make_planar_face(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimPlanarFaceInfo>& info, const Ref<OcctlNodeId>& out_face) { // NOLINT
    occtl_prim_planar_face_info_t _info_c = {};
    const occtl_prim_planar_face_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_face_val = {};
    occtl_status_t _status = ::occtl_prim_make_planar_face(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_face_val);
    if (out_face.is_valid()) out_face->copy_from_c(_out_face_val);
    return static_cast<int>(_status);
}

void OcctlPrimSketch::convex_hull_2d_info_init(const Ref<OcctlPrimConvexHull2dInfo>& info) { // NOLINT
    occtl_prim_convex_hull_2d_info_t _info_val = {};
    ::occtl_prim_convex_hull_2d_info_init(&_info_val);
    ::occtl_prim_convex_hull_2d_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSketch::make_convex_hull_2d(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimConvexHull2dInfo>& info, const Ref<OcctlNodeId>& out_node) { // NOLINT
    occtl_prim_convex_hull_2d_info_t _info_c = {};
    const occtl_prim_convex_hull_2d_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_node_val = {};
    occtl_status_t _status = ::occtl_prim_make_convex_hull_2d(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_node_val);
    if (out_node.is_valid()) out_node->copy_from_c(_out_node_val);
    return static_cast<int>(_status);
}

void OcctlPrimSketch::trace_info_init(const Ref<OcctlPrimTraceInfo>& info) { // NOLINT
    occtl_prim_trace_info_t _info_val = {};
    ::occtl_prim_trace_info_init(&_info_val);
    ::occtl_prim_trace_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSketch::make_trace(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimTraceInfo>& info, const Ref<OcctlNodeId>& out_face) { // NOLINT
    occtl_prim_trace_info_t _info_c = {};
    const occtl_prim_trace_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_face_val = {};
    occtl_status_t _status = ::occtl_prim_make_trace(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_face_val);
    if (out_face.is_valid()) out_face->copy_from_c(_out_face_val);
    return static_cast<int>(_status);
}

void OcctlPrimSketch::constrained_edge_info_init(const Ref<OcctlPrimConstrainedEdgeInfo>& info) { // NOLINT
    occtl_prim_constrained_edge_info_t _info_val = {};
    ::occtl_prim_constrained_edge_info_init(&_info_val);
    ::occtl_prim_constrained_edge_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSketch::make_constrained_edge(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimConstrainedEdgeInfo>& info, const Ref<OcctlNodeId>& out_edge) { // NOLINT
    occtl_prim_constrained_edge_info_t _info_c = {};
    const occtl_prim_constrained_edge_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_edge_val = {};
    occtl_status_t _status = ::occtl_prim_make_constrained_edge(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_edge_val);
    if (out_edge.is_valid()) out_edge->copy_from_c(_out_edge_val);
    return static_cast<int>(_status);
}

void OcctlPrimSketch::arc_3pt_info_init(const Ref<OcctlPrimArc3ptInfo>& info) { // NOLINT
    occtl_prim_arc_3pt_info_t _info_val = {};
    ::occtl_prim_arc_3pt_info_init(&_info_val);
    ::occtl_prim_arc_3pt_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSketch::make_arc_3pt(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimArc3ptInfo>& info, const Ref<OcctlNodeId>& out_wire) { // NOLINT
    occtl_prim_arc_3pt_info_t _info_c = {};
    const occtl_prim_arc_3pt_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_wire_val = {};
    occtl_status_t _status = ::occtl_prim_make_arc_3pt(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_wire_val);
    if (out_wire.is_valid()) out_wire->copy_from_c(_out_wire_val);
    return static_cast<int>(_status);
}

void OcctlPrimSketch::arc_center_info_init(const Ref<OcctlPrimArcCenterInfo>& info) { // NOLINT
    occtl_prim_arc_center_info_t _info_val = {};
    ::occtl_prim_arc_center_info_init(&_info_val);
    ::occtl_prim_arc_center_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSketch::make_arc_center(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimArcCenterInfo>& info, const Ref<OcctlNodeId>& out_wire) { // NOLINT
    occtl_prim_arc_center_info_t _info_c = {};
    const occtl_prim_arc_center_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_wire_val = {};
    occtl_status_t _status = ::occtl_prim_make_arc_center(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_wire_val);
    if (out_wire.is_valid()) out_wire->copy_from_c(_out_wire_val);
    return static_cast<int>(_status);
}

void OcctlPrimSketch::spline_info_init(const Ref<OcctlPrimSplineInfo>& info) { // NOLINT
    occtl_prim_spline_info_t _info_val = {};
    ::occtl_prim_spline_info_init(&_info_val);
    ::occtl_prim_spline_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSketch::make_spline(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimSplineInfo>& info, const Ref<OcctlNodeId>& out_wire) { // NOLINT
    occtl_prim_spline_info_t _info_c = {};
    const occtl_prim_spline_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_wire_val = {};
    occtl_status_t _status = ::occtl_prim_make_spline(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_wire_val);
    if (out_wire.is_valid()) out_wire->copy_from_c(_out_wire_val);
    return static_cast<int>(_status);
}

void OcctlPrimSketch::plane_info_init(const Ref<OcctlPrimPlaneInfo>& info) { // NOLINT
    occtl_prim_plane_info_t _info_val = {};
    ::occtl_prim_plane_info_init(&_info_val);
    ::occtl_prim_plane_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSketch::make_plane(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimPlaneInfo>& info, const Ref<OcctlNodeId>& out_face) { // NOLINT
    occtl_prim_plane_info_t _info_c = {};
    const occtl_prim_plane_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_face_val = {};
    occtl_status_t _status = ::occtl_prim_make_plane(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_face_val);
    if (out_face.is_valid()) out_face->copy_from_c(_out_face_val);
    return static_cast<int>(_status);
}

void OcctlPrimSketch::disk_info_init(const Ref<OcctlPrimDiskInfo>& info) { // NOLINT
    occtl_prim_disk_info_t _info_val = {};
    ::occtl_prim_disk_info_init(&_info_val);
    ::occtl_prim_disk_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSketch::make_disk(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimDiskInfo>& info, const Ref<OcctlNodeId>& out_face) { // NOLINT
    occtl_prim_disk_info_t _info_c = {};
    const occtl_prim_disk_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_face_val = {};
    occtl_status_t _status = ::occtl_prim_make_disk(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_face_val);
    if (out_face.is_valid()) out_face->copy_from_c(_out_face_val);
    return static_cast<int>(_status);
}

void OcctlPrimSketch::slot_info_init(const Ref<OcctlPrimSlotInfo>& info) { // NOLINT
    occtl_prim_slot_info_t _info_val = {};
    ::occtl_prim_slot_info_init(&_info_val);
    ::occtl_prim_slot_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSketch::make_slot(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimSlotInfo>& info, const Ref<OcctlNodeId>& out_wire) { // NOLINT
    occtl_prim_slot_info_t _info_c = {};
    const occtl_prim_slot_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_wire_val = {};
    occtl_status_t _status = ::occtl_prim_make_slot(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_wire_val);
    if (out_wire.is_valid()) out_wire->copy_from_c(_out_wire_val);
    return static_cast<int>(_status);
}

void OcctlPrimSketch::tube_info_init(const Ref<OcctlPrimTubeInfo>& info) { // NOLINT
    occtl_prim_tube_info_t _info_val = {};
    ::occtl_prim_tube_info_init(&_info_val);
    ::occtl_prim_tube_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSketch::make_tube(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimTubeInfo>& info, const Ref<OcctlNodeId>& out_solid) { // NOLINT
    occtl_prim_tube_info_t _info_c = {};
    const occtl_prim_tube_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_solid_val = {};
    occtl_status_t _status = ::occtl_prim_make_tube(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_solid_val);
    if (out_solid.is_valid()) out_solid->copy_from_c(_out_solid_val);
    return static_cast<int>(_status);
}

void OcctlPrimSketch::helix_info_init(const Ref<OcctlPrimHelixInfo>& info) { // NOLINT
    occtl_prim_helix_info_t _info_val = {};
    ::occtl_prim_helix_info_init(&_info_val);
    ::occtl_prim_helix_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSketch::make_helix(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimHelixInfo>& info, const Ref<OcctlNodeId>& out_wire) { // NOLINT
    occtl_prim_helix_info_t _info_c = {};
    const occtl_prim_helix_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_wire_val = {};
    occtl_status_t _status = ::occtl_prim_make_helix(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_wire_val);
    if (out_wire.is_valid()) out_wire->copy_from_c(_out_wire_val);
    return static_cast<int>(_status);
}

void OcctlPrimSketch::fillet_2d_info_init(const Ref<OcctlPrimFillet2dInfo>& info) { // NOLINT
    occtl_prim_fillet_2d_info_t _info_val = {};
    ::occtl_prim_fillet_2d_info_init(&_info_val);
    ::occtl_prim_fillet_2d_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSketch::make_fillet_2d(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimFillet2dInfo>& info, const Ref<OcctlNodeId>& out_face) { // NOLINT
    occtl_prim_fillet_2d_info_t _info_c = {};
    const occtl_prim_fillet_2d_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_face_val = {};
    occtl_status_t _status = ::occtl_prim_make_fillet_2d(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_face_val);
    if (out_face.is_valid()) out_face->copy_from_c(_out_face_val);
    return static_cast<int>(_status);
}

void OcctlPrimSketch::full_round_2d_info_init(const Ref<OcctlPrimFullRound2dInfo>& info) { // NOLINT
    occtl_prim_full_round_2d_info_t _info_val = {};
    ::occtl_prim_full_round_2d_info_init(&_info_val);
    ::occtl_prim_full_round_2d_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSketch::make_full_round_2d(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimFullRound2dInfo>& info, const Ref<OcctlNodeId>& out_face) { // NOLINT
    occtl_prim_full_round_2d_info_t _info_c = {};
    const occtl_prim_full_round_2d_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_face_val = {};
    occtl_status_t _status = ::occtl_prim_make_full_round_2d(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_face_val);
    if (out_face.is_valid()) out_face->copy_from_c(_out_face_val);
    return static_cast<int>(_status);
}
