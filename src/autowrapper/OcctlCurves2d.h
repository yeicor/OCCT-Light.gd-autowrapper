#ifndef OCCTLCURVES2D_H
#define OCCTLCURVES2D_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/packed_byte_array.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/vector3.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/transform3d.hpp>
#include <godot_cpp/variant/aabb.hpp>
#include <godot_cpp/variant/color.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <cstdint>
#include "occtl/occtl_curves2d.h"

#include "OcctlCurve2dBezierCreateInfo.h"
#include "OcctlCurve2dBlendArcInfo.h"
#include "OcctlCurve2dBspline.h"
#include "OcctlCurve2dBsplineCreateInfo.h"
#include "OcctlCurve2dCircleTangentCenterOnCurveInfo.h"
#include "OcctlCurve2dCircleTangentFixedCenterInfo.h"
#include "OcctlCurve2dCircleTangentOnCurveRadiusInfo.h"
#include "OcctlCurve2dCircleTangentToThreeInfo.h"
#include "OcctlCurve2dCircleTangentToTwoRadiusInfo.h"
#include "OcctlCurve2dLineTangentThroughPointInfo.h"
#include "OcctlCurve2dLineTangentToTwoInfo.h"
#include "OcctlCurve2dLineTangentWithAngleInfo.h"
#include "OcctlCurve2dOffsetCreateInfo.h"
#include "OcctlCurveBezierSegmentsOptions.h"
#include "OcctlCurveTrimmedCreateInfo.h"
#include "OcctlDouble.h"
#include "OcctlGeom2dCircle.h"
#include "OcctlGeom2dEllipse.h"
#include "OcctlGeom2dHyperbola.h"
#include "OcctlGeom2dLine.h"
#include "OcctlGeom2dParabola.h"
#include "OcctlGraphHandle.h"
#include "OcctlInt32.h"
#include "OcctlPoint2.h"
#include "OcctlRepId.h"
#include "OcctlSize.h"
#include "OcctlVector2.h"

using namespace godot;

class OcctlCurves2d : public godot::RefCounted {
    GDCLASS(OcctlCurves2d, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    void circle_tangent_to_two_radius_info_init(const Ref<OcctlCurve2dCircleTangentToTwoRadiusInfo>& info); // NOLINT
    void blend_arc_info_init(const Ref<OcctlCurve2dBlendArcInfo>& info); // NOLINT
    void line_tangent_to_two_info_init(const Ref<OcctlCurve2dLineTangentToTwoInfo>& info); // NOLINT
    void line_tangent_through_point_info_init(const Ref<OcctlCurve2dLineTangentThroughPointInfo>& info); // NOLINT
    void line_tangent_with_angle_info_init(const Ref<OcctlCurve2dLineTangentWithAngleInfo>& info); // NOLINT
    void circle_tangent_to_three_info_init(const Ref<OcctlCurve2dCircleTangentToThreeInfo>& info); // NOLINT
    void circle_tangent_fixed_center_info_init(const Ref<OcctlCurve2dCircleTangentFixedCenterInfo>& info); // NOLINT
    void circle_tangent_center_on_curve_info_init(const Ref<OcctlCurve2dCircleTangentCenterOnCurveInfo>& info); // NOLINT
    void circle_tangent_on_curve_radius_info_init(const Ref<OcctlCurve2dCircleTangentOnCurveRadiusInfo>& info); // NOLINT
    int create_tangent_circle_to_two_radius(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurve2dCircleTangentToTwoRadiusInfo>& info, int solution_index, const Ref<OcctlGeom2dCircle>& out_circle, const Ref<OcctlSize>& out_count); // NOLINT
    int create_blend_arc(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurve2dBlendArcInfo>& info, int solution_index, const Ref<OcctlRepId>& out_id, const Ref<OcctlSize>& out_count); // NOLINT
    int create_tangent_line_to_two(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurve2dLineTangentToTwoInfo>& info, int solution_index, const Ref<OcctlGeom2dLine>& out_line, const Ref<OcctlSize>& out_count); // NOLINT
    int create_tangent_line_through_point(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurve2dLineTangentThroughPointInfo>& info, int solution_index, const Ref<OcctlGeom2dLine>& out_line, const Ref<OcctlSize>& out_count); // NOLINT
    int create_tangent_line_with_angle(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurve2dLineTangentWithAngleInfo>& info, int solution_index, const Ref<OcctlGeom2dLine>& out_line, const Ref<OcctlSize>& out_count); // NOLINT
    int create_tangent_circle_to_three(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurve2dCircleTangentToThreeInfo>& info, int solution_index, const Ref<OcctlGeom2dCircle>& out_circle, const Ref<OcctlSize>& out_count); // NOLINT
    int create_tangent_circle_fixed_center(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurve2dCircleTangentFixedCenterInfo>& info, int solution_index, const Ref<OcctlGeom2dCircle>& out_circle, const Ref<OcctlSize>& out_count); // NOLINT
    int create_tangent_circle_center_on_curve(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurve2dCircleTangentCenterOnCurveInfo>& info, int solution_index, const Ref<OcctlGeom2dCircle>& out_circle, const Ref<OcctlSize>& out_count); // NOLINT
    int create_tangent_circle_on_curve_radius(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurve2dCircleTangentOnCurveRadiusInfo>& info, int solution_index, const Ref<OcctlGeom2dCircle>& out_circle, const Ref<OcctlSize>& out_count); // NOLINT
    int create_line(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlGeom2dLine>& line, const Ref<OcctlRepId>& out_id); // NOLINT
    int create_circle(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlGeom2dCircle>& circle, const Ref<OcctlRepId>& out_id); // NOLINT
    int create_ellipse(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlGeom2dEllipse>& ellipse, const Ref<OcctlRepId>& out_id); // NOLINT
    int create_hyperbola(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlGeom2dHyperbola>& hyperbola, const Ref<OcctlRepId>& out_id); // NOLINT
    int create_parabola(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlGeom2dParabola>& parabola, const Ref<OcctlRepId>& out_id); // NOLINT
    void bspline_create_info_init(const Ref<OcctlCurve2dBsplineCreateInfo>& info); // NOLINT
    int create_bspline(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurve2dBsplineCreateInfo>& info, const Ref<OcctlRepId>& out_id); // NOLINT
    void bezier_create_info_init(const Ref<OcctlCurve2dBezierCreateInfo>& info); // NOLINT
    int create_bezier(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurve2dBezierCreateInfo>& info, const Ref<OcctlRepId>& out_id); // NOLINT
    int create_trimmed(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurveTrimmedCreateInfo>& info, const Ref<OcctlRepId>& out_id); // NOLINT
    void offset_create_info_init(const Ref<OcctlCurve2dOffsetCreateInfo>& info); // NOLINT
    int create_offset(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurve2dOffsetCreateInfo>& info, const Ref<OcctlRepId>& out_id); // NOLINT
    int reverse(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlRepId>& out_id); // NOLINT
    int transformed(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, double translate_x, double translate_y, double rotate_angle, double scale_x, double scale_y, const Ref<OcctlRepId>& out_id); // NOLINT
    int translated(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlVector2>& delta, const Ref<OcctlRepId>& out_id); // NOLINT
    int rotated(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, double angle, const Ref<OcctlRepId>& out_id); // NOLINT
    int scaled(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlPoint2>& origin, double factor, const Ref<OcctlRepId>& out_id); // NOLINT
    int length(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlDouble>& out_length); // NOLINT
    int project_point(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlPoint2>& point, const Ref<OcctlDouble>& out_param, const Ref<OcctlDouble>& out_distance); // NOLINT
    int parameter_of_point(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlPoint2>& point, const Ref<OcctlDouble>& out_param); // NOLINT
    int kind(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_kind); // NOLINT
    int is_periodic(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_is_periodic); // NOLINT
    int is_closed(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_is_closed); // NOLINT
    int continuity(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_continuity); // NOLINT
    int parameter_range(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlDouble>& out_u_min, const Ref<OcctlDouble>& out_u_max); // NOLINT
    int as_line(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlGeom2dLine>& out_line); // NOLINT
    int as_circle(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlGeom2dCircle>& out_circle); // NOLINT
    int as_ellipse(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlGeom2dEllipse>& out_ellipse); // NOLINT
    int as_hyperbola(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlGeom2dHyperbola>& out_hyperbola); // NOLINT
    int as_parabola(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlGeom2dParabola>& out_parabola); // NOLINT
    int as_trimmed(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlDouble>& out_u_first, const Ref<OcctlDouble>& out_u_last); // NOLINT
    int as_offset(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlDouble>& out_offset); // NOLINT
    int bspline_degree(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_degree); // NOLINT
    int bspline_pole_count(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlSize>& out_count); // NOLINT
    int bspline_knot_count(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlSize>& out_count); // NOLINT
    int bspline_is_rational(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_is_rational); // NOLINT
    int bezier_degree(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_degree); // NOLINT
    int bezier_pole_count(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlSize>& out_count); // NOLINT
    int bezier_is_rational(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_is_rational); // NOLINT
    Array bspline_poles(const Ref<OcctlGraphHandle>& graph, int64_t curve_id); // NOLINT
    PackedFloat64Array bspline_knots(const Ref<OcctlGraphHandle>& graph, int64_t curve_id); // NOLINT
    PackedInt32Array bspline_multiplicities(const Ref<OcctlGraphHandle>& graph, int64_t curve_id); // NOLINT
    PackedFloat64Array bspline_weights(const Ref<OcctlGraphHandle>& graph, int64_t curve_id); // NOLINT
    PackedFloat64Array bspline_flat_knots(const Ref<OcctlGraphHandle>& graph, int64_t curve_id); // NOLINT
    int bspline_poles_view(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlSize>& out_count); // NOLINT
    void bspline_init(const Ref<OcctlCurve2dBspline>& out); // NOLINT
    int as_bspline(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlCurve2dBspline>& out); // NOLINT
    int to_bezier_segments(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlCurveBezierSegmentsOptions>& options, const Ref<OcctlSize>& out_count); // NOLINT
    void free_bezier_segments(const Ref<OcctlRepId>& ids); // NOLINT
    int eval_d0(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, double u, const Ref<OcctlPoint2>& out_point); // NOLINT
    int eval_d1(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, double u, const Ref<OcctlPoint2>& out_point, const Ref<OcctlVector2>& out_d1); // NOLINT
    int eval_d2(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, double u, const Ref<OcctlPoint2>& out_point, const Ref<OcctlVector2>& out_d1, const Ref<OcctlVector2>& out_d2); // NOLINT
    int eval_d3(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, double u, const Ref<OcctlPoint2>& out_point, const Ref<OcctlVector2>& out_d1, const Ref<OcctlVector2>& out_d2, const Ref<OcctlVector2>& out_d3); // NOLINT
    int eval_dn(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, double u, int n, const Ref<OcctlVector2>& out_derivative); // NOLINT
};

#endif // OCCTLCURVES2D_H
