#include "OcctlPrimArcCenterInfo.h"

#include "OcctlAxis2Placement.h"

int OcctlPrimArcCenterInfo::get_struct_version() const { return struct_version; }
void OcctlPrimArcCenterInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimArcCenterInfo::get_p_next() const { return p_next; }
void OcctlPrimArcCenterInfo::set_p_next(int64_t val) { p_next = val; }

Ref<OcctlAxis2Placement> OcctlPrimArcCenterInfo::get_placement() const { return placement; }
void OcctlPrimArcCenterInfo::set_placement(Ref<OcctlAxis2Placement> val) { placement = val; }

double OcctlPrimArcCenterInfo::get_radius() const { return radius; }
void OcctlPrimArcCenterInfo::set_radius(double val) { radius = val; }

double OcctlPrimArcCenterInfo::get_start_angle() const { return start_angle; }
void OcctlPrimArcCenterInfo::set_start_angle(double val) { start_angle = val; }

double OcctlPrimArcCenterInfo::get_end_angle() const { return end_angle; }
void OcctlPrimArcCenterInfo::set_end_angle(double val) { end_angle = val; }

void OcctlPrimArcCenterInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimArcCenterInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimArcCenterInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimArcCenterInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimArcCenterInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_placement"), &OcctlPrimArcCenterInfo::get_placement);
    godot::ClassDB::bind_method(godot::D_METHOD("set_placement", "val"), &OcctlPrimArcCenterInfo::set_placement);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "placement"), "set_placement", "get_placement");
    godot::ClassDB::bind_method(godot::D_METHOD("get_radius"), &OcctlPrimArcCenterInfo::get_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_radius", "val"), &OcctlPrimArcCenterInfo::set_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "radius"), "set_radius", "get_radius");
    godot::ClassDB::bind_method(godot::D_METHOD("get_start_angle"), &OcctlPrimArcCenterInfo::get_start_angle);
    godot::ClassDB::bind_method(godot::D_METHOD("set_start_angle", "val"), &OcctlPrimArcCenterInfo::set_start_angle);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "start_angle"), "set_start_angle", "get_start_angle");
    godot::ClassDB::bind_method(godot::D_METHOD("get_end_angle"), &OcctlPrimArcCenterInfo::get_end_angle);
    godot::ClassDB::bind_method(godot::D_METHOD("set_end_angle", "val"), &OcctlPrimArcCenterInfo::set_end_angle);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "end_angle"), "set_end_angle", "get_end_angle");
}

occtl_prim_arc_center_info_t OcctlPrimArcCenterInfo::to_c() const {
    occtl_prim_arc_center_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.placement = placement->to_c();
    result.radius = radius;
    result.start_angle = start_angle;
    result.end_angle = end_angle;
    return result;
}

Ref<OcctlPrimArcCenterInfo> OcctlPrimArcCenterInfo::from_c(const occtl_prim_arc_center_info_t& val) {
    Ref<OcctlPrimArcCenterInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->placement = OcctlAxis2Placement::from_c(val.placement);
    r->radius = val.radius;
    r->start_angle = val.start_angle;
    r->end_angle = val.end_angle;
    return r;
}

void OcctlPrimArcCenterInfo::copy_from_c(const occtl_prim_arc_center_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    placement = OcctlAxis2Placement::from_c(val.placement);
    radius = val.radius;
    start_angle = val.start_angle;
    end_angle = val.end_angle;
}
