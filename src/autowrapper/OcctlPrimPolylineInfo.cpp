#include "OcctlPrimPolylineInfo.h"


int OcctlPrimPolylineInfo::get_struct_version() const { return struct_version; }
void OcctlPrimPolylineInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimPolylineInfo::get_p_next() const { return p_next; }
void OcctlPrimPolylineInfo::set_p_next(int64_t val) { p_next = val; }

Array OcctlPrimPolylineInfo::get_points() const { return points; }
void OcctlPrimPolylineInfo::set_points(Array val) { points = val; }

int OcctlPrimPolylineInfo::get_point_count() const { return point_count; }
void OcctlPrimPolylineInfo::set_point_count(int val) { point_count = val; }

int OcctlPrimPolylineInfo::get_closed() const { return closed; }
void OcctlPrimPolylineInfo::set_closed(int val) { closed = val; }

void OcctlPrimPolylineInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimPolylineInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimPolylineInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimPolylineInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimPolylineInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_points"), &OcctlPrimPolylineInfo::get_points);
    godot::ClassDB::bind_method(godot::D_METHOD("set_points", "val"), &OcctlPrimPolylineInfo::set_points);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "points"), "set_points", "get_points");
    godot::ClassDB::bind_method(godot::D_METHOD("get_point_count"), &OcctlPrimPolylineInfo::get_point_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_point_count", "val"), &OcctlPrimPolylineInfo::set_point_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "point_count"), "set_point_count", "get_point_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_closed"), &OcctlPrimPolylineInfo::get_closed);
    godot::ClassDB::bind_method(godot::D_METHOD("set_closed", "val"), &OcctlPrimPolylineInfo::set_closed);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "closed"), "set_closed", "get_closed");
}

occtl_prim_polyline_info_t OcctlPrimPolylineInfo::to_c() const {
    occtl_prim_polyline_info_t result = {};
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
    result.closed = closed;
    return result;
}

Ref<OcctlPrimPolylineInfo> OcctlPrimPolylineInfo::from_c(const occtl_prim_polyline_info_t& val) {
    Ref<OcctlPrimPolylineInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field points is not populated from C
    r->point_count = val.point_count;
    r->closed = val.closed;
    return r;
}

void OcctlPrimPolylineInfo::copy_from_c(const occtl_prim_polyline_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field points is not populated from C
    point_count = val.point_count;
    closed = val.closed;
}
