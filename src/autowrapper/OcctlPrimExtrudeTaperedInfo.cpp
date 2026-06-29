#include "OcctlPrimExtrudeTaperedInfo.h"

#include "OcctlNodeId.h"

int OcctlPrimExtrudeTaperedInfo::get_struct_version() const { return struct_version; }
void OcctlPrimExtrudeTaperedInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimExtrudeTaperedInfo::get_p_next() const { return p_next; }
void OcctlPrimExtrudeTaperedInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlPrimExtrudeTaperedInfo::get_profile_face() const { return profile_face; }
void OcctlPrimExtrudeTaperedInfo::set_profile_face(int64_t val) { profile_face = val; }

double OcctlPrimExtrudeTaperedInfo::get_height() const { return height; }
void OcctlPrimExtrudeTaperedInfo::set_height(double val) { height = val; }

double OcctlPrimExtrudeTaperedInfo::get_taper_angle() const { return taper_angle; }
void OcctlPrimExtrudeTaperedInfo::set_taper_angle(double val) { taper_angle = val; }

void OcctlPrimExtrudeTaperedInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimExtrudeTaperedInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimExtrudeTaperedInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimExtrudeTaperedInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimExtrudeTaperedInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_profile_face"), &OcctlPrimExtrudeTaperedInfo::get_profile_face);
    godot::ClassDB::bind_method(godot::D_METHOD("set_profile_face", "val"), &OcctlPrimExtrudeTaperedInfo::set_profile_face);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "profile_face"), "set_profile_face", "get_profile_face");
    godot::ClassDB::bind_method(godot::D_METHOD("get_height"), &OcctlPrimExtrudeTaperedInfo::get_height);
    godot::ClassDB::bind_method(godot::D_METHOD("set_height", "val"), &OcctlPrimExtrudeTaperedInfo::set_height);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "height"), "set_height", "get_height");
    godot::ClassDB::bind_method(godot::D_METHOD("get_taper_angle"), &OcctlPrimExtrudeTaperedInfo::get_taper_angle);
    godot::ClassDB::bind_method(godot::D_METHOD("set_taper_angle", "val"), &OcctlPrimExtrudeTaperedInfo::set_taper_angle);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "taper_angle"), "set_taper_angle", "get_taper_angle");
}

occtl_prim_extrude_tapered_info_t OcctlPrimExtrudeTaperedInfo::to_c() const {
    occtl_prim_extrude_tapered_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.profile_face.bits = static_cast<uint64_t>(profile_face);
    result.height = height;
    result.taper_angle = taper_angle;
    return result;
}

Ref<OcctlPrimExtrudeTaperedInfo> OcctlPrimExtrudeTaperedInfo::from_c(const occtl_prim_extrude_tapered_info_t& val) {
    Ref<OcctlPrimExtrudeTaperedInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->profile_face = static_cast<int64_t>(val.profile_face.bits);
    r->height = val.height;
    r->taper_angle = val.taper_angle;
    return r;
}

void OcctlPrimExtrudeTaperedInfo::copy_from_c(const occtl_prim_extrude_tapered_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    profile_face = static_cast<int64_t>(val.profile_face.bits);
    height = val.height;
    taper_angle = val.taper_angle;
}
