#include "OcctlPrimRuledSurfaceInfo.h"

#include "OcctlNodeId.h"

int OcctlPrimRuledSurfaceInfo::get_struct_version() const { return struct_version; }
void OcctlPrimRuledSurfaceInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimRuledSurfaceInfo::get_p_next() const { return p_next; }
void OcctlPrimRuledSurfaceInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlPrimRuledSurfaceInfo::get_section_a() const { return section_a; }
void OcctlPrimRuledSurfaceInfo::set_section_a(int64_t val) { section_a = val; }

int64_t OcctlPrimRuledSurfaceInfo::get_section_b() const { return section_b; }
void OcctlPrimRuledSurfaceInfo::set_section_b(int64_t val) { section_b = val; }

void OcctlPrimRuledSurfaceInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimRuledSurfaceInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimRuledSurfaceInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimRuledSurfaceInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimRuledSurfaceInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_section_a"), &OcctlPrimRuledSurfaceInfo::get_section_a);
    godot::ClassDB::bind_method(godot::D_METHOD("set_section_a", "val"), &OcctlPrimRuledSurfaceInfo::set_section_a);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "section_a"), "set_section_a", "get_section_a");
    godot::ClassDB::bind_method(godot::D_METHOD("get_section_b"), &OcctlPrimRuledSurfaceInfo::get_section_b);
    godot::ClassDB::bind_method(godot::D_METHOD("set_section_b", "val"), &OcctlPrimRuledSurfaceInfo::set_section_b);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "section_b"), "set_section_b", "get_section_b");
}

occtl_prim_ruled_surface_info_t OcctlPrimRuledSurfaceInfo::to_c() const {
    occtl_prim_ruled_surface_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.section_a.bits = static_cast<uint64_t>(section_a);
    result.section_b.bits = static_cast<uint64_t>(section_b);
    return result;
}

Ref<OcctlPrimRuledSurfaceInfo> OcctlPrimRuledSurfaceInfo::from_c(const occtl_prim_ruled_surface_info_t& val) {
    Ref<OcctlPrimRuledSurfaceInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->section_a = static_cast<int64_t>(val.section_a.bits);
    r->section_b = static_cast<int64_t>(val.section_b.bits);
    return r;
}

void OcctlPrimRuledSurfaceInfo::copy_from_c(const occtl_prim_ruled_surface_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    section_a = static_cast<int64_t>(val.section_a.bits);
    section_b = static_cast<int64_t>(val.section_b.bits);
}
