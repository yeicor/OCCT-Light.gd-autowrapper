#include "OcctlGeomToroidalSurface.h"

#include "OcctlAxis3Placement.h"

Ref<OcctlAxis3Placement> OcctlGeomToroidalSurface::get_position() const { return position; }
void OcctlGeomToroidalSurface::set_position(Ref<OcctlAxis3Placement> val) { position = val; }

double OcctlGeomToroidalSurface::get_major_radius() const { return major_radius; }
void OcctlGeomToroidalSurface::set_major_radius(double val) { major_radius = val; }

double OcctlGeomToroidalSurface::get_minor_radius() const { return minor_radius; }
void OcctlGeomToroidalSurface::set_minor_radius(double val) { minor_radius = val; }

void OcctlGeomToroidalSurface::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_position"), &OcctlGeomToroidalSurface::get_position);
    godot::ClassDB::bind_method(godot::D_METHOD("set_position", "val"), &OcctlGeomToroidalSurface::set_position);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "position"), "set_position", "get_position");
    godot::ClassDB::bind_method(godot::D_METHOD("get_major_radius"), &OcctlGeomToroidalSurface::get_major_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_major_radius", "val"), &OcctlGeomToroidalSurface::set_major_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "major_radius"), "set_major_radius", "get_major_radius");
    godot::ClassDB::bind_method(godot::D_METHOD("get_minor_radius"), &OcctlGeomToroidalSurface::get_minor_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_minor_radius", "val"), &OcctlGeomToroidalSurface::set_minor_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "minor_radius"), "set_minor_radius", "get_minor_radius");
}

occtl_geom_toroidal_surface_t OcctlGeomToroidalSurface::to_c() const {
    occtl_geom_toroidal_surface_t result = {};
    result.position = position->to_c();
    result.major_radius = major_radius;
    result.minor_radius = minor_radius;
    return result;
}

Ref<OcctlGeomToroidalSurface> OcctlGeomToroidalSurface::from_c(const occtl_geom_toroidal_surface_t& val) {
    Ref<OcctlGeomToroidalSurface> r;
    r.instantiate();
    r->position = OcctlAxis3Placement::from_c(val.position);
    r->major_radius = val.major_radius;
    r->minor_radius = val.minor_radius;
    return r;
}

void OcctlGeomToroidalSurface::copy_from_c(const occtl_geom_toroidal_surface_t& val) {
    position = OcctlAxis3Placement::from_c(val.position);
    major_radius = val.major_radius;
    minor_radius = val.minor_radius;
}
