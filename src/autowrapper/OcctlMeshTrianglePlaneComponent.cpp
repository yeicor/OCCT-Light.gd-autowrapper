#include "OcctlMeshTrianglePlaneComponent.h"

#include "OcctlPoint3.h"
#include "OcctlVector3.h"
#include "OcctlAabb3.h"

int OcctlMeshTrianglePlaneComponent::get_component_id() const { return component_id; }
void OcctlMeshTrianglePlaneComponent::set_component_id(int val) { component_id = val; }

int OcctlMeshTrianglePlaneComponent::get_triangle_count() const { return triangle_count; }
void OcctlMeshTrianglePlaneComponent::set_triangle_count(int val) { triangle_count = val; }

double OcctlMeshTrianglePlaneComponent::get_area() const { return area; }
void OcctlMeshTrianglePlaneComponent::set_area(double val) { area = val; }

Ref<OcctlPoint3> OcctlMeshTrianglePlaneComponent::get_origin() const { return origin; }
void OcctlMeshTrianglePlaneComponent::set_origin(Ref<OcctlPoint3> val) { origin = val; }

Ref<OcctlVector3> OcctlMeshTrianglePlaneComponent::get_normal() const { return normal; }
void OcctlMeshTrianglePlaneComponent::set_normal(Ref<OcctlVector3> val) { normal = val; }

Ref<OcctlAabb3> OcctlMeshTrianglePlaneComponent::get_bounds() const { return bounds; }
void OcctlMeshTrianglePlaneComponent::set_bounds(Ref<OcctlAabb3> val) { bounds = val; }

double OcctlMeshTrianglePlaneComponent::get_max_distance() const { return max_distance; }
void OcctlMeshTrianglePlaneComponent::set_max_distance(double val) { max_distance = val; }

void OcctlMeshTrianglePlaneComponent::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_component_id"), &OcctlMeshTrianglePlaneComponent::get_component_id);
    godot::ClassDB::bind_method(godot::D_METHOD("set_component_id", "val"), &OcctlMeshTrianglePlaneComponent::set_component_id);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "component_id"), "set_component_id", "get_component_id");
    godot::ClassDB::bind_method(godot::D_METHOD("get_triangle_count"), &OcctlMeshTrianglePlaneComponent::get_triangle_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_triangle_count", "val"), &OcctlMeshTrianglePlaneComponent::set_triangle_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "triangle_count"), "set_triangle_count", "get_triangle_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_area"), &OcctlMeshTrianglePlaneComponent::get_area);
    godot::ClassDB::bind_method(godot::D_METHOD("set_area", "val"), &OcctlMeshTrianglePlaneComponent::set_area);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "area"), "set_area", "get_area");
    godot::ClassDB::bind_method(godot::D_METHOD("get_origin"), &OcctlMeshTrianglePlaneComponent::get_origin);
    godot::ClassDB::bind_method(godot::D_METHOD("set_origin", "val"), &OcctlMeshTrianglePlaneComponent::set_origin);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "origin"), "set_origin", "get_origin");
    godot::ClassDB::bind_method(godot::D_METHOD("get_normal"), &OcctlMeshTrianglePlaneComponent::get_normal);
    godot::ClassDB::bind_method(godot::D_METHOD("set_normal", "val"), &OcctlMeshTrianglePlaneComponent::set_normal);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "normal"), "set_normal", "get_normal");
    godot::ClassDB::bind_method(godot::D_METHOD("get_bounds"), &OcctlMeshTrianglePlaneComponent::get_bounds);
    godot::ClassDB::bind_method(godot::D_METHOD("set_bounds", "val"), &OcctlMeshTrianglePlaneComponent::set_bounds);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "bounds"), "set_bounds", "get_bounds");
    godot::ClassDB::bind_method(godot::D_METHOD("get_max_distance"), &OcctlMeshTrianglePlaneComponent::get_max_distance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max_distance", "val"), &OcctlMeshTrianglePlaneComponent::set_max_distance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max_distance"), "set_max_distance", "get_max_distance");
}

occtl_mesh_triangle_plane_component_t OcctlMeshTrianglePlaneComponent::to_c() const {
    occtl_mesh_triangle_plane_component_t result = {};
    result.component_id = component_id;
    result.triangle_count = triangle_count;
    result.area = area;
    result.origin = origin->to_c();
    result.normal = normal->to_c();
    result.bounds = bounds->to_c();
    result.max_distance = max_distance;
    return result;
}

Ref<OcctlMeshTrianglePlaneComponent> OcctlMeshTrianglePlaneComponent::from_c(const occtl_mesh_triangle_plane_component_t& val) {
    Ref<OcctlMeshTrianglePlaneComponent> r;
    r.instantiate();
    r->component_id = val.component_id;
    r->triangle_count = val.triangle_count;
    r->area = val.area;
    r->origin = OcctlPoint3::from_c(val.origin);
    r->normal = OcctlVector3::from_c(val.normal);
    r->bounds = OcctlAabb3::from_c(val.bounds);
    r->max_distance = val.max_distance;
    return r;
}

void OcctlMeshTrianglePlaneComponent::copy_from_c(const occtl_mesh_triangle_plane_component_t& val) {
    component_id = val.component_id;
    triangle_count = val.triangle_count;
    area = val.area;
    origin = OcctlPoint3::from_c(val.origin);
    normal = OcctlVector3::from_c(val.normal);
    bounds = OcctlAabb3::from_c(val.bounds);
    max_distance = val.max_distance;
}
