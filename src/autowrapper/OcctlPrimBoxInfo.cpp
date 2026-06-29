#include "OcctlPrimBoxInfo.h"

#include "OcctlAxis2Placement.h"

int OcctlPrimBoxInfo::get_struct_version() const { return struct_version; }
void OcctlPrimBoxInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimBoxInfo::get_p_next() const { return p_next; }
void OcctlPrimBoxInfo::set_p_next(int64_t val) { p_next = val; }

Ref<OcctlAxis2Placement> OcctlPrimBoxInfo::get_placement() const { return placement; }
void OcctlPrimBoxInfo::set_placement(Ref<OcctlAxis2Placement> val) { placement = val; }

double OcctlPrimBoxInfo::get_dx() const { return dx; }
void OcctlPrimBoxInfo::set_dx(double val) { dx = val; }

double OcctlPrimBoxInfo::get_dy() const { return dy; }
void OcctlPrimBoxInfo::set_dy(double val) { dy = val; }

double OcctlPrimBoxInfo::get_dz() const { return dz; }
void OcctlPrimBoxInfo::set_dz(double val) { dz = val; }

void OcctlPrimBoxInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimBoxInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimBoxInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimBoxInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimBoxInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_placement"), &OcctlPrimBoxInfo::get_placement);
    godot::ClassDB::bind_method(godot::D_METHOD("set_placement", "val"), &OcctlPrimBoxInfo::set_placement);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "placement"), "set_placement", "get_placement");
    godot::ClassDB::bind_method(godot::D_METHOD("get_dx"), &OcctlPrimBoxInfo::get_dx);
    godot::ClassDB::bind_method(godot::D_METHOD("set_dx", "val"), &OcctlPrimBoxInfo::set_dx);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "dx"), "set_dx", "get_dx");
    godot::ClassDB::bind_method(godot::D_METHOD("get_dy"), &OcctlPrimBoxInfo::get_dy);
    godot::ClassDB::bind_method(godot::D_METHOD("set_dy", "val"), &OcctlPrimBoxInfo::set_dy);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "dy"), "set_dy", "get_dy");
    godot::ClassDB::bind_method(godot::D_METHOD("get_dz"), &OcctlPrimBoxInfo::get_dz);
    godot::ClassDB::bind_method(godot::D_METHOD("set_dz", "val"), &OcctlPrimBoxInfo::set_dz);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "dz"), "set_dz", "get_dz");
}

occtl_prim_box_info_t OcctlPrimBoxInfo::to_c() const {
    occtl_prim_box_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.placement = placement->to_c();
    result.dx = dx;
    result.dy = dy;
    result.dz = dz;
    return result;
}

Ref<OcctlPrimBoxInfo> OcctlPrimBoxInfo::from_c(const occtl_prim_box_info_t& val) {
    Ref<OcctlPrimBoxInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->placement = OcctlAxis2Placement::from_c(val.placement);
    r->dx = val.dx;
    r->dy = val.dy;
    r->dz = val.dz;
    return r;
}

void OcctlPrimBoxInfo::copy_from_c(const occtl_prim_box_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    placement = OcctlAxis2Placement::from_c(val.placement);
    dx = val.dx;
    dy = val.dy;
    dz = val.dz;
}
