#include "OcctlGeomConicalSurface.h"

#include "OcctlAxis3Placement.h"

Ref<OcctlAxis3Placement> OcctlGeomConicalSurface::get_position() const { return position; }
void OcctlGeomConicalSurface::set_position(Ref<OcctlAxis3Placement> val) { position = val; }

double OcctlGeomConicalSurface::get_semi_angle() const { return semi_angle; }
void OcctlGeomConicalSurface::set_semi_angle(double val) { semi_angle = val; }

double OcctlGeomConicalSurface::get_radius() const { return radius; }
void OcctlGeomConicalSurface::set_radius(double val) { radius = val; }

void OcctlGeomConicalSurface::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_position"), &OcctlGeomConicalSurface::get_position);
    godot::ClassDB::bind_method(godot::D_METHOD("set_position", "val"), &OcctlGeomConicalSurface::set_position);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "position"), "set_position", "get_position");
    godot::ClassDB::bind_method(godot::D_METHOD("get_semi_angle"), &OcctlGeomConicalSurface::get_semi_angle);
    godot::ClassDB::bind_method(godot::D_METHOD("set_semi_angle", "val"), &OcctlGeomConicalSurface::set_semi_angle);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "semi_angle"), "set_semi_angle", "get_semi_angle");
    godot::ClassDB::bind_method(godot::D_METHOD("get_radius"), &OcctlGeomConicalSurface::get_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_radius", "val"), &OcctlGeomConicalSurface::set_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "radius"), "set_radius", "get_radius");
}

occtl_geom_conical_surface_t OcctlGeomConicalSurface::to_c() const {
    occtl_geom_conical_surface_t result = {};
    result.position = position->to_c();
    result.semi_angle = semi_angle;
    result.radius = radius;
    return result;
}

Ref<OcctlGeomConicalSurface> OcctlGeomConicalSurface::from_c(const occtl_geom_conical_surface_t& val) {
    Ref<OcctlGeomConicalSurface> r;
    r.instantiate();
    r->position = OcctlAxis3Placement::from_c(val.position);
    r->semi_angle = val.semi_angle;
    r->radius = val.radius;
    return r;
}

void OcctlGeomConicalSurface::copy_from_c(const occtl_geom_conical_surface_t& val) {
    position = OcctlAxis3Placement::from_c(val.position);
    semi_angle = val.semi_angle;
    radius = val.radius;
}
