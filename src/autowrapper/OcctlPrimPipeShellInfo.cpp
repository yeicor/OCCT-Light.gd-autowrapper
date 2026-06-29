#include "OcctlPrimPipeShellInfo.h"

#include "OcctlNodeId.h"
#include "OcctlAxis2Placement.h"
#include "OcctlDirection3.h"

int OcctlPrimPipeShellInfo::get_struct_version() const { return struct_version; }
void OcctlPrimPipeShellInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimPipeShellInfo::get_p_next() const { return p_next; }
void OcctlPrimPipeShellInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlPrimPipeShellInfo::get_spine_wire() const { return spine_wire; }
void OcctlPrimPipeShellInfo::set_spine_wire(int64_t val) { spine_wire = val; }

PackedInt64Array OcctlPrimPipeShellInfo::get_profiles() const { return profiles; }
void OcctlPrimPipeShellInfo::set_profiles(PackedInt64Array val) { profiles = val; }

int OcctlPrimPipeShellInfo::get_profile_count() const { return profile_count; }
void OcctlPrimPipeShellInfo::set_profile_count(int val) { profile_count = val; }

int OcctlPrimPipeShellInfo::get_mode() const { return mode; }
void OcctlPrimPipeShellInfo::set_mode(int val) { mode = val; }

Ref<OcctlAxis2Placement> OcctlPrimPipeShellInfo::get_mode_axis() const { return mode_axis; }
void OcctlPrimPipeShellInfo::set_mode_axis(Ref<OcctlAxis2Placement> val) { mode_axis = val; }

Ref<OcctlDirection3> OcctlPrimPipeShellInfo::get_mode_binormal() const { return mode_binormal; }
void OcctlPrimPipeShellInfo::set_mode_binormal(Ref<OcctlDirection3> val) { mode_binormal = val; }

int OcctlPrimPipeShellInfo::get_transition() const { return transition; }
void OcctlPrimPipeShellInfo::set_transition(int val) { transition = val; }

int OcctlPrimPipeShellInfo::get_with_contact() const { return with_contact; }
void OcctlPrimPipeShellInfo::set_with_contact(int val) { with_contact = val; }

int OcctlPrimPipeShellInfo::get_with_correction() const { return with_correction; }
void OcctlPrimPipeShellInfo::set_with_correction(int val) { with_correction = val; }

int OcctlPrimPipeShellInfo::get_make_solid() const { return make_solid; }
void OcctlPrimPipeShellInfo::set_make_solid(int val) { make_solid = val; }

void OcctlPrimPipeShellInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimPipeShellInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimPipeShellInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimPipeShellInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimPipeShellInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_spine_wire"), &OcctlPrimPipeShellInfo::get_spine_wire);
    godot::ClassDB::bind_method(godot::D_METHOD("set_spine_wire", "val"), &OcctlPrimPipeShellInfo::set_spine_wire);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "spine_wire"), "set_spine_wire", "get_spine_wire");
    godot::ClassDB::bind_method(godot::D_METHOD("get_profiles"), &OcctlPrimPipeShellInfo::get_profiles);
    godot::ClassDB::bind_method(godot::D_METHOD("set_profiles", "val"), &OcctlPrimPipeShellInfo::set_profiles);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "profiles"), "set_profiles", "get_profiles");
    godot::ClassDB::bind_method(godot::D_METHOD("get_profile_count"), &OcctlPrimPipeShellInfo::get_profile_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_profile_count", "val"), &OcctlPrimPipeShellInfo::set_profile_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "profile_count"), "set_profile_count", "get_profile_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_mode"), &OcctlPrimPipeShellInfo::get_mode);
    godot::ClassDB::bind_method(godot::D_METHOD("set_mode", "val"), &OcctlPrimPipeShellInfo::set_mode);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "mode"), "set_mode", "get_mode");
    godot::ClassDB::bind_method(godot::D_METHOD("get_mode_axis"), &OcctlPrimPipeShellInfo::get_mode_axis);
    godot::ClassDB::bind_method(godot::D_METHOD("set_mode_axis", "val"), &OcctlPrimPipeShellInfo::set_mode_axis);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "mode_axis"), "set_mode_axis", "get_mode_axis");
    godot::ClassDB::bind_method(godot::D_METHOD("get_mode_binormal"), &OcctlPrimPipeShellInfo::get_mode_binormal);
    godot::ClassDB::bind_method(godot::D_METHOD("set_mode_binormal", "val"), &OcctlPrimPipeShellInfo::set_mode_binormal);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "mode_binormal"), "set_mode_binormal", "get_mode_binormal");
    godot::ClassDB::bind_method(godot::D_METHOD("get_transition"), &OcctlPrimPipeShellInfo::get_transition);
    godot::ClassDB::bind_method(godot::D_METHOD("set_transition", "val"), &OcctlPrimPipeShellInfo::set_transition);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "transition"), "set_transition", "get_transition");
    godot::ClassDB::bind_method(godot::D_METHOD("get_with_contact"), &OcctlPrimPipeShellInfo::get_with_contact);
    godot::ClassDB::bind_method(godot::D_METHOD("set_with_contact", "val"), &OcctlPrimPipeShellInfo::set_with_contact);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "with_contact"), "set_with_contact", "get_with_contact");
    godot::ClassDB::bind_method(godot::D_METHOD("get_with_correction"), &OcctlPrimPipeShellInfo::get_with_correction);
    godot::ClassDB::bind_method(godot::D_METHOD("set_with_correction", "val"), &OcctlPrimPipeShellInfo::set_with_correction);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "with_correction"), "set_with_correction", "get_with_correction");
    godot::ClassDB::bind_method(godot::D_METHOD("get_make_solid"), &OcctlPrimPipeShellInfo::get_make_solid);
    godot::ClassDB::bind_method(godot::D_METHOD("set_make_solid", "val"), &OcctlPrimPipeShellInfo::set_make_solid);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "make_solid"), "set_make_solid", "get_make_solid");
}

occtl_prim_pipe_shell_info_t OcctlPrimPipeShellInfo::to_c() const {
    occtl_prim_pipe_shell_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.spine_wire.bits = static_cast<uint64_t>(spine_wire);
    result.profiles = reinterpret_cast<const occtl_node_id_t*>(profiles.ptr());
    result.profile_count = profile_count;
    result.mode = static_cast<occtl_prim_pipe_mode_t>(mode);
    result.mode_axis = mode_axis->to_c();
    result.mode_binormal = mode_binormal->to_c();
    result.transition = static_cast<occtl_prim_pipe_transition_t>(transition);
    result.with_contact = with_contact;
    result.with_correction = with_correction;
    result.make_solid = make_solid;
    return result;
}

Ref<OcctlPrimPipeShellInfo> OcctlPrimPipeShellInfo::from_c(const occtl_prim_pipe_shell_info_t& val) {
    Ref<OcctlPrimPipeShellInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->spine_wire = static_cast<int64_t>(val.spine_wire.bits);
    // array field profiles is not populated from C
    r->profile_count = val.profile_count;
    r->mode = static_cast<int>(val.mode);
    r->mode_axis = OcctlAxis2Placement::from_c(val.mode_axis);
    r->mode_binormal = OcctlDirection3::from_c(val.mode_binormal);
    r->transition = static_cast<int>(val.transition);
    r->with_contact = val.with_contact;
    r->with_correction = val.with_correction;
    r->make_solid = val.make_solid;
    return r;
}

void OcctlPrimPipeShellInfo::copy_from_c(const occtl_prim_pipe_shell_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    spine_wire = static_cast<int64_t>(val.spine_wire.bits);
    // array field profiles is not populated from C
    profile_count = val.profile_count;
    mode = static_cast<int>(val.mode);
    mode_axis = OcctlAxis2Placement::from_c(val.mode_axis);
    mode_binormal = OcctlDirection3::from_c(val.mode_binormal);
    transition = static_cast<int>(val.transition);
    with_contact = val.with_contact;
    with_correction = val.with_correction;
    make_solid = val.make_solid;
}
