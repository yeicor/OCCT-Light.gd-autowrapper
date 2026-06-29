#include "OcctlPrimFillet2dInfo.h"

#include "OcctlNodeId.h"

int OcctlPrimFillet2dInfo::get_struct_version() const { return struct_version; }
void OcctlPrimFillet2dInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimFillet2dInfo::get_p_next() const { return p_next; }
void OcctlPrimFillet2dInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlPrimFillet2dInfo::get_face() const { return face; }
void OcctlPrimFillet2dInfo::set_face(int64_t val) { face = val; }

PackedInt64Array OcctlPrimFillet2dInfo::get_vertices() const { return vertices; }
void OcctlPrimFillet2dInfo::set_vertices(PackedInt64Array val) { vertices = val; }

int OcctlPrimFillet2dInfo::get_vertex_count() const { return vertex_count; }
void OcctlPrimFillet2dInfo::set_vertex_count(int val) { vertex_count = val; }

double OcctlPrimFillet2dInfo::get_radius() const { return radius; }
void OcctlPrimFillet2dInfo::set_radius(double val) { radius = val; }

void OcctlPrimFillet2dInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimFillet2dInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimFillet2dInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimFillet2dInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimFillet2dInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_face"), &OcctlPrimFillet2dInfo::get_face);
    godot::ClassDB::bind_method(godot::D_METHOD("set_face", "val"), &OcctlPrimFillet2dInfo::set_face);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "face"), "set_face", "get_face");
    godot::ClassDB::bind_method(godot::D_METHOD("get_vertices"), &OcctlPrimFillet2dInfo::get_vertices);
    godot::ClassDB::bind_method(godot::D_METHOD("set_vertices", "val"), &OcctlPrimFillet2dInfo::set_vertices);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "vertices"), "set_vertices", "get_vertices");
    godot::ClassDB::bind_method(godot::D_METHOD("get_vertex_count"), &OcctlPrimFillet2dInfo::get_vertex_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_vertex_count", "val"), &OcctlPrimFillet2dInfo::set_vertex_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "vertex_count"), "set_vertex_count", "get_vertex_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_radius"), &OcctlPrimFillet2dInfo::get_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_radius", "val"), &OcctlPrimFillet2dInfo::set_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "radius"), "set_radius", "get_radius");
}

occtl_prim_fillet_2d_info_t OcctlPrimFillet2dInfo::to_c() const {
    occtl_prim_fillet_2d_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.face.bits = static_cast<uint64_t>(face);
    result.vertices = reinterpret_cast<const occtl_node_id_t*>(vertices.ptr());
    result.vertex_count = vertex_count;
    result.radius = radius;
    return result;
}

Ref<OcctlPrimFillet2dInfo> OcctlPrimFillet2dInfo::from_c(const occtl_prim_fillet_2d_info_t& val) {
    Ref<OcctlPrimFillet2dInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->face = static_cast<int64_t>(val.face.bits);
    // array field vertices is not populated from C
    r->vertex_count = val.vertex_count;
    r->radius = val.radius;
    return r;
}

void OcctlPrimFillet2dInfo::copy_from_c(const occtl_prim_fillet_2d_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    face = static_cast<int64_t>(val.face.bits);
    // array field vertices is not populated from C
    vertex_count = val.vertex_count;
    radius = val.radius;
}
