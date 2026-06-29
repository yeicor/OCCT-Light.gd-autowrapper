#include "OcctlBool.h"

#include "occtl/occtl_bool.h"

void OcctlBool::_bind_methods() {
    BIND_CONSTANT(OCCTL_BOOL_OPTIONS_VERSION_1);
    godot::ClassDB::bind_method(godot::D_METHOD("options_init", "options"), &OcctlBool::options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("fuse", "graph", "objects", "tools", "opts", "out_root"), &OcctlBool::fuse, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("cut", "graph", "objects", "tools", "opts", "out_root"), &OcctlBool::cut, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("common", "graph", "objects", "tools", "opts", "out_root"), &OcctlBool::common, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("section", "graph", "objects", "tools", "opts", "out_root"), &OcctlBool::section, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("split", "graph", "objects", "tools", "opts", "out_root"), &OcctlBool::split, DEFVAL(Variant()));
}

void OcctlBool::options_init(const Ref<OcctlBoolOptions>& options) { // NOLINT
    occtl_bool_options_t _options_val = {};
    ::occtl_bool_options_init(&_options_val);
    ::occtl_bool_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

int OcctlBool::fuse(const Ref<OcctlGraphHandle>& graph, const PackedInt64Array& objects, const PackedInt64Array& tools, const Ref<OcctlBoolOptions>& opts, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_bool_options_t _opts_c = {};
    const occtl_bool_options_t* _opts_ptr = nullptr;
    if (opts.is_valid()) { _opts_c = opts->to_c(); _opts_ptr = &_opts_c; }
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_bool_fuse(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), reinterpret_cast<const occtl_node_id_t*>(static_cast<const void*>(objects.ptr())), static_cast<size_t>(objects.size()), reinterpret_cast<const occtl_node_id_t*>(static_cast<const void*>(tools.ptr())), static_cast<size_t>(tools.size()), _opts_ptr, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    return static_cast<int>(_status);
}

int OcctlBool::cut(const Ref<OcctlGraphHandle>& graph, const PackedInt64Array& objects, const PackedInt64Array& tools, const Ref<OcctlBoolOptions>& opts, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_bool_options_t _opts_c = {};
    const occtl_bool_options_t* _opts_ptr = nullptr;
    if (opts.is_valid()) { _opts_c = opts->to_c(); _opts_ptr = &_opts_c; }
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_bool_cut(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), reinterpret_cast<const occtl_node_id_t*>(static_cast<const void*>(objects.ptr())), static_cast<size_t>(objects.size()), reinterpret_cast<const occtl_node_id_t*>(static_cast<const void*>(tools.ptr())), static_cast<size_t>(tools.size()), _opts_ptr, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    return static_cast<int>(_status);
}

int OcctlBool::common(const Ref<OcctlGraphHandle>& graph, const PackedInt64Array& objects, const PackedInt64Array& tools, const Ref<OcctlBoolOptions>& opts, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_bool_options_t _opts_c = {};
    const occtl_bool_options_t* _opts_ptr = nullptr;
    if (opts.is_valid()) { _opts_c = opts->to_c(); _opts_ptr = &_opts_c; }
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_bool_common(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), reinterpret_cast<const occtl_node_id_t*>(static_cast<const void*>(objects.ptr())), static_cast<size_t>(objects.size()), reinterpret_cast<const occtl_node_id_t*>(static_cast<const void*>(tools.ptr())), static_cast<size_t>(tools.size()), _opts_ptr, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    return static_cast<int>(_status);
}

int OcctlBool::section(const Ref<OcctlGraphHandle>& graph, const PackedInt64Array& objects, const PackedInt64Array& tools, const Ref<OcctlBoolOptions>& opts, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_bool_options_t _opts_c = {};
    const occtl_bool_options_t* _opts_ptr = nullptr;
    if (opts.is_valid()) { _opts_c = opts->to_c(); _opts_ptr = &_opts_c; }
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_bool_section(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), reinterpret_cast<const occtl_node_id_t*>(static_cast<const void*>(objects.ptr())), static_cast<size_t>(objects.size()), reinterpret_cast<const occtl_node_id_t*>(static_cast<const void*>(tools.ptr())), static_cast<size_t>(tools.size()), _opts_ptr, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    return static_cast<int>(_status);
}

int OcctlBool::split(const Ref<OcctlGraphHandle>& graph, const PackedInt64Array& objects, const PackedInt64Array& tools, const Ref<OcctlBoolOptions>& opts, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_bool_options_t _opts_c = {};
    const occtl_bool_options_t* _opts_ptr = nullptr;
    if (opts.is_valid()) { _opts_c = opts->to_c(); _opts_ptr = &_opts_c; }
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_bool_split(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), reinterpret_cast<const occtl_node_id_t*>(static_cast<const void*>(objects.ptr())), static_cast<size_t>(objects.size()), reinterpret_cast<const occtl_node_id_t*>(static_cast<const void*>(tools.ptr())), static_cast<size_t>(tools.size()), _opts_ptr, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    return static_cast<int>(_status);
}
