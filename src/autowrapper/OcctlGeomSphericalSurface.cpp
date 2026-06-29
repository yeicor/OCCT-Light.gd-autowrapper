#include "OcctlGeomSphericalSurface.h"

#include "OcctlAxis3Placement.h"

Ref<OcctlAxis3Placement> OcctlGeomSphericalSurface::get_position() const { return position; }
void OcctlGeomSphericalSurface::set_position(Ref<OcctlAxis3Placement> val) { position = val; }

double OcctlGeomSphericalSurface::get_radius() const { return radius; }
void OcctlGeomSphericalSurface::set_radius(double val) { radius = val; }

void OcctlGeomSphericalSurface::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_position"), &OcctlGeomSphericalSurface::get_position);
    godot::ClassDB::bind_method(godot::D_METHOD("set_position", "val"), &OcctlGeomSphericalSurface::set_position);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "position"), "set_position", "get_position");
    godot::ClassDB::bind_method(godot::D_METHOD("get_radius"), &OcctlGeomSphericalSurface::get_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_radius", "val"), &OcctlGeomSphericalSurface::set_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "radius"), "set_radius", "get_radius");
}

occtl_geom_spherical_surface_t OcctlGeomSphericalSurface::to_c() const {
    occtl_geom_spherical_surface_t result = {};
    result.position = position->to_c();
    result.radius = radius;
    return result;
}

Ref<OcctlGeomSphericalSurface> OcctlGeomSphericalSurface::from_c(const occtl_geom_spherical_surface_t& val) {
    Ref<OcctlGeomSphericalSurface> r;
    r.instantiate();
    r->position = OcctlAxis3Placement::from_c(val.position);
    r->radius = val.radius;
    return r;
}

void OcctlGeomSphericalSurface::copy_from_c(const occtl_geom_spherical_surface_t& val) {
    position = OcctlAxis3Placement::from_c(val.position);
    radius = val.radius;
}
