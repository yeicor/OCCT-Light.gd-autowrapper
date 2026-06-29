#include "OcctlIoStepWriteOptions.h"


int OcctlIoStepWriteOptions::get_struct_version() const { return struct_version; }
void OcctlIoStepWriteOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlIoStepWriteOptions::get_p_next() const { return p_next; }
void OcctlIoStepWriteOptions::set_p_next(int64_t val) { p_next = val; }

int OcctlIoStepWriteOptions::get_unit() const { return unit; }
void OcctlIoStepWriteOptions::set_unit(int val) { unit = val; }

int OcctlIoStepWriteOptions::get_schema() const { return schema; }
void OcctlIoStepWriteOptions::set_schema(int val) { schema = val; }

int OcctlIoStepWriteOptions::get_write_surface_curves() const { return write_surface_curves; }
void OcctlIoStepWriteOptions::set_write_surface_curves(int val) { write_surface_curves = val; }

int OcctlIoStepWriteOptions::get_write_tessellated() const { return write_tessellated; }
void OcctlIoStepWriteOptions::set_write_tessellated(int val) { write_tessellated = val; }

void OcctlIoStepWriteOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlIoStepWriteOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlIoStepWriteOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlIoStepWriteOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlIoStepWriteOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_unit"), &OcctlIoStepWriteOptions::get_unit);
    godot::ClassDB::bind_method(godot::D_METHOD("set_unit", "val"), &OcctlIoStepWriteOptions::set_unit);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "unit"), "set_unit", "get_unit");
    godot::ClassDB::bind_method(godot::D_METHOD("get_schema"), &OcctlIoStepWriteOptions::get_schema);
    godot::ClassDB::bind_method(godot::D_METHOD("set_schema", "val"), &OcctlIoStepWriteOptions::set_schema);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "schema"), "set_schema", "get_schema");
    godot::ClassDB::bind_method(godot::D_METHOD("get_write_surface_curves"), &OcctlIoStepWriteOptions::get_write_surface_curves);
    godot::ClassDB::bind_method(godot::D_METHOD("set_write_surface_curves", "val"), &OcctlIoStepWriteOptions::set_write_surface_curves);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "write_surface_curves"), "set_write_surface_curves", "get_write_surface_curves");
    godot::ClassDB::bind_method(godot::D_METHOD("get_write_tessellated"), &OcctlIoStepWriteOptions::get_write_tessellated);
    godot::ClassDB::bind_method(godot::D_METHOD("set_write_tessellated", "val"), &OcctlIoStepWriteOptions::set_write_tessellated);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "write_tessellated"), "set_write_tessellated", "get_write_tessellated");
}

occtl_io_step_write_options_t OcctlIoStepWriteOptions::to_c() const {
    occtl_io_step_write_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.unit = static_cast<occtl_io_step_length_unit_t>(unit);
    result.schema = static_cast<occtl_io_step_schema_t>(schema);
    result.write_surface_curves = write_surface_curves;
    result.write_tessellated = write_tessellated;
    return result;
}

Ref<OcctlIoStepWriteOptions> OcctlIoStepWriteOptions::from_c(const occtl_io_step_write_options_t& val) {
    Ref<OcctlIoStepWriteOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->unit = static_cast<int>(val.unit);
    r->schema = static_cast<int>(val.schema);
    r->write_surface_curves = val.write_surface_curves;
    r->write_tessellated = val.write_tessellated;
    return r;
}

void OcctlIoStepWriteOptions::copy_from_c(const occtl_io_step_write_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    unit = static_cast<int>(val.unit);
    schema = static_cast<int>(val.schema);
    write_surface_curves = val.write_surface_curves;
    write_tessellated = val.write_tessellated;
}
