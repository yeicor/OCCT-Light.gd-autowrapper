#include "OcctlWireView.h"


int OcctlWireView::get_struct_version() const { return struct_version; }
void OcctlWireView::set_struct_version(int val) { struct_version = val; }

int64_t OcctlWireView::get_p_next() const { return p_next; }
void OcctlWireView::set_p_next(int64_t val) { p_next = val; }

int OcctlWireView::get_is_closed() const { return is_closed; }
void OcctlWireView::set_is_closed(int val) { is_closed = val; }

int OcctlWireView::get_coedge_count() const { return coedge_count; }
void OcctlWireView::set_coedge_count(int val) { coedge_count = val; }

int OcctlWireView::get_distinct_edge_count() const { return distinct_edge_count; }
void OcctlWireView::set_distinct_edge_count(int val) { distinct_edge_count = val; }

void OcctlWireView::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlWireView::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlWireView::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlWireView::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlWireView::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_closed"), &OcctlWireView::get_is_closed);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_closed", "val"), &OcctlWireView::set_is_closed);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_closed"), "set_is_closed", "get_is_closed");
    godot::ClassDB::bind_method(godot::D_METHOD("get_coedge_count"), &OcctlWireView::get_coedge_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_coedge_count", "val"), &OcctlWireView::set_coedge_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "coedge_count"), "set_coedge_count", "get_coedge_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_distinct_edge_count"), &OcctlWireView::get_distinct_edge_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_distinct_edge_count", "val"), &OcctlWireView::set_distinct_edge_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "distinct_edge_count"), "set_distinct_edge_count", "get_distinct_edge_count");
}

occtl_wire_view_t OcctlWireView::to_c() const {
    occtl_wire_view_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.is_closed = is_closed;
    result.coedge_count = coedge_count;
    result.distinct_edge_count = distinct_edge_count;
    return result;
}

Ref<OcctlWireView> OcctlWireView::from_c(const occtl_wire_view_t& val) {
    Ref<OcctlWireView> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->is_closed = val.is_closed;
    r->coedge_count = val.coedge_count;
    r->distinct_edge_count = val.distinct_edge_count;
    return r;
}

void OcctlWireView::copy_from_c(const occtl_wire_view_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    is_closed = val.is_closed;
    coedge_count = val.coedge_count;
    distinct_edge_count = val.distinct_edge_count;
}
