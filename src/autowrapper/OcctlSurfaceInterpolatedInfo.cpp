#include "OcctlSurfaceInterpolatedInfo.h"


int OcctlSurfaceInterpolatedInfo::get_struct_version() const { return struct_version; }
void OcctlSurfaceInterpolatedInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlSurfaceInterpolatedInfo::get_p_next() const { return p_next; }
void OcctlSurfaceInterpolatedInfo::set_p_next(int64_t val) { p_next = val; }

Array OcctlSurfaceInterpolatedInfo::get_points() const { return points; }
void OcctlSurfaceInterpolatedInfo::set_points(Array val) { points = val; }

int OcctlSurfaceInterpolatedInfo::get_u_point_count() const { return u_point_count; }
void OcctlSurfaceInterpolatedInfo::set_u_point_count(int val) { u_point_count = val; }

int OcctlSurfaceInterpolatedInfo::get_v_point_count() const { return v_point_count; }
void OcctlSurfaceInterpolatedInfo::set_v_point_count(int val) { v_point_count = val; }

int OcctlSurfaceInterpolatedInfo::get_is_u_periodic() const { return is_u_periodic; }
void OcctlSurfaceInterpolatedInfo::set_is_u_periodic(int val) { is_u_periodic = val; }

void OcctlSurfaceInterpolatedInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlSurfaceInterpolatedInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlSurfaceInterpolatedInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlSurfaceInterpolatedInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlSurfaceInterpolatedInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_points"), &OcctlSurfaceInterpolatedInfo::get_points);
    godot::ClassDB::bind_method(godot::D_METHOD("set_points", "val"), &OcctlSurfaceInterpolatedInfo::set_points);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "points"), "set_points", "get_points");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_point_count"), &OcctlSurfaceInterpolatedInfo::get_u_point_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_point_count", "val"), &OcctlSurfaceInterpolatedInfo::set_u_point_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "u_point_count"), "set_u_point_count", "get_u_point_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_v_point_count"), &OcctlSurfaceInterpolatedInfo::get_v_point_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_v_point_count", "val"), &OcctlSurfaceInterpolatedInfo::set_v_point_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "v_point_count"), "set_v_point_count", "get_v_point_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_u_periodic"), &OcctlSurfaceInterpolatedInfo::get_is_u_periodic);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_u_periodic", "val"), &OcctlSurfaceInterpolatedInfo::set_is_u_periodic);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_u_periodic"), "set_is_u_periodic", "get_is_u_periodic");
}

occtl_surface_interpolated_info_t OcctlSurfaceInterpolatedInfo::to_c() const {
    occtl_surface_interpolated_info_t result = {};
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
    result.is_u_periodic = is_u_periodic;
    return result;
}

Ref<OcctlSurfaceInterpolatedInfo> OcctlSurfaceInterpolatedInfo::from_c(const occtl_surface_interpolated_info_t& val) {
    Ref<OcctlSurfaceInterpolatedInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field points is not populated from C
    r->u_point_count = val.u_point_count;
    r->v_point_count = val.v_point_count;
    r->is_u_periodic = val.is_u_periodic;
    return r;
}

void OcctlSurfaceInterpolatedInfo::copy_from_c(const occtl_surface_interpolated_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field points is not populated from C
    u_point_count = val.u_point_count;
    v_point_count = val.v_point_count;
    is_u_periodic = val.is_u_periodic;
}
