#include "OcctlPrimPipeShellInterpolatedLawInfo.h"

#include "OcctlNodeId.h"
#include "OcctlAxis2Placement.h"
#include "OcctlDirection3.h"

int OcctlPrimPipeShellInterpolatedLawInfo::get_struct_version() const { return struct_version; }
void OcctlPrimPipeShellInterpolatedLawInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimPipeShellInterpolatedLawInfo::get_p_next() const { return p_next; }
void OcctlPrimPipeShellInterpolatedLawInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlPrimPipeShellInterpolatedLawInfo::get_spine_wire() const { return spine_wire; }
void OcctlPrimPipeShellInterpolatedLawInfo::set_spine_wire(int64_t val) { spine_wire = val; }

int64_t OcctlPrimPipeShellInterpolatedLawInfo::get_profile() const { return profile; }
void OcctlPrimPipeShellInterpolatedLawInfo::set_profile(int64_t val) { profile = val; }

PackedFloat64Array OcctlPrimPipeShellInterpolatedLawInfo::get_parameters() const { return parameters; }
void OcctlPrimPipeShellInterpolatedLawInfo::set_parameters(PackedFloat64Array val) { parameters = val; }

PackedFloat64Array OcctlPrimPipeShellInterpolatedLawInfo::get_scales() const { return scales; }
void OcctlPrimPipeShellInterpolatedLawInfo::set_scales(PackedFloat64Array val) { scales = val; }

int OcctlPrimPipeShellInterpolatedLawInfo::get_sample_count() const { return sample_count; }
void OcctlPrimPipeShellInterpolatedLawInfo::set_sample_count(int val) { sample_count = val; }

int OcctlPrimPipeShellInterpolatedLawInfo::get_mode() const { return mode; }
void OcctlPrimPipeShellInterpolatedLawInfo::set_mode(int val) { mode = val; }

Ref<OcctlAxis2Placement> OcctlPrimPipeShellInterpolatedLawInfo::get_mode_axis() const { return mode_axis; }
void OcctlPrimPipeShellInterpolatedLawInfo::set_mode_axis(Ref<OcctlAxis2Placement> val) { mode_axis = val; }

Ref<OcctlDirection3> OcctlPrimPipeShellInterpolatedLawInfo::get_mode_binormal() const { return mode_binormal; }
void OcctlPrimPipeShellInterpolatedLawInfo::set_mode_binormal(Ref<OcctlDirection3> val) { mode_binormal = val; }

int OcctlPrimPipeShellInterpolatedLawInfo::get_transition() const { return transition; }
void OcctlPrimPipeShellInterpolatedLawInfo::set_transition(int val) { transition = val; }

int OcctlPrimPipeShellInterpolatedLawInfo::get_with_contact() const { return with_contact; }
void OcctlPrimPipeShellInterpolatedLawInfo::set_with_contact(int val) { with_contact = val; }

int OcctlPrimPipeShellInterpolatedLawInfo::get_with_correction() const { return with_correction; }
void OcctlPrimPipeShellInterpolatedLawInfo::set_with_correction(int val) { with_correction = val; }

int OcctlPrimPipeShellInterpolatedLawInfo::get_make_solid() const { return make_solid; }
void OcctlPrimPipeShellInterpolatedLawInfo::set_make_solid(int val) { make_solid = val; }

void OcctlPrimPipeShellInterpolatedLawInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimPipeShellInterpolatedLawInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimPipeShellInterpolatedLawInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimPipeShellInterpolatedLawInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimPipeShellInterpolatedLawInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_spine_wire"), &OcctlPrimPipeShellInterpolatedLawInfo::get_spine_wire);
    godot::ClassDB::bind_method(godot::D_METHOD("set_spine_wire", "val"), &OcctlPrimPipeShellInterpolatedLawInfo::set_spine_wire);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "spine_wire"), "set_spine_wire", "get_spine_wire");
    godot::ClassDB::bind_method(godot::D_METHOD("get_profile"), &OcctlPrimPipeShellInterpolatedLawInfo::get_profile);
    godot::ClassDB::bind_method(godot::D_METHOD("set_profile", "val"), &OcctlPrimPipeShellInterpolatedLawInfo::set_profile);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "profile"), "set_profile", "get_profile");
    godot::ClassDB::bind_method(godot::D_METHOD("get_parameters"), &OcctlPrimPipeShellInterpolatedLawInfo::get_parameters);
    godot::ClassDB::bind_method(godot::D_METHOD("set_parameters", "val"), &OcctlPrimPipeShellInterpolatedLawInfo::set_parameters);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "parameters"), "set_parameters", "get_parameters");
    godot::ClassDB::bind_method(godot::D_METHOD("get_scales"), &OcctlPrimPipeShellInterpolatedLawInfo::get_scales);
    godot::ClassDB::bind_method(godot::D_METHOD("set_scales", "val"), &OcctlPrimPipeShellInterpolatedLawInfo::set_scales);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "scales"), "set_scales", "get_scales");
    godot::ClassDB::bind_method(godot::D_METHOD("get_sample_count"), &OcctlPrimPipeShellInterpolatedLawInfo::get_sample_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_sample_count", "val"), &OcctlPrimPipeShellInterpolatedLawInfo::set_sample_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "sample_count"), "set_sample_count", "get_sample_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_mode"), &OcctlPrimPipeShellInterpolatedLawInfo::get_mode);
    godot::ClassDB::bind_method(godot::D_METHOD("set_mode", "val"), &OcctlPrimPipeShellInterpolatedLawInfo::set_mode);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "mode"), "set_mode", "get_mode");
    godot::ClassDB::bind_method(godot::D_METHOD("get_mode_axis"), &OcctlPrimPipeShellInterpolatedLawInfo::get_mode_axis);
    godot::ClassDB::bind_method(godot::D_METHOD("set_mode_axis", "val"), &OcctlPrimPipeShellInterpolatedLawInfo::set_mode_axis);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "mode_axis"), "set_mode_axis", "get_mode_axis");
    godot::ClassDB::bind_method(godot::D_METHOD("get_mode_binormal"), &OcctlPrimPipeShellInterpolatedLawInfo::get_mode_binormal);
    godot::ClassDB::bind_method(godot::D_METHOD("set_mode_binormal", "val"), &OcctlPrimPipeShellInterpolatedLawInfo::set_mode_binormal);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "mode_binormal"), "set_mode_binormal", "get_mode_binormal");
    godot::ClassDB::bind_method(godot::D_METHOD("get_transition"), &OcctlPrimPipeShellInterpolatedLawInfo::get_transition);
    godot::ClassDB::bind_method(godot::D_METHOD("set_transition", "val"), &OcctlPrimPipeShellInterpolatedLawInfo::set_transition);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "transition"), "set_transition", "get_transition");
    godot::ClassDB::bind_method(godot::D_METHOD("get_with_contact"), &OcctlPrimPipeShellInterpolatedLawInfo::get_with_contact);
    godot::ClassDB::bind_method(godot::D_METHOD("set_with_contact", "val"), &OcctlPrimPipeShellInterpolatedLawInfo::set_with_contact);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "with_contact"), "set_with_contact", "get_with_contact");
    godot::ClassDB::bind_method(godot::D_METHOD("get_with_correction"), &OcctlPrimPipeShellInterpolatedLawInfo::get_with_correction);
    godot::ClassDB::bind_method(godot::D_METHOD("set_with_correction", "val"), &OcctlPrimPipeShellInterpolatedLawInfo::set_with_correction);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "with_correction"), "set_with_correction", "get_with_correction");
    godot::ClassDB::bind_method(godot::D_METHOD("get_make_solid"), &OcctlPrimPipeShellInterpolatedLawInfo::get_make_solid);
    godot::ClassDB::bind_method(godot::D_METHOD("set_make_solid", "val"), &OcctlPrimPipeShellInterpolatedLawInfo::set_make_solid);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "make_solid"), "set_make_solid", "get_make_solid");
}

occtl_prim_pipe_shell_interpolated_law_info_t OcctlPrimPipeShellInterpolatedLawInfo::to_c() const {
    occtl_prim_pipe_shell_interpolated_law_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.spine_wire.bits = static_cast<uint64_t>(spine_wire);
    result.profile.bits = static_cast<uint64_t>(profile);
    result.parameters = parameters.ptr();
    result.scales = scales.ptr();
    result.sample_count = sample_count;
    result.mode = static_cast<occtl_prim_pipe_mode_t>(mode);
    result.mode_axis = mode_axis->to_c();
    result.mode_binormal = mode_binormal->to_c();
    result.transition = static_cast<occtl_prim_pipe_transition_t>(transition);
    result.with_contact = with_contact;
    result.with_correction = with_correction;
    result.make_solid = make_solid;
    return result;
}

Ref<OcctlPrimPipeShellInterpolatedLawInfo> OcctlPrimPipeShellInterpolatedLawInfo::from_c(const occtl_prim_pipe_shell_interpolated_law_info_t& val) {
    Ref<OcctlPrimPipeShellInterpolatedLawInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->spine_wire = static_cast<int64_t>(val.spine_wire.bits);
    r->profile = static_cast<int64_t>(val.profile.bits);
    // array field parameters is not populated from C
    // array field scales is not populated from C
    r->sample_count = val.sample_count;
    r->mode = static_cast<int>(val.mode);
    r->mode_axis = OcctlAxis2Placement::from_c(val.mode_axis);
    r->mode_binormal = OcctlDirection3::from_c(val.mode_binormal);
    r->transition = static_cast<int>(val.transition);
    r->with_contact = val.with_contact;
    r->with_correction = val.with_correction;
    r->make_solid = val.make_solid;
    return r;
}

void OcctlPrimPipeShellInterpolatedLawInfo::copy_from_c(const occtl_prim_pipe_shell_interpolated_law_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    spine_wire = static_cast<int64_t>(val.spine_wire.bits);
    profile = static_cast<int64_t>(val.profile.bits);
    // array field parameters is not populated from C
    // array field scales is not populated from C
    sample_count = val.sample_count;
    mode = static_cast<int>(val.mode);
    mode_axis = OcctlAxis2Placement::from_c(val.mode_axis);
    mode_binormal = OcctlDirection3::from_c(val.mode_binormal);
    transition = static_cast<int>(val.transition);
    with_contact = val.with_contact;
    with_correction = val.with_correction;
    make_solid = val.make_solid;
}
