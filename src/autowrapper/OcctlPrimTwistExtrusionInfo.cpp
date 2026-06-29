#include "OcctlPrimTwistExtrusionInfo.h"

#include "OcctlNodeId.h"
#include "OcctlAxis1Placement.h"

int OcctlPrimTwistExtrusionInfo::get_struct_version() const { return struct_version; }
void OcctlPrimTwistExtrusionInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimTwistExtrusionInfo::get_p_next() const { return p_next; }
void OcctlPrimTwistExtrusionInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlPrimTwistExtrusionInfo::get_profile_wire() const { return profile_wire; }
void OcctlPrimTwistExtrusionInfo::set_profile_wire(int64_t val) { profile_wire = val; }

Ref<OcctlAxis1Placement> OcctlPrimTwistExtrusionInfo::get_axis() const { return axis; }
void OcctlPrimTwistExtrusionInfo::set_axis(Ref<OcctlAxis1Placement> val) { axis = val; }

double OcctlPrimTwistExtrusionInfo::get_height() const { return height; }
void OcctlPrimTwistExtrusionInfo::set_height(double val) { height = val; }

double OcctlPrimTwistExtrusionInfo::get_angle() const { return angle; }
void OcctlPrimTwistExtrusionInfo::set_angle(double val) { angle = val; }

int OcctlPrimTwistExtrusionInfo::get_section_count() const { return section_count; }
void OcctlPrimTwistExtrusionInfo::set_section_count(int val) { section_count = val; }

int OcctlPrimTwistExtrusionInfo::get_make_solid() const { return make_solid; }
void OcctlPrimTwistExtrusionInfo::set_make_solid(int val) { make_solid = val; }

int OcctlPrimTwistExtrusionInfo::get_ruled() const { return ruled; }
void OcctlPrimTwistExtrusionInfo::set_ruled(int val) { ruled = val; }

double OcctlPrimTwistExtrusionInfo::get_pres3d() const { return pres3d; }
void OcctlPrimTwistExtrusionInfo::set_pres3d(double val) { pres3d = val; }

void OcctlPrimTwistExtrusionInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimTwistExtrusionInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimTwistExtrusionInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimTwistExtrusionInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimTwistExtrusionInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_profile_wire"), &OcctlPrimTwistExtrusionInfo::get_profile_wire);
    godot::ClassDB::bind_method(godot::D_METHOD("set_profile_wire", "val"), &OcctlPrimTwistExtrusionInfo::set_profile_wire);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "profile_wire"), "set_profile_wire", "get_profile_wire");
    godot::ClassDB::bind_method(godot::D_METHOD("get_axis"), &OcctlPrimTwistExtrusionInfo::get_axis);
    godot::ClassDB::bind_method(godot::D_METHOD("set_axis", "val"), &OcctlPrimTwistExtrusionInfo::set_axis);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "axis"), "set_axis", "get_axis");
    godot::ClassDB::bind_method(godot::D_METHOD("get_height"), &OcctlPrimTwistExtrusionInfo::get_height);
    godot::ClassDB::bind_method(godot::D_METHOD("set_height", "val"), &OcctlPrimTwistExtrusionInfo::set_height);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "height"), "set_height", "get_height");
    godot::ClassDB::bind_method(godot::D_METHOD("get_angle"), &OcctlPrimTwistExtrusionInfo::get_angle);
    godot::ClassDB::bind_method(godot::D_METHOD("set_angle", "val"), &OcctlPrimTwistExtrusionInfo::set_angle);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "angle"), "set_angle", "get_angle");
    godot::ClassDB::bind_method(godot::D_METHOD("get_section_count"), &OcctlPrimTwistExtrusionInfo::get_section_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_section_count", "val"), &OcctlPrimTwistExtrusionInfo::set_section_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "section_count"), "set_section_count", "get_section_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_make_solid"), &OcctlPrimTwistExtrusionInfo::get_make_solid);
    godot::ClassDB::bind_method(godot::D_METHOD("set_make_solid", "val"), &OcctlPrimTwistExtrusionInfo::set_make_solid);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "make_solid"), "set_make_solid", "get_make_solid");
    godot::ClassDB::bind_method(godot::D_METHOD("get_ruled"), &OcctlPrimTwistExtrusionInfo::get_ruled);
    godot::ClassDB::bind_method(godot::D_METHOD("set_ruled", "val"), &OcctlPrimTwistExtrusionInfo::set_ruled);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "ruled"), "set_ruled", "get_ruled");
    godot::ClassDB::bind_method(godot::D_METHOD("get_pres3d"), &OcctlPrimTwistExtrusionInfo::get_pres3d);
    godot::ClassDB::bind_method(godot::D_METHOD("set_pres3d", "val"), &OcctlPrimTwistExtrusionInfo::set_pres3d);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "pres3d"), "set_pres3d", "get_pres3d");
}

occtl_prim_twist_extrusion_info_t OcctlPrimTwistExtrusionInfo::to_c() const {
    occtl_prim_twist_extrusion_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.profile_wire.bits = static_cast<uint64_t>(profile_wire);
    result.axis = axis->to_c();
    result.height = height;
    result.angle = angle;
    result.section_count = section_count;
    result.make_solid = make_solid;
    result.ruled = ruled;
    result.pres3d = pres3d;
    return result;
}

Ref<OcctlPrimTwistExtrusionInfo> OcctlPrimTwistExtrusionInfo::from_c(const occtl_prim_twist_extrusion_info_t& val) {
    Ref<OcctlPrimTwistExtrusionInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->profile_wire = static_cast<int64_t>(val.profile_wire.bits);
    r->axis = OcctlAxis1Placement::from_c(val.axis);
    r->height = val.height;
    r->angle = val.angle;
    r->section_count = val.section_count;
    r->make_solid = val.make_solid;
    r->ruled = val.ruled;
    r->pres3d = val.pres3d;
    return r;
}

void OcctlPrimTwistExtrusionInfo::copy_from_c(const occtl_prim_twist_extrusion_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    profile_wire = static_cast<int64_t>(val.profile_wire.bits);
    axis = OcctlAxis1Placement::from_c(val.axis);
    height = val.height;
    angle = val.angle;
    section_count = val.section_count;
    make_solid = val.make_solid;
    ruled = val.ruled;
    pres3d = val.pres3d;
}
