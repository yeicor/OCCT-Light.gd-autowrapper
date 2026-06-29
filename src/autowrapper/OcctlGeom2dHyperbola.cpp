#include "OcctlGeom2dHyperbola.h"

#include "OcctlAxis2Placement2d.h"

Ref<OcctlAxis2Placement2d> OcctlGeom2dHyperbola::get_position() const { return position; }
void OcctlGeom2dHyperbola::set_position(Ref<OcctlAxis2Placement2d> val) { position = val; }

double OcctlGeom2dHyperbola::get_major_radius() const { return major_radius; }
void OcctlGeom2dHyperbola::set_major_radius(double val) { major_radius = val; }

double OcctlGeom2dHyperbola::get_minor_radius() const { return minor_radius; }
void OcctlGeom2dHyperbola::set_minor_radius(double val) { minor_radius = val; }

void OcctlGeom2dHyperbola::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_position"), &OcctlGeom2dHyperbola::get_position);
    godot::ClassDB::bind_method(godot::D_METHOD("set_position", "val"), &OcctlGeom2dHyperbola::set_position);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "position"), "set_position", "get_position");
    godot::ClassDB::bind_method(godot::D_METHOD("get_major_radius"), &OcctlGeom2dHyperbola::get_major_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_major_radius", "val"), &OcctlGeom2dHyperbola::set_major_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "major_radius"), "set_major_radius", "get_major_radius");
    godot::ClassDB::bind_method(godot::D_METHOD("get_minor_radius"), &OcctlGeom2dHyperbola::get_minor_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_minor_radius", "val"), &OcctlGeom2dHyperbola::set_minor_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "minor_radius"), "set_minor_radius", "get_minor_radius");
}

occtl_geom2d_hyperbola_t OcctlGeom2dHyperbola::to_c() const {
    occtl_geom2d_hyperbola_t result = {};
    result.position = position->to_c();
    result.major_radius = major_radius;
    result.minor_radius = minor_radius;
    return result;
}

Ref<OcctlGeom2dHyperbola> OcctlGeom2dHyperbola::from_c(const occtl_geom2d_hyperbola_t& val) {
    Ref<OcctlGeom2dHyperbola> r;
    r.instantiate();
    r->position = OcctlAxis2Placement2d::from_c(val.position);
    r->major_radius = val.major_radius;
    r->minor_radius = val.minor_radius;
    return r;
}

void OcctlGeom2dHyperbola::copy_from_c(const occtl_geom2d_hyperbola_t& val) {
    position = OcctlAxis2Placement2d::from_c(val.position);
    major_radius = val.major_radius;
    minor_radius = val.minor_radius;
}
