#include "OcctlPrimFullRound2dInfo.h"

#include "OcctlNodeId.h"

int OcctlPrimFullRound2dInfo::get_struct_version() const { return struct_version; }
void OcctlPrimFullRound2dInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimFullRound2dInfo::get_p_next() const { return p_next; }
void OcctlPrimFullRound2dInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlPrimFullRound2dInfo::get_face() const { return face; }
void OcctlPrimFullRound2dInfo::set_face(int64_t val) { face = val; }

int64_t OcctlPrimFullRound2dInfo::get_edge() const { return edge; }
void OcctlPrimFullRound2dInfo::set_edge(int64_t val) { edge = val; }

double OcctlPrimFullRound2dInfo::get_radius() const { return radius; }
void OcctlPrimFullRound2dInfo::set_radius(double val) { radius = val; }

int OcctlPrimFullRound2dInfo::get_search_steps() const { return search_steps; }
void OcctlPrimFullRound2dInfo::set_search_steps(int val) { search_steps = val; }

void OcctlPrimFullRound2dInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimFullRound2dInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimFullRound2dInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimFullRound2dInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimFullRound2dInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_face"), &OcctlPrimFullRound2dInfo::get_face);
    godot::ClassDB::bind_method(godot::D_METHOD("set_face", "val"), &OcctlPrimFullRound2dInfo::set_face);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "face"), "set_face", "get_face");
    godot::ClassDB::bind_method(godot::D_METHOD("get_edge"), &OcctlPrimFullRound2dInfo::get_edge);
    godot::ClassDB::bind_method(godot::D_METHOD("set_edge", "val"), &OcctlPrimFullRound2dInfo::set_edge);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "edge"), "set_edge", "get_edge");
    godot::ClassDB::bind_method(godot::D_METHOD("get_radius"), &OcctlPrimFullRound2dInfo::get_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_radius", "val"), &OcctlPrimFullRound2dInfo::set_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "radius"), "set_radius", "get_radius");
    godot::ClassDB::bind_method(godot::D_METHOD("get_search_steps"), &OcctlPrimFullRound2dInfo::get_search_steps);
    godot::ClassDB::bind_method(godot::D_METHOD("set_search_steps", "val"), &OcctlPrimFullRound2dInfo::set_search_steps);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "search_steps"), "set_search_steps", "get_search_steps");
}

occtl_prim_full_round_2d_info_t OcctlPrimFullRound2dInfo::to_c() const {
    occtl_prim_full_round_2d_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.face.bits = static_cast<uint64_t>(face);
    result.edge.bits = static_cast<uint64_t>(edge);
    result.radius = radius;
    result.search_steps = search_steps;
    return result;
}

Ref<OcctlPrimFullRound2dInfo> OcctlPrimFullRound2dInfo::from_c(const occtl_prim_full_round_2d_info_t& val) {
    Ref<OcctlPrimFullRound2dInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->face = static_cast<int64_t>(val.face.bits);
    r->edge = static_cast<int64_t>(val.edge.bits);
    r->radius = val.radius;
    r->search_steps = val.search_steps;
    return r;
}

void OcctlPrimFullRound2dInfo::copy_from_c(const occtl_prim_full_round_2d_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    face = static_cast<int64_t>(val.face.bits);
    edge = static_cast<int64_t>(val.edge.bits);
    radius = val.radius;
    search_steps = val.search_steps;
}
