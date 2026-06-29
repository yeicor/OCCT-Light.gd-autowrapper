#include "OcctlString.h"

String OcctlString::get_value() const {
    return _value;
}

void OcctlString::set_value(const String& v) {
    _value = v;
}

void OcctlString::copy_from_c(const char* v) {
    _value = v ? String(v) : String();
}

void OcctlString::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_value"), &OcctlString::get_value);
    godot::ClassDB::bind_method(godot::D_METHOD("set_value", "v"), &OcctlString::set_value);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "value"), "set_value", "get_value");
}
