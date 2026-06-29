#include "OcctlIoObjWriteOptions.h"


int OcctlIoObjWriteOptions::get_struct_version() const { return struct_version; }
void OcctlIoObjWriteOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlIoObjWriteOptions::get_p_next() const { return p_next; }
void OcctlIoObjWriteOptions::set_p_next(int64_t val) { p_next = val; }

int OcctlIoObjWriteOptions::get_system_coordinate_system() const { return system_coordinate_system; }
void OcctlIoObjWriteOptions::set_system_coordinate_system(int val) { system_coordinate_system = val; }

int OcctlIoObjWriteOptions::get_file_coordinate_system() const { return file_coordinate_system; }
void OcctlIoObjWriteOptions::set_file_coordinate_system(int val) { file_coordinate_system = val; }

String OcctlIoObjWriteOptions::get_comment() const { return comment; }
void OcctlIoObjWriteOptions::set_comment(String val) { comment = val; }

String OcctlIoObjWriteOptions::get_author() const { return author; }
void OcctlIoObjWriteOptions::set_author(String val) { author = val; }

void OcctlIoObjWriteOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlIoObjWriteOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlIoObjWriteOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlIoObjWriteOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlIoObjWriteOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_system_coordinate_system"), &OcctlIoObjWriteOptions::get_system_coordinate_system);
    godot::ClassDB::bind_method(godot::D_METHOD("set_system_coordinate_system", "val"), &OcctlIoObjWriteOptions::set_system_coordinate_system);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "system_coordinate_system"), "set_system_coordinate_system", "get_system_coordinate_system");
    godot::ClassDB::bind_method(godot::D_METHOD("get_file_coordinate_system"), &OcctlIoObjWriteOptions::get_file_coordinate_system);
    godot::ClassDB::bind_method(godot::D_METHOD("set_file_coordinate_system", "val"), &OcctlIoObjWriteOptions::set_file_coordinate_system);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "file_coordinate_system"), "set_file_coordinate_system", "get_file_coordinate_system");
    godot::ClassDB::bind_method(godot::D_METHOD("get_comment"), &OcctlIoObjWriteOptions::get_comment);
    godot::ClassDB::bind_method(godot::D_METHOD("set_comment", "val"), &OcctlIoObjWriteOptions::set_comment);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "comment"), "set_comment", "get_comment");
    godot::ClassDB::bind_method(godot::D_METHOD("get_author"), &OcctlIoObjWriteOptions::get_author);
    godot::ClassDB::bind_method(godot::D_METHOD("set_author", "val"), &OcctlIoObjWriteOptions::set_author);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "author"), "set_author", "get_author");
}

occtl_io_obj_write_options_t OcctlIoObjWriteOptions::to_c() const {
    occtl_io_obj_write_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.system_coordinate_system = static_cast<occtl_io_obj_coordinate_system_t>(system_coordinate_system);
    result.file_coordinate_system = static_cast<occtl_io_obj_coordinate_system_t>(file_coordinate_system);
    // const pointer field comment: not convertible (type String)
    // const pointer field author: not convertible (type String)
    return result;
}

Ref<OcctlIoObjWriteOptions> OcctlIoObjWriteOptions::from_c(const occtl_io_obj_write_options_t& val) {
    Ref<OcctlIoObjWriteOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->system_coordinate_system = static_cast<int>(val.system_coordinate_system);
    r->file_coordinate_system = static_cast<int>(val.file_coordinate_system);
    if (val.comment) r->comment = String(val.comment);
    if (val.author) r->author = String(val.author);
    return r;
}

void OcctlIoObjWriteOptions::copy_from_c(const occtl_io_obj_write_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    system_coordinate_system = static_cast<int>(val.system_coordinate_system);
    file_coordinate_system = static_cast<int>(val.file_coordinate_system);
    if (val.comment) comment = String(val.comment);
    if (val.author) author = String(val.author);
}
