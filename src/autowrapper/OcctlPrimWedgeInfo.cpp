#include "OcctlPrimWedgeInfo.h"

#include "OcctlAxis2Placement.h"

int OcctlPrimWedgeInfo::get_struct_version() const { return struct_version; }
void OcctlPrimWedgeInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimWedgeInfo::get_p_next() const { return p_next; }
void OcctlPrimWedgeInfo::set_p_next(int64_t val) { p_next = val; }

Ref<OcctlAxis2Placement> OcctlPrimWedgeInfo::get_placement() const { return placement; }
void OcctlPrimWedgeInfo::set_placement(Ref<OcctlAxis2Placement> val) { placement = val; }

double OcctlPrimWedgeInfo::get_dx() const { return dx; }
void OcctlPrimWedgeInfo::set_dx(double val) { dx = val; }

double OcctlPrimWedgeInfo::get_dy() const { return dy; }
void OcctlPrimWedgeInfo::set_dy(double val) { dy = val; }

double OcctlPrimWedgeInfo::get_dz() const { return dz; }
void OcctlPrimWedgeInfo::set_dz(double val) { dz = val; }

double OcctlPrimWedgeInfo::get_ltx() const { return ltx; }
void OcctlPrimWedgeInfo::set_ltx(double val) { ltx = val; }

void OcctlPrimWedgeInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimWedgeInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimWedgeInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimWedgeInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimWedgeInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_placement"), &OcctlPrimWedgeInfo::get_placement);
    godot::ClassDB::bind_method(godot::D_METHOD("set_placement", "val"), &OcctlPrimWedgeInfo::set_placement);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "placement"), "set_placement", "get_placement");
    godot::ClassDB::bind_method(godot::D_METHOD("get_dx"), &OcctlPrimWedgeInfo::get_dx);
    godot::ClassDB::bind_method(godot::D_METHOD("set_dx", "val"), &OcctlPrimWedgeInfo::set_dx);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "dx"), "set_dx", "get_dx");
    godot::ClassDB::bind_method(godot::D_METHOD("get_dy"), &OcctlPrimWedgeInfo::get_dy);
    godot::ClassDB::bind_method(godot::D_METHOD("set_dy", "val"), &OcctlPrimWedgeInfo::set_dy);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "dy"), "set_dy", "get_dy");
    godot::ClassDB::bind_method(godot::D_METHOD("get_dz"), &OcctlPrimWedgeInfo::get_dz);
    godot::ClassDB::bind_method(godot::D_METHOD("set_dz", "val"), &OcctlPrimWedgeInfo::set_dz);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "dz"), "set_dz", "get_dz");
    godot::ClassDB::bind_method(godot::D_METHOD("get_ltx"), &OcctlPrimWedgeInfo::get_ltx);
    godot::ClassDB::bind_method(godot::D_METHOD("set_ltx", "val"), &OcctlPrimWedgeInfo::set_ltx);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "ltx"), "set_ltx", "get_ltx");
}

occtl_prim_wedge_info_t OcctlPrimWedgeInfo::to_c() const {
    occtl_prim_wedge_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.placement = placement->to_c();
    result.dx = dx;
    result.dy = dy;
    result.dz = dz;
    result.ltx = ltx;
    return result;
}

Ref<OcctlPrimWedgeInfo> OcctlPrimWedgeInfo::from_c(const occtl_prim_wedge_info_t& val) {
    Ref<OcctlPrimWedgeInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->placement = OcctlAxis2Placement::from_c(val.placement);
    r->dx = val.dx;
    r->dy = val.dy;
    r->dz = val.dz;
    r->ltx = val.ltx;
    return r;
}

void OcctlPrimWedgeInfo::copy_from_c(const occtl_prim_wedge_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    placement = OcctlAxis2Placement::from_c(val.placement);
    dx = val.dx;
    dy = val.dy;
    dz = val.dz;
    ltx = val.ltx;
}
