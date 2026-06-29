#include "OcctlIoVrml.h"

#include "occtl/occtl_io_vrml.h"

#include <vector>

void OcctlIoVrml::_bind_methods() {
    BIND_CONSTANT(OCCTL_IO_VRML_READ_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_IO_VRML_WRITE_OPTIONS_VERSION_1);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_vrml_coordinate_system_t", "OCCTL_IO_VRML_COORDINATE_SYSTEM_Y_UP", OCCTL_IO_VRML_COORDINATE_SYSTEM_Y_UP);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_vrml_coordinate_system_t", "OCCTL_IO_VRML_COORDINATE_SYSTEM_Z_UP", OCCTL_IO_VRML_COORDINATE_SYSTEM_Z_UP);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_vrml_coordinate_system_t", "OCCTL_IO_VRML_COORDINATE_SYSTEM_GLTF", OCCTL_IO_VRML_COORDINATE_SYSTEM_GLTF);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_vrml_coordinate_system_t", "OCCTL_IO_VRML_COORDINATE_SYSTEM_RESERVED_FUTURE", OCCTL_IO_VRML_COORDINATE_SYSTEM_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_vrml_writer_version_t", "OCCTL_IO_VRML_WRITER_VERSION_1", OCCTL_IO_VRML_WRITER_VERSION_1);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_vrml_writer_version_t", "OCCTL_IO_VRML_WRITER_VERSION_2", OCCTL_IO_VRML_WRITER_VERSION_2);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_vrml_writer_version_t", "OCCTL_IO_VRML_WRITER_VERSION_RESERVED_FUTURE", OCCTL_IO_VRML_WRITER_VERSION_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_vrml_representation_t", "OCCTL_IO_VRML_REPRESENTATION_SHADED", OCCTL_IO_VRML_REPRESENTATION_SHADED);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_vrml_representation_t", "OCCTL_IO_VRML_REPRESENTATION_WIREFRAME", OCCTL_IO_VRML_REPRESENTATION_WIREFRAME);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_vrml_representation_t", "OCCTL_IO_VRML_REPRESENTATION_BOTH", OCCTL_IO_VRML_REPRESENTATION_BOTH);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_vrml_representation_t", "OCCTL_IO_VRML_REPRESENTATION_RESERVED_FUTURE", OCCTL_IO_VRML_REPRESENTATION_RESERVED_FUTURE);
    godot::ClassDB::bind_method(godot::D_METHOD("read_options_init", "options"), &OcctlIoVrml::read_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("write_options_init", "options"), &OcctlIoVrml::write_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("read", "path", "out_root", "options"), &OcctlIoVrml::read, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("write", "graph", "root", "path", "options"), &OcctlIoVrml::write, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("read_memory", "data", "size", "out_root", "options"), &OcctlIoVrml::read_memory, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("write_memory", "graph", "root", "options"), &OcctlIoVrml::write_memory, DEFVAL(Variant()));
}

void OcctlIoVrml::read_options_init(const Ref<OcctlIoVrmlReadOptions>& options) { // NOLINT
    occtl_io_vrml_read_options_t _options_val = {};
    ::occtl_io_vrml_read_options_init(&_options_val);
    ::occtl_io_vrml_read_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

void OcctlIoVrml::write_options_init(const Ref<OcctlIoVrmlWriteOptions>& options) { // NOLINT
    occtl_io_vrml_write_options_t _options_val = {};
    ::occtl_io_vrml_write_options_init(&_options_val);
    ::occtl_io_vrml_write_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

Ref<OcctlGraphHandle> OcctlIoVrml::read(const String& path, const Ref<OcctlNodeId>& out_root, const Ref<OcctlIoVrmlReadOptions>& options) { // NOLINT
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_io_vrml_read_options_t _options_c = {};
    const occtl_io_vrml_read_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_status_t _status = ::occtl_io_vrml_read(path.utf8().get_data(), &_out_graph_val, &_out_root_val, _options_ptr);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

int OcctlIoVrml::write(const Ref<OcctlGraphHandle>& graph, int64_t root, const String& path, const Ref<OcctlIoVrmlWriteOptions>& options) { // NOLINT
    occtl_io_vrml_write_options_t _options_c = {};
    const occtl_io_vrml_write_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_status_t _status = ::occtl_io_vrml_write(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(root)}, path.utf8().get_data(), _options_ptr);
    return static_cast<int>(_status);
}

Ref<OcctlGraphHandle> OcctlIoVrml::read_memory(const PackedByteArray& data, int size, const Ref<OcctlNodeId>& out_root, const Ref<OcctlIoVrmlReadOptions>& options) { // NOLINT
    const uint8_t* _data_c = data.ptr();
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_io_vrml_read_options_t _options_c = {};
    const occtl_io_vrml_read_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_status_t _status = ::occtl_io_vrml_read_memory(_data_c, size, &_out_graph_val, &_out_root_val, _options_ptr);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

PackedByteArray OcctlIoVrml::write_memory(const Ref<OcctlGraphHandle>& graph, int64_t root, const Ref<OcctlIoVrmlWriteOptions>& options) { // NOLINT
    size_t _out_size_cnt = 0;
    occtl_io_vrml_write_options_t _options_c = {};
    const occtl_io_vrml_write_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_status_t _err = ::occtl_io_vrml_write_memory(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(root)}, _options_ptr, nullptr, 0, &_out_size_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedByteArray(); }
    std::vector<uint8_t> _out_data_buf(_out_size_cnt);
    _err = ::occtl_io_vrml_write_memory(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(root)}, _options_ptr, _out_data_buf.data(), _out_size_cnt, &_out_size_cnt);
    PackedByteArray _result;
    _result.resize(static_cast<int64_t>(_out_size_cnt));
    for (size_t _i = 0; _i < _out_size_cnt; _i++) _result[static_cast<int64_t>(_i)] = _out_data_buf[_i];
    return _result;
}
