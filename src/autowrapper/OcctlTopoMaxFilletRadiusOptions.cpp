#include "OcctlTopoMaxFilletRadiusOptions.h"

#include "OcctlNodeId.h"

int OcctlTopoMaxFilletRadiusOptions::get_struct_version() const { return struct_version; }
void OcctlTopoMaxFilletRadiusOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoMaxFilletRadiusOptions::get_p_next() const { return p_next; }
void OcctlTopoMaxFilletRadiusOptions::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlTopoMaxFilletRadiusOptions::get_root() const { return root; }
void OcctlTopoMaxFilletRadiusOptions::set_root(int64_t val) { root = val; }

PackedInt64Array OcctlTopoMaxFilletRadiusOptions::get_edges() const { return edges; }
void OcctlTopoMaxFilletRadiusOptions::set_edges(PackedInt64Array val) { edges = val; }

int OcctlTopoMaxFilletRadiusOptions::get_edge_count() const { return edge_count; }
void OcctlTopoMaxFilletRadiusOptions::set_edge_count(int val) { edge_count = val; }

double OcctlTopoMaxFilletRadiusOptions::get_min_radius() const { return min_radius; }
void OcctlTopoMaxFilletRadiusOptions::set_min_radius(double val) { min_radius = val; }

double OcctlTopoMaxFilletRadiusOptions::get_max_radius() const { return max_radius; }
void OcctlTopoMaxFilletRadiusOptions::set_max_radius(double val) { max_radius = val; }

double OcctlTopoMaxFilletRadiusOptions::get_tolerance() const { return tolerance; }
void OcctlTopoMaxFilletRadiusOptions::set_tolerance(double val) { tolerance = val; }

int OcctlTopoMaxFilletRadiusOptions::get_max_iterations() const { return max_iterations; }
void OcctlTopoMaxFilletRadiusOptions::set_max_iterations(int val) { max_iterations = val; }

void OcctlTopoMaxFilletRadiusOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoMaxFilletRadiusOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoMaxFilletRadiusOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoMaxFilletRadiusOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoMaxFilletRadiusOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_root"), &OcctlTopoMaxFilletRadiusOptions::get_root);
    godot::ClassDB::bind_method(godot::D_METHOD("set_root", "val"), &OcctlTopoMaxFilletRadiusOptions::set_root);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "root"), "set_root", "get_root");
    godot::ClassDB::bind_method(godot::D_METHOD("get_edges"), &OcctlTopoMaxFilletRadiusOptions::get_edges);
    godot::ClassDB::bind_method(godot::D_METHOD("set_edges", "val"), &OcctlTopoMaxFilletRadiusOptions::set_edges);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "edges"), "set_edges", "get_edges");
    godot::ClassDB::bind_method(godot::D_METHOD("get_edge_count"), &OcctlTopoMaxFilletRadiusOptions::get_edge_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_edge_count", "val"), &OcctlTopoMaxFilletRadiusOptions::set_edge_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "edge_count"), "set_edge_count", "get_edge_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_min_radius"), &OcctlTopoMaxFilletRadiusOptions::get_min_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_min_radius", "val"), &OcctlTopoMaxFilletRadiusOptions::set_min_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "min_radius"), "set_min_radius", "get_min_radius");
    godot::ClassDB::bind_method(godot::D_METHOD("get_max_radius"), &OcctlTopoMaxFilletRadiusOptions::get_max_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max_radius", "val"), &OcctlTopoMaxFilletRadiusOptions::set_max_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max_radius"), "set_max_radius", "get_max_radius");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlTopoMaxFilletRadiusOptions::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlTopoMaxFilletRadiusOptions::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_max_iterations"), &OcctlTopoMaxFilletRadiusOptions::get_max_iterations);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max_iterations", "val"), &OcctlTopoMaxFilletRadiusOptions::set_max_iterations);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "max_iterations"), "set_max_iterations", "get_max_iterations");
}

occtl_topo_max_fillet_radius_options_t OcctlTopoMaxFilletRadiusOptions::to_c() const {
    occtl_topo_max_fillet_radius_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.root.bits = static_cast<uint64_t>(root);
    result.edges = reinterpret_cast<const occtl_node_id_t*>(edges.ptr());
    result.edge_count = edge_count;
    result.min_radius = min_radius;
    result.max_radius = max_radius;
    result.tolerance = tolerance;
    result.max_iterations = max_iterations;
    return result;
}

Ref<OcctlTopoMaxFilletRadiusOptions> OcctlTopoMaxFilletRadiusOptions::from_c(const occtl_topo_max_fillet_radius_options_t& val) {
    Ref<OcctlTopoMaxFilletRadiusOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->root = static_cast<int64_t>(val.root.bits);
    // array field edges is not populated from C
    r->edge_count = val.edge_count;
    r->min_radius = val.min_radius;
    r->max_radius = val.max_radius;
    r->tolerance = val.tolerance;
    r->max_iterations = val.max_iterations;
    return r;
}

void OcctlTopoMaxFilletRadiusOptions::copy_from_c(const occtl_topo_max_fillet_radius_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    root = static_cast<int64_t>(val.root.bits);
    // array field edges is not populated from C
    edge_count = val.edge_count;
    min_radius = val.min_radius;
    max_radius = val.max_radius;
    tolerance = val.tolerance;
    max_iterations = val.max_iterations;
}
