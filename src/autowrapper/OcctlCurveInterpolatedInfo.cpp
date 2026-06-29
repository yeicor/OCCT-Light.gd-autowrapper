#include "OcctlCurveInterpolatedInfo.h"


int OcctlCurveInterpolatedInfo::get_struct_version() const { return struct_version; }
void OcctlCurveInterpolatedInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlCurveInterpolatedInfo::get_p_next() const { return p_next; }
void OcctlCurveInterpolatedInfo::set_p_next(int64_t val) { p_next = val; }

Array OcctlCurveInterpolatedInfo::get_points() const { return points; }
void OcctlCurveInterpolatedInfo::set_points(Array val) { points = val; }

int OcctlCurveInterpolatedInfo::get_point_count() const { return point_count; }
void OcctlCurveInterpolatedInfo::set_point_count(int val) { point_count = val; }

int OcctlCurveInterpolatedInfo::get_is_periodic() const { return is_periodic; }
void OcctlCurveInterpolatedInfo::set_is_periodic(int val) { is_periodic = val; }

double OcctlCurveInterpolatedInfo::get_tolerance() const { return tolerance; }
void OcctlCurveInterpolatedInfo::set_tolerance(double val) { tolerance = val; }

void OcctlCurveInterpolatedInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlCurveInterpolatedInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlCurveInterpolatedInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlCurveInterpolatedInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlCurveInterpolatedInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_points"), &OcctlCurveInterpolatedInfo::get_points);
    godot::ClassDB::bind_method(godot::D_METHOD("set_points", "val"), &OcctlCurveInterpolatedInfo::set_points);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "points"), "set_points", "get_points");
    godot::ClassDB::bind_method(godot::D_METHOD("get_point_count"), &OcctlCurveInterpolatedInfo::get_point_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_point_count", "val"), &OcctlCurveInterpolatedInfo::set_point_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "point_count"), "set_point_count", "get_point_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_periodic"), &OcctlCurveInterpolatedInfo::get_is_periodic);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_periodic", "val"), &OcctlCurveInterpolatedInfo::set_is_periodic);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_periodic"), "set_is_periodic", "get_is_periodic");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlCurveInterpolatedInfo::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlCurveInterpolatedInfo::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
}

occtl_curve_interpolated_info_t OcctlCurveInterpolatedInfo::to_c() const {
    occtl_curve_interpolated_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    _cache_points.resize(points.size());
    for (int _i = 0; _i < points.size(); _i++) {
        Ref<OcctlPoint3> _item = points[_i];
        if (_item.is_valid()) _cache_points[_i] = _item->to_c();
        else _cache_points[_i] = {};
    }
    result.points = _cache_points.data();
    result.point_count = point_count;
    result.is_periodic = is_periodic;
    result.tolerance = tolerance;
    return result;
}

Ref<OcctlCurveInterpolatedInfo> OcctlCurveInterpolatedInfo::from_c(const occtl_curve_interpolated_info_t& val) {
    Ref<OcctlCurveInterpolatedInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field points is not populated from C
    r->point_count = val.point_count;
    r->is_periodic = val.is_periodic;
    r->tolerance = val.tolerance;
    return r;
}

void OcctlCurveInterpolatedInfo::copy_from_c(const occtl_curve_interpolated_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field points is not populated from C
    point_count = val.point_count;
    is_periodic = val.is_periodic;
    tolerance = val.tolerance;
}
