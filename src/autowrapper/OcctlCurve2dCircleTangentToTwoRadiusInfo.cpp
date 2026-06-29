#include "OcctlCurve2dCircleTangentToTwoRadiusInfo.h"

#include "OcctlRepId.h"

int OcctlCurve2dCircleTangentToTwoRadiusInfo::get_struct_version() const { return struct_version; }
void OcctlCurve2dCircleTangentToTwoRadiusInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlCurve2dCircleTangentToTwoRadiusInfo::get_p_next() const { return p_next; }
void OcctlCurve2dCircleTangentToTwoRadiusInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlCurve2dCircleTangentToTwoRadiusInfo::get_curve_a() const { return curve_a; }
void OcctlCurve2dCircleTangentToTwoRadiusInfo::set_curve_a(int64_t val) { curve_a = val; }

int OcctlCurve2dCircleTangentToTwoRadiusInfo::get_qualifier_a() const { return qualifier_a; }
void OcctlCurve2dCircleTangentToTwoRadiusInfo::set_qualifier_a(int val) { qualifier_a = val; }

int64_t OcctlCurve2dCircleTangentToTwoRadiusInfo::get_curve_b() const { return curve_b; }
void OcctlCurve2dCircleTangentToTwoRadiusInfo::set_curve_b(int64_t val) { curve_b = val; }

int OcctlCurve2dCircleTangentToTwoRadiusInfo::get_qualifier_b() const { return qualifier_b; }
void OcctlCurve2dCircleTangentToTwoRadiusInfo::set_qualifier_b(int val) { qualifier_b = val; }

double OcctlCurve2dCircleTangentToTwoRadiusInfo::get_radius() const { return radius; }
void OcctlCurve2dCircleTangentToTwoRadiusInfo::set_radius(double val) { radius = val; }

double OcctlCurve2dCircleTangentToTwoRadiusInfo::get_tolerance() const { return tolerance; }
void OcctlCurve2dCircleTangentToTwoRadiusInfo::set_tolerance(double val) { tolerance = val; }

void OcctlCurve2dCircleTangentToTwoRadiusInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlCurve2dCircleTangentToTwoRadiusInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlCurve2dCircleTangentToTwoRadiusInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlCurve2dCircleTangentToTwoRadiusInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlCurve2dCircleTangentToTwoRadiusInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_curve_a"), &OcctlCurve2dCircleTangentToTwoRadiusInfo::get_curve_a);
    godot::ClassDB::bind_method(godot::D_METHOD("set_curve_a", "val"), &OcctlCurve2dCircleTangentToTwoRadiusInfo::set_curve_a);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "curve_a"), "set_curve_a", "get_curve_a");
    godot::ClassDB::bind_method(godot::D_METHOD("get_qualifier_a"), &OcctlCurve2dCircleTangentToTwoRadiusInfo::get_qualifier_a);
    godot::ClassDB::bind_method(godot::D_METHOD("set_qualifier_a", "val"), &OcctlCurve2dCircleTangentToTwoRadiusInfo::set_qualifier_a);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "qualifier_a"), "set_qualifier_a", "get_qualifier_a");
    godot::ClassDB::bind_method(godot::D_METHOD("get_curve_b"), &OcctlCurve2dCircleTangentToTwoRadiusInfo::get_curve_b);
    godot::ClassDB::bind_method(godot::D_METHOD("set_curve_b", "val"), &OcctlCurve2dCircleTangentToTwoRadiusInfo::set_curve_b);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "curve_b"), "set_curve_b", "get_curve_b");
    godot::ClassDB::bind_method(godot::D_METHOD("get_qualifier_b"), &OcctlCurve2dCircleTangentToTwoRadiusInfo::get_qualifier_b);
    godot::ClassDB::bind_method(godot::D_METHOD("set_qualifier_b", "val"), &OcctlCurve2dCircleTangentToTwoRadiusInfo::set_qualifier_b);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "qualifier_b"), "set_qualifier_b", "get_qualifier_b");
    godot::ClassDB::bind_method(godot::D_METHOD("get_radius"), &OcctlCurve2dCircleTangentToTwoRadiusInfo::get_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_radius", "val"), &OcctlCurve2dCircleTangentToTwoRadiusInfo::set_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "radius"), "set_radius", "get_radius");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlCurve2dCircleTangentToTwoRadiusInfo::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlCurve2dCircleTangentToTwoRadiusInfo::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
}

occtl_curve2d_circle_tangent_to_two_radius_info_t OcctlCurve2dCircleTangentToTwoRadiusInfo::to_c() const {
    occtl_curve2d_circle_tangent_to_two_radius_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.curve_a.bits = static_cast<uint64_t>(curve_a);
    result.qualifier_a = static_cast<occtl_curve2d_tangency_qualifier_t>(qualifier_a);
    result.curve_b.bits = static_cast<uint64_t>(curve_b);
    result.qualifier_b = static_cast<occtl_curve2d_tangency_qualifier_t>(qualifier_b);
    result.radius = radius;
    result.tolerance = tolerance;
    return result;
}

Ref<OcctlCurve2dCircleTangentToTwoRadiusInfo> OcctlCurve2dCircleTangentToTwoRadiusInfo::from_c(const occtl_curve2d_circle_tangent_to_two_radius_info_t& val) {
    Ref<OcctlCurve2dCircleTangentToTwoRadiusInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->curve_a = static_cast<int64_t>(val.curve_a.bits);
    r->qualifier_a = static_cast<int>(val.qualifier_a);
    r->curve_b = static_cast<int64_t>(val.curve_b.bits);
    r->qualifier_b = static_cast<int>(val.qualifier_b);
    r->radius = val.radius;
    r->tolerance = val.tolerance;
    return r;
}

void OcctlCurve2dCircleTangentToTwoRadiusInfo::copy_from_c(const occtl_curve2d_circle_tangent_to_two_radius_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    curve_a = static_cast<int64_t>(val.curve_a.bits);
    qualifier_a = static_cast<int>(val.qualifier_a);
    curve_b = static_cast<int64_t>(val.curve_b.bits);
    qualifier_b = static_cast<int>(val.qualifier_b);
    radius = val.radius;
    tolerance = val.tolerance;
}
