#include "OcctlTopoDefeatureOptions.h"

#include "OcctlNodeId.h"

int OcctlTopoDefeatureOptions::get_struct_version() const { return struct_version; }
void OcctlTopoDefeatureOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoDefeatureOptions::get_p_next() const { return p_next; }
void OcctlTopoDefeatureOptions::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlTopoDefeatureOptions::get_root() const { return root; }
void OcctlTopoDefeatureOptions::set_root(int64_t val) { root = val; }

PackedInt64Array OcctlTopoDefeatureOptions::get_selections() const { return selections; }
void OcctlTopoDefeatureOptions::set_selections(PackedInt64Array val) { selections = val; }

int OcctlTopoDefeatureOptions::get_selection_count() const { return selection_count; }
void OcctlTopoDefeatureOptions::set_selection_count(int val) { selection_count = val; }

int OcctlTopoDefeatureOptions::get_parallel() const { return parallel; }
void OcctlTopoDefeatureOptions::set_parallel(int val) { parallel = val; }

void OcctlTopoDefeatureOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoDefeatureOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoDefeatureOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoDefeatureOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoDefeatureOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_root"), &OcctlTopoDefeatureOptions::get_root);
    godot::ClassDB::bind_method(godot::D_METHOD("set_root", "val"), &OcctlTopoDefeatureOptions::set_root);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "root"), "set_root", "get_root");
    godot::ClassDB::bind_method(godot::D_METHOD("get_selections"), &OcctlTopoDefeatureOptions::get_selections);
    godot::ClassDB::bind_method(godot::D_METHOD("set_selections", "val"), &OcctlTopoDefeatureOptions::set_selections);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "selections"), "set_selections", "get_selections");
    godot::ClassDB::bind_method(godot::D_METHOD("get_selection_count"), &OcctlTopoDefeatureOptions::get_selection_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_selection_count", "val"), &OcctlTopoDefeatureOptions::set_selection_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "selection_count"), "set_selection_count", "get_selection_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_parallel"), &OcctlTopoDefeatureOptions::get_parallel);
    godot::ClassDB::bind_method(godot::D_METHOD("set_parallel", "val"), &OcctlTopoDefeatureOptions::set_parallel);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "parallel"), "set_parallel", "get_parallel");
}

occtl_topo_defeature_options_t OcctlTopoDefeatureOptions::to_c() const {
    occtl_topo_defeature_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.root.bits = static_cast<uint64_t>(root);
    result.selections = reinterpret_cast<const occtl_node_id_t*>(selections.ptr());
    result.selection_count = selection_count;
    result.parallel = parallel;
    return result;
}

Ref<OcctlTopoDefeatureOptions> OcctlTopoDefeatureOptions::from_c(const occtl_topo_defeature_options_t& val) {
    Ref<OcctlTopoDefeatureOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->root = static_cast<int64_t>(val.root.bits);
    // array field selections is not populated from C
    r->selection_count = val.selection_count;
    r->parallel = val.parallel;
    return r;
}

void OcctlTopoDefeatureOptions::copy_from_c(const occtl_topo_defeature_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    root = static_cast<int64_t>(val.root.bits);
    // array field selections is not populated from C
    selection_count = val.selection_count;
    parallel = val.parallel;
}
