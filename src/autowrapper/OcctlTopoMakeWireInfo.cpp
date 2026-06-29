#include "OcctlTopoMakeWireInfo.h"


int OcctlTopoMakeWireInfo::get_struct_version() const { return struct_version; }
void OcctlTopoMakeWireInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoMakeWireInfo::get_p_next() const { return p_next; }
void OcctlTopoMakeWireInfo::set_p_next(int64_t val) { p_next = val; }

Array OcctlTopoMakeWireInfo::get_edges() const { return edges; }
void OcctlTopoMakeWireInfo::set_edges(Array val) { edges = val; }

int OcctlTopoMakeWireInfo::get_edge_count() const { return edge_count; }
void OcctlTopoMakeWireInfo::set_edge_count(int val) { edge_count = val; }

void OcctlTopoMakeWireInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoMakeWireInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoMakeWireInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoMakeWireInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoMakeWireInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_edges"), &OcctlTopoMakeWireInfo::get_edges);
    godot::ClassDB::bind_method(godot::D_METHOD("set_edges", "val"), &OcctlTopoMakeWireInfo::set_edges);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "edges"), "set_edges", "get_edges");
    godot::ClassDB::bind_method(godot::D_METHOD("get_edge_count"), &OcctlTopoMakeWireInfo::get_edge_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_edge_count", "val"), &OcctlTopoMakeWireInfo::set_edge_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "edge_count"), "set_edge_count", "get_edge_count");
}

occtl_topo_make_wire_info_t OcctlTopoMakeWireInfo::to_c() const {
    occtl_topo_make_wire_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    _cache_edges.resize(edges.size());
    for (int _i = 0; _i < edges.size(); _i++) {
        Ref<OcctlOrientedNode> _item = edges[_i];
        if (_item.is_valid()) _cache_edges[_i] = _item->to_c();
        else _cache_edges[_i] = {};
    }
    result.edges = _cache_edges.data();
    result.edge_count = edge_count;
    return result;
}

Ref<OcctlTopoMakeWireInfo> OcctlTopoMakeWireInfo::from_c(const occtl_topo_make_wire_info_t& val) {
    Ref<OcctlTopoMakeWireInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field edges is not populated from C
    r->edge_count = val.edge_count;
    return r;
}

void OcctlTopoMakeWireInfo::copy_from_c(const occtl_topo_make_wire_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field edges is not populated from C
    edge_count = val.edge_count;
}
