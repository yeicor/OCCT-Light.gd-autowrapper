#include "OcctlPrimConeInfo.h"

#include "OcctlAxis2Placement.h"

int OcctlPrimConeInfo::get_struct_version() const { return struct_version; }
void OcctlPrimConeInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimConeInfo::get_p_next() const { return p_next; }
void OcctlPrimConeInfo::set_p_next(int64_t val) { p_next = val; }

Ref<OcctlAxis2Placement> OcctlPrimConeInfo::get_placement() const { return placement; }
void OcctlPrimConeInfo::set_placement(Ref<OcctlAxis2Placement> val) { placement = val; }

double OcctlPrimConeInfo::get_r1() const { return r1; }
void OcctlPrimConeInfo::set_r1(double val) { r1 = val; }

double OcctlPrimConeInfo::get_r2() const { return r2; }
void OcctlPrimConeInfo::set_r2(double val) { r2 = val; }

double OcctlPrimConeInfo::get_height() const { return height; }
void OcctlPrimConeInfo::set_height(double val) { height = val; }

double OcctlPrimConeInfo::get_angle() const { return angle; }
void OcctlPrimConeInfo::set_angle(double val) { angle = val; }

void OcctlPrimConeInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimConeInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimConeInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimConeInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimConeInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_placement"), &OcctlPrimConeInfo::get_placement);
    godot::ClassDB::bind_method(godot::D_METHOD("set_placement", "val"), &OcctlPrimConeInfo::set_placement);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "placement"), "set_placement", "get_placement");
    godot::ClassDB::bind_method(godot::D_METHOD("get_r1"), &OcctlPrimConeInfo::get_r1);
    godot::ClassDB::bind_method(godot::D_METHOD("set_r1", "val"), &OcctlPrimConeInfo::set_r1);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "r1"), "set_r1", "get_r1");
    godot::ClassDB::bind_method(godot::D_METHOD("get_r2"), &OcctlPrimConeInfo::get_r2);
    godot::ClassDB::bind_method(godot::D_METHOD("set_r2", "val"), &OcctlPrimConeInfo::set_r2);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "r2"), "set_r2", "get_r2");
    godot::ClassDB::bind_method(godot::D_METHOD("get_height"), &OcctlPrimConeInfo::get_height);
    godot::ClassDB::bind_method(godot::D_METHOD("set_height", "val"), &OcctlPrimConeInfo::set_height);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "height"), "set_height", "get_height");
    godot::ClassDB::bind_method(godot::D_METHOD("get_angle"), &OcctlPrimConeInfo::get_angle);
    godot::ClassDB::bind_method(godot::D_METHOD("set_angle", "val"), &OcctlPrimConeInfo::set_angle);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "angle"), "set_angle", "get_angle");
}

occtl_prim_cone_info_t OcctlPrimConeInfo::to_c() const {
    occtl_prim_cone_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.placement = placement->to_c();
    result.r1 = r1;
    result.r2 = r2;
    result.height = height;
    result.angle = angle;
    return result;
}

Ref<OcctlPrimConeInfo> OcctlPrimConeInfo::from_c(const occtl_prim_cone_info_t& val) {
    Ref<OcctlPrimConeInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->placement = OcctlAxis2Placement::from_c(val.placement);
    r->r1 = val.r1;
    r->r2 = val.r2;
    r->height = val.height;
    r->angle = val.angle;
    return r;
}

void OcctlPrimConeInfo::copy_from_c(const occtl_prim_cone_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    placement = OcctlAxis2Placement::from_c(val.placement);
    r1 = val.r1;
    r2 = val.r2;
    height = val.height;
    angle = val.angle;
}
