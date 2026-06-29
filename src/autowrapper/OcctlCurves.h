#ifndef OCCTLCURVES_H
#define OCCTLCURVES_H

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
#include "occtl/occtl_curves.h"

#include "OcctlAxis1Placement.h"
#include "OcctlCurveAirfoilNaca4Info.h"
#include "OcctlCurveApproximatedInfo.h"
#include "OcctlCurveBezierCreateInfo.h"
#include "OcctlCurveBezierSegmentsOptions.h"
#include "OcctlCurveBspline.h"
#include "OcctlCurveBsplineCreateInfo.h"
#include "OcctlCurveInterpolatedInfo.h"
#include "OcctlCurveIntersectionPoint.h"
#include "OcctlCurveOffsetCreateInfo.h"
#include "OcctlCurveTrimmedCreateInfo.h"
#include "OcctlDouble.h"
#include "OcctlGeomCircle.h"
#include "OcctlGeomEllipse.h"
#include "OcctlGeomHyperbola.h"
#include "OcctlGeomParabola.h"
#include "OcctlGraphHandle.h"
#include "OcctlInt32.h"
#include "OcctlPoint3.h"
#include "OcctlRepId.h"
#include "OcctlSize.h"
#include "OcctlTransform.h"
#include "OcctlVector3.h"

using namespace godot;

class OcctlCurves : public godot::RefCounted {
    GDCLASS(OcctlCurves, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int create_line(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlAxis1Placement>& line, const Ref<OcctlRepId>& out_id); // NOLINT
    int create_circle(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlGeomCircle>& circle, const Ref<OcctlRepId>& out_id); // NOLINT
    int create_ellipse(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlGeomEllipse>& ellipse, const Ref<OcctlRepId>& out_id); // NOLINT
    int create_hyperbola(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlGeomHyperbola>& hyperbola, const Ref<OcctlRepId>& out_id); // NOLINT
    int create_parabola(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlGeomParabola>& parabola, const Ref<OcctlRepId>& out_id); // NOLINT
    void bspline_create_info_init(const Ref<OcctlCurveBsplineCreateInfo>& info); // NOLINT
    int create_bspline(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurveBsplineCreateInfo>& info, const Ref<OcctlRepId>& out_id); // NOLINT
    void bezier_create_info_init(const Ref<OcctlCurveBezierCreateInfo>& info); // NOLINT
    int create_bezier(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurveBezierCreateInfo>& info, const Ref<OcctlRepId>& out_id); // NOLINT
    int create_trimmed(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurveTrimmedCreateInfo>& info, const Ref<OcctlRepId>& out_id); // NOLINT
    void offset_create_info_init(const Ref<OcctlCurveOffsetCreateInfo>& info); // NOLINT
    int create_offset(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurveOffsetCreateInfo>& info, const Ref<OcctlRepId>& out_id); // NOLINT
    int reverse(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlRepId>& out_id); // NOLINT
    int transformed(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlTransform>& transform, const Ref<OcctlRepId>& out_id); // NOLINT
    int translated(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlVector3>& delta, const Ref<OcctlRepId>& out_id); // NOLINT
    int rotated(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlAxis1Placement>& axis, double angle, const Ref<OcctlRepId>& out_id); // NOLINT
    int scaled(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlPoint3>& origin, double factor, const Ref<OcctlRepId>& out_id); // NOLINT
    int length(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlDouble>& out_length); // NOLINT
    int project_point(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlPoint3>& point, const Ref<OcctlDouble>& out_param, const Ref<OcctlDouble>& out_distance); // NOLINT
    int parameter_of_point(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlPoint3>& point, const Ref<OcctlDouble>& out_param); // NOLINT
    int kind(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_kind); // NOLINT
    int is_periodic(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_is_periodic); // NOLINT
    int is_closed(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_is_closed); // NOLINT
    int continuity(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlInt32>& out_continuity); // NOLINT
    int parameter_range(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlDouble>& out_u_min, const Ref<OcctlDouble>& out_u_max); // NOLINT
    int as_line(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlAxis1Placement>& out_line); // NOLINT
    int as_circle(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlGeomCircle>& out_circle); // NOLINT
    int as_ellipse(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlGeomEllipse>& out_ellipse); // NOLINT
    int as_hyperbola(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlGeomHyperbola>& out_hyperbola); // NOLINT
    int as_parabola(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlGeomParabola>& out_parabola); // NOLINT
    int as_trimmed(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlDouble>& out_u_first, const Ref<OcctlDouble>& out_u_last); // NOLINT
    int as_offset(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlDouble>& out_offset, const Ref<OcctlVector3>& out_offset_dir); // NOLINT
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
    int bspline_poles_view(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlSize>& out_count); // NOLINT
    PackedFloat64Array bspline_flat_knots(const Ref<OcctlGraphHandle>& graph, int64_t curve_id); // NOLINT
    void bspline_init(const Ref<OcctlCurveBspline>& out); // NOLINT
    int as_bspline(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlCurveBspline>& out); // NOLINT
    int eval_d0(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, double u, const Ref<OcctlPoint3>& out_point); // NOLINT
    int eval_d1(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, double u, const Ref<OcctlPoint3>& out_point, const Ref<OcctlVector3>& out_d1); // NOLINT
    int eval_d2(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, double u, const Ref<OcctlPoint3>& out_point, const Ref<OcctlVector3>& out_d1, const Ref<OcctlVector3>& out_d2); // NOLINT
    int eval_d3(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, double u, const Ref<OcctlPoint3>& out_point, const Ref<OcctlVector3>& out_d1, const Ref<OcctlVector3>& out_d2, const Ref<OcctlVector3>& out_d3); // NOLINT
    int eval_dn(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, double u, int n, const Ref<OcctlVector3>& out_derivative); // NOLINT
    void airfoil_naca4_info_init(const Ref<OcctlCurveAirfoilNaca4Info>& info); // NOLINT
    int create_airfoil_naca4(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurveAirfoilNaca4Info>& info, const Ref<OcctlRepId>& out_id); // NOLINT
    int create_arc_of_circle_3pt(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPoint3>& p1, const Ref<OcctlPoint3>& p2, const Ref<OcctlPoint3>& p3, const Ref<OcctlRepId>& out_id); // NOLINT
    void interpolated_info_init(const Ref<OcctlCurveInterpolatedInfo>& info); // NOLINT
    int create_interpolated(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurveInterpolatedInfo>& info, const Ref<OcctlRepId>& out_id); // NOLINT
    void approximated_info_init(const Ref<OcctlCurveApproximatedInfo>& info); // NOLINT
    int create_approximated(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlCurveApproximatedInfo>& info, const Ref<OcctlRepId>& out_id); // NOLINT
    int to_bezier_segments(const Ref<OcctlGraphHandle>& graph, int64_t curve_id, const Ref<OcctlCurveBezierSegmentsOptions>& options, const Ref<OcctlSize>& out_count); // NOLINT
    void free_bezier_segments(const Ref<OcctlRepId>& ids); // NOLINT
    int intersect(const Ref<OcctlGraphHandle>& graph, int64_t curve_id_a, int64_t curve_id_b, const Ref<OcctlSize>& out_count); // NOLINT
    void free_intersection_points(const Ref<OcctlCurveIntersectionPoint>& results); // NOLINT
};

#endif // OCCTLCURVES_H
