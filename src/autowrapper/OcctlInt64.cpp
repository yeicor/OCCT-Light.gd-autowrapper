#include "OcctlInt64.h"

int64_t OcctlInt64::get_value() const {
    return static_cast<int64_t>(_value);
}

void OcctlInt64::set_value(int64_t v) {
    _value = static_cast<int64_t>(v);
}

void OcctlInt64::copy_from_c(const int64_t& v) {
    _value = v;
}

void OcctlInt64::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_value"), &OcctlInt64::get_value);
    godot::ClassDB::bind_method(godot::D_METHOD("set_value", "v"), &OcctlInt64::set_value);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "value"), "set_value", "get_value");
}
