#include "OcctlPrimPipeInfo.h"

#include "OcctlNodeId.h"

int OcctlPrimPipeInfo::get_struct_version() const { return struct_version; }
void OcctlPrimPipeInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimPipeInfo::get_p_next() const { return p_next; }
void OcctlPrimPipeInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlPrimPipeInfo::get_profile() const { return profile; }
void OcctlPrimPipeInfo::set_profile(int64_t val) { profile = val; }

int64_t OcctlPrimPipeInfo::get_spine_wire() const { return spine_wire; }
void OcctlPrimPipeInfo::set_spine_wire(int64_t val) { spine_wire = val; }

void OcctlPrimPipeInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimPipeInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimPipeInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimPipeInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimPipeInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_profile"), &OcctlPrimPipeInfo::get_profile);
    godot::ClassDB::bind_method(godot::D_METHOD("set_profile", "val"), &OcctlPrimPipeInfo::set_profile);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "profile"), "set_profile", "get_profile");
    godot::ClassDB::bind_method(godot::D_METHOD("get_spine_wire"), &OcctlPrimPipeInfo::get_spine_wire);
    godot::ClassDB::bind_method(godot::D_METHOD("set_spine_wire", "val"), &OcctlPrimPipeInfo::set_spine_wire);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "spine_wire"), "set_spine_wire", "get_spine_wire");
}

occtl_prim_pipe_info_t OcctlPrimPipeInfo::to_c() const {
    occtl_prim_pipe_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.profile.bits = static_cast<uint64_t>(profile);
    result.spine_wire.bits = static_cast<uint64_t>(spine_wire);
    return result;
}

Ref<OcctlPrimPipeInfo> OcctlPrimPipeInfo::from_c(const occtl_prim_pipe_info_t& val) {
    Ref<OcctlPrimPipeInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->profile = static_cast<int64_t>(val.profile.bits);
    r->spine_wire = static_cast<int64_t>(val.spine_wire.bits);
    return r;
}

void OcctlPrimPipeInfo::copy_from_c(const occtl_prim_pipe_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    profile = static_cast<int64_t>(val.profile.bits);
    spine_wire = static_cast<int64_t>(val.spine_wire.bits);
}
