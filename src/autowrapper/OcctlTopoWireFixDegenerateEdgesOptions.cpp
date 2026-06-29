#include "OcctlTopoWireFixDegenerateEdgesOptions.h"

#include "OcctlNodeId.h"

int OcctlTopoWireFixDegenerateEdgesOptions::get_struct_version() const { return struct_version; }
void OcctlTopoWireFixDegenerateEdgesOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoWireFixDegenerateEdgesOptions::get_p_next() const { return p_next; }
void OcctlTopoWireFixDegenerateEdgesOptions::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlTopoWireFixDegenerateEdgesOptions::get_wire() const { return wire; }
void OcctlTopoWireFixDegenerateEdgesOptions::set_wire(int64_t val) { wire = val; }

double OcctlTopoWireFixDegenerateEdgesOptions::get_min_length() const { return min_length; }
void OcctlTopoWireFixDegenerateEdgesOptions::set_min_length(double val) { min_length = val; }

void OcctlTopoWireFixDegenerateEdgesOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoWireFixDegenerateEdgesOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoWireFixDegenerateEdgesOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoWireFixDegenerateEdgesOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoWireFixDegenerateEdgesOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_wire"), &OcctlTopoWireFixDegenerateEdgesOptions::get_wire);
    godot::ClassDB::bind_method(godot::D_METHOD("set_wire", "val"), &OcctlTopoWireFixDegenerateEdgesOptions::set_wire);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "wire"), "set_wire", "get_wire");
    godot::ClassDB::bind_method(godot::D_METHOD("get_min_length"), &OcctlTopoWireFixDegenerateEdgesOptions::get_min_length);
    godot::ClassDB::bind_method(godot::D_METHOD("set_min_length", "val"), &OcctlTopoWireFixDegenerateEdgesOptions::set_min_length);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "min_length"), "set_min_length", "get_min_length");
}

occtl_topo_wire_fix_degenerate_edges_options_t OcctlTopoWireFixDegenerateEdgesOptions::to_c() const {
    occtl_topo_wire_fix_degenerate_edges_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.wire.bits = static_cast<uint64_t>(wire);
    result.min_length = min_length;
    return result;
}

Ref<OcctlTopoWireFixDegenerateEdgesOptions> OcctlTopoWireFixDegenerateEdgesOptions::from_c(const occtl_topo_wire_fix_degenerate_edges_options_t& val) {
    Ref<OcctlTopoWireFixDegenerateEdgesOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->wire = static_cast<int64_t>(val.wire.bits);
    r->min_length = val.min_length;
    return r;
}

void OcctlTopoWireFixDegenerateEdgesOptions::copy_from_c(const occtl_topo_wire_fix_degenerate_edges_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    wire = static_cast<int64_t>(val.wire.bits);
    min_length = val.min_length;
}
