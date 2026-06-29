#include "OcctlAxis3Placement.h"

#include "OcctlPoint3.h"
#include "OcctlDirection3.h"

Ref<OcctlPoint3> OcctlAxis3Placement::get_location() const { return location; }
void OcctlAxis3Placement::set_location(Ref<OcctlPoint3> val) { location = val; }

Ref<OcctlDirection3> OcctlAxis3Placement::get_x_dir() const { return x_dir; }
void OcctlAxis3Placement::set_x_dir(Ref<OcctlDirection3> val) { x_dir = val; }

Ref<OcctlDirection3> OcctlAxis3Placement::get_y_dir() const { return y_dir; }
void OcctlAxis3Placement::set_y_dir(Ref<OcctlDirection3> val) { y_dir = val; }

Ref<OcctlDirection3> OcctlAxis3Placement::get_z_dir() const { return z_dir; }
void OcctlAxis3Placement::set_z_dir(Ref<OcctlDirection3> val) { z_dir = val; }

void OcctlAxis3Placement::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_location"), &OcctlAxis3Placement::get_location);
    godot::ClassDB::bind_method(godot::D_METHOD("set_location", "val"), &OcctlAxis3Placement::set_location);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "location"), "set_location", "get_location");
    godot::ClassDB::bind_method(godot::D_METHOD("get_x_dir"), &OcctlAxis3Placement::get_x_dir);
    godot::ClassDB::bind_method(godot::D_METHOD("set_x_dir", "val"), &OcctlAxis3Placement::set_x_dir);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "x_dir"), "set_x_dir", "get_x_dir");
    godot::ClassDB::bind_method(godot::D_METHOD("get_y_dir"), &OcctlAxis3Placement::get_y_dir);
    godot::ClassDB::bind_method(godot::D_METHOD("set_y_dir", "val"), &OcctlAxis3Placement::set_y_dir);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "y_dir"), "set_y_dir", "get_y_dir");
    godot::ClassDB::bind_method(godot::D_METHOD("get_z_dir"), &OcctlAxis3Placement::get_z_dir);
    godot::ClassDB::bind_method(godot::D_METHOD("set_z_dir", "val"), &OcctlAxis3Placement::set_z_dir);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "z_dir"), "set_z_dir", "get_z_dir");
    godot::ClassDB::bind_static_method("OcctlAxis3Placement", godot::D_METHOD("from_components", "point", "z_dir", "x_dir"), &OcctlAxis3Placement::from_components);
}

occtl_axis3_placement_t OcctlAxis3Placement::to_c() const {
    occtl_axis3_placement_t result = {};
    result.location = location->to_c();
    result.x_dir = x_dir->to_c();
    result.y_dir = y_dir->to_c();
    result.z_dir = z_dir->to_c();
    return result;
}

Ref<OcctlAxis3Placement> OcctlAxis3Placement::from_c(const occtl_axis3_placement_t& val) {
    Ref<OcctlAxis3Placement> r;
    r.instantiate();
    r->location = OcctlPoint3::from_c(val.location);
    r->x_dir = OcctlDirection3::from_c(val.x_dir);
    r->y_dir = OcctlDirection3::from_c(val.y_dir);
    r->z_dir = OcctlDirection3::from_c(val.z_dir);
    return r;
}

void OcctlAxis3Placement::copy_from_c(const occtl_axis3_placement_t& val) {
    location = OcctlPoint3::from_c(val.location);
    x_dir = OcctlDirection3::from_c(val.x_dir);
    y_dir = OcctlDirection3::from_c(val.y_dir);
    z_dir = OcctlDirection3::from_c(val.z_dir);
}

Ref<OcctlAxis3Placement> OcctlAxis3Placement::from_components(Vector3 point, Vector3 z_dir, Vector3 x_dir) {
    Ref<OcctlAxis3Placement> instance;
    instance.instantiate();
    { auto _loc = occtl_point3_t{}; _loc.x = point.x; _loc.y = point.y; _loc.z = point.z; instance->location = OcctlPoint3::from_c(_loc); }
    { auto _x = occtl_direction3_t{}; _x.x = x_dir.x; _x.y = x_dir.y; _x.z = x_dir.z; instance->x_dir = OcctlDirection3::from_c(_x); }
    { auto _y = occtl_direction3_t{}; _y.x = point.x; _y.y = point.y; _y.z = point.z; instance->y_dir = OcctlDirection3::from_c(_y); }
    { auto _z = occtl_direction3_t{}; _z.x = z_dir.x; _z.y = z_dir.y; _z.z = z_dir.z; instance->z_dir = OcctlDirection3::from_c(_z); }
    return instance;
}
