#include "OcctlTopoWireChamfer2dOptions.h"

#include "OcctlNodeId.h"

int OcctlTopoWireChamfer2dOptions::get_struct_version() const { return struct_version; }
void OcctlTopoWireChamfer2dOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoWireChamfer2dOptions::get_p_next() const { return p_next; }
void OcctlTopoWireChamfer2dOptions::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlTopoWireChamfer2dOptions::get_wire() const { return wire; }
void OcctlTopoWireChamfer2dOptions::set_wire(int64_t val) { wire = val; }

PackedInt64Array OcctlTopoWireChamfer2dOptions::get_vertices() const { return vertices; }
void OcctlTopoWireChamfer2dOptions::set_vertices(PackedInt64Array val) { vertices = val; }

int OcctlTopoWireChamfer2dOptions::get_vertex_count() const { return vertex_count; }
void OcctlTopoWireChamfer2dOptions::set_vertex_count(int val) { vertex_count = val; }

double OcctlTopoWireChamfer2dOptions::get_distance1() const { return distance1; }
void OcctlTopoWireChamfer2dOptions::set_distance1(double val) { distance1 = val; }

double OcctlTopoWireChamfer2dOptions::get_distance2() const { return distance2; }
void OcctlTopoWireChamfer2dOptions::set_distance2(double val) { distance2 = val; }

void OcctlTopoWireChamfer2dOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoWireChamfer2dOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoWireChamfer2dOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoWireChamfer2dOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoWireChamfer2dOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_wire"), &OcctlTopoWireChamfer2dOptions::get_wire);
    godot::ClassDB::bind_method(godot::D_METHOD("set_wire", "val"), &OcctlTopoWireChamfer2dOptions::set_wire);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "wire"), "set_wire", "get_wire");
    godot::ClassDB::bind_method(godot::D_METHOD("get_vertices"), &OcctlTopoWireChamfer2dOptions::get_vertices);
    godot::ClassDB::bind_method(godot::D_METHOD("set_vertices", "val"), &OcctlTopoWireChamfer2dOptions::set_vertices);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "vertices"), "set_vertices", "get_vertices");
    godot::ClassDB::bind_method(godot::D_METHOD("get_vertex_count"), &OcctlTopoWireChamfer2dOptions::get_vertex_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_vertex_count", "val"), &OcctlTopoWireChamfer2dOptions::set_vertex_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "vertex_count"), "set_vertex_count", "get_vertex_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_distance1"), &OcctlTopoWireChamfer2dOptions::get_distance1);
    godot::ClassDB::bind_method(godot::D_METHOD("set_distance1", "val"), &OcctlTopoWireChamfer2dOptions::set_distance1);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "distance1"), "set_distance1", "get_distance1");
    godot::ClassDB::bind_method(godot::D_METHOD("get_distance2"), &OcctlTopoWireChamfer2dOptions::get_distance2);
    godot::ClassDB::bind_method(godot::D_METHOD("set_distance2", "val"), &OcctlTopoWireChamfer2dOptions::set_distance2);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "distance2"), "set_distance2", "get_distance2");
}

occtl_topo_wire_chamfer_2d_options_t OcctlTopoWireChamfer2dOptions::to_c() const {
    occtl_topo_wire_chamfer_2d_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.wire.bits = static_cast<uint64_t>(wire);
    result.vertices = reinterpret_cast<const occtl_node_id_t*>(vertices.ptr());
    result.vertex_count = vertex_count;
    result.distance1 = distance1;
    result.distance2 = distance2;
    return result;
}

Ref<OcctlTopoWireChamfer2dOptions> OcctlTopoWireChamfer2dOptions::from_c(const occtl_topo_wire_chamfer_2d_options_t& val) {
    Ref<OcctlTopoWireChamfer2dOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->wire = static_cast<int64_t>(val.wire.bits);
    // array field vertices is not populated from C
    r->vertex_count = val.vertex_count;
    r->distance1 = val.distance1;
    r->distance2 = val.distance2;
    return r;
}

void OcctlTopoWireChamfer2dOptions::copy_from_c(const occtl_topo_wire_chamfer_2d_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    wire = static_cast<int64_t>(val.wire.bits);
    // array field vertices is not populated from C
    vertex_count = val.vertex_count;
    distance1 = val.distance1;
    distance2 = val.distance2;
}
