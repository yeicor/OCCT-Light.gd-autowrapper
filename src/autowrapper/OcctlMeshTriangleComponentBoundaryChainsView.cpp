#include "OcctlMeshTriangleComponentBoundaryChainsView.h"

#include "OcctlNodeId.h"

Array OcctlMeshTriangleComponentBoundaryChainsView::get_edges() const { return edges; }
void OcctlMeshTriangleComponentBoundaryChainsView::set_edges(Array val) { edges = val; }

int OcctlMeshTriangleComponentBoundaryChainsView::get_edge_count() const { return edge_count; }
void OcctlMeshTriangleComponentBoundaryChainsView::set_edge_count(int val) { edge_count = val; }

Array OcctlMeshTriangleComponentBoundaryChainsView::get_chains() const { return chains; }
void OcctlMeshTriangleComponentBoundaryChainsView::set_chains(Array val) { chains = val; }

int OcctlMeshTriangleComponentBoundaryChainsView::get_chain_count() const { return chain_count; }
void OcctlMeshTriangleComponentBoundaryChainsView::set_chain_count(int val) { chain_count = val; }

int OcctlMeshTriangleComponentBoundaryChainsView::get_component_id() const { return component_id; }
void OcctlMeshTriangleComponentBoundaryChainsView::set_component_id(int val) { component_id = val; }

int64_t OcctlMeshTriangleComponentBoundaryChainsView::get_root() const { return root; }
void OcctlMeshTriangleComponentBoundaryChainsView::set_root(int64_t val) { root = val; }

void OcctlMeshTriangleComponentBoundaryChainsView::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_edges"), &OcctlMeshTriangleComponentBoundaryChainsView::get_edges);
    godot::ClassDB::bind_method(godot::D_METHOD("set_edges", "val"), &OcctlMeshTriangleComponentBoundaryChainsView::set_edges);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "edges"), "set_edges", "get_edges");
    godot::ClassDB::bind_method(godot::D_METHOD("get_edge_count"), &OcctlMeshTriangleComponentBoundaryChainsView::get_edge_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_edge_count", "val"), &OcctlMeshTriangleComponentBoundaryChainsView::set_edge_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "edge_count"), "set_edge_count", "get_edge_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_chains"), &OcctlMeshTriangleComponentBoundaryChainsView::get_chains);
    godot::ClassDB::bind_method(godot::D_METHOD("set_chains", "val"), &OcctlMeshTriangleComponentBoundaryChainsView::set_chains);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "chains"), "set_chains", "get_chains");
    godot::ClassDB::bind_method(godot::D_METHOD("get_chain_count"), &OcctlMeshTriangleComponentBoundaryChainsView::get_chain_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_chain_count", "val"), &OcctlMeshTriangleComponentBoundaryChainsView::set_chain_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "chain_count"), "set_chain_count", "get_chain_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_component_id"), &OcctlMeshTriangleComponentBoundaryChainsView::get_component_id);
    godot::ClassDB::bind_method(godot::D_METHOD("set_component_id", "val"), &OcctlMeshTriangleComponentBoundaryChainsView::set_component_id);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "component_id"), "set_component_id", "get_component_id");
    godot::ClassDB::bind_method(godot::D_METHOD("get_root"), &OcctlMeshTriangleComponentBoundaryChainsView::get_root);
    godot::ClassDB::bind_method(godot::D_METHOD("set_root", "val"), &OcctlMeshTriangleComponentBoundaryChainsView::set_root);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "root"), "set_root", "get_root");
}

occtl_mesh_triangle_component_boundary_chains_view_t OcctlMeshTriangleComponentBoundaryChainsView::to_c() const {
    occtl_mesh_triangle_component_boundary_chains_view_t result = {};
    _cache_edges.resize(edges.size());
    for (int _i = 0; _i < edges.size(); _i++) {
        Ref<OcctlMeshTriangleComponentBoundaryEdge> _item = edges[_i];
        if (_item.is_valid()) _cache_edges[_i] = _item->to_c();
        else _cache_edges[_i] = {};
    }
    result.edges = _cache_edges.data();
    result.edge_count = edge_count;
    _cache_chains.resize(chains.size());
    for (int _i = 0; _i < chains.size(); _i++) {
        Ref<OcctlMeshTriangleComponentBoundaryChain> _item = chains[_i];
        if (_item.is_valid()) _cache_chains[_i] = _item->to_c();
        else _cache_chains[_i] = {};
    }
    result.chains = _cache_chains.data();
    result.chain_count = chain_count;
    result.component_id = component_id;
    result.root.bits = static_cast<uint64_t>(root);
    return result;
}

Ref<OcctlMeshTriangleComponentBoundaryChainsView> OcctlMeshTriangleComponentBoundaryChainsView::from_c(const occtl_mesh_triangle_component_boundary_chains_view_t& val) {
    Ref<OcctlMeshTriangleComponentBoundaryChainsView> r;
    r.instantiate();
    // array field edges is not populated from C
    r->edge_count = val.edge_count;
    // array field chains is not populated from C
    r->chain_count = val.chain_count;
    r->component_id = val.component_id;
    r->root = static_cast<int64_t>(val.root.bits);
    return r;
}

void OcctlMeshTriangleComponentBoundaryChainsView::copy_from_c(const occtl_mesh_triangle_component_boundary_chains_view_t& val) {
    // array field edges is not populated from C
    edge_count = val.edge_count;
    // array field chains is not populated from C
    chain_count = val.chain_count;
    component_id = val.component_id;
    root = static_cast<int64_t>(val.root.bits);
}
