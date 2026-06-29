#include "OcctlCurve2dLineTangentThroughPointInfo.h"

#include "OcctlRepId.h"
#include "OcctlPoint2.h"

int OcctlCurve2dLineTangentThroughPointInfo::get_struct_version() const { return struct_version; }
void OcctlCurve2dLineTangentThroughPointInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlCurve2dLineTangentThroughPointInfo::get_p_next() const { return p_next; }
void OcctlCurve2dLineTangentThroughPointInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlCurve2dLineTangentThroughPointInfo::get_curve() const { return curve; }
void OcctlCurve2dLineTangentThroughPointInfo::set_curve(int64_t val) { curve = val; }

int OcctlCurve2dLineTangentThroughPointInfo::get_qualifier() const { return qualifier; }
void OcctlCurve2dLineTangentThroughPointInfo::set_qualifier(int val) { qualifier = val; }

Ref<OcctlPoint2> OcctlCurve2dLineTangentThroughPointInfo::get_point() const { return point; }
void OcctlCurve2dLineTangentThroughPointInfo::set_point(Ref<OcctlPoint2> val) { point = val; }

double OcctlCurve2dLineTangentThroughPointInfo::get_tolerance() const { return tolerance; }
void OcctlCurve2dLineTangentThroughPointInfo::set_tolerance(double val) { tolerance = val; }

void OcctlCurve2dLineTangentThroughPointInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlCurve2dLineTangentThroughPointInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlCurve2dLineTangentThroughPointInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlCurve2dLineTangentThroughPointInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlCurve2dLineTangentThroughPointInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_curve"), &OcctlCurve2dLineTangentThroughPointInfo::get_curve);
    godot::ClassDB::bind_method(godot::D_METHOD("set_curve", "val"), &OcctlCurve2dLineTangentThroughPointInfo::set_curve);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "curve"), "set_curve", "get_curve");
    godot::ClassDB::bind_method(godot::D_METHOD("get_qualifier"), &OcctlCurve2dLineTangentThroughPointInfo::get_qualifier);
    godot::ClassDB::bind_method(godot::D_METHOD("set_qualifier", "val"), &OcctlCurve2dLineTangentThroughPointInfo::set_qualifier);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "qualifier"), "set_qualifier", "get_qualifier");
    godot::ClassDB::bind_method(godot::D_METHOD("get_point"), &OcctlCurve2dLineTangentThroughPointInfo::get_point);
    godot::ClassDB::bind_method(godot::D_METHOD("set_point", "val"), &OcctlCurve2dLineTangentThroughPointInfo::set_point);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "point"), "set_point", "get_point");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlCurve2dLineTangentThroughPointInfo::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlCurve2dLineTangentThroughPointInfo::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
}

occtl_curve2d_line_tangent_through_point_info_t OcctlCurve2dLineTangentThroughPointInfo::to_c() const {
    occtl_curve2d_line_tangent_through_point_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.curve.bits = static_cast<uint64_t>(curve);
    result.qualifier = static_cast<occtl_curve2d_tangency_qualifier_t>(qualifier);
    result.point = point->to_c();
    result.tolerance = tolerance;
    return result;
}

Ref<OcctlCurve2dLineTangentThroughPointInfo> OcctlCurve2dLineTangentThroughPointInfo::from_c(const occtl_curve2d_line_tangent_through_point_info_t& val) {
    Ref<OcctlCurve2dLineTangentThroughPointInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->curve = static_cast<int64_t>(val.curve.bits);
    r->qualifier = static_cast<int>(val.qualifier);
    r->point = OcctlPoint2::from_c(val.point);
    r->tolerance = val.tolerance;
    return r;
}

void OcctlCurve2dLineTangentThroughPointInfo::copy_from_c(const occtl_curve2d_line_tangent_through_point_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    curve = static_cast<int64_t>(val.curve.bits);
    qualifier = static_cast<int>(val.qualifier);
    point = OcctlPoint2::from_c(val.point);
    tolerance = val.tolerance;
}
