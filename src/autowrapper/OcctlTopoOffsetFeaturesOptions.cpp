#include "OcctlTopoOffsetFeaturesOptions.h"

#include "OcctlNodeId.h"

int OcctlTopoOffsetFeaturesOptions::get_struct_version() const { return struct_version; }
void OcctlTopoOffsetFeaturesOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoOffsetFeaturesOptions::get_p_next() const { return p_next; }
void OcctlTopoOffsetFeaturesOptions::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlTopoOffsetFeaturesOptions::get_root() const { return root; }
void OcctlTopoOffsetFeaturesOptions::set_root(int64_t val) { root = val; }

PackedInt64Array OcctlTopoOffsetFeaturesOptions::get_selections() const { return selections; }
void OcctlTopoOffsetFeaturesOptions::set_selections(PackedInt64Array val) { selections = val; }

int OcctlTopoOffsetFeaturesOptions::get_selection_count() const { return selection_count; }
void OcctlTopoOffsetFeaturesOptions::set_selection_count(int val) { selection_count = val; }

double OcctlTopoOffsetFeaturesOptions::get_base_offset() const { return base_offset; }
void OcctlTopoOffsetFeaturesOptions::set_base_offset(double val) { base_offset = val; }

double OcctlTopoOffsetFeaturesOptions::get_selection_offset() const { return selection_offset; }
void OcctlTopoOffsetFeaturesOptions::set_selection_offset(double val) { selection_offset = val; }

double OcctlTopoOffsetFeaturesOptions::get_tolerance() const { return tolerance; }
void OcctlTopoOffsetFeaturesOptions::set_tolerance(double val) { tolerance = val; }

int OcctlTopoOffsetFeaturesOptions::get_join() const { return join; }
void OcctlTopoOffsetFeaturesOptions::set_join(int val) { join = val; }

int OcctlTopoOffsetFeaturesOptions::get_intersection() const { return intersection; }
void OcctlTopoOffsetFeaturesOptions::set_intersection(int val) { intersection = val; }

int OcctlTopoOffsetFeaturesOptions::get_self_intersection() const { return self_intersection; }
void OcctlTopoOffsetFeaturesOptions::set_self_intersection(int val) { self_intersection = val; }

int OcctlTopoOffsetFeaturesOptions::get_remove_internal_edges() const { return remove_internal_edges; }
void OcctlTopoOffsetFeaturesOptions::set_remove_internal_edges(int val) { remove_internal_edges = val; }

void OcctlTopoOffsetFeaturesOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoOffsetFeaturesOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoOffsetFeaturesOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoOffsetFeaturesOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoOffsetFeaturesOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_root"), &OcctlTopoOffsetFeaturesOptions::get_root);
    godot::ClassDB::bind_method(godot::D_METHOD("set_root", "val"), &OcctlTopoOffsetFeaturesOptions::set_root);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "root"), "set_root", "get_root");
    godot::ClassDB::bind_method(godot::D_METHOD("get_selections"), &OcctlTopoOffsetFeaturesOptions::get_selections);
    godot::ClassDB::bind_method(godot::D_METHOD("set_selections", "val"), &OcctlTopoOffsetFeaturesOptions::set_selections);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "selections"), "set_selections", "get_selections");
    godot::ClassDB::bind_method(godot::D_METHOD("get_selection_count"), &OcctlTopoOffsetFeaturesOptions::get_selection_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_selection_count", "val"), &OcctlTopoOffsetFeaturesOptions::set_selection_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "selection_count"), "set_selection_count", "get_selection_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_base_offset"), &OcctlTopoOffsetFeaturesOptions::get_base_offset);
    godot::ClassDB::bind_method(godot::D_METHOD("set_base_offset", "val"), &OcctlTopoOffsetFeaturesOptions::set_base_offset);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "base_offset"), "set_base_offset", "get_base_offset");
    godot::ClassDB::bind_method(godot::D_METHOD("get_selection_offset"), &OcctlTopoOffsetFeaturesOptions::get_selection_offset);
    godot::ClassDB::bind_method(godot::D_METHOD("set_selection_offset", "val"), &OcctlTopoOffsetFeaturesOptions::set_selection_offset);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "selection_offset"), "set_selection_offset", "get_selection_offset");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlTopoOffsetFeaturesOptions::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlTopoOffsetFeaturesOptions::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_join"), &OcctlTopoOffsetFeaturesOptions::get_join);
    godot::ClassDB::bind_method(godot::D_METHOD("set_join", "val"), &OcctlTopoOffsetFeaturesOptions::set_join);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "join"), "set_join", "get_join");
    godot::ClassDB::bind_method(godot::D_METHOD("get_intersection"), &OcctlTopoOffsetFeaturesOptions::get_intersection);
    godot::ClassDB::bind_method(godot::D_METHOD("set_intersection", "val"), &OcctlTopoOffsetFeaturesOptions::set_intersection);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "intersection"), "set_intersection", "get_intersection");
    godot::ClassDB::bind_method(godot::D_METHOD("get_self_intersection"), &OcctlTopoOffsetFeaturesOptions::get_self_intersection);
    godot::ClassDB::bind_method(godot::D_METHOD("set_self_intersection", "val"), &OcctlTopoOffsetFeaturesOptions::set_self_intersection);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "self_intersection"), "set_self_intersection", "get_self_intersection");
    godot::ClassDB::bind_method(godot::D_METHOD("get_remove_internal_edges"), &OcctlTopoOffsetFeaturesOptions::get_remove_internal_edges);
    godot::ClassDB::bind_method(godot::D_METHOD("set_remove_internal_edges", "val"), &OcctlTopoOffsetFeaturesOptions::set_remove_internal_edges);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "remove_internal_edges"), "set_remove_internal_edges", "get_remove_internal_edges");
}

occtl_topo_offset_features_options_t OcctlTopoOffsetFeaturesOptions::to_c() const {
    occtl_topo_offset_features_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.root.bits = static_cast<uint64_t>(root);
    result.selections = reinterpret_cast<const occtl_node_id_t*>(selections.ptr());
    result.selection_count = selection_count;
    result.base_offset = base_offset;
    result.selection_offset = selection_offset;
    result.tolerance = tolerance;
    result.join = static_cast<occtl_offset_join_type_t>(join);
    result.intersection = intersection;
    result.self_intersection = self_intersection;
    result.remove_internal_edges = remove_internal_edges;
    return result;
}

Ref<OcctlTopoOffsetFeaturesOptions> OcctlTopoOffsetFeaturesOptions::from_c(const occtl_topo_offset_features_options_t& val) {
    Ref<OcctlTopoOffsetFeaturesOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->root = static_cast<int64_t>(val.root.bits);
    // array field selections is not populated from C
    r->selection_count = val.selection_count;
    r->base_offset = val.base_offset;
    r->selection_offset = val.selection_offset;
    r->tolerance = val.tolerance;
    r->join = static_cast<int>(val.join);
    r->intersection = val.intersection;
    r->self_intersection = val.self_intersection;
    r->remove_internal_edges = val.remove_internal_edges;
    return r;
}

void OcctlTopoOffsetFeaturesOptions::copy_from_c(const occtl_topo_offset_features_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    root = static_cast<int64_t>(val.root.bits);
    // array field selections is not populated from C
    selection_count = val.selection_count;
    base_offset = val.base_offset;
    selection_offset = val.selection_offset;
    tolerance = val.tolerance;
    join = static_cast<int>(val.join);
    intersection = val.intersection;
    self_intersection = val.self_intersection;
    remove_internal_edges = val.remove_internal_edges;
}
