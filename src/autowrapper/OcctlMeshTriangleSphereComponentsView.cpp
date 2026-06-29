#include "OcctlMeshTriangleSphereComponentsView.h"

#include "OcctlNodeId.h"

Array OcctlMeshTriangleSphereComponentsView::get_components() const { return components; }
void OcctlMeshTriangleSphereComponentsView::set_components(Array val) { components = val; }

int OcctlMeshTriangleSphereComponentsView::get_component_count() const { return component_count; }
void OcctlMeshTriangleSphereComponentsView::set_component_count(int val) { component_count = val; }

int OcctlMeshTriangleSphereComponentsView::get_triangle_count() const { return triangle_count; }
void OcctlMeshTriangleSphereComponentsView::set_triangle_count(int val) { triangle_count = val; }

int64_t OcctlMeshTriangleSphereComponentsView::get_root() const { return root; }
void OcctlMeshTriangleSphereComponentsView::set_root(int64_t val) { root = val; }

void OcctlMeshTriangleSphereComponentsView::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_components"), &OcctlMeshTriangleSphereComponentsView::get_components);
    godot::ClassDB::bind_method(godot::D_METHOD("set_components", "val"), &OcctlMeshTriangleSphereComponentsView::set_components);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "components"), "set_components", "get_components");
    godot::ClassDB::bind_method(godot::D_METHOD("get_component_count"), &OcctlMeshTriangleSphereComponentsView::get_component_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_component_count", "val"), &OcctlMeshTriangleSphereComponentsView::set_component_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "component_count"), "set_component_count", "get_component_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_triangle_count"), &OcctlMeshTriangleSphereComponentsView::get_triangle_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_triangle_count", "val"), &OcctlMeshTriangleSphereComponentsView::set_triangle_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "triangle_count"), "set_triangle_count", "get_triangle_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_root"), &OcctlMeshTriangleSphereComponentsView::get_root);
    godot::ClassDB::bind_method(godot::D_METHOD("set_root", "val"), &OcctlMeshTriangleSphereComponentsView::set_root);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "root"), "set_root", "get_root");
}

occtl_mesh_triangle_sphere_components_view_t OcctlMeshTriangleSphereComponentsView::to_c() const {
    occtl_mesh_triangle_sphere_components_view_t result = {};
    _cache_components.resize(components.size());
    for (int _i = 0; _i < components.size(); _i++) {
        Ref<OcctlMeshTriangleSphereComponent> _item = components[_i];
        if (_item.is_valid()) _cache_components[_i] = _item->to_c();
        else _cache_components[_i] = {};
    }
    result.components = _cache_components.data();
    result.component_count = component_count;
    result.triangle_count = triangle_count;
    result.root.bits = static_cast<uint64_t>(root);
    return result;
}

Ref<OcctlMeshTriangleSphereComponentsView> OcctlMeshTriangleSphereComponentsView::from_c(const occtl_mesh_triangle_sphere_components_view_t& val) {
    Ref<OcctlMeshTriangleSphereComponentsView> r;
    r.instantiate();
    // array field components is not populated from C
    r->component_count = val.component_count;
    r->triangle_count = val.triangle_count;
    r->root = static_cast<int64_t>(val.root.bits);
    return r;
}

void OcctlMeshTriangleSphereComponentsView::copy_from_c(const occtl_mesh_triangle_sphere_components_view_t& val) {
    // array field components is not populated from C
    component_count = val.component_count;
    triangle_count = val.triangle_count;
    root = static_cast<int64_t>(val.root.bits);
}
