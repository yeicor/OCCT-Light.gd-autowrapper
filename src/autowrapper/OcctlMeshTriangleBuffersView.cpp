#include "OcctlMeshTriangleBuffersView.h"

#include "OcctlNodeId.h"

PackedFloat64Array OcctlMeshTriangleBuffersView::get_nodes() const { return nodes; }
void OcctlMeshTriangleBuffersView::set_nodes(PackedFloat64Array val) { nodes = val; }

int OcctlMeshTriangleBuffersView::get_node_count() const { return node_count; }
void OcctlMeshTriangleBuffersView::set_node_count(int val) { node_count = val; }

PackedInt32Array OcctlMeshTriangleBuffersView::get_triangles() const { return triangles; }
void OcctlMeshTriangleBuffersView::set_triangles(PackedInt32Array val) { triangles = val; }

int OcctlMeshTriangleBuffersView::get_triangle_count() const { return triangle_count; }
void OcctlMeshTriangleBuffersView::set_triangle_count(int val) { triangle_count = val; }

int OcctlMeshTriangleBuffersView::get_face_count() const { return face_count; }
void OcctlMeshTriangleBuffersView::set_face_count(int val) { face_count = val; }

int64_t OcctlMeshTriangleBuffersView::get_root() const { return root; }
void OcctlMeshTriangleBuffersView::set_root(int64_t val) { root = val; }

void OcctlMeshTriangleBuffersView::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_nodes"), &OcctlMeshTriangleBuffersView::get_nodes);
    godot::ClassDB::bind_method(godot::D_METHOD("set_nodes", "val"), &OcctlMeshTriangleBuffersView::set_nodes);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "nodes"), "set_nodes", "get_nodes");
    godot::ClassDB::bind_method(godot::D_METHOD("get_node_count"), &OcctlMeshTriangleBuffersView::get_node_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_node_count", "val"), &OcctlMeshTriangleBuffersView::set_node_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "node_count"), "set_node_count", "get_node_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_triangles"), &OcctlMeshTriangleBuffersView::get_triangles);
    godot::ClassDB::bind_method(godot::D_METHOD("set_triangles", "val"), &OcctlMeshTriangleBuffersView::set_triangles);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "triangles"), "set_triangles", "get_triangles");
    godot::ClassDB::bind_method(godot::D_METHOD("get_triangle_count"), &OcctlMeshTriangleBuffersView::get_triangle_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_triangle_count", "val"), &OcctlMeshTriangleBuffersView::set_triangle_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "triangle_count"), "set_triangle_count", "get_triangle_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_face_count"), &OcctlMeshTriangleBuffersView::get_face_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_face_count", "val"), &OcctlMeshTriangleBuffersView::set_face_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "face_count"), "set_face_count", "get_face_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_root"), &OcctlMeshTriangleBuffersView::get_root);
    godot::ClassDB::bind_method(godot::D_METHOD("set_root", "val"), &OcctlMeshTriangleBuffersView::set_root);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "root"), "set_root", "get_root");
}

occtl_mesh_triangle_buffers_view_t OcctlMeshTriangleBuffersView::to_c() const {
    occtl_mesh_triangle_buffers_view_t result = {};
    result.nodes = nodes.ptr();
    result.node_count = node_count;
    result.triangles = reinterpret_cast<const uint32_t*>(triangles.ptr());
    result.triangle_count = triangle_count;
    result.face_count = face_count;
    result.root.bits = static_cast<uint64_t>(root);
    return result;
}

Ref<OcctlMeshTriangleBuffersView> OcctlMeshTriangleBuffersView::from_c(const occtl_mesh_triangle_buffers_view_t& val) {
    Ref<OcctlMeshTriangleBuffersView> r;
    r.instantiate();
    // array field nodes is not populated from C
    r->node_count = val.node_count;
    // array field triangles is not populated from C
    r->triangle_count = val.triangle_count;
    r->face_count = val.face_count;
    r->root = static_cast<int64_t>(val.root.bits);
    return r;
}

void OcctlMeshTriangleBuffersView::copy_from_c(const occtl_mesh_triangle_buffers_view_t& val) {
    // array field nodes is not populated from C
    node_count = val.node_count;
    // array field triangles is not populated from C
    triangle_count = val.triangle_count;
    face_count = val.face_count;
    root = static_cast<int64_t>(val.root.bits);
}
