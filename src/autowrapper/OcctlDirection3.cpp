#include "OcctlDirection3.h"


double OcctlDirection3::get_x() const { return x; }
void OcctlDirection3::set_x(double val) { x = val; }

double OcctlDirection3::get_y() const { return y; }
void OcctlDirection3::set_y(double val) { y = val; }

double OcctlDirection3::get_z() const { return z; }
void OcctlDirection3::set_z(double val) { z = val; }

void OcctlDirection3::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_x"), &OcctlDirection3::get_x);
    godot::ClassDB::bind_method(godot::D_METHOD("set_x", "val"), &OcctlDirection3::set_x);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "x"), "set_x", "get_x");
    godot::ClassDB::bind_method(godot::D_METHOD("get_y"), &OcctlDirection3::get_y);
    godot::ClassDB::bind_method(godot::D_METHOD("set_y", "val"), &OcctlDirection3::set_y);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "y"), "set_y", "get_y");
    godot::ClassDB::bind_method(godot::D_METHOD("get_z"), &OcctlDirection3::get_z);
    godot::ClassDB::bind_method(godot::D_METHOD("set_z", "val"), &OcctlDirection3::set_z);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "z"), "set_z", "get_z");
    godot::ClassDB::bind_static_method("OcctlDirection3", godot::D_METHOD("from_vector3", "v"), &OcctlDirection3::from_vector3);
}

occtl_direction3_t OcctlDirection3::to_c() const {
    occtl_direction3_t result = {};
    result.x = x;
    result.y = y;
    result.z = z;
    return result;
}

Ref<OcctlDirection3> OcctlDirection3::from_c(const occtl_direction3_t& val) {
    Ref<OcctlDirection3> r;
    r.instantiate();
    r->x = val.x;
    r->y = val.y;
    r->z = val.z;
    return r;
}

void OcctlDirection3::copy_from_c(const occtl_direction3_t& val) {
    x = val.x;
    y = val.y;
    z = val.z;
}

Ref<OcctlDirection3> OcctlDirection3::from_vector3(Vector3 v) {
    Ref<OcctlDirection3> instance;
    instance.instantiate();
    instance->x = v.x;
    instance->y = v.y;
    instance->z = v.z;
    return instance;
}
