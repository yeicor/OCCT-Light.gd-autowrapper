#include "OcctlTopoFillingPatchOptions.h"


int OcctlTopoFillingPatchOptions::get_struct_version() const { return struct_version; }
void OcctlTopoFillingPatchOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoFillingPatchOptions::get_p_next() const { return p_next; }
void OcctlTopoFillingPatchOptions::set_p_next(int64_t val) { p_next = val; }

Array OcctlTopoFillingPatchOptions::get_edges() const { return edges; }
void OcctlTopoFillingPatchOptions::set_edges(Array val) { edges = val; }

int OcctlTopoFillingPatchOptions::get_edge_count() const { return edge_count; }
void OcctlTopoFillingPatchOptions::set_edge_count(int val) { edge_count = val; }

Array OcctlTopoFillingPatchOptions::get_points() const { return points; }
void OcctlTopoFillingPatchOptions::set_points(Array val) { points = val; }

int OcctlTopoFillingPatchOptions::get_point_count() const { return point_count; }
void OcctlTopoFillingPatchOptions::set_point_count(int val) { point_count = val; }

int OcctlTopoFillingPatchOptions::get_degree() const { return degree; }
void OcctlTopoFillingPatchOptions::set_degree(int val) { degree = val; }

int OcctlTopoFillingPatchOptions::get_point_count_on_curve() const { return point_count_on_curve; }
void OcctlTopoFillingPatchOptions::set_point_count_on_curve(int val) { point_count_on_curve = val; }

int OcctlTopoFillingPatchOptions::get_iteration_count() const { return iteration_count; }
void OcctlTopoFillingPatchOptions::set_iteration_count(int val) { iteration_count = val; }

int OcctlTopoFillingPatchOptions::get_anisotropic() const { return anisotropic; }
void OcctlTopoFillingPatchOptions::set_anisotropic(int val) { anisotropic = val; }

double OcctlTopoFillingPatchOptions::get_tolerance_2d() const { return tolerance_2d; }
void OcctlTopoFillingPatchOptions::set_tolerance_2d(double val) { tolerance_2d = val; }

double OcctlTopoFillingPatchOptions::get_tolerance_3d() const { return tolerance_3d; }
void OcctlTopoFillingPatchOptions::set_tolerance_3d(double val) { tolerance_3d = val; }

double OcctlTopoFillingPatchOptions::get_angular_tolerance() const { return angular_tolerance; }
void OcctlTopoFillingPatchOptions::set_angular_tolerance(double val) { angular_tolerance = val; }

double OcctlTopoFillingPatchOptions::get_curvature_tolerance() const { return curvature_tolerance; }
void OcctlTopoFillingPatchOptions::set_curvature_tolerance(double val) { curvature_tolerance = val; }

int OcctlTopoFillingPatchOptions::get_max_degree() const { return max_degree; }
void OcctlTopoFillingPatchOptions::set_max_degree(int val) { max_degree = val; }

int OcctlTopoFillingPatchOptions::get_max_segments() const { return max_segments; }
void OcctlTopoFillingPatchOptions::set_max_segments(int val) { max_segments = val; }

void OcctlTopoFillingPatchOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoFillingPatchOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoFillingPatchOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoFillingPatchOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoFillingPatchOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_edges"), &OcctlTopoFillingPatchOptions::get_edges);
    godot::ClassDB::bind_method(godot::D_METHOD("set_edges", "val"), &OcctlTopoFillingPatchOptions::set_edges);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "edges"), "set_edges", "get_edges");
    godot::ClassDB::bind_method(godot::D_METHOD("get_edge_count"), &OcctlTopoFillingPatchOptions::get_edge_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_edge_count", "val"), &OcctlTopoFillingPatchOptions::set_edge_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "edge_count"), "set_edge_count", "get_edge_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_points"), &OcctlTopoFillingPatchOptions::get_points);
    godot::ClassDB::bind_method(godot::D_METHOD("set_points", "val"), &OcctlTopoFillingPatchOptions::set_points);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "points"), "set_points", "get_points");
    godot::ClassDB::bind_method(godot::D_METHOD("get_point_count"), &OcctlTopoFillingPatchOptions::get_point_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_point_count", "val"), &OcctlTopoFillingPatchOptions::set_point_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "point_count"), "set_point_count", "get_point_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_degree"), &OcctlTopoFillingPatchOptions::get_degree);
    godot::ClassDB::bind_method(godot::D_METHOD("set_degree", "val"), &OcctlTopoFillingPatchOptions::set_degree);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "degree"), "set_degree", "get_degree");
    godot::ClassDB::bind_method(godot::D_METHOD("get_point_count_on_curve"), &OcctlTopoFillingPatchOptions::get_point_count_on_curve);
    godot::ClassDB::bind_method(godot::D_METHOD("set_point_count_on_curve", "val"), &OcctlTopoFillingPatchOptions::set_point_count_on_curve);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "point_count_on_curve"), "set_point_count_on_curve", "get_point_count_on_curve");
    godot::ClassDB::bind_method(godot::D_METHOD("get_iteration_count"), &OcctlTopoFillingPatchOptions::get_iteration_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_iteration_count", "val"), &OcctlTopoFillingPatchOptions::set_iteration_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "iteration_count"), "set_iteration_count", "get_iteration_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_anisotropic"), &OcctlTopoFillingPatchOptions::get_anisotropic);
    godot::ClassDB::bind_method(godot::D_METHOD("set_anisotropic", "val"), &OcctlTopoFillingPatchOptions::set_anisotropic);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "anisotropic"), "set_anisotropic", "get_anisotropic");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance_2d"), &OcctlTopoFillingPatchOptions::get_tolerance_2d);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance_2d", "val"), &OcctlTopoFillingPatchOptions::set_tolerance_2d);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance_2d"), "set_tolerance_2d", "get_tolerance_2d");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance_3d"), &OcctlTopoFillingPatchOptions::get_tolerance_3d);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance_3d", "val"), &OcctlTopoFillingPatchOptions::set_tolerance_3d);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance_3d"), "set_tolerance_3d", "get_tolerance_3d");
    godot::ClassDB::bind_method(godot::D_METHOD("get_angular_tolerance"), &OcctlTopoFillingPatchOptions::get_angular_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_angular_tolerance", "val"), &OcctlTopoFillingPatchOptions::set_angular_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "angular_tolerance"), "set_angular_tolerance", "get_angular_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_curvature_tolerance"), &OcctlTopoFillingPatchOptions::get_curvature_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_curvature_tolerance", "val"), &OcctlTopoFillingPatchOptions::set_curvature_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "curvature_tolerance"), "set_curvature_tolerance", "get_curvature_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_max_degree"), &OcctlTopoFillingPatchOptions::get_max_degree);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max_degree", "val"), &OcctlTopoFillingPatchOptions::set_max_degree);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "max_degree"), "set_max_degree", "get_max_degree");
    godot::ClassDB::bind_method(godot::D_METHOD("get_max_segments"), &OcctlTopoFillingPatchOptions::get_max_segments);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max_segments", "val"), &OcctlTopoFillingPatchOptions::set_max_segments);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "max_segments"), "set_max_segments", "get_max_segments");
}

occtl_topo_filling_patch_options_t OcctlTopoFillingPatchOptions::to_c() const {
    occtl_topo_filling_patch_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    _cache_edges.resize(edges.size());
    for (int _i = 0; _i < edges.size(); _i++) {
        Ref<OcctlTopoFillingPatchEdge> _item = edges[_i];
        if (_item.is_valid()) _cache_edges[_i] = _item->to_c();
        else _cache_edges[_i] = {};
    }
    result.edges = _cache_edges.data();
    result.edge_count = edge_count;
    _cache_points.resize(points.size());
    for (int _i = 0; _i < points.size(); _i++) {
        Ref<OcctlPoint3> _item = points[_i];
        if (_item.is_valid()) _cache_points[_i] = _item->to_c();
        else _cache_points[_i] = {};
    }
    result.points = _cache_points.data();
    result.point_count = point_count;
    result.degree = degree;
    result.point_count_on_curve = point_count_on_curve;
    result.iteration_count = iteration_count;
    result.anisotropic = anisotropic;
    result.tolerance_2d = tolerance_2d;
    result.tolerance_3d = tolerance_3d;
    result.angular_tolerance = angular_tolerance;
    result.curvature_tolerance = curvature_tolerance;
    result.max_degree = max_degree;
    result.max_segments = max_segments;
    return result;
}

Ref<OcctlTopoFillingPatchOptions> OcctlTopoFillingPatchOptions::from_c(const occtl_topo_filling_patch_options_t& val) {
    Ref<OcctlTopoFillingPatchOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field edges is not populated from C
    r->edge_count = val.edge_count;
    // array field points is not populated from C
    r->point_count = val.point_count;
    r->degree = val.degree;
    r->point_count_on_curve = val.point_count_on_curve;
    r->iteration_count = val.iteration_count;
    r->anisotropic = val.anisotropic;
    r->tolerance_2d = val.tolerance_2d;
    r->tolerance_3d = val.tolerance_3d;
    r->angular_tolerance = val.angular_tolerance;
    r->curvature_tolerance = val.curvature_tolerance;
    r->max_degree = val.max_degree;
    r->max_segments = val.max_segments;
    return r;
}

void OcctlTopoFillingPatchOptions::copy_from_c(const occtl_topo_filling_patch_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field edges is not populated from C
    edge_count = val.edge_count;
    // array field points is not populated from C
    point_count = val.point_count;
    degree = val.degree;
    point_count_on_curve = val.point_count_on_curve;
    iteration_count = val.iteration_count;
    anisotropic = val.anisotropic;
    tolerance_2d = val.tolerance_2d;
    tolerance_3d = val.tolerance_3d;
    angular_tolerance = val.angular_tolerance;
    curvature_tolerance = val.curvature_tolerance;
    max_degree = val.max_degree;
    max_segments = val.max_segments;
}
