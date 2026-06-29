#include "OcctlMeshComponentBoundaryPolylinesView.h"

#include "OcctlNodeId.h"

Array OcctlMeshComponentBoundaryPolylinesView::get_points() const { return points; }
void OcctlMeshComponentBoundaryPolylinesView::set_points(Array val) { points = val; }

int OcctlMeshComponentBoundaryPolylinesView::get_point_count() const { return point_count; }
void OcctlMeshComponentBoundaryPolylinesView::set_point_count(int val) { point_count = val; }

Array OcctlMeshComponentBoundaryPolylinesView::get_polylines() const { return polylines; }
void OcctlMeshComponentBoundaryPolylinesView::set_polylines(Array val) { polylines = val; }

int OcctlMeshComponentBoundaryPolylinesView::get_polyline_count() const { return polyline_count; }
void OcctlMeshComponentBoundaryPolylinesView::set_polyline_count(int val) { polyline_count = val; }

int OcctlMeshComponentBoundaryPolylinesView::get_component_id() const { return component_id; }
void OcctlMeshComponentBoundaryPolylinesView::set_component_id(int val) { component_id = val; }

int64_t OcctlMeshComponentBoundaryPolylinesView::get_root() const { return root; }
void OcctlMeshComponentBoundaryPolylinesView::set_root(int64_t val) { root = val; }

void OcctlMeshComponentBoundaryPolylinesView::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_points"), &OcctlMeshComponentBoundaryPolylinesView::get_points);
    godot::ClassDB::bind_method(godot::D_METHOD("set_points", "val"), &OcctlMeshComponentBoundaryPolylinesView::set_points);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "points"), "set_points", "get_points");
    godot::ClassDB::bind_method(godot::D_METHOD("get_point_count"), &OcctlMeshComponentBoundaryPolylinesView::get_point_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_point_count", "val"), &OcctlMeshComponentBoundaryPolylinesView::set_point_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "point_count"), "set_point_count", "get_point_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_polylines"), &OcctlMeshComponentBoundaryPolylinesView::get_polylines);
    godot::ClassDB::bind_method(godot::D_METHOD("set_polylines", "val"), &OcctlMeshComponentBoundaryPolylinesView::set_polylines);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "polylines"), "set_polylines", "get_polylines");
    godot::ClassDB::bind_method(godot::D_METHOD("get_polyline_count"), &OcctlMeshComponentBoundaryPolylinesView::get_polyline_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_polyline_count", "val"), &OcctlMeshComponentBoundaryPolylinesView::set_polyline_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "polyline_count"), "set_polyline_count", "get_polyline_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_component_id"), &OcctlMeshComponentBoundaryPolylinesView::get_component_id);
    godot::ClassDB::bind_method(godot::D_METHOD("set_component_id", "val"), &OcctlMeshComponentBoundaryPolylinesView::set_component_id);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "component_id"), "set_component_id", "get_component_id");
    godot::ClassDB::bind_method(godot::D_METHOD("get_root"), &OcctlMeshComponentBoundaryPolylinesView::get_root);
    godot::ClassDB::bind_method(godot::D_METHOD("set_root", "val"), &OcctlMeshComponentBoundaryPolylinesView::set_root);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "root"), "set_root", "get_root");
}

occtl_mesh_component_boundary_polylines_view_t OcctlMeshComponentBoundaryPolylinesView::to_c() const {
    occtl_mesh_component_boundary_polylines_view_t result = {};
    _cache_points.resize(points.size());
    for (int _i = 0; _i < points.size(); _i++) {
        Ref<OcctlPoint3> _item = points[_i];
        if (_item.is_valid()) _cache_points[_i] = _item->to_c();
        else _cache_points[_i] = {};
    }
    result.points = _cache_points.data();
    result.point_count = point_count;
    _cache_polylines.resize(polylines.size());
    for (int _i = 0; _i < polylines.size(); _i++) {
        Ref<OcctlMeshComponentBoundaryPolyline> _item = polylines[_i];
        if (_item.is_valid()) _cache_polylines[_i] = _item->to_c();
        else _cache_polylines[_i] = {};
    }
    result.polylines = _cache_polylines.data();
    result.polyline_count = polyline_count;
    result.component_id = component_id;
    result.root.bits = static_cast<uint64_t>(root);
    return result;
}

Ref<OcctlMeshComponentBoundaryPolylinesView> OcctlMeshComponentBoundaryPolylinesView::from_c(const occtl_mesh_component_boundary_polylines_view_t& val) {
    Ref<OcctlMeshComponentBoundaryPolylinesView> r;
    r.instantiate();
    // array field points is not populated from C
    r->point_count = val.point_count;
    // array field polylines is not populated from C
    r->polyline_count = val.polyline_count;
    r->component_id = val.component_id;
    r->root = static_cast<int64_t>(val.root.bits);
    return r;
}

void OcctlMeshComponentBoundaryPolylinesView::copy_from_c(const occtl_mesh_component_boundary_polylines_view_t& val) {
    // array field points is not populated from C
    point_count = val.point_count;
    // array field polylines is not populated from C
    polyline_count = val.polyline_count;
    component_id = val.component_id;
    root = static_cast<int64_t>(val.root.bits);
}
