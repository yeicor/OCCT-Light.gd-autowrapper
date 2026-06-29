#include "OcctlIoPly.h"

#include "occtl/occtl_io_ply.h"

void OcctlIoPly::_bind_methods() {
    BIND_CONSTANT(OCCTL_IO_PLY_WRITE_OPTIONS_VERSION_1);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_ply_coordinate_system_t", "OCCTL_IO_PLY_COORDINATE_SYSTEM_Y_UP", OCCTL_IO_PLY_COORDINATE_SYSTEM_Y_UP);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_ply_coordinate_system_t", "OCCTL_IO_PLY_COORDINATE_SYSTEM_Z_UP", OCCTL_IO_PLY_COORDINATE_SYSTEM_Z_UP);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_ply_coordinate_system_t", "OCCTL_IO_PLY_COORDINATE_SYSTEM_GLTF", OCCTL_IO_PLY_COORDINATE_SYSTEM_GLTF);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_ply_coordinate_system_t", "OCCTL_IO_PLY_COORDINATE_SYSTEM_RESERVED_FUTURE", OCCTL_IO_PLY_COORDINATE_SYSTEM_RESERVED_FUTURE);
    godot::ClassDB::bind_method(godot::D_METHOD("write_options_init", "options"), &OcctlIoPly::write_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("write", "graph", "root", "path", "options"), &OcctlIoPly::write, DEFVAL(Variant()));
}

void OcctlIoPly::write_options_init(const Ref<OcctlIoPlyWriteOptions>& options) { // NOLINT
    occtl_io_ply_write_options_t _options_val = {};
    ::occtl_io_ply_write_options_init(&_options_val);
    ::occtl_io_ply_write_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

int OcctlIoPly::write(const Ref<OcctlGraphHandle>& graph, int64_t root, const String& path, const Ref<OcctlIoPlyWriteOptions>& options) { // NOLINT
    occtl_io_ply_write_options_t _options_c = {};
    const occtl_io_ply_write_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_status_t _status = ::occtl_io_ply_write(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(root)}, path.utf8().get_data(), _options_ptr);
    return static_cast<int>(_status);
}
