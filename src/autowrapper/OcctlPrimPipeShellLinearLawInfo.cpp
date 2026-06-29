#include "OcctlPrimPipeShellLinearLawInfo.h"

#include "OcctlNodeId.h"
#include "OcctlAxis2Placement.h"
#include "OcctlDirection3.h"

int OcctlPrimPipeShellLinearLawInfo::get_struct_version() const { return struct_version; }
void OcctlPrimPipeShellLinearLawInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimPipeShellLinearLawInfo::get_p_next() const { return p_next; }
void OcctlPrimPipeShellLinearLawInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlPrimPipeShellLinearLawInfo::get_spine_wire() const { return spine_wire; }
void OcctlPrimPipeShellLinearLawInfo::set_spine_wire(int64_t val) { spine_wire = val; }

int64_t OcctlPrimPipeShellLinearLawInfo::get_profile() const { return profile; }
void OcctlPrimPipeShellLinearLawInfo::set_profile(int64_t val) { profile = val; }

double OcctlPrimPipeShellLinearLawInfo::get_scale_first() const { return scale_first; }
void OcctlPrimPipeShellLinearLawInfo::set_scale_first(double val) { scale_first = val; }

double OcctlPrimPipeShellLinearLawInfo::get_scale_last() const { return scale_last; }
void OcctlPrimPipeShellLinearLawInfo::set_scale_last(double val) { scale_last = val; }

int OcctlPrimPipeShellLinearLawInfo::get_mode() const { return mode; }
void OcctlPrimPipeShellLinearLawInfo::set_mode(int val) { mode = val; }

Ref<OcctlAxis2Placement> OcctlPrimPipeShellLinearLawInfo::get_mode_axis() const { return mode_axis; }
void OcctlPrimPipeShellLinearLawInfo::set_mode_axis(Ref<OcctlAxis2Placement> val) { mode_axis = val; }

Ref<OcctlDirection3> OcctlPrimPipeShellLinearLawInfo::get_mode_binormal() const { return mode_binormal; }
void OcctlPrimPipeShellLinearLawInfo::set_mode_binormal(Ref<OcctlDirection3> val) { mode_binormal = val; }

int OcctlPrimPipeShellLinearLawInfo::get_transition() const { return transition; }
void OcctlPrimPipeShellLinearLawInfo::set_transition(int val) { transition = val; }

int OcctlPrimPipeShellLinearLawInfo::get_with_contact() const { return with_contact; }
void OcctlPrimPipeShellLinearLawInfo::set_with_contact(int val) { with_contact = val; }

int OcctlPrimPipeShellLinearLawInfo::get_with_correction() const { return with_correction; }
void OcctlPrimPipeShellLinearLawInfo::set_with_correction(int val) { with_correction = val; }

int OcctlPrimPipeShellLinearLawInfo::get_make_solid() const { return make_solid; }
void OcctlPrimPipeShellLinearLawInfo::set_make_solid(int val) { make_solid = val; }

void OcctlPrimPipeShellLinearLawInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimPipeShellLinearLawInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimPipeShellLinearLawInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimPipeShellLinearLawInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimPipeShellLinearLawInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_spine_wire"), &OcctlPrimPipeShellLinearLawInfo::get_spine_wire);
    godot::ClassDB::bind_method(godot::D_METHOD("set_spine_wire", "val"), &OcctlPrimPipeShellLinearLawInfo::set_spine_wire);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "spine_wire"), "set_spine_wire", "get_spine_wire");
    godot::ClassDB::bind_method(godot::D_METHOD("get_profile"), &OcctlPrimPipeShellLinearLawInfo::get_profile);
    godot::ClassDB::bind_method(godot::D_METHOD("set_profile", "val"), &OcctlPrimPipeShellLinearLawInfo::set_profile);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "profile"), "set_profile", "get_profile");
    godot::ClassDB::bind_method(godot::D_METHOD("get_scale_first"), &OcctlPrimPipeShellLinearLawInfo::get_scale_first);
    godot::ClassDB::bind_method(godot::D_METHOD("set_scale_first", "val"), &OcctlPrimPipeShellLinearLawInfo::set_scale_first);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "scale_first"), "set_scale_first", "get_scale_first");
    godot::ClassDB::bind_method(godot::D_METHOD("get_scale_last"), &OcctlPrimPipeShellLinearLawInfo::get_scale_last);
    godot::ClassDB::bind_method(godot::D_METHOD("set_scale_last", "val"), &OcctlPrimPipeShellLinearLawInfo::set_scale_last);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "scale_last"), "set_scale_last", "get_scale_last");
    godot::ClassDB::bind_method(godot::D_METHOD("get_mode"), &OcctlPrimPipeShellLinearLawInfo::get_mode);
    godot::ClassDB::bind_method(godot::D_METHOD("set_mode", "val"), &OcctlPrimPipeShellLinearLawInfo::set_mode);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "mode"), "set_mode", "get_mode");
    godot::ClassDB::bind_method(godot::D_METHOD("get_mode_axis"), &OcctlPrimPipeShellLinearLawInfo::get_mode_axis);
    godot::ClassDB::bind_method(godot::D_METHOD("set_mode_axis", "val"), &OcctlPrimPipeShellLinearLawInfo::set_mode_axis);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "mode_axis"), "set_mode_axis", "get_mode_axis");
    godot::ClassDB::bind_method(godot::D_METHOD("get_mode_binormal"), &OcctlPrimPipeShellLinearLawInfo::get_mode_binormal);
    godot::ClassDB::bind_method(godot::D_METHOD("set_mode_binormal", "val"), &OcctlPrimPipeShellLinearLawInfo::set_mode_binormal);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "mode_binormal"), "set_mode_binormal", "get_mode_binormal");
    godot::ClassDB::bind_method(godot::D_METHOD("get_transition"), &OcctlPrimPipeShellLinearLawInfo::get_transition);
    godot::ClassDB::bind_method(godot::D_METHOD("set_transition", "val"), &OcctlPrimPipeShellLinearLawInfo::set_transition);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "transition"), "set_transition", "get_transition");
    godot::ClassDB::bind_method(godot::D_METHOD("get_with_contact"), &OcctlPrimPipeShellLinearLawInfo::get_with_contact);
    godot::ClassDB::bind_method(godot::D_METHOD("set_with_contact", "val"), &OcctlPrimPipeShellLinearLawInfo::set_with_contact);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "with_contact"), "set_with_contact", "get_with_contact");
    godot::ClassDB::bind_method(godot::D_METHOD("get_with_correction"), &OcctlPrimPipeShellLinearLawInfo::get_with_correction);
    godot::ClassDB::bind_method(godot::D_METHOD("set_with_correction", "val"), &OcctlPrimPipeShellLinearLawInfo::set_with_correction);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "with_correction"), "set_with_correction", "get_with_correction");
    godot::ClassDB::bind_method(godot::D_METHOD("get_make_solid"), &OcctlPrimPipeShellLinearLawInfo::get_make_solid);
    godot::ClassDB::bind_method(godot::D_METHOD("set_make_solid", "val"), &OcctlPrimPipeShellLinearLawInfo::set_make_solid);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "make_solid"), "set_make_solid", "get_make_solid");
}

occtl_prim_pipe_shell_linear_law_info_t OcctlPrimPipeShellLinearLawInfo::to_c() const {
    occtl_prim_pipe_shell_linear_law_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.spine_wire.bits = static_cast<uint64_t>(spine_wire);
    result.profile.bits = static_cast<uint64_t>(profile);
    result.scale_first = scale_first;
    result.scale_last = scale_last;
    result.mode = static_cast<occtl_prim_pipe_mode_t>(mode);
    result.mode_axis = mode_axis->to_c();
    result.mode_binormal = mode_binormal->to_c();
    result.transition = static_cast<occtl_prim_pipe_transition_t>(transition);
    result.with_contact = with_contact;
    result.with_correction = with_correction;
    result.make_solid = make_solid;
    return result;
}

Ref<OcctlPrimPipeShellLinearLawInfo> OcctlPrimPipeShellLinearLawInfo::from_c(const occtl_prim_pipe_shell_linear_law_info_t& val) {
    Ref<OcctlPrimPipeShellLinearLawInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->spine_wire = static_cast<int64_t>(val.spine_wire.bits);
    r->profile = static_cast<int64_t>(val.profile.bits);
    r->scale_first = val.scale_first;
    r->scale_last = val.scale_last;
    r->mode = static_cast<int>(val.mode);
    r->mode_axis = OcctlAxis2Placement::from_c(val.mode_axis);
    r->mode_binormal = OcctlDirection3::from_c(val.mode_binormal);
    r->transition = static_cast<int>(val.transition);
    r->with_contact = val.with_contact;
    r->with_correction = val.with_correction;
    r->make_solid = val.make_solid;
    return r;
}

void OcctlPrimPipeShellLinearLawInfo::copy_from_c(const occtl_prim_pipe_shell_linear_law_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    spine_wire = static_cast<int64_t>(val.spine_wire.bits);
    profile = static_cast<int64_t>(val.profile.bits);
    scale_first = val.scale_first;
    scale_last = val.scale_last;
    mode = static_cast<int>(val.mode);
    mode_axis = OcctlAxis2Placement::from_c(val.mode_axis);
    mode_binormal = OcctlDirection3::from_c(val.mode_binormal);
    transition = static_cast<int>(val.transition);
    with_contact = val.with_contact;
    with_correction = val.with_correction;
    make_solid = val.make_solid;
}
