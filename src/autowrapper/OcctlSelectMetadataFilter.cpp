#include "OcctlSelectMetadataFilter.h"


int OcctlSelectMetadataFilter::get_struct_version() const { return struct_version; }
void OcctlSelectMetadataFilter::set_struct_version(int val) { struct_version = val; }

int64_t OcctlSelectMetadataFilter::get_p_next() const { return p_next; }
void OcctlSelectMetadataFilter::set_p_next(int64_t val) { p_next = val; }

String OcctlSelectMetadataFilter::get_key() const { return key; }
void OcctlSelectMetadataFilter::set_key(String val) { key = val; }

int OcctlSelectMetadataFilter::get_key_len() const { return key_len; }
void OcctlSelectMetadataFilter::set_key_len(int val) { key_len = val; }

String OcctlSelectMetadataFilter::get_value() const { return value; }
void OcctlSelectMetadataFilter::set_value(String val) { value = val; }

int OcctlSelectMetadataFilter::get_value_len() const { return value_len; }
void OcctlSelectMetadataFilter::set_value_len(int val) { value_len = val; }

int OcctlSelectMetadataFilter::get_match_value() const { return match_value; }
void OcctlSelectMetadataFilter::set_match_value(int val) { match_value = val; }

void OcctlSelectMetadataFilter::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlSelectMetadataFilter::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlSelectMetadataFilter::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlSelectMetadataFilter::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlSelectMetadataFilter::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_key"), &OcctlSelectMetadataFilter::get_key);
    godot::ClassDB::bind_method(godot::D_METHOD("set_key", "val"), &OcctlSelectMetadataFilter::set_key);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "key"), "set_key", "get_key");
    godot::ClassDB::bind_method(godot::D_METHOD("get_key_len"), &OcctlSelectMetadataFilter::get_key_len);
    godot::ClassDB::bind_method(godot::D_METHOD("set_key_len", "val"), &OcctlSelectMetadataFilter::set_key_len);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "key_len"), "set_key_len", "get_key_len");
    godot::ClassDB::bind_method(godot::D_METHOD("get_value"), &OcctlSelectMetadataFilter::get_value);
    godot::ClassDB::bind_method(godot::D_METHOD("set_value", "val"), &OcctlSelectMetadataFilter::set_value);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "value"), "set_value", "get_value");
    godot::ClassDB::bind_method(godot::D_METHOD("get_value_len"), &OcctlSelectMetadataFilter::get_value_len);
    godot::ClassDB::bind_method(godot::D_METHOD("set_value_len", "val"), &OcctlSelectMetadataFilter::set_value_len);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "value_len"), "set_value_len", "get_value_len");
    godot::ClassDB::bind_method(godot::D_METHOD("get_match_value"), &OcctlSelectMetadataFilter::get_match_value);
    godot::ClassDB::bind_method(godot::D_METHOD("set_match_value", "val"), &OcctlSelectMetadataFilter::set_match_value);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "match_value"), "set_match_value", "get_match_value");
}

occtl_select_metadata_filter_t OcctlSelectMetadataFilter::to_c() const {
    occtl_select_metadata_filter_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    // const pointer field key: not convertible (type String)
    result.key_len = key_len;
    // const pointer field value: not convertible (type String)
    result.value_len = value_len;
    result.match_value = match_value;
    return result;
}

Ref<OcctlSelectMetadataFilter> OcctlSelectMetadataFilter::from_c(const occtl_select_metadata_filter_t& val) {
    Ref<OcctlSelectMetadataFilter> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    if (val.key) r->key = String(val.key);
    r->key_len = val.key_len;
    if (val.value) r->value = String(val.value);
    r->value_len = val.value_len;
    r->match_value = val.match_value;
    return r;
}

void OcctlSelectMetadataFilter::copy_from_c(const occtl_select_metadata_filter_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    if (val.key) key = String(val.key);
    key_len = val.key_len;
    if (val.value) value = String(val.value);
    value_len = val.value_len;
    match_value = val.match_value;
}
