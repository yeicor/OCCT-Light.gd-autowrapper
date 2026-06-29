#include "OcctlVector3.h"


double OcctlVector3::get_x() const { return x; }
void OcctlVector3::set_x(double val) { x = val; }

double OcctlVector3::get_y() const { return y; }
void OcctlVector3::set_y(double val) { y = val; }

double OcctlVector3::get_z() const { return z; }
void OcctlVector3::set_z(double val) { z = val; }

void OcctlVector3::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_x"), &OcctlVector3::get_x);
    godot::ClassDB::bind_method(godot::D_METHOD("set_x", "val"), &OcctlVector3::set_x);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "x"), "set_x", "get_x");
    godot::ClassDB::bind_method(godot::D_METHOD("get_y"), &OcctlVector3::get_y);
    godot::ClassDB::bind_method(godot::D_METHOD("set_y", "val"), &OcctlVector3::set_y);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "y"), "set_y", "get_y");
    godot::ClassDB::bind_method(godot::D_METHOD("get_z"), &OcctlVector3::get_z);
    godot::ClassDB::bind_method(godot::D_METHOD("set_z", "val"), &OcctlVector3::set_z);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "z"), "set_z", "get_z");
    godot::ClassDB::bind_static_method("OcctlVector3", godot::D_METHOD("from_vector3", "v"), &OcctlVector3::from_vector3);
}

occtl_vector3_t OcctlVector3::to_c() const {
    occtl_vector3_t result = {};
    result.x = x;
    result.y = y;
    result.z = z;
    return result;
}

Ref<OcctlVector3> OcctlVector3::from_c(const occtl_vector3_t& val) {
    Ref<OcctlVector3> r;
    r.instantiate();
    r->x = val.x;
    r->y = val.y;
    r->z = val.z;
    return r;
}

void OcctlVector3::copy_from_c(const occtl_vector3_t& val) {
    x = val.x;
    y = val.y;
    z = val.z;
}

Ref<OcctlVector3> OcctlVector3::from_vector3(Vector3 v) {
    Ref<OcctlVector3> instance;
    instance.instantiate();
    instance->x = v.x;
    instance->y = v.y;
    instance->z = v.z;
    return instance;
}
