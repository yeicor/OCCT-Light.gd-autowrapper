#include "OcctlGeom2dLine.h"

#include "OcctlAxis2Placement2d.h"

Ref<OcctlAxis2Placement2d> OcctlGeom2dLine::get_position() const { return position; }
void OcctlGeom2dLine::set_position(Ref<OcctlAxis2Placement2d> val) { position = val; }

void OcctlGeom2dLine::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_position"), &OcctlGeom2dLine::get_position);
    godot::ClassDB::bind_method(godot::D_METHOD("set_position", "val"), &OcctlGeom2dLine::set_position);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "position"), "set_position", "get_position");
}

occtl_geom2d_line_t OcctlGeom2dLine::to_c() const {
    occtl_geom2d_line_t result = {};
    result.position = position->to_c();
    return result;
}

Ref<OcctlGeom2dLine> OcctlGeom2dLine::from_c(const occtl_geom2d_line_t& val) {
    Ref<OcctlGeom2dLine> r;
    r.instantiate();
    r->position = OcctlAxis2Placement2d::from_c(val.position);
    return r;
}

void OcctlGeom2dLine::copy_from_c(const occtl_geom2d_line_t& val) {
    position = OcctlAxis2Placement2d::from_c(val.position);
}
