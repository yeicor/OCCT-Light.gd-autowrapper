#include "OcctlMeshTriangleComponentTrianglesView.h"

#include "OcctlNodeId.h"

PackedInt32Array OcctlMeshTriangleComponentTrianglesView::get_triangles() const { return triangles; }
void OcctlMeshTriangleComponentTrianglesView::set_triangles(PackedInt32Array val) { triangles = val; }

int OcctlMeshTriangleComponentTrianglesView::get_triangle_count() const { return triangle_count; }
void OcctlMeshTriangleComponentTrianglesView::set_triangle_count(int val) { triangle_count = val; }

int OcctlMeshTriangleComponentTrianglesView::get_component_id() const { return component_id; }
void OcctlMeshTriangleComponentTrianglesView::set_component_id(int val) { component_id = val; }

int64_t OcctlMeshTriangleComponentTrianglesView::get_root() const { return root; }
void OcctlMeshTriangleComponentTrianglesView::set_root(int64_t val) { root = val; }

void OcctlMeshTriangleComponentTrianglesView::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_triangles"), &OcctlMeshTriangleComponentTrianglesView::get_triangles);
    godot::ClassDB::bind_method(godot::D_METHOD("set_triangles", "val"), &OcctlMeshTriangleComponentTrianglesView::set_triangles);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "triangles"), "set_triangles", "get_triangles");
    godot::ClassDB::bind_method(godot::D_METHOD("get_triangle_count"), &OcctlMeshTriangleComponentTrianglesView::get_triangle_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_triangle_count", "val"), &OcctlMeshTriangleComponentTrianglesView::set_triangle_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "triangle_count"), "set_triangle_count", "get_triangle_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_component_id"), &OcctlMeshTriangleComponentTrianglesView::get_component_id);
    godot::ClassDB::bind_method(godot::D_METHOD("set_component_id", "val"), &OcctlMeshTriangleComponentTrianglesView::set_component_id);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "component_id"), "set_component_id", "get_component_id");
    godot::ClassDB::bind_method(godot::D_METHOD("get_root"), &OcctlMeshTriangleComponentTrianglesView::get_root);
    godot::ClassDB::bind_method(godot::D_METHOD("set_root", "val"), &OcctlMeshTriangleComponentTrianglesView::set_root);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "root"), "set_root", "get_root");
}

occtl_mesh_triangle_component_triangles_view_t OcctlMeshTriangleComponentTrianglesView::to_c() const {
    occtl_mesh_triangle_component_triangles_view_t result = {};
    result.triangles = reinterpret_cast<const uint32_t*>(triangles.ptr());
    result.triangle_count = triangle_count;
    result.component_id = component_id;
    result.root.bits = static_cast<uint64_t>(root);
    return result;
}

Ref<OcctlMeshTriangleComponentTrianglesView> OcctlMeshTriangleComponentTrianglesView::from_c(const occtl_mesh_triangle_component_triangles_view_t& val) {
    Ref<OcctlMeshTriangleComponentTrianglesView> r;
    r.instantiate();
    // array field triangles is not populated from C
    r->triangle_count = val.triangle_count;
    r->component_id = val.component_id;
    r->root = static_cast<int64_t>(val.root.bits);
    return r;
}

void OcctlMeshTriangleComponentTrianglesView::copy_from_c(const occtl_mesh_triangle_component_triangles_view_t& val) {
    // array field triangles is not populated from C
    triangle_count = val.triangle_count;
    component_id = val.component_id;
    root = static_cast<int64_t>(val.root.bits);
}
