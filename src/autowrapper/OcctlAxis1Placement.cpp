#include "OcctlAxis1Placement.h"

#include "OcctlPoint3.h"
#include "OcctlDirection3.h"

Ref<OcctlPoint3> OcctlAxis1Placement::get_location() const { return location; }
void OcctlAxis1Placement::set_location(Ref<OcctlPoint3> val) { location = val; }

Ref<OcctlDirection3> OcctlAxis1Placement::get_direction() const { return direction; }
void OcctlAxis1Placement::set_direction(Ref<OcctlDirection3> val) { direction = val; }

void OcctlAxis1Placement::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_location"), &OcctlAxis1Placement::get_location);
    godot::ClassDB::bind_method(godot::D_METHOD("set_location", "val"), &OcctlAxis1Placement::set_location);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "location"), "set_location", "get_location");
    godot::ClassDB::bind_method(godot::D_METHOD("get_direction"), &OcctlAxis1Placement::get_direction);
    godot::ClassDB::bind_method(godot::D_METHOD("set_direction", "val"), &OcctlAxis1Placement::set_direction);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "direction"), "set_direction", "get_direction");
    godot::ClassDB::bind_static_method("OcctlAxis1Placement", godot::D_METHOD("from_components", "point", "direction"), &OcctlAxis1Placement::from_components);
}

occtl_axis1_placement_t OcctlAxis1Placement::to_c() const {
    occtl_axis1_placement_t result = {};
    result.location = location->to_c();
    result.direction = direction->to_c();
    return result;
}

Ref<OcctlAxis1Placement> OcctlAxis1Placement::from_c(const occtl_axis1_placement_t& val) {
    Ref<OcctlAxis1Placement> r;
    r.instantiate();
    r->location = OcctlPoint3::from_c(val.location);
    r->direction = OcctlDirection3::from_c(val.direction);
    return r;
}

void OcctlAxis1Placement::copy_from_c(const occtl_axis1_placement_t& val) {
    location = OcctlPoint3::from_c(val.location);
    direction = OcctlDirection3::from_c(val.direction);
}

Ref<OcctlAxis1Placement> OcctlAxis1Placement::from_components(Vector3 point, Vector3 direction) {
    Ref<OcctlAxis1Placement> instance;
    instance.instantiate();
    { auto _loc = occtl_point3_t{}; _loc.x = point.x; _loc.y = point.y; _loc.z = point.z; instance->location = OcctlPoint3::from_c(_loc); }
    { auto _dir = occtl_direction3_t{}; _dir.x = direction.x; _dir.y = direction.y; _dir.z = direction.z; instance->direction = OcctlDirection3::from_c(_dir); }
    return instance;
}
