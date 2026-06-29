#include "OcctlPrimFeatPrismInfo.h"

#include "OcctlNodeId.h"
#include "OcctlDirection3.h"

int OcctlPrimFeatPrismInfo::get_struct_version() const { return struct_version; }
void OcctlPrimFeatPrismInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimFeatPrismInfo::get_p_next() const { return p_next; }
void OcctlPrimFeatPrismInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlPrimFeatPrismInfo::get_base_shape() const { return base_shape; }
void OcctlPrimFeatPrismInfo::set_base_shape(int64_t val) { base_shape = val; }

int64_t OcctlPrimFeatPrismInfo::get_profile() const { return profile; }
void OcctlPrimFeatPrismInfo::set_profile(int64_t val) { profile = val; }

int64_t OcctlPrimFeatPrismInfo::get_sketch_face() const { return sketch_face; }
void OcctlPrimFeatPrismInfo::set_sketch_face(int64_t val) { sketch_face = val; }

Ref<OcctlDirection3> OcctlPrimFeatPrismInfo::get_direction() const { return direction; }
void OcctlPrimFeatPrismInfo::set_direction(Ref<OcctlDirection3> val) { direction = val; }

int OcctlPrimFeatPrismInfo::get_combine() const { return combine; }
void OcctlPrimFeatPrismInfo::set_combine(int val) { combine = val; }

int OcctlPrimFeatPrismInfo::get_modify() const { return modify; }
void OcctlPrimFeatPrismInfo::set_modify(int val) { modify = val; }

int OcctlPrimFeatPrismInfo::get_until_kind() const { return until_kind; }
void OcctlPrimFeatPrismInfo::set_until_kind(int val) { until_kind = val; }

int64_t OcctlPrimFeatPrismInfo::get_until_shape() const { return until_shape; }
void OcctlPrimFeatPrismInfo::set_until_shape(int64_t val) { until_shape = val; }

double OcctlPrimFeatPrismInfo::get_length() const { return length; }
void OcctlPrimFeatPrismInfo::set_length(double val) { length = val; }

void OcctlPrimFeatPrismInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimFeatPrismInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimFeatPrismInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimFeatPrismInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimFeatPrismInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_base_shape"), &OcctlPrimFeatPrismInfo::get_base_shape);
    godot::ClassDB::bind_method(godot::D_METHOD("set_base_shape", "val"), &OcctlPrimFeatPrismInfo::set_base_shape);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "base_shape"), "set_base_shape", "get_base_shape");
    godot::ClassDB::bind_method(godot::D_METHOD("get_profile"), &OcctlPrimFeatPrismInfo::get_profile);
    godot::ClassDB::bind_method(godot::D_METHOD("set_profile", "val"), &OcctlPrimFeatPrismInfo::set_profile);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "profile"), "set_profile", "get_profile");
    godot::ClassDB::bind_method(godot::D_METHOD("get_sketch_face"), &OcctlPrimFeatPrismInfo::get_sketch_face);
    godot::ClassDB::bind_method(godot::D_METHOD("set_sketch_face", "val"), &OcctlPrimFeatPrismInfo::set_sketch_face);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "sketch_face"), "set_sketch_face", "get_sketch_face");
    godot::ClassDB::bind_method(godot::D_METHOD("get_direction"), &OcctlPrimFeatPrismInfo::get_direction);
    godot::ClassDB::bind_method(godot::D_METHOD("set_direction", "val"), &OcctlPrimFeatPrismInfo::set_direction);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "direction"), "set_direction", "get_direction");
    godot::ClassDB::bind_method(godot::D_METHOD("get_combine"), &OcctlPrimFeatPrismInfo::get_combine);
    godot::ClassDB::bind_method(godot::D_METHOD("set_combine", "val"), &OcctlPrimFeatPrismInfo::set_combine);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "combine"), "set_combine", "get_combine");
    godot::ClassDB::bind_method(godot::D_METHOD("get_modify"), &OcctlPrimFeatPrismInfo::get_modify);
    godot::ClassDB::bind_method(godot::D_METHOD("set_modify", "val"), &OcctlPrimFeatPrismInfo::set_modify);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "modify"), "set_modify", "get_modify");
    godot::ClassDB::bind_method(godot::D_METHOD("get_until_kind"), &OcctlPrimFeatPrismInfo::get_until_kind);
    godot::ClassDB::bind_method(godot::D_METHOD("set_until_kind", "val"), &OcctlPrimFeatPrismInfo::set_until_kind);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "until_kind"), "set_until_kind", "get_until_kind");
    godot::ClassDB::bind_method(godot::D_METHOD("get_until_shape"), &OcctlPrimFeatPrismInfo::get_until_shape);
    godot::ClassDB::bind_method(godot::D_METHOD("set_until_shape", "val"), &OcctlPrimFeatPrismInfo::set_until_shape);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "until_shape"), "set_until_shape", "get_until_shape");
    godot::ClassDB::bind_method(godot::D_METHOD("get_length"), &OcctlPrimFeatPrismInfo::get_length);
    godot::ClassDB::bind_method(godot::D_METHOD("set_length", "val"), &OcctlPrimFeatPrismInfo::set_length);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "length"), "set_length", "get_length");
}

occtl_prim_feat_prism_info_t OcctlPrimFeatPrismInfo::to_c() const {
    occtl_prim_feat_prism_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.base_shape.bits = static_cast<uint64_t>(base_shape);
    result.profile.bits = static_cast<uint64_t>(profile);
    result.sketch_face.bits = static_cast<uint64_t>(sketch_face);
    result.direction = direction->to_c();
    result.combine = static_cast<occtl_prim_feat_combine_t>(combine);
    result.modify = modify;
    result.until_kind = static_cast<occtl_prim_until_kind_t>(until_kind);
    result.until_shape.bits = static_cast<uint64_t>(until_shape);
    result.length = length;
    return result;
}

Ref<OcctlPrimFeatPrismInfo> OcctlPrimFeatPrismInfo::from_c(const occtl_prim_feat_prism_info_t& val) {
    Ref<OcctlPrimFeatPrismInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->base_shape = static_cast<int64_t>(val.base_shape.bits);
    r->profile = static_cast<int64_t>(val.profile.bits);
    r->sketch_face = static_cast<int64_t>(val.sketch_face.bits);
    r->direction = OcctlDirection3::from_c(val.direction);
    r->combine = static_cast<int>(val.combine);
    r->modify = val.modify;
    r->until_kind = static_cast<int>(val.until_kind);
    r->until_shape = static_cast<int64_t>(val.until_shape.bits);
    r->length = val.length;
    return r;
}

void OcctlPrimFeatPrismInfo::copy_from_c(const occtl_prim_feat_prism_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    base_shape = static_cast<int64_t>(val.base_shape.bits);
    profile = static_cast<int64_t>(val.profile.bits);
    sketch_face = static_cast<int64_t>(val.sketch_face.bits);
    direction = OcctlDirection3::from_c(val.direction);
    combine = static_cast<int>(val.combine);
    modify = val.modify;
    until_kind = static_cast<int>(val.until_kind);
    until_shape = static_cast<int64_t>(val.until_shape.bits);
    length = val.length;
}
