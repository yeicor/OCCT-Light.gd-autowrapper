#include "OcctlPrimRevolInfo.h"

#include "OcctlNodeId.h"
#include "OcctlAxis1Placement.h"

int OcctlPrimRevolInfo::get_struct_version() const { return struct_version; }
void OcctlPrimRevolInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimRevolInfo::get_p_next() const { return p_next; }
void OcctlPrimRevolInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlPrimRevolInfo::get_profile() const { return profile; }
void OcctlPrimRevolInfo::set_profile(int64_t val) { profile = val; }

Ref<OcctlAxis1Placement> OcctlPrimRevolInfo::get_axis() const { return axis; }
void OcctlPrimRevolInfo::set_axis(Ref<OcctlAxis1Placement> val) { axis = val; }

double OcctlPrimRevolInfo::get_angle() const { return angle; }
void OcctlPrimRevolInfo::set_angle(double val) { angle = val; }

int OcctlPrimRevolInfo::get_copy() const { return copy; }
void OcctlPrimRevolInfo::set_copy(int val) { copy = val; }

void OcctlPrimRevolInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimRevolInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimRevolInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimRevolInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimRevolInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_profile"), &OcctlPrimRevolInfo::get_profile);
    godot::ClassDB::bind_method(godot::D_METHOD("set_profile", "val"), &OcctlPrimRevolInfo::set_profile);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "profile"), "set_profile", "get_profile");
    godot::ClassDB::bind_method(godot::D_METHOD("get_axis"), &OcctlPrimRevolInfo::get_axis);
    godot::ClassDB::bind_method(godot::D_METHOD("set_axis", "val"), &OcctlPrimRevolInfo::set_axis);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "axis"), "set_axis", "get_axis");
    godot::ClassDB::bind_method(godot::D_METHOD("get_angle"), &OcctlPrimRevolInfo::get_angle);
    godot::ClassDB::bind_method(godot::D_METHOD("set_angle", "val"), &OcctlPrimRevolInfo::set_angle);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "angle"), "set_angle", "get_angle");
    godot::ClassDB::bind_method(godot::D_METHOD("get_copy"), &OcctlPrimRevolInfo::get_copy);
    godot::ClassDB::bind_method(godot::D_METHOD("set_copy", "val"), &OcctlPrimRevolInfo::set_copy);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "copy"), "set_copy", "get_copy");
}

occtl_prim_revol_info_t OcctlPrimRevolInfo::to_c() const {
    occtl_prim_revol_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.profile.bits = static_cast<uint64_t>(profile);
    result.axis = axis->to_c();
    result.angle = angle;
    result.copy = copy;
    return result;
}

Ref<OcctlPrimRevolInfo> OcctlPrimRevolInfo::from_c(const occtl_prim_revol_info_t& val) {
    Ref<OcctlPrimRevolInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->profile = static_cast<int64_t>(val.profile.bits);
    r->axis = OcctlAxis1Placement::from_c(val.axis);
    r->angle = val.angle;
    r->copy = val.copy;
    return r;
}

void OcctlPrimRevolInfo::copy_from_c(const occtl_prim_revol_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    profile = static_cast<int64_t>(val.profile.bits);
    axis = OcctlAxis1Placement::from_c(val.axis);
    angle = val.angle;
    copy = val.copy;
}
