#include "OcctlCurveIntersectionPoint.h"

#include "OcctlPoint3.h"

Ref<OcctlPoint3> OcctlCurveIntersectionPoint::get_point() const { return point; }
void OcctlCurveIntersectionPoint::set_point(Ref<OcctlPoint3> val) { point = val; }

double OcctlCurveIntersectionPoint::get_param_a() const { return param_a; }
void OcctlCurveIntersectionPoint::set_param_a(double val) { param_a = val; }

double OcctlCurveIntersectionPoint::get_param_b() const { return param_b; }
void OcctlCurveIntersectionPoint::set_param_b(double val) { param_b = val; }

void OcctlCurveIntersectionPoint::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_point"), &OcctlCurveIntersectionPoint::get_point);
    godot::ClassDB::bind_method(godot::D_METHOD("set_point", "val"), &OcctlCurveIntersectionPoint::set_point);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "point"), "set_point", "get_point");
    godot::ClassDB::bind_method(godot::D_METHOD("get_param_a"), &OcctlCurveIntersectionPoint::get_param_a);
    godot::ClassDB::bind_method(godot::D_METHOD("set_param_a", "val"), &OcctlCurveIntersectionPoint::set_param_a);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "param_a"), "set_param_a", "get_param_a");
    godot::ClassDB::bind_method(godot::D_METHOD("get_param_b"), &OcctlCurveIntersectionPoint::get_param_b);
    godot::ClassDB::bind_method(godot::D_METHOD("set_param_b", "val"), &OcctlCurveIntersectionPoint::set_param_b);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "param_b"), "set_param_b", "get_param_b");
}

occtl_curve_intersection_point_t OcctlCurveIntersectionPoint::to_c() const {
    occtl_curve_intersection_point_t result = {};
    result.point = point->to_c();
    result.param_a = param_a;
    result.param_b = param_b;
    return result;
}

Ref<OcctlCurveIntersectionPoint> OcctlCurveIntersectionPoint::from_c(const occtl_curve_intersection_point_t& val) {
    Ref<OcctlCurveIntersectionPoint> r;
    r.instantiate();
    r->point = OcctlPoint3::from_c(val.point);
    r->param_a = val.param_a;
    r->param_b = val.param_b;
    return r;
}

void OcctlCurveIntersectionPoint::copy_from_c(const occtl_curve_intersection_point_t& val) {
    point = OcctlPoint3::from_c(val.point);
    param_a = val.param_a;
    param_b = val.param_b;
}
