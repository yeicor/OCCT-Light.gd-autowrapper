#include "OcctlPrimHelixInfo.h"

#include "OcctlAxis2Placement.h"

int OcctlPrimHelixInfo::get_struct_version() const { return struct_version; }
void OcctlPrimHelixInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimHelixInfo::get_p_next() const { return p_next; }
void OcctlPrimHelixInfo::set_p_next(int64_t val) { p_next = val; }

Ref<OcctlAxis2Placement> OcctlPrimHelixInfo::get_placement() const { return placement; }
void OcctlPrimHelixInfo::set_placement(Ref<OcctlAxis2Placement> val) { placement = val; }

double OcctlPrimHelixInfo::get_radius() const { return radius; }
void OcctlPrimHelixInfo::set_radius(double val) { radius = val; }

double OcctlPrimHelixInfo::get_pitch() const { return pitch; }
void OcctlPrimHelixInfo::set_pitch(double val) { pitch = val; }

double OcctlPrimHelixInfo::get_height() const { return height; }
void OcctlPrimHelixInfo::set_height(double val) { height = val; }

int OcctlPrimHelixInfo::get_left_handed() const { return left_handed; }
void OcctlPrimHelixInfo::set_left_handed(int val) { left_handed = val; }

void OcctlPrimHelixInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimHelixInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimHelixInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimHelixInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimHelixInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_placement"), &OcctlPrimHelixInfo::get_placement);
    godot::ClassDB::bind_method(godot::D_METHOD("set_placement", "val"), &OcctlPrimHelixInfo::set_placement);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "placement"), "set_placement", "get_placement");
    godot::ClassDB::bind_method(godot::D_METHOD("get_radius"), &OcctlPrimHelixInfo::get_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_radius", "val"), &OcctlPrimHelixInfo::set_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "radius"), "set_radius", "get_radius");
    godot::ClassDB::bind_method(godot::D_METHOD("get_pitch"), &OcctlPrimHelixInfo::get_pitch);
    godot::ClassDB::bind_method(godot::D_METHOD("set_pitch", "val"), &OcctlPrimHelixInfo::set_pitch);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "pitch"), "set_pitch", "get_pitch");
    godot::ClassDB::bind_method(godot::D_METHOD("get_height"), &OcctlPrimHelixInfo::get_height);
    godot::ClassDB::bind_method(godot::D_METHOD("set_height", "val"), &OcctlPrimHelixInfo::set_height);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "height"), "set_height", "get_height");
    godot::ClassDB::bind_method(godot::D_METHOD("get_left_handed"), &OcctlPrimHelixInfo::get_left_handed);
    godot::ClassDB::bind_method(godot::D_METHOD("set_left_handed", "val"), &OcctlPrimHelixInfo::set_left_handed);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "left_handed"), "set_left_handed", "get_left_handed");
}

occtl_prim_helix_info_t OcctlPrimHelixInfo::to_c() const {
    occtl_prim_helix_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.placement = placement->to_c();
    result.radius = radius;
    result.pitch = pitch;
    result.height = height;
    result.left_handed = left_handed;
    return result;
}

Ref<OcctlPrimHelixInfo> OcctlPrimHelixInfo::from_c(const occtl_prim_helix_info_t& val) {
    Ref<OcctlPrimHelixInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->placement = OcctlAxis2Placement::from_c(val.placement);
    r->radius = val.radius;
    r->pitch = val.pitch;
    r->height = val.height;
    r->left_handed = val.left_handed;
    return r;
}

void OcctlPrimHelixInfo::copy_from_c(const occtl_prim_helix_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    placement = OcctlAxis2Placement::from_c(val.placement);
    radius = val.radius;
    pitch = val.pitch;
    height = val.height;
    left_handed = val.left_handed;
}
