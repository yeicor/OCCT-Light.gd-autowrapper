#include "OcctlIoStlWriteOptions.h"


int OcctlIoStlWriteOptions::get_struct_version() const { return struct_version; }
void OcctlIoStlWriteOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlIoStlWriteOptions::get_p_next() const { return p_next; }
void OcctlIoStlWriteOptions::set_p_next(int64_t val) { p_next = val; }

int OcctlIoStlWriteOptions::get_ascii_mode() const { return ascii_mode; }
void OcctlIoStlWriteOptions::set_ascii_mode(int val) { ascii_mode = val; }

void OcctlIoStlWriteOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlIoStlWriteOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlIoStlWriteOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlIoStlWriteOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlIoStlWriteOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_ascii_mode"), &OcctlIoStlWriteOptions::get_ascii_mode);
    godot::ClassDB::bind_method(godot::D_METHOD("set_ascii_mode", "val"), &OcctlIoStlWriteOptions::set_ascii_mode);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "ascii_mode"), "set_ascii_mode", "get_ascii_mode");
}

occtl_io_stl_write_options_t OcctlIoStlWriteOptions::to_c() const {
    occtl_io_stl_write_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.ascii_mode = ascii_mode;
    return result;
}

Ref<OcctlIoStlWriteOptions> OcctlIoStlWriteOptions::from_c(const occtl_io_stl_write_options_t& val) {
    Ref<OcctlIoStlWriteOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->ascii_mode = val.ascii_mode;
    return r;
}

void OcctlIoStlWriteOptions::copy_from_c(const occtl_io_stl_write_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    ascii_mode = val.ascii_mode;
}
