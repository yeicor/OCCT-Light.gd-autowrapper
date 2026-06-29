#include "OcctlInt32.h"

int64_t OcctlInt32::get_value() const {
    return static_cast<int64_t>(_value);
}

void OcctlInt32::set_value(int64_t v) {
    _value = static_cast<int>(v);
}

void OcctlInt32::copy_from_c(const int& v) {
    _value = v;
}

void OcctlInt32::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_value"), &OcctlInt32::get_value);
    godot::ClassDB::bind_method(godot::D_METHOD("set_value", "v"), &OcctlInt32::set_value);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "value"), "set_value", "get_value");
}
