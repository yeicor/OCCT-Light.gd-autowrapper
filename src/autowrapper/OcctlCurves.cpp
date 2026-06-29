#include "OcctlCurves.h"

#include "occtl/occtl_curves.h"

#include <vector>

void OcctlCurves::_bind_methods() {
    BIND_CONSTANT(OCCTL_CURVE_BSPLINE_CREATE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_CURVE_BEZIER_CREATE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_CURVE_OFFSET_CREATE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_CURVE_BSPLINE_VERSION_1);
    BIND_CONSTANT(OCCTL_CURVE_AIRFOIL_NACA4_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_CURVE_INTERPOLATED_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_CURVE_APPROXIMATED_INFO_VERSION_1);
    godot::ClassDB::bind_method(godot::D_METHOD("create_line", "graph", "line", "out_id"), &OcctlCurves::create_line);
    godot::ClassDB::bind_method(godot::D_METHOD("create_circle", "graph", "circle", "out_id"), &OcctlCurves::create_circle);
    godot::ClassDB::bind_method(godot::D_METHOD("create_ellipse", "graph", "ellipse", "out_id"), &OcctlCurves::create_ellipse);
    godot::ClassDB::bind_method(godot::D_METHOD("create_hyperbola", "graph", "hyperbola", "out_id"), &OcctlCurves::create_hyperbola);
    godot::ClassDB::bind_method(godot::D_METHOD("create_parabola", "graph", "parabola", "out_id"), &OcctlCurves::create_parabola);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_create_info_init", "info"), &OcctlCurves::bspline_create_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("create_bspline", "graph", "info", "out_id"), &OcctlCurves::create_bspline, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("bezier_create_info_init", "info"), &OcctlCurves::bezier_create_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("create_bezier", "graph", "info", "out_id"), &OcctlCurves::create_bezier, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("create_trimmed", "graph", "info", "out_id"), &OcctlCurves::create_trimmed, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("offset_create_info_init", "info"), &OcctlCurves::offset_create_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("create_offset", "graph", "info", "out_id"), &OcctlCurves::create_offset, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("reverse", "graph", "curve_id", "out_id"), &OcctlCurves::reverse);
    godot::ClassDB::bind_method(godot::D_METHOD("transformed", "graph", "curve_id", "transform", "out_id"), &OcctlCurves::transformed);
    godot::ClassDB::bind_method(godot::D_METHOD("translated", "graph", "curve_id", "delta", "out_id"), &OcctlCurves::translated);
    godot::ClassDB::bind_method(godot::D_METHOD("rotated", "graph", "curve_id", "axis", "angle", "out_id"), &OcctlCurves::rotated);
    godot::ClassDB::bind_method(godot::D_METHOD("scaled", "graph", "curve_id", "origin", "factor", "out_id"), &OcctlCurves::scaled);
    godot::ClassDB::bind_method(godot::D_METHOD("length", "graph", "curve_id", "out_length"), &OcctlCurves::length);
    godot::ClassDB::bind_method(godot::D_METHOD("project_point", "graph", "curve_id", "point", "out_param", "out_distance"), &OcctlCurves::project_point);
    godot::ClassDB::bind_method(godot::D_METHOD("parameter_of_point", "graph", "curve_id", "point", "out_param"), &OcctlCurves::parameter_of_point);
    godot::ClassDB::bind_method(godot::D_METHOD("kind", "graph", "curve_id", "out_kind"), &OcctlCurves::kind);
    godot::ClassDB::bind_method(godot::D_METHOD("is_periodic", "graph", "curve_id", "out_is_periodic"), &OcctlCurves::is_periodic);
    godot::ClassDB::bind_method(godot::D_METHOD("is_closed", "graph", "curve_id", "out_is_closed"), &OcctlCurves::is_closed);
    godot::ClassDB::bind_method(godot::D_METHOD("continuity", "graph", "curve_id", "out_continuity"), &OcctlCurves::continuity);
    godot::ClassDB::bind_method(godot::D_METHOD("parameter_range", "graph", "curve_id", "out_u_min", "out_u_max"), &OcctlCurves::parameter_range);
    godot::ClassDB::bind_method(godot::D_METHOD("as_line", "graph", "curve_id", "out_line"), &OcctlCurves::as_line);
    godot::ClassDB::bind_method(godot::D_METHOD("as_circle", "graph", "curve_id", "out_circle"), &OcctlCurves::as_circle);
    godot::ClassDB::bind_method(godot::D_METHOD("as_ellipse", "graph", "curve_id", "out_ellipse"), &OcctlCurves::as_ellipse);
    godot::ClassDB::bind_method(godot::D_METHOD("as_hyperbola", "graph", "curve_id", "out_hyperbola"), &OcctlCurves::as_hyperbola);
    godot::ClassDB::bind_method(godot::D_METHOD("as_parabola", "graph", "curve_id", "out_parabola"), &OcctlCurves::as_parabola);
    godot::ClassDB::bind_method(godot::D_METHOD("as_trimmed", "graph", "curve_id", "out_u_first", "out_u_last"), &OcctlCurves::as_trimmed);
    godot::ClassDB::bind_method(godot::D_METHOD("as_offset", "graph", "curve_id", "out_offset", "out_offset_dir"), &OcctlCurves::as_offset);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_degree", "graph", "curve_id", "out_degree"), &OcctlCurves::bspline_degree);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_pole_count", "graph", "curve_id", "out_count"), &OcctlCurves::bspline_pole_count);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_knot_count", "graph", "curve_id", "out_count"), &OcctlCurves::bspline_knot_count);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_is_rational", "graph", "curve_id", "out_is_rational"), &OcctlCurves::bspline_is_rational);
    godot::ClassDB::bind_method(godot::D_METHOD("bezier_degree", "graph", "curve_id", "out_degree"), &OcctlCurves::bezier_degree);
    godot::ClassDB::bind_method(godot::D_METHOD("bezier_pole_count", "graph", "curve_id", "out_count"), &OcctlCurves::bezier_pole_count);
    godot::ClassDB::bind_method(godot::D_METHOD("bezier_is_rational", "graph", "curve_id", "out_is_rational"), &OcctlCurves::bezier_is_rational);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_poles", "graph", "curve_id"), &OcctlCurves::bspline_poles);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_knots", "graph", "curve_id"), &OcctlCurves::bspline_knots);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_multiplicities", "graph", "curve_id"), &OcctlCurves::bspline_multiplicities);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_weights", "graph", "curve_id"), &OcctlCurves::bspline_weights);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_poles_view", "graph", "curve_id", "out_count"), &OcctlCurves::bspline_poles_view);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_flat_knots", "graph", "curve_id"), &OcctlCurves::bspline_flat_knots);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_init", "out"), &OcctlCurves::bspline_init);
    godot::ClassDB::bind_method(godot::D_METHOD("as_bspline", "graph", "curve_id", "out"), &OcctlCurves::as_bspline);
    godot::ClassDB::bind_method(godot::D_METHOD("eval_d0", "graph", "curve_id", "u", "out_point"), &OcctlCurves::eval_d0);
    godot::ClassDB::bind_method(godot::D_METHOD("eval_d1", "graph", "curve_id", "u", "out_point", "out_d1"), &OcctlCurves::eval_d1);
    godot::ClassDB::bind_method(godot::D_METHOD("eval_d2", "graph", "curve_id", "u", "out_point", "out_d1", "out_d2"), &OcctlCurves::eval_d2);
    godot::ClassDB::bind_method(godot::D_METHOD("eval_d3", "graph", "curve_id", "u", "out_point", "out_d1", "out_d2", "out_d3"), &OcctlCurves::eval_d3);
    godot::ClassDB::bind_method(godot::D_METHOD("eval_dn", "graph", "curve_id", "u", "n", "out_derivative"), &OcctlCurves::eval_dn);
    godot::ClassDB::bind_method(godot::D_METHOD("airfoil_naca4_info_init", "info"), &OcctlCurves::airfoil_naca4_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("create_airfoil_naca4", "graph", "info", "out_id"), &OcctlCurves::create_airfoil_naca4, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("create_arc_of_circle_3pt", "graph", "p1", "p2", "p3", "out_id"), &OcctlCurves::create_arc_of_circle_3pt);
    godot::ClassDB::bind_method(godot::D_METHOD("interpolated_info_init", "info"), &OcctlCurves::interpolated_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("create_interpolated", "graph", "info", "out_id"), &OcctlCurves::create_interpolated, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("approximated_info_init", "info"), &OcctlCurves::approximated_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("create_approximated", "graph", "info", "out_id"), &OcctlCurves::create_approximated, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("to_bezier_segments", "graph", "curve_id", "options", "out_count"), &OcctlCurves::to_bezier_segments, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("free_bezier_segments", "ids"), &OcctlCurves::free_bezier_segments);
    godot::ClassDB::bind_method(godot::D_METHOD("intersect", "graph", "curve_id_a", "curve_id_b", "out_count"), &OcctlCurves::intersect);
    godot::ClassDB::bind_method(godot::D_METHOD("free_intersection_points", "results"), &OcctlCurves::free_intersection_points);
}

int OcctlCurves::create_line(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlAxis1Placement>& line, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve_create_line(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), line->to_c(), &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlCurves::create_circle(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlGeomCircle>& circle, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve_create_circle(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), circle->to_c(), &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlCurves::create_ellipse(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlGeomEllipse>& ellipse, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve_create_ellipse(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), ellipse->to_c(), &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlCurves::create_hyperbola(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlGeomHyperbola>& hyperbola, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve_create_hyperbola(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), hyperbola->to_c(), &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlCurves::create_parabola(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlGeomParabola>& parabola, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve_create_parabola(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), parabola->to_c(), &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

void OcctlCurves::bspline_create_info_init(const Ref<OcctlCurveBsplineCreateInfo>& info) { // NOLINT
    occtl_curve_bspline_create_info_t _info_val = {};
    ::occtl_curve_bspline_create_info_init(&_info_val);
    ::occtl_curve_bspline_create_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlCurves::create_bspline(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurveBsplineCreateInfo>& info, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_curve_bspline_create_info_t _info_c = {};
    const occtl_curve_bspline_create_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve_create_bspline(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

void OcctlCurves::bezier_create_info_init(const Ref<OcctlCurveBezierCreateInfo>& info) { // NOLINT
    occtl_curve_bezier_create_info_t _info_val = {};
    ::occtl_curve_bezier_create_info_init(&_info_val);
    ::occtl_curve_bezier_create_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlCurves::create_bezier(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurveBezierCreateInfo>& info, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_curve_bezier_create_info_t _info_c = {};
    const occtl_curve_bezier_create_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve_create_bezier(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlCurves::create_trimmed(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurveTrimmedCreateInfo>& info, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_curve_trimmed_create_info_t _info_c = {};
    const occtl_curve_trimmed_create_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve_create_trimmed(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

void OcctlCurves::offset_create_info_init(const Ref<OcctlCurveOffsetCreateInfo>& info) { // NOLINT
    occtl_curve_offset_create_info_t _info_val = {};
    ::occtl_curve_offset_create_info_init(&_info_val);
    ::occtl_curve_offset_create_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlCurves::create_offset(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurveOffsetCreateInfo>& info, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_curve_offset_create_info_t _info_c = {};
    const occtl_curve_offset_create_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve_create_offset(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlCurves::reverse(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve_reverse(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlCurves::transformed(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlTransform>& transform, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve_transformed(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, transform->to_c(), &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlCurves::translated(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlVector3>& delta, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve_translated(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, delta->to_c(), &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlCurves::rotated(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlAxis1Placement>& axis, double angle, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve_rotated(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, axis->to_c(), angle, &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlCurves::scaled(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlPoint3>& origin, double factor, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve_scaled(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, origin->to_c(), factor, &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlCurves::length(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlDouble>& out_length) { // NOLINT
    double _out_length_val = {};
    occtl_status_t _status = ::occtl_curve_length(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_length_val);
    if (out_length.is_valid()) out_length->copy_from_c(_out_length_val);
    return static_cast<int>(_status);
}

int OcctlCurves::project_point(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlPoint3>& point, const Ref<OcctlDouble>& out_param, const Ref<OcctlDouble>& out_distance) { // NOLINT
    double _out_param_val = {};
    double _out_distance_val = {};
    occtl_status_t _status = ::occtl_curve_project_point(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, point->to_c(), &_out_param_val, &_out_distance_val);
    if (out_param.is_valid()) out_param->copy_from_c(_out_param_val);
    if (out_distance.is_valid()) out_distance->copy_from_c(_out_distance_val);
    return static_cast<int>(_status);
}

int OcctlCurves::parameter_of_point(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlPoint3>& point, const Ref<OcctlDouble>& out_param) { // NOLINT
    double _out_param_val = {};
    occtl_status_t _status = ::occtl_curve_parameter_of_point(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, point->to_c(), &_out_param_val);
    if (out_param.is_valid()) out_param->copy_from_c(_out_param_val);
    return static_cast<int>(_status);
}

int OcctlCurves::kind(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_kind) { // NOLINT
    occtl_curve_kind_t _out_kind_val = {};
    occtl_status_t _status = ::occtl_curve_kind(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_kind_val);
    if (out_kind.is_valid()) out_kind->copy_from_c(_out_kind_val);
    return static_cast<int>(_status);
}

int OcctlCurves::is_periodic(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_is_periodic) { // NOLINT
    int32_t _out_is_periodic_val = {};
    occtl_status_t _status = ::occtl_curve_is_periodic(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_is_periodic_val);
    if (out_is_periodic.is_valid()) out_is_periodic->copy_from_c(_out_is_periodic_val);
    return static_cast<int>(_status);
}

int OcctlCurves::is_closed(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_is_closed) { // NOLINT
    int32_t _out_is_closed_val = {};
    occtl_status_t _status = ::occtl_curve_is_closed(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_is_closed_val);
    if (out_is_closed.is_valid()) out_is_closed->copy_from_c(_out_is_closed_val);
    return static_cast<int>(_status);
}

int OcctlCurves::continuity(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_continuity) { // NOLINT
    occtl_geom_continuity_t _out_continuity_val = {};
    occtl_status_t _status = ::occtl_curve_continuity(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_continuity_val);
    if (out_continuity.is_valid()) out_continuity->copy_from_c(_out_continuity_val);
    return static_cast<int>(_status);
}

int OcctlCurves::parameter_range(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlDouble>& out_u_min, const Ref<OcctlDouble>& out_u_max) { // NOLINT
    double _out_u_min_val = {};
    double _out_u_max_val = {};
    occtl_status_t _status = ::occtl_curve_parameter_range(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_u_min_val, &_out_u_max_val);
    if (out_u_min.is_valid()) out_u_min->copy_from_c(_out_u_min_val);
    if (out_u_max.is_valid()) out_u_max->copy_from_c(_out_u_max_val);
    return static_cast<int>(_status);
}

int OcctlCurves::as_line(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlAxis1Placement>& out_line) { // NOLINT
    occtl_axis1_placement_t _out_line_val = {};
    occtl_status_t _status = ::occtl_curve_as_line(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_line_val);
    if (out_line.is_valid()) out_line->copy_from_c(_out_line_val);
    return static_cast<int>(_status);
}

int OcctlCurves::as_circle(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlGeomCircle>& out_circle) { // NOLINT
    occtl_geom_circle_t _out_circle_val = {};
    occtl_status_t _status = ::occtl_curve_as_circle(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_circle_val);
    if (out_circle.is_valid()) out_circle->copy_from_c(_out_circle_val);
    return static_cast<int>(_status);
}

int OcctlCurves::as_ellipse(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlGeomEllipse>& out_ellipse) { // NOLINT
    occtl_geom_ellipse_t _out_ellipse_val = {};
    occtl_status_t _status = ::occtl_curve_as_ellipse(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_ellipse_val);
    if (out_ellipse.is_valid()) out_ellipse->copy_from_c(_out_ellipse_val);
    return static_cast<int>(_status);
}

int OcctlCurves::as_hyperbola(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlGeomHyperbola>& out_hyperbola) { // NOLINT
    occtl_geom_hyperbola_t _out_hyperbola_val = {};
    occtl_status_t _status = ::occtl_curve_as_hyperbola(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_hyperbola_val);
    if (out_hyperbola.is_valid()) out_hyperbola->copy_from_c(_out_hyperbola_val);
    return static_cast<int>(_status);
}

int OcctlCurves::as_parabola(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlGeomParabola>& out_parabola) { // NOLINT
    occtl_geom_parabola_t _out_parabola_val = {};
    occtl_status_t _status = ::occtl_curve_as_parabola(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_parabola_val);
    if (out_parabola.is_valid()) out_parabola->copy_from_c(_out_parabola_val);
    return static_cast<int>(_status);
}

int OcctlCurves::as_trimmed(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlDouble>& out_u_first, const Ref<OcctlDouble>& out_u_last) { // NOLINT
    double _out_u_first_val = {};
    double _out_u_last_val = {};
    occtl_status_t _status = ::occtl_curve_as_trimmed(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_u_first_val, &_out_u_last_val);
    if (out_u_first.is_valid()) out_u_first->copy_from_c(_out_u_first_val);
    if (out_u_last.is_valid()) out_u_last->copy_from_c(_out_u_last_val);
    return static_cast<int>(_status);
}

int OcctlCurves::as_offset(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlDouble>& out_offset, const Ref<OcctlVector3>& out_offset_dir) { // NOLINT
    double _out_offset_val = {};
    occtl_vector3_t _out_offset_dir_val = {};
    occtl_status_t _status = ::occtl_curve_as_offset(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_offset_val, &_out_offset_dir_val);
    if (out_offset.is_valid()) out_offset->copy_from_c(_out_offset_val);
    if (out_offset_dir.is_valid()) out_offset_dir->copy_from_c(_out_offset_dir_val);
    return static_cast<int>(_status);
}

int OcctlCurves::bspline_degree(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_degree) { // NOLINT
    int32_t _out_degree_val = {};
    occtl_status_t _status = ::occtl_curve_bspline_degree(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_degree_val);
    if (out_degree.is_valid()) out_degree->copy_from_c(_out_degree_val);
    return static_cast<int>(_status);
}

int OcctlCurves::bspline_pole_count(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlSize>& out_count) { // NOLINT
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_curve_bspline_pole_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlCurves::bspline_knot_count(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlSize>& out_count) { // NOLINT
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_curve_bspline_knot_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlCurves::bspline_is_rational(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_is_rational) { // NOLINT
    int32_t _out_is_rational_val = {};
    occtl_status_t _status = ::occtl_curve_bspline_is_rational(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_is_rational_val);
    if (out_is_rational.is_valid()) out_is_rational->copy_from_c(_out_is_rational_val);
    return static_cast<int>(_status);
}

int OcctlCurves::bezier_degree(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_degree) { // NOLINT
    int32_t _out_degree_val = {};
    occtl_status_t _status = ::occtl_curve_bezier_degree(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_degree_val);
    if (out_degree.is_valid()) out_degree->copy_from_c(_out_degree_val);
    return static_cast<int>(_status);
}

int OcctlCurves::bezier_pole_count(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlSize>& out_count) { // NOLINT
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_curve_bezier_pole_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlCurves::bezier_is_rational(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_is_rational) { // NOLINT
    int32_t _out_is_rational_val = {};
    occtl_status_t _status = ::occtl_curve_bezier_is_rational(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_is_rational_val);
    if (out_is_rational.is_valid()) out_is_rational->copy_from_c(_out_is_rational_val);
    return static_cast<int>(_status);
}

Array OcctlCurves::bspline_poles(const Ref<OcctlGraphHandle>& graph, int64_t curve_id) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_curve_bspline_poles(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return Array(); }
    std::vector<occtl_point3_t> _out_buf_buf(static_cast<size_t>(_out_count_cnt));
    _err = ::occtl_curve_bspline_poles(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) {
        Ref<OcctlPoint3> _item;
        _item.instantiate();
        _item->copy_from_c(_out_buf_buf[_i]);
        _result[static_cast<int64_t>(_i)] = _item;
    }
    return _result;
}

PackedFloat64Array OcctlCurves::bspline_knots(const Ref<OcctlGraphHandle>& graph, int64_t curve_id) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_curve_bspline_knots(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedFloat64Array(); }
    std::vector<double> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_curve_bspline_knots(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedFloat64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = _out_buf_buf[_i];
    return _result;
}

PackedInt32Array OcctlCurves::bspline_multiplicities(const Ref<OcctlGraphHandle>& graph, int64_t curve_id) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_curve_bspline_multiplicities(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt32Array(); }
    std::vector<int32_t> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_curve_bspline_multiplicities(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt32Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = _out_buf_buf[_i];
    return _result;
}

PackedFloat64Array OcctlCurves::bspline_weights(const Ref<OcctlGraphHandle>& graph, int64_t curve_id) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_curve_bspline_weights(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedFloat64Array(); }
    std::vector<double> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_curve_bspline_weights(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedFloat64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = _out_buf_buf[_i];
    return _result;
}

int OcctlCurves::bspline_poles_view(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlSize>& out_count) { // NOLINT
    const occtl_point3_t* _out_data_val = nullptr;
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_curve_bspline_poles_view(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_data_val, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

PackedFloat64Array OcctlCurves::bspline_flat_knots(const Ref<OcctlGraphHandle>& graph, int64_t curve_id) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_curve_bspline_flat_knots(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedFloat64Array(); }
    std::vector<double> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_curve_bspline_flat_knots(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedFloat64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = _out_buf_buf[_i];
    return _result;
}

void OcctlCurves::bspline_init(const Ref<OcctlCurveBspline>& out) { // NOLINT
    occtl_curve_bspline_t _out_val = {};
    ::occtl_curve_bspline_init(&_out_val);
    ::occtl_curve_bspline_init(&_out_val);
    if (out.is_valid()) out->copy_from_c(_out_val);
}

int OcctlCurves::as_bspline(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlCurveBspline>& out) { // NOLINT
    occtl_curve_bspline_t _out_val = {};
    ::occtl_curve_bspline_init(&_out_val);
    occtl_status_t _status = ::occtl_curve_as_bspline(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_val);
    if (out.is_valid()) out->copy_from_c(_out_val);
    return static_cast<int>(_status);
}

int OcctlCurves::eval_d0(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, double u, const Ref<OcctlPoint3>& out_point) { // NOLINT
    occtl_point3_t _out_point_val = {};
    occtl_status_t _status = ::occtl_curve_eval_d0(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, u, &_out_point_val);
    if (out_point.is_valid()) out_point->copy_from_c(_out_point_val);
    return static_cast<int>(_status);
}

int OcctlCurves::eval_d1(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, double u, const Ref<OcctlPoint3>& out_point, const Ref<OcctlVector3>& out_d1) { // NOLINT
    occtl_point3_t _out_point_val = {};
    occtl_vector3_t _out_d1_val = {};
    occtl_status_t _status = ::occtl_curve_eval_d1(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, u, &_out_point_val, &_out_d1_val);
    if (out_point.is_valid()) out_point->copy_from_c(_out_point_val);
    if (out_d1.is_valid()) out_d1->copy_from_c(_out_d1_val);
    return static_cast<int>(_status);
}

int OcctlCurves::eval_d2(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, double u, const Ref<OcctlPoint3>& out_point, const Ref<OcctlVector3>& out_d1, const Ref<OcctlVector3>& out_d2) { // NOLINT
    occtl_point3_t _out_point_val = {};
    occtl_vector3_t _out_d1_val = {};
    occtl_vector3_t _out_d2_val = {};
    occtl_status_t _status = ::occtl_curve_eval_d2(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, u, &_out_point_val, &_out_d1_val, &_out_d2_val);
    if (out_point.is_valid()) out_point->copy_from_c(_out_point_val);
    if (out_d1.is_valid()) out_d1->copy_from_c(_out_d1_val);
    if (out_d2.is_valid()) out_d2->copy_from_c(_out_d2_val);
    return static_cast<int>(_status);
}

int OcctlCurves::eval_d3(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, double u, const Ref<OcctlPoint3>& out_point, const Ref<OcctlVector3>& out_d1, const Ref<OcctlVector3>& out_d2, const Ref<OcctlVector3>& out_d3) { // NOLINT
    occtl_point3_t _out_point_val = {};
    occtl_vector3_t _out_d1_val = {};
    occtl_vector3_t _out_d2_val = {};
    occtl_vector3_t _out_d3_val = {};
    occtl_status_t _status = ::occtl_curve_eval_d3(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, u, &_out_point_val, &_out_d1_val, &_out_d2_val, &_out_d3_val);
    if (out_point.is_valid()) out_point->copy_from_c(_out_point_val);
    if (out_d1.is_valid()) out_d1->copy_from_c(_out_d1_val);
    if (out_d2.is_valid()) out_d2->copy_from_c(_out_d2_val);
    if (out_d3.is_valid()) out_d3->copy_from_c(_out_d3_val);
    return static_cast<int>(_status);
}

int OcctlCurves::eval_dn(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, double u, int n, const Ref<OcctlVector3>& out_derivative) { // NOLINT
    occtl_vector3_t _out_derivative_val = {};
    occtl_status_t _status = ::occtl_curve_eval_dn(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, u, n, &_out_derivative_val);
    if (out_derivative.is_valid()) out_derivative->copy_from_c(_out_derivative_val);
    return static_cast<int>(_status);
}

void OcctlCurves::airfoil_naca4_info_init(const Ref<OcctlCurveAirfoilNaca4Info>& info) { // NOLINT
    occtl_curve_airfoil_naca4_info_t _info_val = {};
    ::occtl_curve_airfoil_naca4_info_init(&_info_val);
    ::occtl_curve_airfoil_naca4_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlCurves::create_airfoil_naca4(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurveAirfoilNaca4Info>& info, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_curve_airfoil_naca4_info_t _info_c = {};
    const occtl_curve_airfoil_naca4_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve_create_airfoil_naca4(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlCurves::create_arc_of_circle_3pt(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPoint3>& p1, const Ref<OcctlPoint3>& p2, const Ref<OcctlPoint3>& p3, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve_create_arc_of_circle_3pt(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), p1->to_c(), p2->to_c(), p3->to_c(), &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

void OcctlCurves::interpolated_info_init(const Ref<OcctlCurveInterpolatedInfo>& info) { // NOLINT
    occtl_curve_interpolated_info_t _info_val = {};
    ::occtl_curve_interpolated_info_init(&_info_val);
    ::occtl_curve_interpolated_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlCurves::create_interpolated(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurveInterpolatedInfo>& info, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_curve_interpolated_info_t _info_c = {};
    const occtl_curve_interpolated_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve_create_interpolated(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

void OcctlCurves::approximated_info_init(const Ref<OcctlCurveApproximatedInfo>& info) { // NOLINT
    occtl_curve_approximated_info_t _info_val = {};
    ::occtl_curve_approximated_info_init(&_info_val);
    ::occtl_curve_approximated_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlCurves::create_approximated(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurveApproximatedInfo>& info, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_curve_approximated_info_t _info_c = {};
    const occtl_curve_approximated_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve_create_approximated(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlCurves::to_bezier_segments(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlCurveBezierSegmentsOptions>& options, const Ref<OcctlSize>& out_count) { // NOLINT
    occtl_curve_bezier_segments_options_t _options_c = {};
    const occtl_curve_bezier_segments_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_rep_id_t* _out_ids_val = nullptr;
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_curve_to_bezier_segments(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, _options_ptr, &_out_ids_val, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    if (_status != OCCTL_OK) { return 0; }
    return static_cast<int64_t>(_out_ids_val->bits);
}

void OcctlCurves::free_bezier_segments(const Ref<OcctlRepId>& ids) { // NOLINT
    occtl_rep_id_t _ids_val = {};
    ::occtl_curve_free_bezier_segments(&_ids_val);
    if (ids.is_valid()) ids->copy_from_c(_ids_val);
}

int OcctlCurves::intersect(const Ref<OcctlGraphHandle>& graph, int64_t curve_id_a, int64_t curve_id_b, const Ref<OcctlSize>& out_count) { // NOLINT
    const occtl_curve_intersection_point_t* _out_results_val = nullptr;
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_curve_intersect(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id_a)}, occtl_rep_id_t{static_cast<uint64_t>(curve_id_b)}, &_out_results_val, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

void OcctlCurves::free_intersection_points(const Ref<OcctlCurveIntersectionPoint>& results) { // NOLINT
    occtl_curve_intersection_point_t _results_val = {};
    ::occtl_curve_free_intersection_points(&_results_val);
    if (results.is_valid()) results->copy_from_c(_results_val);
}
