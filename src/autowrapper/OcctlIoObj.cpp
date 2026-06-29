#include "OcctlIoObj.h"

#include "occtl/occtl_io_obj.h"

void OcctlIoObj::_bind_methods() {
    BIND_CONSTANT(OCCTL_IO_OBJ_READ_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_IO_OBJ_WRITE_OPTIONS_VERSION_1);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_obj_coordinate_system_t", "OCCTL_IO_OBJ_COORDINATE_SYSTEM_Y_UP", OCCTL_IO_OBJ_COORDINATE_SYSTEM_Y_UP);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_obj_coordinate_system_t", "OCCTL_IO_OBJ_COORDINATE_SYSTEM_Z_UP", OCCTL_IO_OBJ_COORDINATE_SYSTEM_Z_UP);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_obj_coordinate_system_t", "OCCTL_IO_OBJ_COORDINATE_SYSTEM_GLTF", OCCTL_IO_OBJ_COORDINATE_SYSTEM_GLTF);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_obj_coordinate_system_t", "OCCTL_IO_OBJ_COORDINATE_SYSTEM_RESERVED_FUTURE", OCCTL_IO_OBJ_COORDINATE_SYSTEM_RESERVED_FUTURE);
    godot::ClassDB::bind_method(godot::D_METHOD("read_options_init", "options"), &OcctlIoObj::read_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("write_options_init", "options"), &OcctlIoObj::write_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("read", "path", "out_root", "options"), &OcctlIoObj::read, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("write", "graph", "root", "path", "options"), &OcctlIoObj::write, DEFVAL(Variant()));
}

void OcctlIoObj::read_options_init(const Ref<OcctlIoObjReadOptions>& options) { // NOLINT
    occtl_io_obj_read_options_t _options_val = {};
    ::occtl_io_obj_read_options_init(&_options_val);
    ::occtl_io_obj_read_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

void OcctlIoObj::write_options_init(const Ref<OcctlIoObjWriteOptions>& options) { // NOLINT
    occtl_io_obj_write_options_t _options_val = {};
    ::occtl_io_obj_write_options_init(&_options_val);
    ::occtl_io_obj_write_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

Ref<OcctlGraphHandle> OcctlIoObj::read(const String& path, const Ref<OcctlNodeId>& out_root, const Ref<OcctlIoObjReadOptions>& options) { // NOLINT
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_io_obj_read_options_t _options_c = {};
    const occtl_io_obj_read_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_status_t _status = ::occtl_io_obj_read(path.utf8().get_data(), &_out_graph_val, &_out_root_val, _options_ptr);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

int OcctlIoObj::write(const Ref<OcctlGraphHandle>& graph, int64_t root, const String& path, const Ref<OcctlIoObjWriteOptions>& options) { // NOLINT
    occtl_io_obj_write_options_t _options_c = {};
    const occtl_io_obj_write_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_status_t _status = ::occtl_io_obj_write(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(root)}, path.utf8().get_data(), _options_ptr);
    return static_cast<int>(_status);
}
