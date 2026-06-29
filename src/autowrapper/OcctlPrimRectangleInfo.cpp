#include "OcctlPrimRectangleInfo.h"

#include "OcctlAxis2Placement.h"

int OcctlPrimRectangleInfo::get_struct_version() const { return struct_version; }
void OcctlPrimRectangleInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimRectangleInfo::get_p_next() const { return p_next; }
void OcctlPrimRectangleInfo::set_p_next(int64_t val) { p_next = val; }

Ref<OcctlAxis2Placement> OcctlPrimRectangleInfo::get_placement() const { return placement; }
void OcctlPrimRectangleInfo::set_placement(Ref<OcctlAxis2Placement> val) { placement = val; }

double OcctlPrimRectangleInfo::get_width() const { return width; }
void OcctlPrimRectangleInfo::set_width(double val) { width = val; }

double OcctlPrimRectangleInfo::get_height() const { return height; }
void OcctlPrimRectangleInfo::set_height(double val) { height = val; }

void OcctlPrimRectangleInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimRectangleInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimRectangleInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimRectangleInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimRectangleInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_placement"), &OcctlPrimRectangleInfo::get_placement);
    godot::ClassDB::bind_method(godot::D_METHOD("set_placement", "val"), &OcctlPrimRectangleInfo::set_placement);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "placement"), "set_placement", "get_placement");
    godot::ClassDB::bind_method(godot::D_METHOD("get_width"), &OcctlPrimRectangleInfo::get_width);
    godot::ClassDB::bind_method(godot::D_METHOD("set_width", "val"), &OcctlPrimRectangleInfo::set_width);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "width"), "set_width", "get_width");
    godot::ClassDB::bind_method(godot::D_METHOD("get_height"), &OcctlPrimRectangleInfo::get_height);
    godot::ClassDB::bind_method(godot::D_METHOD("set_height", "val"), &OcctlPrimRectangleInfo::set_height);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "height"), "set_height", "get_height");
}

occtl_prim_rectangle_info_t OcctlPrimRectangleInfo::to_c() const {
    occtl_prim_rectangle_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.placement = placement->to_c();
    result.width = width;
    result.height = height;
    return result;
}

Ref<OcctlPrimRectangleInfo> OcctlPrimRectangleInfo::from_c(const occtl_prim_rectangle_info_t& val) {
    Ref<OcctlPrimRectangleInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->placement = OcctlAxis2Placement::from_c(val.placement);
    r->width = val.width;
    r->height = val.height;
    return r;
}

void OcctlPrimRectangleInfo::copy_from_c(const occtl_prim_rectangle_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    placement = OcctlAxis2Placement::from_c(val.placement);
    width = val.width;
    height = val.height;
}
