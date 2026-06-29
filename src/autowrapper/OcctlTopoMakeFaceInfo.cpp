#include "OcctlTopoMakeFaceInfo.h"

#include "OcctlRepId.h"
#include "OcctlNodeId.h"

int OcctlTopoMakeFaceInfo::get_struct_version() const { return struct_version; }
void OcctlTopoMakeFaceInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoMakeFaceInfo::get_p_next() const { return p_next; }
void OcctlTopoMakeFaceInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlTopoMakeFaceInfo::get_surface() const { return surface; }
void OcctlTopoMakeFaceInfo::set_surface(int64_t val) { surface = val; }

int64_t OcctlTopoMakeFaceInfo::get_outer_wire() const { return outer_wire; }
void OcctlTopoMakeFaceInfo::set_outer_wire(int64_t val) { outer_wire = val; }

PackedInt64Array OcctlTopoMakeFaceInfo::get_inner_wires() const { return inner_wires; }
void OcctlTopoMakeFaceInfo::set_inner_wires(PackedInt64Array val) { inner_wires = val; }

int OcctlTopoMakeFaceInfo::get_inner_wire_count() const { return inner_wire_count; }
void OcctlTopoMakeFaceInfo::set_inner_wire_count(int val) { inner_wire_count = val; }

double OcctlTopoMakeFaceInfo::get_tolerance() const { return tolerance; }
void OcctlTopoMakeFaceInfo::set_tolerance(double val) { tolerance = val; }

void OcctlTopoMakeFaceInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoMakeFaceInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoMakeFaceInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoMakeFaceInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoMakeFaceInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_surface"), &OcctlTopoMakeFaceInfo::get_surface);
    godot::ClassDB::bind_method(godot::D_METHOD("set_surface", "val"), &OcctlTopoMakeFaceInfo::set_surface);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "surface"), "set_surface", "get_surface");
    godot::ClassDB::bind_method(godot::D_METHOD("get_outer_wire"), &OcctlTopoMakeFaceInfo::get_outer_wire);
    godot::ClassDB::bind_method(godot::D_METHOD("set_outer_wire", "val"), &OcctlTopoMakeFaceInfo::set_outer_wire);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "outer_wire"), "set_outer_wire", "get_outer_wire");
    godot::ClassDB::bind_method(godot::D_METHOD("get_inner_wires"), &OcctlTopoMakeFaceInfo::get_inner_wires);
    godot::ClassDB::bind_method(godot::D_METHOD("set_inner_wires", "val"), &OcctlTopoMakeFaceInfo::set_inner_wires);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "inner_wires"), "set_inner_wires", "get_inner_wires");
    godot::ClassDB::bind_method(godot::D_METHOD("get_inner_wire_count"), &OcctlTopoMakeFaceInfo::get_inner_wire_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_inner_wire_count", "val"), &OcctlTopoMakeFaceInfo::set_inner_wire_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "inner_wire_count"), "set_inner_wire_count", "get_inner_wire_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlTopoMakeFaceInfo::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlTopoMakeFaceInfo::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
}

occtl_topo_make_face_info_t OcctlTopoMakeFaceInfo::to_c() const {
    occtl_topo_make_face_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.surface.bits = static_cast<uint64_t>(surface);
    result.outer_wire.bits = static_cast<uint64_t>(outer_wire);
    result.inner_wires = reinterpret_cast<const occtl_node_id_t*>(inner_wires.ptr());
    result.inner_wire_count = inner_wire_count;
    result.tolerance = tolerance;
    return result;
}

Ref<OcctlTopoMakeFaceInfo> OcctlTopoMakeFaceInfo::from_c(const occtl_topo_make_face_info_t& val) {
    Ref<OcctlTopoMakeFaceInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->surface = static_cast<int64_t>(val.surface.bits);
    r->outer_wire = static_cast<int64_t>(val.outer_wire.bits);
    // array field inner_wires is not populated from C
    r->inner_wire_count = val.inner_wire_count;
    r->tolerance = val.tolerance;
    return r;
}

void OcctlTopoMakeFaceInfo::copy_from_c(const occtl_topo_make_face_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    surface = static_cast<int64_t>(val.surface.bits);
    outer_wire = static_cast<int64_t>(val.outer_wire.bits);
    // array field inner_wires is not populated from C
    inner_wire_count = val.inner_wire_count;
    tolerance = val.tolerance;
}
