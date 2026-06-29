#include "OcctlPrimDraftPrismInfo.h"

#include "OcctlNodeId.h"

int OcctlPrimDraftPrismInfo::get_struct_version() const { return struct_version; }
void OcctlPrimDraftPrismInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimDraftPrismInfo::get_p_next() const { return p_next; }
void OcctlPrimDraftPrismInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlPrimDraftPrismInfo::get_profile() const { return profile; }
void OcctlPrimDraftPrismInfo::set_profile(int64_t val) { profile = val; }

double OcctlPrimDraftPrismInfo::get_height() const { return height; }
void OcctlPrimDraftPrismInfo::set_height(double val) { height = val; }

double OcctlPrimDraftPrismInfo::get_taper_angle() const { return taper_angle; }
void OcctlPrimDraftPrismInfo::set_taper_angle(double val) { taper_angle = val; }

void OcctlPrimDraftPrismInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimDraftPrismInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimDraftPrismInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimDraftPrismInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimDraftPrismInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_profile"), &OcctlPrimDraftPrismInfo::get_profile);
    godot::ClassDB::bind_method(godot::D_METHOD("set_profile", "val"), &OcctlPrimDraftPrismInfo::set_profile);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "profile"), "set_profile", "get_profile");
    godot::ClassDB::bind_method(godot::D_METHOD("get_height"), &OcctlPrimDraftPrismInfo::get_height);
    godot::ClassDB::bind_method(godot::D_METHOD("set_height", "val"), &OcctlPrimDraftPrismInfo::set_height);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "height"), "set_height", "get_height");
    godot::ClassDB::bind_method(godot::D_METHOD("get_taper_angle"), &OcctlPrimDraftPrismInfo::get_taper_angle);
    godot::ClassDB::bind_method(godot::D_METHOD("set_taper_angle", "val"), &OcctlPrimDraftPrismInfo::set_taper_angle);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "taper_angle"), "set_taper_angle", "get_taper_angle");
}

occtl_prim_draft_prism_info_t OcctlPrimDraftPrismInfo::to_c() const {
    occtl_prim_draft_prism_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.profile.bits = static_cast<uint64_t>(profile);
    result.height = height;
    result.taper_angle = taper_angle;
    return result;
}

Ref<OcctlPrimDraftPrismInfo> OcctlPrimDraftPrismInfo::from_c(const occtl_prim_draft_prism_info_t& val) {
    Ref<OcctlPrimDraftPrismInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->profile = static_cast<int64_t>(val.profile.bits);
    r->height = val.height;
    r->taper_angle = val.taper_angle;
    return r;
}

void OcctlPrimDraftPrismInfo::copy_from_c(const occtl_prim_draft_prism_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    profile = static_cast<int64_t>(val.profile.bits);
    height = val.height;
    taper_angle = val.taper_angle;
}
