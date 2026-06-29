#include "OcctlCurve2dCircleTangentFixedCenterInfo.h"

#include "OcctlRepId.h"
#include "OcctlPoint2.h"

int OcctlCurve2dCircleTangentFixedCenterInfo::get_struct_version() const { return struct_version; }
void OcctlCurve2dCircleTangentFixedCenterInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlCurve2dCircleTangentFixedCenterInfo::get_p_next() const { return p_next; }
void OcctlCurve2dCircleTangentFixedCenterInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlCurve2dCircleTangentFixedCenterInfo::get_curve() const { return curve; }
void OcctlCurve2dCircleTangentFixedCenterInfo::set_curve(int64_t val) { curve = val; }

int OcctlCurve2dCircleTangentFixedCenterInfo::get_qualifier() const { return qualifier; }
void OcctlCurve2dCircleTangentFixedCenterInfo::set_qualifier(int val) { qualifier = val; }

Ref<OcctlPoint2> OcctlCurve2dCircleTangentFixedCenterInfo::get_center() const { return center; }
void OcctlCurve2dCircleTangentFixedCenterInfo::set_center(Ref<OcctlPoint2> val) { center = val; }

double OcctlCurve2dCircleTangentFixedCenterInfo::get_tolerance() const { return tolerance; }
void OcctlCurve2dCircleTangentFixedCenterInfo::set_tolerance(double val) { tolerance = val; }

void OcctlCurve2dCircleTangentFixedCenterInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlCurve2dCircleTangentFixedCenterInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlCurve2dCircleTangentFixedCenterInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlCurve2dCircleTangentFixedCenterInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlCurve2dCircleTangentFixedCenterInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_curve"), &OcctlCurve2dCircleTangentFixedCenterInfo::get_curve);
    godot::ClassDB::bind_method(godot::D_METHOD("set_curve", "val"), &OcctlCurve2dCircleTangentFixedCenterInfo::set_curve);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "curve"), "set_curve", "get_curve");
    godot::ClassDB::bind_method(godot::D_METHOD("get_qualifier"), &OcctlCurve2dCircleTangentFixedCenterInfo::get_qualifier);
    godot::ClassDB::bind_method(godot::D_METHOD("set_qualifier", "val"), &OcctlCurve2dCircleTangentFixedCenterInfo::set_qualifier);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "qualifier"), "set_qualifier", "get_qualifier");
    godot::ClassDB::bind_method(godot::D_METHOD("get_center"), &OcctlCurve2dCircleTangentFixedCenterInfo::get_center);
    godot::ClassDB::bind_method(godot::D_METHOD("set_center", "val"), &OcctlCurve2dCircleTangentFixedCenterInfo::set_center);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "center"), "set_center", "get_center");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlCurve2dCircleTangentFixedCenterInfo::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlCurve2dCircleTangentFixedCenterInfo::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
}

occtl_curve2d_circle_tangent_fixed_center_info_t OcctlCurve2dCircleTangentFixedCenterInfo::to_c() const {
    occtl_curve2d_circle_tangent_fixed_center_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.curve.bits = static_cast<uint64_t>(curve);
    result.qualifier = static_cast<occtl_curve2d_tangency_qualifier_t>(qualifier);
    result.center = center->to_c();
    result.tolerance = tolerance;
    return result;
}

Ref<OcctlCurve2dCircleTangentFixedCenterInfo> OcctlCurve2dCircleTangentFixedCenterInfo::from_c(const occtl_curve2d_circle_tangent_fixed_center_info_t& val) {
    Ref<OcctlCurve2dCircleTangentFixedCenterInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->curve = static_cast<int64_t>(val.curve.bits);
    r->qualifier = static_cast<int>(val.qualifier);
    r->center = OcctlPoint2::from_c(val.center);
    r->tolerance = val.tolerance;
    return r;
}

void OcctlCurve2dCircleTangentFixedCenterInfo::copy_from_c(const occtl_curve2d_circle_tangent_fixed_center_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    curve = static_cast<int64_t>(val.curve.bits);
    qualifier = static_cast<int>(val.qualifier);
    center = OcctlPoint2::from_c(val.center);
    tolerance = val.tolerance;
}
