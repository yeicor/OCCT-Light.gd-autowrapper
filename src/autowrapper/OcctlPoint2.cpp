#include "OcctlPoint2.h"


double OcctlPoint2::get_x() const { return x; }
void OcctlPoint2::set_x(double val) { x = val; }

double OcctlPoint2::get_y() const { return y; }
void OcctlPoint2::set_y(double val) { y = val; }

void OcctlPoint2::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_x"), &OcctlPoint2::get_x);
    godot::ClassDB::bind_method(godot::D_METHOD("set_x", "val"), &OcctlPoint2::set_x);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "x"), "set_x", "get_x");
    godot::ClassDB::bind_method(godot::D_METHOD("get_y"), &OcctlPoint2::get_y);
    godot::ClassDB::bind_method(godot::D_METHOD("set_y", "val"), &OcctlPoint2::set_y);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "y"), "set_y", "get_y");
    godot::ClassDB::bind_static_method("OcctlPoint2", godot::D_METHOD("from_vector2", "v"), &OcctlPoint2::from_vector2);
}

occtl_point2_t OcctlPoint2::to_c() const {
    occtl_point2_t result = {};
    result.x = x;
    result.y = y;
    return result;
}

Ref<OcctlPoint2> OcctlPoint2::from_c(const occtl_point2_t& val) {
    Ref<OcctlPoint2> r;
    r.instantiate();
    r->x = val.x;
    r->y = val.y;
    return r;
}

void OcctlPoint2::copy_from_c(const occtl_point2_t& val) {
    x = val.x;
    y = val.y;
}

Ref<OcctlPoint2> OcctlPoint2::from_vector2(Vector2 v) {
    Ref<OcctlPoint2> instance;
    instance.instantiate();
    instance->x = v.x;
    instance->y = v.y;
    return instance;
}
