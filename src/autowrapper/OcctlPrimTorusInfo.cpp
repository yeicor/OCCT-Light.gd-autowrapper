#include "OcctlPrimTorusInfo.h"

#include "OcctlAxis2Placement.h"

int OcctlPrimTorusInfo::get_struct_version() const { return struct_version; }
void OcctlPrimTorusInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimTorusInfo::get_p_next() const { return p_next; }
void OcctlPrimTorusInfo::set_p_next(int64_t val) { p_next = val; }

Ref<OcctlAxis2Placement> OcctlPrimTorusInfo::get_placement() const { return placement; }
void OcctlPrimTorusInfo::set_placement(Ref<OcctlAxis2Placement> val) { placement = val; }

double OcctlPrimTorusInfo::get_r1() const { return r1; }
void OcctlPrimTorusInfo::set_r1(double val) { r1 = val; }

double OcctlPrimTorusInfo::get_r2() const { return r2; }
void OcctlPrimTorusInfo::set_r2(double val) { r2 = val; }

double OcctlPrimTorusInfo::get_angle1() const { return angle1; }
void OcctlPrimTorusInfo::set_angle1(double val) { angle1 = val; }

double OcctlPrimTorusInfo::get_angle2() const { return angle2; }
void OcctlPrimTorusInfo::set_angle2(double val) { angle2 = val; }

double OcctlPrimTorusInfo::get_angle() const { return angle; }
void OcctlPrimTorusInfo::set_angle(double val) { angle = val; }

void OcctlPrimTorusInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimTorusInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimTorusInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimTorusInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimTorusInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_placement"), &OcctlPrimTorusInfo::get_placement);
    godot::ClassDB::bind_method(godot::D_METHOD("set_placement", "val"), &OcctlPrimTorusInfo::set_placement);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "placement"), "set_placement", "get_placement");
    godot::ClassDB::bind_method(godot::D_METHOD("get_r1"), &OcctlPrimTorusInfo::get_r1);
    godot::ClassDB::bind_method(godot::D_METHOD("set_r1", "val"), &OcctlPrimTorusInfo::set_r1);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "r1"), "set_r1", "get_r1");
    godot::ClassDB::bind_method(godot::D_METHOD("get_r2"), &OcctlPrimTorusInfo::get_r2);
    godot::ClassDB::bind_method(godot::D_METHOD("set_r2", "val"), &OcctlPrimTorusInfo::set_r2);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "r2"), "set_r2", "get_r2");
    godot::ClassDB::bind_method(godot::D_METHOD("get_angle1"), &OcctlPrimTorusInfo::get_angle1);
    godot::ClassDB::bind_method(godot::D_METHOD("set_angle1", "val"), &OcctlPrimTorusInfo::set_angle1);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "angle1"), "set_angle1", "get_angle1");
    godot::ClassDB::bind_method(godot::D_METHOD("get_angle2"), &OcctlPrimTorusInfo::get_angle2);
    godot::ClassDB::bind_method(godot::D_METHOD("set_angle2", "val"), &OcctlPrimTorusInfo::set_angle2);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "angle2"), "set_angle2", "get_angle2");
    godot::ClassDB::bind_method(godot::D_METHOD("get_angle"), &OcctlPrimTorusInfo::get_angle);
    godot::ClassDB::bind_method(godot::D_METHOD("set_angle", "val"), &OcctlPrimTorusInfo::set_angle);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "angle"), "set_angle", "get_angle");
}

occtl_prim_torus_info_t OcctlPrimTorusInfo::to_c() const {
    occtl_prim_torus_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.placement = placement->to_c();
    result.r1 = r1;
    result.r2 = r2;
    result.angle1 = angle1;
    result.angle2 = angle2;
    result.angle = angle;
    return result;
}

Ref<OcctlPrimTorusInfo> OcctlPrimTorusInfo::from_c(const occtl_prim_torus_info_t& val) {
    Ref<OcctlPrimTorusInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->placement = OcctlAxis2Placement::from_c(val.placement);
    r->r1 = val.r1;
    r->r2 = val.r2;
    r->angle1 = val.angle1;
    r->angle2 = val.angle2;
    r->angle = val.angle;
    return r;
}

void OcctlPrimTorusInfo::copy_from_c(const occtl_prim_torus_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    placement = OcctlAxis2Placement::from_c(val.placement);
    r1 = val.r1;
    r2 = val.r2;
    angle1 = val.angle1;
    angle2 = val.angle2;
    angle = val.angle;
}
