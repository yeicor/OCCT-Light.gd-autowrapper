#include "OcctlTopoFillingOptions.h"


int OcctlTopoFillingOptions::get_struct_version() const { return struct_version; }
void OcctlTopoFillingOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoFillingOptions::get_p_next() const { return p_next; }
void OcctlTopoFillingOptions::set_p_next(int64_t val) { p_next = val; }

PackedInt64Array OcctlTopoFillingOptions::get_edges() const { return edges; }
void OcctlTopoFillingOptions::set_edges(PackedInt64Array val) { edges = val; }

int OcctlTopoFillingOptions::get_edge_count() const { return edge_count; }
void OcctlTopoFillingOptions::set_edge_count(int val) { edge_count = val; }

int OcctlTopoFillingOptions::get_continuity() const { return continuity; }
void OcctlTopoFillingOptions::set_continuity(int val) { continuity = val; }

int OcctlTopoFillingOptions::get_degree() const { return degree; }
void OcctlTopoFillingOptions::set_degree(int val) { degree = val; }

int OcctlTopoFillingOptions::get_point_count_on_curve() const { return point_count_on_curve; }
void OcctlTopoFillingOptions::set_point_count_on_curve(int val) { point_count_on_curve = val; }

int OcctlTopoFillingOptions::get_iteration_count() const { return iteration_count; }
void OcctlTopoFillingOptions::set_iteration_count(int val) { iteration_count = val; }

int OcctlTopoFillingOptions::get_anisotropic() const { return anisotropic; }
void OcctlTopoFillingOptions::set_anisotropic(int val) { anisotropic = val; }

double OcctlTopoFillingOptions::get_tolerance_2d() const { return tolerance_2d; }
void OcctlTopoFillingOptions::set_tolerance_2d(double val) { tolerance_2d = val; }

double OcctlTopoFillingOptions::get_tolerance_3d() const { return tolerance_3d; }
void OcctlTopoFillingOptions::set_tolerance_3d(double val) { tolerance_3d = val; }

double OcctlTopoFillingOptions::get_angular_tolerance() const { return angular_tolerance; }
void OcctlTopoFillingOptions::set_angular_tolerance(double val) { angular_tolerance = val; }

double OcctlTopoFillingOptions::get_curvature_tolerance() const { return curvature_tolerance; }
void OcctlTopoFillingOptions::set_curvature_tolerance(double val) { curvature_tolerance = val; }

int OcctlTopoFillingOptions::get_max_degree() const { return max_degree; }
void OcctlTopoFillingOptions::set_max_degree(int val) { max_degree = val; }

int OcctlTopoFillingOptions::get_max_segments() const { return max_segments; }
void OcctlTopoFillingOptions::set_max_segments(int val) { max_segments = val; }

void OcctlTopoFillingOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoFillingOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoFillingOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoFillingOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoFillingOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_edges"), &OcctlTopoFillingOptions::get_edges);
    godot::ClassDB::bind_method(godot::D_METHOD("set_edges", "val"), &OcctlTopoFillingOptions::set_edges);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "edges"), "set_edges", "get_edges");
    godot::ClassDB::bind_method(godot::D_METHOD("get_edge_count"), &OcctlTopoFillingOptions::get_edge_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_edge_count", "val"), &OcctlTopoFillingOptions::set_edge_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "edge_count"), "set_edge_count", "get_edge_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_continuity"), &OcctlTopoFillingOptions::get_continuity);
    godot::ClassDB::bind_method(godot::D_METHOD("set_continuity", "val"), &OcctlTopoFillingOptions::set_continuity);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "continuity"), "set_continuity", "get_continuity");
    godot::ClassDB::bind_method(godot::D_METHOD("get_degree"), &OcctlTopoFillingOptions::get_degree);
    godot::ClassDB::bind_method(godot::D_METHOD("set_degree", "val"), &OcctlTopoFillingOptions::set_degree);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "degree"), "set_degree", "get_degree");
    godot::ClassDB::bind_method(godot::D_METHOD("get_point_count_on_curve"), &OcctlTopoFillingOptions::get_point_count_on_curve);
    godot::ClassDB::bind_method(godot::D_METHOD("set_point_count_on_curve", "val"), &OcctlTopoFillingOptions::set_point_count_on_curve);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "point_count_on_curve"), "set_point_count_on_curve", "get_point_count_on_curve");
    godot::ClassDB::bind_method(godot::D_METHOD("get_iteration_count"), &OcctlTopoFillingOptions::get_iteration_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_iteration_count", "val"), &OcctlTopoFillingOptions::set_iteration_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "iteration_count"), "set_iteration_count", "get_iteration_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_anisotropic"), &OcctlTopoFillingOptions::get_anisotropic);
    godot::ClassDB::bind_method(godot::D_METHOD("set_anisotropic", "val"), &OcctlTopoFillingOptions::set_anisotropic);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "anisotropic"), "set_anisotropic", "get_anisotropic");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance_2d"), &OcctlTopoFillingOptions::get_tolerance_2d);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance_2d", "val"), &OcctlTopoFillingOptions::set_tolerance_2d);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance_2d"), "set_tolerance_2d", "get_tolerance_2d");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance_3d"), &OcctlTopoFillingOptions::get_tolerance_3d);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance_3d", "val"), &OcctlTopoFillingOptions::set_tolerance_3d);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance_3d"), "set_tolerance_3d", "get_tolerance_3d");
    godot::ClassDB::bind_method(godot::D_METHOD("get_angular_tolerance"), &OcctlTopoFillingOptions::get_angular_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_angular_tolerance", "val"), &OcctlTopoFillingOptions::set_angular_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "angular_tolerance"), "set_angular_tolerance", "get_angular_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_curvature_tolerance"), &OcctlTopoFillingOptions::get_curvature_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_curvature_tolerance", "val"), &OcctlTopoFillingOptions::set_curvature_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "curvature_tolerance"), "set_curvature_tolerance", "get_curvature_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_max_degree"), &OcctlTopoFillingOptions::get_max_degree);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max_degree", "val"), &OcctlTopoFillingOptions::set_max_degree);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "max_degree"), "set_max_degree", "get_max_degree");
    godot::ClassDB::bind_method(godot::D_METHOD("get_max_segments"), &OcctlTopoFillingOptions::get_max_segments);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max_segments", "val"), &OcctlTopoFillingOptions::set_max_segments);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "max_segments"), "set_max_segments", "get_max_segments");
}

occtl_topo_filling_options_t OcctlTopoFillingOptions::to_c() const {
    occtl_topo_filling_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.edges = reinterpret_cast<const occtl_node_id_t*>(edges.ptr());
    result.edge_count = edge_count;
    result.continuity = static_cast<occtl_topo_filling_continuity_t>(continuity);
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

Ref<OcctlTopoFillingOptions> OcctlTopoFillingOptions::from_c(const occtl_topo_filling_options_t& val) {
    Ref<OcctlTopoFillingOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field edges is not populated from C
    r->edge_count = val.edge_count;
    r->continuity = static_cast<int>(val.continuity);
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

void OcctlTopoFillingOptions::copy_from_c(const occtl_topo_filling_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field edges is not populated from C
    edge_count = val.edge_count;
    continuity = static_cast<int>(val.continuity);
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
