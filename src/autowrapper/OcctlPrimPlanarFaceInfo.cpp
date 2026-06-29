#include "OcctlPrimPlanarFaceInfo.h"

#include "OcctlNodeId.h"

int OcctlPrimPlanarFaceInfo::get_struct_version() const { return struct_version; }
void OcctlPrimPlanarFaceInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimPlanarFaceInfo::get_p_next() const { return p_next; }
void OcctlPrimPlanarFaceInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlPrimPlanarFaceInfo::get_outer_wire() const { return outer_wire; }
void OcctlPrimPlanarFaceInfo::set_outer_wire(int64_t val) { outer_wire = val; }

PackedInt64Array OcctlPrimPlanarFaceInfo::get_inner_wires() const { return inner_wires; }
void OcctlPrimPlanarFaceInfo::set_inner_wires(PackedInt64Array val) { inner_wires = val; }

int OcctlPrimPlanarFaceInfo::get_inner_wire_count() const { return inner_wire_count; }
void OcctlPrimPlanarFaceInfo::set_inner_wire_count(int val) { inner_wire_count = val; }

void OcctlPrimPlanarFaceInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimPlanarFaceInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimPlanarFaceInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimPlanarFaceInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimPlanarFaceInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_outer_wire"), &OcctlPrimPlanarFaceInfo::get_outer_wire);
    godot::ClassDB::bind_method(godot::D_METHOD("set_outer_wire", "val"), &OcctlPrimPlanarFaceInfo::set_outer_wire);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "outer_wire"), "set_outer_wire", "get_outer_wire");
    godot::ClassDB::bind_method(godot::D_METHOD("get_inner_wires"), &OcctlPrimPlanarFaceInfo::get_inner_wires);
    godot::ClassDB::bind_method(godot::D_METHOD("set_inner_wires", "val"), &OcctlPrimPlanarFaceInfo::set_inner_wires);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "inner_wires"), "set_inner_wires", "get_inner_wires");
    godot::ClassDB::bind_method(godot::D_METHOD("get_inner_wire_count"), &OcctlPrimPlanarFaceInfo::get_inner_wire_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_inner_wire_count", "val"), &OcctlPrimPlanarFaceInfo::set_inner_wire_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "inner_wire_count"), "set_inner_wire_count", "get_inner_wire_count");
}

occtl_prim_planar_face_info_t OcctlPrimPlanarFaceInfo::to_c() const {
    occtl_prim_planar_face_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.outer_wire.bits = static_cast<uint64_t>(outer_wire);
    result.inner_wires = reinterpret_cast<const occtl_node_id_t*>(inner_wires.ptr());
    result.inner_wire_count = inner_wire_count;
    return result;
}

Ref<OcctlPrimPlanarFaceInfo> OcctlPrimPlanarFaceInfo::from_c(const occtl_prim_planar_face_info_t& val) {
    Ref<OcctlPrimPlanarFaceInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->outer_wire = static_cast<int64_t>(val.outer_wire.bits);
    // array field inner_wires is not populated from C
    r->inner_wire_count = val.inner_wire_count;
    return r;
}

void OcctlPrimPlanarFaceInfo::copy_from_c(const occtl_prim_planar_face_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    outer_wire = static_cast<int64_t>(val.outer_wire.bits);
    // array field inner_wires is not populated from C
    inner_wire_count = val.inner_wire_count;
}
