#include "OcctlMeshTriangleSphereComponentsOptions.h"

#include "OcctlNodeId.h"

int OcctlMeshTriangleSphereComponentsOptions::get_struct_version() const { return struct_version; }
void OcctlMeshTriangleSphereComponentsOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlMeshTriangleSphereComponentsOptions::get_p_next() const { return p_next; }
void OcctlMeshTriangleSphereComponentsOptions::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlMeshTriangleSphereComponentsOptions::get_root() const { return root; }
void OcctlMeshTriangleSphereComponentsOptions::set_root(int64_t val) { root = val; }

double OcctlMeshTriangleSphereComponentsOptions::get_max_normal_angle() const { return max_normal_angle; }
void OcctlMeshTriangleSphereComponentsOptions::set_max_normal_angle(double val) { max_normal_angle = val; }

int OcctlMeshTriangleSphereComponentsOptions::get_include_opposite_normals() const { return include_opposite_normals; }
void OcctlMeshTriangleSphereComponentsOptions::set_include_opposite_normals(int val) { include_opposite_normals = val; }

double OcctlMeshTriangleSphereComponentsOptions::get_max_distance() const { return max_distance; }
void OcctlMeshTriangleSphereComponentsOptions::set_max_distance(double val) { max_distance = val; }

double OcctlMeshTriangleSphereComponentsOptions::get_min_area() const { return min_area; }
void OcctlMeshTriangleSphereComponentsOptions::set_min_area(double val) { min_area = val; }

int OcctlMeshTriangleSphereComponentsOptions::get_min_triangle_count() const { return min_triangle_count; }
void OcctlMeshTriangleSphereComponentsOptions::set_min_triangle_count(int val) { min_triangle_count = val; }

double OcctlMeshTriangleSphereComponentsOptions::get_min_radius() const { return min_radius; }
void OcctlMeshTriangleSphereComponentsOptions::set_min_radius(double val) { min_radius = val; }

void OcctlMeshTriangleSphereComponentsOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlMeshTriangleSphereComponentsOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlMeshTriangleSphereComponentsOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlMeshTriangleSphereComponentsOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlMeshTriangleSphereComponentsOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_root"), &OcctlMeshTriangleSphereComponentsOptions::get_root);
    godot::ClassDB::bind_method(godot::D_METHOD("set_root", "val"), &OcctlMeshTriangleSphereComponentsOptions::set_root);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "root"), "set_root", "get_root");
    godot::ClassDB::bind_method(godot::D_METHOD("get_max_normal_angle"), &OcctlMeshTriangleSphereComponentsOptions::get_max_normal_angle);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max_normal_angle", "val"), &OcctlMeshTriangleSphereComponentsOptions::set_max_normal_angle);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max_normal_angle"), "set_max_normal_angle", "get_max_normal_angle");
    godot::ClassDB::bind_method(godot::D_METHOD("get_include_opposite_normals"), &OcctlMeshTriangleSphereComponentsOptions::get_include_opposite_normals);
    godot::ClassDB::bind_method(godot::D_METHOD("set_include_opposite_normals", "val"), &OcctlMeshTriangleSphereComponentsOptions::set_include_opposite_normals);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "include_opposite_normals"), "set_include_opposite_normals", "get_include_opposite_normals");
    godot::ClassDB::bind_method(godot::D_METHOD("get_max_distance"), &OcctlMeshTriangleSphereComponentsOptions::get_max_distance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max_distance", "val"), &OcctlMeshTriangleSphereComponentsOptions::set_max_distance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max_distance"), "set_max_distance", "get_max_distance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_min_area"), &OcctlMeshTriangleSphereComponentsOptions::get_min_area);
    godot::ClassDB::bind_method(godot::D_METHOD("set_min_area", "val"), &OcctlMeshTriangleSphereComponentsOptions::set_min_area);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "min_area"), "set_min_area", "get_min_area");
    godot::ClassDB::bind_method(godot::D_METHOD("get_min_triangle_count"), &OcctlMeshTriangleSphereComponentsOptions::get_min_triangle_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_min_triangle_count", "val"), &OcctlMeshTriangleSphereComponentsOptions::set_min_triangle_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "min_triangle_count"), "set_min_triangle_count", "get_min_triangle_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_min_radius"), &OcctlMeshTriangleSphereComponentsOptions::get_min_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_min_radius", "val"), &OcctlMeshTriangleSphereComponentsOptions::set_min_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "min_radius"), "set_min_radius", "get_min_radius");
}

occtl_mesh_triangle_sphere_components_options_t OcctlMeshTriangleSphereComponentsOptions::to_c() const {
    occtl_mesh_triangle_sphere_components_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.root.bits = static_cast<uint64_t>(root);
    result.max_normal_angle = max_normal_angle;
    result.include_opposite_normals = include_opposite_normals;
    result.max_distance = max_distance;
    result.min_area = min_area;
    result.min_triangle_count = min_triangle_count;
    result.min_radius = min_radius;
    return result;
}

Ref<OcctlMeshTriangleSphereComponentsOptions> OcctlMeshTriangleSphereComponentsOptions::from_c(const occtl_mesh_triangle_sphere_components_options_t& val) {
    Ref<OcctlMeshTriangleSphereComponentsOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->root = static_cast<int64_t>(val.root.bits);
    r->max_normal_angle = val.max_normal_angle;
    r->include_opposite_normals = val.include_opposite_normals;
    r->max_distance = val.max_distance;
    r->min_area = val.min_area;
    r->min_triangle_count = val.min_triangle_count;
    r->min_radius = val.min_radius;
    return r;
}

void OcctlMeshTriangleSphereComponentsOptions::copy_from_c(const occtl_mesh_triangle_sphere_components_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    root = static_cast<int64_t>(val.root.bits);
    max_normal_angle = val.max_normal_angle;
    include_opposite_normals = val.include_opposite_normals;
    max_distance = val.max_distance;
    min_area = val.min_area;
    min_triangle_count = val.min_triangle_count;
    min_radius = val.min_radius;
}
