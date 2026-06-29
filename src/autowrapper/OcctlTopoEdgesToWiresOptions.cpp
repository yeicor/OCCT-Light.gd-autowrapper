#include "OcctlTopoEdgesToWiresOptions.h"


int OcctlTopoEdgesToWiresOptions::get_struct_version() const { return struct_version; }
void OcctlTopoEdgesToWiresOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoEdgesToWiresOptions::get_p_next() const { return p_next; }
void OcctlTopoEdgesToWiresOptions::set_p_next(int64_t val) { p_next = val; }

PackedInt64Array OcctlTopoEdgesToWiresOptions::get_edges() const { return edges; }
void OcctlTopoEdgesToWiresOptions::set_edges(PackedInt64Array val) { edges = val; }

int OcctlTopoEdgesToWiresOptions::get_edge_count() const { return edge_count; }
void OcctlTopoEdgesToWiresOptions::set_edge_count(int val) { edge_count = val; }

double OcctlTopoEdgesToWiresOptions::get_tolerance() const { return tolerance; }
void OcctlTopoEdgesToWiresOptions::set_tolerance(double val) { tolerance = val; }

int OcctlTopoEdgesToWiresOptions::get_allow_open() const { return allow_open; }
void OcctlTopoEdgesToWiresOptions::set_allow_open(int val) { allow_open = val; }

void OcctlTopoEdgesToWiresOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoEdgesToWiresOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoEdgesToWiresOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoEdgesToWiresOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoEdgesToWiresOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_edges"), &OcctlTopoEdgesToWiresOptions::get_edges);
    godot::ClassDB::bind_method(godot::D_METHOD("set_edges", "val"), &OcctlTopoEdgesToWiresOptions::set_edges);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "edges"), "set_edges", "get_edges");
    godot::ClassDB::bind_method(godot::D_METHOD("get_edge_count"), &OcctlTopoEdgesToWiresOptions::get_edge_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_edge_count", "val"), &OcctlTopoEdgesToWiresOptions::set_edge_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "edge_count"), "set_edge_count", "get_edge_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlTopoEdgesToWiresOptions::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlTopoEdgesToWiresOptions::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_allow_open"), &OcctlTopoEdgesToWiresOptions::get_allow_open);
    godot::ClassDB::bind_method(godot::D_METHOD("set_allow_open", "val"), &OcctlTopoEdgesToWiresOptions::set_allow_open);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "allow_open"), "set_allow_open", "get_allow_open");
}

occtl_topo_edges_to_wires_options_t OcctlTopoEdgesToWiresOptions::to_c() const {
    occtl_topo_edges_to_wires_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.edges = reinterpret_cast<const occtl_node_id_t*>(edges.ptr());
    result.edge_count = edge_count;
    result.tolerance = tolerance;
    result.allow_open = allow_open;
    return result;
}

Ref<OcctlTopoEdgesToWiresOptions> OcctlTopoEdgesToWiresOptions::from_c(const occtl_topo_edges_to_wires_options_t& val) {
    Ref<OcctlTopoEdgesToWiresOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field edges is not populated from C
    r->edge_count = val.edge_count;
    r->tolerance = val.tolerance;
    r->allow_open = val.allow_open;
    return r;
}

void OcctlTopoEdgesToWiresOptions::copy_from_c(const occtl_topo_edges_to_wires_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field edges is not populated from C
    edge_count = val.edge_count;
    tolerance = val.tolerance;
    allow_open = val.allow_open;
}
