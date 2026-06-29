#include "OcctlHealOptions.h"


int OcctlHealOptions::get_struct_version() const { return struct_version; }
void OcctlHealOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlHealOptions::get_p_next() const { return p_next; }
void OcctlHealOptions::set_p_next(int64_t val) { p_next = val; }

int OcctlHealOptions::get_mode() const { return mode; }
void OcctlHealOptions::set_mode(int val) { mode = val; }

double OcctlHealOptions::get_tolerance() const { return tolerance; }
void OcctlHealOptions::set_tolerance(double val) { tolerance = val; }

int OcctlHealOptions::get_fix_same_parameter() const { return fix_same_parameter; }
void OcctlHealOptions::set_fix_same_parameter(int val) { fix_same_parameter = val; }

int OcctlHealOptions::get_fix_small_edges() const { return fix_small_edges; }
void OcctlHealOptions::set_fix_small_edges(int val) { fix_small_edges = val; }

int OcctlHealOptions::get_fix_face_orient() const { return fix_face_orient; }
void OcctlHealOptions::set_fix_face_orient(int val) { fix_face_orient = val; }

int OcctlHealOptions::get_fix_missing_seam() const { return fix_missing_seam; }
void OcctlHealOptions::set_fix_missing_seam(int val) { fix_missing_seam = val; }

void OcctlHealOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlHealOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlHealOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlHealOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlHealOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_mode"), &OcctlHealOptions::get_mode);
    godot::ClassDB::bind_method(godot::D_METHOD("set_mode", "val"), &OcctlHealOptions::set_mode);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "mode"), "set_mode", "get_mode");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlHealOptions::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlHealOptions::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_fix_same_parameter"), &OcctlHealOptions::get_fix_same_parameter);
    godot::ClassDB::bind_method(godot::D_METHOD("set_fix_same_parameter", "val"), &OcctlHealOptions::set_fix_same_parameter);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "fix_same_parameter"), "set_fix_same_parameter", "get_fix_same_parameter");
    godot::ClassDB::bind_method(godot::D_METHOD("get_fix_small_edges"), &OcctlHealOptions::get_fix_small_edges);
    godot::ClassDB::bind_method(godot::D_METHOD("set_fix_small_edges", "val"), &OcctlHealOptions::set_fix_small_edges);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "fix_small_edges"), "set_fix_small_edges", "get_fix_small_edges");
    godot::ClassDB::bind_method(godot::D_METHOD("get_fix_face_orient"), &OcctlHealOptions::get_fix_face_orient);
    godot::ClassDB::bind_method(godot::D_METHOD("set_fix_face_orient", "val"), &OcctlHealOptions::set_fix_face_orient);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "fix_face_orient"), "set_fix_face_orient", "get_fix_face_orient");
    godot::ClassDB::bind_method(godot::D_METHOD("get_fix_missing_seam"), &OcctlHealOptions::get_fix_missing_seam);
    godot::ClassDB::bind_method(godot::D_METHOD("set_fix_missing_seam", "val"), &OcctlHealOptions::set_fix_missing_seam);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "fix_missing_seam"), "set_fix_missing_seam", "get_fix_missing_seam");
}

occtl_heal_options_t OcctlHealOptions::to_c() const {
    occtl_heal_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.mode = static_cast<occtl_heal_mode_t>(mode);
    result.tolerance = tolerance;
    result.fix_same_parameter = fix_same_parameter;
    result.fix_small_edges = fix_small_edges;
    result.fix_face_orient = fix_face_orient;
    result.fix_missing_seam = fix_missing_seam;
    return result;
}

Ref<OcctlHealOptions> OcctlHealOptions::from_c(const occtl_heal_options_t& val) {
    Ref<OcctlHealOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->mode = static_cast<int>(val.mode);
    r->tolerance = val.tolerance;
    r->fix_same_parameter = val.fix_same_parameter;
    r->fix_small_edges = val.fix_small_edges;
    r->fix_face_orient = val.fix_face_orient;
    r->fix_missing_seam = val.fix_missing_seam;
    return r;
}

void OcctlHealOptions::copy_from_c(const occtl_heal_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    mode = static_cast<int>(val.mode);
    tolerance = val.tolerance;
    fix_same_parameter = val.fix_same_parameter;
    fix_small_edges = val.fix_small_edges;
    fix_face_orient = val.fix_face_orient;
    fix_missing_seam = val.fix_missing_seam;
}
