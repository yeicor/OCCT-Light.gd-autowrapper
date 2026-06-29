#include "OcctlMeshTriangleCylinderComponent.h"

#include "OcctlPoint3.h"
#include "OcctlVector3.h"
#include "OcctlAabb3.h"

int OcctlMeshTriangleCylinderComponent::get_component_id() const { return component_id; }
void OcctlMeshTriangleCylinderComponent::set_component_id(int val) { component_id = val; }

int OcctlMeshTriangleCylinderComponent::get_triangle_count() const { return triangle_count; }
void OcctlMeshTriangleCylinderComponent::set_triangle_count(int val) { triangle_count = val; }

double OcctlMeshTriangleCylinderComponent::get_area() const { return area; }
void OcctlMeshTriangleCylinderComponent::set_area(double val) { area = val; }

Ref<OcctlPoint3> OcctlMeshTriangleCylinderComponent::get_axis_origin() const { return axis_origin; }
void OcctlMeshTriangleCylinderComponent::set_axis_origin(Ref<OcctlPoint3> val) { axis_origin = val; }

Ref<OcctlVector3> OcctlMeshTriangleCylinderComponent::get_axis_direction() const { return axis_direction; }
void OcctlMeshTriangleCylinderComponent::set_axis_direction(Ref<OcctlVector3> val) { axis_direction = val; }

double OcctlMeshTriangleCylinderComponent::get_radius() const { return radius; }
void OcctlMeshTriangleCylinderComponent::set_radius(double val) { radius = val; }

double OcctlMeshTriangleCylinderComponent::get_height_min() const { return height_min; }
void OcctlMeshTriangleCylinderComponent::set_height_min(double val) { height_min = val; }

double OcctlMeshTriangleCylinderComponent::get_height_max() const { return height_max; }
void OcctlMeshTriangleCylinderComponent::set_height_max(double val) { height_max = val; }

Ref<OcctlAabb3> OcctlMeshTriangleCylinderComponent::get_bounds() const { return bounds; }
void OcctlMeshTriangleCylinderComponent::set_bounds(Ref<OcctlAabb3> val) { bounds = val; }

double OcctlMeshTriangleCylinderComponent::get_max_distance() const { return max_distance; }
void OcctlMeshTriangleCylinderComponent::set_max_distance(double val) { max_distance = val; }

void OcctlMeshTriangleCylinderComponent::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_component_id"), &OcctlMeshTriangleCylinderComponent::get_component_id);
    godot::ClassDB::bind_method(godot::D_METHOD("set_component_id", "val"), &OcctlMeshTriangleCylinderComponent::set_component_id);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "component_id"), "set_component_id", "get_component_id");
    godot::ClassDB::bind_method(godot::D_METHOD("get_triangle_count"), &OcctlMeshTriangleCylinderComponent::get_triangle_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_triangle_count", "val"), &OcctlMeshTriangleCylinderComponent::set_triangle_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "triangle_count"), "set_triangle_count", "get_triangle_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_area"), &OcctlMeshTriangleCylinderComponent::get_area);
    godot::ClassDB::bind_method(godot::D_METHOD("set_area", "val"), &OcctlMeshTriangleCylinderComponent::set_area);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "area"), "set_area", "get_area");
    godot::ClassDB::bind_method(godot::D_METHOD("get_axis_origin"), &OcctlMeshTriangleCylinderComponent::get_axis_origin);
    godot::ClassDB::bind_method(godot::D_METHOD("set_axis_origin", "val"), &OcctlMeshTriangleCylinderComponent::set_axis_origin);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "axis_origin"), "set_axis_origin", "get_axis_origin");
    godot::ClassDB::bind_method(godot::D_METHOD("get_axis_direction"), &OcctlMeshTriangleCylinderComponent::get_axis_direction);
    godot::ClassDB::bind_method(godot::D_METHOD("set_axis_direction", "val"), &OcctlMeshTriangleCylinderComponent::set_axis_direction);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "axis_direction"), "set_axis_direction", "get_axis_direction");
    godot::ClassDB::bind_method(godot::D_METHOD("get_radius"), &OcctlMeshTriangleCylinderComponent::get_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_radius", "val"), &OcctlMeshTriangleCylinderComponent::set_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "radius"), "set_radius", "get_radius");
    godot::ClassDB::bind_method(godot::D_METHOD("get_height_min"), &OcctlMeshTriangleCylinderComponent::get_height_min);
    godot::ClassDB::bind_method(godot::D_METHOD("set_height_min", "val"), &OcctlMeshTriangleCylinderComponent::set_height_min);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "height_min"), "set_height_min", "get_height_min");
    godot::ClassDB::bind_method(godot::D_METHOD("get_height_max"), &OcctlMeshTriangleCylinderComponent::get_height_max);
    godot::ClassDB::bind_method(godot::D_METHOD("set_height_max", "val"), &OcctlMeshTriangleCylinderComponent::set_height_max);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "height_max"), "set_height_max", "get_height_max");
    godot::ClassDB::bind_method(godot::D_METHOD("get_bounds"), &OcctlMeshTriangleCylinderComponent::get_bounds);
    godot::ClassDB::bind_method(godot::D_METHOD("set_bounds", "val"), &OcctlMeshTriangleCylinderComponent::set_bounds);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "bounds"), "set_bounds", "get_bounds");
    godot::ClassDB::bind_method(godot::D_METHOD("get_max_distance"), &OcctlMeshTriangleCylinderComponent::get_max_distance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max_distance", "val"), &OcctlMeshTriangleCylinderComponent::set_max_distance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max_distance"), "set_max_distance", "get_max_distance");
}

occtl_mesh_triangle_cylinder_component_t OcctlMeshTriangleCylinderComponent::to_c() const {
    occtl_mesh_triangle_cylinder_component_t result = {};
    result.component_id = component_id;
    result.triangle_count = triangle_count;
    result.area = area;
    result.axis_origin = axis_origin->to_c();
    result.axis_direction = axis_direction->to_c();
    result.radius = radius;
    result.height_min = height_min;
    result.height_max = height_max;
    result.bounds = bounds->to_c();
    result.max_distance = max_distance;
    return result;
}

Ref<OcctlMeshTriangleCylinderComponent> OcctlMeshTriangleCylinderComponent::from_c(const occtl_mesh_triangle_cylinder_component_t& val) {
    Ref<OcctlMeshTriangleCylinderComponent> r;
    r.instantiate();
    r->component_id = val.component_id;
    r->triangle_count = val.triangle_count;
    r->area = val.area;
    r->axis_origin = OcctlPoint3::from_c(val.axis_origin);
    r->axis_direction = OcctlVector3::from_c(val.axis_direction);
    r->radius = val.radius;
    r->height_min = val.height_min;
    r->height_max = val.height_max;
    r->bounds = OcctlAabb3::from_c(val.bounds);
    r->max_distance = val.max_distance;
    return r;
}

void OcctlMeshTriangleCylinderComponent::copy_from_c(const occtl_mesh_triangle_cylinder_component_t& val) {
    component_id = val.component_id;
    triangle_count = val.triangle_count;
    area = val.area;
    axis_origin = OcctlPoint3::from_c(val.axis_origin);
    axis_direction = OcctlVector3::from_c(val.axis_direction);
    radius = val.radius;
    height_min = val.height_min;
    height_max = val.height_max;
    bounds = OcctlAabb3::from_c(val.bounds);
    max_distance = val.max_distance;
}
