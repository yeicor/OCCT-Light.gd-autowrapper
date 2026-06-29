#include "OcctlIoVrmlReadOptions.h"


int OcctlIoVrmlReadOptions::get_struct_version() const { return struct_version; }
void OcctlIoVrmlReadOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlIoVrmlReadOptions::get_p_next() const { return p_next; }
void OcctlIoVrmlReadOptions::set_p_next(int64_t val) { p_next = val; }

double OcctlIoVrmlReadOptions::get_file_length_unit_m() const { return file_length_unit_m; }
void OcctlIoVrmlReadOptions::set_file_length_unit_m(double val) { file_length_unit_m = val; }

int OcctlIoVrmlReadOptions::get_system_coordinate_system() const { return system_coordinate_system; }
void OcctlIoVrmlReadOptions::set_system_coordinate_system(int val) { system_coordinate_system = val; }

int OcctlIoVrmlReadOptions::get_file_coordinate_system() const { return file_coordinate_system; }
void OcctlIoVrmlReadOptions::set_file_coordinate_system(int val) { file_coordinate_system = val; }

int OcctlIoVrmlReadOptions::get_fill_incomplete() const { return fill_incomplete; }
void OcctlIoVrmlReadOptions::set_fill_incomplete(int val) { fill_incomplete = val; }

void OcctlIoVrmlReadOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlIoVrmlReadOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlIoVrmlReadOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlIoVrmlReadOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlIoVrmlReadOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_file_length_unit_m"), &OcctlIoVrmlReadOptions::get_file_length_unit_m);
    godot::ClassDB::bind_method(godot::D_METHOD("set_file_length_unit_m", "val"), &OcctlIoVrmlReadOptions::set_file_length_unit_m);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "file_length_unit_m"), "set_file_length_unit_m", "get_file_length_unit_m");
    godot::ClassDB::bind_method(godot::D_METHOD("get_system_coordinate_system"), &OcctlIoVrmlReadOptions::get_system_coordinate_system);
    godot::ClassDB::bind_method(godot::D_METHOD("set_system_coordinate_system", "val"), &OcctlIoVrmlReadOptions::set_system_coordinate_system);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "system_coordinate_system"), "set_system_coordinate_system", "get_system_coordinate_system");
    godot::ClassDB::bind_method(godot::D_METHOD("get_file_coordinate_system"), &OcctlIoVrmlReadOptions::get_file_coordinate_system);
    godot::ClassDB::bind_method(godot::D_METHOD("set_file_coordinate_system", "val"), &OcctlIoVrmlReadOptions::set_file_coordinate_system);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "file_coordinate_system"), "set_file_coordinate_system", "get_file_coordinate_system");
    godot::ClassDB::bind_method(godot::D_METHOD("get_fill_incomplete"), &OcctlIoVrmlReadOptions::get_fill_incomplete);
    godot::ClassDB::bind_method(godot::D_METHOD("set_fill_incomplete", "val"), &OcctlIoVrmlReadOptions::set_fill_incomplete);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "fill_incomplete"), "set_fill_incomplete", "get_fill_incomplete");
}

occtl_io_vrml_read_options_t OcctlIoVrmlReadOptions::to_c() const {
    occtl_io_vrml_read_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.file_length_unit_m = file_length_unit_m;
    result.system_coordinate_system = static_cast<occtl_io_vrml_coordinate_system_t>(system_coordinate_system);
    result.file_coordinate_system = static_cast<occtl_io_vrml_coordinate_system_t>(file_coordinate_system);
    result.fill_incomplete = fill_incomplete;
    return result;
}

Ref<OcctlIoVrmlReadOptions> OcctlIoVrmlReadOptions::from_c(const occtl_io_vrml_read_options_t& val) {
    Ref<OcctlIoVrmlReadOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->file_length_unit_m = val.file_length_unit_m;
    r->system_coordinate_system = static_cast<int>(val.system_coordinate_system);
    r->file_coordinate_system = static_cast<int>(val.file_coordinate_system);
    r->fill_incomplete = val.fill_incomplete;
    return r;
}

void OcctlIoVrmlReadOptions::copy_from_c(const occtl_io_vrml_read_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    file_length_unit_m = val.file_length_unit_m;
    system_coordinate_system = static_cast<int>(val.system_coordinate_system);
    file_coordinate_system = static_cast<int>(val.file_coordinate_system);
    fill_incomplete = val.fill_incomplete;
}
