#include "OcctlPrimSphereInfo.h"

#include "OcctlAxis2Placement.h"

int OcctlPrimSphereInfo::get_struct_version() const { return struct_version; }
void OcctlPrimSphereInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimSphereInfo::get_p_next() const { return p_next; }
void OcctlPrimSphereInfo::set_p_next(int64_t val) { p_next = val; }

Ref<OcctlAxis2Placement> OcctlPrimSphereInfo::get_placement() const { return placement; }
void OcctlPrimSphereInfo::set_placement(Ref<OcctlAxis2Placement> val) { placement = val; }

double OcctlPrimSphereInfo::get_radius() const { return radius; }
void OcctlPrimSphereInfo::set_radius(double val) { radius = val; }

double OcctlPrimSphereInfo::get_angle1() const { return angle1; }
void OcctlPrimSphereInfo::set_angle1(double val) { angle1 = val; }

double OcctlPrimSphereInfo::get_angle2() const { return angle2; }
void OcctlPrimSphereInfo::set_angle2(double val) { angle2 = val; }

double OcctlPrimSphereInfo::get_angle() const { return angle; }
void OcctlPrimSphereInfo::set_angle(double val) { angle = val; }

void OcctlPrimSphereInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimSphereInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimSphereInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimSphereInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimSphereInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_placement"), &OcctlPrimSphereInfo::get_placement);
    godot::ClassDB::bind_method(godot::D_METHOD("set_placement", "val"), &OcctlPrimSphereInfo::set_placement);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "placement"), "set_placement", "get_placement");
    godot::ClassDB::bind_method(godot::D_METHOD("get_radius"), &OcctlPrimSphereInfo::get_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_radius", "val"), &OcctlPrimSphereInfo::set_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "radius"), "set_radius", "get_radius");
    godot::ClassDB::bind_method(godot::D_METHOD("get_angle1"), &OcctlPrimSphereInfo::get_angle1);
    godot::ClassDB::bind_method(godot::D_METHOD("set_angle1", "val"), &OcctlPrimSphereInfo::set_angle1);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "angle1"), "set_angle1", "get_angle1");
    godot::ClassDB::bind_method(godot::D_METHOD("get_angle2"), &OcctlPrimSphereInfo::get_angle2);
    godot::ClassDB::bind_method(godot::D_METHOD("set_angle2", "val"), &OcctlPrimSphereInfo::set_angle2);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "angle2"), "set_angle2", "get_angle2");
    godot::ClassDB::bind_method(godot::D_METHOD("get_angle"), &OcctlPrimSphereInfo::get_angle);
    godot::ClassDB::bind_method(godot::D_METHOD("set_angle", "val"), &OcctlPrimSphereInfo::set_angle);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "angle"), "set_angle", "get_angle");
}

occtl_prim_sphere_info_t OcctlPrimSphereInfo::to_c() const {
    occtl_prim_sphere_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.placement = placement->to_c();
    result.radius = radius;
    result.angle1 = angle1;
    result.angle2 = angle2;
    result.angle = angle;
    return result;
}

Ref<OcctlPrimSphereInfo> OcctlPrimSphereInfo::from_c(const occtl_prim_sphere_info_t& val) {
    Ref<OcctlPrimSphereInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->placement = OcctlAxis2Placement::from_c(val.placement);
    r->radius = val.radius;
    r->angle1 = val.angle1;
    r->angle2 = val.angle2;
    r->angle = val.angle;
    return r;
}

void OcctlPrimSphereInfo::copy_from_c(const occtl_prim_sphere_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    placement = OcctlAxis2Placement::from_c(val.placement);
    radius = val.radius;
    angle1 = val.angle1;
    angle2 = val.angle2;
    angle = val.angle;
}
