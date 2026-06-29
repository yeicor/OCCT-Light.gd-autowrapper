#include "OcctlSize.h"

int64_t OcctlSize::get_value() const {
    return static_cast<int64_t>(_value);
}

void OcctlSize::set_value(int64_t v) {
    _value = static_cast<size_t>(v);
}

void OcctlSize::copy_from_c(const size_t& v) {
    _value = v;
}

void OcctlSize::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_value"), &OcctlSize::get_value);
    godot::ClassDB::bind_method(godot::D_METHOD("set_value", "v"), &OcctlSize::set_value);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "value"), "set_value", "get_value");
}
