#include "OcctlPrimSplineInfo.h"


int OcctlPrimSplineInfo::get_struct_version() const { return struct_version; }
void OcctlPrimSplineInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimSplineInfo::get_p_next() const { return p_next; }
void OcctlPrimSplineInfo::set_p_next(int64_t val) { p_next = val; }

Array OcctlPrimSplineInfo::get_points() const { return points; }
void OcctlPrimSplineInfo::set_points(Array val) { points = val; }

int OcctlPrimSplineInfo::get_point_count() const { return point_count; }
void OcctlPrimSplineInfo::set_point_count(int val) { point_count = val; }

int OcctlPrimSplineInfo::get_degree_min() const { return degree_min; }
void OcctlPrimSplineInfo::set_degree_min(int val) { degree_min = val; }

int OcctlPrimSplineInfo::get_degree_max() const { return degree_max; }
void OcctlPrimSplineInfo::set_degree_max(int val) { degree_max = val; }

double OcctlPrimSplineInfo::get_tolerance() const { return tolerance; }
void OcctlPrimSplineInfo::set_tolerance(double val) { tolerance = val; }

void OcctlPrimSplineInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimSplineInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimSplineInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimSplineInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimSplineInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_points"), &OcctlPrimSplineInfo::get_points);
    godot::ClassDB::bind_method(godot::D_METHOD("set_points", "val"), &OcctlPrimSplineInfo::set_points);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "points"), "set_points", "get_points");
    godot::ClassDB::bind_method(godot::D_METHOD("get_point_count"), &OcctlPrimSplineInfo::get_point_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_point_count", "val"), &OcctlPrimSplineInfo::set_point_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "point_count"), "set_point_count", "get_point_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_degree_min"), &OcctlPrimSplineInfo::get_degree_min);
    godot::ClassDB::bind_method(godot::D_METHOD("set_degree_min", "val"), &OcctlPrimSplineInfo::set_degree_min);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "degree_min"), "set_degree_min", "get_degree_min");
    godot::ClassDB::bind_method(godot::D_METHOD("get_degree_max"), &OcctlPrimSplineInfo::get_degree_max);
    godot::ClassDB::bind_method(godot::D_METHOD("set_degree_max", "val"), &OcctlPrimSplineInfo::set_degree_max);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "degree_max"), "set_degree_max", "get_degree_max");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlPrimSplineInfo::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlPrimSplineInfo::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
}

occtl_prim_spline_info_t OcctlPrimSplineInfo::to_c() const {
    occtl_prim_spline_info_t result = {};
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
    result.degree_min = degree_min;
    result.degree_max = degree_max;
    result.tolerance = tolerance;
    return result;
}

Ref<OcctlPrimSplineInfo> OcctlPrimSplineInfo::from_c(const occtl_prim_spline_info_t& val) {
    Ref<OcctlPrimSplineInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field points is not populated from C
    r->point_count = val.point_count;
    r->degree_min = val.degree_min;
    r->degree_max = val.degree_max;
    r->tolerance = val.tolerance;
    return r;
}

void OcctlPrimSplineInfo::copy_from_c(const occtl_prim_spline_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field points is not populated from C
    point_count = val.point_count;
    degree_min = val.degree_min;
    degree_max = val.degree_max;
    tolerance = val.tolerance;
}
