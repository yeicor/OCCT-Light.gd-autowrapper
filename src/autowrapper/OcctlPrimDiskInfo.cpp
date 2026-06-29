#include "OcctlPrimDiskInfo.h"

#include "OcctlAxis2Placement.h"

int OcctlPrimDiskInfo::get_struct_version() const { return struct_version; }
void OcctlPrimDiskInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimDiskInfo::get_p_next() const { return p_next; }
void OcctlPrimDiskInfo::set_p_next(int64_t val) { p_next = val; }

Ref<OcctlAxis2Placement> OcctlPrimDiskInfo::get_placement() const { return placement; }
void OcctlPrimDiskInfo::set_placement(Ref<OcctlAxis2Placement> val) { placement = val; }

double OcctlPrimDiskInfo::get_radius() const { return radius; }
void OcctlPrimDiskInfo::set_radius(double val) { radius = val; }

void OcctlPrimDiskInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimDiskInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimDiskInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimDiskInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimDiskInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_placement"), &OcctlPrimDiskInfo::get_placement);
    godot::ClassDB::bind_method(godot::D_METHOD("set_placement", "val"), &OcctlPrimDiskInfo::set_placement);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "placement"), "set_placement", "get_placement");
    godot::ClassDB::bind_method(godot::D_METHOD("get_radius"), &OcctlPrimDiskInfo::get_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_radius", "val"), &OcctlPrimDiskInfo::set_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "radius"), "set_radius", "get_radius");
}

occtl_prim_disk_info_t OcctlPrimDiskInfo::to_c() const {
    occtl_prim_disk_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.placement = placement->to_c();
    result.radius = radius;
    return result;
}

Ref<OcctlPrimDiskInfo> OcctlPrimDiskInfo::from_c(const occtl_prim_disk_info_t& val) {
    Ref<OcctlPrimDiskInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->placement = OcctlAxis2Placement::from_c(val.placement);
    r->radius = val.radius;
    return r;
}

void OcctlPrimDiskInfo::copy_from_c(const occtl_prim_disk_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    placement = OcctlAxis2Placement::from_c(val.placement);
    radius = val.radius;
}
