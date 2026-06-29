#include "OcctlMeshTriangleComponentSummary.h"

#include "OcctlPoint3.h"
#include "OcctlVector3.h"
#include "OcctlAabb3.h"

int OcctlMeshTriangleComponentSummary::get_component_id() const { return component_id; }
void OcctlMeshTriangleComponentSummary::set_component_id(int val) { component_id = val; }

int OcctlMeshTriangleComponentSummary::get_triangle_count() const { return triangle_count; }
void OcctlMeshTriangleComponentSummary::set_triangle_count(int val) { triangle_count = val; }

double OcctlMeshTriangleComponentSummary::get_area() const { return area; }
void OcctlMeshTriangleComponentSummary::set_area(double val) { area = val; }

Ref<OcctlPoint3> OcctlMeshTriangleComponentSummary::get_centroid() const { return centroid; }
void OcctlMeshTriangleComponentSummary::set_centroid(Ref<OcctlPoint3> val) { centroid = val; }

Ref<OcctlVector3> OcctlMeshTriangleComponentSummary::get_normal() const { return normal; }
void OcctlMeshTriangleComponentSummary::set_normal(Ref<OcctlVector3> val) { normal = val; }

Ref<OcctlAabb3> OcctlMeshTriangleComponentSummary::get_bounds() const { return bounds; }
void OcctlMeshTriangleComponentSummary::set_bounds(Ref<OcctlAabb3> val) { bounds = val; }

void OcctlMeshTriangleComponentSummary::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_component_id"), &OcctlMeshTriangleComponentSummary::get_component_id);
    godot::ClassDB::bind_method(godot::D_METHOD("set_component_id", "val"), &OcctlMeshTriangleComponentSummary::set_component_id);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "component_id"), "set_component_id", "get_component_id");
    godot::ClassDB::bind_method(godot::D_METHOD("get_triangle_count"), &OcctlMeshTriangleComponentSummary::get_triangle_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_triangle_count", "val"), &OcctlMeshTriangleComponentSummary::set_triangle_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "triangle_count"), "set_triangle_count", "get_triangle_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_area"), &OcctlMeshTriangleComponentSummary::get_area);
    godot::ClassDB::bind_method(godot::D_METHOD("set_area", "val"), &OcctlMeshTriangleComponentSummary::set_area);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "area"), "set_area", "get_area");
    godot::ClassDB::bind_method(godot::D_METHOD("get_centroid"), &OcctlMeshTriangleComponentSummary::get_centroid);
    godot::ClassDB::bind_method(godot::D_METHOD("set_centroid", "val"), &OcctlMeshTriangleComponentSummary::set_centroid);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "centroid"), "set_centroid", "get_centroid");
    godot::ClassDB::bind_method(godot::D_METHOD("get_normal"), &OcctlMeshTriangleComponentSummary::get_normal);
    godot::ClassDB::bind_method(godot::D_METHOD("set_normal", "val"), &OcctlMeshTriangleComponentSummary::set_normal);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "normal"), "set_normal", "get_normal");
    godot::ClassDB::bind_method(godot::D_METHOD("get_bounds"), &OcctlMeshTriangleComponentSummary::get_bounds);
    godot::ClassDB::bind_method(godot::D_METHOD("set_bounds", "val"), &OcctlMeshTriangleComponentSummary::set_bounds);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "bounds"), "set_bounds", "get_bounds");
}

occtl_mesh_triangle_component_summary_t OcctlMeshTriangleComponentSummary::to_c() const {
    occtl_mesh_triangle_component_summary_t result = {};
    result.component_id = component_id;
    result.triangle_count = triangle_count;
    result.area = area;
    result.centroid = centroid->to_c();
    result.normal = normal->to_c();
    result.bounds = bounds->to_c();
    return result;
}

Ref<OcctlMeshTriangleComponentSummary> OcctlMeshTriangleComponentSummary::from_c(const occtl_mesh_triangle_component_summary_t& val) {
    Ref<OcctlMeshTriangleComponentSummary> r;
    r.instantiate();
    r->component_id = val.component_id;
    r->triangle_count = val.triangle_count;
    r->area = val.area;
    r->centroid = OcctlPoint3::from_c(val.centroid);
    r->normal = OcctlVector3::from_c(val.normal);
    r->bounds = OcctlAabb3::from_c(val.bounds);
    return r;
}

void OcctlMeshTriangleComponentSummary::copy_from_c(const occtl_mesh_triangle_component_summary_t& val) {
    component_id = val.component_id;
    triangle_count = val.triangle_count;
    area = val.area;
    centroid = OcctlPoint3::from_c(val.centroid);
    normal = OcctlVector3::from_c(val.normal);
    bounds = OcctlAabb3::from_c(val.bounds);
}
