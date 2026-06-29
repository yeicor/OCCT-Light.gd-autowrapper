#include "OcctlMeshTriangleComponentBoundaryChain.h"


int OcctlMeshTriangleComponentBoundaryChain::get_first_edge() const { return first_edge; }
void OcctlMeshTriangleComponentBoundaryChain::set_first_edge(int val) { first_edge = val; }

int OcctlMeshTriangleComponentBoundaryChain::get_edge_count() const { return edge_count; }
void OcctlMeshTriangleComponentBoundaryChain::set_edge_count(int val) { edge_count = val; }

int OcctlMeshTriangleComponentBoundaryChain::get_is_closed() const { return is_closed; }
void OcctlMeshTriangleComponentBoundaryChain::set_is_closed(int val) { is_closed = val; }

void OcctlMeshTriangleComponentBoundaryChain::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_first_edge"), &OcctlMeshTriangleComponentBoundaryChain::get_first_edge);
    godot::ClassDB::bind_method(godot::D_METHOD("set_first_edge", "val"), &OcctlMeshTriangleComponentBoundaryChain::set_first_edge);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "first_edge"), "set_first_edge", "get_first_edge");
    godot::ClassDB::bind_method(godot::D_METHOD("get_edge_count"), &OcctlMeshTriangleComponentBoundaryChain::get_edge_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_edge_count", "val"), &OcctlMeshTriangleComponentBoundaryChain::set_edge_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "edge_count"), "set_edge_count", "get_edge_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_closed"), &OcctlMeshTriangleComponentBoundaryChain::get_is_closed);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_closed", "val"), &OcctlMeshTriangleComponentBoundaryChain::set_is_closed);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_closed"), "set_is_closed", "get_is_closed");
}

occtl_mesh_triangle_component_boundary_chain_t OcctlMeshTriangleComponentBoundaryChain::to_c() const {
    occtl_mesh_triangle_component_boundary_chain_t result = {};
    result.first_edge = first_edge;
    result.edge_count = edge_count;
    result.is_closed = is_closed;
    return result;
}

Ref<OcctlMeshTriangleComponentBoundaryChain> OcctlMeshTriangleComponentBoundaryChain::from_c(const occtl_mesh_triangle_component_boundary_chain_t& val) {
    Ref<OcctlMeshTriangleComponentBoundaryChain> r;
    r.instantiate();
    r->first_edge = val.first_edge;
    r->edge_count = val.edge_count;
    r->is_closed = val.is_closed;
    return r;
}

void OcctlMeshTriangleComponentBoundaryChain::copy_from_c(const occtl_mesh_triangle_component_boundary_chain_t& val) {
    first_edge = val.first_edge;
    edge_count = val.edge_count;
    is_closed = val.is_closed;
}
