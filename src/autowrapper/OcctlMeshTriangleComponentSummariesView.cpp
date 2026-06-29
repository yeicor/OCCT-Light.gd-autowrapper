#include "OcctlMeshTriangleComponentSummariesView.h"

#include "OcctlNodeId.h"

Array OcctlMeshTriangleComponentSummariesView::get_summaries() const { return summaries; }
void OcctlMeshTriangleComponentSummariesView::set_summaries(Array val) { summaries = val; }

int OcctlMeshTriangleComponentSummariesView::get_component_count() const { return component_count; }
void OcctlMeshTriangleComponentSummariesView::set_component_count(int val) { component_count = val; }

int OcctlMeshTriangleComponentSummariesView::get_triangle_count() const { return triangle_count; }
void OcctlMeshTriangleComponentSummariesView::set_triangle_count(int val) { triangle_count = val; }

int64_t OcctlMeshTriangleComponentSummariesView::get_root() const { return root; }
void OcctlMeshTriangleComponentSummariesView::set_root(int64_t val) { root = val; }

void OcctlMeshTriangleComponentSummariesView::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_summaries"), &OcctlMeshTriangleComponentSummariesView::get_summaries);
    godot::ClassDB::bind_method(godot::D_METHOD("set_summaries", "val"), &OcctlMeshTriangleComponentSummariesView::set_summaries);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "summaries"), "set_summaries", "get_summaries");
    godot::ClassDB::bind_method(godot::D_METHOD("get_component_count"), &OcctlMeshTriangleComponentSummariesView::get_component_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_component_count", "val"), &OcctlMeshTriangleComponentSummariesView::set_component_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "component_count"), "set_component_count", "get_component_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_triangle_count"), &OcctlMeshTriangleComponentSummariesView::get_triangle_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_triangle_count", "val"), &OcctlMeshTriangleComponentSummariesView::set_triangle_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "triangle_count"), "set_triangle_count", "get_triangle_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_root"), &OcctlMeshTriangleComponentSummariesView::get_root);
    godot::ClassDB::bind_method(godot::D_METHOD("set_root", "val"), &OcctlMeshTriangleComponentSummariesView::set_root);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "root"), "set_root", "get_root");
}

occtl_mesh_triangle_component_summaries_view_t OcctlMeshTriangleComponentSummariesView::to_c() const {
    occtl_mesh_triangle_component_summaries_view_t result = {};
    _cache_summaries.resize(summaries.size());
    for (int _i = 0; _i < summaries.size(); _i++) {
        Ref<OcctlMeshTriangleComponentSummary> _item = summaries[_i];
        if (_item.is_valid()) _cache_summaries[_i] = _item->to_c();
        else _cache_summaries[_i] = {};
    }
    result.summaries = _cache_summaries.data();
    result.component_count = component_count;
    result.triangle_count = triangle_count;
    result.root.bits = static_cast<uint64_t>(root);
    return result;
}

Ref<OcctlMeshTriangleComponentSummariesView> OcctlMeshTriangleComponentSummariesView::from_c(const occtl_mesh_triangle_component_summaries_view_t& val) {
    Ref<OcctlMeshTriangleComponentSummariesView> r;
    r.instantiate();
    // array field summaries is not populated from C
    r->component_count = val.component_count;
    r->triangle_count = val.triangle_count;
    r->root = static_cast<int64_t>(val.root.bits);
    return r;
}

void OcctlMeshTriangleComponentSummariesView::copy_from_c(const occtl_mesh_triangle_component_summaries_view_t& val) {
    // array field summaries is not populated from C
    component_count = val.component_count;
    triangle_count = val.triangle_count;
    root = static_cast<int64_t>(val.root.bits);
}
