#include "OcctlMeshTriangleComponentsOptions.h"

#include "OcctlNodeId.h"

int OcctlMeshTriangleComponentsOptions::get_struct_version() const { return struct_version; }
void OcctlMeshTriangleComponentsOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlMeshTriangleComponentsOptions::get_p_next() const { return p_next; }
void OcctlMeshTriangleComponentsOptions::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlMeshTriangleComponentsOptions::get_root() const { return root; }
void OcctlMeshTriangleComponentsOptions::set_root(int64_t val) { root = val; }

double OcctlMeshTriangleComponentsOptions::get_max_normal_angle() const { return max_normal_angle; }
void OcctlMeshTriangleComponentsOptions::set_max_normal_angle(double val) { max_normal_angle = val; }

int OcctlMeshTriangleComponentsOptions::get_include_opposite_normals() const { return include_opposite_normals; }
void OcctlMeshTriangleComponentsOptions::set_include_opposite_normals(int val) { include_opposite_normals = val; }

void OcctlMeshTriangleComponentsOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlMeshTriangleComponentsOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlMeshTriangleComponentsOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlMeshTriangleComponentsOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlMeshTriangleComponentsOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_root"), &OcctlMeshTriangleComponentsOptions::get_root);
    godot::ClassDB::bind_method(godot::D_METHOD("set_root", "val"), &OcctlMeshTriangleComponentsOptions::set_root);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "root"), "set_root", "get_root");
    godot::ClassDB::bind_method(godot::D_METHOD("get_max_normal_angle"), &OcctlMeshTriangleComponentsOptions::get_max_normal_angle);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max_normal_angle", "val"), &OcctlMeshTriangleComponentsOptions::set_max_normal_angle);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max_normal_angle"), "set_max_normal_angle", "get_max_normal_angle");
    godot::ClassDB::bind_method(godot::D_METHOD("get_include_opposite_normals"), &OcctlMeshTriangleComponentsOptions::get_include_opposite_normals);
    godot::ClassDB::bind_method(godot::D_METHOD("set_include_opposite_normals", "val"), &OcctlMeshTriangleComponentsOptions::set_include_opposite_normals);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "include_opposite_normals"), "set_include_opposite_normals", "get_include_opposite_normals");
}

occtl_mesh_triangle_components_options_t OcctlMeshTriangleComponentsOptions::to_c() const {
    occtl_mesh_triangle_components_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.root.bits = static_cast<uint64_t>(root);
    result.max_normal_angle = max_normal_angle;
    result.include_opposite_normals = include_opposite_normals;
    return result;
}

Ref<OcctlMeshTriangleComponentsOptions> OcctlMeshTriangleComponentsOptions::from_c(const occtl_mesh_triangle_components_options_t& val) {
    Ref<OcctlMeshTriangleComponentsOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->root = static_cast<int64_t>(val.root.bits);
    r->max_normal_angle = val.max_normal_angle;
    r->include_opposite_normals = val.include_opposite_normals;
    return r;
}

void OcctlMeshTriangleComponentsOptions::copy_from_c(const occtl_mesh_triangle_components_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    root = static_cast<int64_t>(val.root.bits);
    max_normal_angle = val.max_normal_angle;
    include_opposite_normals = val.include_opposite_normals;
}
