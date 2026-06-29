#include "OcctlSurfaces.h"

#include "occtl/occtl_surfaces.h"

#include <vector>

void OcctlSurfaces::_bind_methods() {
    BIND_CONSTANT(OCCTL_SURFACE_REVOLUTION_CREATE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_SURFACE_EXTRUSION_CREATE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_SURFACE_RECTANGULAR_TRIMMED_CREATE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_SURFACE_OFFSET_CREATE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_SURFACE_BSPLINE_CREATE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_SURFACE_BEZIER_CREATE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_SURFACE_BSPLINE_VERSION_1);
    BIND_CONSTANT(OCCTL_SURFACE_INTERPOLATED_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_SURFACE_APPROXIMATED_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_SURFACE_POINT_GRID_CREATE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_SURFACE_BOUNDARY_CURVES_CREATE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_SURFACE_GORDON_CREATE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_SURFACE_CURVE_GRID_CREATE_INFO_VERSION_1);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_surface_kind_t", "OCCTL_SURFACE_KIND_PLANE", OCCTL_SURFACE_KIND_PLANE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_surface_kind_t", "OCCTL_SURFACE_KIND_CYLINDRICAL", OCCTL_SURFACE_KIND_CYLINDRICAL);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_surface_kind_t", "OCCTL_SURFACE_KIND_CONICAL", OCCTL_SURFACE_KIND_CONICAL);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_surface_kind_t", "OCCTL_SURFACE_KIND_SPHERICAL", OCCTL_SURFACE_KIND_SPHERICAL);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_surface_kind_t", "OCCTL_SURFACE_KIND_TOROIDAL", OCCTL_SURFACE_KIND_TOROIDAL);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_surface_kind_t", "OCCTL_SURFACE_KIND_BSPLINE", OCCTL_SURFACE_KIND_BSPLINE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_surface_kind_t", "OCCTL_SURFACE_KIND_BEZIER", OCCTL_SURFACE_KIND_BEZIER);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_surface_kind_t", "OCCTL_SURFACE_KIND_REVOLUTION", OCCTL_SURFACE_KIND_REVOLUTION);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_surface_kind_t", "OCCTL_SURFACE_KIND_EXTRUSION", OCCTL_SURFACE_KIND_EXTRUSION);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_surface_kind_t", "OCCTL_SURFACE_KIND_RECTANGULAR_TRIMMED", OCCTL_SURFACE_KIND_RECTANGULAR_TRIMMED);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_surface_kind_t", "OCCTL_SURFACE_KIND_OFFSET", OCCTL_SURFACE_KIND_OFFSET);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_surface_kind_t", "OCCTL_SURFACE_KIND_UNDEFINED", OCCTL_SURFACE_KIND_UNDEFINED);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_surface_kind_t", "OCCTL_SURFACE_KIND_RESERVED_FUTURE", OCCTL_SURFACE_KIND_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_surface_point_grid_mode_t", "OCCTL_SURFACE_POINT_GRID_MODE_APPROXIMATE", OCCTL_SURFACE_POINT_GRID_MODE_APPROXIMATE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_surface_point_grid_mode_t", "OCCTL_SURFACE_POINT_GRID_MODE_INTERPOLATE", OCCTL_SURFACE_POINT_GRID_MODE_INTERPOLATE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_surface_point_grid_mode_t", "OCCTL_SURFACE_POINT_GRID_MODE_RESERVED_FUTURE", OCCTL_SURFACE_POINT_GRID_MODE_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_surface_filling_style_t", "OCCTL_SURFACE_FILLING_STRETCH", OCCTL_SURFACE_FILLING_STRETCH);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_surface_filling_style_t", "OCCTL_SURFACE_FILLING_COONS", OCCTL_SURFACE_FILLING_COONS);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_surface_filling_style_t", "OCCTL_SURFACE_FILLING_CURVED", OCCTL_SURFACE_FILLING_CURVED);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_surface_filling_style_t", "OCCTL_SURFACE_FILLING_RESERVED_FUTURE", OCCTL_SURFACE_FILLING_RESERVED_FUTURE);
    godot::ClassDB::bind_method(godot::D_METHOD("create_plane", "graph", "out_id", "plane"), &OcctlSurfaces::create_plane);
    godot::ClassDB::bind_method(godot::D_METHOD("create_cylinder", "graph", "out_id", "cylinder"), &OcctlSurfaces::create_cylinder);
    godot::ClassDB::bind_method(godot::D_METHOD("create_cone", "graph", "out_id", "cone"), &OcctlSurfaces::create_cone);
    godot::ClassDB::bind_method(godot::D_METHOD("create_sphere", "graph", "out_id", "sphere"), &OcctlSurfaces::create_sphere);
    godot::ClassDB::bind_method(godot::D_METHOD("create_torus", "graph", "out_id", "torus"), &OcctlSurfaces::create_torus);
    godot::ClassDB::bind_method(godot::D_METHOD("revolution_create_info_init", "info"), &OcctlSurfaces::revolution_create_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("create_revolution", "graph", "out_id", "info"), &OcctlSurfaces::create_revolution, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("extrusion_create_info_init", "info"), &OcctlSurfaces::extrusion_create_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("create_extrusion", "graph", "out_id", "info"), &OcctlSurfaces::create_extrusion, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("rectangular_trimmed_create_info_init", "info"), &OcctlSurfaces::rectangular_trimmed_create_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("create_rectangular_trimmed", "graph", "out_id", "info"), &OcctlSurfaces::create_rectangular_trimmed, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("offset_create_info_init", "info"), &OcctlSurfaces::offset_create_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("create_offset", "graph", "out_id", "info"), &OcctlSurfaces::create_offset, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_create_info_init", "info"), &OcctlSurfaces::bspline_create_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("create_bspline", "graph", "out_id", "info"), &OcctlSurfaces::create_bspline, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("bezier_create_info_init", "info"), &OcctlSurfaces::bezier_create_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("create_bezier", "graph", "out_id", "info"), &OcctlSurfaces::create_bezier, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("create_bezier_grid", "graph", "out_id", "info"), &OcctlSurfaces::create_bezier_grid, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("reverse", "graph", "surface_id", "out_id"), &OcctlSurfaces::reverse);
    godot::ClassDB::bind_method(godot::D_METHOD("transformed", "graph", "surface_id", "transform", "out_id"), &OcctlSurfaces::transformed);
    godot::ClassDB::bind_method(godot::D_METHOD("translated", "graph", "surface_id", "delta", "out_id"), &OcctlSurfaces::translated);
    godot::ClassDB::bind_method(godot::D_METHOD("rotated", "graph", "surface_id", "axis", "angle", "out_id"), &OcctlSurfaces::rotated);
    godot::ClassDB::bind_method(godot::D_METHOD("scaled", "graph", "surface_id", "origin", "factor", "out_id"), &OcctlSurfaces::scaled);
    godot::ClassDB::bind_method(godot::D_METHOD("area", "graph", "surface_id", "out_area"), &OcctlSurfaces::area);
    godot::ClassDB::bind_method(godot::D_METHOD("project_point", "graph", "surface_id", "point", "out_u", "out_v", "out_distance"), &OcctlSurfaces::project_point);
    godot::ClassDB::bind_method(godot::D_METHOD("uv_of_point", "graph", "surface_id", "point", "out_u", "out_v"), &OcctlSurfaces::uv_of_point);
    godot::ClassDB::bind_method(godot::D_METHOD("kind", "graph", "surface_id", "out_kind"), &OcctlSurfaces::kind);
    godot::ClassDB::bind_method(godot::D_METHOD("is_u_periodic", "graph", "surface_id", "out_is_periodic"), &OcctlSurfaces::is_u_periodic);
    godot::ClassDB::bind_method(godot::D_METHOD("is_v_periodic", "graph", "surface_id", "out_is_periodic"), &OcctlSurfaces::is_v_periodic);
    godot::ClassDB::bind_method(godot::D_METHOD("is_closed", "graph", "surface_id", "out_is_closed"), &OcctlSurfaces::is_closed);
    godot::ClassDB::bind_method(godot::D_METHOD("is_periodic", "graph", "surface_id", "out_is_periodic"), &OcctlSurfaces::is_periodic);
    godot::ClassDB::bind_method(godot::D_METHOD("continuity", "graph", "surface_id", "out_continuity"), &OcctlSurfaces::continuity);
    godot::ClassDB::bind_method(godot::D_METHOD("parameter_range", "graph", "surface_id", "out_u_min", "out_u_max", "out_v_min", "out_v_max"), &OcctlSurfaces::parameter_range);
    godot::ClassDB::bind_method(godot::D_METHOD("as_plane", "graph", "surface_id", "out_plane"), &OcctlSurfaces::as_plane);
    godot::ClassDB::bind_method(godot::D_METHOD("as_cylinder", "graph", "surface_id", "out_cylinder"), &OcctlSurfaces::as_cylinder);
    godot::ClassDB::bind_method(godot::D_METHOD("as_cone", "graph", "surface_id", "out_cone"), &OcctlSurfaces::as_cone);
    godot::ClassDB::bind_method(godot::D_METHOD("as_sphere", "graph", "surface_id", "out_sphere"), &OcctlSurfaces::as_sphere);
    godot::ClassDB::bind_method(godot::D_METHOD("as_torus", "graph", "surface_id", "out_torus"), &OcctlSurfaces::as_torus);
    godot::ClassDB::bind_method(godot::D_METHOD("as_revolution", "graph", "surface_id", "out_axis"), &OcctlSurfaces::as_revolution);
    godot::ClassDB::bind_method(godot::D_METHOD("as_extrusion", "graph", "surface_id", "out_direction"), &OcctlSurfaces::as_extrusion);
    godot::ClassDB::bind_method(godot::D_METHOD("as_rectangular_trimmed", "graph", "surface_id", "out_u_first", "out_u_last", "out_v_first", "out_v_last"), &OcctlSurfaces::as_rectangular_trimmed);
    godot::ClassDB::bind_method(godot::D_METHOD("as_offset", "graph", "surface_id", "out_offset"), &OcctlSurfaces::as_offset);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_u_degree", "graph", "surface_id", "out_degree"), &OcctlSurfaces::bspline_u_degree);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_v_degree", "graph", "surface_id", "out_degree"), &OcctlSurfaces::bspline_v_degree);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_u_pole_count", "graph", "surface_id", "out_count"), &OcctlSurfaces::bspline_u_pole_count);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_v_pole_count", "graph", "surface_id", "out_count"), &OcctlSurfaces::bspline_v_pole_count);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_is_rational", "graph", "surface_id", "out_is_rational"), &OcctlSurfaces::bspline_is_rational);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_u_knot_count", "graph", "surface_id", "out_count"), &OcctlSurfaces::bspline_u_knot_count);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_v_knot_count", "graph", "surface_id", "out_count"), &OcctlSurfaces::bspline_v_knot_count);
    godot::ClassDB::bind_method(godot::D_METHOD("bezier_u_degree", "graph", "surface_id", "out_degree"), &OcctlSurfaces::bezier_u_degree);
    godot::ClassDB::bind_method(godot::D_METHOD("bezier_v_degree", "graph", "surface_id", "out_degree"), &OcctlSurfaces::bezier_v_degree);
    godot::ClassDB::bind_method(godot::D_METHOD("bezier_u_pole_count", "graph", "surface_id", "out_count"), &OcctlSurfaces::bezier_u_pole_count);
    godot::ClassDB::bind_method(godot::D_METHOD("bezier_v_pole_count", "graph", "surface_id", "out_count"), &OcctlSurfaces::bezier_v_pole_count);
    godot::ClassDB::bind_method(godot::D_METHOD("bezier_is_rational", "graph", "surface_id", "out_is_rational"), &OcctlSurfaces::bezier_is_rational);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_poles", "graph", "surface_id"), &OcctlSurfaces::bspline_poles);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_u_knots", "graph", "surface_id"), &OcctlSurfaces::bspline_u_knots);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_v_knots", "graph", "surface_id"), &OcctlSurfaces::bspline_v_knots);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_u_multiplicities", "graph", "surface_id"), &OcctlSurfaces::bspline_u_multiplicities);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_v_multiplicities", "graph", "surface_id"), &OcctlSurfaces::bspline_v_multiplicities);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_weights", "graph", "surface_id"), &OcctlSurfaces::bspline_weights);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_u_flat_knots", "graph", "surface_id"), &OcctlSurfaces::bspline_u_flat_knots);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_v_flat_knots", "graph", "surface_id"), &OcctlSurfaces::bspline_v_flat_knots);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_poles_view", "graph", "surface_id", "out_u_count", "out_v_count"), &OcctlSurfaces::bspline_poles_view);
    godot::ClassDB::bind_method(godot::D_METHOD("bspline_init", "out"), &OcctlSurfaces::bspline_init);
    godot::ClassDB::bind_method(godot::D_METHOD("as_bspline", "graph", "surface_id", "out"), &OcctlSurfaces::as_bspline);
    godot::ClassDB::bind_method(godot::D_METHOD("eval_d0", "graph", "surface_id", "u", "v", "out_point"), &OcctlSurfaces::eval_d0);
    godot::ClassDB::bind_method(godot::D_METHOD("eval_d1", "graph", "surface_id", "u", "v", "out_point", "out_d1u", "out_d1v"), &OcctlSurfaces::eval_d1);
    godot::ClassDB::bind_method(godot::D_METHOD("eval_d2", "graph", "surface_id", "u", "v", "out_point", "out_d1u", "out_d1v", "out_d2u", "out_d2v", "out_d2uv"), &OcctlSurfaces::eval_d2);
    godot::ClassDB::bind_method(godot::D_METHOD("eval_d3", "graph", "surface_id", "u", "v", "out_point", "out_d1u", "out_d1v", "out_d2u", "out_d2v", "out_d2uv", "out_d3u", "out_d3v", "out_d3uuv", "out_d3uvv"), &OcctlSurfaces::eval_d3);
    godot::ClassDB::bind_method(godot::D_METHOD("eval_dn", "graph", "surface_id", "u", "v", "nu", "nv", "out_derivative"), &OcctlSurfaces::eval_dn);
    godot::ClassDB::bind_method(godot::D_METHOD("interpolated_info_init", "info"), &OcctlSurfaces::interpolated_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("create_interpolated", "graph", "info", "out_id"), &OcctlSurfaces::create_interpolated, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("approximated_info_init", "info"), &OcctlSurfaces::approximated_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("create_approximated", "graph", "info", "out_id"), &OcctlSurfaces::create_approximated, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("point_grid_create_info_init", "info"), &OcctlSurfaces::point_grid_create_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("create_from_point_grid", "graph", "out_id", "info"), &OcctlSurfaces::create_from_point_grid, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("boundary_curves_create_info_init", "info"), &OcctlSurfaces::boundary_curves_create_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("create_from_boundary_curves", "graph", "out_id", "info"), &OcctlSurfaces::create_from_boundary_curves, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("gordon_create_info_init", "info"), &OcctlSurfaces::gordon_create_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("create_gordon", "graph", "out_id", "info"), &OcctlSurfaces::create_gordon, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("curve_grid_create_info_init", "info"), &OcctlSurfaces::curve_grid_create_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("create_from_curve_grid", "graph", "out_id", "info"), &OcctlSurfaces::create_from_curve_grid, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("intersect_curve", "graph", "surface_id", "curve_id"), &OcctlSurfaces::intersect_curve);
    godot::ClassDB::bind_method(godot::D_METHOD("surface_intersect", "graph", "surface_a", "surface_b", "tolerance", "out_count"), &OcctlSurfaces::surface_intersect);
}

int OcctlSurfaces::create_plane(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlGeomPlane>& plane) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_surface_create_plane(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_id_val, plane->to_c());
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::create_cylinder(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlGeomCylindricalSurface>& cylinder) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_surface_create_cylinder(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_id_val, cylinder->to_c());
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::create_cone(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlGeomConicalSurface>& cone) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_surface_create_cone(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_id_val, cone->to_c());
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::create_sphere(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlGeomSphericalSurface>& sphere) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_surface_create_sphere(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_id_val, sphere->to_c());
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::create_torus(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlGeomToroidalSurface>& torus) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_surface_create_torus(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_id_val, torus->to_c());
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

void OcctlSurfaces::revolution_create_info_init(const Ref<OcctlSurfaceRevolutionCreateInfo>& info) { // NOLINT
    occtl_surface_revolution_create_info_t _info_val = {};
    ::occtl_surface_revolution_create_info_init(&_info_val);
    ::occtl_surface_revolution_create_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlSurfaces::create_revolution(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlSurfaceRevolutionCreateInfo>& info) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_surface_revolution_create_info_t _info_c = {};
    const occtl_surface_revolution_create_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_status_t _status = ::occtl_surface_create_revolution(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_id_val, _info_ptr);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

void OcctlSurfaces::extrusion_create_info_init(const Ref<OcctlSurfaceExtrusionCreateInfo>& info) { // NOLINT
    occtl_surface_extrusion_create_info_t _info_val = {};
    ::occtl_surface_extrusion_create_info_init(&_info_val);
    ::occtl_surface_extrusion_create_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlSurfaces::create_extrusion(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlSurfaceExtrusionCreateInfo>& info) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_surface_extrusion_create_info_t _info_c = {};
    const occtl_surface_extrusion_create_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_status_t _status = ::occtl_surface_create_extrusion(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_id_val, _info_ptr);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

void OcctlSurfaces::rectangular_trimmed_create_info_init(const Ref<OcctlSurfaceRectangularTrimmedCreateInfo>& info) { // NOLINT
    occtl_surface_rectangular_trimmed_create_info_t _info_val = {};
    ::occtl_surface_rectangular_trimmed_create_info_init(&_info_val);
    ::occtl_surface_rectangular_trimmed_create_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlSurfaces::create_rectangular_trimmed(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlSurfaceRectangularTrimmedCreateInfo>& info) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_surface_rectangular_trimmed_create_info_t _info_c = {};
    const occtl_surface_rectangular_trimmed_create_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_status_t _status = ::occtl_surface_create_rectangular_trimmed(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_id_val, _info_ptr);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

void OcctlSurfaces::offset_create_info_init(const Ref<OcctlSurfaceOffsetCreateInfo>& info) { // NOLINT
    occtl_surface_offset_create_info_t _info_val = {};
    ::occtl_surface_offset_create_info_init(&_info_val);
    ::occtl_surface_offset_create_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlSurfaces::create_offset(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlSurfaceOffsetCreateInfo>& info) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_surface_offset_create_info_t _info_c = {};
    const occtl_surface_offset_create_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_status_t _status = ::occtl_surface_create_offset(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_id_val, _info_ptr);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

void OcctlSurfaces::bspline_create_info_init(const Ref<OcctlSurfaceBsplineCreateInfo>& info) { // NOLINT
    occtl_surface_bspline_create_info_t _info_val = {};
    ::occtl_surface_bspline_create_info_init(&_info_val);
    ::occtl_surface_bspline_create_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlSurfaces::create_bspline(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlSurfaceBsplineCreateInfo>& info) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_surface_bspline_create_info_t _info_c = {};
    const occtl_surface_bspline_create_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_status_t _status = ::occtl_surface_create_bspline(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_id_val, _info_ptr);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

void OcctlSurfaces::bezier_create_info_init(const Ref<OcctlSurfaceBezierCreateInfo>& info) { // NOLINT
    occtl_surface_bezier_create_info_t _info_val = {};
    ::occtl_surface_bezier_create_info_init(&_info_val);
    ::occtl_surface_bezier_create_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlSurfaces::create_bezier(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlSurfaceBezierCreateInfo>& info) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_surface_bezier_create_info_t _info_c = {};
    const occtl_surface_bezier_create_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_status_t _status = ::occtl_surface_create_bezier(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_id_val, _info_ptr);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::create_bezier_grid(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlSurfaceBezierCreateInfo>& info) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_surface_bezier_create_info_t _info_c = {};
    const occtl_surface_bezier_create_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_status_t _status = ::occtl_surface_create_bezier_grid(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_id_val, _info_ptr);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::reverse(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_surface_reverse(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::transformed(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlTransform>& transform, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_surface_transformed(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, transform->to_c(), &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::translated(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlVector3>& delta, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_surface_translated(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, delta->to_c(), &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::rotated(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlAxis1Placement>& axis, double angle, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_surface_rotated(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, axis->to_c(), angle, &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::scaled(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlPoint3>& origin, double factor, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_surface_scaled(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, origin->to_c(), factor, &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::area(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlDouble>& out_area) { // NOLINT
    double _out_area_val = {};
    occtl_status_t _status = ::occtl_surface_area(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_area_val);
    if (out_area.is_valid()) out_area->copy_from_c(_out_area_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::project_point(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlPoint3>& point, const Ref<OcctlDouble>& out_u, const Ref<OcctlDouble>& out_v, const Ref<OcctlDouble>& out_distance) { // NOLINT
    double _out_u_val = {};
    double _out_v_val = {};
    double _out_distance_val = {};
    occtl_status_t _status = ::occtl_surface_project_point(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, point->to_c(), &_out_u_val, &_out_v_val, &_out_distance_val);
    if (out_u.is_valid()) out_u->copy_from_c(_out_u_val);
    if (out_v.is_valid()) out_v->copy_from_c(_out_v_val);
    if (out_distance.is_valid()) out_distance->copy_from_c(_out_distance_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::uv_of_point(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlPoint3>& point, const Ref<OcctlDouble>& out_u, const Ref<OcctlDouble>& out_v) { // NOLINT
    double _out_u_val = {};
    double _out_v_val = {};
    occtl_status_t _status = ::occtl_surface_uv_of_point(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, point->to_c(), &_out_u_val, &_out_v_val);
    if (out_u.is_valid()) out_u->copy_from_c(_out_u_val);
    if (out_v.is_valid()) out_v->copy_from_c(_out_v_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::kind(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlInt32>& out_kind) { // NOLINT
    occtl_surface_kind_t _out_kind_val = {};
    occtl_status_t _status = ::occtl_surface_kind(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_kind_val);
    if (out_kind.is_valid()) out_kind->copy_from_c(_out_kind_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::is_u_periodic(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlInt32>& out_is_periodic) { // NOLINT
    int32_t _out_is_periodic_val = {};
    occtl_status_t _status = ::occtl_surface_is_u_periodic(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_is_periodic_val);
    if (out_is_periodic.is_valid()) out_is_periodic->copy_from_c(_out_is_periodic_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::is_v_periodic(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlInt32>& out_is_periodic) { // NOLINT
    int32_t _out_is_periodic_val = {};
    occtl_status_t _status = ::occtl_surface_is_v_periodic(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_is_periodic_val);
    if (out_is_periodic.is_valid()) out_is_periodic->copy_from_c(_out_is_periodic_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::is_closed(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlInt32>& out_is_closed) { // NOLINT
    int32_t _out_is_closed_val = {};
    occtl_status_t _status = ::occtl_surface_is_closed(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_is_closed_val);
    if (out_is_closed.is_valid()) out_is_closed->copy_from_c(_out_is_closed_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::is_periodic(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlInt32>& out_is_periodic) { // NOLINT
    int32_t _out_is_periodic_val = {};
    occtl_status_t _status = ::occtl_surface_is_periodic(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_is_periodic_val);
    if (out_is_periodic.is_valid()) out_is_periodic->copy_from_c(_out_is_periodic_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::continuity(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlInt32>& out_continuity) { // NOLINT
    occtl_geom_continuity_t _out_continuity_val = {};
    occtl_status_t _status = ::occtl_surface_continuity(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_continuity_val);
    if (out_continuity.is_valid()) out_continuity->copy_from_c(_out_continuity_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::parameter_range(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlDouble>& out_u_min, const Ref<OcctlDouble>& out_u_max, const Ref<OcctlDouble>& out_v_min, const Ref<OcctlDouble>& out_v_max) { // NOLINT
    double _out_u_min_val = {};
    double _out_u_max_val = {};
    double _out_v_min_val = {};
    double _out_v_max_val = {};
    occtl_status_t _status = ::occtl_surface_parameter_range(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_u_min_val, &_out_u_max_val, &_out_v_min_val, &_out_v_max_val);
    if (out_u_min.is_valid()) out_u_min->copy_from_c(_out_u_min_val);
    if (out_u_max.is_valid()) out_u_max->copy_from_c(_out_u_max_val);
    if (out_v_min.is_valid()) out_v_min->copy_from_c(_out_v_min_val);
    if (out_v_max.is_valid()) out_v_max->copy_from_c(_out_v_max_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::as_plane(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlGeomPlane>& out_plane) { // NOLINT
    occtl_geom_plane_t _out_plane_val = {};
    occtl_status_t _status = ::occtl_surface_as_plane(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_plane_val);
    if (out_plane.is_valid()) out_plane->copy_from_c(_out_plane_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::as_cylinder(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlGeomCylindricalSurface>& out_cylinder) { // NOLINT
    occtl_geom_cylindrical_surface_t _out_cylinder_val = {};
    occtl_status_t _status = ::occtl_surface_as_cylinder(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_cylinder_val);
    if (out_cylinder.is_valid()) out_cylinder->copy_from_c(_out_cylinder_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::as_cone(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlGeomConicalSurface>& out_cone) { // NOLINT
    occtl_geom_conical_surface_t _out_cone_val = {};
    occtl_status_t _status = ::occtl_surface_as_cone(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_cone_val);
    if (out_cone.is_valid()) out_cone->copy_from_c(_out_cone_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::as_sphere(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlGeomSphericalSurface>& out_sphere) { // NOLINT
    occtl_geom_spherical_surface_t _out_sphere_val = {};
    occtl_status_t _status = ::occtl_surface_as_sphere(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_sphere_val);
    if (out_sphere.is_valid()) out_sphere->copy_from_c(_out_sphere_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::as_torus(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlGeomToroidalSurface>& out_torus) { // NOLINT
    occtl_geom_toroidal_surface_t _out_torus_val = {};
    occtl_status_t _status = ::occtl_surface_as_torus(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_torus_val);
    if (out_torus.is_valid()) out_torus->copy_from_c(_out_torus_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::as_revolution(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlAxis1Placement>& out_axis) { // NOLINT
    occtl_axis1_placement_t _out_axis_val = {};
    occtl_status_t _status = ::occtl_surface_as_revolution(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_axis_val);
    if (out_axis.is_valid()) out_axis->copy_from_c(_out_axis_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::as_extrusion(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlVector3>& out_direction) { // NOLINT
    occtl_vector3_t _out_direction_val = {};
    occtl_status_t _status = ::occtl_surface_as_extrusion(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_direction_val);
    if (out_direction.is_valid()) out_direction->copy_from_c(_out_direction_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::as_rectangular_trimmed(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlDouble>& out_u_first, const Ref<OcctlDouble>& out_u_last, const Ref<OcctlDouble>& out_v_first, const Ref<OcctlDouble>& out_v_last) { // NOLINT
    double _out_u_first_val = {};
    double _out_u_last_val = {};
    double _out_v_first_val = {};
    double _out_v_last_val = {};
    occtl_status_t _status = ::occtl_surface_as_rectangular_trimmed(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_u_first_val, &_out_u_last_val, &_out_v_first_val, &_out_v_last_val);
    if (out_u_first.is_valid()) out_u_first->copy_from_c(_out_u_first_val);
    if (out_u_last.is_valid()) out_u_last->copy_from_c(_out_u_last_val);
    if (out_v_first.is_valid()) out_v_first->copy_from_c(_out_v_first_val);
    if (out_v_last.is_valid()) out_v_last->copy_from_c(_out_v_last_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::as_offset(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlDouble>& out_offset) { // NOLINT
    double _out_offset_val = {};
    occtl_status_t _status = ::occtl_surface_as_offset(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_offset_val);
    if (out_offset.is_valid()) out_offset->copy_from_c(_out_offset_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::bspline_u_degree(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlInt32>& out_degree) { // NOLINT
    int32_t _out_degree_val = {};
    occtl_status_t _status = ::occtl_surface_bspline_u_degree(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_degree_val);
    if (out_degree.is_valid()) out_degree->copy_from_c(_out_degree_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::bspline_v_degree(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlInt32>& out_degree) { // NOLINT
    int32_t _out_degree_val = {};
    occtl_status_t _status = ::occtl_surface_bspline_v_degree(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_degree_val);
    if (out_degree.is_valid()) out_degree->copy_from_c(_out_degree_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::bspline_u_pole_count(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlSize>& out_count) { // NOLINT
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_surface_bspline_u_pole_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::bspline_v_pole_count(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlSize>& out_count) { // NOLINT
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_surface_bspline_v_pole_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::bspline_is_rational(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlInt32>& out_is_rational) { // NOLINT
    int32_t _out_is_rational_val = {};
    occtl_status_t _status = ::occtl_surface_bspline_is_rational(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_is_rational_val);
    if (out_is_rational.is_valid()) out_is_rational->copy_from_c(_out_is_rational_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::bspline_u_knot_count(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlSize>& out_count) { // NOLINT
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_surface_bspline_u_knot_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::bspline_v_knot_count(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlSize>& out_count) { // NOLINT
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_surface_bspline_v_knot_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::bezier_u_degree(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlInt32>& out_degree) { // NOLINT
    int32_t _out_degree_val = {};
    occtl_status_t _status = ::occtl_surface_bezier_u_degree(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_degree_val);
    if (out_degree.is_valid()) out_degree->copy_from_c(_out_degree_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::bezier_v_degree(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlInt32>& out_degree) { // NOLINT
    int32_t _out_degree_val = {};
    occtl_status_t _status = ::occtl_surface_bezier_v_degree(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_degree_val);
    if (out_degree.is_valid()) out_degree->copy_from_c(_out_degree_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::bezier_u_pole_count(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlSize>& out_count) { // NOLINT
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_surface_bezier_u_pole_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::bezier_v_pole_count(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlSize>& out_count) { // NOLINT
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_surface_bezier_v_pole_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::bezier_is_rational(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlInt32>& out_is_rational) { // NOLINT
    int32_t _out_is_rational_val = {};
    occtl_status_t _status = ::occtl_surface_bezier_is_rational(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_is_rational_val);
    if (out_is_rational.is_valid()) out_is_rational->copy_from_c(_out_is_rational_val);
    return static_cast<int>(_status);
}

Array OcctlSurfaces::bspline_poles(const Ref<OcctlGraphHandle>& graph, int64_t surface_id) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_surface_bspline_poles(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return Array(); }
    std::vector<occtl_point3_t> _out_buf_buf(static_cast<size_t>(_out_count_cnt));
    _err = ::occtl_surface_bspline_poles(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
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

PackedFloat64Array OcctlSurfaces::bspline_u_knots(const Ref<OcctlGraphHandle>& graph, int64_t surface_id) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_surface_bspline_u_knots(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedFloat64Array(); }
    std::vector<double> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_surface_bspline_u_knots(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedFloat64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = _out_buf_buf[_i];
    return _result;
}

PackedFloat64Array OcctlSurfaces::bspline_v_knots(const Ref<OcctlGraphHandle>& graph, int64_t surface_id) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_surface_bspline_v_knots(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedFloat64Array(); }
    std::vector<double> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_surface_bspline_v_knots(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedFloat64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = _out_buf_buf[_i];
    return _result;
}

PackedInt32Array OcctlSurfaces::bspline_u_multiplicities(const Ref<OcctlGraphHandle>& graph, int64_t surface_id) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_surface_bspline_u_multiplicities(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt32Array(); }
    std::vector<int32_t> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_surface_bspline_u_multiplicities(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt32Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = _out_buf_buf[_i];
    return _result;
}

PackedInt32Array OcctlSurfaces::bspline_v_multiplicities(const Ref<OcctlGraphHandle>& graph, int64_t surface_id) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_surface_bspline_v_multiplicities(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt32Array(); }
    std::vector<int32_t> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_surface_bspline_v_multiplicities(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt32Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = _out_buf_buf[_i];
    return _result;
}

PackedFloat64Array OcctlSurfaces::bspline_weights(const Ref<OcctlGraphHandle>& graph, int64_t surface_id) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_surface_bspline_weights(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedFloat64Array(); }
    std::vector<double> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_surface_bspline_weights(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedFloat64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = _out_buf_buf[_i];
    return _result;
}

PackedFloat64Array OcctlSurfaces::bspline_u_flat_knots(const Ref<OcctlGraphHandle>& graph, int64_t surface_id) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_surface_bspline_u_flat_knots(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedFloat64Array(); }
    std::vector<double> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_surface_bspline_u_flat_knots(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedFloat64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = _out_buf_buf[_i];
    return _result;
}

PackedFloat64Array OcctlSurfaces::bspline_v_flat_knots(const Ref<OcctlGraphHandle>& graph, int64_t surface_id) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_surface_bspline_v_flat_knots(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedFloat64Array(); }
    std::vector<double> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_surface_bspline_v_flat_knots(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedFloat64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = _out_buf_buf[_i];
    return _result;
}

int OcctlSurfaces::bspline_poles_view(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlSize>& out_u_count, const Ref<OcctlSize>& out_v_count) { // NOLINT
    const occtl_point3_t* _out_data_val = nullptr;
    size_t _out_u_count_val = {};
    size_t _out_v_count_val = {};
    occtl_status_t _status = ::occtl_surface_bspline_poles_view(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_data_val, &_out_u_count_val, &_out_v_count_val);
    if (out_u_count.is_valid()) out_u_count->copy_from_c(_out_u_count_val);
    if (out_v_count.is_valid()) out_v_count->copy_from_c(_out_v_count_val);
    return static_cast<int>(_status);
}

void OcctlSurfaces::bspline_init(const Ref<OcctlSurfaceBspline>& out) { // NOLINT
    occtl_surface_bspline_t _out_val = {};
    ::occtl_surface_bspline_init(&_out_val);
    ::occtl_surface_bspline_init(&_out_val);
    if (out.is_valid()) out->copy_from_c(_out_val);
}

int OcctlSurfaces::as_bspline(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, const Ref<OcctlSurfaceBspline>& out) { // NOLINT
    occtl_surface_bspline_t _out_val = {};
    ::occtl_surface_bspline_init(&_out_val);
    occtl_status_t _status = ::occtl_surface_as_bspline(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, &_out_val);
    if (out.is_valid()) out->copy_from_c(_out_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::eval_d0(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, double u, double v, const Ref<OcctlPoint3>& out_point) { // NOLINT
    occtl_point3_t _out_point_val = {};
    occtl_status_t _status = ::occtl_surface_eval_d0(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, u, v, &_out_point_val);
    if (out_point.is_valid()) out_point->copy_from_c(_out_point_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::eval_d1(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, double u, double v, const Ref<OcctlPoint3>& out_point, const Ref<OcctlVector3>& out_d1u, const Ref<OcctlVector3>& out_d1v) { // NOLINT
    occtl_point3_t _out_point_val = {};
    occtl_vector3_t _out_d1u_val = {};
    occtl_vector3_t _out_d1v_val = {};
    occtl_status_t _status = ::occtl_surface_eval_d1(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, u, v, &_out_point_val, &_out_d1u_val, &_out_d1v_val);
    if (out_point.is_valid()) out_point->copy_from_c(_out_point_val);
    if (out_d1u.is_valid()) out_d1u->copy_from_c(_out_d1u_val);
    if (out_d1v.is_valid()) out_d1v->copy_from_c(_out_d1v_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::eval_d2(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, double u, double v, const Ref<OcctlPoint3>& out_point, const Ref<OcctlVector3>& out_d1u, const Ref<OcctlVector3>& out_d1v, const Ref<OcctlVector3>& out_d2u, const Ref<OcctlVector3>& out_d2v, const Ref<OcctlVector3>& out_d2uv) { // NOLINT
    occtl_point3_t _out_point_val = {};
    occtl_vector3_t _out_d1u_val = {};
    occtl_vector3_t _out_d1v_val = {};
    occtl_vector3_t _out_d2u_val = {};
    occtl_vector3_t _out_d2v_val = {};
    occtl_vector3_t _out_d2uv_val = {};
    occtl_status_t _status = ::occtl_surface_eval_d2(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, u, v, &_out_point_val, &_out_d1u_val, &_out_d1v_val, &_out_d2u_val, &_out_d2v_val, &_out_d2uv_val);
    if (out_point.is_valid()) out_point->copy_from_c(_out_point_val);
    if (out_d1u.is_valid()) out_d1u->copy_from_c(_out_d1u_val);
    if (out_d1v.is_valid()) out_d1v->copy_from_c(_out_d1v_val);
    if (out_d2u.is_valid()) out_d2u->copy_from_c(_out_d2u_val);
    if (out_d2v.is_valid()) out_d2v->copy_from_c(_out_d2v_val);
    if (out_d2uv.is_valid()) out_d2uv->copy_from_c(_out_d2uv_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::eval_d3(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, double u, double v, const Ref<OcctlPoint3>& out_point, const Ref<OcctlVector3>& out_d1u, const Ref<OcctlVector3>& out_d1v, const Ref<OcctlVector3>& out_d2u, const Ref<OcctlVector3>& out_d2v, const Ref<OcctlVector3>& out_d2uv, const Ref<OcctlVector3>& out_d3u, const Ref<OcctlVector3>& out_d3v, const Ref<OcctlVector3>& out_d3uuv, const Ref<OcctlVector3>& out_d3uvv) { // NOLINT
    occtl_point3_t _out_point_val = {};
    occtl_vector3_t _out_d1u_val = {};
    occtl_vector3_t _out_d1v_val = {};
    occtl_vector3_t _out_d2u_val = {};
    occtl_vector3_t _out_d2v_val = {};
    occtl_vector3_t _out_d2uv_val = {};
    occtl_vector3_t _out_d3u_val = {};
    occtl_vector3_t _out_d3v_val = {};
    occtl_vector3_t _out_d3uuv_val = {};
    occtl_vector3_t _out_d3uvv_val = {};
    occtl_status_t _status = ::occtl_surface_eval_d3(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, u, v, &_out_point_val, &_out_d1u_val, &_out_d1v_val, &_out_d2u_val, &_out_d2v_val, &_out_d2uv_val, &_out_d3u_val, &_out_d3v_val, &_out_d3uuv_val, &_out_d3uvv_val);
    if (out_point.is_valid()) out_point->copy_from_c(_out_point_val);
    if (out_d1u.is_valid()) out_d1u->copy_from_c(_out_d1u_val);
    if (out_d1v.is_valid()) out_d1v->copy_from_c(_out_d1v_val);
    if (out_d2u.is_valid()) out_d2u->copy_from_c(_out_d2u_val);
    if (out_d2v.is_valid()) out_d2v->copy_from_c(_out_d2v_val);
    if (out_d2uv.is_valid()) out_d2uv->copy_from_c(_out_d2uv_val);
    if (out_d3u.is_valid()) out_d3u->copy_from_c(_out_d3u_val);
    if (out_d3v.is_valid()) out_d3v->copy_from_c(_out_d3v_val);
    if (out_d3uuv.is_valid()) out_d3uuv->copy_from_c(_out_d3uuv_val);
    if (out_d3uvv.is_valid()) out_d3uvv->copy_from_c(_out_d3uvv_val);
    return static_cast<int>(_status);
}

int OcctlSurfaces::eval_dn(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, double u, double v, int nu, int nv, const Ref<OcctlVector3>& out_derivative) { // NOLINT
    occtl_vector3_t _out_derivative_val = {};
    occtl_status_t _status = ::occtl_surface_eval_dn(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, u, v, nu, nv, &_out_derivative_val);
    if (out_derivative.is_valid()) out_derivative->copy_from_c(_out_derivative_val);
    return static_cast<int>(_status);
}

void OcctlSurfaces::interpolated_info_init(const Ref<OcctlSurfaceInterpolatedInfo>& info) { // NOLINT
    occtl_surface_interpolated_info_t _info_val = {};
    ::occtl_surface_interpolated_info_init(&_info_val);
    ::occtl_surface_interpolated_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlSurfaces::create_interpolated(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSurfaceInterpolatedInfo>& info, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_surface_interpolated_info_t _info_c = {};
    const occtl_surface_interpolated_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_surface_create_interpolated(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

void OcctlSurfaces::approximated_info_init(const Ref<OcctlSurfaceApproximatedInfo>& info) { // NOLINT
    occtl_surface_approximated_info_t _info_val = {};
    ::occtl_surface_approximated_info_init(&_info_val);
    ::occtl_surface_approximated_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlSurfaces::create_approximated(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSurfaceApproximatedInfo>& info, const Ref<OcctlRepId>& out_id) { // NOLINT
    occtl_surface_approximated_info_t _info_c = {};
    const occtl_surface_approximated_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_rep_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_surface_create_approximated(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

void OcctlSurfaces::point_grid_create_info_init(const Ref<OcctlSurfacePointGridCreateInfo>& info) { // NOLINT
    occtl_surface_point_grid_create_info_t _info_val = {};
    ::occtl_surface_point_grid_create_info_init(&_info_val);
    ::occtl_surface_point_grid_create_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlSurfaces::create_from_point_grid(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlSurfacePointGridCreateInfo>& info) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_surface_point_grid_create_info_t _info_c = {};
    const occtl_surface_point_grid_create_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_status_t _status = ::occtl_surface_create_from_point_grid(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_id_val, _info_ptr);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

void OcctlSurfaces::boundary_curves_create_info_init(const Ref<OcctlSurfaceBoundaryCurvesCreateInfo>& info) { // NOLINT
    occtl_surface_boundary_curves_create_info_t _info_val = {};
    ::occtl_surface_boundary_curves_create_info_init(&_info_val);
    ::occtl_surface_boundary_curves_create_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlSurfaces::create_from_boundary_curves(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlSurfaceBoundaryCurvesCreateInfo>& info) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_surface_boundary_curves_create_info_t _info_c = {};
    const occtl_surface_boundary_curves_create_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_status_t _status = ::occtl_surface_create_from_boundary_curves(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_id_val, _info_ptr);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

void OcctlSurfaces::gordon_create_info_init(const Ref<OcctlSurfaceGordonCreateInfo>& info) { // NOLINT
    occtl_surface_gordon_create_info_t _info_val = {};
    ::occtl_surface_gordon_create_info_init(&_info_val);
    ::occtl_surface_gordon_create_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlSurfaces::create_gordon(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlSurfaceGordonCreateInfo>& info) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_surface_gordon_create_info_t _info_c = {};
    const occtl_surface_gordon_create_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_status_t _status = ::occtl_surface_create_gordon(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_id_val, _info_ptr);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

void OcctlSurfaces::curve_grid_create_info_init(const Ref<OcctlSurfaceCurveGridCreateInfo>& info) { // NOLINT
    occtl_surface_curve_grid_create_info_t _info_val = {};
    ::occtl_surface_curve_grid_create_info_init(&_info_val);
    ::occtl_surface_curve_grid_create_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlSurfaces::create_from_curve_grid(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlRepId>& out_id, const Ref<OcctlSurfaceCurveGridCreateInfo>& info) { // NOLINT
    occtl_rep_id_t _out_id_val = {};
    occtl_surface_curve_grid_create_info_t _info_c = {};
    const occtl_surface_curve_grid_create_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_status_t _status = ::occtl_surface_create_from_curve_grid(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_id_val, _info_ptr);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

Array OcctlSurfaces::intersect_curve(const Ref<OcctlGraphHandle>& graph, int64_t surface_id, int64_t curve_id) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_surface_intersect_curve(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return Array(); }
    std::vector<occtl_point3_t> _out_buf_buf(static_cast<size_t>(_out_count_cnt));
    _err = ::occtl_surface_intersect_curve(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_id)}, occtl_rep_id_t{static_cast<uint64_t>(curve_id)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
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

int OcctlSurfaces::surface_intersect(const Ref<OcctlGraphHandle>& graph, int64_t surface_a, int64_t surface_b, double tolerance, const Ref<OcctlSize>& out_count) { // NOLINT
    occtl_rep_id_t* _out_ids_val = nullptr;
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_surface_surface_intersect(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(surface_a)}, occtl_rep_id_t{static_cast<uint64_t>(surface_b)}, tolerance, &_out_ids_val, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    if (_status != OCCTL_OK) { return 0; }
    return static_cast<int64_t>(_out_ids_val->bits);
}
