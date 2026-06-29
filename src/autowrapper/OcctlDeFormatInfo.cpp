#include "OcctlDeFormatInfo.h"


int OcctlDeFormatInfo::get_struct_version() const { return struct_version; }
void OcctlDeFormatInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlDeFormatInfo::get_p_next() const { return p_next; }
void OcctlDeFormatInfo::set_p_next(int64_t val) { p_next = val; }

String OcctlDeFormatInfo::get_id() const { return id; }
void OcctlDeFormatInfo::set_id(String val) { id = val; }

String OcctlDeFormatInfo::get_label() const { return label; }
void OcctlDeFormatInfo::set_label(String val) { label = val; }

int OcctlDeFormatInfo::get_extension_count() const { return extension_count; }
void OcctlDeFormatInfo::set_extension_count(int val) { extension_count = val; }

int OcctlDeFormatInfo::get_can_read_file() const { return can_read_file; }
void OcctlDeFormatInfo::set_can_read_file(int val) { can_read_file = val; }

int OcctlDeFormatInfo::get_can_write_file() const { return can_write_file; }
void OcctlDeFormatInfo::set_can_write_file(int val) { can_write_file = val; }

int OcctlDeFormatInfo::get_can_read_memory() const { return can_read_memory; }
void OcctlDeFormatInfo::set_can_read_memory(int val) { can_read_memory = val; }

int OcctlDeFormatInfo::get_can_write_memory() const { return can_write_memory; }
void OcctlDeFormatInfo::set_can_write_memory(int val) { can_write_memory = val; }

void OcctlDeFormatInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlDeFormatInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlDeFormatInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlDeFormatInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlDeFormatInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_id"), &OcctlDeFormatInfo::get_id);
    godot::ClassDB::bind_method(godot::D_METHOD("set_id", "val"), &OcctlDeFormatInfo::set_id);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "id"), "set_id", "get_id");
    godot::ClassDB::bind_method(godot::D_METHOD("get_label"), &OcctlDeFormatInfo::get_label);
    godot::ClassDB::bind_method(godot::D_METHOD("set_label", "val"), &OcctlDeFormatInfo::set_label);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "label"), "set_label", "get_label");
    godot::ClassDB::bind_method(godot::D_METHOD("get_extension_count"), &OcctlDeFormatInfo::get_extension_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_extension_count", "val"), &OcctlDeFormatInfo::set_extension_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "extension_count"), "set_extension_count", "get_extension_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_can_read_file"), &OcctlDeFormatInfo::get_can_read_file);
    godot::ClassDB::bind_method(godot::D_METHOD("set_can_read_file", "val"), &OcctlDeFormatInfo::set_can_read_file);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "can_read_file"), "set_can_read_file", "get_can_read_file");
    godot::ClassDB::bind_method(godot::D_METHOD("get_can_write_file"), &OcctlDeFormatInfo::get_can_write_file);
    godot::ClassDB::bind_method(godot::D_METHOD("set_can_write_file", "val"), &OcctlDeFormatInfo::set_can_write_file);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "can_write_file"), "set_can_write_file", "get_can_write_file");
    godot::ClassDB::bind_method(godot::D_METHOD("get_can_read_memory"), &OcctlDeFormatInfo::get_can_read_memory);
    godot::ClassDB::bind_method(godot::D_METHOD("set_can_read_memory", "val"), &OcctlDeFormatInfo::set_can_read_memory);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "can_read_memory"), "set_can_read_memory", "get_can_read_memory");
    godot::ClassDB::bind_method(godot::D_METHOD("get_can_write_memory"), &OcctlDeFormatInfo::get_can_write_memory);
    godot::ClassDB::bind_method(godot::D_METHOD("set_can_write_memory", "val"), &OcctlDeFormatInfo::set_can_write_memory);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "can_write_memory"), "set_can_write_memory", "get_can_write_memory");
}

occtl_de_format_info_t OcctlDeFormatInfo::to_c() const {
    occtl_de_format_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    // const pointer field id: not convertible (type String)
    // const pointer field label: not convertible (type String)
    result.extension_count = extension_count;
    result.can_read_file = can_read_file;
    result.can_write_file = can_write_file;
    result.can_read_memory = can_read_memory;
    result.can_write_memory = can_write_memory;
    return result;
}

Ref<OcctlDeFormatInfo> OcctlDeFormatInfo::from_c(const occtl_de_format_info_t& val) {
    Ref<OcctlDeFormatInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    if (val.id) r->id = String(val.id);
    if (val.label) r->label = String(val.label);
    r->extension_count = val.extension_count;
    r->can_read_file = val.can_read_file;
    r->can_write_file = val.can_write_file;
    r->can_read_memory = val.can_read_memory;
    r->can_write_memory = val.can_write_memory;
    return r;
}

void OcctlDeFormatInfo::copy_from_c(const occtl_de_format_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    if (val.id) id = String(val.id);
    if (val.label) label = String(val.label);
    extension_count = val.extension_count;
    can_read_file = val.can_read_file;
    can_write_file = val.can_write_file;
    can_read_memory = val.can_read_memory;
    can_write_memory = val.can_write_memory;
}
