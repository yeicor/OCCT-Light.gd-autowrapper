#include "OcctlGeomPlane.h"

#include "OcctlAxis3Placement.h"

Ref<OcctlAxis3Placement> OcctlGeomPlane::get_position() const { return position; }
void OcctlGeomPlane::set_position(Ref<OcctlAxis3Placement> val) { position = val; }

void OcctlGeomPlane::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_position"), &OcctlGeomPlane::get_position);
    godot::ClassDB::bind_method(godot::D_METHOD("set_position", "val"), &OcctlGeomPlane::set_position);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "position"), "set_position", "get_position");
}

occtl_geom_plane_t OcctlGeomPlane::to_c() const {
    occtl_geom_plane_t result = {};
    result.position = position->to_c();
    return result;
}

Ref<OcctlGeomPlane> OcctlGeomPlane::from_c(const occtl_geom_plane_t& val) {
    Ref<OcctlGeomPlane> r;
    r.instantiate();
    r->position = OcctlAxis3Placement::from_c(val.position);
    return r;
}

void OcctlGeomPlane::copy_from_c(const occtl_geom_plane_t& val) {
    position = OcctlAxis3Placement::from_c(val.position);
}
