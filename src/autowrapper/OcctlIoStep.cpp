#include "OcctlIoStep.h"

#include "occtl/occtl_io_step.h"

#include <vector>

void OcctlIoStep::_bind_methods() {
    BIND_CONSTANT(OCCTL_IO_STEP_READ_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_IO_STEP_WRITE_OPTIONS_VERSION_1);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_step_length_unit_t", "OCCTL_IO_STEP_UNIT_MM", OCCTL_IO_STEP_UNIT_MM);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_step_length_unit_t", "OCCTL_IO_STEP_UNIT_M", OCCTL_IO_STEP_UNIT_M);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_step_length_unit_t", "OCCTL_IO_STEP_UNIT_INCH", OCCTL_IO_STEP_UNIT_INCH);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_step_length_unit_t", "OCCTL_IO_STEP_UNIT_RESERVED_FUTURE", OCCTL_IO_STEP_UNIT_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_step_schema_t", "OCCTL_IO_STEP_SCHEMA_AP203", OCCTL_IO_STEP_SCHEMA_AP203);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_step_schema_t", "OCCTL_IO_STEP_SCHEMA_AP214", OCCTL_IO_STEP_SCHEMA_AP214);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_step_schema_t", "OCCTL_IO_STEP_SCHEMA_AP242", OCCTL_IO_STEP_SCHEMA_AP242);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_io_step_schema_t", "OCCTL_IO_STEP_SCHEMA_RESERVED_FUTURE", OCCTL_IO_STEP_SCHEMA_RESERVED_FUTURE);
    godot::ClassDB::bind_method(godot::D_METHOD("read_options_init", "options"), &OcctlIoStep::read_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("write_options_init", "options"), &OcctlIoStep::write_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("read", "path", "out_root", "options"), &OcctlIoStep::read, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("read_memory", "data", "size", "out_root", "options"), &OcctlIoStep::read_memory, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("write", "graph", "root", "path", "options"), &OcctlIoStep::write, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("write_memory", "graph", "root", "options"), &OcctlIoStep::write_memory, DEFVAL(Variant()));
}

void OcctlIoStep::read_options_init(const Ref<OcctlIoStepReadOptions>& options) { // NOLINT
    occtl_io_step_read_options_t _options_val = {};
    ::occtl_io_step_read_options_init(&_options_val);
    ::occtl_io_step_read_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

void OcctlIoStep::write_options_init(const Ref<OcctlIoStepWriteOptions>& options) { // NOLINT
    occtl_io_step_write_options_t _options_val = {};
    ::occtl_io_step_write_options_init(&_options_val);
    ::occtl_io_step_write_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

Ref<OcctlGraphHandle> OcctlIoStep::read(const String& path, const Ref<OcctlNodeId>& out_root, const Ref<OcctlIoStepReadOptions>& options) { // NOLINT
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_io_step_read_options_t _options_c = {};
    const occtl_io_step_read_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_status_t _status = ::occtl_io_step_read(path.utf8().get_data(), &_out_graph_val, &_out_root_val, _options_ptr);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

Ref<OcctlGraphHandle> OcctlIoStep::read_memory(const PackedByteArray& data, int size, const Ref<OcctlNodeId>& out_root, const Ref<OcctlIoStepReadOptions>& options) { // NOLINT
    const uint8_t* _data_c = data.ptr();
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_io_step_read_options_t _options_c = {};
    const occtl_io_step_read_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_status_t _status = ::occtl_io_step_read_memory(_data_c, size, &_out_graph_val, &_out_root_val, _options_ptr);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

int OcctlIoStep::write(const Ref<OcctlGraphHandle>& graph, int64_t root, const String& path, const Ref<OcctlIoStepWriteOptions>& options) { // NOLINT
    occtl_io_step_write_options_t _options_c = {};
    const occtl_io_step_write_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_status_t _status = ::occtl_io_step_write(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(root)}, path.utf8().get_data(), _options_ptr);
    return static_cast<int>(_status);
}

PackedByteArray OcctlIoStep::write_memory(const Ref<OcctlGraphHandle>& graph, int64_t root, const Ref<OcctlIoStepWriteOptions>& options) { // NOLINT
    size_t _out_size_cnt = 0;
    occtl_io_step_write_options_t _options_c = {};
    const occtl_io_step_write_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_status_t _err = ::occtl_io_step_write_memory(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(root)}, _options_ptr, nullptr, 0, &_out_size_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedByteArray(); }
    std::vector<uint8_t> _out_data_buf(_out_size_cnt);
    _err = ::occtl_io_step_write_memory(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(root)}, _options_ptr, _out_data_buf.data(), _out_size_cnt, &_out_size_cnt);
    PackedByteArray _result;
    _result.resize(static_cast<int64_t>(_out_size_cnt));
    for (size_t _i = 0; _i < _out_size_cnt; _i++) _result[static_cast<int64_t>(_i)] = _out_data_buf[_i];
    return _result;
}
