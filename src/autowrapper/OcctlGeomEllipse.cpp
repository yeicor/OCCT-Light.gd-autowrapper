#include "OcctlGeomEllipse.h"

#include "OcctlAxis2Placement.h"

Ref<OcctlAxis2Placement> OcctlGeomEllipse::get_position() const { return position; }
void OcctlGeomEllipse::set_position(Ref<OcctlAxis2Placement> val) { position = val; }

double OcctlGeomEllipse::get_major_radius() const { return major_radius; }
void OcctlGeomEllipse::set_major_radius(double val) { major_radius = val; }

double OcctlGeomEllipse::get_minor_radius() const { return minor_radius; }
void OcctlGeomEllipse::set_minor_radius(double val) { minor_radius = val; }

void OcctlGeomEllipse::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_position"), &OcctlGeomEllipse::get_position);
    godot::ClassDB::bind_method(godot::D_METHOD("set_position", "val"), &OcctlGeomEllipse::set_position);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "position"), "set_position", "get_position");
    godot::ClassDB::bind_method(godot::D_METHOD("get_major_radius"), &OcctlGeomEllipse::get_major_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_major_radius", "val"), &OcctlGeomEllipse::set_major_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "major_radius"), "set_major_radius", "get_major_radius");
    godot::ClassDB::bind_method(godot::D_METHOD("get_minor_radius"), &OcctlGeomEllipse::get_minor_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_minor_radius", "val"), &OcctlGeomEllipse::set_minor_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "minor_radius"), "set_minor_radius", "get_minor_radius");
}

occtl_geom_ellipse_t OcctlGeomEllipse::to_c() const {
    occtl_geom_ellipse_t result = {};
    result.position = position->to_c();
    result.major_radius = major_radius;
    result.minor_radius = minor_radius;
    return result;
}

Ref<OcctlGeomEllipse> OcctlGeomEllipse::from_c(const occtl_geom_ellipse_t& val) {
    Ref<OcctlGeomEllipse> r;
    r.instantiate();
    r->position = OcctlAxis2Placement::from_c(val.position);
    r->major_radius = val.major_radius;
    r->minor_radius = val.minor_radius;
    return r;
}

void OcctlGeomEllipse::copy_from_c(const occtl_geom_ellipse_t& val) {
    position = OcctlAxis2Placement::from_c(val.position);
    major_radius = val.major_radius;
    minor_radius = val.minor_radius;
}
