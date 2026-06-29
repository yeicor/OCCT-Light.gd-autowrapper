#include "OcctlGeom2dParabola.h"

#include "OcctlAxis2Placement2d.h"

Ref<OcctlAxis2Placement2d> OcctlGeom2dParabola::get_position() const { return position; }
void OcctlGeom2dParabola::set_position(Ref<OcctlAxis2Placement2d> val) { position = val; }

double OcctlGeom2dParabola::get_focal_length() const { return focal_length; }
void OcctlGeom2dParabola::set_focal_length(double val) { focal_length = val; }

void OcctlGeom2dParabola::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_position"), &OcctlGeom2dParabola::get_position);
    godot::ClassDB::bind_method(godot::D_METHOD("set_position", "val"), &OcctlGeom2dParabola::set_position);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "position"), "set_position", "get_position");
    godot::ClassDB::bind_method(godot::D_METHOD("get_focal_length"), &OcctlGeom2dParabola::get_focal_length);
    godot::ClassDB::bind_method(godot::D_METHOD("set_focal_length", "val"), &OcctlGeom2dParabola::set_focal_length);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "focal_length"), "set_focal_length", "get_focal_length");
}

occtl_geom2d_parabola_t OcctlGeom2dParabola::to_c() const {
    occtl_geom2d_parabola_t result = {};
    result.position = position->to_c();
    result.focal_length = focal_length;
    return result;
}

Ref<OcctlGeom2dParabola> OcctlGeom2dParabola::from_c(const occtl_geom2d_parabola_t& val) {
    Ref<OcctlGeom2dParabola> r;
    r.instantiate();
    r->position = OcctlAxis2Placement2d::from_c(val.position);
    r->focal_length = val.focal_length;
    return r;
}

void OcctlGeom2dParabola::copy_from_c(const occtl_geom2d_parabola_t& val) {
    position = OcctlAxis2Placement2d::from_c(val.position);
    focal_length = val.focal_length;
}
