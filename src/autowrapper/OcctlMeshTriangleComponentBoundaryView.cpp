#include "OcctlMeshTriangleComponentBoundaryView.h"

#include "OcctlNodeId.h"

Array OcctlMeshTriangleComponentBoundaryView::get_edges() const { return edges; }
void OcctlMeshTriangleComponentBoundaryView::set_edges(Array val) { edges = val; }

int OcctlMeshTriangleComponentBoundaryView::get_edge_count() const { return edge_count; }
void OcctlMeshTriangleComponentBoundaryView::set_edge_count(int val) { edge_count = val; }

int OcctlMeshTriangleComponentBoundaryView::get_component_id() const { return component_id; }
void OcctlMeshTriangleComponentBoundaryView::set_component_id(int val) { component_id = val; }

int64_t OcctlMeshTriangleComponentBoundaryView::get_root() const { return root; }
void OcctlMeshTriangleComponentBoundaryView::set_root(int64_t val) { root = val; }

void OcctlMeshTriangleComponentBoundaryView::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_edges"), &OcctlMeshTriangleComponentBoundaryView::get_edges);
    godot::ClassDB::bind_method(godot::D_METHOD("set_edges", "val"), &OcctlMeshTriangleComponentBoundaryView::set_edges);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "edges"), "set_edges", "get_edges");
    godot::ClassDB::bind_method(godot::D_METHOD("get_edge_count"), &OcctlMeshTriangleComponentBoundaryView::get_edge_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_edge_count", "val"), &OcctlMeshTriangleComponentBoundaryView::set_edge_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "edge_count"), "set_edge_count", "get_edge_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_component_id"), &OcctlMeshTriangleComponentBoundaryView::get_component_id);
    godot::ClassDB::bind_method(godot::D_METHOD("set_component_id", "val"), &OcctlMeshTriangleComponentBoundaryView::set_component_id);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "component_id"), "set_component_id", "get_component_id");
    godot::ClassDB::bind_method(godot::D_METHOD("get_root"), &OcctlMeshTriangleComponentBoundaryView::get_root);
    godot::ClassDB::bind_method(godot::D_METHOD("set_root", "val"), &OcctlMeshTriangleComponentBoundaryView::set_root);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "root"), "set_root", "get_root");
}

occtl_mesh_triangle_component_boundary_view_t OcctlMeshTriangleComponentBoundaryView::to_c() const {
    occtl_mesh_triangle_component_boundary_view_t result = {};
    _cache_edges.resize(edges.size());
    for (int _i = 0; _i < edges.size(); _i++) {
        Ref<OcctlMeshTriangleComponentBoundaryEdge> _item = edges[_i];
        if (_item.is_valid()) _cache_edges[_i] = _item->to_c();
        else _cache_edges[_i] = {};
    }
    result.edges = _cache_edges.data();
    result.edge_count = edge_count;
    result.component_id = component_id;
    result.root.bits = static_cast<uint64_t>(root);
    return result;
}

Ref<OcctlMeshTriangleComponentBoundaryView> OcctlMeshTriangleComponentBoundaryView::from_c(const occtl_mesh_triangle_component_boundary_view_t& val) {
    Ref<OcctlMeshTriangleComponentBoundaryView> r;
    r.instantiate();
    // array field edges is not populated from C
    r->edge_count = val.edge_count;
    r->component_id = val.component_id;
    r->root = static_cast<int64_t>(val.root.bits);
    return r;
}

void OcctlMeshTriangleComponentBoundaryView::copy_from_c(const occtl_mesh_triangle_component_boundary_view_t& val) {
    // array field edges is not populated from C
    edge_count = val.edge_count;
    component_id = val.component_id;
    root = static_cast<int64_t>(val.root.bits);
}
