#include "OcctlIoVrmlWriteOptions.h"


int OcctlIoVrmlWriteOptions::get_struct_version() const { return struct_version; }
void OcctlIoVrmlWriteOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlIoVrmlWriteOptions::get_p_next() const { return p_next; }
void OcctlIoVrmlWriteOptions::set_p_next(int64_t val) { p_next = val; }

int OcctlIoVrmlWriteOptions::get_writer_version() const { return writer_version; }
void OcctlIoVrmlWriteOptions::set_writer_version(int val) { writer_version = val; }

int OcctlIoVrmlWriteOptions::get_representation() const { return representation; }
void OcctlIoVrmlWriteOptions::set_representation(int val) { representation = val; }

void OcctlIoVrmlWriteOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlIoVrmlWriteOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlIoVrmlWriteOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlIoVrmlWriteOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlIoVrmlWriteOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_writer_version"), &OcctlIoVrmlWriteOptions::get_writer_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_writer_version", "val"), &OcctlIoVrmlWriteOptions::set_writer_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "writer_version"), "set_writer_version", "get_writer_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_representation"), &OcctlIoVrmlWriteOptions::get_representation);
    godot::ClassDB::bind_method(godot::D_METHOD("set_representation", "val"), &OcctlIoVrmlWriteOptions::set_representation);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "representation"), "set_representation", "get_representation");
}

occtl_io_vrml_write_options_t OcctlIoVrmlWriteOptions::to_c() const {
    occtl_io_vrml_write_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.writer_version = static_cast<occtl_io_vrml_writer_version_t>(writer_version);
    result.representation = static_cast<occtl_io_vrml_representation_t>(representation);
    return result;
}

Ref<OcctlIoVrmlWriteOptions> OcctlIoVrmlWriteOptions::from_c(const occtl_io_vrml_write_options_t& val) {
    Ref<OcctlIoVrmlWriteOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->writer_version = static_cast<int>(val.writer_version);
    r->representation = static_cast<int>(val.representation);
    return r;
}

void OcctlIoVrmlWriteOptions::copy_from_c(const occtl_io_vrml_write_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    writer_version = static_cast<int>(val.writer_version);
    representation = static_cast<int>(val.representation);
}
