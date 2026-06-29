#include "OcctlMeshTriangleComponentsView.h"

#include "OcctlNodeId.h"

PackedInt32Array OcctlMeshTriangleComponentsView::get_triangle_component_ids() const { return triangle_component_ids; }
void OcctlMeshTriangleComponentsView::set_triangle_component_ids(PackedInt32Array val) { triangle_component_ids = val; }

int OcctlMeshTriangleComponentsView::get_triangle_count() const { return triangle_count; }
void OcctlMeshTriangleComponentsView::set_triangle_count(int val) { triangle_count = val; }

PackedInt32Array OcctlMeshTriangleComponentsView::get_component_sizes() const { return component_sizes; }
void OcctlMeshTriangleComponentsView::set_component_sizes(PackedInt32Array val) { component_sizes = val; }

int OcctlMeshTriangleComponentsView::get_component_count() const { return component_count; }
void OcctlMeshTriangleComponentsView::set_component_count(int val) { component_count = val; }

int64_t OcctlMeshTriangleComponentsView::get_root() const { return root; }
void OcctlMeshTriangleComponentsView::set_root(int64_t val) { root = val; }

void OcctlMeshTriangleComponentsView::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_triangle_component_ids"), &OcctlMeshTriangleComponentsView::get_triangle_component_ids);
    godot::ClassDB::bind_method(godot::D_METHOD("set_triangle_component_ids", "val"), &OcctlMeshTriangleComponentsView::set_triangle_component_ids);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "triangle_component_ids"), "set_triangle_component_ids", "get_triangle_component_ids");
    godot::ClassDB::bind_method(godot::D_METHOD("get_triangle_count"), &OcctlMeshTriangleComponentsView::get_triangle_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_triangle_count", "val"), &OcctlMeshTriangleComponentsView::set_triangle_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "triangle_count"), "set_triangle_count", "get_triangle_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_component_sizes"), &OcctlMeshTriangleComponentsView::get_component_sizes);
    godot::ClassDB::bind_method(godot::D_METHOD("set_component_sizes", "val"), &OcctlMeshTriangleComponentsView::set_component_sizes);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "component_sizes"), "set_component_sizes", "get_component_sizes");
    godot::ClassDB::bind_method(godot::D_METHOD("get_component_count"), &OcctlMeshTriangleComponentsView::get_component_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_component_count", "val"), &OcctlMeshTriangleComponentsView::set_component_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "component_count"), "set_component_count", "get_component_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_root"), &OcctlMeshTriangleComponentsView::get_root);
    godot::ClassDB::bind_method(godot::D_METHOD("set_root", "val"), &OcctlMeshTriangleComponentsView::set_root);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "root"), "set_root", "get_root");
}

occtl_mesh_triangle_components_view_t OcctlMeshTriangleComponentsView::to_c() const {
    occtl_mesh_triangle_components_view_t result = {};
    result.triangle_component_ids = reinterpret_cast<const uint32_t*>(triangle_component_ids.ptr());
    result.triangle_count = triangle_count;
    result.component_sizes = reinterpret_cast<const uint32_t*>(component_sizes.ptr());
    result.component_count = component_count;
    result.root.bits = static_cast<uint64_t>(root);
    return result;
}

Ref<OcctlMeshTriangleComponentsView> OcctlMeshTriangleComponentsView::from_c(const occtl_mesh_triangle_components_view_t& val) {
    Ref<OcctlMeshTriangleComponentsView> r;
    r.instantiate();
    // array field triangle_component_ids is not populated from C
    r->triangle_count = val.triangle_count;
    // array field component_sizes is not populated from C
    r->component_count = val.component_count;
    r->root = static_cast<int64_t>(val.root.bits);
    return r;
}

void OcctlMeshTriangleComponentsView::copy_from_c(const occtl_mesh_triangle_components_view_t& val) {
    // array field triangle_component_ids is not populated from C
    triangle_count = val.triangle_count;
    // array field component_sizes is not populated from C
    component_count = val.component_count;
    root = static_cast<int64_t>(val.root.bits);
}
