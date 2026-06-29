#include "OcctlIoObjReadOptions.h"


int OcctlIoObjReadOptions::get_struct_version() const { return struct_version; }
void OcctlIoObjReadOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlIoObjReadOptions::get_p_next() const { return p_next; }
void OcctlIoObjReadOptions::set_p_next(int64_t val) { p_next = val; }

double OcctlIoObjReadOptions::get_file_length_unit_m() const { return file_length_unit_m; }
void OcctlIoObjReadOptions::set_file_length_unit_m(double val) { file_length_unit_m = val; }

int OcctlIoObjReadOptions::get_system_coordinate_system() const { return system_coordinate_system; }
void OcctlIoObjReadOptions::set_system_coordinate_system(int val) { system_coordinate_system = val; }

int OcctlIoObjReadOptions::get_file_coordinate_system() const { return file_coordinate_system; }
void OcctlIoObjReadOptions::set_file_coordinate_system(int val) { file_coordinate_system = val; }

int OcctlIoObjReadOptions::get_single_precision() const { return single_precision; }
void OcctlIoObjReadOptions::set_single_precision(int val) { single_precision = val; }

int OcctlIoObjReadOptions::get_create_shapes() const { return create_shapes; }
void OcctlIoObjReadOptions::set_create_shapes(int val) { create_shapes = val; }

int OcctlIoObjReadOptions::get_fill_incomplete() const { return fill_incomplete; }
void OcctlIoObjReadOptions::set_fill_incomplete(int val) { fill_incomplete = val; }

int OcctlIoObjReadOptions::get_memory_limit_mib() const { return memory_limit_mib; }
void OcctlIoObjReadOptions::set_memory_limit_mib(int val) { memory_limit_mib = val; }

String OcctlIoObjReadOptions::get_root_prefix() const { return root_prefix; }
void OcctlIoObjReadOptions::set_root_prefix(String val) { root_prefix = val; }

void OcctlIoObjReadOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlIoObjReadOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlIoObjReadOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlIoObjReadOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlIoObjReadOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_file_length_unit_m"), &OcctlIoObjReadOptions::get_file_length_unit_m);
    godot::ClassDB::bind_method(godot::D_METHOD("set_file_length_unit_m", "val"), &OcctlIoObjReadOptions::set_file_length_unit_m);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "file_length_unit_m"), "set_file_length_unit_m", "get_file_length_unit_m");
    godot::ClassDB::bind_method(godot::D_METHOD("get_system_coordinate_system"), &OcctlIoObjReadOptions::get_system_coordinate_system);
    godot::ClassDB::bind_method(godot::D_METHOD("set_system_coordinate_system", "val"), &OcctlIoObjReadOptions::set_system_coordinate_system);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "system_coordinate_system"), "set_system_coordinate_system", "get_system_coordinate_system");
    godot::ClassDB::bind_method(godot::D_METHOD("get_file_coordinate_system"), &OcctlIoObjReadOptions::get_file_coordinate_system);
    godot::ClassDB::bind_method(godot::D_METHOD("set_file_coordinate_system", "val"), &OcctlIoObjReadOptions::set_file_coordinate_system);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "file_coordinate_system"), "set_file_coordinate_system", "get_file_coordinate_system");
    godot::ClassDB::bind_method(godot::D_METHOD("get_single_precision"), &OcctlIoObjReadOptions::get_single_precision);
    godot::ClassDB::bind_method(godot::D_METHOD("set_single_precision", "val"), &OcctlIoObjReadOptions::set_single_precision);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "single_precision"), "set_single_precision", "get_single_precision");
    godot::ClassDB::bind_method(godot::D_METHOD("get_create_shapes"), &OcctlIoObjReadOptions::get_create_shapes);
    godot::ClassDB::bind_method(godot::D_METHOD("set_create_shapes", "val"), &OcctlIoObjReadOptions::set_create_shapes);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "create_shapes"), "set_create_shapes", "get_create_shapes");
    godot::ClassDB::bind_method(godot::D_METHOD("get_fill_incomplete"), &OcctlIoObjReadOptions::get_fill_incomplete);
    godot::ClassDB::bind_method(godot::D_METHOD("set_fill_incomplete", "val"), &OcctlIoObjReadOptions::set_fill_incomplete);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "fill_incomplete"), "set_fill_incomplete", "get_fill_incomplete");
    godot::ClassDB::bind_method(godot::D_METHOD("get_memory_limit_mib"), &OcctlIoObjReadOptions::get_memory_limit_mib);
    godot::ClassDB::bind_method(godot::D_METHOD("set_memory_limit_mib", "val"), &OcctlIoObjReadOptions::set_memory_limit_mib);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "memory_limit_mib"), "set_memory_limit_mib", "get_memory_limit_mib");
    godot::ClassDB::bind_method(godot::D_METHOD("get_root_prefix"), &OcctlIoObjReadOptions::get_root_prefix);
    godot::ClassDB::bind_method(godot::D_METHOD("set_root_prefix", "val"), &OcctlIoObjReadOptions::set_root_prefix);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "root_prefix"), "set_root_prefix", "get_root_prefix");
}

occtl_io_obj_read_options_t OcctlIoObjReadOptions::to_c() const {
    occtl_io_obj_read_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.file_length_unit_m = file_length_unit_m;
    result.system_coordinate_system = static_cast<occtl_io_obj_coordinate_system_t>(system_coordinate_system);
    result.file_coordinate_system = static_cast<occtl_io_obj_coordinate_system_t>(file_coordinate_system);
    result.single_precision = single_precision;
    result.create_shapes = create_shapes;
    result.fill_incomplete = fill_incomplete;
    result.memory_limit_mib = memory_limit_mib;
    // const pointer field root_prefix: not convertible (type String)
    return result;
}

Ref<OcctlIoObjReadOptions> OcctlIoObjReadOptions::from_c(const occtl_io_obj_read_options_t& val) {
    Ref<OcctlIoObjReadOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->file_length_unit_m = val.file_length_unit_m;
    r->system_coordinate_system = static_cast<int>(val.system_coordinate_system);
    r->file_coordinate_system = static_cast<int>(val.file_coordinate_system);
    r->single_precision = val.single_precision;
    r->create_shapes = val.create_shapes;
    r->fill_incomplete = val.fill_incomplete;
    r->memory_limit_mib = val.memory_limit_mib;
    if (val.root_prefix) r->root_prefix = String(val.root_prefix);
    return r;
}

void OcctlIoObjReadOptions::copy_from_c(const occtl_io_obj_read_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    file_length_unit_m = val.file_length_unit_m;
    system_coordinate_system = static_cast<int>(val.system_coordinate_system);
    file_coordinate_system = static_cast<int>(val.file_coordinate_system);
    single_precision = val.single_precision;
    create_shapes = val.create_shapes;
    fill_incomplete = val.fill_incomplete;
    memory_limit_mib = val.memory_limit_mib;
    if (val.root_prefix) root_prefix = String(val.root_prefix);
}
