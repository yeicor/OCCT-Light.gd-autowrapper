#include "OcctlGeomHyperbola.h"

#include "OcctlAxis2Placement.h"

Ref<OcctlAxis2Placement> OcctlGeomHyperbola::get_position() const { return position; }
void OcctlGeomHyperbola::set_position(Ref<OcctlAxis2Placement> val) { position = val; }

double OcctlGeomHyperbola::get_major_radius() const { return major_radius; }
void OcctlGeomHyperbola::set_major_radius(double val) { major_radius = val; }

double OcctlGeomHyperbola::get_minor_radius() const { return minor_radius; }
void OcctlGeomHyperbola::set_minor_radius(double val) { minor_radius = val; }

void OcctlGeomHyperbola::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_position"), &OcctlGeomHyperbola::get_position);
    godot::ClassDB::bind_method(godot::D_METHOD("set_position", "val"), &OcctlGeomHyperbola::set_position);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "position"), "set_position", "get_position");
    godot::ClassDB::bind_method(godot::D_METHOD("get_major_radius"), &OcctlGeomHyperbola::get_major_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_major_radius", "val"), &OcctlGeomHyperbola::set_major_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "major_radius"), "set_major_radius", "get_major_radius");
    godot::ClassDB::bind_method(godot::D_METHOD("get_minor_radius"), &OcctlGeomHyperbola::get_minor_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_minor_radius", "val"), &OcctlGeomHyperbola::set_minor_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "minor_radius"), "set_minor_radius", "get_minor_radius");
}

occtl_geom_hyperbola_t OcctlGeomHyperbola::to_c() const {
    occtl_geom_hyperbola_t result = {};
    result.position = position->to_c();
    result.major_radius = major_radius;
    result.minor_radius = minor_radius;
    return result;
}

Ref<OcctlGeomHyperbola> OcctlGeomHyperbola::from_c(const occtl_geom_hyperbola_t& val) {
    Ref<OcctlGeomHyperbola> r;
    r.instantiate();
    r->position = OcctlAxis2Placement::from_c(val.position);
    r->major_radius = val.major_radius;
    r->minor_radius = val.minor_radius;
    return r;
}

void OcctlGeomHyperbola::copy_from_c(const occtl_geom_hyperbola_t& val) {
    position = OcctlAxis2Placement::from_c(val.position);
    major_radius = val.major_radius;
    minor_radius = val.minor_radius;
}
