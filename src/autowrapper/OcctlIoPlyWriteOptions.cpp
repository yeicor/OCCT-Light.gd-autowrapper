#include "OcctlIoPlyWriteOptions.h"


int OcctlIoPlyWriteOptions::get_struct_version() const { return struct_version; }
void OcctlIoPlyWriteOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlIoPlyWriteOptions::get_p_next() const { return p_next; }
void OcctlIoPlyWriteOptions::set_p_next(int64_t val) { p_next = val; }

int OcctlIoPlyWriteOptions::get_system_coordinate_system() const { return system_coordinate_system; }
void OcctlIoPlyWriteOptions::set_system_coordinate_system(int val) { system_coordinate_system = val; }

int OcctlIoPlyWriteOptions::get_file_coordinate_system() const { return file_coordinate_system; }
void OcctlIoPlyWriteOptions::set_file_coordinate_system(int val) { file_coordinate_system = val; }

int OcctlIoPlyWriteOptions::get_write_normals() const { return write_normals; }
void OcctlIoPlyWriteOptions::set_write_normals(int val) { write_normals = val; }

int OcctlIoPlyWriteOptions::get_write_colors() const { return write_colors; }
void OcctlIoPlyWriteOptions::set_write_colors(int val) { write_colors = val; }

int OcctlIoPlyWriteOptions::get_write_texcoords() const { return write_texcoords; }
void OcctlIoPlyWriteOptions::set_write_texcoords(int val) { write_texcoords = val; }

int OcctlIoPlyWriteOptions::get_write_part_id() const { return write_part_id; }
void OcctlIoPlyWriteOptions::set_write_part_id(int val) { write_part_id = val; }

int OcctlIoPlyWriteOptions::get_write_face_id() const { return write_face_id; }
void OcctlIoPlyWriteOptions::set_write_face_id(int val) { write_face_id = val; }

String OcctlIoPlyWriteOptions::get_comment() const { return comment; }
void OcctlIoPlyWriteOptions::set_comment(String val) { comment = val; }

String OcctlIoPlyWriteOptions::get_author() const { return author; }
void OcctlIoPlyWriteOptions::set_author(String val) { author = val; }

void OcctlIoPlyWriteOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlIoPlyWriteOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlIoPlyWriteOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlIoPlyWriteOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlIoPlyWriteOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_system_coordinate_system"), &OcctlIoPlyWriteOptions::get_system_coordinate_system);
    godot::ClassDB::bind_method(godot::D_METHOD("set_system_coordinate_system", "val"), &OcctlIoPlyWriteOptions::set_system_coordinate_system);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "system_coordinate_system"), "set_system_coordinate_system", "get_system_coordinate_system");
    godot::ClassDB::bind_method(godot::D_METHOD("get_file_coordinate_system"), &OcctlIoPlyWriteOptions::get_file_coordinate_system);
    godot::ClassDB::bind_method(godot::D_METHOD("set_file_coordinate_system", "val"), &OcctlIoPlyWriteOptions::set_file_coordinate_system);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "file_coordinate_system"), "set_file_coordinate_system", "get_file_coordinate_system");
    godot::ClassDB::bind_method(godot::D_METHOD("get_write_normals"), &OcctlIoPlyWriteOptions::get_write_normals);
    godot::ClassDB::bind_method(godot::D_METHOD("set_write_normals", "val"), &OcctlIoPlyWriteOptions::set_write_normals);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "write_normals"), "set_write_normals", "get_write_normals");
    godot::ClassDB::bind_method(godot::D_METHOD("get_write_colors"), &OcctlIoPlyWriteOptions::get_write_colors);
    godot::ClassDB::bind_method(godot::D_METHOD("set_write_colors", "val"), &OcctlIoPlyWriteOptions::set_write_colors);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "write_colors"), "set_write_colors", "get_write_colors");
    godot::ClassDB::bind_method(godot::D_METHOD("get_write_texcoords"), &OcctlIoPlyWriteOptions::get_write_texcoords);
    godot::ClassDB::bind_method(godot::D_METHOD("set_write_texcoords", "val"), &OcctlIoPlyWriteOptions::set_write_texcoords);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "write_texcoords"), "set_write_texcoords", "get_write_texcoords");
    godot::ClassDB::bind_method(godot::D_METHOD("get_write_part_id"), &OcctlIoPlyWriteOptions::get_write_part_id);
    godot::ClassDB::bind_method(godot::D_METHOD("set_write_part_id", "val"), &OcctlIoPlyWriteOptions::set_write_part_id);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "write_part_id"), "set_write_part_id", "get_write_part_id");
    godot::ClassDB::bind_method(godot::D_METHOD("get_write_face_id"), &OcctlIoPlyWriteOptions::get_write_face_id);
    godot::ClassDB::bind_method(godot::D_METHOD("set_write_face_id", "val"), &OcctlIoPlyWriteOptions::set_write_face_id);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "write_face_id"), "set_write_face_id", "get_write_face_id");
    godot::ClassDB::bind_method(godot::D_METHOD("get_comment"), &OcctlIoPlyWriteOptions::get_comment);
    godot::ClassDB::bind_method(godot::D_METHOD("set_comment", "val"), &OcctlIoPlyWriteOptions::set_comment);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "comment"), "set_comment", "get_comment");
    godot::ClassDB::bind_method(godot::D_METHOD("get_author"), &OcctlIoPlyWriteOptions::get_author);
    godot::ClassDB::bind_method(godot::D_METHOD("set_author", "val"), &OcctlIoPlyWriteOptions::set_author);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "author"), "set_author", "get_author");
}

occtl_io_ply_write_options_t OcctlIoPlyWriteOptions::to_c() const {
    occtl_io_ply_write_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.system_coordinate_system = static_cast<occtl_io_ply_coordinate_system_t>(system_coordinate_system);
    result.file_coordinate_system = static_cast<occtl_io_ply_coordinate_system_t>(file_coordinate_system);
    result.write_normals = write_normals;
    result.write_colors = write_colors;
    result.write_texcoords = write_texcoords;
    result.write_part_id = write_part_id;
    result.write_face_id = write_face_id;
    // const pointer field comment: not convertible (type String)
    // const pointer field author: not convertible (type String)
    return result;
}

Ref<OcctlIoPlyWriteOptions> OcctlIoPlyWriteOptions::from_c(const occtl_io_ply_write_options_t& val) {
    Ref<OcctlIoPlyWriteOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->system_coordinate_system = static_cast<int>(val.system_coordinate_system);
    r->file_coordinate_system = static_cast<int>(val.file_coordinate_system);
    r->write_normals = val.write_normals;
    r->write_colors = val.write_colors;
    r->write_texcoords = val.write_texcoords;
    r->write_part_id = val.write_part_id;
    r->write_face_id = val.write_face_id;
    if (val.comment) r->comment = String(val.comment);
    if (val.author) r->author = String(val.author);
    return r;
}

void OcctlIoPlyWriteOptions::copy_from_c(const occtl_io_ply_write_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    system_coordinate_system = static_cast<int>(val.system_coordinate_system);
    file_coordinate_system = static_cast<int>(val.file_coordinate_system);
    write_normals = val.write_normals;
    write_colors = val.write_colors;
    write_texcoords = val.write_texcoords;
    write_part_id = val.write_part_id;
    write_face_id = val.write_face_id;
    if (val.comment) comment = String(val.comment);
    if (val.author) author = String(val.author);
}
