#include "OcctlTopoFaceChamfer2dOptions.h"

#include "OcctlNodeId.h"

int OcctlTopoFaceChamfer2dOptions::get_struct_version() const { return struct_version; }
void OcctlTopoFaceChamfer2dOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoFaceChamfer2dOptions::get_p_next() const { return p_next; }
void OcctlTopoFaceChamfer2dOptions::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlTopoFaceChamfer2dOptions::get_face() const { return face; }
void OcctlTopoFaceChamfer2dOptions::set_face(int64_t val) { face = val; }

PackedInt64Array OcctlTopoFaceChamfer2dOptions::get_vertices() const { return vertices; }
void OcctlTopoFaceChamfer2dOptions::set_vertices(PackedInt64Array val) { vertices = val; }

int OcctlTopoFaceChamfer2dOptions::get_vertex_count() const { return vertex_count; }
void OcctlTopoFaceChamfer2dOptions::set_vertex_count(int val) { vertex_count = val; }

double OcctlTopoFaceChamfer2dOptions::get_distance1() const { return distance1; }
void OcctlTopoFaceChamfer2dOptions::set_distance1(double val) { distance1 = val; }

double OcctlTopoFaceChamfer2dOptions::get_distance2() const { return distance2; }
void OcctlTopoFaceChamfer2dOptions::set_distance2(double val) { distance2 = val; }

void OcctlTopoFaceChamfer2dOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoFaceChamfer2dOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoFaceChamfer2dOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoFaceChamfer2dOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoFaceChamfer2dOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_face"), &OcctlTopoFaceChamfer2dOptions::get_face);
    godot::ClassDB::bind_method(godot::D_METHOD("set_face", "val"), &OcctlTopoFaceChamfer2dOptions::set_face);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "face"), "set_face", "get_face");
    godot::ClassDB::bind_method(godot::D_METHOD("get_vertices"), &OcctlTopoFaceChamfer2dOptions::get_vertices);
    godot::ClassDB::bind_method(godot::D_METHOD("set_vertices", "val"), &OcctlTopoFaceChamfer2dOptions::set_vertices);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "vertices"), "set_vertices", "get_vertices");
    godot::ClassDB::bind_method(godot::D_METHOD("get_vertex_count"), &OcctlTopoFaceChamfer2dOptions::get_vertex_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_vertex_count", "val"), &OcctlTopoFaceChamfer2dOptions::set_vertex_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "vertex_count"), "set_vertex_count", "get_vertex_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_distance1"), &OcctlTopoFaceChamfer2dOptions::get_distance1);
    godot::ClassDB::bind_method(godot::D_METHOD("set_distance1", "val"), &OcctlTopoFaceChamfer2dOptions::set_distance1);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "distance1"), "set_distance1", "get_distance1");
    godot::ClassDB::bind_method(godot::D_METHOD("get_distance2"), &OcctlTopoFaceChamfer2dOptions::get_distance2);
    godot::ClassDB::bind_method(godot::D_METHOD("set_distance2", "val"), &OcctlTopoFaceChamfer2dOptions::set_distance2);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "distance2"), "set_distance2", "get_distance2");
}

occtl_topo_face_chamfer_2d_options_t OcctlTopoFaceChamfer2dOptions::to_c() const {
    occtl_topo_face_chamfer_2d_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.face.bits = static_cast<uint64_t>(face);
    result.vertices = reinterpret_cast<const occtl_node_id_t*>(vertices.ptr());
    result.vertex_count = vertex_count;
    result.distance1 = distance1;
    result.distance2 = distance2;
    return result;
}

Ref<OcctlTopoFaceChamfer2dOptions> OcctlTopoFaceChamfer2dOptions::from_c(const occtl_topo_face_chamfer_2d_options_t& val) {
    Ref<OcctlTopoFaceChamfer2dOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->face = static_cast<int64_t>(val.face.bits);
    // array field vertices is not populated from C
    r->vertex_count = val.vertex_count;
    r->distance1 = val.distance1;
    r->distance2 = val.distance2;
    return r;
}

void OcctlTopoFaceChamfer2dOptions::copy_from_c(const occtl_topo_face_chamfer_2d_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    face = static_cast<int64_t>(val.face.bits);
    // array field vertices is not populated from C
    vertex_count = val.vertex_count;
    distance1 = val.distance1;
    distance2 = val.distance2;
}
