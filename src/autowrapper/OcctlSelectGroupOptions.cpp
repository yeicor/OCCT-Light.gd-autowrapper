#include "OcctlSelectGroupOptions.h"


int OcctlSelectGroupOptions::get_struct_version() const { return struct_version; }
void OcctlSelectGroupOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlSelectGroupOptions::get_p_next() const { return p_next; }
void OcctlSelectGroupOptions::set_p_next(int64_t val) { p_next = val; }

int OcctlSelectGroupOptions::get_key() const { return key; }
void OcctlSelectGroupOptions::set_key(int val) { key = val; }

int OcctlSelectGroupOptions::get_axis() const { return axis; }
void OcctlSelectGroupOptions::set_axis(int val) { axis = val; }

double OcctlSelectGroupOptions::get_tolerance() const { return tolerance; }
void OcctlSelectGroupOptions::set_tolerance(double val) { tolerance = val; }

float OcctlSelectGroupOptions::get_color_tolerance() const { return color_tolerance; }
void OcctlSelectGroupOptions::set_color_tolerance(float val) { color_tolerance = val; }

int OcctlSelectGroupOptions::get_include_missing() const { return include_missing; }
void OcctlSelectGroupOptions::set_include_missing(int val) { include_missing = val; }

void OcctlSelectGroupOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlSelectGroupOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlSelectGroupOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlSelectGroupOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlSelectGroupOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_key"), &OcctlSelectGroupOptions::get_key);
    godot::ClassDB::bind_method(godot::D_METHOD("set_key", "val"), &OcctlSelectGroupOptions::set_key);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "key"), "set_key", "get_key");
    godot::ClassDB::bind_method(godot::D_METHOD("get_axis"), &OcctlSelectGroupOptions::get_axis);
    godot::ClassDB::bind_method(godot::D_METHOD("set_axis", "val"), &OcctlSelectGroupOptions::set_axis);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "axis"), "set_axis", "get_axis");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlSelectGroupOptions::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlSelectGroupOptions::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_color_tolerance"), &OcctlSelectGroupOptions::get_color_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_color_tolerance", "val"), &OcctlSelectGroupOptions::set_color_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "color_tolerance"), "set_color_tolerance", "get_color_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_include_missing"), &OcctlSelectGroupOptions::get_include_missing);
    godot::ClassDB::bind_method(godot::D_METHOD("set_include_missing", "val"), &OcctlSelectGroupOptions::set_include_missing);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "include_missing"), "set_include_missing", "get_include_missing");
}

occtl_select_group_options_t OcctlSelectGroupOptions::to_c() const {
    occtl_select_group_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.key = static_cast<occtl_select_group_key_t>(key);
    result.axis = static_cast<occtl_select_axis_t>(axis);
    result.tolerance = tolerance;
    result.color_tolerance = color_tolerance;
    result.include_missing = include_missing;
    return result;
}

Ref<OcctlSelectGroupOptions> OcctlSelectGroupOptions::from_c(const occtl_select_group_options_t& val) {
    Ref<OcctlSelectGroupOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->key = static_cast<int>(val.key);
    r->axis = static_cast<int>(val.axis);
    r->tolerance = val.tolerance;
    r->color_tolerance = val.color_tolerance;
    r->include_missing = val.include_missing;
    return r;
}

void OcctlSelectGroupOptions::copy_from_c(const occtl_select_group_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    key = static_cast<int>(val.key);
    axis = static_cast<int>(val.axis);
    tolerance = val.tolerance;
    color_tolerance = val.color_tolerance;
    include_missing = val.include_missing;
}
