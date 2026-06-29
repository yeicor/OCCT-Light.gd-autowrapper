#include "OcctlGeomParabola.h"

#include "OcctlAxis2Placement.h"

Ref<OcctlAxis2Placement> OcctlGeomParabola::get_position() const { return position; }
void OcctlGeomParabola::set_position(Ref<OcctlAxis2Placement> val) { position = val; }

double OcctlGeomParabola::get_focal_length() const { return focal_length; }
void OcctlGeomParabola::set_focal_length(double val) { focal_length = val; }

void OcctlGeomParabola::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_position"), &OcctlGeomParabola::get_position);
    godot::ClassDB::bind_method(godot::D_METHOD("set_position", "val"), &OcctlGeomParabola::set_position);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "position"), "set_position", "get_position");
    godot::ClassDB::bind_method(godot::D_METHOD("get_focal_length"), &OcctlGeomParabola::get_focal_length);
    godot::ClassDB::bind_method(godot::D_METHOD("set_focal_length", "val"), &OcctlGeomParabola::set_focal_length);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "focal_length"), "set_focal_length", "get_focal_length");
}

occtl_geom_parabola_t OcctlGeomParabola::to_c() const {
    occtl_geom_parabola_t result = {};
    result.position = position->to_c();
    result.focal_length = focal_length;
    return result;
}

Ref<OcctlGeomParabola> OcctlGeomParabola::from_c(const occtl_geom_parabola_t& val) {
    Ref<OcctlGeomParabola> r;
    r.instantiate();
    r->position = OcctlAxis2Placement::from_c(val.position);
    r->focal_length = val.focal_length;
    return r;
}

void OcctlGeomParabola::copy_from_c(const occtl_geom_parabola_t& val) {
    position = OcctlAxis2Placement::from_c(val.position);
    focal_length = val.focal_length;
}
