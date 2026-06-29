#include "OcctlSurfacePointGridCreateInfo.h"


int OcctlSurfacePointGridCreateInfo::get_struct_version() const { return struct_version; }
void OcctlSurfacePointGridCreateInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlSurfacePointGridCreateInfo::get_p_next() const { return p_next; }
void OcctlSurfacePointGridCreateInfo::set_p_next(int64_t val) { p_next = val; }

Array OcctlSurfacePointGridCreateInfo::get_points() const { return points; }
void OcctlSurfacePointGridCreateInfo::set_points(Array val) { points = val; }

int OcctlSurfacePointGridCreateInfo::get_u_point_count() const { return u_point_count; }
void OcctlSurfacePointGridCreateInfo::set_u_point_count(int val) { u_point_count = val; }

int OcctlSurfacePointGridCreateInfo::get_v_point_count() const { return v_point_count; }
void OcctlSurfacePointGridCreateInfo::set_v_point_count(int val) { v_point_count = val; }

int OcctlSurfacePointGridCreateInfo::get_mode() const { return mode; }
void OcctlSurfacePointGridCreateInfo::set_mode(int val) { mode = val; }

int OcctlSurfacePointGridCreateInfo::get_degree_min() const { return degree_min; }
void OcctlSurfacePointGridCreateInfo::set_degree_min(int val) { degree_min = val; }

int OcctlSurfacePointGridCreateInfo::get_degree_max() const { return degree_max; }
void OcctlSurfacePointGridCreateInfo::set_degree_max(int val) { degree_max = val; }

int OcctlSurfacePointGridCreateInfo::get_is_u_periodic() const { return is_u_periodic; }
void OcctlSurfacePointGridCreateInfo::set_is_u_periodic(int val) { is_u_periodic = val; }

double OcctlSurfacePointGridCreateInfo::get_tolerance() const { return tolerance; }
void OcctlSurfacePointGridCreateInfo::set_tolerance(double val) { tolerance = val; }

void OcctlSurfacePointGridCreateInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlSurfacePointGridCreateInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlSurfacePointGridCreateInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlSurfacePointGridCreateInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlSurfacePointGridCreateInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_points"), &OcctlSurfacePointGridCreateInfo::get_points);
    godot::ClassDB::bind_method(godot::D_METHOD("set_points", "val"), &OcctlSurfacePointGridCreateInfo::set_points);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "points"), "set_points", "get_points");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_point_count"), &OcctlSurfacePointGridCreateInfo::get_u_point_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_point_count", "val"), &OcctlSurfacePointGridCreateInfo::set_u_point_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "u_point_count"), "set_u_point_count", "get_u_point_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_v_point_count"), &OcctlSurfacePointGridCreateInfo::get_v_point_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_v_point_count", "val"), &OcctlSurfacePointGridCreateInfo::set_v_point_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "v_point_count"), "set_v_point_count", "get_v_point_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_mode"), &OcctlSurfacePointGridCreateInfo::get_mode);
    godot::ClassDB::bind_method(godot::D_METHOD("set_mode", "val"), &OcctlSurfacePointGridCreateInfo::set_mode);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "mode"), "set_mode", "get_mode");
    godot::ClassDB::bind_method(godot::D_METHOD("get_degree_min"), &OcctlSurfacePointGridCreateInfo::get_degree_min);
    godot::ClassDB::bind_method(godot::D_METHOD("set_degree_min", "val"), &OcctlSurfacePointGridCreateInfo::set_degree_min);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "degree_min"), "set_degree_min", "get_degree_min");
    godot::ClassDB::bind_method(godot::D_METHOD("get_degree_max"), &OcctlSurfacePointGridCreateInfo::get_degree_max);
    godot::ClassDB::bind_method(godot::D_METHOD("set_degree_max", "val"), &OcctlSurfacePointGridCreateInfo::set_degree_max);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "degree_max"), "set_degree_max", "get_degree_max");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_u_periodic"), &OcctlSurfacePointGridCreateInfo::get_is_u_periodic);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_u_periodic", "val"), &OcctlSurfacePointGridCreateInfo::set_is_u_periodic);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_u_periodic"), "set_is_u_periodic", "get_is_u_periodic");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlSurfacePointGridCreateInfo::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlSurfacePointGridCreateInfo::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
}

occtl_surface_point_grid_create_info_t OcctlSurfacePointGridCreateInfo::to_c() const {
    occtl_surface_point_grid_create_info_t result = {};
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
    result.mode = static_cast<occtl_surface_point_grid_mode_t>(mode);
    result.degree_min = degree_min;
    result.degree_max = degree_max;
    result.is_u_periodic = is_u_periodic;
    result.tolerance = tolerance;
    return result;
}

Ref<OcctlSurfacePointGridCreateInfo> OcctlSurfacePointGridCreateInfo::from_c(const occtl_surface_point_grid_create_info_t& val) {
    Ref<OcctlSurfacePointGridCreateInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field points is not populated from C
    r->u_point_count = val.u_point_count;
    r->v_point_count = val.v_point_count;
    r->mode = static_cast<int>(val.mode);
    r->degree_min = val.degree_min;
    r->degree_max = val.degree_max;
    r->is_u_periodic = val.is_u_periodic;
    r->tolerance = val.tolerance;
    return r;
}

void OcctlSurfacePointGridCreateInfo::copy_from_c(const occtl_surface_point_grid_create_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field points is not populated from C
    u_point_count = val.u_point_count;
    v_point_count = val.v_point_count;
    mode = static_cast<int>(val.mode);
    degree_min = val.degree_min;
    degree_max = val.degree_max;
    is_u_periodic = val.is_u_periodic;
    tolerance = val.tolerance;
}
