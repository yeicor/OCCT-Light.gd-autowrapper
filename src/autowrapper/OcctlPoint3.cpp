#include "OcctlPoint3.h"


double OcctlPoint3::get_x() const { return x; }
void OcctlPoint3::set_x(double val) { x = val; }

double OcctlPoint3::get_y() const { return y; }
void OcctlPoint3::set_y(double val) { y = val; }

double OcctlPoint3::get_z() const { return z; }
void OcctlPoint3::set_z(double val) { z = val; }

void OcctlPoint3::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_x"), &OcctlPoint3::get_x);
    godot::ClassDB::bind_method(godot::D_METHOD("set_x", "val"), &OcctlPoint3::set_x);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "x"), "set_x", "get_x");
    godot::ClassDB::bind_method(godot::D_METHOD("get_y"), &OcctlPoint3::get_y);
    godot::ClassDB::bind_method(godot::D_METHOD("set_y", "val"), &OcctlPoint3::set_y);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "y"), "set_y", "get_y");
    godot::ClassDB::bind_method(godot::D_METHOD("get_z"), &OcctlPoint3::get_z);
    godot::ClassDB::bind_method(godot::D_METHOD("set_z", "val"), &OcctlPoint3::set_z);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "z"), "set_z", "get_z");
    godot::ClassDB::bind_static_method("OcctlPoint3", godot::D_METHOD("from_vector3", "v"), &OcctlPoint3::from_vector3);
}

occtl_point3_t OcctlPoint3::to_c() const {
    occtl_point3_t result = {};
    result.x = x;
    result.y = y;
    result.z = z;
    return result;
}

Ref<OcctlPoint3> OcctlPoint3::from_c(const occtl_point3_t& val) {
    Ref<OcctlPoint3> r;
    r.instantiate();
    r->x = val.x;
    r->y = val.y;
    r->z = val.z;
    return r;
}

void OcctlPoint3::copy_from_c(const occtl_point3_t& val) {
    x = val.x;
    y = val.y;
    z = val.z;
}

Ref<OcctlPoint3> OcctlPoint3::from_vector3(Vector3 v) {
    Ref<OcctlPoint3> instance;
    instance.instantiate();
    instance->x = v.x;
    instance->y = v.y;
    instance->z = v.z;
    return instance;
}
