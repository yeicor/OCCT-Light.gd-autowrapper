#include "OcctlMeshTriangleCylinderComponentsOptions.h"

#include "OcctlNodeId.h"

int OcctlMeshTriangleCylinderComponentsOptions::get_struct_version() const { return struct_version; }
void OcctlMeshTriangleCylinderComponentsOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlMeshTriangleCylinderComponentsOptions::get_p_next() const { return p_next; }
void OcctlMeshTriangleCylinderComponentsOptions::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlMeshTriangleCylinderComponentsOptions::get_root() const { return root; }
void OcctlMeshTriangleCylinderComponentsOptions::set_root(int64_t val) { root = val; }

double OcctlMeshTriangleCylinderComponentsOptions::get_max_normal_angle() const { return max_normal_angle; }
void OcctlMeshTriangleCylinderComponentsOptions::set_max_normal_angle(double val) { max_normal_angle = val; }

int OcctlMeshTriangleCylinderComponentsOptions::get_include_opposite_normals() const { return include_opposite_normals; }
void OcctlMeshTriangleCylinderComponentsOptions::set_include_opposite_normals(int val) { include_opposite_normals = val; }

double OcctlMeshTriangleCylinderComponentsOptions::get_max_distance() const { return max_distance; }
void OcctlMeshTriangleCylinderComponentsOptions::set_max_distance(double val) { max_distance = val; }

double OcctlMeshTriangleCylinderComponentsOptions::get_min_area() const { return min_area; }
void OcctlMeshTriangleCylinderComponentsOptions::set_min_area(double val) { min_area = val; }

int OcctlMeshTriangleCylinderComponentsOptions::get_min_triangle_count() const { return min_triangle_count; }
void OcctlMeshTriangleCylinderComponentsOptions::set_min_triangle_count(int val) { min_triangle_count = val; }

double OcctlMeshTriangleCylinderComponentsOptions::get_min_radius() const { return min_radius; }
void OcctlMeshTriangleCylinderComponentsOptions::set_min_radius(double val) { min_radius = val; }

void OcctlMeshTriangleCylinderComponentsOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlMeshTriangleCylinderComponentsOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlMeshTriangleCylinderComponentsOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlMeshTriangleCylinderComponentsOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlMeshTriangleCylinderComponentsOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_root"), &OcctlMeshTriangleCylinderComponentsOptions::get_root);
    godot::ClassDB::bind_method(godot::D_METHOD("set_root", "val"), &OcctlMeshTriangleCylinderComponentsOptions::set_root);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "root"), "set_root", "get_root");
    godot::ClassDB::bind_method(godot::D_METHOD("get_max_normal_angle"), &OcctlMeshTriangleCylinderComponentsOptions::get_max_normal_angle);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max_normal_angle", "val"), &OcctlMeshTriangleCylinderComponentsOptions::set_max_normal_angle);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max_normal_angle"), "set_max_normal_angle", "get_max_normal_angle");
    godot::ClassDB::bind_method(godot::D_METHOD("get_include_opposite_normals"), &OcctlMeshTriangleCylinderComponentsOptions::get_include_opposite_normals);
    godot::ClassDB::bind_method(godot::D_METHOD("set_include_opposite_normals", "val"), &OcctlMeshTriangleCylinderComponentsOptions::set_include_opposite_normals);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "include_opposite_normals"), "set_include_opposite_normals", "get_include_opposite_normals");
    godot::ClassDB::bind_method(godot::D_METHOD("get_max_distance"), &OcctlMeshTriangleCylinderComponentsOptions::get_max_distance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max_distance", "val"), &OcctlMeshTriangleCylinderComponentsOptions::set_max_distance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max_distance"), "set_max_distance", "get_max_distance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_min_area"), &OcctlMeshTriangleCylinderComponentsOptions::get_min_area);
    godot::ClassDB::bind_method(godot::D_METHOD("set_min_area", "val"), &OcctlMeshTriangleCylinderComponentsOptions::set_min_area);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "min_area"), "set_min_area", "get_min_area");
    godot::ClassDB::bind_method(godot::D_METHOD("get_min_triangle_count"), &OcctlMeshTriangleCylinderComponentsOptions::get_min_triangle_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_min_triangle_count", "val"), &OcctlMeshTriangleCylinderComponentsOptions::set_min_triangle_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "min_triangle_count"), "set_min_triangle_count", "get_min_triangle_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_min_radius"), &OcctlMeshTriangleCylinderComponentsOptions::get_min_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_min_radius", "val"), &OcctlMeshTriangleCylinderComponentsOptions::set_min_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "min_radius"), "set_min_radius", "get_min_radius");
}

occtl_mesh_triangle_cylinder_components_options_t OcctlMeshTriangleCylinderComponentsOptions::to_c() const {
    occtl_mesh_triangle_cylinder_components_options_t result = {};
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

Ref<OcctlMeshTriangleCylinderComponentsOptions> OcctlMeshTriangleCylinderComponentsOptions::from_c(const occtl_mesh_triangle_cylinder_components_options_t& val) {
    Ref<OcctlMeshTriangleCylinderComponentsOptions> r;
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

void OcctlMeshTriangleCylinderComponentsOptions::copy_from_c(const occtl_mesh_triangle_cylinder_components_options_t& val) {
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
