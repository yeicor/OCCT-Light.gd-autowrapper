#include "OcctlDouble.h"

double OcctlDouble::get_value() const {
    return _value;
}

void OcctlDouble::set_value(double v) {
    _value = static_cast<float>(v);
}

void OcctlDouble::copy_from_c(const float& v) {
    _value = v;
}

void OcctlDouble::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_value"), &OcctlDouble::get_value);
    godot::ClassDB::bind_method(godot::D_METHOD("set_value", "v"), &OcctlDouble::set_value);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "value"), "set_value", "get_value");
}
