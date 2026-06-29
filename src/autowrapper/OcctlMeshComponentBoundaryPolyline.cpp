#include "OcctlMeshComponentBoundaryPolyline.h"


int OcctlMeshComponentBoundaryPolyline::get_first_point() const { return first_point; }
void OcctlMeshComponentBoundaryPolyline::set_first_point(int val) { first_point = val; }

int OcctlMeshComponentBoundaryPolyline::get_point_count() const { return point_count; }
void OcctlMeshComponentBoundaryPolyline::set_point_count(int val) { point_count = val; }

int OcctlMeshComponentBoundaryPolyline::get_is_closed() const { return is_closed; }
void OcctlMeshComponentBoundaryPolyline::set_is_closed(int val) { is_closed = val; }

void OcctlMeshComponentBoundaryPolyline::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_first_point"), &OcctlMeshComponentBoundaryPolyline::get_first_point);
    godot::ClassDB::bind_method(godot::D_METHOD("set_first_point", "val"), &OcctlMeshComponentBoundaryPolyline::set_first_point);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "first_point"), "set_first_point", "get_first_point");
    godot::ClassDB::bind_method(godot::D_METHOD("get_point_count"), &OcctlMeshComponentBoundaryPolyline::get_point_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_point_count", "val"), &OcctlMeshComponentBoundaryPolyline::set_point_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "point_count"), "set_point_count", "get_point_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_closed"), &OcctlMeshComponentBoundaryPolyline::get_is_closed);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_closed", "val"), &OcctlMeshComponentBoundaryPolyline::set_is_closed);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_closed"), "set_is_closed", "get_is_closed");
}

occtl_mesh_component_boundary_polyline_t OcctlMeshComponentBoundaryPolyline::to_c() const {
    occtl_mesh_component_boundary_polyline_t result = {};
    result.first_point = first_point;
    result.point_count = point_count;
    result.is_closed = is_closed;
    return result;
}

Ref<OcctlMeshComponentBoundaryPolyline> OcctlMeshComponentBoundaryPolyline::from_c(const occtl_mesh_component_boundary_polyline_t& val) {
    Ref<OcctlMeshComponentBoundaryPolyline> r;
    r.instantiate();
    r->first_point = val.first_point;
    r->point_count = val.point_count;
    r->is_closed = val.is_closed;
    return r;
}

void OcctlMeshComponentBoundaryPolyline::copy_from_c(const occtl_mesh_component_boundary_polyline_t& val) {
    first_point = val.first_point;
    point_count = val.point_count;
    is_closed = val.is_closed;
}
