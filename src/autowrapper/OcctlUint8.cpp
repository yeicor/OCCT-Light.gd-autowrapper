#include "OcctlUint8.h"

int64_t OcctlUint8::get_value() const {
    return static_cast<int64_t>(_value);
}

void OcctlUint8::set_value(int64_t v) {
    _value = static_cast<uint8_t>(v);
}

void OcctlUint8::copy_from_c(const uint8_t& v) {
    _value = v;
}

void OcctlUint8::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_value"), &OcctlUint8::get_value);
    godot::ClassDB::bind_method(godot::D_METHOD("set_value", "v"), &OcctlUint8::set_value);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "value"), "set_value", "get_value");
}
