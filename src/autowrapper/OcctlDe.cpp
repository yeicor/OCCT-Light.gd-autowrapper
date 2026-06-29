#include "OcctlDe.h"

#include "occtl/occtl_de.h"

#include <vector>

void OcctlDe::_bind_methods() {
    BIND_CONSTANT(OCCTL_DE_FORMAT_INFO_VERSION_1);
    godot::ClassDB::bind_method(godot::D_METHOD("format_info_init", "info"), &OcctlDe::format_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("read", "path", "out_root"), &OcctlDe::read);
    godot::ClassDB::bind_method(godot::D_METHOD("read_memory", "format_id", "data", "size", "out_root"), &OcctlDe::read_memory);
    godot::ClassDB::bind_method(godot::D_METHOD("write", "graph", "root", "path"), &OcctlDe::write);
    godot::ClassDB::bind_method(godot::D_METHOD("write_memory", "graph", "root", "format_id"), &OcctlDe::write_memory);
    godot::ClassDB::bind_method(godot::D_METHOD("format_ids", "cap", "out_count"), &OcctlDe::format_ids);
    godot::ClassDB::bind_method(godot::D_METHOD("format_count", "out_count"), &OcctlDe::format_count);
    godot::ClassDB::bind_method(godot::D_METHOD("format_info_at", "index", "out_info"), &OcctlDe::format_info_at);
    godot::ClassDB::bind_method(godot::D_METHOD("format_info_by_id", "format_id", "out_info"), &OcctlDe::format_info_by_id);
    godot::ClassDB::bind_method(godot::D_METHOD("format_extensions", "format_id", "cap", "out_count"), &OcctlDe::format_extensions);
    godot::ClassDB::bind_method(godot::D_METHOD("format_id_from_path", "path"), &OcctlDe::format_id_from_path);
}

void OcctlDe::format_info_init(const Ref<OcctlDeFormatInfo>& info) { // NOLINT
    occtl_de_format_info_t _info_val = {};
    ::occtl_de_format_info_init(&_info_val);
    ::occtl_de_format_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

Ref<OcctlGraphHandle> OcctlDe::read(const String& path, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_de_read(path.utf8().get_data(), &_out_graph_val, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

Ref<OcctlGraphHandle> OcctlDe::read_memory(const String& format_id, const PackedByteArray& data, int size, const Ref<OcctlNodeId>& out_root) { // NOLINT
    const uint8_t* _data_c = data.ptr();
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_de_read_memory(format_id.utf8().get_data(), _data_c, size, &_out_graph_val, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

int OcctlDe::write(const Ref<OcctlGraphHandle>& graph, int64_t root, const String& path) { // NOLINT
    occtl_status_t _status = ::occtl_de_write(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(root)}, path.utf8().get_data());
    return static_cast<int>(_status);
}

PackedByteArray OcctlDe::write_memory(const Ref<OcctlGraphHandle>& graph, int64_t root, const String& format_id) { // NOLINT
    size_t _out_size_cnt = 0;
    godot::CharString _format_id_cs = format_id.utf8();
    occtl_status_t _err = ::occtl_de_write_memory(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(root)}, _format_id_cs.get_data(), nullptr, 0, &_out_size_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedByteArray(); }
    std::vector<uint8_t> _out_data_buf(_out_size_cnt);
    _err = ::occtl_de_write_memory(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(root)}, _format_id_cs.get_data(), _out_data_buf.data(), _out_size_cnt, &_out_size_cnt);
    PackedByteArray _result;
    _result.resize(static_cast<int64_t>(_out_size_cnt));
    for (size_t _i = 0; _i < _out_size_cnt; _i++) _result[static_cast<int64_t>(_i)] = _out_data_buf[_i];
    return _result;
}

int OcctlDe::format_ids(int cap, const Ref<OcctlSize>& out_count) { // NOLINT
    std::vector<const char*> _out_format_ids_buf(static_cast<size_t>(cap));
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_de_format_ids(_out_format_ids_buf.data(), cap, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlDe::format_count(const Ref<OcctlSize>& out_count) { // NOLINT
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_de_format_count(&_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlDe::format_info_at(int index, const Ref<OcctlDeFormatInfo>& out_info) { // NOLINT
    occtl_de_format_info_t _out_info_val = {};
    ::occtl_de_format_info_init(&_out_info_val);
    occtl_status_t _status = ::occtl_de_format_info_at(index, &_out_info_val);
    if (out_info.is_valid()) out_info->copy_from_c(_out_info_val);
    return static_cast<int>(_status);
}

int OcctlDe::format_info_by_id(const String& format_id, const Ref<OcctlDeFormatInfo>& out_info) { // NOLINT
    occtl_de_format_info_t _out_info_val = {};
    ::occtl_de_format_info_init(&_out_info_val);
    occtl_status_t _status = ::occtl_de_format_info_by_id(format_id.utf8().get_data(), &_out_info_val);
    if (out_info.is_valid()) out_info->copy_from_c(_out_info_val);
    return static_cast<int>(_status);
}

int OcctlDe::format_extensions(const String& format_id, int cap, const Ref<OcctlSize>& out_count) { // NOLINT
    std::vector<const char*> _out_extensions_buf(static_cast<size_t>(cap));
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_de_format_extensions(format_id.utf8().get_data(), _out_extensions_buf.data(), cap, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlDe::format_id_from_path(const String& path) { // NOLINT
    const char* _out_format_id_val = nullptr;
    occtl_status_t _status = ::occtl_de_format_id_from_path(path.utf8().get_data(), &_out_format_id_val);
    return static_cast<int>(_status);
}
