#include "OcctlPrimSlotInfo.h"

#include "OcctlAxis2Placement.h"

int OcctlPrimSlotInfo::get_struct_version() const { return struct_version; }
void OcctlPrimSlotInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimSlotInfo::get_p_next() const { return p_next; }
void OcctlPrimSlotInfo::set_p_next(int64_t val) { p_next = val; }

Ref<OcctlAxis2Placement> OcctlPrimSlotInfo::get_placement() const { return placement; }
void OcctlPrimSlotInfo::set_placement(Ref<OcctlAxis2Placement> val) { placement = val; }

double OcctlPrimSlotInfo::get_length() const { return length; }
void OcctlPrimSlotInfo::set_length(double val) { length = val; }

double OcctlPrimSlotInfo::get_width() const { return width; }
void OcctlPrimSlotInfo::set_width(double val) { width = val; }

void OcctlPrimSlotInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimSlotInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimSlotInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimSlotInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimSlotInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_placement"), &OcctlPrimSlotInfo::get_placement);
    godot::ClassDB::bind_method(godot::D_METHOD("set_placement", "val"), &OcctlPrimSlotInfo::set_placement);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "placement"), "set_placement", "get_placement");
    godot::ClassDB::bind_method(godot::D_METHOD("get_length"), &OcctlPrimSlotInfo::get_length);
    godot::ClassDB::bind_method(godot::D_METHOD("set_length", "val"), &OcctlPrimSlotInfo::set_length);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "length"), "set_length", "get_length");
    godot::ClassDB::bind_method(godot::D_METHOD("get_width"), &OcctlPrimSlotInfo::get_width);
    godot::ClassDB::bind_method(godot::D_METHOD("set_width", "val"), &OcctlPrimSlotInfo::set_width);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "width"), "set_width", "get_width");
}

occtl_prim_slot_info_t OcctlPrimSlotInfo::to_c() const {
    occtl_prim_slot_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.placement = placement->to_c();
    result.length = length;
    result.width = width;
    return result;
}

Ref<OcctlPrimSlotInfo> OcctlPrimSlotInfo::from_c(const occtl_prim_slot_info_t& val) {
    Ref<OcctlPrimSlotInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->placement = OcctlAxis2Placement::from_c(val.placement);
    r->length = val.length;
    r->width = val.width;
    return r;
}

void OcctlPrimSlotInfo::copy_from_c(const occtl_prim_slot_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    placement = OcctlAxis2Placement::from_c(val.placement);
    length = val.length;
    width = val.width;
}
