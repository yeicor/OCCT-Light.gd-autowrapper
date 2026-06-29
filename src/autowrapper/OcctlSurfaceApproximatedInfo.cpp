#include "OcctlSurfaceApproximatedInfo.h"


int OcctlSurfaceApproximatedInfo::get_struct_version() const { return struct_version; }
void OcctlSurfaceApproximatedInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlSurfaceApproximatedInfo::get_p_next() const { return p_next; }
void OcctlSurfaceApproximatedInfo::set_p_next(int64_t val) { p_next = val; }

Array OcctlSurfaceApproximatedInfo::get_points() const { return points; }
void OcctlSurfaceApproximatedInfo::set_points(Array val) { points = val; }

int OcctlSurfaceApproximatedInfo::get_u_point_count() const { return u_point_count; }
void OcctlSurfaceApproximatedInfo::set_u_point_count(int val) { u_point_count = val; }

int OcctlSurfaceApproximatedInfo::get_v_point_count() const { return v_point_count; }
void OcctlSurfaceApproximatedInfo::set_v_point_count(int val) { v_point_count = val; }

int OcctlSurfaceApproximatedInfo::get_degree_min() const { return degree_min; }
void OcctlSurfaceApproximatedInfo::set_degree_min(int val) { degree_min = val; }

int OcctlSurfaceApproximatedInfo::get_degree_max() const { return degree_max; }
void OcctlSurfaceApproximatedInfo::set_degree_max(int val) { degree_max = val; }

double OcctlSurfaceApproximatedInfo::get_tolerance() const { return tolerance; }
void OcctlSurfaceApproximatedInfo::set_tolerance(double val) { tolerance = val; }

void OcctlSurfaceApproximatedInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlSurfaceApproximatedInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlSurfaceApproximatedInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlSurfaceApproximatedInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlSurfaceApproximatedInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_points"), &OcctlSurfaceApproximatedInfo::get_points);
    godot::ClassDB::bind_method(godot::D_METHOD("set_points", "val"), &OcctlSurfaceApproximatedInfo::set_points);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "points"), "set_points", "get_points");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_point_count"), &OcctlSurfaceApproximatedInfo::get_u_point_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_point_count", "val"), &OcctlSurfaceApproximatedInfo::set_u_point_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "u_point_count"), "set_u_point_count", "get_u_point_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_v_point_count"), &OcctlSurfaceApproximatedInfo::get_v_point_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_v_point_count", "val"), &OcctlSurfaceApproximatedInfo::set_v_point_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "v_point_count"), "set_v_point_count", "get_v_point_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_degree_min"), &OcctlSurfaceApproximatedInfo::get_degree_min);
    godot::ClassDB::bind_method(godot::D_METHOD("set_degree_min", "val"), &OcctlSurfaceApproximatedInfo::set_degree_min);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "degree_min"), "set_degree_min", "get_degree_min");
    godot::ClassDB::bind_method(godot::D_METHOD("get_degree_max"), &OcctlSurfaceApproximatedInfo::get_degree_max);
    godot::ClassDB::bind_method(godot::D_METHOD("set_degree_max", "val"), &OcctlSurfaceApproximatedInfo::set_degree_max);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "degree_max"), "set_degree_max", "get_degree_max");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlSurfaceApproximatedInfo::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlSurfaceApproximatedInfo::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
}

occtl_surface_approximated_info_t OcctlSurfaceApproximatedInfo::to_c() const {
    occtl_surface_approximated_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    _cache_points.resize(points.size());
    for (int _i = 0; _i < points.size(); _i++) {
        Ref<OcctlPoint3> _item = points[_i];
        if (_item.is_valid()) _cache_points[_i] = _item->to_c();
        else _cache_points[_i] = {};
    }
    result.points = _cache_points.data();
    result.u_point_count = u_point_count;
    result.v_point_count = v_point_count;
    result.degree_min = degree_min;
    result.degree_max = degree_max;
    result.tolerance = tolerance;
    return result;
}

Ref<OcctlSurfaceApproximatedInfo> OcctlSurfaceApproximatedInfo::from_c(const occtl_surface_approximated_info_t& val) {
    Ref<OcctlSurfaceApproximatedInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field points is not populated from C
    r->u_point_count = val.u_point_count;
    r->v_point_count = val.v_point_count;
    r->degree_min = val.degree_min;
    r->degree_max = val.degree_max;
    r->tolerance = val.tolerance;
    return r;
}

void OcctlSurfaceApproximatedInfo::copy_from_c(const occtl_surface_approximated_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field points is not populated from C
    u_point_count = val.u_point_count;
    v_point_count = val.v_point_count;
    degree_min = val.degree_min;
    degree_max = val.degree_max;
    tolerance = val.tolerance;
}
