#include "OcctlPrimPrismInfo.h"

#include "OcctlNodeId.h"
#include "OcctlVector3.h"

int OcctlPrimPrismInfo::get_struct_version() const { return struct_version; }
void OcctlPrimPrismInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimPrismInfo::get_p_next() const { return p_next; }
void OcctlPrimPrismInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlPrimPrismInfo::get_profile() const { return profile; }
void OcctlPrimPrismInfo::set_profile(int64_t val) { profile = val; }

Ref<OcctlVector3> OcctlPrimPrismInfo::get_direction() const { return direction; }
void OcctlPrimPrismInfo::set_direction(Ref<OcctlVector3> val) { direction = val; }

int OcctlPrimPrismInfo::get_copy() const { return copy; }
void OcctlPrimPrismInfo::set_copy(int val) { copy = val; }

int OcctlPrimPrismInfo::get_canonize() const { return canonize; }
void OcctlPrimPrismInfo::set_canonize(int val) { canonize = val; }

void OcctlPrimPrismInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimPrismInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimPrismInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimPrismInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimPrismInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_profile"), &OcctlPrimPrismInfo::get_profile);
    godot::ClassDB::bind_method(godot::D_METHOD("set_profile", "val"), &OcctlPrimPrismInfo::set_profile);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "profile"), "set_profile", "get_profile");
    godot::ClassDB::bind_method(godot::D_METHOD("get_direction"), &OcctlPrimPrismInfo::get_direction);
    godot::ClassDB::bind_method(godot::D_METHOD("set_direction", "val"), &OcctlPrimPrismInfo::set_direction);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "direction"), "set_direction", "get_direction");
    godot::ClassDB::bind_method(godot::D_METHOD("get_copy"), &OcctlPrimPrismInfo::get_copy);
    godot::ClassDB::bind_method(godot::D_METHOD("set_copy", "val"), &OcctlPrimPrismInfo::set_copy);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "copy"), "set_copy", "get_copy");
    godot::ClassDB::bind_method(godot::D_METHOD("get_canonize"), &OcctlPrimPrismInfo::get_canonize);
    godot::ClassDB::bind_method(godot::D_METHOD("set_canonize", "val"), &OcctlPrimPrismInfo::set_canonize);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "canonize"), "set_canonize", "get_canonize");
}

occtl_prim_prism_info_t OcctlPrimPrismInfo::to_c() const {
    occtl_prim_prism_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.profile.bits = static_cast<uint64_t>(profile);
    result.direction = direction->to_c();
    result.copy = copy;
    result.canonize = canonize;
    return result;
}

Ref<OcctlPrimPrismInfo> OcctlPrimPrismInfo::from_c(const occtl_prim_prism_info_t& val) {
    Ref<OcctlPrimPrismInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->profile = static_cast<int64_t>(val.profile.bits);
    r->direction = OcctlVector3::from_c(val.direction);
    r->copy = val.copy;
    r->canonize = val.canonize;
    return r;
}

void OcctlPrimPrismInfo::copy_from_c(const occtl_prim_prism_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    profile = static_cast<int64_t>(val.profile.bits);
    direction = OcctlVector3::from_c(val.direction);
    copy = val.copy;
    canonize = val.canonize;
}
