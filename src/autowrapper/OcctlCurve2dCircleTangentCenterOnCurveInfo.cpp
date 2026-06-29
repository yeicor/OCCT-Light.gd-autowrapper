#include "OcctlCurve2dCircleTangentCenterOnCurveInfo.h"

#include "OcctlRepId.h"

int OcctlCurve2dCircleTangentCenterOnCurveInfo::get_struct_version() const { return struct_version; }
void OcctlCurve2dCircleTangentCenterOnCurveInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlCurve2dCircleTangentCenterOnCurveInfo::get_p_next() const { return p_next; }
void OcctlCurve2dCircleTangentCenterOnCurveInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlCurve2dCircleTangentCenterOnCurveInfo::get_curve_a() const { return curve_a; }
void OcctlCurve2dCircleTangentCenterOnCurveInfo::set_curve_a(int64_t val) { curve_a = val; }

int OcctlCurve2dCircleTangentCenterOnCurveInfo::get_qualifier_a() const { return qualifier_a; }
void OcctlCurve2dCircleTangentCenterOnCurveInfo::set_qualifier_a(int val) { qualifier_a = val; }

int64_t OcctlCurve2dCircleTangentCenterOnCurveInfo::get_curve_b() const { return curve_b; }
void OcctlCurve2dCircleTangentCenterOnCurveInfo::set_curve_b(int64_t val) { curve_b = val; }

int OcctlCurve2dCircleTangentCenterOnCurveInfo::get_qualifier_b() const { return qualifier_b; }
void OcctlCurve2dCircleTangentCenterOnCurveInfo::set_qualifier_b(int val) { qualifier_b = val; }

int64_t OcctlCurve2dCircleTangentCenterOnCurveInfo::get_center_curve() const { return center_curve; }
void OcctlCurve2dCircleTangentCenterOnCurveInfo::set_center_curve(int64_t val) { center_curve = val; }

double OcctlCurve2dCircleTangentCenterOnCurveInfo::get_initial_parameter_a() const { return initial_parameter_a; }
void OcctlCurve2dCircleTangentCenterOnCurveInfo::set_initial_parameter_a(double val) { initial_parameter_a = val; }

double OcctlCurve2dCircleTangentCenterOnCurveInfo::get_initial_parameter_b() const { return initial_parameter_b; }
void OcctlCurve2dCircleTangentCenterOnCurveInfo::set_initial_parameter_b(double val) { initial_parameter_b = val; }

double OcctlCurve2dCircleTangentCenterOnCurveInfo::get_initial_parameter_center() const { return initial_parameter_center; }
void OcctlCurve2dCircleTangentCenterOnCurveInfo::set_initial_parameter_center(double val) { initial_parameter_center = val; }

double OcctlCurve2dCircleTangentCenterOnCurveInfo::get_tolerance() const { return tolerance; }
void OcctlCurve2dCircleTangentCenterOnCurveInfo::set_tolerance(double val) { tolerance = val; }

void OcctlCurve2dCircleTangentCenterOnCurveInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlCurve2dCircleTangentCenterOnCurveInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlCurve2dCircleTangentCenterOnCurveInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlCurve2dCircleTangentCenterOnCurveInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlCurve2dCircleTangentCenterOnCurveInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_curve_a"), &OcctlCurve2dCircleTangentCenterOnCurveInfo::get_curve_a);
    godot::ClassDB::bind_method(godot::D_METHOD("set_curve_a", "val"), &OcctlCurve2dCircleTangentCenterOnCurveInfo::set_curve_a);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "curve_a"), "set_curve_a", "get_curve_a");
    godot::ClassDB::bind_method(godot::D_METHOD("get_qualifier_a"), &OcctlCurve2dCircleTangentCenterOnCurveInfo::get_qualifier_a);
    godot::ClassDB::bind_method(godot::D_METHOD("set_qualifier_a", "val"), &OcctlCurve2dCircleTangentCenterOnCurveInfo::set_qualifier_a);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "qualifier_a"), "set_qualifier_a", "get_qualifier_a");
    godot::ClassDB::bind_method(godot::D_METHOD("get_curve_b"), &OcctlCurve2dCircleTangentCenterOnCurveInfo::get_curve_b);
    godot::ClassDB::bind_method(godot::D_METHOD("set_curve_b", "val"), &OcctlCurve2dCircleTangentCenterOnCurveInfo::set_curve_b);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "curve_b"), "set_curve_b", "get_curve_b");
    godot::ClassDB::bind_method(godot::D_METHOD("get_qualifier_b"), &OcctlCurve2dCircleTangentCenterOnCurveInfo::get_qualifier_b);
    godot::ClassDB::bind_method(godot::D_METHOD("set_qualifier_b", "val"), &OcctlCurve2dCircleTangentCenterOnCurveInfo::set_qualifier_b);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "qualifier_b"), "set_qualifier_b", "get_qualifier_b");
    godot::ClassDB::bind_method(godot::D_METHOD("get_center_curve"), &OcctlCurve2dCircleTangentCenterOnCurveInfo::get_center_curve);
    godot::ClassDB::bind_method(godot::D_METHOD("set_center_curve", "val"), &OcctlCurve2dCircleTangentCenterOnCurveInfo::set_center_curve);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "center_curve"), "set_center_curve", "get_center_curve");
    godot::ClassDB::bind_method(godot::D_METHOD("get_initial_parameter_a"), &OcctlCurve2dCircleTangentCenterOnCurveInfo::get_initial_parameter_a);
    godot::ClassDB::bind_method(godot::D_METHOD("set_initial_parameter_a", "val"), &OcctlCurve2dCircleTangentCenterOnCurveInfo::set_initial_parameter_a);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "initial_parameter_a"), "set_initial_parameter_a", "get_initial_parameter_a");
    godot::ClassDB::bind_method(godot::D_METHOD("get_initial_parameter_b"), &OcctlCurve2dCircleTangentCenterOnCurveInfo::get_initial_parameter_b);
    godot::ClassDB::bind_method(godot::D_METHOD("set_initial_parameter_b", "val"), &OcctlCurve2dCircleTangentCenterOnCurveInfo::set_initial_parameter_b);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "initial_parameter_b"), "set_initial_parameter_b", "get_initial_parameter_b");
    godot::ClassDB::bind_method(godot::D_METHOD("get_initial_parameter_center"), &OcctlCurve2dCircleTangentCenterOnCurveInfo::get_initial_parameter_center);
    godot::ClassDB::bind_method(godot::D_METHOD("set_initial_parameter_center", "val"), &OcctlCurve2dCircleTangentCenterOnCurveInfo::set_initial_parameter_center);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "initial_parameter_center"), "set_initial_parameter_center", "get_initial_parameter_center");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlCurve2dCircleTangentCenterOnCurveInfo::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlCurve2dCircleTangentCenterOnCurveInfo::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
}

occtl_curve2d_circle_tangent_center_on_curve_info_t OcctlCurve2dCircleTangentCenterOnCurveInfo::to_c() const {
    occtl_curve2d_circle_tangent_center_on_curve_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.curve_a.bits = static_cast<uint64_t>(curve_a);
    result.qualifier_a = static_cast<occtl_curve2d_tangency_qualifier_t>(qualifier_a);
    result.curve_b.bits = static_cast<uint64_t>(curve_b);
    result.qualifier_b = static_cast<occtl_curve2d_tangency_qualifier_t>(qualifier_b);
    result.center_curve.bits = static_cast<uint64_t>(center_curve);
    result.initial_parameter_a = initial_parameter_a;
    result.initial_parameter_b = initial_parameter_b;
    result.initial_parameter_center = initial_parameter_center;
    result.tolerance = tolerance;
    return result;
}

Ref<OcctlCurve2dCircleTangentCenterOnCurveInfo> OcctlCurve2dCircleTangentCenterOnCurveInfo::from_c(const occtl_curve2d_circle_tangent_center_on_curve_info_t& val) {
    Ref<OcctlCurve2dCircleTangentCenterOnCurveInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->curve_a = static_cast<int64_t>(val.curve_a.bits);
    r->qualifier_a = static_cast<int>(val.qualifier_a);
    r->curve_b = static_cast<int64_t>(val.curve_b.bits);
    r->qualifier_b = static_cast<int>(val.qualifier_b);
    r->center_curve = static_cast<int64_t>(val.center_curve.bits);
    r->initial_parameter_a = val.initial_parameter_a;
    r->initial_parameter_b = val.initial_parameter_b;
    r->initial_parameter_center = val.initial_parameter_center;
    r->tolerance = val.tolerance;
    return r;
}

void OcctlCurve2dCircleTangentCenterOnCurveInfo::copy_from_c(const occtl_curve2d_circle_tangent_center_on_curve_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    curve_a = static_cast<int64_t>(val.curve_a.bits);
    qualifier_a = static_cast<int>(val.qualifier_a);
    curve_b = static_cast<int64_t>(val.curve_b.bits);
    qualifier_b = static_cast<int>(val.qualifier_b);
    center_curve = static_cast<int64_t>(val.center_curve.bits);
    initial_parameter_a = val.initial_parameter_a;
    initial_parameter_b = val.initial_parameter_b;
    initial_parameter_center = val.initial_parameter_center;
    tolerance = val.tolerance;
}
