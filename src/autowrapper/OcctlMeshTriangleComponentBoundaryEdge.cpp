#include "OcctlMeshTriangleComponentBoundaryEdge.h"


int OcctlMeshTriangleComponentBoundaryEdge::get_triangle() const { return triangle; }
void OcctlMeshTriangleComponentBoundaryEdge::set_triangle(int val) { triangle = val; }

int OcctlMeshTriangleComponentBoundaryEdge::get_local_edge() const { return local_edge; }
void OcctlMeshTriangleComponentBoundaryEdge::set_local_edge(int val) { local_edge = val; }

int OcctlMeshTriangleComponentBoundaryEdge::get_node0() const { return node0; }
void OcctlMeshTriangleComponentBoundaryEdge::set_node0(int val) { node0 = val; }

int OcctlMeshTriangleComponentBoundaryEdge::get_node1() const { return node1; }
void OcctlMeshTriangleComponentBoundaryEdge::set_node1(int val) { node1 = val; }

int OcctlMeshTriangleComponentBoundaryEdge::get_adjacent_triangle() const { return adjacent_triangle; }
void OcctlMeshTriangleComponentBoundaryEdge::set_adjacent_triangle(int val) { adjacent_triangle = val; }

void OcctlMeshTriangleComponentBoundaryEdge::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_triangle"), &OcctlMeshTriangleComponentBoundaryEdge::get_triangle);
    godot::ClassDB::bind_method(godot::D_METHOD("set_triangle", "val"), &OcctlMeshTriangleComponentBoundaryEdge::set_triangle);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "triangle"), "set_triangle", "get_triangle");
    godot::ClassDB::bind_method(godot::D_METHOD("get_local_edge"), &OcctlMeshTriangleComponentBoundaryEdge::get_local_edge);
    godot::ClassDB::bind_method(godot::D_METHOD("set_local_edge", "val"), &OcctlMeshTriangleComponentBoundaryEdge::set_local_edge);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "local_edge"), "set_local_edge", "get_local_edge");
    godot::ClassDB::bind_method(godot::D_METHOD("get_node0"), &OcctlMeshTriangleComponentBoundaryEdge::get_node0);
    godot::ClassDB::bind_method(godot::D_METHOD("set_node0", "val"), &OcctlMeshTriangleComponentBoundaryEdge::set_node0);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "node0"), "set_node0", "get_node0");
    godot::ClassDB::bind_method(godot::D_METHOD("get_node1"), &OcctlMeshTriangleComponentBoundaryEdge::get_node1);
    godot::ClassDB::bind_method(godot::D_METHOD("set_node1", "val"), &OcctlMeshTriangleComponentBoundaryEdge::set_node1);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "node1"), "set_node1", "get_node1");
    godot::ClassDB::bind_method(godot::D_METHOD("get_adjacent_triangle"), &OcctlMeshTriangleComponentBoundaryEdge::get_adjacent_triangle);
    godot::ClassDB::bind_method(godot::D_METHOD("set_adjacent_triangle", "val"), &OcctlMeshTriangleComponentBoundaryEdge::set_adjacent_triangle);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "adjacent_triangle"), "set_adjacent_triangle", "get_adjacent_triangle");
}

occtl_mesh_triangle_component_boundary_edge_t OcctlMeshTriangleComponentBoundaryEdge::to_c() const {
    occtl_mesh_triangle_component_boundary_edge_t result = {};
    result.triangle = triangle;
    result.local_edge = local_edge;
    result.node0 = node0;
    result.node1 = node1;
    result.adjacent_triangle = adjacent_triangle;
    return result;
}

Ref<OcctlMeshTriangleComponentBoundaryEdge> OcctlMeshTriangleComponentBoundaryEdge::from_c(const occtl_mesh_triangle_component_boundary_edge_t& val) {
    Ref<OcctlMeshTriangleComponentBoundaryEdge> r;
    r.instantiate();
    r->triangle = val.triangle;
    r->local_edge = val.local_edge;
    r->node0 = val.node0;
    r->node1 = val.node1;
    r->adjacent_triangle = val.adjacent_triangle;
    return r;
}

void OcctlMeshTriangleComponentBoundaryEdge::copy_from_c(const occtl_mesh_triangle_component_boundary_edge_t& val) {
    triangle = val.triangle;
    local_edge = val.local_edge;
    node0 = val.node0;
    node1 = val.node1;
    adjacent_triangle = val.adjacent_triangle;
}
