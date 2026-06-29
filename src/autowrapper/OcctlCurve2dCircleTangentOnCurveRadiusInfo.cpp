#include "OcctlCurve2dCircleTangentOnCurveRadiusInfo.h"

#include "OcctlRepId.h"

int OcctlCurve2dCircleTangentOnCurveRadiusInfo::get_struct_version() const { return struct_version; }
void OcctlCurve2dCircleTangentOnCurveRadiusInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlCurve2dCircleTangentOnCurveRadiusInfo::get_p_next() const { return p_next; }
void OcctlCurve2dCircleTangentOnCurveRadiusInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlCurve2dCircleTangentOnCurveRadiusInfo::get_curve() const { return curve; }
void OcctlCurve2dCircleTangentOnCurveRadiusInfo::set_curve(int64_t val) { curve = val; }

int OcctlCurve2dCircleTangentOnCurveRadiusInfo::get_qualifier() const { return qualifier; }
void OcctlCurve2dCircleTangentOnCurveRadiusInfo::set_qualifier(int val) { qualifier = val; }

int64_t OcctlCurve2dCircleTangentOnCurveRadiusInfo::get_center_curve() const { return center_curve; }
void OcctlCurve2dCircleTangentOnCurveRadiusInfo::set_center_curve(int64_t val) { center_curve = val; }

double OcctlCurve2dCircleTangentOnCurveRadiusInfo::get_radius() const { return radius; }
void OcctlCurve2dCircleTangentOnCurveRadiusInfo::set_radius(double val) { radius = val; }

double OcctlCurve2dCircleTangentOnCurveRadiusInfo::get_tolerance() const { return tolerance; }
void OcctlCurve2dCircleTangentOnCurveRadiusInfo::set_tolerance(double val) { tolerance = val; }

void OcctlCurve2dCircleTangentOnCurveRadiusInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlCurve2dCircleTangentOnCurveRadiusInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlCurve2dCircleTangentOnCurveRadiusInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlCurve2dCircleTangentOnCurveRadiusInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlCurve2dCircleTangentOnCurveRadiusInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_curve"), &OcctlCurve2dCircleTangentOnCurveRadiusInfo::get_curve);
    godot::ClassDB::bind_method(godot::D_METHOD("set_curve", "val"), &OcctlCurve2dCircleTangentOnCurveRadiusInfo::set_curve);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "curve"), "set_curve", "get_curve");
    godot::ClassDB::bind_method(godot::D_METHOD("get_qualifier"), &OcctlCurve2dCircleTangentOnCurveRadiusInfo::get_qualifier);
    godot::ClassDB::bind_method(godot::D_METHOD("set_qualifier", "val"), &OcctlCurve2dCircleTangentOnCurveRadiusInfo::set_qualifier);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "qualifier"), "set_qualifier", "get_qualifier");
    godot::ClassDB::bind_method(godot::D_METHOD("get_center_curve"), &OcctlCurve2dCircleTangentOnCurveRadiusInfo::get_center_curve);
    godot::ClassDB::bind_method(godot::D_METHOD("set_center_curve", "val"), &OcctlCurve2dCircleTangentOnCurveRadiusInfo::set_center_curve);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "center_curve"), "set_center_curve", "get_center_curve");
    godot::ClassDB::bind_method(godot::D_METHOD("get_radius"), &OcctlCurve2dCircleTangentOnCurveRadiusInfo::get_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_radius", "val"), &OcctlCurve2dCircleTangentOnCurveRadiusInfo::set_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "radius"), "set_radius", "get_radius");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlCurve2dCircleTangentOnCurveRadiusInfo::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlCurve2dCircleTangentOnCurveRadiusInfo::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
}

occtl_curve2d_circle_tangent_on_curve_radius_info_t OcctlCurve2dCircleTangentOnCurveRadiusInfo::to_c() const {
    occtl_curve2d_circle_tangent_on_curve_radius_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.curve.bits = static_cast<uint64_t>(curve);
    result.qualifier = static_cast<occtl_curve2d_tangency_qualifier_t>(qualifier);
    result.center_curve.bits = static_cast<uint64_t>(center_curve);
    result.radius = radius;
    result.tolerance = tolerance;
    return result;
}

Ref<OcctlCurve2dCircleTangentOnCurveRadiusInfo> OcctlCurve2dCircleTangentOnCurveRadiusInfo::from_c(const occtl_curve2d_circle_tangent_on_curve_radius_info_t& val) {
    Ref<OcctlCurve2dCircleTangentOnCurveRadiusInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->curve = static_cast<int64_t>(val.curve.bits);
    r->qualifier = static_cast<int>(val.qualifier);
    r->center_curve = static_cast<int64_t>(val.center_curve.bits);
    r->radius = val.radius;
    r->tolerance = val.tolerance;
    return r;
}

void OcctlCurve2dCircleTangentOnCurveRadiusInfo::copy_from_c(const occtl_curve2d_circle_tangent_on_curve_radius_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    curve = static_cast<int64_t>(val.curve.bits);
    qualifier = static_cast<int>(val.qualifier);
    center_curve = static_cast<int64_t>(val.center_curve.bits);
    radius = val.radius;
    tolerance = val.tolerance;
}
