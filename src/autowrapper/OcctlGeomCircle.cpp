#include "OcctlGeomCircle.h"

#include "OcctlAxis2Placement.h"

Ref<OcctlAxis2Placement> OcctlGeomCircle::get_position() const { return position; }
void OcctlGeomCircle::set_position(Ref<OcctlAxis2Placement> val) { position = val; }

double OcctlGeomCircle::get_radius() const { return radius; }
void OcctlGeomCircle::set_radius(double val) { radius = val; }

void OcctlGeomCircle::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_position"), &OcctlGeomCircle::get_position);
    godot::ClassDB::bind_method(godot::D_METHOD("set_position", "val"), &OcctlGeomCircle::set_position);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "position"), "set_position", "get_position");
    godot::ClassDB::bind_method(godot::D_METHOD("get_radius"), &OcctlGeomCircle::get_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_radius", "val"), &OcctlGeomCircle::set_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "radius"), "set_radius", "get_radius");
}

occtl_geom_circle_t OcctlGeomCircle::to_c() const {
    occtl_geom_circle_t result = {};
    result.position = position->to_c();
    result.radius = radius;
    return result;
}

Ref<OcctlGeomCircle> OcctlGeomCircle::from_c(const occtl_geom_circle_t& val) {
    Ref<OcctlGeomCircle> r;
    r.instantiate();
    r->position = OcctlAxis2Placement::from_c(val.position);
    r->radius = val.radius;
    return r;
}

void OcctlGeomCircle::copy_from_c(const occtl_geom_circle_t& val) {
    position = OcctlAxis2Placement::from_c(val.position);
    radius = val.radius;
}
