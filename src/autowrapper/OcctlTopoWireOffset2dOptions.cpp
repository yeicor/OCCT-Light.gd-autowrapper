#include "OcctlTopoWireOffset2dOptions.h"

#include "OcctlNodeId.h"

int OcctlTopoWireOffset2dOptions::get_struct_version() const { return struct_version; }
void OcctlTopoWireOffset2dOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoWireOffset2dOptions::get_p_next() const { return p_next; }
void OcctlTopoWireOffset2dOptions::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlTopoWireOffset2dOptions::get_wire() const { return wire; }
void OcctlTopoWireOffset2dOptions::set_wire(int64_t val) { wire = val; }

double OcctlTopoWireOffset2dOptions::get_distance() const { return distance; }
void OcctlTopoWireOffset2dOptions::set_distance(double val) { distance = val; }

int OcctlTopoWireOffset2dOptions::get_join() const { return join; }
void OcctlTopoWireOffset2dOptions::set_join(int val) { join = val; }

int OcctlTopoWireOffset2dOptions::get_open_result() const { return open_result; }
void OcctlTopoWireOffset2dOptions::set_open_result(int val) { open_result = val; }

int OcctlTopoWireOffset2dOptions::get_approximate() const { return approximate; }
void OcctlTopoWireOffset2dOptions::set_approximate(int val) { approximate = val; }

void OcctlTopoWireOffset2dOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoWireOffset2dOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoWireOffset2dOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoWireOffset2dOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoWireOffset2dOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_wire"), &OcctlTopoWireOffset2dOptions::get_wire);
    godot::ClassDB::bind_method(godot::D_METHOD("set_wire", "val"), &OcctlTopoWireOffset2dOptions::set_wire);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "wire"), "set_wire", "get_wire");
    godot::ClassDB::bind_method(godot::D_METHOD("get_distance"), &OcctlTopoWireOffset2dOptions::get_distance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_distance", "val"), &OcctlTopoWireOffset2dOptions::set_distance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "distance"), "set_distance", "get_distance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_join"), &OcctlTopoWireOffset2dOptions::get_join);
    godot::ClassDB::bind_method(godot::D_METHOD("set_join", "val"), &OcctlTopoWireOffset2dOptions::set_join);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "join"), "set_join", "get_join");
    godot::ClassDB::bind_method(godot::D_METHOD("get_open_result"), &OcctlTopoWireOffset2dOptions::get_open_result);
    godot::ClassDB::bind_method(godot::D_METHOD("set_open_result", "val"), &OcctlTopoWireOffset2dOptions::set_open_result);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "open_result"), "set_open_result", "get_open_result");
    godot::ClassDB::bind_method(godot::D_METHOD("get_approximate"), &OcctlTopoWireOffset2dOptions::get_approximate);
    godot::ClassDB::bind_method(godot::D_METHOD("set_approximate", "val"), &OcctlTopoWireOffset2dOptions::set_approximate);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "approximate"), "set_approximate", "get_approximate");
}

occtl_topo_wire_offset_2d_options_t OcctlTopoWireOffset2dOptions::to_c() const {
    occtl_topo_wire_offset_2d_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.wire.bits = static_cast<uint64_t>(wire);
    result.distance = distance;
    result.join = static_cast<occtl_topo_wire_offset_2d_join_t>(join);
    result.open_result = open_result;
    result.approximate = approximate;
    return result;
}

Ref<OcctlTopoWireOffset2dOptions> OcctlTopoWireOffset2dOptions::from_c(const occtl_topo_wire_offset_2d_options_t& val) {
    Ref<OcctlTopoWireOffset2dOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->wire = static_cast<int64_t>(val.wire.bits);
    r->distance = val.distance;
    r->join = static_cast<int>(val.join);
    r->open_result = val.open_result;
    r->approximate = val.approximate;
    return r;
}

void OcctlTopoWireOffset2dOptions::copy_from_c(const occtl_topo_wire_offset_2d_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    wire = static_cast<int64_t>(val.wire.bits);
    distance = val.distance;
    join = static_cast<int>(val.join);
    open_result = val.open_result;
    approximate = val.approximate;
}
