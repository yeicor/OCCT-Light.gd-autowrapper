#include "OcctlMeshTrianglePlaneComponentsView.h"

#include "OcctlNodeId.h"

Array OcctlMeshTrianglePlaneComponentsView::get_components() const { return components; }
void OcctlMeshTrianglePlaneComponentsView::set_components(Array val) { components = val; }

int OcctlMeshTrianglePlaneComponentsView::get_component_count() const { return component_count; }
void OcctlMeshTrianglePlaneComponentsView::set_component_count(int val) { component_count = val; }

int OcctlMeshTrianglePlaneComponentsView::get_triangle_count() const { return triangle_count; }
void OcctlMeshTrianglePlaneComponentsView::set_triangle_count(int val) { triangle_count = val; }

int64_t OcctlMeshTrianglePlaneComponentsView::get_root() const { return root; }
void OcctlMeshTrianglePlaneComponentsView::set_root(int64_t val) { root = val; }

void OcctlMeshTrianglePlaneComponentsView::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_components"), &OcctlMeshTrianglePlaneComponentsView::get_components);
    godot::ClassDB::bind_method(godot::D_METHOD("set_components", "val"), &OcctlMeshTrianglePlaneComponentsView::set_components);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "components"), "set_components", "get_components");
    godot::ClassDB::bind_method(godot::D_METHOD("get_component_count"), &OcctlMeshTrianglePlaneComponentsView::get_component_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_component_count", "val"), &OcctlMeshTrianglePlaneComponentsView::set_component_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "component_count"), "set_component_count", "get_component_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_triangle_count"), &OcctlMeshTrianglePlaneComponentsView::get_triangle_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_triangle_count", "val"), &OcctlMeshTrianglePlaneComponentsView::set_triangle_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "triangle_count"), "set_triangle_count", "get_triangle_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_root"), &OcctlMeshTrianglePlaneComponentsView::get_root);
    godot::ClassDB::bind_method(godot::D_METHOD("set_root", "val"), &OcctlMeshTrianglePlaneComponentsView::set_root);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "root"), "set_root", "get_root");
}

occtl_mesh_triangle_plane_components_view_t OcctlMeshTrianglePlaneComponentsView::to_c() const {
    occtl_mesh_triangle_plane_components_view_t result = {};
    _cache_components.resize(components.size());
    for (int _i = 0; _i < components.size(); _i++) {
        Ref<OcctlMeshTrianglePlaneComponent> _item = components[_i];
        if (_item.is_valid()) _cache_components[_i] = _item->to_c();
        else _cache_components[_i] = {};
    }
    result.components = _cache_components.data();
    result.component_count = component_count;
    result.triangle_count = triangle_count;
    result.root.bits = static_cast<uint64_t>(root);
    return result;
}

Ref<OcctlMeshTrianglePlaneComponentsView> OcctlMeshTrianglePlaneComponentsView::from_c(const occtl_mesh_triangle_plane_components_view_t& val) {
    Ref<OcctlMeshTrianglePlaneComponentsView> r;
    r.instantiate();
    // array field components is not populated from C
    r->component_count = val.component_count;
    r->triangle_count = val.triangle_count;
    r->root = static_cast<int64_t>(val.root.bits);
    return r;
}

void OcctlMeshTrianglePlaneComponentsView::copy_from_c(const occtl_mesh_triangle_plane_components_view_t& val) {
    // array field components is not populated from C
    component_count = val.component_count;
    triangle_count = val.triangle_count;
    root = static_cast<int64_t>(val.root.bits);
}
