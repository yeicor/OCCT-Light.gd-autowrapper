#include "OcctlPrimLoftInfo.h"


int OcctlPrimLoftInfo::get_struct_version() const { return struct_version; }
void OcctlPrimLoftInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimLoftInfo::get_p_next() const { return p_next; }
void OcctlPrimLoftInfo::set_p_next(int64_t val) { p_next = val; }

PackedInt64Array OcctlPrimLoftInfo::get_sections() const { return sections; }
void OcctlPrimLoftInfo::set_sections(PackedInt64Array val) { sections = val; }

int OcctlPrimLoftInfo::get_section_count() const { return section_count; }
void OcctlPrimLoftInfo::set_section_count(int val) { section_count = val; }

int OcctlPrimLoftInfo::get_is_solid() const { return is_solid; }
void OcctlPrimLoftInfo::set_is_solid(int val) { is_solid = val; }

int OcctlPrimLoftInfo::get_ruled() const { return ruled; }
void OcctlPrimLoftInfo::set_ruled(int val) { ruled = val; }

double OcctlPrimLoftInfo::get_pres3d() const { return pres3d; }
void OcctlPrimLoftInfo::set_pres3d(double val) { pres3d = val; }

void OcctlPrimLoftInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimLoftInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimLoftInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimLoftInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimLoftInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_sections"), &OcctlPrimLoftInfo::get_sections);
    godot::ClassDB::bind_method(godot::D_METHOD("set_sections", "val"), &OcctlPrimLoftInfo::set_sections);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "sections"), "set_sections", "get_sections");
    godot::ClassDB::bind_method(godot::D_METHOD("get_section_count"), &OcctlPrimLoftInfo::get_section_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_section_count", "val"), &OcctlPrimLoftInfo::set_section_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "section_count"), "set_section_count", "get_section_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_solid"), &OcctlPrimLoftInfo::get_is_solid);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_solid", "val"), &OcctlPrimLoftInfo::set_is_solid);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_solid"), "set_is_solid", "get_is_solid");
    godot::ClassDB::bind_method(godot::D_METHOD("get_ruled"), &OcctlPrimLoftInfo::get_ruled);
    godot::ClassDB::bind_method(godot::D_METHOD("set_ruled", "val"), &OcctlPrimLoftInfo::set_ruled);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "ruled"), "set_ruled", "get_ruled");
    godot::ClassDB::bind_method(godot::D_METHOD("get_pres3d"), &OcctlPrimLoftInfo::get_pres3d);
    godot::ClassDB::bind_method(godot::D_METHOD("set_pres3d", "val"), &OcctlPrimLoftInfo::set_pres3d);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "pres3d"), "set_pres3d", "get_pres3d");
}

occtl_prim_loft_info_t OcctlPrimLoftInfo::to_c() const {
    occtl_prim_loft_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.sections = reinterpret_cast<const occtl_node_id_t*>(sections.ptr());
    result.section_count = section_count;
    result.is_solid = is_solid;
    result.ruled = ruled;
    result.pres3d = pres3d;
    return result;
}

Ref<OcctlPrimLoftInfo> OcctlPrimLoftInfo::from_c(const occtl_prim_loft_info_t& val) {
    Ref<OcctlPrimLoftInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field sections is not populated from C
    r->section_count = val.section_count;
    r->is_solid = val.is_solid;
    r->ruled = val.ruled;
    r->pres3d = val.pres3d;
    return r;
}

void OcctlPrimLoftInfo::copy_from_c(const occtl_prim_loft_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field sections is not populated from C
    section_count = val.section_count;
    is_solid = val.is_solid;
    ruled = val.ruled;
    pres3d = val.pres3d;
}
