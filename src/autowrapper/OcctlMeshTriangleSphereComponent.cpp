#include "OcctlMeshTriangleSphereComponent.h"

#include "OcctlPoint3.h"
#include "OcctlAabb3.h"

int OcctlMeshTriangleSphereComponent::get_component_id() const { return component_id; }
void OcctlMeshTriangleSphereComponent::set_component_id(int val) { component_id = val; }

int OcctlMeshTriangleSphereComponent::get_triangle_count() const { return triangle_count; }
void OcctlMeshTriangleSphereComponent::set_triangle_count(int val) { triangle_count = val; }

double OcctlMeshTriangleSphereComponent::get_area() const { return area; }
void OcctlMeshTriangleSphereComponent::set_area(double val) { area = val; }

Ref<OcctlPoint3> OcctlMeshTriangleSphereComponent::get_center() const { return center; }
void OcctlMeshTriangleSphereComponent::set_center(Ref<OcctlPoint3> val) { center = val; }

double OcctlMeshTriangleSphereComponent::get_radius() const { return radius; }
void OcctlMeshTriangleSphereComponent::set_radius(double val) { radius = val; }

Ref<OcctlAabb3> OcctlMeshTriangleSphereComponent::get_bounds() const { return bounds; }
void OcctlMeshTriangleSphereComponent::set_bounds(Ref<OcctlAabb3> val) { bounds = val; }

double OcctlMeshTriangleSphereComponent::get_max_distance() const { return max_distance; }
void OcctlMeshTriangleSphereComponent::set_max_distance(double val) { max_distance = val; }

void OcctlMeshTriangleSphereComponent::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_component_id"), &OcctlMeshTriangleSphereComponent::get_component_id);
    godot::ClassDB::bind_method(godot::D_METHOD("set_component_id", "val"), &OcctlMeshTriangleSphereComponent::set_component_id);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "component_id"), "set_component_id", "get_component_id");
    godot::ClassDB::bind_method(godot::D_METHOD("get_triangle_count"), &OcctlMeshTriangleSphereComponent::get_triangle_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_triangle_count", "val"), &OcctlMeshTriangleSphereComponent::set_triangle_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "triangle_count"), "set_triangle_count", "get_triangle_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_area"), &OcctlMeshTriangleSphereComponent::get_area);
    godot::ClassDB::bind_method(godot::D_METHOD("set_area", "val"), &OcctlMeshTriangleSphereComponent::set_area);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "area"), "set_area", "get_area");
    godot::ClassDB::bind_method(godot::D_METHOD("get_center"), &OcctlMeshTriangleSphereComponent::get_center);
    godot::ClassDB::bind_method(godot::D_METHOD("set_center", "val"), &OcctlMeshTriangleSphereComponent::set_center);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "center"), "set_center", "get_center");
    godot::ClassDB::bind_method(godot::D_METHOD("get_radius"), &OcctlMeshTriangleSphereComponent::get_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_radius", "val"), &OcctlMeshTriangleSphereComponent::set_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "radius"), "set_radius", "get_radius");
    godot::ClassDB::bind_method(godot::D_METHOD("get_bounds"), &OcctlMeshTriangleSphereComponent::get_bounds);
    godot::ClassDB::bind_method(godot::D_METHOD("set_bounds", "val"), &OcctlMeshTriangleSphereComponent::set_bounds);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "bounds"), "set_bounds", "get_bounds");
    godot::ClassDB::bind_method(godot::D_METHOD("get_max_distance"), &OcctlMeshTriangleSphereComponent::get_max_distance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max_distance", "val"), &OcctlMeshTriangleSphereComponent::set_max_distance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max_distance"), "set_max_distance", "get_max_distance");
}

occtl_mesh_triangle_sphere_component_t OcctlMeshTriangleSphereComponent::to_c() const {
    occtl_mesh_triangle_sphere_component_t result = {};
    result.component_id = component_id;
    result.triangle_count = triangle_count;
    result.area = area;
    result.center = center->to_c();
    result.radius = radius;
    result.bounds = bounds->to_c();
    result.max_distance = max_distance;
    return result;
}

Ref<OcctlMeshTriangleSphereComponent> OcctlMeshTriangleSphereComponent::from_c(const occtl_mesh_triangle_sphere_component_t& val) {
    Ref<OcctlMeshTriangleSphereComponent> r;
    r.instantiate();
    r->component_id = val.component_id;
    r->triangle_count = val.triangle_count;
    r->area = val.area;
    r->center = OcctlPoint3::from_c(val.center);
    r->radius = val.radius;
    r->bounds = OcctlAabb3::from_c(val.bounds);
    r->max_distance = val.max_distance;
    return r;
}

void OcctlMeshTriangleSphereComponent::copy_from_c(const occtl_mesh_triangle_sphere_component_t& val) {
    component_id = val.component_id;
    triangle_count = val.triangle_count;
    area = val.area;
    center = OcctlPoint3::from_c(val.center);
    radius = val.radius;
    bounds = OcctlAabb3::from_c(val.bounds);
    max_distance = val.max_distance;
}
