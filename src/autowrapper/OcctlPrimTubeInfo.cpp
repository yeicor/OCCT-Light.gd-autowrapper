#include "OcctlPrimTubeInfo.h"

#include "OcctlAxis2Placement.h"

int OcctlPrimTubeInfo::get_struct_version() const { return struct_version; }
void OcctlPrimTubeInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimTubeInfo::get_p_next() const { return p_next; }
void OcctlPrimTubeInfo::set_p_next(int64_t val) { p_next = val; }

Ref<OcctlAxis2Placement> OcctlPrimTubeInfo::get_placement() const { return placement; }
void OcctlPrimTubeInfo::set_placement(Ref<OcctlAxis2Placement> val) { placement = val; }

double OcctlPrimTubeInfo::get_outer_radius() const { return outer_radius; }
void OcctlPrimTubeInfo::set_outer_radius(double val) { outer_radius = val; }

double OcctlPrimTubeInfo::get_inner_radius() const { return inner_radius; }
void OcctlPrimTubeInfo::set_inner_radius(double val) { inner_radius = val; }

double OcctlPrimTubeInfo::get_height() const { return height; }
void OcctlPrimTubeInfo::set_height(double val) { height = val; }

void OcctlPrimTubeInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimTubeInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimTubeInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimTubeInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimTubeInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_placement"), &OcctlPrimTubeInfo::get_placement);
    godot::ClassDB::bind_method(godot::D_METHOD("set_placement", "val"), &OcctlPrimTubeInfo::set_placement);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "placement"), "set_placement", "get_placement");
    godot::ClassDB::bind_method(godot::D_METHOD("get_outer_radius"), &OcctlPrimTubeInfo::get_outer_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_outer_radius", "val"), &OcctlPrimTubeInfo::set_outer_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "outer_radius"), "set_outer_radius", "get_outer_radius");
    godot::ClassDB::bind_method(godot::D_METHOD("get_inner_radius"), &OcctlPrimTubeInfo::get_inner_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_inner_radius", "val"), &OcctlPrimTubeInfo::set_inner_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "inner_radius"), "set_inner_radius", "get_inner_radius");
    godot::ClassDB::bind_method(godot::D_METHOD("get_height"), &OcctlPrimTubeInfo::get_height);
    godot::ClassDB::bind_method(godot::D_METHOD("set_height", "val"), &OcctlPrimTubeInfo::set_height);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "height"), "set_height", "get_height");
}

occtl_prim_tube_info_t OcctlPrimTubeInfo::to_c() const {
    occtl_prim_tube_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.placement = placement->to_c();
    result.outer_radius = outer_radius;
    result.inner_radius = inner_radius;
    result.height = height;
    return result;
}

Ref<OcctlPrimTubeInfo> OcctlPrimTubeInfo::from_c(const occtl_prim_tube_info_t& val) {
    Ref<OcctlPrimTubeInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->placement = OcctlAxis2Placement::from_c(val.placement);
    r->outer_radius = val.outer_radius;
    r->inner_radius = val.inner_radius;
    r->height = val.height;
    return r;
}

void OcctlPrimTubeInfo::copy_from_c(const occtl_prim_tube_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    placement = OcctlAxis2Placement::from_c(val.placement);
    outer_radius = val.outer_radius;
    inner_radius = val.inner_radius;
    height = val.height;
}
