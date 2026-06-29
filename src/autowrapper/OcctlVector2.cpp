#include "OcctlVector2.h"


double OcctlVector2::get_x() const { return x; }
void OcctlVector2::set_x(double val) { x = val; }

double OcctlVector2::get_y() const { return y; }
void OcctlVector2::set_y(double val) { y = val; }

void OcctlVector2::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_x"), &OcctlVector2::get_x);
    godot::ClassDB::bind_method(godot::D_METHOD("set_x", "val"), &OcctlVector2::set_x);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "x"), "set_x", "get_x");
    godot::ClassDB::bind_method(godot::D_METHOD("get_y"), &OcctlVector2::get_y);
    godot::ClassDB::bind_method(godot::D_METHOD("set_y", "val"), &OcctlVector2::set_y);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "y"), "set_y", "get_y");
    godot::ClassDB::bind_static_method("OcctlVector2", godot::D_METHOD("from_vector2", "v"), &OcctlVector2::from_vector2);
}

occtl_vector2_t OcctlVector2::to_c() const {
    occtl_vector2_t result = {};
    result.x = x;
    result.y = y;
    return result;
}

Ref<OcctlVector2> OcctlVector2::from_c(const occtl_vector2_t& val) {
    Ref<OcctlVector2> r;
    r.instantiate();
    r->x = val.x;
    r->y = val.y;
    return r;
}

void OcctlVector2::copy_from_c(const occtl_vector2_t& val) {
    x = val.x;
    y = val.y;
}

Ref<OcctlVector2> OcctlVector2::from_vector2(Vector2 v) {
    Ref<OcctlVector2> instance;
    instance.instantiate();
    instance->x = v.x;
    instance->y = v.y;
    return instance;
}
