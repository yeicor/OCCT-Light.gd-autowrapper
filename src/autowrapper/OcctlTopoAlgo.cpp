#include "OcctlTopoAlgo.h"

#include "occtl/occtl_topo_algo.h"

#include <vector>

void OcctlTopoAlgo::_bind_methods() {
    BIND_CONSTANT(OCCTL_TOPO_SEW_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_SEW_RESULT_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_SAME_PARAMETER_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_FILLET_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_EDGE_BLEND_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_MAX_FILLET_RADIUS_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_PROJECT_ON_FACE_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_WRAP_ON_FACE_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_PROJECT_FACE_DIRECTION_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_FACE_TO_ARCS_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_HLR_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_HLR_RESULT_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_DRAFT_FACES_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_DEFEATURE_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_OFFSET_FEATURES_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_FILLING_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_FILLING_PATCH_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_SPLIT_BY_PLANE_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_SECTION_BY_PLANES_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_EXTRUDE_FACES_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_LINEAR_PATTERN_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_CIRCULAR_PATTERN_OPTIONS_VERSION_1);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_check_severity_t", "OCCTL_TOPO_CHECK_WARNING", OCCTL_TOPO_CHECK_WARNING);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_check_severity_t", "OCCTL_TOPO_CHECK_ERROR", OCCTL_TOPO_CHECK_ERROR);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_check_severity_t", "OCCTL_TOPO_CHECK_FATAL", OCCTL_TOPO_CHECK_FATAL);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_check_severity_t", "OCCTL_TOPO_CHECK_SEVERITY_RESERVED_FUTURE", OCCTL_TOPO_CHECK_SEVERITY_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_hlr_mode_t", "OCCTL_TOPO_HLR_BREP", OCCTL_TOPO_HLR_BREP);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_hlr_mode_t", "OCCTL_TOPO_HLR_POLY", OCCTL_TOPO_HLR_POLY);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_hlr_mode_t", "OCCTL_TOPO_HLR_MODE_RESERVED_FUTURE", OCCTL_TOPO_HLR_MODE_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_filling_continuity_t", "OCCTL_TOPO_FILLING_C0", OCCTL_TOPO_FILLING_C0);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_filling_continuity_t", "OCCTL_TOPO_FILLING_G1", OCCTL_TOPO_FILLING_G1);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_filling_continuity_t", "OCCTL_TOPO_FILLING_G2", OCCTL_TOPO_FILLING_G2);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_filling_continuity_t", "OCCTL_TOPO_FILLING_CONTINUITY_RESERVED_FUTURE", OCCTL_TOPO_FILLING_CONTINUITY_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_split_keep_t", "OCCTL_TOPO_SPLIT_KEEP_ALL", OCCTL_TOPO_SPLIT_KEEP_ALL);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_split_keep_t", "OCCTL_TOPO_SPLIT_KEEP_POSITIVE", OCCTL_TOPO_SPLIT_KEEP_POSITIVE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_split_keep_t", "OCCTL_TOPO_SPLIT_KEEP_NEGATIVE", OCCTL_TOPO_SPLIT_KEEP_NEGATIVE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_split_keep_t", "OCCTL_TOPO_SPLIT_KEEP_RESERVED_FUTURE", OCCTL_TOPO_SPLIT_KEEP_RESERVED_FUTURE);
    godot::ClassDB::bind_method(godot::D_METHOD("sew_options_init", "options"), &OcctlTopoAlgo::sew_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("sew_result_init", "result"), &OcctlTopoAlgo::sew_result_init);
    godot::ClassDB::bind_method(godot::D_METHOD("sew", "graph", "options", "out_result"), &OcctlTopoAlgo::sew, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("same_parameter_options_init", "options"), &OcctlTopoAlgo::same_parameter_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("recompute_same_parameter", "graph", "options", "out_c0_fallback_count", "out_approx_fallback_count"), &OcctlTopoAlgo::recompute_same_parameter, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("check", "graph"), &OcctlTopoAlgo::check);
    godot::ClassDB::bind_method(godot::D_METHOD("fillet_options_init", "opts"), &OcctlTopoAlgo::fillet_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("fillet", "graph", "opts", "out_root"), &OcctlTopoAlgo::fillet, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("edge_blend_options_init", "opts"), &OcctlTopoAlgo::edge_blend_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("blend_edges", "graph", "options", "out_root"), &OcctlTopoAlgo::blend_edges, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("max_fillet_radius_options_init", "opts"), &OcctlTopoAlgo::max_fillet_radius_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("max_fillet_radius", "graph", "options", "out_radius"), &OcctlTopoAlgo::max_fillet_radius, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("transformed", "graph", "root", "transform", "out_root"), &OcctlTopoAlgo::transformed);
    godot::ClassDB::bind_method(godot::D_METHOD("project_on_face_options_init", "opts"), &OcctlTopoAlgo::project_on_face_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("project_on_face", "graph", "options", "out_root"), &OcctlTopoAlgo::project_on_face, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("wrap_on_face_options_init", "opts"), &OcctlTopoAlgo::wrap_on_face_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("wrap_on_face", "graph", "options", "out_root"), &OcctlTopoAlgo::wrap_on_face, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("project_face_direction_options_init", "opts"), &OcctlTopoAlgo::project_face_direction_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("project_face_along_direction", "graph", "options", "out_root"), &OcctlTopoAlgo::project_face_along_direction, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("face_to_arcs_options_init", "opts"), &OcctlTopoAlgo::face_to_arcs_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("face_to_arcs", "graph", "options", "out_root"), &OcctlTopoAlgo::face_to_arcs, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("hlr_result_init", "result"), &OcctlTopoAlgo::hlr_result_init);
    godot::ClassDB::bind_method(godot::D_METHOD("hlr_options_init", "options"), &OcctlTopoAlgo::hlr_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_hlr_projection", "graph", "options", "out_result"), &OcctlTopoAlgo::make_hlr_projection, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("draft_faces_options_init", "opts"), &OcctlTopoAlgo::draft_faces_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("draft_faces", "graph", "options", "out_root"), &OcctlTopoAlgo::draft_faces, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("defeature_options_init", "opts"), &OcctlTopoAlgo::defeature_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("defeature", "graph", "options", "out_root"), &OcctlTopoAlgo::defeature, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("offset_features_options_init", "opts"), &OcctlTopoAlgo::offset_features_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_offset_features", "graph", "options", "out_root"), &OcctlTopoAlgo::make_offset_features, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("filling_options_init", "opts"), &OcctlTopoAlgo::filling_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_filling", "graph", "options", "out_root"), &OcctlTopoAlgo::make_filling, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("filling_patch_options_init", "opts"), &OcctlTopoAlgo::filling_patch_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_filling_patch", "graph", "options", "out_root"), &OcctlTopoAlgo::make_filling_patch, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("split_by_plane_options_init", "opts"), &OcctlTopoAlgo::split_by_plane_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_split_by_plane", "graph", "options", "out_root"), &OcctlTopoAlgo::make_split_by_plane, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("section_by_planes_options_init", "opts"), &OcctlTopoAlgo::section_by_planes_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_sections_by_planes", "graph", "options", "out_root"), &OcctlTopoAlgo::make_sections_by_planes, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("extrude_faces_options_init", "opts"), &OcctlTopoAlgo::extrude_faces_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_face_extrusion", "graph", "options", "out_root"), &OcctlTopoAlgo::make_face_extrusion, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("mirrored", "graph", "root", "point", "normal", "out_root"), &OcctlTopoAlgo::mirrored);
    godot::ClassDB::bind_method(godot::D_METHOD("linear_pattern_options_init", "opts"), &OcctlTopoAlgo::linear_pattern_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_linear_pattern", "graph", "root", "opts", "out_root"), &OcctlTopoAlgo::make_linear_pattern, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("circular_pattern_options_init", "opts"), &OcctlTopoAlgo::circular_pattern_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_circular_pattern", "graph", "root", "opts", "out_root"), &OcctlTopoAlgo::make_circular_pattern, DEFVAL(Variant()));
}

void OcctlTopoAlgo::sew_options_init(const Ref<OcctlTopoSewOptions>& options) { // NOLINT
    occtl_topo_sew_options_t _options_val = {};
    ::occtl_topo_sew_options_init(&_options_val);
    ::occtl_topo_sew_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

void OcctlTopoAlgo::sew_result_init(const Ref<OcctlTopoSewResult>& result) { // NOLINT
    occtl_topo_sew_result_t _result_val = {};
    ::occtl_topo_sew_result_init(&_result_val);
    ::occtl_topo_sew_result_init(&_result_val);
    if (result.is_valid()) result->copy_from_c(_result_val);
}

int OcctlTopoAlgo::sew(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoSewOptions>& options, const Ref<OcctlTopoSewResult>& out_result) { // NOLINT
    occtl_topo_sew_options_t _options_c = {};
    const occtl_topo_sew_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_topo_sew_result_t _out_result_val = {};
    ::occtl_topo_sew_result_init(&_out_result_val);
    occtl_status_t _status = ::occtl_topo_sew(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_result_val);
    if (out_result.is_valid()) out_result->copy_from_c(_out_result_val);
    return static_cast<int>(_status);
}

void OcctlTopoAlgo::same_parameter_options_init(const Ref<OcctlTopoSameParameterOptions>& options) { // NOLINT
    occtl_topo_same_parameter_options_t _options_val = {};
    ::occtl_topo_same_parameter_options_init(&_options_val);
    ::occtl_topo_same_parameter_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

int OcctlTopoAlgo::recompute_same_parameter(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoSameParameterOptions>& options, const Ref<OcctlUint32>& out_c0_fallback_count, const Ref<OcctlUint32>& out_approx_fallback_count) { // NOLINT
    occtl_topo_same_parameter_options_t _options_c = {};
    const occtl_topo_same_parameter_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    uint32_t _out_c0_fallback_count_val = {};
    uint32_t _out_approx_fallback_count_val = {};
    occtl_status_t _status = ::occtl_topo_recompute_same_parameter(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_c0_fallback_count_val, &_out_approx_fallback_count_val);
    if (out_c0_fallback_count.is_valid()) out_c0_fallback_count->copy_from_c(_out_c0_fallback_count_val);
    if (out_approx_fallback_count.is_valid()) out_approx_fallback_count->copy_from_c(_out_approx_fallback_count_val);
    return static_cast<int>(_status);
}

Array OcctlTopoAlgo::check(const Ref<OcctlGraphHandle>& graph) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_topo_check(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return Array(); }
    std::vector<occtl_topo_check_issue_t> _out_issues_buf(static_cast<size_t>(_out_count_cnt));
    _err = ::occtl_topo_check(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _out_issues_buf.data(), _out_count_cnt, &_out_count_cnt);
    Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) {
        Ref<OcctlTopoCheckIssue> _item;
        _item.instantiate();
        _item->copy_from_c(_out_issues_buf[_i]);
        _result[static_cast<int64_t>(_i)] = _item;
    }
    return _result;
}

void OcctlTopoAlgo::fillet_options_init(const Ref<OcctlTopoFilletOptions>& opts) { // NOLINT
    occtl_topo_fillet_options_t _opts_val = {};
    ::occtl_topo_fillet_options_init(&_opts_val);
    ::occtl_topo_fillet_options_init(&_opts_val);
    if (opts.is_valid()) opts->copy_from_c(_opts_val);
}

Ref<OcctlGraphHandle> OcctlTopoAlgo::fillet(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoFilletOptions>& opts, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_topo_fillet_options_t _opts_c = {};
    const occtl_topo_fillet_options_t* _opts_ptr = nullptr;
    if (opts.is_valid()) { _opts_c = opts->to_c(); _opts_ptr = &_opts_c; }
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_topo_fillet(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _opts_ptr, &_out_graph_val, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

void OcctlTopoAlgo::edge_blend_options_init(const Ref<OcctlTopoEdgeBlendOptions>& opts) { // NOLINT
    occtl_topo_edge_blend_options_t _opts_val = {};
    ::occtl_topo_edge_blend_options_init(&_opts_val);
    ::occtl_topo_edge_blend_options_init(&_opts_val);
    if (opts.is_valid()) opts->copy_from_c(_opts_val);
}

Ref<OcctlGraphHandle> OcctlTopoAlgo::blend_edges(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoEdgeBlendOptions>& options, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_topo_edge_blend_options_t _options_c = {};
    const occtl_topo_edge_blend_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_topo_blend_edges(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_graph_val, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

void OcctlTopoAlgo::max_fillet_radius_options_init(const Ref<OcctlTopoMaxFilletRadiusOptions>& opts) { // NOLINT
    occtl_topo_max_fillet_radius_options_t _opts_val = {};
    ::occtl_topo_max_fillet_radius_options_init(&_opts_val);
    ::occtl_topo_max_fillet_radius_options_init(&_opts_val);
    if (opts.is_valid()) opts->copy_from_c(_opts_val);
}

int OcctlTopoAlgo::max_fillet_radius(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoMaxFilletRadiusOptions>& options, const Ref<OcctlDouble>& out_radius) { // NOLINT
    occtl_topo_max_fillet_radius_options_t _options_c = {};
    const occtl_topo_max_fillet_radius_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    double _out_radius_val = {};
    occtl_status_t _status = ::occtl_topo_max_fillet_radius(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_radius_val);
    if (out_radius.is_valid()) out_radius->copy_from_c(_out_radius_val);
    return static_cast<int>(_status);
}

Ref<OcctlGraphHandle> OcctlTopoAlgo::transformed(const Ref<OcctlGraphHandle>& graph, int64_t root, const Ref<OcctlTransform>& transform, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_topo_transformed(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(root)}, transform->to_c(), &_out_graph_val, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

void OcctlTopoAlgo::project_on_face_options_init(const Ref<OcctlTopoProjectOnFaceOptions>& opts) { // NOLINT
    occtl_topo_project_on_face_options_t _opts_val = {};
    ::occtl_topo_project_on_face_options_init(&_opts_val);
    ::occtl_topo_project_on_face_options_init(&_opts_val);
    if (opts.is_valid()) opts->copy_from_c(_opts_val);
}

Ref<OcctlGraphHandle> OcctlTopoAlgo::project_on_face(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoProjectOnFaceOptions>& options, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_topo_project_on_face_options_t _options_c = {};
    const occtl_topo_project_on_face_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_topo_project_on_face(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_graph_val, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

void OcctlTopoAlgo::wrap_on_face_options_init(const Ref<OcctlTopoWrapOnFaceOptions>& opts) { // NOLINT
    occtl_topo_wrap_on_face_options_t _opts_val = {};
    ::occtl_topo_wrap_on_face_options_init(&_opts_val);
    ::occtl_topo_wrap_on_face_options_init(&_opts_val);
    if (opts.is_valid()) opts->copy_from_c(_opts_val);
}

Ref<OcctlGraphHandle> OcctlTopoAlgo::wrap_on_face(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoWrapOnFaceOptions>& options, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_topo_wrap_on_face_options_t _options_c = {};
    const occtl_topo_wrap_on_face_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_topo_wrap_on_face(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_graph_val, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

void OcctlTopoAlgo::project_face_direction_options_init(const Ref<OcctlTopoProjectFaceDirectionOptions>& opts) { // NOLINT
    occtl_topo_project_face_direction_options_t _opts_val = {};
    ::occtl_topo_project_face_direction_options_init(&_opts_val);
    ::occtl_topo_project_face_direction_options_init(&_opts_val);
    if (opts.is_valid()) opts->copy_from_c(_opts_val);
}

Ref<OcctlGraphHandle> OcctlTopoAlgo::project_face_along_direction(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoProjectFaceDirectionOptions>& options, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_topo_project_face_direction_options_t _options_c = {};
    const occtl_topo_project_face_direction_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_topo_project_face_along_direction(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_graph_val, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

void OcctlTopoAlgo::face_to_arcs_options_init(const Ref<OcctlTopoFaceToArcsOptions>& opts) { // NOLINT
    occtl_topo_face_to_arcs_options_t _opts_val = {};
    ::occtl_topo_face_to_arcs_options_init(&_opts_val);
    ::occtl_topo_face_to_arcs_options_init(&_opts_val);
    if (opts.is_valid()) opts->copy_from_c(_opts_val);
}

Ref<OcctlGraphHandle> OcctlTopoAlgo::face_to_arcs(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoFaceToArcsOptions>& options, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_topo_face_to_arcs_options_t _options_c = {};
    const occtl_topo_face_to_arcs_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_topo_face_to_arcs(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_graph_val, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

void OcctlTopoAlgo::hlr_result_init(const Ref<OcctlTopoHlrResult>& result) { // NOLINT
    occtl_topo_hlr_result_t _result_val = {};
    ::occtl_topo_hlr_result_init(&_result_val);
    ::occtl_topo_hlr_result_init(&_result_val);
    if (result.is_valid()) result->copy_from_c(_result_val);
}

void OcctlTopoAlgo::hlr_options_init(const Ref<OcctlTopoHlrOptions>& options) { // NOLINT
    occtl_topo_hlr_options_t _options_val = {};
    ::occtl_topo_hlr_options_init(&_options_val);
    ::occtl_topo_hlr_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

int OcctlTopoAlgo::make_hlr_projection(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoHlrOptions>& options, const Ref<OcctlTopoHlrResult>& out_result) { // NOLINT
    occtl_topo_hlr_options_t _options_c = {};
    const occtl_topo_hlr_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_topo_hlr_result_t _out_result_val = {};
    ::occtl_topo_hlr_result_init(&_out_result_val);
    occtl_status_t _status = ::occtl_topo_make_hlr_projection(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_result_val);
    if (out_result.is_valid()) out_result->copy_from_c(_out_result_val);
    return static_cast<int>(_status);
}

void OcctlTopoAlgo::draft_faces_options_init(const Ref<OcctlTopoDraftFacesOptions>& opts) { // NOLINT
    occtl_topo_draft_faces_options_t _opts_val = {};
    ::occtl_topo_draft_faces_options_init(&_opts_val);
    ::occtl_topo_draft_faces_options_init(&_opts_val);
    if (opts.is_valid()) opts->copy_from_c(_opts_val);
}

Ref<OcctlGraphHandle> OcctlTopoAlgo::draft_faces(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoDraftFacesOptions>& options, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_topo_draft_faces_options_t _options_c = {};
    const occtl_topo_draft_faces_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_topo_draft_faces(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_graph_val, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

void OcctlTopoAlgo::defeature_options_init(const Ref<OcctlTopoDefeatureOptions>& opts) { // NOLINT
    occtl_topo_defeature_options_t _opts_val = {};
    ::occtl_topo_defeature_options_init(&_opts_val);
    ::occtl_topo_defeature_options_init(&_opts_val);
    if (opts.is_valid()) opts->copy_from_c(_opts_val);
}

Ref<OcctlGraphHandle> OcctlTopoAlgo::defeature(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoDefeatureOptions>& options, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_topo_defeature_options_t _options_c = {};
    const occtl_topo_defeature_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_topo_defeature(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_graph_val, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

void OcctlTopoAlgo::offset_features_options_init(const Ref<OcctlTopoOffsetFeaturesOptions>& opts) { // NOLINT
    occtl_topo_offset_features_options_t _opts_val = {};
    ::occtl_topo_offset_features_options_init(&_opts_val);
    ::occtl_topo_offset_features_options_init(&_opts_val);
    if (opts.is_valid()) opts->copy_from_c(_opts_val);
}

Ref<OcctlGraphHandle> OcctlTopoAlgo::make_offset_features(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoOffsetFeaturesOptions>& options, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_topo_offset_features_options_t _options_c = {};
    const occtl_topo_offset_features_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_topo_make_offset_features(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_graph_val, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

void OcctlTopoAlgo::filling_options_init(const Ref<OcctlTopoFillingOptions>& opts) { // NOLINT
    occtl_topo_filling_options_t _opts_val = {};
    ::occtl_topo_filling_options_init(&_opts_val);
    ::occtl_topo_filling_options_init(&_opts_val);
    if (opts.is_valid()) opts->copy_from_c(_opts_val);
}

Ref<OcctlGraphHandle> OcctlTopoAlgo::make_filling(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoFillingOptions>& options, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_topo_filling_options_t _options_c = {};
    const occtl_topo_filling_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_topo_make_filling(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_graph_val, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

void OcctlTopoAlgo::filling_patch_options_init(const Ref<OcctlTopoFillingPatchOptions>& opts) { // NOLINT
    occtl_topo_filling_patch_options_t _opts_val = {};
    ::occtl_topo_filling_patch_options_init(&_opts_val);
    ::occtl_topo_filling_patch_options_init(&_opts_val);
    if (opts.is_valid()) opts->copy_from_c(_opts_val);
}

Ref<OcctlGraphHandle> OcctlTopoAlgo::make_filling_patch(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoFillingPatchOptions>& options, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_topo_filling_patch_options_t _options_c = {};
    const occtl_topo_filling_patch_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_topo_make_filling_patch(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_graph_val, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

void OcctlTopoAlgo::split_by_plane_options_init(const Ref<OcctlTopoSplitByPlaneOptions>& opts) { // NOLINT
    occtl_topo_split_by_plane_options_t _opts_val = {};
    ::occtl_topo_split_by_plane_options_init(&_opts_val);
    ::occtl_topo_split_by_plane_options_init(&_opts_val);
    if (opts.is_valid()) opts->copy_from_c(_opts_val);
}

Ref<OcctlGraphHandle> OcctlTopoAlgo::make_split_by_plane(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoSplitByPlaneOptions>& options, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_topo_split_by_plane_options_t _options_c = {};
    const occtl_topo_split_by_plane_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_topo_make_split_by_plane(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_graph_val, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

void OcctlTopoAlgo::section_by_planes_options_init(const Ref<OcctlTopoSectionByPlanesOptions>& opts) { // NOLINT
    occtl_topo_section_by_planes_options_t _opts_val = {};
    ::occtl_topo_section_by_planes_options_init(&_opts_val);
    ::occtl_topo_section_by_planes_options_init(&_opts_val);
    if (opts.is_valid()) opts->copy_from_c(_opts_val);
}

Ref<OcctlGraphHandle> OcctlTopoAlgo::make_sections_by_planes(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoSectionByPlanesOptions>& options, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_topo_section_by_planes_options_t _options_c = {};
    const occtl_topo_section_by_planes_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_topo_make_sections_by_planes(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_graph_val, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

void OcctlTopoAlgo::extrude_faces_options_init(const Ref<OcctlTopoExtrudeFacesOptions>& opts) { // NOLINT
    occtl_topo_extrude_faces_options_t _opts_val = {};
    ::occtl_topo_extrude_faces_options_init(&_opts_val);
    ::occtl_topo_extrude_faces_options_init(&_opts_val);
    if (opts.is_valid()) opts->copy_from_c(_opts_val);
}

Ref<OcctlGraphHandle> OcctlTopoAlgo::make_face_extrusion(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoExtrudeFacesOptions>& options, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_topo_extrude_faces_options_t _options_c = {};
    const occtl_topo_extrude_faces_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_topo_make_face_extrusion(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_graph_val, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

Ref<OcctlGraphHandle> OcctlTopoAlgo::mirrored(const Ref<OcctlGraphHandle>& graph, int64_t root, const Ref<OcctlPoint3>& point, const Ref<OcctlDirection3>& normal, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_topo_mirrored(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(root)}, point->to_c(), normal->to_c(), &_out_graph_val, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

void OcctlTopoAlgo::linear_pattern_options_init(const Ref<OcctlTopoLinearPatternOptions>& opts) { // NOLINT
    occtl_topo_linear_pattern_options_t _opts_val = {};
    ::occtl_topo_linear_pattern_options_init(&_opts_val);
    ::occtl_topo_linear_pattern_options_init(&_opts_val);
    if (opts.is_valid()) opts->copy_from_c(_opts_val);
}

Ref<OcctlGraphHandle> OcctlTopoAlgo::make_linear_pattern(const Ref<OcctlGraphHandle>& graph, int64_t root, const Ref<OcctlTopoLinearPatternOptions>& opts, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_topo_linear_pattern_options_t _opts_c = {};
    const occtl_topo_linear_pattern_options_t* _opts_ptr = nullptr;
    if (opts.is_valid()) { _opts_c = opts->to_c(); _opts_ptr = &_opts_c; }
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_topo_make_linear_pattern(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(root)}, _opts_ptr, &_out_graph_val, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

void OcctlTopoAlgo::circular_pattern_options_init(const Ref<OcctlTopoCircularPatternOptions>& opts) { // NOLINT
    occtl_topo_circular_pattern_options_t _opts_val = {};
    ::occtl_topo_circular_pattern_options_init(&_opts_val);
    ::occtl_topo_circular_pattern_options_init(&_opts_val);
    if (opts.is_valid()) opts->copy_from_c(_opts_val);
}

Ref<OcctlGraphHandle> OcctlTopoAlgo::make_circular_pattern(const Ref<OcctlGraphHandle>& graph, int64_t root, const Ref<OcctlTopoCircularPatternOptions>& opts, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_topo_circular_pattern_options_t _opts_c = {};
    const occtl_topo_circular_pattern_options_t* _opts_ptr = nullptr;
    if (opts.is_valid()) { _opts_c = opts->to_c(); _opts_ptr = &_opts_c; }
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_topo_make_circular_pattern(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(root)}, _opts_ptr, &_out_graph_val, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}
