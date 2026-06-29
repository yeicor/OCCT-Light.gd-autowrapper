#include "OcctlPrimCylinderInfo.h"

#include "OcctlAxis2Placement.h"

int OcctlPrimCylinderInfo::get_struct_version() const { return struct_version; }
void OcctlPrimCylinderInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimCylinderInfo::get_p_next() const { return p_next; }
void OcctlPrimCylinderInfo::set_p_next(int64_t val) { p_next = val; }

Ref<OcctlAxis2Placement> OcctlPrimCylinderInfo::get_placement() const { return placement; }
void OcctlPrimCylinderInfo::set_placement(Ref<OcctlAxis2Placement> val) { placement = val; }

double OcctlPrimCylinderInfo::get_radius() const { return radius; }
void OcctlPrimCylinderInfo::set_radius(double val) { radius = val; }

double OcctlPrimCylinderInfo::get_height() const { return height; }
void OcctlPrimCylinderInfo::set_height(double val) { height = val; }

double OcctlPrimCylinderInfo::get_angle() const { return angle; }
void OcctlPrimCylinderInfo::set_angle(double val) { angle = val; }

void OcctlPrimCylinderInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimCylinderInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimCylinderInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimCylinderInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimCylinderInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_placement"), &OcctlPrimCylinderInfo::get_placement);
    godot::ClassDB::bind_method(godot::D_METHOD("set_placement", "val"), &OcctlPrimCylinderInfo::set_placement);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "placement"), "set_placement", "get_placement");
    godot::ClassDB::bind_method(godot::D_METHOD("get_radius"), &OcctlPrimCylinderInfo::get_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_radius", "val"), &OcctlPrimCylinderInfo::set_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "radius"), "set_radius", "get_radius");
    godot::ClassDB::bind_method(godot::D_METHOD("get_height"), &OcctlPrimCylinderInfo::get_height);
    godot::ClassDB::bind_method(godot::D_METHOD("set_height", "val"), &OcctlPrimCylinderInfo::set_height);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "height"), "set_height", "get_height");
    godot::ClassDB::bind_method(godot::D_METHOD("get_angle"), &OcctlPrimCylinderInfo::get_angle);
    godot::ClassDB::bind_method(godot::D_METHOD("set_angle", "val"), &OcctlPrimCylinderInfo::set_angle);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "angle"), "set_angle", "get_angle");
}

occtl_prim_cylinder_info_t OcctlPrimCylinderInfo::to_c() const {
    occtl_prim_cylinder_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.placement = placement->to_c();
    result.radius = radius;
    result.height = height;
    result.angle = angle;
    return result;
}

Ref<OcctlPrimCylinderInfo> OcctlPrimCylinderInfo::from_c(const occtl_prim_cylinder_info_t& val) {
    Ref<OcctlPrimCylinderInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->placement = OcctlAxis2Placement::from_c(val.placement);
    r->radius = val.radius;
    r->height = val.height;
    r->angle = val.angle;
    return r;
}

void OcctlPrimCylinderInfo::copy_from_c(const occtl_prim_cylinder_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    placement = OcctlAxis2Placement::from_c(val.placement);
    radius = val.radius;
    height = val.height;
    angle = val.angle;
}
