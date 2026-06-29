#include "OcctlGeom2dCircle.h"

#include "OcctlAxis2Placement2d.h"

Ref<OcctlAxis2Placement2d> OcctlGeom2dCircle::get_position() const { return position; }
void OcctlGeom2dCircle::set_position(Ref<OcctlAxis2Placement2d> val) { position = val; }

double OcctlGeom2dCircle::get_radius() const { return radius; }
void OcctlGeom2dCircle::set_radius(double val) { radius = val; }

void OcctlGeom2dCircle::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_position"), &OcctlGeom2dCircle::get_position);
    godot::ClassDB::bind_method(godot::D_METHOD("set_position", "val"), &OcctlGeom2dCircle::set_position);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "position"), "set_position", "get_position");
    godot::ClassDB::bind_method(godot::D_METHOD("get_radius"), &OcctlGeom2dCircle::get_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_radius", "val"), &OcctlGeom2dCircle::set_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "radius"), "set_radius", "get_radius");
}

occtl_geom2d_circle_t OcctlGeom2dCircle::to_c() const {
    occtl_geom2d_circle_t result = {};
    result.position = position->to_c();
    result.radius = radius;
    return result;
}

Ref<OcctlGeom2dCircle> OcctlGeom2dCircle::from_c(const occtl_geom2d_circle_t& val) {
    Ref<OcctlGeom2dCircle> r;
    r.instantiate();
    r->position = OcctlAxis2Placement2d::from_c(val.position);
    r->radius = val.radius;
    return r;
}

void OcctlGeom2dCircle::copy_from_c(const occtl_geom2d_circle_t& val) {
    position = OcctlAxis2Placement2d::from_c(val.position);
    radius = val.radius;
}
