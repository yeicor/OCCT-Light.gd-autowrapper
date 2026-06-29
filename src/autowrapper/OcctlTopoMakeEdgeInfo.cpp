#include "OcctlTopoMakeEdgeInfo.h"

#include "OcctlNodeId.h"
#include "OcctlRepId.h"

int OcctlTopoMakeEdgeInfo::get_struct_version() const { return struct_version; }
void OcctlTopoMakeEdgeInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoMakeEdgeInfo::get_p_next() const { return p_next; }
void OcctlTopoMakeEdgeInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlTopoMakeEdgeInfo::get_start_vertex() const { return start_vertex; }
void OcctlTopoMakeEdgeInfo::set_start_vertex(int64_t val) { start_vertex = val; }

int64_t OcctlTopoMakeEdgeInfo::get_end_vertex() const { return end_vertex; }
void OcctlTopoMakeEdgeInfo::set_end_vertex(int64_t val) { end_vertex = val; }

int64_t OcctlTopoMakeEdgeInfo::get_curve() const { return curve; }
void OcctlTopoMakeEdgeInfo::set_curve(int64_t val) { curve = val; }

double OcctlTopoMakeEdgeInfo::get_first() const { return first; }
void OcctlTopoMakeEdgeInfo::set_first(double val) { first = val; }

double OcctlTopoMakeEdgeInfo::get_last() const { return last; }
void OcctlTopoMakeEdgeInfo::set_last(double val) { last = val; }

double OcctlTopoMakeEdgeInfo::get_tolerance() const { return tolerance; }
void OcctlTopoMakeEdgeInfo::set_tolerance(double val) { tolerance = val; }

void OcctlTopoMakeEdgeInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoMakeEdgeInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoMakeEdgeInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoMakeEdgeInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoMakeEdgeInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_start_vertex"), &OcctlTopoMakeEdgeInfo::get_start_vertex);
    godot::ClassDB::bind_method(godot::D_METHOD("set_start_vertex", "val"), &OcctlTopoMakeEdgeInfo::set_start_vertex);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "start_vertex"), "set_start_vertex", "get_start_vertex");
    godot::ClassDB::bind_method(godot::D_METHOD("get_end_vertex"), &OcctlTopoMakeEdgeInfo::get_end_vertex);
    godot::ClassDB::bind_method(godot::D_METHOD("set_end_vertex", "val"), &OcctlTopoMakeEdgeInfo::set_end_vertex);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "end_vertex"), "set_end_vertex", "get_end_vertex");
    godot::ClassDB::bind_method(godot::D_METHOD("get_curve"), &OcctlTopoMakeEdgeInfo::get_curve);
    godot::ClassDB::bind_method(godot::D_METHOD("set_curve", "val"), &OcctlTopoMakeEdgeInfo::set_curve);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "curve"), "set_curve", "get_curve");
    godot::ClassDB::bind_method(godot::D_METHOD("get_first"), &OcctlTopoMakeEdgeInfo::get_first);
    godot::ClassDB::bind_method(godot::D_METHOD("set_first", "val"), &OcctlTopoMakeEdgeInfo::set_first);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "first"), "set_first", "get_first");
    godot::ClassDB::bind_method(godot::D_METHOD("get_last"), &OcctlTopoMakeEdgeInfo::get_last);
    godot::ClassDB::bind_method(godot::D_METHOD("set_last", "val"), &OcctlTopoMakeEdgeInfo::set_last);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "last"), "set_last", "get_last");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlTopoMakeEdgeInfo::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlTopoMakeEdgeInfo::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
}

occtl_topo_make_edge_info_t OcctlTopoMakeEdgeInfo::to_c() const {
    occtl_topo_make_edge_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.start_vertex.bits = static_cast<uint64_t>(start_vertex);
    result.end_vertex.bits = static_cast<uint64_t>(end_vertex);
    result.curve.bits = static_cast<uint64_t>(curve);
    result.first = first;
    result.last = last;
    result.tolerance = tolerance;
    return result;
}

Ref<OcctlTopoMakeEdgeInfo> OcctlTopoMakeEdgeInfo::from_c(const occtl_topo_make_edge_info_t& val) {
    Ref<OcctlTopoMakeEdgeInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->start_vertex = static_cast<int64_t>(val.start_vertex.bits);
    r->end_vertex = static_cast<int64_t>(val.end_vertex.bits);
    r->curve = static_cast<int64_t>(val.curve.bits);
    r->first = val.first;
    r->last = val.last;
    r->tolerance = val.tolerance;
    return r;
}

void OcctlTopoMakeEdgeInfo::copy_from_c(const occtl_topo_make_edge_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    start_vertex = static_cast<int64_t>(val.start_vertex.bits);
    end_vertex = static_cast<int64_t>(val.end_vertex.bits);
    curve = static_cast<int64_t>(val.curve.bits);
    first = val.first;
    last = val.last;
    tolerance = val.tolerance;
}
