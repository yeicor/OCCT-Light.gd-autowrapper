#include "OcctlUint64.h"

int64_t OcctlUint64::get_value() const {
    return static_cast<int64_t>(_value);
}

void OcctlUint64::set_value(int64_t v) {
    _value = static_cast<uint64_t>(v);
}

void OcctlUint64::copy_from_c(const uint64_t& v) {
    _value = v;
}

void OcctlUint64::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_value"), &OcctlUint64::get_value);
    godot::ClassDB::bind_method(godot::D_METHOD("set_value", "v"), &OcctlUint64::set_value);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "value"), "set_value", "get_value");
}
