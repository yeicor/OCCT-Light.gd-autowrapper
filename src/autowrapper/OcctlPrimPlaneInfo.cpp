#include "OcctlPrimPlaneInfo.h"

#include "OcctlAxis2Placement.h"

int OcctlPrimPlaneInfo::get_struct_version() const { return struct_version; }
void OcctlPrimPlaneInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimPlaneInfo::get_p_next() const { return p_next; }
void OcctlPrimPlaneInfo::set_p_next(int64_t val) { p_next = val; }

Ref<OcctlAxis2Placement> OcctlPrimPlaneInfo::get_placement() const { return placement; }
void OcctlPrimPlaneInfo::set_placement(Ref<OcctlAxis2Placement> val) { placement = val; }

double OcctlPrimPlaneInfo::get_width() const { return width; }
void OcctlPrimPlaneInfo::set_width(double val) { width = val; }

double OcctlPrimPlaneInfo::get_height() const { return height; }
void OcctlPrimPlaneInfo::set_height(double val) { height = val; }

void OcctlPrimPlaneInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimPlaneInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimPlaneInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimPlaneInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimPlaneInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_placement"), &OcctlPrimPlaneInfo::get_placement);
    godot::ClassDB::bind_method(godot::D_METHOD("set_placement", "val"), &OcctlPrimPlaneInfo::set_placement);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "placement"), "set_placement", "get_placement");
    godot::ClassDB::bind_method(godot::D_METHOD("get_width"), &OcctlPrimPlaneInfo::get_width);
    godot::ClassDB::bind_method(godot::D_METHOD("set_width", "val"), &OcctlPrimPlaneInfo::set_width);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "width"), "set_width", "get_width");
    godot::ClassDB::bind_method(godot::D_METHOD("get_height"), &OcctlPrimPlaneInfo::get_height);
    godot::ClassDB::bind_method(godot::D_METHOD("set_height", "val"), &OcctlPrimPlaneInfo::set_height);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "height"), "set_height", "get_height");
}

occtl_prim_plane_info_t OcctlPrimPlaneInfo::to_c() const {
    occtl_prim_plane_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.placement = placement->to_c();
    result.width = width;
    result.height = height;
    return result;
}

Ref<OcctlPrimPlaneInfo> OcctlPrimPlaneInfo::from_c(const occtl_prim_plane_info_t& val) {
    Ref<OcctlPrimPlaneInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->placement = OcctlAxis2Placement::from_c(val.placement);
    r->width = val.width;
    r->height = val.height;
    return r;
}

void OcctlPrimPlaneInfo::copy_from_c(const occtl_prim_plane_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    placement = OcctlAxis2Placement::from_c(val.placement);
    width = val.width;
    height = val.height;
}
