#include "OcctlTopoParentExplorerConfig.h"


int OcctlTopoParentExplorerConfig::get_struct_version() const { return struct_version; }
void OcctlTopoParentExplorerConfig::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoParentExplorerConfig::get_p_next() const { return p_next; }
void OcctlTopoParentExplorerConfig::set_p_next(int64_t val) { p_next = val; }

int OcctlTopoParentExplorerConfig::get_mode() const { return mode; }
void OcctlTopoParentExplorerConfig::set_mode(int val) { mode = val; }

int OcctlTopoParentExplorerConfig::get_target_kind() const { return target_kind; }
void OcctlTopoParentExplorerConfig::set_target_kind(int val) { target_kind = val; }

int OcctlTopoParentExplorerConfig::get_avoid_kind() const { return avoid_kind; }
void OcctlTopoParentExplorerConfig::set_avoid_kind(int val) { avoid_kind = val; }

int OcctlTopoParentExplorerConfig::get_emit_avoid_kind() const { return emit_avoid_kind; }
void OcctlTopoParentExplorerConfig::set_emit_avoid_kind(int val) { emit_avoid_kind = val; }

void OcctlTopoParentExplorerConfig::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoParentExplorerConfig::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoParentExplorerConfig::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoParentExplorerConfig::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoParentExplorerConfig::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_mode"), &OcctlTopoParentExplorerConfig::get_mode);
    godot::ClassDB::bind_method(godot::D_METHOD("set_mode", "val"), &OcctlTopoParentExplorerConfig::set_mode);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "mode"), "set_mode", "get_mode");
    godot::ClassDB::bind_method(godot::D_METHOD("get_target_kind"), &OcctlTopoParentExplorerConfig::get_target_kind);
    godot::ClassDB::bind_method(godot::D_METHOD("set_target_kind", "val"), &OcctlTopoParentExplorerConfig::set_target_kind);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "target_kind"), "set_target_kind", "get_target_kind");
    godot::ClassDB::bind_method(godot::D_METHOD("get_avoid_kind"), &OcctlTopoParentExplorerConfig::get_avoid_kind);
    godot::ClassDB::bind_method(godot::D_METHOD("set_avoid_kind", "val"), &OcctlTopoParentExplorerConfig::set_avoid_kind);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "avoid_kind"), "set_avoid_kind", "get_avoid_kind");
    godot::ClassDB::bind_method(godot::D_METHOD("get_emit_avoid_kind"), &OcctlTopoParentExplorerConfig::get_emit_avoid_kind);
    godot::ClassDB::bind_method(godot::D_METHOD("set_emit_avoid_kind", "val"), &OcctlTopoParentExplorerConfig::set_emit_avoid_kind);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "emit_avoid_kind"), "set_emit_avoid_kind", "get_emit_avoid_kind");
}

occtl_topo_parent_explorer_config_t OcctlTopoParentExplorerConfig::to_c() const {
    occtl_topo_parent_explorer_config_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.mode = static_cast<occtl_topo_explorer_traversal_t>(mode);
    result.target_kind = static_cast<occtl_node_kind_t>(target_kind);
    result.avoid_kind = static_cast<occtl_node_kind_t>(avoid_kind);
    result.emit_avoid_kind = emit_avoid_kind;
    return result;
}

Ref<OcctlTopoParentExplorerConfig> OcctlTopoParentExplorerConfig::from_c(const occtl_topo_parent_explorer_config_t& val) {
    Ref<OcctlTopoParentExplorerConfig> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->mode = static_cast<int>(val.mode);
    r->target_kind = static_cast<int>(val.target_kind);
    r->avoid_kind = static_cast<int>(val.avoid_kind);
    r->emit_avoid_kind = val.emit_avoid_kind;
    return r;
}

void OcctlTopoParentExplorerConfig::copy_from_c(const occtl_topo_parent_explorer_config_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    mode = static_cast<int>(val.mode);
    target_kind = static_cast<int>(val.target_kind);
    avoid_kind = static_cast<int>(val.avoid_kind);
    emit_avoid_kind = val.emit_avoid_kind;
}
