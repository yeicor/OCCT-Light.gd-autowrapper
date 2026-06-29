#include "OcctlHeal.h"

#include "occtl/occtl_heal.h"

void OcctlHeal::_bind_methods() {
    BIND_CONSTANT(OCCTL_HEAL_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_HEAL_UNIFY_SAME_DOMAIN_OPTIONS_VERSION_1);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_heal_mode_t", "OCCTL_HEAL_MODE_BASIC", OCCTL_HEAL_MODE_BASIC);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_heal_mode_t", "OCCTL_HEAL_MODE_STANDARD", OCCTL_HEAL_MODE_STANDARD);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_heal_mode_t", "OCCTL_HEAL_MODE_FULL", OCCTL_HEAL_MODE_FULL);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_heal_mode_t", "OCCTL_HEAL_MODE_RESERVED_FUTURE", OCCTL_HEAL_MODE_RESERVED_FUTURE);
    godot::ClassDB::bind_method(godot::D_METHOD("options_init", "options"), &OcctlHeal::options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("unify_same_domain_options_init", "options"), &OcctlHeal::unify_same_domain_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("shape", "graph", "node_id", "options"), &OcctlHeal::shape, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("unify_same_domain", "graph", "node_id", "options", "out_root"), &OcctlHeal::unify_same_domain, DEFVAL(Variant()));
}

void OcctlHeal::options_init(const Ref<OcctlHealOptions>& options) { // NOLINT
    occtl_heal_options_t _options_val = {};
    ::occtl_heal_options_init(&_options_val);
    ::occtl_heal_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

void OcctlHeal::unify_same_domain_options_init(const Ref<OcctlHealUnifySameDomainOptions>& options) { // NOLINT
    occtl_heal_unify_same_domain_options_t _options_val = {};
    ::occtl_heal_unify_same_domain_options_init(&_options_val);
    ::occtl_heal_unify_same_domain_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

int OcctlHeal::shape(const Ref<OcctlGraphHandle>& graph, int64_t node_id, const Ref<OcctlHealOptions>& options) { // NOLINT
    occtl_heal_options_t _options_c = {};
    const occtl_heal_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_status_t _status = ::occtl_heal_shape(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node_id)}, _options_ptr);
    return static_cast<int>(_status);
}

int OcctlHeal::unify_same_domain(const Ref<OcctlGraphHandle>& graph, int64_t node_id, const Ref<OcctlHealUnifySameDomainOptions>& options, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_heal_unify_same_domain_options_t _options_c = {};
    const occtl_heal_unify_same_domain_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_heal_unify_same_domain(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node_id)}, _options_ptr, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    return static_cast<int>(_status);
}
