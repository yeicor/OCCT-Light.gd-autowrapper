#ifndef OCCTLSURFACES_H
#define OCCTLSURFACES_H

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
#include "occtl/occtl_surfaces.h"

#include "OcctlAxis1Placement.h"
#include "OcctlDouble.h"
#include "OcctlGeomConicalSurface.h"
#include "OcctlGeomCylindricalSurface.h"
#include "OcctlGeomPlane.h"
#include "OcctlGeomSphericalSurface.h"
#include "OcctlGeomToroidalSurface.h"
#include "OcctlGraphHandle.h"
#include "OcctlInt32.h"
#include "OcctlPoint3.h"
#include "OcctlRepId.h"
#include "OcctlSize.h"
#include "OcctlSurfaceApproximatedInfo.h"
#include "OcctlSurfaceBezierCreateInfo.h"
#include "OcctlSurfaceBoundaryCurvesCreateInfo.h"
#include "OcctlSurfaceBspline.h"
#include "OcctlSurfaceBsplineCreateInfo.h"
#include "OcctlSurfaceCurveGridCreateInfo.h"
#include "OcctlSurfaceExtrusionCreateInfo.h"
#include "OcctlSurfaceGordonCreateInfo.h"
#include "OcctlSurfaceInterpolatedInfo.h"
#include "OcctlSurfaceOffsetCreateInfo.h"
#include "OcctlSurfacePointGridCreateInfo.h"
#include "OcctlSurfaceRectangularTrimmedCreateInfo.h"
#include "OcctlSurfaceRevolutionCreateInfo.h"
#include "OcctlTransform.h"
#include "OcctlVector3.h"

using namespace godot;

class OcctlSurfaces : public godot::RefCounted {
    GDCLASS(OcctlSurfaces, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int create_plane(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlGeomPlane>& plane); // NOLINT
    int create_cylinder(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlGeomCylindricalSurface>& cylinder); // NOLINT
    int create_cone(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlGeomConicalSurface>& cone); // NOLINT
    int create_sphere(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlGeomSphericalSurface>& sphere); // NOLINT
    int create_torus(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlGeomToroidalSurface>& torus); // NOLINT
    void revolution_create_info_init(const Ref<OcctlSurfaceRevolutionCreateInfo>& info); // NOLINT
    int create_revolution(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlSurfaceRevolutionCreateInfo>& info); // NOLINT
    void extrusion_create_info_init(const Ref<OcctlSurfaceExtrusionCreateInfo>& info); // NOLINT
    int create_extrusion(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlSurfaceExtrusionCreateInfo>& info); // NOLINT
    void rectangular_trimmed_create_info_init(const Ref<OcctlSurfaceRectangularTrimmedCreateInfo>& info); // NOLINT
    int create_rectangular_trimmed(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlSurfaceRectangularTrimmedCreateInfo>& info); // NOLINT
    void offset_create_info_init(const Ref<OcctlSurfaceOffsetCreateInfo>& info); // NOLINT
    int create_offset(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlSurfaceOffsetCreateInfo>& info); // NOLINT
    void bspline_create_info_init(const Ref<OcctlSurfaceBsplineCreateInfo>& info); // NOLINT
    int create_bspline(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlSurfaceBsplineCreateInfo>& info); // NOLINT
    void bezier_create_info_init(const Ref<OcctlSurfaceBezierCreateInfo>& info); // NOLINT
    int create_bezier(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlSurfaceBezierCreateInfo>& info); // NOLINT
    int create_bezier_grid(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlSurfaceBezierCreateInfo>& info); // NOLINT
    int reverse(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlRepId>& out_id); // NOLINT
    int transformed(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlTransform>& transform, const Ref<OcctlRepId>& out_id); // NOLINT
    int translated(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlVector3>& delta, const Ref<OcctlRepId>& out_id); // NOLINT
    int rotated(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlAxis1Placement>& axis, double angle, const Ref<OcctlRepId>& out_id); // NOLINT
    int scaled(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlPoint3>& origin, double factor, const Ref<OcctlRepId>& out_id); // NOLINT
    int area(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlDouble>& out_area); // NOLINT
    int project_point(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlPoint3>& point, const Ref<OcctlDouble>& out_u, const Ref<OcctlDouble>& out_v, const Ref<OcctlDouble>& out_distance); // NOLINT
    int uv_of_point(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlPoint3>& point, const Ref<OcctlDouble>& out_u, const Ref<OcctlDouble>& out_v); // NOLINT
    int kind(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlInt32>& out_kind); // NOLINT
    int is_u_periodic(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlInt32>& out_is_periodic); // NOLINT
    int is_v_periodic(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlInt32>& out_is_periodic); // NOLINT
    int is_closed(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlInt32>& out_is_closed); // NOLINT
    int is_periodic(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlInt32>& out_is_periodic); // NOLINT
    int continuity(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlInt32>& out_continuity); // NOLINT
    int parameter_range(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlDouble>& out_u_min, const Ref<OcctlDouble>& out_u_max, const Ref<OcctlDouble>& out_v_min, const Ref<OcctlDouble>& out_v_max); // NOLINT
    int as_plane(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlGeomPlane>& out_plane); // NOLINT
    int as_cylinder(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlGeomCylindricalSurface>& out_cylinder); // NOLINT
    int as_cone(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlGeomConicalSurface>& out_cone); // NOLINT
    int as_sphere(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlGeomSphericalSurface>& out_sphere); // NOLINT
    int as_torus(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlGeomToroidalSurface>& out_torus); // NOLINT
    int as_revolution(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlAxis1Placement>& out_axis); // NOLINT
    int as_extrusion(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlVector3>& out_direction); // NOLINT
    int as_rectangular_trimmed(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlDouble>& out_u_first, const Ref<OcctlDouble>& out_u_last, const Ref<OcctlDouble>& out_v_first, const Ref<OcctlDouble>& out_v_last); // NOLINT
    int as_offset(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlDouble>& out_offset); // NOLINT
    int bspline_u_degree(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlInt32>& out_degree); // NOLINT
    int bspline_v_degree(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlInt32>& out_degree); // NOLINT
    int bspline_u_pole_count(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlSize>& out_count); // NOLINT
    int bspline_v_pole_count(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlSize>& out_count); // NOLINT
    int bspline_is_rational(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlInt32>& out_is_rational); // NOLINT
    int bspline_u_knot_count(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlSize>& out_count); // NOLINT
    int bspline_v_knot_count(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlSize>& out_count); // NOLINT
    int bezier_u_degree(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlInt32>& out_degree); // NOLINT
    int bezier_v_degree(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlInt32>& out_degree); // NOLINT
    int bezier_u_pole_count(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlSize>& out_count); // NOLINT
    int bezier_v_pole_count(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlSize>& out_count); // NOLINT
    int bezier_is_rational(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlInt32>& out_is_rational); // NOLINT
    Array bspline_poles(const Ref<OcctlGraphHandle>& graph, int64_t surface_id); // NOLINT
    PackedFloat64Array bspline_u_knots(const Ref<OcctlGraphHandle>& graph, int64_t surface_id); // NOLINT
    PackedFloat64Array bspline_v_knots(const Ref<OcctlGraphHandle>& graph, int64_t surface_id); // NOLINT
    PackedInt32Array bspline_u_multiplicities(const Ref<OcctlGraphHandle>& graph, int64_t surface_id); // NOLINT
    PackedInt32Array bspline_v_multiplicities(const Ref<OcctlGraphHandle>& graph, int64_t surface_id); // NOLINT
    PackedFloat64Array bspline_weights(const Ref<OcctlGraphHandle>& graph, int64_t surface_id); // NOLINT
    PackedFloat64Array bspline_u_flat_knots(const Ref<OcctlGraphHandle>& graph, int64_t surface_id); // NOLINT
    PackedFloat64Array bspline_v_flat_knots(const Ref<OcctlGraphHandle>& graph, int64_t surface_id); // NOLINT
    int bspline_poles_view(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlSize>& out_u_count, const Ref<OcctlSize>& out_v_count); // NOLINT
    void bspline_init(const Ref<OcctlSurfaceBspline>& out); // NOLINT
    int as_bspline(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlSurfaceBspline>& out); // NOLINT
    int eval_d0(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, double u, double v, const Ref<OcctlPoint3>& out_point); // NOLINT
    int eval_d1(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, double u, double v, const Ref<OcctlPoint3>& out_point, const Ref<OcctlVector3>& out_d1u, const Ref<OcctlVector3>& out_d1v); // NOLINT
    int eval_d2(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, double u, double v, const Ref<OcctlPoint3>& out_point, const Ref<OcctlVector3>& out_d1u, const Ref<OcctlVector3>& out_d1v, const Ref<OcctlVector3>& out_d2u, const Ref<OcctlVector3>& out_d2v, const Ref<OcctlVector3>& out_d2uv); // NOLINT
    int eval_d3(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, double u, double v, const Ref<OcctlPoint3>& out_point, const Ref<OcctlVector3>& out_d1u, const Ref<OcctlVector3>& out_d1v, const Ref<OcctlVector3>& out_d2u, const Ref<OcctlVector3>& out_d2v, const Ref<OcctlVector3>& out_d2uv, const Ref<OcctlVector3>& out_d3u, const Ref<OcctlVector3>& out_d3v, const Ref<OcctlVector3>& out_d3uuv, const Ref<OcctlVector3>& out_d3uvv); // NOLINT
    int eval_dn(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, double u, double v, int nu, int nv, const Ref<OcctlVector3>& out_derivative); // NOLINT
    void interpolated_info_init(const Ref<OcctlSurfaceInterpolatedInfo>& info); // NOLINT
    int create_interpolated(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSurfaceInterpolatedInfo>& info, const Ref<OcctlRepId>& out_id); // NOLINT
    void approximated_info_init(const Ref<OcctlSurfaceApproximatedInfo>& info); // NOLINT
    int create_approximated(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSurfaceApproximatedInfo>& info, const Ref<OcctlRepId>& out_id); // NOLINT
    void point_grid_create_info_init(const Ref<OcctlSurfacePointGridCreateInfo>& info); // NOLINT
    int create_from_point_grid(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlSurfacePointGridCreateInfo>& info); // NOLINT
    void boundary_curves_create_info_init(const Ref<OcctlSurfaceBoundaryCurvesCreateInfo>& info); // NOLINT
    int create_from_boundary_curves(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlSurfaceBoundaryCurvesCreateInfo>& info); // NOLINT
    void gordon_create_info_init(const Ref<OcctlSurfaceGordonCreateInfo>& info); // NOLINT
    int create_gordon(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlSurfaceGordonCreateInfo>& info); // NOLINT
    void curve_grid_create_info_init(const Ref<OcctlSurfaceCurveGridCreateInfo>& info); // NOLINT
    int create_from_curve_grid(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlSurfaceCurveGridCreateInfo>& info); // NOLINT
    Array intersect_curve(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, int64_t curve_id); // NOLINT
    int surface_intersect(const Ref<OcctlGraphHandle>& graph, int64_t surface_a, int64_t surface_b, double tolerance, const Ref<OcctlSize>& out_count); // NOLINT
};

#endif // OCCTLSURFACES_H
