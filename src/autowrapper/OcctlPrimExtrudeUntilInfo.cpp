#include "OcctlPrimExtrudeUntilInfo.h"

#include "OcctlNodeId.h"
#include "OcctlDirection3.h"

int OcctlPrimExtrudeUntilInfo::get_struct_version() const { return struct_version; }
void OcctlPrimExtrudeUntilInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimExtrudeUntilInfo::get_p_next() const { return p_next; }
void OcctlPrimExtrudeUntilInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlPrimExtrudeUntilInfo::get_base_shape() const { return base_shape; }
void OcctlPrimExtrudeUntilInfo::set_base_shape(int64_t val) { base_shape = val; }

int64_t OcctlPrimExtrudeUntilInfo::get_profile() const { return profile; }
void OcctlPrimExtrudeUntilInfo::set_profile(int64_t val) { profile = val; }

int64_t OcctlPrimExtrudeUntilInfo::get_sketch_face() const { return sketch_face; }
void OcctlPrimExtrudeUntilInfo::set_sketch_face(int64_t val) { sketch_face = val; }

int64_t OcctlPrimExtrudeUntilInfo::get_target_shape() const { return target_shape; }
void OcctlPrimExtrudeUntilInfo::set_target_shape(int64_t val) { target_shape = val; }

Ref<OcctlDirection3> OcctlPrimExtrudeUntilInfo::get_direction() const { return direction; }
void OcctlPrimExtrudeUntilInfo::set_direction(Ref<OcctlDirection3> val) { direction = val; }

int OcctlPrimExtrudeUntilInfo::get_side() const { return side; }
void OcctlPrimExtrudeUntilInfo::set_side(int val) { side = val; }

int OcctlPrimExtrudeUntilInfo::get_combine() const { return combine; }
void OcctlPrimExtrudeUntilInfo::set_combine(int val) { combine = val; }

int OcctlPrimExtrudeUntilInfo::get_modify() const { return modify; }
void OcctlPrimExtrudeUntilInfo::set_modify(int val) { modify = val; }

double OcctlPrimExtrudeUntilInfo::get_limit() const { return limit; }
void OcctlPrimExtrudeUntilInfo::set_limit(double val) { limit = val; }

void OcctlPrimExtrudeUntilInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimExtrudeUntilInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimExtrudeUntilInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimExtrudeUntilInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimExtrudeUntilInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_base_shape"), &OcctlPrimExtrudeUntilInfo::get_base_shape);
    godot::ClassDB::bind_method(godot::D_METHOD("set_base_shape", "val"), &OcctlPrimExtrudeUntilInfo::set_base_shape);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "base_shape"), "set_base_shape", "get_base_shape");
    godot::ClassDB::bind_method(godot::D_METHOD("get_profile"), &OcctlPrimExtrudeUntilInfo::get_profile);
    godot::ClassDB::bind_method(godot::D_METHOD("set_profile", "val"), &OcctlPrimExtrudeUntilInfo::set_profile);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "profile"), "set_profile", "get_profile");
    godot::ClassDB::bind_method(godot::D_METHOD("get_sketch_face"), &OcctlPrimExtrudeUntilInfo::get_sketch_face);
    godot::ClassDB::bind_method(godot::D_METHOD("set_sketch_face", "val"), &OcctlPrimExtrudeUntilInfo::set_sketch_face);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "sketch_face"), "set_sketch_face", "get_sketch_face");
    godot::ClassDB::bind_method(godot::D_METHOD("get_target_shape"), &OcctlPrimExtrudeUntilInfo::get_target_shape);
    godot::ClassDB::bind_method(godot::D_METHOD("set_target_shape", "val"), &OcctlPrimExtrudeUntilInfo::set_target_shape);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "target_shape"), "set_target_shape", "get_target_shape");
    godot::ClassDB::bind_method(godot::D_METHOD("get_direction"), &OcctlPrimExtrudeUntilInfo::get_direction);
    godot::ClassDB::bind_method(godot::D_METHOD("set_direction", "val"), &OcctlPrimExtrudeUntilInfo::set_direction);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "direction"), "set_direction", "get_direction");
    godot::ClassDB::bind_method(godot::D_METHOD("get_side"), &OcctlPrimExtrudeUntilInfo::get_side);
    godot::ClassDB::bind_method(godot::D_METHOD("set_side", "val"), &OcctlPrimExtrudeUntilInfo::set_side);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "side"), "set_side", "get_side");
    godot::ClassDB::bind_method(godot::D_METHOD("get_combine"), &OcctlPrimExtrudeUntilInfo::get_combine);
    godot::ClassDB::bind_method(godot::D_METHOD("set_combine", "val"), &OcctlPrimExtrudeUntilInfo::set_combine);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "combine"), "set_combine", "get_combine");
    godot::ClassDB::bind_method(godot::D_METHOD("get_modify"), &OcctlPrimExtrudeUntilInfo::get_modify);
    godot::ClassDB::bind_method(godot::D_METHOD("set_modify", "val"), &OcctlPrimExtrudeUntilInfo::set_modify);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "modify"), "set_modify", "get_modify");
    godot::ClassDB::bind_method(godot::D_METHOD("get_limit"), &OcctlPrimExtrudeUntilInfo::get_limit);
    godot::ClassDB::bind_method(godot::D_METHOD("set_limit", "val"), &OcctlPrimExtrudeUntilInfo::set_limit);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "limit"), "set_limit", "get_limit");
}

occtl_prim_extrude_until_info_t OcctlPrimExtrudeUntilInfo::to_c() const {
    occtl_prim_extrude_until_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.base_shape.bits = static_cast<uint64_t>(base_shape);
    result.profile.bits = static_cast<uint64_t>(profile);
    result.sketch_face.bits = static_cast<uint64_t>(sketch_face);
    result.target_shape.bits = static_cast<uint64_t>(target_shape);
    result.direction = direction->to_c();
    result.side = static_cast<occtl_prim_extrude_until_side_t>(side);
    result.combine = static_cast<occtl_prim_feat_combine_t>(combine);
    result.modify = modify;
    result.limit = limit;
    return result;
}

Ref<OcctlPrimExtrudeUntilInfo> OcctlPrimExtrudeUntilInfo::from_c(const occtl_prim_extrude_until_info_t& val) {
    Ref<OcctlPrimExtrudeUntilInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->base_shape = static_cast<int64_t>(val.base_shape.bits);
    r->profile = static_cast<int64_t>(val.profile.bits);
    r->sketch_face = static_cast<int64_t>(val.sketch_face.bits);
    r->target_shape = static_cast<int64_t>(val.target_shape.bits);
    r->direction = OcctlDirection3::from_c(val.direction);
    r->side = static_cast<int>(val.side);
    r->combine = static_cast<int>(val.combine);
    r->modify = val.modify;
    r->limit = val.limit;
    return r;
}

void OcctlPrimExtrudeUntilInfo::copy_from_c(const occtl_prim_extrude_until_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    base_shape = static_cast<int64_t>(val.base_shape.bits);
    profile = static_cast<int64_t>(val.profile.bits);
    sketch_face = static_cast<int64_t>(val.sketch_face.bits);
    target_shape = static_cast<int64_t>(val.target_shape.bits);
    direction = OcctlDirection3::from_c(val.direction);
    side = static_cast<int>(val.side);
    combine = static_cast<int>(val.combine);
    modify = val.modify;
    limit = val.limit;
}
