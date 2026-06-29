#include "OcctlStringArray.h"

PackedStringArray OcctlStringArray::get_strings() const {
    return _value;
}

void OcctlStringArray::set_strings(const PackedStringArray& v) {
    _value = v;
}

int64_t OcctlStringArray::get_count() const {
    return static_cast<int64_t>(_value.size());
}

void OcctlStringArray::copy_from_c(const PackedStringArray& v) {
    _value = v;
}

void OcctlStringArray::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_strings"), &OcctlStringArray::get_strings);
    godot::ClassDB::bind_method(godot::D_METHOD("set_strings", "v"), &OcctlStringArray::set_strings);
    godot::ClassDB::bind_method(godot::D_METHOD("get_count"), &OcctlStringArray::get_count);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_STRING_ARRAY, "strings"), "set_strings", "get_strings");
}
