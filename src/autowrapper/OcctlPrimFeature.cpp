#include "OcctlPrimFeature.h"

#include "occtl/occtl_prim_feature.h"

void OcctlPrimFeature::_bind_methods() {
    BIND_CONSTANT(OCCTL_PRIM_FACE_FROM_SURFACE_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_FACE_FROM_POINT_GRID_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_FACE_FROM_BOUNDARY_CURVES_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_FACE_FROM_CURVE_GRID_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_BRAKE_FORMED_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_DRAFT_PRISM_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_EXTRUDE_TAPERED_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_RULED_SURFACE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_FEAT_PRISM_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_EXTRUDE_UNTIL_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_FEAT_DRAFT_PRISM_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_CYLINDRICAL_HOLE_INFO_VERSION_1);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_brake_side_t", "OCCTL_PRIM_BRAKE_SIDE_LEFT", OCCTL_PRIM_BRAKE_SIDE_LEFT);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_brake_side_t", "OCCTL_PRIM_BRAKE_SIDE_RIGHT", OCCTL_PRIM_BRAKE_SIDE_RIGHT);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_brake_side_t", "OCCTL_PRIM_BRAKE_SIDE_RESERVED_FUTURE", OCCTL_PRIM_BRAKE_SIDE_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_until_kind_t", "OCCTL_UNTIL_LENGTH", OCCTL_UNTIL_LENGTH);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_until_kind_t", "OCCTL_UNTIL_SHAPE", OCCTL_UNTIL_SHAPE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_until_kind_t", "OCCTL_UNTIL_THRU_ALL", OCCTL_UNTIL_THRU_ALL);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_until_kind_t", "OCCTL_UNTIL_HEIGHT", OCCTL_UNTIL_HEIGHT);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_until_kind_t", "OCCTL_UNTIL_RESERVED_FUTURE", OCCTL_UNTIL_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_feat_combine_t", "OCCTL_FEAT_SEPARATE", OCCTL_FEAT_SEPARATE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_feat_combine_t", "OCCTL_FEAT_CUT", OCCTL_FEAT_CUT);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_feat_combine_t", "OCCTL_FEAT_FUSE", OCCTL_FEAT_FUSE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_feat_combine_t", "OCCTL_FEAT_COMBINE_RESERVED_FUTURE", OCCTL_FEAT_COMBINE_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_extrude_until_side_t", "OCCTL_EXTRUDE_UNTIL_NEXT", OCCTL_EXTRUDE_UNTIL_NEXT);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_extrude_until_side_t", "OCCTL_EXTRUDE_UNTIL_LAST", OCCTL_EXTRUDE_UNTIL_LAST);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_extrude_until_side_t", "OCCTL_EXTRUDE_UNTIL_PREVIOUS", OCCTL_EXTRUDE_UNTIL_PREVIOUS);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_extrude_until_side_t", "OCCTL_EXTRUDE_UNTIL_FIRST", OCCTL_EXTRUDE_UNTIL_FIRST);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_extrude_until_side_t", "OCCTL_EXTRUDE_UNTIL_RESERVED_FUTURE", OCCTL_EXTRUDE_UNTIL_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_cylindrical_hole_kind_t", "OCCTL_CYLINDRICAL_HOLE_THROUGH_ALL", OCCTL_CYLINDRICAL_HOLE_THROUGH_ALL);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_cylindrical_hole_kind_t", "OCCTL_CYLINDRICAL_HOLE_BETWEEN_PARAMS", OCCTL_CYLINDRICAL_HOLE_BETWEEN_PARAMS);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_cylindrical_hole_kind_t", "OCCTL_CYLINDRICAL_HOLE_THRU_NEXT", OCCTL_CYLINDRICAL_HOLE_THRU_NEXT);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_cylindrical_hole_kind_t", "OCCTL_CYLINDRICAL_HOLE_UNTIL_END", OCCTL_CYLINDRICAL_HOLE_UNTIL_END);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_cylindrical_hole_kind_t", "OCCTL_CYLINDRICAL_HOLE_BLIND", OCCTL_CYLINDRICAL_HOLE_BLIND);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_cylindrical_hole_kind_t", "OCCTL_CYLINDRICAL_HOLE_RESERVED_FUTURE", OCCTL_CYLINDRICAL_HOLE_RESERVED_FUTURE);
    godot::ClassDB::bind_method(godot::D_METHOD("face_from_surface_options_init", "options"), &OcctlPrimFeature::face_from_surface_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_face_from_surface", "graph", "options", "out_face"), &OcctlPrimFeature::make_face_from_surface, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("face_from_point_grid_options_init", "options"), &OcctlPrimFeature::face_from_point_grid_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_face_from_point_grid", "graph", "options", "out_face"), &OcctlPrimFeature::make_face_from_point_grid, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("face_from_boundary_curves_options_init", "options"), &OcctlPrimFeature::face_from_boundary_curves_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_face_from_boundary_curves", "graph", "options", "out_face"), &OcctlPrimFeature::make_face_from_boundary_curves, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("face_from_curve_grid_options_init", "options"), &OcctlPrimFeature::face_from_curve_grid_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_face_from_curve_grid", "graph", "options", "out_face"), &OcctlPrimFeature::make_face_from_curve_grid, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("brake_formed_options_init", "opts"), &OcctlPrimFeature::brake_formed_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_brake_formed", "graph", "options", "out_root"), &OcctlPrimFeature::make_brake_formed, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("draft_prism_info_init", "info"), &OcctlPrimFeature::draft_prism_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_draft_prism", "graph", "info", "out_shape"), &OcctlPrimFeature::make_draft_prism, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("extrude_tapered_info_init", "info"), &OcctlPrimFeature::extrude_tapered_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_extrude_tapered", "graph", "info", "out_shape"), &OcctlPrimFeature::make_extrude_tapered, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("ruled_surface_info_init", "info"), &OcctlPrimFeature::ruled_surface_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_ruled_surface", "graph", "info", "out_shape"), &OcctlPrimFeature::make_ruled_surface, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("feat_prism_info_init", "info"), &OcctlPrimFeature::feat_prism_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_feat_prism", "graph", "info", "out_shape"), &OcctlPrimFeature::make_feat_prism, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("extrude_until_info_init", "info"), &OcctlPrimFeature::extrude_until_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_extrude_until", "graph", "info", "out_shape"), &OcctlPrimFeature::make_extrude_until, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("feat_draft_prism_info_init", "info"), &OcctlPrimFeature::feat_draft_prism_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_feat_draft_prism", "graph", "info", "out_shape"), &OcctlPrimFeature::make_feat_draft_prism, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("cylindrical_hole_info_init", "info"), &OcctlPrimFeature::cylindrical_hole_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_cylindrical_hole", "graph", "info", "out_shape"), &OcctlPrimFeature::make_cylindrical_hole, DEFVAL(Variant()));
}

void OcctlPrimFeature::face_from_surface_options_init(const Ref<OcctlPrimFaceFromSurfaceOptions>& options) { // NOLINT
    occtl_prim_face_from_surface_options_t _options_val = {};
    ::occtl_prim_face_from_surface_options_init(&_options_val);
    ::occtl_prim_face_from_surface_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

int OcctlPrimFeature::make_face_from_surface(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimFaceFromSurfaceOptions>& options, const Ref<OcctlNodeId>& out_face) { // NOLINT
    occtl_prim_face_from_surface_options_t _options_c = {};
    const occtl_prim_face_from_surface_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_node_id_t _out_face_val = {};
    occtl_status_t _status = ::occtl_prim_make_face_from_surface(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_face_val);
    if (out_face.is_valid()) out_face->copy_from_c(_out_face_val);
    return static_cast<int>(_status);
}

void OcctlPrimFeature::face_from_point_grid_options_init(const Ref<OcctlPrimFaceFromPointGridOptions>& options) { // NOLINT
    occtl_prim_face_from_point_grid_options_t _options_val = {};
    ::occtl_prim_face_from_point_grid_options_init(&_options_val);
    ::occtl_prim_face_from_point_grid_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

int OcctlPrimFeature::make_face_from_point_grid(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimFaceFromPointGridOptions>& options, const Ref<OcctlNodeId>& out_face) { // NOLINT
    occtl_prim_face_from_point_grid_options_t _options_c = {};
    const occtl_prim_face_from_point_grid_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_node_id_t _out_face_val = {};
    occtl_status_t _status = ::occtl_prim_make_face_from_point_grid(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_face_val);
    if (out_face.is_valid()) out_face->copy_from_c(_out_face_val);
    return static_cast<int>(_status);
}

void OcctlPrimFeature::face_from_boundary_curves_options_init(const Ref<OcctlPrimFaceFromBoundaryCurvesOptions>& options) { // NOLINT
    occtl_prim_face_from_boundary_curves_options_t _options_val = {};
    ::occtl_prim_face_from_boundary_curves_options_init(&_options_val);
    ::occtl_prim_face_from_boundary_curves_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

int OcctlPrimFeature::make_face_from_boundary_curves(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimFaceFromBoundaryCurvesOptions>& options, const Ref<OcctlNodeId>& out_face) { // NOLINT
    occtl_prim_face_from_boundary_curves_options_t _options_c = {};
    const occtl_prim_face_from_boundary_curves_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_node_id_t _out_face_val = {};
    occtl_status_t _status = ::occtl_prim_make_face_from_boundary_curves(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_face_val);
    if (out_face.is_valid()) out_face->copy_from_c(_out_face_val);
    return static_cast<int>(_status);
}

void OcctlPrimFeature::face_from_curve_grid_options_init(const Ref<OcctlPrimFaceFromCurveGridOptions>& options) { // NOLINT
    occtl_prim_face_from_curve_grid_options_t _options_val = {};
    ::occtl_prim_face_from_curve_grid_options_init(&_options_val);
    ::occtl_prim_face_from_curve_grid_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

int OcctlPrimFeature::make_face_from_curve_grid(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimFaceFromCurveGridOptions>& options, const Ref<OcctlNodeId>& out_face) { // NOLINT
    occtl_prim_face_from_curve_grid_options_t _options_c = {};
    const occtl_prim_face_from_curve_grid_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_node_id_t _out_face_val = {};
    occtl_status_t _status = ::occtl_prim_make_face_from_curve_grid(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_face_val);
    if (out_face.is_valid()) out_face->copy_from_c(_out_face_val);
    return static_cast<int>(_status);
}

void OcctlPrimFeature::brake_formed_options_init(const Ref<OcctlPrimBrakeFormedOptions>& opts) { // NOLINT
    occtl_prim_brake_formed_options_t _opts_val = {};
    ::occtl_prim_brake_formed_options_init(&_opts_val);
    ::occtl_prim_brake_formed_options_init(&_opts_val);
    if (opts.is_valid()) opts->copy_from_c(_opts_val);
}

Ref<OcctlGraphHandle> OcctlPrimFeature::make_brake_formed(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimBrakeFormedOptions>& options, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_prim_brake_formed_options_t _options_c = {};
    const occtl_prim_brake_formed_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_prim_make_brake_formed(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_graph_val, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

void OcctlPrimFeature::draft_prism_info_init(const Ref<OcctlPrimDraftPrismInfo>& info) { // NOLINT
    occtl_prim_draft_prism_info_t _info_val = {};
    ::occtl_prim_draft_prism_info_init(&_info_val);
    ::occtl_prim_draft_prism_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimFeature::make_draft_prism(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimDraftPrismInfo>& info, const Ref<OcctlNodeId>& out_shape) { // NOLINT
    occtl_prim_draft_prism_info_t _info_c = {};
    const occtl_prim_draft_prism_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_shape_val = {};
    occtl_status_t _status = ::occtl_prim_make_draft_prism(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_shape_val);
    if (out_shape.is_valid()) out_shape->copy_from_c(_out_shape_val);
    return static_cast<int>(_status);
}

void OcctlPrimFeature::extrude_tapered_info_init(const Ref<OcctlPrimExtrudeTaperedInfo>& info) { // NOLINT
    occtl_prim_extrude_tapered_info_t _info_val = {};
    ::occtl_prim_extrude_tapered_info_init(&_info_val);
    ::occtl_prim_extrude_tapered_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimFeature::make_extrude_tapered(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimExtrudeTaperedInfo>& info, const Ref<OcctlNodeId>& out_shape) { // NOLINT
    occtl_prim_extrude_tapered_info_t _info_c = {};
    const occtl_prim_extrude_tapered_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_shape_val = {};
    occtl_status_t _status = ::occtl_prim_make_extrude_tapered(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_shape_val);
    if (out_shape.is_valid()) out_shape->copy_from_c(_out_shape_val);
    return static_cast<int>(_status);
}

void OcctlPrimFeature::ruled_surface_info_init(const Ref<OcctlPrimRuledSurfaceInfo>& info) { // NOLINT
    occtl_prim_ruled_surface_info_t _info_val = {};
    ::occtl_prim_ruled_surface_info_init(&_info_val);
    ::occtl_prim_ruled_surface_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimFeature::make_ruled_surface(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimRuledSurfaceInfo>& info, const Ref<OcctlNodeId>& out_shape) { // NOLINT
    occtl_prim_ruled_surface_info_t _info_c = {};
    const occtl_prim_ruled_surface_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_shape_val = {};
    occtl_status_t _status = ::occtl_prim_make_ruled_surface(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_shape_val);
    if (out_shape.is_valid()) out_shape->copy_from_c(_out_shape_val);
    return static_cast<int>(_status);
}

void OcctlPrimFeature::feat_prism_info_init(const Ref<OcctlPrimFeatPrismInfo>& info) { // NOLINT
    occtl_prim_feat_prism_info_t _info_val = {};
    ::occtl_prim_feat_prism_info_init(&_info_val);
    ::occtl_prim_feat_prism_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimFeature::make_feat_prism(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimFeatPrismInfo>& info, const Ref<OcctlNodeId>& out_shape) { // NOLINT
    occtl_prim_feat_prism_info_t _info_c = {};
    const occtl_prim_feat_prism_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_shape_val = {};
    occtl_status_t _status = ::occtl_prim_make_feat_prism(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_shape_val);
    if (out_shape.is_valid()) out_shape->copy_from_c(_out_shape_val);
    return static_cast<int>(_status);
}

void OcctlPrimFeature::extrude_until_info_init(const Ref<OcctlPrimExtrudeUntilInfo>& info) { // NOLINT
    occtl_prim_extrude_until_info_t _info_val = {};
    ::occtl_prim_extrude_until_info_init(&_info_val);
    ::occtl_prim_extrude_until_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimFeature::make_extrude_until(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimExtrudeUntilInfo>& info, const Ref<OcctlNodeId>& out_shape) { // NOLINT
    occtl_prim_extrude_until_info_t _info_c = {};
    const occtl_prim_extrude_until_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_shape_val = {};
    occtl_status_t _status = ::occtl_prim_make_extrude_until(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_shape_val);
    if (out_shape.is_valid()) out_shape->copy_from_c(_out_shape_val);
    return static_cast<int>(_status);
}

void OcctlPrimFeature::feat_draft_prism_info_init(const Ref<OcctlPrimFeatDraftPrismInfo>& info) { // NOLINT
    occtl_prim_feat_draft_prism_info_t _info_val = {};
    ::occtl_prim_feat_draft_prism_info_init(&_info_val);
    ::occtl_prim_feat_draft_prism_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimFeature::make_feat_draft_prism(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimFeatDraftPrismInfo>& info, const Ref<OcctlNodeId>& out_shape) { // NOLINT
    occtl_prim_feat_draft_prism_info_t _info_c = {};
    const occtl_prim_feat_draft_prism_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_shape_val = {};
    occtl_status_t _status = ::occtl_prim_make_feat_draft_prism(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_shape_val);
    if (out_shape.is_valid()) out_shape->copy_from_c(_out_shape_val);
    return static_cast<int>(_status);
}

void OcctlPrimFeature::cylindrical_hole_info_init(const Ref<OcctlPrimCylindricalHoleInfo>& info) { // NOLINT
    occtl_prim_cylindrical_hole_info_t _info_val = {};
    ::occtl_prim_cylindrical_hole_info_init(&_info_val);
    ::occtl_prim_cylindrical_hole_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimFeature::make_cylindrical_hole(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimCylindricalHoleInfo>& info, const Ref<OcctlNodeId>& out_shape) { // NOLINT
    occtl_prim_cylindrical_hole_info_t _info_c = {};
    const occtl_prim_cylindrical_hole_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_shape_val = {};
    occtl_status_t _status = ::occtl_prim_make_cylindrical_hole(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_shape_val);
    if (out_shape.is_valid()) out_shape->copy_from_c(_out_shape_val);
    return static_cast<int>(_status);
}
