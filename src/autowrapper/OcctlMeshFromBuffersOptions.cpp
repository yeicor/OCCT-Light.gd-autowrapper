#include "OcctlMeshFromBuffersOptions.h"


int OcctlMeshFromBuffersOptions::get_struct_version() const { return struct_version; }
void OcctlMeshFromBuffersOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlMeshFromBuffersOptions::get_p_next() const { return p_next; }
void OcctlMeshFromBuffersOptions::set_p_next(int64_t val) { p_next = val; }

PackedFloat64Array OcctlMeshFromBuffersOptions::get_nodes() const { return nodes; }
void OcctlMeshFromBuffersOptions::set_nodes(PackedFloat64Array val) { nodes = val; }

int OcctlMeshFromBuffersOptions::get_node_count() const { return node_count; }
void OcctlMeshFromBuffersOptions::set_node_count(int val) { node_count = val; }

PackedInt32Array OcctlMeshFromBuffersOptions::get_triangles() const { return triangles; }
void OcctlMeshFromBuffersOptions::set_triangles(PackedInt32Array val) { triangles = val; }

int OcctlMeshFromBuffersOptions::get_triangle_count() const { return triangle_count; }
void OcctlMeshFromBuffersOptions::set_triangle_count(int val) { triangle_count = val; }

double OcctlMeshFromBuffersOptions::get_deflection() const { return deflection; }
void OcctlMeshFromBuffersOptions::set_deflection(double val) { deflection = val; }

void OcctlMeshFromBuffersOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlMeshFromBuffersOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlMeshFromBuffersOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlMeshFromBuffersOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlMeshFromBuffersOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_nodes"), &OcctlMeshFromBuffersOptions::get_nodes);
    godot::ClassDB::bind_method(godot::D_METHOD("set_nodes", "val"), &OcctlMeshFromBuffersOptions::set_nodes);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "nodes"), "set_nodes", "get_nodes");
    godot::ClassDB::bind_method(godot::D_METHOD("get_node_count"), &OcctlMeshFromBuffersOptions::get_node_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_node_count", "val"), &OcctlMeshFromBuffersOptions::set_node_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "node_count"), "set_node_count", "get_node_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_triangles"), &OcctlMeshFromBuffersOptions::get_triangles);
    godot::ClassDB::bind_method(godot::D_METHOD("set_triangles", "val"), &OcctlMeshFromBuffersOptions::set_triangles);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "triangles"), "set_triangles", "get_triangles");
    godot::ClassDB::bind_method(godot::D_METHOD("get_triangle_count"), &OcctlMeshFromBuffersOptions::get_triangle_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_triangle_count", "val"), &OcctlMeshFromBuffersOptions::set_triangle_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "triangle_count"), "set_triangle_count", "get_triangle_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_deflection"), &OcctlMeshFromBuffersOptions::get_deflection);
    godot::ClassDB::bind_method(godot::D_METHOD("set_deflection", "val"), &OcctlMeshFromBuffersOptions::set_deflection);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "deflection"), "set_deflection", "get_deflection");
}

occtl_mesh_from_buffers_options_t OcctlMeshFromBuffersOptions::to_c() const {
    occtl_mesh_from_buffers_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.nodes = nodes.ptr();
    result.node_count = node_count;
    result.triangles = reinterpret_cast<const uint32_t*>(triangles.ptr());
    result.triangle_count = triangle_count;
    result.deflection = deflection;
    return result;
}

Ref<OcctlMeshFromBuffersOptions> OcctlMeshFromBuffersOptions::from_c(const occtl_mesh_from_buffers_options_t& val) {
    Ref<OcctlMeshFromBuffersOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field nodes is not populated from C
    r->node_count = val.node_count;
    // array field triangles is not populated from C
    r->triangle_count = val.triangle_count;
    r->deflection = val.deflection;
    return r;
}

void OcctlMeshFromBuffersOptions::copy_from_c(const occtl_mesh_from_buffers_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field nodes is not populated from C
    node_count = val.node_count;
    // array field triangles is not populated from C
    triangle_count = val.triangle_count;
    deflection = val.deflection;
}
