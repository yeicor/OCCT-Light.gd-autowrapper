#include "OcctlGeomCylindricalSurface.h"

#include "OcctlAxis3Placement.h"

Ref<OcctlAxis3Placement> OcctlGeomCylindricalSurface::get_position() const { return position; }
void OcctlGeomCylindricalSurface::set_position(Ref<OcctlAxis3Placement> val) { position = val; }

double OcctlGeomCylindricalSurface::get_radius() const { return radius; }
void OcctlGeomCylindricalSurface::set_radius(double val) { radius = val; }

void OcctlGeomCylindricalSurface::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_position"), &OcctlGeomCylindricalSurface::get_position);
    godot::ClassDB::bind_method(godot::D_METHOD("set_position", "val"), &OcctlGeomCylindricalSurface::set_position);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "position"), "set_position", "get_position");
    godot::ClassDB::bind_method(godot::D_METHOD("get_radius"), &OcctlGeomCylindricalSurface::get_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_radius", "val"), &OcctlGeomCylindricalSurface::set_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "radius"), "set_radius", "get_radius");
}

occtl_geom_cylindrical_surface_t OcctlGeomCylindricalSurface::to_c() const {
    occtl_geom_cylindrical_surface_t result = {};
    result.position = position->to_c();
    result.radius = radius;
    return result;
}

Ref<OcctlGeomCylindricalSurface> OcctlGeomCylindricalSurface::from_c(const occtl_geom_cylindrical_surface_t& val) {
    Ref<OcctlGeomCylindricalSurface> r;
    r.instantiate();
    r->position = OcctlAxis3Placement::from_c(val.position);
    r->radius = val.radius;
    return r;
}

void OcctlGeomCylindricalSurface::copy_from_c(const occtl_geom_cylindrical_surface_t& val) {
    position = OcctlAxis3Placement::from_c(val.position);
    radius = val.radius;
}
