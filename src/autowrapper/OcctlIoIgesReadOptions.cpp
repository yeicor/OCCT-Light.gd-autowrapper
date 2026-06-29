#include "OcctlIoIgesReadOptions.h"


int OcctlIoIgesReadOptions::get_struct_version() const { return struct_version; }
void OcctlIoIgesReadOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlIoIgesReadOptions::get_p_next() const { return p_next; }
void OcctlIoIgesReadOptions::set_p_next(int64_t val) { p_next = val; }

int OcctlIoIgesReadOptions::get_read_color() const { return read_color; }
void OcctlIoIgesReadOptions::set_read_color(int val) { read_color = val; }

int OcctlIoIgesReadOptions::get_read_name() const { return read_name; }
void OcctlIoIgesReadOptions::set_read_name(int val) { read_name = val; }

void OcctlIoIgesReadOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlIoIgesReadOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlIoIgesReadOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlIoIgesReadOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlIoIgesReadOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_read_color"), &OcctlIoIgesReadOptions::get_read_color);
    godot::ClassDB::bind_method(godot::D_METHOD("set_read_color", "val"), &OcctlIoIgesReadOptions::set_read_color);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "read_color"), "set_read_color", "get_read_color");
    godot::ClassDB::bind_method(godot::D_METHOD("get_read_name"), &OcctlIoIgesReadOptions::get_read_name);
    godot::ClassDB::bind_method(godot::D_METHOD("set_read_name", "val"), &OcctlIoIgesReadOptions::set_read_name);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "read_name"), "set_read_name", "get_read_name");
}

occtl_io_iges_read_options_t OcctlIoIgesReadOptions::to_c() const {
    occtl_io_iges_read_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.read_color = read_color;
    result.read_name = read_name;
    return result;
}

Ref<OcctlIoIgesReadOptions> OcctlIoIgesReadOptions::from_c(const occtl_io_iges_read_options_t& val) {
    Ref<OcctlIoIgesReadOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->read_color = val.read_color;
    r->read_name = val.read_name;
    return r;
}

void OcctlIoIgesReadOptions::copy_from_c(const occtl_io_iges_read_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    read_color = val.read_color;
    read_name = val.read_name;
}
