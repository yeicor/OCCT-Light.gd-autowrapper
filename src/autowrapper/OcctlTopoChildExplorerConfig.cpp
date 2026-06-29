#include "OcctlTopoChildExplorerConfig.h"


int OcctlTopoChildExplorerConfig::get_struct_version() const { return struct_version; }
void OcctlTopoChildExplorerConfig::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoChildExplorerConfig::get_p_next() const { return p_next; }
void OcctlTopoChildExplorerConfig::set_p_next(int64_t val) { p_next = val; }

int OcctlTopoChildExplorerConfig::get_mode() const { return mode; }
void OcctlTopoChildExplorerConfig::set_mode(int val) { mode = val; }

int OcctlTopoChildExplorerConfig::get_target_kind() const { return target_kind; }
void OcctlTopoChildExplorerConfig::set_target_kind(int val) { target_kind = val; }

int OcctlTopoChildExplorerConfig::get_avoid_kind() const { return avoid_kind; }
void OcctlTopoChildExplorerConfig::set_avoid_kind(int val) { avoid_kind = val; }

int OcctlTopoChildExplorerConfig::get_emit_avoid_kind() const { return emit_avoid_kind; }
void OcctlTopoChildExplorerConfig::set_emit_avoid_kind(int val) { emit_avoid_kind = val; }

int OcctlTopoChildExplorerConfig::get_accumulate_location() const { return accumulate_location; }
void OcctlTopoChildExplorerConfig::set_accumulate_location(int val) { accumulate_location = val; }

int OcctlTopoChildExplorerConfig::get_accumulate_orientation() const { return accumulate_orientation; }
void OcctlTopoChildExplorerConfig::set_accumulate_orientation(int val) { accumulate_orientation = val; }

void OcctlTopoChildExplorerConfig::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoChildExplorerConfig::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoChildExplorerConfig::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoChildExplorerConfig::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoChildExplorerConfig::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_mode"), &OcctlTopoChildExplorerConfig::get_mode);
    godot::ClassDB::bind_method(godot::D_METHOD("set_mode", "val"), &OcctlTopoChildExplorerConfig::set_mode);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "mode"), "set_mode", "get_mode");
    godot::ClassDB::bind_method(godot::D_METHOD("get_target_kind"), &OcctlTopoChildExplorerConfig::get_target_kind);
    godot::ClassDB::bind_method(godot::D_METHOD("set_target_kind", "val"), &OcctlTopoChildExplorerConfig::set_target_kind);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "target_kind"), "set_target_kind", "get_target_kind");
    godot::ClassDB::bind_method(godot::D_METHOD("get_avoid_kind"), &OcctlTopoChildExplorerConfig::get_avoid_kind);
    godot::ClassDB::bind_method(godot::D_METHOD("set_avoid_kind", "val"), &OcctlTopoChildExplorerConfig::set_avoid_kind);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "avoid_kind"), "set_avoid_kind", "get_avoid_kind");
    godot::ClassDB::bind_method(godot::D_METHOD("get_emit_avoid_kind"), &OcctlTopoChildExplorerConfig::get_emit_avoid_kind);
    godot::ClassDB::bind_method(godot::D_METHOD("set_emit_avoid_kind", "val"), &OcctlTopoChildExplorerConfig::set_emit_avoid_kind);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "emit_avoid_kind"), "set_emit_avoid_kind", "get_emit_avoid_kind");
    godot::ClassDB::bind_method(godot::D_METHOD("get_accumulate_location"), &OcctlTopoChildExplorerConfig::get_accumulate_location);
    godot::ClassDB::bind_method(godot::D_METHOD("set_accumulate_location", "val"), &OcctlTopoChildExplorerConfig::set_accumulate_location);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "accumulate_location"), "set_accumulate_location", "get_accumulate_location");
    godot::ClassDB::bind_method(godot::D_METHOD("get_accumulate_orientation"), &OcctlTopoChildExplorerConfig::get_accumulate_orientation);
    godot::ClassDB::bind_method(godot::D_METHOD("set_accumulate_orientation", "val"), &OcctlTopoChildExplorerConfig::set_accumulate_orientation);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "accumulate_orientation"), "set_accumulate_orientation", "get_accumulate_orientation");
}

occtl_topo_child_explorer_config_t OcctlTopoChildExplorerConfig::to_c() const {
    occtl_topo_child_explorer_config_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.mode = static_cast<occtl_topo_explorer_traversal_t>(mode);
    result.target_kind = static_cast<occtl_node_kind_t>(target_kind);
    result.avoid_kind = static_cast<occtl_node_kind_t>(avoid_kind);
    result.emit_avoid_kind = emit_avoid_kind;
    result.accumulate_location = accumulate_location;
    result.accumulate_orientation = accumulate_orientation;
    return result;
}

Ref<OcctlTopoChildExplorerConfig> OcctlTopoChildExplorerConfig::from_c(const occtl_topo_child_explorer_config_t& val) {
    Ref<OcctlTopoChildExplorerConfig> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->mode = static_cast<int>(val.mode);
    r->target_kind = static_cast<int>(val.target_kind);
    r->avoid_kind = static_cast<int>(val.avoid_kind);
    r->emit_avoid_kind = val.emit_avoid_kind;
    r->accumulate_location = val.accumulate_location;
    r->accumulate_orientation = val.accumulate_orientation;
    return r;
}

void OcctlTopoChildExplorerConfig::copy_from_c(const occtl_topo_child_explorer_config_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    mode = static_cast<int>(val.mode);
    target_kind = static_cast<int>(val.target_kind);
    avoid_kind = static_cast<int>(val.avoid_kind);
    emit_avoid_kind = val.emit_avoid_kind;
    accumulate_location = val.accumulate_location;
    accumulate_orientation = val.accumulate_orientation;
}
