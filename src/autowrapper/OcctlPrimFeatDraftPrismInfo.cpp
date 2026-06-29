#include "OcctlPrimFeatDraftPrismInfo.h"

#include "OcctlNodeId.h"

int OcctlPrimFeatDraftPrismInfo::get_struct_version() const { return struct_version; }
void OcctlPrimFeatDraftPrismInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimFeatDraftPrismInfo::get_p_next() const { return p_next; }
void OcctlPrimFeatDraftPrismInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlPrimFeatDraftPrismInfo::get_base_shape() const { return base_shape; }
void OcctlPrimFeatDraftPrismInfo::set_base_shape(int64_t val) { base_shape = val; }

int64_t OcctlPrimFeatDraftPrismInfo::get_profile_face() const { return profile_face; }
void OcctlPrimFeatDraftPrismInfo::set_profile_face(int64_t val) { profile_face = val; }

int64_t OcctlPrimFeatDraftPrismInfo::get_sketch_face() const { return sketch_face; }
void OcctlPrimFeatDraftPrismInfo::set_sketch_face(int64_t val) { sketch_face = val; }

double OcctlPrimFeatDraftPrismInfo::get_taper_angle() const { return taper_angle; }
void OcctlPrimFeatDraftPrismInfo::set_taper_angle(double val) { taper_angle = val; }

int OcctlPrimFeatDraftPrismInfo::get_combine() const { return combine; }
void OcctlPrimFeatDraftPrismInfo::set_combine(int val) { combine = val; }

int OcctlPrimFeatDraftPrismInfo::get_modify() const { return modify; }
void OcctlPrimFeatDraftPrismInfo::set_modify(int val) { modify = val; }

int OcctlPrimFeatDraftPrismInfo::get_until_kind() const { return until_kind; }
void OcctlPrimFeatDraftPrismInfo::set_until_kind(int val) { until_kind = val; }

int64_t OcctlPrimFeatDraftPrismInfo::get_until_shape() const { return until_shape; }
void OcctlPrimFeatDraftPrismInfo::set_until_shape(int64_t val) { until_shape = val; }

double OcctlPrimFeatDraftPrismInfo::get_length() const { return length; }
void OcctlPrimFeatDraftPrismInfo::set_length(double val) { length = val; }

void OcctlPrimFeatDraftPrismInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimFeatDraftPrismInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimFeatDraftPrismInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimFeatDraftPrismInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimFeatDraftPrismInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_base_shape"), &OcctlPrimFeatDraftPrismInfo::get_base_shape);
    godot::ClassDB::bind_method(godot::D_METHOD("set_base_shape", "val"), &OcctlPrimFeatDraftPrismInfo::set_base_shape);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "base_shape"), "set_base_shape", "get_base_shape");
    godot::ClassDB::bind_method(godot::D_METHOD("get_profile_face"), &OcctlPrimFeatDraftPrismInfo::get_profile_face);
    godot::ClassDB::bind_method(godot::D_METHOD("set_profile_face", "val"), &OcctlPrimFeatDraftPrismInfo::set_profile_face);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "profile_face"), "set_profile_face", "get_profile_face");
    godot::ClassDB::bind_method(godot::D_METHOD("get_sketch_face"), &OcctlPrimFeatDraftPrismInfo::get_sketch_face);
    godot::ClassDB::bind_method(godot::D_METHOD("set_sketch_face", "val"), &OcctlPrimFeatDraftPrismInfo::set_sketch_face);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "sketch_face"), "set_sketch_face", "get_sketch_face");
    godot::ClassDB::bind_method(godot::D_METHOD("get_taper_angle"), &OcctlPrimFeatDraftPrismInfo::get_taper_angle);
    godot::ClassDB::bind_method(godot::D_METHOD("set_taper_angle", "val"), &OcctlPrimFeatDraftPrismInfo::set_taper_angle);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "taper_angle"), "set_taper_angle", "get_taper_angle");
    godot::ClassDB::bind_method(godot::D_METHOD("get_combine"), &OcctlPrimFeatDraftPrismInfo::get_combine);
    godot::ClassDB::bind_method(godot::D_METHOD("set_combine", "val"), &OcctlPrimFeatDraftPrismInfo::set_combine);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "combine"), "set_combine", "get_combine");
    godot::ClassDB::bind_method(godot::D_METHOD("get_modify"), &OcctlPrimFeatDraftPrismInfo::get_modify);
    godot::ClassDB::bind_method(godot::D_METHOD("set_modify", "val"), &OcctlPrimFeatDraftPrismInfo::set_modify);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "modify"), "set_modify", "get_modify");
    godot::ClassDB::bind_method(godot::D_METHOD("get_until_kind"), &OcctlPrimFeatDraftPrismInfo::get_until_kind);
    godot::ClassDB::bind_method(godot::D_METHOD("set_until_kind", "val"), &OcctlPrimFeatDraftPrismInfo::set_until_kind);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "until_kind"), "set_until_kind", "get_until_kind");
    godot::ClassDB::bind_method(godot::D_METHOD("get_until_shape"), &OcctlPrimFeatDraftPrismInfo::get_until_shape);
    godot::ClassDB::bind_method(godot::D_METHOD("set_until_shape", "val"), &OcctlPrimFeatDraftPrismInfo::set_until_shape);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "until_shape"), "set_until_shape", "get_until_shape");
    godot::ClassDB::bind_method(godot::D_METHOD("get_length"), &OcctlPrimFeatDraftPrismInfo::get_length);
    godot::ClassDB::bind_method(godot::D_METHOD("set_length", "val"), &OcctlPrimFeatDraftPrismInfo::set_length);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "length"), "set_length", "get_length");
}

occtl_prim_feat_draft_prism_info_t OcctlPrimFeatDraftPrismInfo::to_c() const {
    occtl_prim_feat_draft_prism_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.base_shape.bits = static_cast<uint64_t>(base_shape);
    result.profile_face.bits = static_cast<uint64_t>(profile_face);
    result.sketch_face.bits = static_cast<uint64_t>(sketch_face);
    result.taper_angle = taper_angle;
    result.combine = static_cast<occtl_prim_feat_combine_t>(combine);
    result.modify = modify;
    result.until_kind = static_cast<occtl_prim_until_kind_t>(until_kind);
    result.until_shape.bits = static_cast<uint64_t>(until_shape);
    result.length = length;
    return result;
}

Ref<OcctlPrimFeatDraftPrismInfo> OcctlPrimFeatDraftPrismInfo::from_c(const occtl_prim_feat_draft_prism_info_t& val) {
    Ref<OcctlPrimFeatDraftPrismInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->base_shape = static_cast<int64_t>(val.base_shape.bits);
    r->profile_face = static_cast<int64_t>(val.profile_face.bits);
    r->sketch_face = static_cast<int64_t>(val.sketch_face.bits);
    r->taper_angle = val.taper_angle;
    r->combine = static_cast<int>(val.combine);
    r->modify = val.modify;
    r->until_kind = static_cast<int>(val.until_kind);
    r->until_shape = static_cast<int64_t>(val.until_shape.bits);
    r->length = val.length;
    return r;
}

void OcctlPrimFeatDraftPrismInfo::copy_from_c(const occtl_prim_feat_draft_prism_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    base_shape = static_cast<int64_t>(val.base_shape.bits);
    profile_face = static_cast<int64_t>(val.profile_face.bits);
    sketch_face = static_cast<int64_t>(val.sketch_face.bits);
    taper_angle = val.taper_angle;
    combine = static_cast<int>(val.combine);
    modify = val.modify;
    until_kind = static_cast<int>(val.until_kind);
    until_shape = static_cast<int64_t>(val.until_shape.bits);
    length = val.length;
}
