#include "OcctlByteArray.h"

PackedByteArray OcctlByteArray::get_value() const {
    return _value;
}

void OcctlByteArray::set_value(const PackedByteArray& v) {
    _value = v;
}

int64_t OcctlByteArray::size() const {
    return static_cast<int64_t>(_value.size());
}

void OcctlByteArray::copy_from_c(const PackedByteArray& v) {
    _value = v;
}

void OcctlByteArray::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_value"), &OcctlByteArray::get_value);
    godot::ClassDB::bind_method(godot::D_METHOD("set_value", "v"), &OcctlByteArray::set_value);
    godot::ClassDB::bind_method(godot::D_METHOD("size"), &OcctlByteArray::size);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_BYTE_ARRAY, "value"), "set_value", "get_value");
}
