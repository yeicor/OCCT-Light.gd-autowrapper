#include "OcctlPrimCircleInfo.h"

#include "OcctlAxis2Placement.h"

int OcctlPrimCircleInfo::get_struct_version() const { return struct_version; }
void OcctlPrimCircleInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimCircleInfo::get_p_next() const { return p_next; }
void OcctlPrimCircleInfo::set_p_next(int64_t val) { p_next = val; }

Ref<OcctlAxis2Placement> OcctlPrimCircleInfo::get_placement() const { return placement; }
void OcctlPrimCircleInfo::set_placement(Ref<OcctlAxis2Placement> val) { placement = val; }

double OcctlPrimCircleInfo::get_radius() const { return radius; }
void OcctlPrimCircleInfo::set_radius(double val) { radius = val; }

void OcctlPrimCircleInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimCircleInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimCircleInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimCircleInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimCircleInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_placement"), &OcctlPrimCircleInfo::get_placement);
    godot::ClassDB::bind_method(godot::D_METHOD("set_placement", "val"), &OcctlPrimCircleInfo::set_placement);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "placement"), "set_placement", "get_placement");
    godot::ClassDB::bind_method(godot::D_METHOD("get_radius"), &OcctlPrimCircleInfo::get_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_radius", "val"), &OcctlPrimCircleInfo::set_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "radius"), "set_radius", "get_radius");
}

occtl_prim_circle_info_t OcctlPrimCircleInfo::to_c() const {
    occtl_prim_circle_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.placement = placement->to_c();
    result.radius = radius;
    return result;
}

Ref<OcctlPrimCircleInfo> OcctlPrimCircleInfo::from_c(const occtl_prim_circle_info_t& val) {
    Ref<OcctlPrimCircleInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->placement = OcctlAxis2Placement::from_c(val.placement);
    r->radius = val.radius;
    return r;
}

void OcctlPrimCircleInfo::copy_from_c(const occtl_prim_circle_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    placement = OcctlAxis2Placement::from_c(val.placement);
    radius = val.radius;
}
