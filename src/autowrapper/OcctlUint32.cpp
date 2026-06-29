#include "OcctlUint32.h"

int64_t OcctlUint32::get_value() const {
    return static_cast<int64_t>(_value);
}

void OcctlUint32::set_value(int64_t v) {
    _value = static_cast<uint32_t>(v);
}

void OcctlUint32::copy_from_c(const uint32_t& v) {
    _value = v;
}

void OcctlUint32::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_value"), &OcctlUint32::get_value);
    godot::ClassDB::bind_method(godot::D_METHOD("set_value", "v"), &OcctlUint32::set_value);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "value"), "set_value", "get_value");
}
