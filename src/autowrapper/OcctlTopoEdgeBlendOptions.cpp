#include "OcctlTopoEdgeBlendOptions.h"

#include "OcctlNodeId.h"

int OcctlTopoEdgeBlendOptions::get_struct_version() const { return struct_version; }
void OcctlTopoEdgeBlendOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoEdgeBlendOptions::get_p_next() const { return p_next; }
void OcctlTopoEdgeBlendOptions::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlTopoEdgeBlendOptions::get_root() const { return root; }
void OcctlTopoEdgeBlendOptions::set_root(int64_t val) { root = val; }

PackedInt64Array OcctlTopoEdgeBlendOptions::get_edges() const { return edges; }
void OcctlTopoEdgeBlendOptions::set_edges(PackedInt64Array val) { edges = val; }

int OcctlTopoEdgeBlendOptions::get_edge_count() const { return edge_count; }
void OcctlTopoEdgeBlendOptions::set_edge_count(int val) { edge_count = val; }

double OcctlTopoEdgeBlendOptions::get_radius() const { return radius; }
void OcctlTopoEdgeBlendOptions::set_radius(double val) { radius = val; }

int OcctlTopoEdgeBlendOptions::get_chamfer_mode() const { return chamfer_mode; }
void OcctlTopoEdgeBlendOptions::set_chamfer_mode(int val) { chamfer_mode = val; }

double OcctlTopoEdgeBlendOptions::get_chamfer_dist1() const { return chamfer_dist1; }
void OcctlTopoEdgeBlendOptions::set_chamfer_dist1(double val) { chamfer_dist1 = val; }

double OcctlTopoEdgeBlendOptions::get_chamfer_dist2() const { return chamfer_dist2; }
void OcctlTopoEdgeBlendOptions::set_chamfer_dist2(double val) { chamfer_dist2 = val; }

void OcctlTopoEdgeBlendOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoEdgeBlendOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoEdgeBlendOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoEdgeBlendOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoEdgeBlendOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_root"), &OcctlTopoEdgeBlendOptions::get_root);
    godot::ClassDB::bind_method(godot::D_METHOD("set_root", "val"), &OcctlTopoEdgeBlendOptions::set_root);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "root"), "set_root", "get_root");
    godot::ClassDB::bind_method(godot::D_METHOD("get_edges"), &OcctlTopoEdgeBlendOptions::get_edges);
    godot::ClassDB::bind_method(godot::D_METHOD("set_edges", "val"), &OcctlTopoEdgeBlendOptions::set_edges);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "edges"), "set_edges", "get_edges");
    godot::ClassDB::bind_method(godot::D_METHOD("get_edge_count"), &OcctlTopoEdgeBlendOptions::get_edge_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_edge_count", "val"), &OcctlTopoEdgeBlendOptions::set_edge_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "edge_count"), "set_edge_count", "get_edge_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_radius"), &OcctlTopoEdgeBlendOptions::get_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_radius", "val"), &OcctlTopoEdgeBlendOptions::set_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "radius"), "set_radius", "get_radius");
    godot::ClassDB::bind_method(godot::D_METHOD("get_chamfer_mode"), &OcctlTopoEdgeBlendOptions::get_chamfer_mode);
    godot::ClassDB::bind_method(godot::D_METHOD("set_chamfer_mode", "val"), &OcctlTopoEdgeBlendOptions::set_chamfer_mode);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "chamfer_mode"), "set_chamfer_mode", "get_chamfer_mode");
    godot::ClassDB::bind_method(godot::D_METHOD("get_chamfer_dist1"), &OcctlTopoEdgeBlendOptions::get_chamfer_dist1);
    godot::ClassDB::bind_method(godot::D_METHOD("set_chamfer_dist1", "val"), &OcctlTopoEdgeBlendOptions::set_chamfer_dist1);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "chamfer_dist1"), "set_chamfer_dist1", "get_chamfer_dist1");
    godot::ClassDB::bind_method(godot::D_METHOD("get_chamfer_dist2"), &OcctlTopoEdgeBlendOptions::get_chamfer_dist2);
    godot::ClassDB::bind_method(godot::D_METHOD("set_chamfer_dist2", "val"), &OcctlTopoEdgeBlendOptions::set_chamfer_dist2);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "chamfer_dist2"), "set_chamfer_dist2", "get_chamfer_dist2");
}

occtl_topo_edge_blend_options_t OcctlTopoEdgeBlendOptions::to_c() const {
    occtl_topo_edge_blend_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.root.bits = static_cast<uint64_t>(root);
    result.edges = reinterpret_cast<const occtl_node_id_t*>(edges.ptr());
    result.edge_count = edge_count;
    result.radius = radius;
    result.chamfer_mode = chamfer_mode;
    result.chamfer_dist1 = chamfer_dist1;
    result.chamfer_dist2 = chamfer_dist2;
    return result;
}

Ref<OcctlTopoEdgeBlendOptions> OcctlTopoEdgeBlendOptions::from_c(const occtl_topo_edge_blend_options_t& val) {
    Ref<OcctlTopoEdgeBlendOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->root = static_cast<int64_t>(val.root.bits);
    // array field edges is not populated from C
    r->edge_count = val.edge_count;
    r->radius = val.radius;
    r->chamfer_mode = val.chamfer_mode;
    r->chamfer_dist1 = val.chamfer_dist1;
    r->chamfer_dist2 = val.chamfer_dist2;
    return r;
}

void OcctlTopoEdgeBlendOptions::copy_from_c(const occtl_topo_edge_blend_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    root = static_cast<int64_t>(val.root.bits);
    // array field edges is not populated from C
    edge_count = val.edge_count;
    radius = val.radius;
    chamfer_mode = val.chamfer_mode;
    chamfer_dist1 = val.chamfer_dist1;
    chamfer_dist2 = val.chamfer_dist2;
}
