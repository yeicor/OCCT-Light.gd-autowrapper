#include "OcctlMeshTriangleAnalysisView.h"

#include "OcctlNodeId.h"

PackedFloat64Array OcctlMeshTriangleAnalysisView::get_triangle_normals() const { return triangle_normals; }
void OcctlMeshTriangleAnalysisView::set_triangle_normals(PackedFloat64Array val) { triangle_normals = val; }

PackedInt32Array OcctlMeshTriangleAnalysisView::get_triangle_adjacency() const { return triangle_adjacency; }
void OcctlMeshTriangleAnalysisView::set_triangle_adjacency(PackedInt32Array val) { triangle_adjacency = val; }

int OcctlMeshTriangleAnalysisView::get_triangle_count() const { return triangle_count; }
void OcctlMeshTriangleAnalysisView::set_triangle_count(int val) { triangle_count = val; }

int OcctlMeshTriangleAnalysisView::get_face_count() const { return face_count; }
void OcctlMeshTriangleAnalysisView::set_face_count(int val) { face_count = val; }

int64_t OcctlMeshTriangleAnalysisView::get_root() const { return root; }
void OcctlMeshTriangleAnalysisView::set_root(int64_t val) { root = val; }

void OcctlMeshTriangleAnalysisView::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_triangle_normals"), &OcctlMeshTriangleAnalysisView::get_triangle_normals);
    godot::ClassDB::bind_method(godot::D_METHOD("set_triangle_normals", "val"), &OcctlMeshTriangleAnalysisView::set_triangle_normals);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "triangle_normals"), "set_triangle_normals", "get_triangle_normals");
    godot::ClassDB::bind_method(godot::D_METHOD("get_triangle_adjacency"), &OcctlMeshTriangleAnalysisView::get_triangle_adjacency);
    godot::ClassDB::bind_method(godot::D_METHOD("set_triangle_adjacency", "val"), &OcctlMeshTriangleAnalysisView::set_triangle_adjacency);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "triangle_adjacency"), "set_triangle_adjacency", "get_triangle_adjacency");
    godot::ClassDB::bind_method(godot::D_METHOD("get_triangle_count"), &OcctlMeshTriangleAnalysisView::get_triangle_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_triangle_count", "val"), &OcctlMeshTriangleAnalysisView::set_triangle_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "triangle_count"), "set_triangle_count", "get_triangle_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_face_count"), &OcctlMeshTriangleAnalysisView::get_face_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_face_count", "val"), &OcctlMeshTriangleAnalysisView::set_face_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "face_count"), "set_face_count", "get_face_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_root"), &OcctlMeshTriangleAnalysisView::get_root);
    godot::ClassDB::bind_method(godot::D_METHOD("set_root", "val"), &OcctlMeshTriangleAnalysisView::set_root);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "root"), "set_root", "get_root");
}

occtl_mesh_triangle_analysis_view_t OcctlMeshTriangleAnalysisView::to_c() const {
    occtl_mesh_triangle_analysis_view_t result = {};
    result.triangle_normals = triangle_normals.ptr();
    result.triangle_adjacency = reinterpret_cast<const uint32_t*>(triangle_adjacency.ptr());
    result.triangle_count = triangle_count;
    result.face_count = face_count;
    result.root.bits = static_cast<uint64_t>(root);
    return result;
}

Ref<OcctlMeshTriangleAnalysisView> OcctlMeshTriangleAnalysisView::from_c(const occtl_mesh_triangle_analysis_view_t& val) {
    Ref<OcctlMeshTriangleAnalysisView> r;
    r.instantiate();
    // array field triangle_normals is not populated from C
    // array field triangle_adjacency is not populated from C
    r->triangle_count = val.triangle_count;
    r->face_count = val.face_count;
    r->root = static_cast<int64_t>(val.root.bits);
    return r;
}

void OcctlMeshTriangleAnalysisView::copy_from_c(const occtl_mesh_triangle_analysis_view_t& val) {
    // array field triangle_normals is not populated from C
    // array field triangle_adjacency is not populated from C
    triangle_count = val.triangle_count;
    face_count = val.face_count;
    root = static_cast<int64_t>(val.root.bits);
}
