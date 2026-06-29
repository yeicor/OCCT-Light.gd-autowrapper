#include "OcctlDirection2.h"


double OcctlDirection2::get_x() const { return x; }
void OcctlDirection2::set_x(double val) { x = val; }

double OcctlDirection2::get_y() const { return y; }
void OcctlDirection2::set_y(double val) { y = val; }

void OcctlDirection2::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_x"), &OcctlDirection2::get_x);
    godot::ClassDB::bind_method(godot::D_METHOD("set_x", "val"), &OcctlDirection2::set_x);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "x"), "set_x", "get_x");
    godot::ClassDB::bind_method(godot::D_METHOD("get_y"), &OcctlDirection2::get_y);
    godot::ClassDB::bind_method(godot::D_METHOD("set_y", "val"), &OcctlDirection2::set_y);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "y"), "set_y", "get_y");
    godot::ClassDB::bind_static_method("OcctlDirection2", godot::D_METHOD("from_vector2", "v"), &OcctlDirection2::from_vector2);
}

occtl_direction2_t OcctlDirection2::to_c() const {
    occtl_direction2_t result = {};
    result.x = x;
    result.y = y;
    return result;
}

Ref<OcctlDirection2> OcctlDirection2::from_c(const occtl_direction2_t& val) {
    Ref<OcctlDirection2> r;
    r.instantiate();
    r->x = val.x;
    r->y = val.y;
    return r;
}

void OcctlDirection2::copy_from_c(const occtl_direction2_t& val) {
    x = val.x;
    y = val.y;
}

Ref<OcctlDirection2> OcctlDirection2::from_vector2(Vector2 v) {
    Ref<OcctlDirection2> instance;
    instance.instantiate();
    instance->x = v.x;
    instance->y = v.y;
    return instance;
}
