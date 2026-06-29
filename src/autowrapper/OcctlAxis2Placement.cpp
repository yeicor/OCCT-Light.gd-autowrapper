#include "OcctlAxis2Placement.h"

#include "OcctlPoint3.h"
#include "OcctlDirection3.h"

Ref<OcctlPoint3> OcctlAxis2Placement::get_location() const { return location; }
void OcctlAxis2Placement::set_location(Ref<OcctlPoint3> val) { location = val; }

Ref<OcctlDirection3> OcctlAxis2Placement::get_x_dir() const { return x_dir; }
void OcctlAxis2Placement::set_x_dir(Ref<OcctlDirection3> val) { x_dir = val; }

Ref<OcctlDirection3> OcctlAxis2Placement::get_x_dir_ref() const { return x_dir_ref; }
void OcctlAxis2Placement::set_x_dir_ref(Ref<OcctlDirection3> val) { x_dir_ref = val; }

void OcctlAxis2Placement::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_location"), &OcctlAxis2Placement::get_location);
    godot::ClassDB::bind_method(godot::D_METHOD("set_location", "val"), &OcctlAxis2Placement::set_location);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "location"), "set_location", "get_location");
    godot::ClassDB::bind_method(godot::D_METHOD("get_x_dir"), &OcctlAxis2Placement::get_x_dir);
    godot::ClassDB::bind_method(godot::D_METHOD("set_x_dir", "val"), &OcctlAxis2Placement::set_x_dir);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "x_dir"), "set_x_dir", "get_x_dir");
    godot::ClassDB::bind_method(godot::D_METHOD("get_x_dir_ref"), &OcctlAxis2Placement::get_x_dir_ref);
    godot::ClassDB::bind_method(godot::D_METHOD("set_x_dir_ref", "val"), &OcctlAxis2Placement::set_x_dir_ref);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "x_dir_ref"), "set_x_dir_ref", "get_x_dir_ref");
    godot::ClassDB::bind_static_method("OcctlAxis2Placement", godot::D_METHOD("from_components", "point", "z_dir", "x_dir"), &OcctlAxis2Placement::from_components);
}

occtl_axis2_placement_t OcctlAxis2Placement::to_c() const {
    occtl_axis2_placement_t result = {};
    result.location = location->to_c();
    result.x_dir = x_dir->to_c();
    result.x_dir_ref = x_dir_ref->to_c();
    return result;
}

Ref<OcctlAxis2Placement> OcctlAxis2Placement::from_c(const occtl_axis2_placement_t& val) {
    Ref<OcctlAxis2Placement> r;
    r.instantiate();
    r->location = OcctlPoint3::from_c(val.location);
    r->x_dir = OcctlDirection3::from_c(val.x_dir);
    r->x_dir_ref = OcctlDirection3::from_c(val.x_dir_ref);
    return r;
}

void OcctlAxis2Placement::copy_from_c(const occtl_axis2_placement_t& val) {
    location = OcctlPoint3::from_c(val.location);
    x_dir = OcctlDirection3::from_c(val.x_dir);
    x_dir_ref = OcctlDirection3::from_c(val.x_dir_ref);
}

Ref<OcctlAxis2Placement> OcctlAxis2Placement::from_components(Vector3 point, Vector3 z_dir, Vector3 x_dir) {
    Ref<OcctlAxis2Placement> instance;
    instance.instantiate();
    { auto _loc = occtl_point3_t{}; _loc.x = point.x; _loc.y = point.y; _loc.z = point.z; instance->location = OcctlPoint3::from_c(_loc); }
    { auto _x = occtl_direction3_t{}; _x.x = x_dir.x; _x.y = x_dir.y; _x.z = x_dir.z; instance->x_dir = OcctlDirection3::from_c(_x); }
    { auto _ref = occtl_direction3_t{}; _ref.x = z_dir.x; _ref.y = z_dir.y; _ref.z = z_dir.z; instance->x_dir_ref = OcctlDirection3::from_c(_ref); }
    return instance;
}
