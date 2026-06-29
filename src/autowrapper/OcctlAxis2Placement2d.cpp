#include "OcctlAxis2Placement2d.h"

#include "OcctlPoint2.h"
#include "OcctlDirection2.h"

Ref<OcctlPoint2> OcctlAxis2Placement2d::get_location() const { return location; }
void OcctlAxis2Placement2d::set_location(Ref<OcctlPoint2> val) { location = val; }

Ref<OcctlDirection2> OcctlAxis2Placement2d::get_x_dir() const { return x_dir; }
void OcctlAxis2Placement2d::set_x_dir(Ref<OcctlDirection2> val) { x_dir = val; }

void OcctlAxis2Placement2d::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_location"), &OcctlAxis2Placement2d::get_location);
    godot::ClassDB::bind_method(godot::D_METHOD("set_location", "val"), &OcctlAxis2Placement2d::set_location);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "location"), "set_location", "get_location");
    godot::ClassDB::bind_method(godot::D_METHOD("get_x_dir"), &OcctlAxis2Placement2d::get_x_dir);
    godot::ClassDB::bind_method(godot::D_METHOD("set_x_dir", "val"), &OcctlAxis2Placement2d::set_x_dir);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "x_dir"), "set_x_dir", "get_x_dir");
    godot::ClassDB::bind_static_method("OcctlAxis2Placement2d", godot::D_METHOD("from_components", "point", "z_dir", "x_dir"), &OcctlAxis2Placement2d::from_components);
}

occtl_axis2_placement2d_t OcctlAxis2Placement2d::to_c() const {
    occtl_axis2_placement2d_t result = {};
    result.location = location->to_c();
    result.x_dir = x_dir->to_c();
    return result;
}

Ref<OcctlAxis2Placement2d> OcctlAxis2Placement2d::from_c(const occtl_axis2_placement2d_t& val) {
    Ref<OcctlAxis2Placement2d> r;
    r.instantiate();
    r->location = OcctlPoint2::from_c(val.location);
    r->x_dir = OcctlDirection2::from_c(val.x_dir);
    return r;
}

void OcctlAxis2Placement2d::copy_from_c(const occtl_axis2_placement2d_t& val) {
    location = OcctlPoint2::from_c(val.location);
    x_dir = OcctlDirection2::from_c(val.x_dir);
}

Ref<OcctlAxis2Placement2d> OcctlAxis2Placement2d::from_components(Vector2 point, Vector2 z_dir, Vector2 x_dir) {
    Ref<OcctlAxis2Placement2d> instance;
    instance.instantiate();
    (void)z_dir;
    { auto _loc = occtl_point2_t{}; _loc.x = point.x; _loc.y = point.y; instance->location = OcctlPoint2::from_c(_loc); }
    { auto _x = occtl_direction2_t{}; _x.x = x_dir.x; _x.y = x_dir.y; instance->x_dir = OcctlDirection2::from_c(_x); }
    return instance;
}
