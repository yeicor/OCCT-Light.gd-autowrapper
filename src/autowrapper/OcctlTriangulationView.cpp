#include "OcctlTriangulationView.h"

#include "OcctlUid.h"

PackedFloat64Array OcctlTriangulationView::get_nodes() const { return nodes; }
void OcctlTriangulationView::set_nodes(PackedFloat64Array val) { nodes = val; }

int OcctlTriangulationView::get_node_count() const { return node_count; }
void OcctlTriangulationView::set_node_count(int val) { node_count = val; }

PackedFloat64Array OcctlTriangulationView::get_normals() const { return normals; }
void OcctlTriangulationView::set_normals(PackedFloat64Array val) { normals = val; }

PackedFloat64Array OcctlTriangulationView::get_uvs() const { return uvs; }
void OcctlTriangulationView::set_uvs(PackedFloat64Array val) { uvs = val; }

PackedInt32Array OcctlTriangulationView::get_triangles() const { return triangles; }
void OcctlTriangulationView::set_triangles(PackedInt32Array val) { triangles = val; }

int OcctlTriangulationView::get_triangle_count() const { return triangle_count; }
void OcctlTriangulationView::set_triangle_count(int val) { triangle_count = val; }

double OcctlTriangulationView::get_deflection() const { return deflection; }
void OcctlTriangulationView::set_deflection(double val) { deflection = val; }

int64_t OcctlTriangulationView::get_source_uid() const { return source_uid; }
void OcctlTriangulationView::set_source_uid(int64_t val) { source_uid = val; }

void OcctlTriangulationView::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_nodes"), &OcctlTriangulationView::get_nodes);
    godot::ClassDB::bind_method(godot::D_METHOD("set_nodes", "val"), &OcctlTriangulationView::set_nodes);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "nodes"), "set_nodes", "get_nodes");
    godot::ClassDB::bind_method(godot::D_METHOD("get_node_count"), &OcctlTriangulationView::get_node_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_node_count", "val"), &OcctlTriangulationView::set_node_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "node_count"), "set_node_count", "get_node_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_normals"), &OcctlTriangulationView::get_normals);
    godot::ClassDB::bind_method(godot::D_METHOD("set_normals", "val"), &OcctlTriangulationView::set_normals);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "normals"), "set_normals", "get_normals");
    godot::ClassDB::bind_method(godot::D_METHOD("get_uvs"), &OcctlTriangulationView::get_uvs);
    godot::ClassDB::bind_method(godot::D_METHOD("set_uvs", "val"), &OcctlTriangulationView::set_uvs);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "uvs"), "set_uvs", "get_uvs");
    godot::ClassDB::bind_method(godot::D_METHOD("get_triangles"), &OcctlTriangulationView::get_triangles);
    godot::ClassDB::bind_method(godot::D_METHOD("set_triangles", "val"), &OcctlTriangulationView::set_triangles);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "triangles"), "set_triangles", "get_triangles");
    godot::ClassDB::bind_method(godot::D_METHOD("get_triangle_count"), &OcctlTriangulationView::get_triangle_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_triangle_count", "val"), &OcctlTriangulationView::set_triangle_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "triangle_count"), "set_triangle_count", "get_triangle_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_deflection"), &OcctlTriangulationView::get_deflection);
    godot::ClassDB::bind_method(godot::D_METHOD("set_deflection", "val"), &OcctlTriangulationView::set_deflection);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "deflection"), "set_deflection", "get_deflection");
    godot::ClassDB::bind_method(godot::D_METHOD("get_source_uid"), &OcctlTriangulationView::get_source_uid);
    godot::ClassDB::bind_method(godot::D_METHOD("set_source_uid", "val"), &OcctlTriangulationView::set_source_uid);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "source_uid"), "set_source_uid", "get_source_uid");
}

occtl_triangulation_view_t OcctlTriangulationView::to_c() const {
    occtl_triangulation_view_t result = {};
    result.nodes = nodes.ptr();
    result.node_count = node_count;
    result.normals = normals.ptr();
    result.uvs = uvs.ptr();
    result.triangles = reinterpret_cast<const uint32_t*>(triangles.ptr());
    result.triangle_count = triangle_count;
    result.deflection = deflection;
    result.source_uid.bits = static_cast<uint64_t>(source_uid);
    return result;
}

Ref<OcctlTriangulationView> OcctlTriangulationView::from_c(const occtl_triangulation_view_t& val) {
    Ref<OcctlTriangulationView> r;
    r.instantiate();
    // array field nodes is not populated from C
    r->node_count = val.node_count;
    // array field normals is not populated from C
    // array field uvs is not populated from C
    // array field triangles is not populated from C
    r->triangle_count = val.triangle_count;
    r->deflection = val.deflection;
    r->source_uid = static_cast<int64_t>(val.source_uid.bits);
    return r;
}

void OcctlTriangulationView::copy_from_c(const occtl_triangulation_view_t& val) {
    // array field nodes is not populated from C
    node_count = val.node_count;
    // array field normals is not populated from C
    // array field uvs is not populated from C
    // array field triangles is not populated from C
    triangle_count = val.triangle_count;
    deflection = val.deflection;
    source_uid = static_cast<int64_t>(val.source_uid.bits);
}
