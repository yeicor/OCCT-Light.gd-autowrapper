#include "OcctlMeshTrianglePlaneComponentsOptions.h"

#include "OcctlNodeId.h"

int OcctlMeshTrianglePlaneComponentsOptions::get_struct_version() const { return struct_version; }
void OcctlMeshTrianglePlaneComponentsOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlMeshTrianglePlaneComponentsOptions::get_p_next() const { return p_next; }
void OcctlMeshTrianglePlaneComponentsOptions::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlMeshTrianglePlaneComponentsOptions::get_root() const { return root; }
void OcctlMeshTrianglePlaneComponentsOptions::set_root(int64_t val) { root = val; }

double OcctlMeshTrianglePlaneComponentsOptions::get_max_normal_angle() const { return max_normal_angle; }
void OcctlMeshTrianglePlaneComponentsOptions::set_max_normal_angle(double val) { max_normal_angle = val; }

int OcctlMeshTrianglePlaneComponentsOptions::get_include_opposite_normals() const { return include_opposite_normals; }
void OcctlMeshTrianglePlaneComponentsOptions::set_include_opposite_normals(int val) { include_opposite_normals = val; }

double OcctlMeshTrianglePlaneComponentsOptions::get_max_distance() const { return max_distance; }
void OcctlMeshTrianglePlaneComponentsOptions::set_max_distance(double val) { max_distance = val; }

double OcctlMeshTrianglePlaneComponentsOptions::get_min_area() const { return min_area; }
void OcctlMeshTrianglePlaneComponentsOptions::set_min_area(double val) { min_area = val; }

int OcctlMeshTrianglePlaneComponentsOptions::get_min_triangle_count() const { return min_triangle_count; }
void OcctlMeshTrianglePlaneComponentsOptions::set_min_triangle_count(int val) { min_triangle_count = val; }

void OcctlMeshTrianglePlaneComponentsOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlMeshTrianglePlaneComponentsOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlMeshTrianglePlaneComponentsOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlMeshTrianglePlaneComponentsOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlMeshTrianglePlaneComponentsOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_root"), &OcctlMeshTrianglePlaneComponentsOptions::get_root);
    godot::ClassDB::bind_method(godot::D_METHOD("set_root", "val"), &OcctlMeshTrianglePlaneComponentsOptions::set_root);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "root"), "set_root", "get_root");
    godot::ClassDB::bind_method(godot::D_METHOD("get_max_normal_angle"), &OcctlMeshTrianglePlaneComponentsOptions::get_max_normal_angle);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max_normal_angle", "val"), &OcctlMeshTrianglePlaneComponentsOptions::set_max_normal_angle);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max_normal_angle"), "set_max_normal_angle", "get_max_normal_angle");
    godot::ClassDB::bind_method(godot::D_METHOD("get_include_opposite_normals"), &OcctlMeshTrianglePlaneComponentsOptions::get_include_opposite_normals);
    godot::ClassDB::bind_method(godot::D_METHOD("set_include_opposite_normals", "val"), &OcctlMeshTrianglePlaneComponentsOptions::set_include_opposite_normals);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "include_opposite_normals"), "set_include_opposite_normals", "get_include_opposite_normals");
    godot::ClassDB::bind_method(godot::D_METHOD("get_max_distance"), &OcctlMeshTrianglePlaneComponentsOptions::get_max_distance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max_distance", "val"), &OcctlMeshTrianglePlaneComponentsOptions::set_max_distance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max_distance"), "set_max_distance", "get_max_distance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_min_area"), &OcctlMeshTrianglePlaneComponentsOptions::get_min_area);
    godot::ClassDB::bind_method(godot::D_METHOD("set_min_area", "val"), &OcctlMeshTrianglePlaneComponentsOptions::set_min_area);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "min_area"), "set_min_area", "get_min_area");
    godot::ClassDB::bind_method(godot::D_METHOD("get_min_triangle_count"), &OcctlMeshTrianglePlaneComponentsOptions::get_min_triangle_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_min_triangle_count", "val"), &OcctlMeshTrianglePlaneComponentsOptions::set_min_triangle_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "min_triangle_count"), "set_min_triangle_count", "get_min_triangle_count");
}

occtl_mesh_triangle_plane_components_options_t OcctlMeshTrianglePlaneComponentsOptions::to_c() const {
    occtl_mesh_triangle_plane_components_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.root.bits = static_cast<uint64_t>(root);
    result.max_normal_angle = max_normal_angle;
    result.include_opposite_normals = include_opposite_normals;
    result.max_distance = max_distance;
    result.min_area = min_area;
    result.min_triangle_count = min_triangle_count;
    return result;
}

Ref<OcctlMeshTrianglePlaneComponentsOptions> OcctlMeshTrianglePlaneComponentsOptions::from_c(const occtl_mesh_triangle_plane_components_options_t& val) {
    Ref<OcctlMeshTrianglePlaneComponentsOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->root = static_cast<int64_t>(val.root.bits);
    r->max_normal_angle = val.max_normal_angle;
    r->include_opposite_normals = val.include_opposite_normals;
    r->max_distance = val.max_distance;
    r->min_area = val.min_area;
    r->min_triangle_count = val.min_triangle_count;
    return r;
}

void OcctlMeshTrianglePlaneComponentsOptions::copy_from_c(const occtl_mesh_triangle_plane_components_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    root = static_cast<int64_t>(val.root.bits);
    max_normal_angle = val.max_normal_angle;
    include_opposite_normals = val.include_opposite_normals;
    max_distance = val.max_distance;
    min_area = val.min_area;
    min_triangle_count = val.min_triangle_count;
}
