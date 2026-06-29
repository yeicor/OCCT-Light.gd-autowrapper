#include "OcctlCurves2d.h"

#include "occtl/occtl_curves2d.h"

#include <vector>

void OcctlCurves2d::_bind_methods() {
    BIND_CONSTANT(OCCTL_CURVE2D_CIRCLE_TANGENT_TO_TWO_RADIUS_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_CURVE2D_BLEND_ARC_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_CURVE2D_LINE_TANGENT_TO_TWO_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_CURVE2D_LINE_TANGENT_THROUGH_POINT_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_CURVE2D_LINE_TANGENT_WITH_ANGLE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_CURVE2D_CIRCLE_TANGENT_TO_THREE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_CURVE2D_CIRCLE_TANGENT_FIXED_CENTER_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_CURVE2D_CIRCLE_TANGENT_CENTER_ON_CURVE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_CURVE2D_CIRCLE_TANGENT_ON_CURVE_RADIUS_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_CURVE2D_BSPLINE_CREATE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_CURVE2D_BEZIER_CREATE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_CURVE2D_OFFSET_CREATE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_CURVE2D_BSPLINE_VERSION_1);
    godot::ClassDB::bind_method(godot::D_METHOD("circle_tangent_to_two_radius_info_init", "info"), &OcctlCurves2d::circle_tangent_to_two_radius_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("blend_arc_info_init", "info"), &OcctlCurves2d::blend_arc_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("line_tangent_to_two_info_init", "info"), &OcctlCurves2d::line_tangent_to_two_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("line_tangent_through_point_info_init", "info"), &OcctlCurves2d::line_tangent_through_point_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("line_tangent_with_angle_info_init", "info"), &OcctlCurves2d::line_tangent_with_angle_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("circle_tangent_to_three_info_init", "info"), &OcctlCurves2d::circle_tangent_to_three_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("circle_tangent_fixed_center_info_init", "info"), &OcctlCurves2d::circle_tangent_fixed_center_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("circle_tangent_center_on_curve_info_init", "info"), &OcctlCurves2d::circle_tangent_center_on_curve_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("circle_tangent_on_curve_radius_info_init", "info"), &OcctlCurves2d::circle_tangent_on_curve_radius_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("create_tangent_circle_to_two_radius", "graph", "info", "solution_index", "out_circle", "out_count"), &OcctlCurves2d::create_tangent_circle_to_two_radius, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("create_blend_arc", "graph", "info", "solution_index", "out_id", "out_count"), &OcctlCurves2d::create_blend_arc, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("create_tangent_line_to_two", "graph", "info", "solution_index", "out_line", "out_count"), &OcctlCurves2d::create_tangent_line_to_two, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("create_tangent_line_through_point", "graph", "info", "solution_index", "out_line", "out_count"), &OcctlCurves2d::create_tangent_line_through_point, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("create_tangent_line_with_angle", "graph", "info", "solution_index", "out_line", "out_count"), &OcctlCurves2d::create_tangent_line_with_angle, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("create_tangent_circle_to_three", "graph", "info", "solution_index", "out_circle", "out_count"), &OcctlCurves2d::create_tangent_circle_to_three, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("create_tangent_circle_fixed_center", "graph", "info", "solution_index", "out_circle", "out_count"), &OcctlCurves2d::create_tangent_circle_fixed_center, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("create_tangent_circle_center_on_curve", "graph", "info", "solution_index", "out_circle", "out_count"), &OcctlCurves2d::create_tangent_circle_center_on_curve, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("create_tangent_circle_on_curve_radius", "graph", "info", "solution_index", "out_circle", "out_count"), &OcctlCurves2d::create_tangent_circle_on_curve_radius, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("create_line", "graph", "line", "out_id"), &OcctlCurves2d::create_line);
    godot::ClassDB::bind_method(godot::D_METHOD("create_circle", "graph", "circle", "out_id"), &OcctlCurves2d::create_circle);
    godot::ClassDB::bind_method(godot::D_METHOD("create_ellipse", "graph", "ellipse", "out_id"), &OcctlCurves2d::create_ellipse);
    godot::ClassDB::bind_method(godot::D_METHOD("create_hyperbola", "graph", "hyperbola", "out_id"), &OcctlCurves2d::create_hyperbola);
    godot::ClassDB::bind_method(godot::D_METHOD("create_parabola", "graph", "parabola", "out_id"), &OcctlCurves2d::create_parabola);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_create_info_init", "info"), &OcctlCurves2d::bspline_create_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("create_bspline", "graph", "info", "out_id"), &OcctlCurves2d::create_bspline, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("bezier_create_info_init", "info"), &OcctlCurves2d::bezier_create_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("create_bezier", "graph", "info", "out_id"), &OcctlCurves2d::create_bezier, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("create_trimmed", "graph", "info", "out_id"), &OcctlCurves2d::create_trimmed, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("offset_create_info_init", "info"), &OcctlCurves2d::offset_create_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("create_offset", "graph", "info", "out_id"), &OcctlCurves2d::create_offset, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("reverse", "graph", "curve_id", "out_id"), &OcctlCurves2d::reverse);
    godot::ClassDB::bind_method(godot::D_METHOD("transformed", "graph", "curve_id", "translate_x", "translate_y", "rotate_angle", "scale_x", "scale_y", "out_id"), &OcctlCurves2d::transformed);
    godot::ClassDB::bind_method(godot::D_METHOD("translated", "graph", "curve_id", "delta", "out_id"), &OcctlCurves2d::translated);
    godot::ClassDB::bind_method(godot::D_METHOD("rotated", "graph", "curve_id", "angle", "out_id"), &OcctlCurves2d::rotated);
    godot::ClassDB::bind_method(godot::D_METHOD("scaled", "graph", "curve_id", "origin", "factor", "out_id"), &OcctlCurves2d::scaled);
    godot::ClassDB::bind_method(godot::D_METHOD("length", "graph", "curve_id", "out_length"), &OcctlCurves2d::length);
    godot::ClassDB::bind_method(godot::D_METHOD("project_point", "graph", "curve_id", "point", "out_param", "out_distance"), &OcctlCurves2d::project_point);
    godot::ClassDB::bind_method(godot::D_METHOD("parameter_of_point", "graph", "curve_id", "point", "out_param"), &OcctlCurves2d::parameter_of_point);
    godot::ClassDB::bind_method(godot::D_METHOD("kind", "graph", "curve_id", "out_kind"), &OcctlCurves2d::kind);
    godot::ClassDB::bind_method(godot::D_METHOD("is_periodic", "graph", "curve_id", "out_is_periodic"), &OcctlCurves2d::is_periodic);
    godot::ClassDB::bind_method(godot::D_METHOD("is_closed", "graph", "curve_id", "out_is_closed"), &OcctlCurves2d::is_closed);
    godot::ClassDB::bind_method(godot::D_METHOD("continuity", "graph", "curve_id", "out_continuity"), &OcctlCurves2d::continuity);
    godot::ClassDB::bind_method(godot::D_METHOD("parameter_range", "graph", "curve_id", "out_u_min", "out_u_max"), &OcctlCurves2d::parameter_range);
    godot::ClassDB::bind_method(godot::D_METHOD("as_line", "graph", "curve_id", "out_line"), &OcctlCurves2d::as_line);
    godot::ClassDB::bind_method(godot::D_METHOD("as_circle", "graph", "curve_id", "out_circle"), &OcctlCurves2d::as_circle);
    godot::ClassDB::bind_method(godot::D_METHOD("as_ellipse", "graph", "curve_id", "out_ellipse"), &OcctlCurves2d::as_ellipse);
    godot::ClassDB::bind_method(godot::D_METHOD("as_hyperbola", "graph", "curve_id", "out_hyperbola"), &OcctlCurves2d::as_hyperbola);
    godot::ClassDB::bind_method(godot::D_METHOD("as_parabola", "graph", "curve_id", "out_parabola"), &OcctlCurves2d::as_parabola);
    godot::ClassDB::bind_method(godot::D_METHOD("as_trimmed", "graph", "curve_id", "out_u_first", "out_u_last"), &OcctlCurves2d::as_trimmed);
    godot::ClassDB::bind_method(godot::D_METHOD("as_offset", "graph", "curve_id", "out_offset"), &OcctlCurves2d::as_offset);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_degree", "graph", "curve_id", "out_degree"), &OcctlCurves2d::bspline_degree);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_pole_count", "graph", "curve_id", "out_count"), &OcctlCurves2d::bspline_pole_count);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_knot_count", "graph", "curve_id", "out_count"), &OcctlCurves2d::bspline_knot_count);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_is_rational", "graph", "curve_id", "out_is_rational"), &OcctlCurves2d::bspline_is_rational);
    godot::ClassDB::bind_method(godot::D_METHOD("bezier_degree", "graph", "curve_id", "out_degree"), &OcctlCurves2d::bezier_degree);
    godot::ClassDB::bind_method(godot::D_METHOD("bezier_pole_count", "graph", "curve_id", "out_count"), &OcctlCurves2d::bezier_pole_count);
    godot::ClassDB::bind_method(godot::D_METHOD("bezier_is_rational", "graph", "curve_id", "out_is_rational"), &OcctlCurves2d::bezier_is_rational);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_poles", "graph", "curve_id"), &OcctlCurves2d::bspline_poles);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_knots", "graph", "curve_id"), &OcctlCurves2d::bspline_knots);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_multiplicities", "graph", "curve_id"), &OcctlCurves2d::bspline_multiplicities);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_weights", "graph", "curve_id"), &OcctlCurves2d::bspline_weights);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_flat_knots", "graph", "curve_id"), &OcctlCurves2d::bspline_flat_knots);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_poles_view", "graph", "curve_id", "out_count"), &OcctlCurves2d::bspline_poles_view);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_init", "out"), &OcctlCurves2d::bspline_init);
    godot::ClassDB::bind_method(godot::D_METHOD("as_bspline", "graph", "curve_id", "out"), &OcctlCurves2d::as_bspline);
    godot::ClassDB::bind_method(godot::D_METHOD("to_bezier_segments", "graph", "curve_id", "options", "out_count"), &OcctlCurves2d::to_bezier_segments, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("free_bezier_segments", "ids"), &OcctlCurves2d::free_bezier_segments);
    godot::ClassDB::bind_method(godot::D_METHOD("eval_d0", "graph", "curve_id", "u", "out_point"), &OcctlCurves2d::eval_d0);
    godot::ClassDB::bind_method(godot::D_METHOD("eval_d1", "graph", "curve_id", "u", "out_point", "out_d1"), &OcctlCurves2d::eval_d1);
    godot::ClassDB::bind_method(godot::D_METHOD("eval_d2", "graph", "curve_id", "u", "out_point", "out_d1", "out_d2"), &OcctlCurves2d::eval_d2);
    godot::ClassDB::bind_method(godot::D_METHOD("eval_d3", "graph", "curve_id", "u", "out_point", "out_d1", "out_d2", "out_d3"), &OcctlCurves2d::eval_d3);
    godot::ClassDB::bind_method(godot::D_METHOD("eval_dn", "graph", "curve_id", "u", "n", "out_derivative"), &OcctlCurves2d::eval_dn);
}

void OcctlCurves2d::circle_tangent_to_two_radius_info_init(const Ref<OcctlCurve2dCircleTangentToTwoRadiusInfo>& info) { // NOLINT
    occtl_curve2d_circle_tangent_to_two_radius_info_t _info_val = {};
    ::occtl_curve2d_circle_tangent_to_two_radius_info_init(&_info_val);
    ::occtl_curve2d_circle_tangent_to_two_radius_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

void OcctlCurves2d::blend_arc_info_init(const Ref<OcctlCurve2dBlendArcInfo>& info) { // NOLINT
    occtl_curve2d_blend_arc_info_t _info_val = {};
    ::occtl_curve2d_blend_arc_info_init(&_info_val);
    ::occtl_curve2d_blend_arc_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

void OcctlCurves2d::line_tangent_to_two_info_init(const Ref<OcctlCurve2dLineTangentToTwoInfo>& info) { // NOLINT
    occtl_curve2d_line_tangent_to_two_info_t _info_val = {};
    ::occtl_curve2d_line_tangent_to_two_info_init(&_info_val);
    ::occtl_curve2d_line_tangent_to_two_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

void OcctlCurves2d::line_tangent_through_point_info_init(const Ref<OcctlCurve2dLineTangentThroughPointInfo>& info) { // NOLINT
    occtl_curve2d_line_tangent_through_point_info_t _info_val = {};
    ::occtl_curve2d_line_tangent_through_point_info_init(&_info_val);
    ::occtl_curve2d_line_tangent_through_point_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

void OcctlCurves2d::line_tangent_with_angle_info_init(const Ref<OcctlCurve2dLineTangentWithAngleInfo>& info) { // NOLINT
    occtl_curve2d_line_tangent_with_angle_info_t _info_val = {};
    ::occtl_curve2d_line_tangent_with_angle_info_init(&_info_val);
    ::occtl_curve2d_line_tangent_with_angle_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

void OcctlCurves2d::circle_tangent_to_three_info_init(const Ref<OcctlCurve2dCircleTangentToThreeInfo>& info) { // NOLINT
    occtl_curve2d_circle_tangent_to_three_info_t _info_val = {};
    ::occtl_curve2d_circle_tangent_to_three_info_init(&_info_val);
    ::occtl_curve2d_circle_tangent_to_three_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

void OcctlCurves2d::circle_tangent_fixed_center_info_init(const Ref<OcctlCurve2dCircleTangentFixedCenterInfo>& info) { // NOLINT
    occtl_curve2d_circle_tangent_fixed_center_info_t _info_val = {};
    ::occtl_curve2d_circle_tangent_fixed_center_info_init(&_info_val);
    ::occtl_curve2d_circle_tangent_fixed_center_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

void OcctlCurves2d::circle_tangent_center_on_curve_info_init(const Ref<OcctlCurve2dCircleTangentCenterOnCurveInfo>& info) { // NOLINT
    occtl_curve2d_circle_tangent_center_on_curve_info_t _info_val = {};
    ::occtl_curve2d_circle_tangent_center_on_curve_info_init(&_info_val);
    ::occtl_curve2d_circle_tangent_center_on_curve_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

void OcctlCurves2d::circle_tangent_on_curve_radius_info_init(const Ref<OcctlCurve2dCircleTangentOnCurveRadiusInfo>& info) { // NOLINT
    occtl_curve2d_circle_tangent_on_curve_radius_info_t _info_val = {};
    ::occtl_curve2d_circle_tangent_on_curve_radius_info_init(&_info_val);
    ::occtl_curve2d_circle_tangent_on_curve_radius_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlCurves2d::create_tangent_circle_to_two_radius(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurve2dCircleTangentToTwoRadiusInfo>& info, int solution_index, const Ref<OcctlGeom2dCircle>& out_circle, const Ref<OcctlSize>& out_count) { // NOLINT
    occtl_curve2d_circle_tangent_to_two_radius_info_t _info_c = {};
    const occtl_curve2d_circle_tangent_to_two_radius_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_geom2d_circle_t _out_circle_val = {};
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_curve2d_create_tangent_circle_to_two_radius(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, solution_index, &_out_circle_val, &_out_count_val);
    if (out_circle.is_valid()) out_circle->copy_from_c(_out_circle_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::create_blend_arc(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurve2dBlendArcInfo>& info, int solution_index, const Ref<OcctlRepId>& out_id, const Ref<OcctlSize>& out_count) { // NOLINT
    occtl_curve2d_blend_arc_info_t _info_c = {};
    const occtl_curve2d_blend_arc_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_rep_id_t _out_id_val = {};
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_curve2d_create_blend_arc(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, solution_index, &_out_id_val, &_out_count_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::create_tangent_line_to_two(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurve2dLineTangentToTwoInfo>& info, int solution_index, const Ref<OcctlGeom2dLine>& out_line, const Ref<OcctlSize>& out_count) { // NOLINT
    occtl_curve2d_line_tangent_to_two_info_t _info_c = {};
    const occtl_curve2d_line_tangent_to_two_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_geom2d_line_t _out_line_val = {};
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_curve2d_create_tangent_line_to_two(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, solution_index, &_out_line_val, &_out_count_val);
    if (out_line.is_valid()) out_line->copy_from_c(_out_line_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::create_tangent_line_through_point(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurve2dLineTangentThroughPointInfo>& info, int solution_index, const Ref<OcctlGeom2dLine>& out_line, const Ref<OcctlSize>& out_count) { // NOLINT
    occtl_curve2d_line_tangent_through_point_info_t _info_c = {};
    const occtl_curve2d_line_tangent_through_point_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_geom2d_line_t _out_line_val = {};
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_curve2d_create_tangent_line_through_point(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, solution_index, &_out_line_val, &_out_count_val);
    if (out_line.is_valid()) out_line->copy_from_c(_out_line_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::create_tangent_line_with_angle(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurve2dLineTangentWithAngleInfo>& info, int solution_index, const Ref<OcctlGeom2dLine>& out_line, const Ref<OcctlSize>& out_count) { // NOLINT
    occtl_curve2d_line_tangent_with_angle_info_t _info_c = {};
    const occtl_curve2d_line_tangent_with_angle_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_geom2d_line_t _out_line_val = {};
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_curve2d_create_tangent_line_with_angle(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, solution_index, &_out_line_val, &_out_count_val);
    if (out_line.is_valid()) out_line->copy_from_c(_out_line_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::create_tangent_circle_to_three(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurve2dCircleTangentToThreeInfo>& info, int solution_index, const Ref<OcctlGeom2dCircle>& out_circle, const Ref<OcctlSize>& out_count) { // NOLINT
    occtl_curve2d_circle_tangent_to_three_info_t _info_c = {};
    const occtl_curve2d_circle_tangent_to_three_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_geom2d_circle_t _out_circle_val = {};
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_curve2d_create_tangent_circle_to_three(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, solution_index, &_out_circle_val, &_out_count_val);
    if (out_circle.is_valid()) out_circle->copy_from_c(_out_circle_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::create_tangent_circle_fixed_center(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurve2dCircleTangentFixedCenterInfo>& info, int solution_index, const Ref<OcctlGeom2dCircle>& out_circle, const Ref<OcctlSize>& out_count) { // NOLINT
    occtl_curve2d_circle_tangent_fixed_center_info_t _info_c = {};
    const occtl_curve2d_circle_tangent_fixed_center_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_geom2d_circle_t _out_circle_val = {};
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_curve2d_create_tangent_circle_fixed_center(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, solution_index, &_out_circle_val, &_out_count_val);
    if (out_circle.is_valid()) out_circle->copy_from_c(_out_circle_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::create_tangent_circle_center_on_curve(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurve2dCircleTangentCenterOnCurveInfo>& info, int solution_index, const Ref<OcctlGeom2dCircle>& out_circle, const Ref<OcctlSize>& out_count) { // NOLINT
    occtl_curve2d_circle_tangent_center_on_curve_info_t _info_c = {};
    const occtl_curve2d_circle_tangent_center_on_curve_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_geom2d_circle_t _out_circle_val = {};
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_curve2d_create_tangent_circle_center_on_curve(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, solution_index, &_out_circle_val, &_out_count_val);
    if (out_circle.is_valid()) out_circle->copy_from_c(_out_circle_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::create_tangent_circle_on_curve_radius(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurve2dCircleTangentOnCurveRadiusInfo>& info, int solution_index, const Ref<OcctlGeom2dCircle>& out_circle, const Ref<OcctlSize>& out_count) { // NOLINT
    occtl_curve2d_circle_tangent_on_curve_radius_info_t _info_c = {};
    const occtl_curve2d_circle_tangent_on_curve_radius_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_geom2d_circle_t _out_circle_val = {};
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_curve2d_create_tangent_circle_on_curve_radius(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, solution_index, &_out_circle_val, &_out_count_val);
    if (out_circle.is_valid()) out_circle->copy_from_c(_out_circle_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::create_line(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlGeom2dLine>& line, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve2d_create_line(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), line->to_c(), &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::create_circle(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlGeom2dCircle>& circle, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve2d_create_circle(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), circle->to_c(), &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::create_ellipse(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlGeom2dEllipse>& ellipse, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve2d_create_ellipse(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), ellipse->to_c(), &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::create_hyperbola(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlGeom2dHyperbola>& hyperbola, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve2d_create_hyperbola(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), hyperbola->to_c(), &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::create_parabola(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlGeom2dParabola>& parabola, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve2d_create_parabola(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), parabola->to_c(), &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

void OcctlCurves2d::bspline_create_info_init(const Ref<OcctlCurve2dBsplineCreateInfo>& info) { // NOLINT
    occtl_curve2d_bspline_create_info_t _info_val = {};
    ::occtl_curve2d_bspline_create_info_init(&_info_val);
    ::occtl_curve2d_bspline_create_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlCurves2d::create_bspline(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurve2dBsplineCreateInfo>& info, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_curve2d_bspline_create_info_t _info_c = {};
    const occtl_curve2d_bspline_create_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve2d_create_bspline(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

void OcctlCurves2d::bezier_create_info_init(const Ref<OcctlCurve2dBezierCreateInfo>& info) { // NOLINT
    occtl_curve2d_bezier_create_info_t _info_val = {};
    ::occtl_curve2d_bezier_create_info_init(&_info_val);
    ::occtl_curve2d_bezier_create_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlCurves2d::create_bezier(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurve2dBezierCreateInfo>& info, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_curve2d_bezier_create_info_t _info_c = {};
    const occtl_curve2d_bezier_create_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve2d_create_bezier(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::create_trimmed(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurveTrimmedCreateInfo>& info, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_curve_trimmed_create_info_t _info_c = {};
    const occtl_curve_trimmed_create_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve2d_create_trimmed(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

void OcctlCurves2d::offset_create_info_init(const Ref<OcctlCurve2dOffsetCreateInfo>& info) { // NOLINT
    occtl_curve2d_offset_create_info_t _info_val = {};
    ::occtl_curve2d_offset_create_info_init(&_info_val);
    ::occtl_curve2d_offset_create_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlCurves2d::create_offset(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurve2dOffsetCreateInfo>& info, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_curve2d_offset_create_info_t _info_c = {};
    const occtl_curve2d_offset_create_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve2d_create_offset(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::reverse(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve2d_reverse(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::transformed(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, double translate_x, double translate_y, double rotate_angle, double scale_x, double scale_y, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve2d_transformed(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, translate_x, translate_y, rotate_angle, scale_x, scale_y, &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::translated(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlVector2>& delta, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve2d_translated(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, delta->to_c(), &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::rotated(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, double angle, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve2d_rotated(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, angle, &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::scaled(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlPoint2>& origin, double factor, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_curve2d_scaled(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, origin->to_c(), factor, &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::length(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlDouble>& out_length) { // NOLINT
    double _out_length_val = {};
    occtl_status_t _status = ::occtl_curve2d_length(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_length_val);
    if (out_length.is_valid()) out_length->copy_from_c(_out_length_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::project_point(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlPoint2>& point, const Ref<OcctlDouble>& out_param, const Ref<OcctlDouble>& out_distance) { // NOLINT
    double _out_param_val = {};
    double _out_distance_val = {};
    occtl_status_t _status = ::occtl_curve2d_project_point(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, point->to_c(), &_out_param_val, &_out_distance_val);
    if (out_param.is_valid()) out_param->copy_from_c(_out_param_val);
    if (out_distance.is_valid()) out_distance->copy_from_c(_out_distance_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::parameter_of_point(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlPoint2>& point, const Ref<OcctlDouble>& out_param) { // NOLINT
    double _out_param_val = {};
    occtl_status_t _status = ::occtl_curve2d_parameter_of_point(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, point->to_c(), &_out_param_val);
    if (out_param.is_valid()) out_param->copy_from_c(_out_param_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::kind(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_kind) { // NOLINT
    occtl_curve_kind_t _out_kind_val = {};
    occtl_status_t _status = ::occtl_curve2d_kind(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_kind_val);
    if (out_kind.is_valid()) out_kind->copy_from_c(_out_kind_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::is_periodic(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_is_periodic) { // NOLINT
    int32_t _out_is_periodic_val = {};
    occtl_status_t _status = ::occtl_curve2d_is_periodic(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_is_periodic_val);
    if (out_is_periodic.is_valid()) out_is_periodic->copy_from_c(_out_is_periodic_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::is_closed(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_is_closed) { // NOLINT
    int32_t _out_is_closed_val = {};
    occtl_status_t _status = ::occtl_curve2d_is_closed(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_is_closed_val);
    if (out_is_closed.is_valid()) out_is_closed->copy_from_c(_out_is_closed_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::continuity(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_continuity) { // NOLINT
    occtl_geom_continuity_t _out_continuity_val = {};
    occtl_status_t _status = ::occtl_curve2d_continuity(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_continuity_val);
    if (out_continuity.is_valid()) out_continuity->copy_from_c(_out_continuity_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::parameter_range(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlDouble>& out_u_min, const Ref<OcctlDouble>& out_u_max) { // NOLINT
    double _out_u_min_val = {};
    double _out_u_max_val = {};
    occtl_status_t _status = ::occtl_curve2d_parameter_range(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_u_min_val, &_out_u_max_val);
    if (out_u_min.is_valid()) out_u_min->copy_from_c(_out_u_min_val);
    if (out_u_max.is_valid()) out_u_max->copy_from_c(_out_u_max_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::as_line(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlGeom2dLine>& out_line) { // NOLINT
    occtl_geom2d_line_t _out_line_val = {};
    occtl_status_t _status = ::occtl_curve2d_as_line(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_line_val);
    if (out_line.is_valid()) out_line->copy_from_c(_out_line_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::as_circle(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlGeom2dCircle>& out_circle) { // NOLINT
    occtl_geom2d_circle_t _out_circle_val = {};
    occtl_status_t _status = ::occtl_curve2d_as_circle(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_circle_val);
    if (out_circle.is_valid()) out_circle->copy_from_c(_out_circle_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::as_ellipse(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlGeom2dEllipse>& out_ellipse) { // NOLINT
    occtl_geom2d_ellipse_t _out_ellipse_val = {};
    occtl_status_t _status = ::occtl_curve2d_as_ellipse(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_ellipse_val);
    if (out_ellipse.is_valid()) out_ellipse->copy_from_c(_out_ellipse_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::as_hyperbola(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlGeom2dHyperbola>& out_hyperbola) { // NOLINT
    occtl_geom2d_hyperbola_t _out_hyperbola_val = {};
    occtl_status_t _status = ::occtl_curve2d_as_hyperbola(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_hyperbola_val);
    if (out_hyperbola.is_valid()) out_hyperbola->copy_from_c(_out_hyperbola_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::as_parabola(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlGeom2dParabola>& out_parabola) { // NOLINT
    occtl_geom2d_parabola_t _out_parabola_val = {};
    occtl_status_t _status = ::occtl_curve2d_as_parabola(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_parabola_val);
    if (out_parabola.is_valid()) out_parabola->copy_from_c(_out_parabola_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::as_trimmed(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlDouble>& out_u_first, const Ref<OcctlDouble>& out_u_last) { // NOLINT
    double _out_u_first_val = {};
    double _out_u_last_val = {};
    occtl_status_t _status = ::occtl_curve2d_as_trimmed(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_u_first_val, &_out_u_last_val);
    if (out_u_first.is_valid()) out_u_first->copy_from_c(_out_u_first_val);
    if (out_u_last.is_valid()) out_u_last->copy_from_c(_out_u_last_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::as_offset(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlDouble>& out_offset) { // NOLINT
    double _out_offset_val = {};
    occtl_status_t _status = ::occtl_curve2d_as_offset(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_offset_val);
    if (out_offset.is_valid()) out_offset->copy_from_c(_out_offset_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::bspline_degree(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_degree) { // NOLINT
    int32_t _out_degree_val = {};
    occtl_status_t _status = ::occtl_curve2d_bspline_degree(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_degree_val);
    if (out_degree.is_valid()) out_degree->copy_from_c(_out_degree_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::bspline_pole_count(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlSize>& out_count) { // NOLINT
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_curve2d_bspline_pole_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::bspline_knot_count(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlSize>& out_count) { // NOLINT
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_curve2d_bspline_knot_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::bspline_is_rational(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_is_rational) { // NOLINT
    int32_t _out_is_rational_val = {};
    occtl_status_t _status = ::occtl_curve2d_bspline_is_rational(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_is_rational_val);
    if (out_is_rational.is_valid()) out_is_rational->copy_from_c(_out_is_rational_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::bezier_degree(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_degree) { // NOLINT
    int32_t _out_degree_val = {};
    occtl_status_t _status = ::occtl_curve2d_bezier_degree(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_degree_val);
    if (out_degree.is_valid()) out_degree->copy_from_c(_out_degree_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::bezier_pole_count(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlSize>& out_count) { // NOLINT
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_curve2d_bezier_pole_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::bezier_is_rational(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_is_rational) { // NOLINT
    int32_t _out_is_rational_val = {};
    occtl_status_t _status = ::occtl_curve2d_bezier_is_rational(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_is_rational_val);
    if (out_is_rational.is_valid()) out_is_rational->copy_from_c(_out_is_rational_val);
    return static_cast<int>(_status);
}

Array OcctlCurves2d::bspline_poles(const Ref<OcctlGraphHandle>& graph, int64_t curve_id) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_curve2d_bspline_poles(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return Array(); }
    std::vector<occtl_point2_t> _out_buf_buf(static_cast<size_t>(_out_count_cnt));
    _err = ::occtl_curve2d_bspline_poles(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) {
        Ref<OcctlPoint2> _item;
        _item.instantiate();
        _item->copy_from_c(_out_buf_buf[_i]);
        _result[static_cast<int64_t>(_i)] = _item;
    }
    return _result;
}

PackedFloat64Array OcctlCurves2d::bspline_knots(const Ref<OcctlGraphHandle>& graph, int64_t curve_id) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_curve2d_bspline_knots(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedFloat64Array(); }
    std::vector<double> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_curve2d_bspline_knots(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedFloat64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = _out_buf_buf[_i];
    return _result;
}

PackedInt32Array OcctlCurves2d::bspline_multiplicities(const Ref<OcctlGraphHandle>& graph, int64_t curve_id) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_curve2d_bspline_multiplicities(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt32Array(); }
    std::vector<int32_t> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_curve2d_bspline_multiplicities(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt32Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = _out_buf_buf[_i];
    return _result;
}

PackedFloat64Array OcctlCurves2d::bspline_weights(const Ref<OcctlGraphHandle>& graph, int64_t curve_id) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_curve2d_bspline_weights(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedFloat64Array(); }
    std::vector<double> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_curve2d_bspline_weights(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedFloat64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = _out_buf_buf[_i];
    return _result;
}

PackedFloat64Array OcctlCurves2d::bspline_flat_knots(const Ref<OcctlGraphHandle>& graph, int64_t curve_id) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_curve2d_bspline_flat_knots(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedFloat64Array(); }
    std::vector<double> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_curve2d_bspline_flat_knots(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedFloat64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = _out_buf_buf[_i];
    return _result;
}

int OcctlCurves2d::bspline_poles_view(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlSize>& out_count) { // NOLINT
    const occtl_point2_t* _out_data_val = nullptr;
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_curve2d_bspline_poles_view(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_data_val, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

void OcctlCurves2d::bspline_init(const Ref<OcctlCurve2dBspline>& out) { // NOLINT
    occtl_curve2d_bspline_t _out_val = {};
    ::occtl_curve2d_bspline_init(&_out_val);
    ::occtl_curve2d_bspline_init(&_out_val);
    if (out.is_valid()) out->copy_from_c(_out_val);
}

int OcctlCurves2d::as_bspline(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlCurve2dBspline>& out) { // NOLINT
    occtl_curve2d_bspline_t _out_val = {};
    ::occtl_curve2d_bspline_init(&_out_val);
    occtl_status_t _status = ::occtl_curve2d_as_bspline(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, &_out_val);
    if (out.is_valid()) out->copy_from_c(_out_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::to_bezier_segments(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlCurveBezierSegmentsOptions>& options, const Ref<OcctlSize>& out_count) { // NOLINT
    occtl_curve_bezier_segments_options_t _options_c = {};
    const occtl_curve_bezier_segments_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_rep_id_t* _out_segments_val = nullptr;
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_curve2d_to_bezier_segments(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, _options_ptr, &_out_segments_val, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    if (_status != OCCTL_OK) { return 0; }
    return static_cast<int64_t>(_out_segments_val->bits);
}

void OcctlCurves2d::free_bezier_segments(const Ref<OcctlRepId>& ids) { // NOLINT
    occtl_rep_id_t _ids_val = {};
    ::occtl_curve2d_free_bezier_segments(&_ids_val);
    if (ids.is_valid()) ids->copy_from_c(_ids_val);
}

int OcctlCurves2d::eval_d0(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, double u, const Ref<OcctlPoint2>& out_point) { // NOLINT
    occtl_point2_t _out_point_val = {};
    occtl_status_t _status = ::occtl_curve2d_eval_d0(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, u, &_out_point_val);
    if (out_point.is_valid()) out_point->copy_from_c(_out_point_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::eval_d1(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, double u, const Ref<OcctlPoint2>& out_point, const Ref<OcctlVector2>& out_d1) { // NOLINT
    occtl_point2_t _out_point_val = {};
    occtl_vector2_t _out_d1_val = {};
    occtl_status_t _status = ::occtl_curve2d_eval_d1(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, u, &_out_point_val, &_out_d1_val);
    if (out_point.is_valid()) out_point->copy_from_c(_out_point_val);
    if (out_d1.is_valid()) out_d1->copy_from_c(_out_d1_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::eval_d2(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, double u, const Ref<OcctlPoint2>& out_point, const Ref<OcctlVector2>& out_d1, const Ref<OcctlVector2>& out_d2) { // NOLINT
    occtl_point2_t _out_point_val = {};
    occtl_vector2_t _out_d1_val = {};
    occtl_vector2_t _out_d2_val = {};
    occtl_status_t _status = ::occtl_curve2d_eval_d2(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, u, &_out_point_val, &_out_d1_val, &_out_d2_val);
    if (out_point.is_valid()) out_point->copy_from_c(_out_point_val);
    if (out_d1.is_valid()) out_d1->copy_from_c(_out_d1_val);
    if (out_d2.is_valid()) out_d2->copy_from_c(_out_d2_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::eval_d3(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, double u, const Ref<OcctlPoint2>& out_point, const Ref<OcctlVector2>& out_d1, const Ref<OcctlVector2>& out_d2, const Ref<OcctlVector2>& out_d3) { // NOLINT
    occtl_point2_t _out_point_val = {};
    occtl_vector2_t _out_d1_val = {};
    occtl_vector2_t _out_d2_val = {};
    occtl_vector2_t _out_d3_val = {};
    occtl_status_t _status = ::occtl_curve2d_eval_d3(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, u, &_out_point_val, &_out_d1_val, &_out_d2_val, &_out_d3_val);
    if (out_point.is_valid()) out_point->copy_from_c(_out_point_val);
    if (out_d1.is_valid()) out_d1->copy_from_c(_out_d1_val);
    if (out_d2.is_valid()) out_d2->copy_from_c(_out_d2_val);
    if (out_d3.is_valid()) out_d3->copy_from_c(_out_d3_val);
    return static_cast<int>(_status);
}

int OcctlCurves2d::eval_dn(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, double u, int n, const Ref<OcctlVector2>& out_derivative) { // NOLINT
    occtl_vector2_t _out_derivative_val = {};
    occtl_status_t _status = ::occtl_curve2d_eval_dn(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, u, n, &_out_derivative_val);
    if (out_derivative.is_valid()) out_derivative->copy_from_c(_out_derivative_val);
    return static_cast<int>(_status);
}
