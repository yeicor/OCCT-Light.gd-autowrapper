#include "OcctlIoStepReadOptions.h"


int OcctlIoStepReadOptions::get_struct_version() const { return struct_version; }
void OcctlIoStepReadOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlIoStepReadOptions::get_p_next() const { return p_next; }
void OcctlIoStepReadOptions::set_p_next(int64_t val) { p_next = val; }

int OcctlIoStepReadOptions::get_read_color() const { return read_color; }
void OcctlIoStepReadOptions::set_read_color(int val) { read_color = val; }

int OcctlIoStepReadOptions::get_read_name() const { return read_name; }
void OcctlIoStepReadOptions::set_read_name(int val) { read_name = val; }

int OcctlIoStepReadOptions::get_read_layer() const { return read_layer; }
void OcctlIoStepReadOptions::set_read_layer(int val) { read_layer = val; }

void OcctlIoStepReadOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlIoStepReadOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlIoStepReadOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlIoStepReadOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlIoStepReadOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_read_color"), &OcctlIoStepReadOptions::get_read_color);
    godot::ClassDB::bind_method(godot::D_METHOD("set_read_color", "val"), &OcctlIoStepReadOptions::set_read_color);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "read_color"), "set_read_color", "get_read_color");
    godot::ClassDB::bind_method(godot::D_METHOD("get_read_name"), &OcctlIoStepReadOptions::get_read_name);
    godot::ClassDB::bind_method(godot::D_METHOD("set_read_name", "val"), &OcctlIoStepReadOptions::set_read_name);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "read_name"), "set_read_name", "get_read_name");
    godot::ClassDB::bind_method(godot::D_METHOD("get_read_layer"), &OcctlIoStepReadOptions::get_read_layer);
    godot::ClassDB::bind_method(godot::D_METHOD("set_read_layer", "val"), &OcctlIoStepReadOptions::set_read_layer);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "read_layer"), "set_read_layer", "get_read_layer");
}

occtl_io_step_read_options_t OcctlIoStepReadOptions::to_c() const {
    occtl_io_step_read_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.read_color = read_color;
    result.read_name = read_name;
    result.read_layer = read_layer;
    return result;
}

Ref<OcctlIoStepReadOptions> OcctlIoStepReadOptions::from_c(const occtl_io_step_read_options_t& val) {
    Ref<OcctlIoStepReadOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->read_color = val.read_color;
    r->read_name = val.read_name;
    r->read_layer = val.read_layer;
    return r;
}

void OcctlIoStepReadOptions::copy_from_c(const occtl_io_step_read_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    read_color = val.read_color;
    read_name = val.read_name;
    read_layer = val.read_layer;
}
