#include "OcctlIoIgesWriteOptions.h"


int OcctlIoIgesWriteOptions::get_struct_version() const { return struct_version; }
void OcctlIoIgesWriteOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlIoIgesWriteOptions::get_p_next() const { return p_next; }
void OcctlIoIgesWriteOptions::set_p_next(int64_t val) { p_next = val; }

int OcctlIoIgesWriteOptions::get_write_brep() const { return write_brep; }
void OcctlIoIgesWriteOptions::set_write_brep(int val) { write_brep = val; }

void OcctlIoIgesWriteOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlIoIgesWriteOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlIoIgesWriteOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlIoIgesWriteOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlIoIgesWriteOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_write_brep"), &OcctlIoIgesWriteOptions::get_write_brep);
    godot::ClassDB::bind_method(godot::D_METHOD("set_write_brep", "val"), &OcctlIoIgesWriteOptions::set_write_brep);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "write_brep"), "set_write_brep", "get_write_brep");
}

occtl_io_iges_write_options_t OcctlIoIgesWriteOptions::to_c() const {
    occtl_io_iges_write_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.write_brep = write_brep;
    return result;
}

Ref<OcctlIoIgesWriteOptions> OcctlIoIgesWriteOptions::from_c(const occtl_io_iges_write_options_t& val) {
    Ref<OcctlIoIgesWriteOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->write_brep = val.write_brep;
    return r;
}

void OcctlIoIgesWriteOptions::copy_from_c(const occtl_io_iges_write_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    write_brep = val.write_brep;
}
