#include "OcctlGraphObb.h"

#include "OcctlPoint3.h"
#include "OcctlDirection3.h"

Ref<OcctlPoint3> OcctlGraphObb::get_center() const { return center; }
void OcctlGraphObb::set_center(Ref<OcctlPoint3> val) { center = val; }

Ref<OcctlDirection3> OcctlGraphObb::get_x_direction() const { return x_direction; }
void OcctlGraphObb::set_x_direction(Ref<OcctlDirection3> val) { x_direction = val; }

Ref<OcctlDirection3> OcctlGraphObb::get_y_direction() const { return y_direction; }
void OcctlGraphObb::set_y_direction(Ref<OcctlDirection3> val) { y_direction = val; }

Ref<OcctlDirection3> OcctlGraphObb::get_z_direction() const { return z_direction; }
void OcctlGraphObb::set_z_direction(Ref<OcctlDirection3> val) { z_direction = val; }

double OcctlGraphObb::get_x_half_size() const { return x_half_size; }
void OcctlGraphObb::set_x_half_size(double val) { x_half_size = val; }

double OcctlGraphObb::get_y_half_size() const { return y_half_size; }
void OcctlGraphObb::set_y_half_size(double val) { y_half_size = val; }

double OcctlGraphObb::get_z_half_size() const { return z_half_size; }
void OcctlGraphObb::set_z_half_size(double val) { z_half_size = val; }

void OcctlGraphObb::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_center"), &OcctlGraphObb::get_center);
    godot::ClassDB::bind_method(godot::D_METHOD("set_center", "val"), &OcctlGraphObb::set_center);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "center"), "set_center", "get_center");
    godot::ClassDB::bind_method(godot::D_METHOD("get_x_direction"), &OcctlGraphObb::get_x_direction);
    godot::ClassDB::bind_method(godot::D_METHOD("set_x_direction", "val"), &OcctlGraphObb::set_x_direction);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "x_direction"), "set_x_direction", "get_x_direction");
    godot::ClassDB::bind_method(godot::D_METHOD("get_y_direction"), &OcctlGraphObb::get_y_direction);
    godot::ClassDB::bind_method(godot::D_METHOD("set_y_direction", "val"), &OcctlGraphObb::set_y_direction);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "y_direction"), "set_y_direction", "get_y_direction");
    godot::ClassDB::bind_method(godot::D_METHOD("get_z_direction"), &OcctlGraphObb::get_z_direction);
    godot::ClassDB::bind_method(godot::D_METHOD("set_z_direction", "val"), &OcctlGraphObb::set_z_direction);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "z_direction"), "set_z_direction", "get_z_direction");
    godot::ClassDB::bind_method(godot::D_METHOD("get_x_half_size"), &OcctlGraphObb::get_x_half_size);
    godot::ClassDB::bind_method(godot::D_METHOD("set_x_half_size", "val"), &OcctlGraphObb::set_x_half_size);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "x_half_size"), "set_x_half_size", "get_x_half_size");
    godot::ClassDB::bind_method(godot::D_METHOD("get_y_half_size"), &OcctlGraphObb::get_y_half_size);
    godot::ClassDB::bind_method(godot::D_METHOD("set_y_half_size", "val"), &OcctlGraphObb::set_y_half_size);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "y_half_size"), "set_y_half_size", "get_y_half_size");
    godot::ClassDB::bind_method(godot::D_METHOD("get_z_half_size"), &OcctlGraphObb::get_z_half_size);
    godot::ClassDB::bind_method(godot::D_METHOD("set_z_half_size", "val"), &OcctlGraphObb::set_z_half_size);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "z_half_size"), "set_z_half_size", "get_z_half_size");
}

occtl_graph_obb_t OcctlGraphObb::to_c() const {
    occtl_graph_obb_t result = {};
    result.center = center->to_c();
    result.x_direction = x_direction->to_c();
    result.y_direction = y_direction->to_c();
    result.z_direction = z_direction->to_c();
    result.x_half_size = x_half_size;
    result.y_half_size = y_half_size;
    result.z_half_size = z_half_size;
    return result;
}

Ref<OcctlGraphObb> OcctlGraphObb::from_c(const occtl_graph_obb_t& val) {
    Ref<OcctlGraphObb> r;
    r.instantiate();
    r->center = OcctlPoint3::from_c(val.center);
    r->x_direction = OcctlDirection3::from_c(val.x_direction);
    r->y_direction = OcctlDirection3::from_c(val.y_direction);
    r->z_direction = OcctlDirection3::from_c(val.z_direction);
    r->x_half_size = val.x_half_size;
    r->y_half_size = val.y_half_size;
    r->z_half_size = val.z_half_size;
    return r;
}

void OcctlGraphObb::copy_from_c(const occtl_graph_obb_t& val) {
    center = OcctlPoint3::from_c(val.center);
    x_direction = OcctlDirection3::from_c(val.x_direction);
    y_direction = OcctlDirection3::from_c(val.y_direction);
    z_direction = OcctlDirection3::from_c(val.z_direction);
    x_half_size = val.x_half_size;
    y_half_size = val.y_half_size;
    z_half_size = val.z_half_size;
}
