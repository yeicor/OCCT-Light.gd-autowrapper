#include "OcctlIoBrep.h"

#include "occtl/occtl_io_brep.h"

void OcctlIoBrep::_bind_methods() {
    BIND_CONSTANT(OCCTL_IO_BREP_WRITE_OPTIONS_VERSION_1);
    godot::ClassDB::bind_method(godot::D_METHOD("write_options_init", "options"), &OcctlIoBrep::write_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("read", "path", "out_root"), &OcctlIoBrep::read);
    godot::ClassDB::bind_method(godot::D_METHOD("write", "graph", "root", "path", "options"), &OcctlIoBrep::write, DEFVAL(Variant()));
}

void OcctlIoBrep::write_options_init(const Ref<OcctlIoBrepWriteOptions>& options) { // NOLINT
    occtl_io_brep_write_options_t _options_val = {};
    ::occtl_io_brep_write_options_init(&_options_val);
    ::occtl_io_brep_write_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

Ref<OcctlGraphHandle> OcctlIoBrep::read(const String& path, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_io_brep_read(path.utf8().get_data(), &_out_graph_val, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

int OcctlIoBrep::write(const Ref<OcctlGraphHandle>& graph, int64_t root, const String& path, const Ref<OcctlIoBrepWriteOptions>& options) { // NOLINT
    occtl_io_brep_write_options_t _options_c = {};
    const occtl_io_brep_write_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_status_t _status = ::occtl_io_brep_write(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(root)}, path.utf8().get_data(), _options_ptr);
    return static_cast<int>(_status);
}
