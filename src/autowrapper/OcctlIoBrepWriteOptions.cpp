#include "OcctlIoBrepWriteOptions.h"


int OcctlIoBrepWriteOptions::get_struct_version() const { return struct_version; }
void OcctlIoBrepWriteOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlIoBrepWriteOptions::get_p_next() const { return p_next; }
void OcctlIoBrepWriteOptions::set_p_next(int64_t val) { p_next = val; }

int OcctlIoBrepWriteOptions::get_write_triangulation() const { return write_triangulation; }
void OcctlIoBrepWriteOptions::set_write_triangulation(int val) { write_triangulation = val; }

void OcctlIoBrepWriteOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlIoBrepWriteOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlIoBrepWriteOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlIoBrepWriteOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlIoBrepWriteOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_write_triangulation"), &OcctlIoBrepWriteOptions::get_write_triangulation);
    godot::ClassDB::bind_method(godot::D_METHOD("set_write_triangulation", "val"), &OcctlIoBrepWriteOptions::set_write_triangulation);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "write_triangulation"), "set_write_triangulation", "get_write_triangulation");
}

occtl_io_brep_write_options_t OcctlIoBrepWriteOptions::to_c() const {
    occtl_io_brep_write_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.write_triangulation = write_triangulation;
    return result;
}

Ref<OcctlIoBrepWriteOptions> OcctlIoBrepWriteOptions::from_c(const occtl_io_brep_write_options_t& val) {
    Ref<OcctlIoBrepWriteOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->write_triangulation = val.write_triangulation;
    return r;
}

void OcctlIoBrepWriteOptions::copy_from_c(const occtl_io_brep_write_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    write_triangulation = val.write_triangulation;
}
