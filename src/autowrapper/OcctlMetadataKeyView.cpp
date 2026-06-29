#include "OcctlMetadataKeyView.h"


String OcctlMetadataKeyView::get_key() const { return key; }
void OcctlMetadataKeyView::set_key(String val) { key = val; }

int OcctlMetadataKeyView::get_key_len() const { return key_len; }
void OcctlMetadataKeyView::set_key_len(int val) { key_len = val; }

void OcctlMetadataKeyView::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_key"), &OcctlMetadataKeyView::get_key);
    godot::ClassDB::bind_method(godot::D_METHOD("set_key", "val"), &OcctlMetadataKeyView::set_key);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "key"), "set_key", "get_key");
    godot::ClassDB::bind_method(godot::D_METHOD("get_key_len"), &OcctlMetadataKeyView::get_key_len);
    godot::ClassDB::bind_method(godot::D_METHOD("set_key_len", "val"), &OcctlMetadataKeyView::set_key_len);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "key_len"), "set_key_len", "get_key_len");
}

occtl_metadata_key_view_t OcctlMetadataKeyView::to_c() const {
    occtl_metadata_key_view_t result = {};
    // const pointer field key: not convertible (type String)
    result.key_len = key_len;
    return result;
}

Ref<OcctlMetadataKeyView> OcctlMetadataKeyView::from_c(const occtl_metadata_key_view_t& val) {
    Ref<OcctlMetadataKeyView> r;
    r.instantiate();
    if (val.key) r->key = String(val.key);
    r->key_len = val.key_len;
    return r;
}

void OcctlMetadataKeyView::copy_from_c(const occtl_metadata_key_view_t& val) {
    if (val.key) key = String(val.key);
    key_len = val.key_len;
}
