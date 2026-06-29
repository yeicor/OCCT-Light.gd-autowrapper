#include "OcctlJointInfo.h"

#include "OcctlJointId.h"
#include "OcctlNodeId.h"
#include "OcctlTransform.h"
#include "OcctlUid.h"

int OcctlJointInfo::get_struct_version() const { return struct_version; }
void OcctlJointInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlJointInfo::get_p_next() const { return p_next; }
void OcctlJointInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlJointInfo::get_id() const { return id; }
void OcctlJointInfo::set_id(int64_t val) { id = val; }

int OcctlJointInfo::get_kind() const { return kind; }
void OcctlJointInfo::set_kind(int val) { kind = val; }

int64_t OcctlJointInfo::get_node_a() const { return node_a; }
void OcctlJointInfo::set_node_a(int64_t val) { node_a = val; }

int64_t OcctlJointInfo::get_node_b() const { return node_b; }
void OcctlJointInfo::set_node_b(int64_t val) { node_b = val; }

Ref<OcctlTransform> OcctlJointInfo::get_frame_a() const { return frame_a; }
void OcctlJointInfo::set_frame_a(Ref<OcctlTransform> val) { frame_a = val; }

Ref<OcctlTransform> OcctlJointInfo::get_frame_b() const { return frame_b; }
void OcctlJointInfo::set_frame_b(Ref<OcctlTransform> val) { frame_b = val; }

int OcctlJointInfo::get_has_limit_min() const { return has_limit_min; }
void OcctlJointInfo::set_has_limit_min(int val) { has_limit_min = val; }

double OcctlJointInfo::get_limit_min() const { return limit_min; }
void OcctlJointInfo::set_limit_min(double val) { limit_min = val; }

int OcctlJointInfo::get_has_limit_max() const { return has_limit_max; }
void OcctlJointInfo::set_has_limit_max(int val) { has_limit_max = val; }

double OcctlJointInfo::get_limit_max() const { return limit_max; }
void OcctlJointInfo::set_limit_max(double val) { limit_max = val; }

int64_t OcctlJointInfo::get_metadata_uid() const { return metadata_uid; }
void OcctlJointInfo::set_metadata_uid(int64_t val) { metadata_uid = val; }

void OcctlJointInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlJointInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlJointInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlJointInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlJointInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_id"), &OcctlJointInfo::get_id);
    godot::ClassDB::bind_method(godot::D_METHOD("set_id", "val"), &OcctlJointInfo::set_id);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "id"), "set_id", "get_id");
    godot::ClassDB::bind_method(godot::D_METHOD("get_kind"), &OcctlJointInfo::get_kind);
    godot::ClassDB::bind_method(godot::D_METHOD("set_kind", "val"), &OcctlJointInfo::set_kind);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "kind"), "set_kind", "get_kind");
    godot::ClassDB::bind_method(godot::D_METHOD("get_node_a"), &OcctlJointInfo::get_node_a);
    godot::ClassDB::bind_method(godot::D_METHOD("set_node_a", "val"), &OcctlJointInfo::set_node_a);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "node_a"), "set_node_a", "get_node_a");
    godot::ClassDB::bind_method(godot::D_METHOD("get_node_b"), &OcctlJointInfo::get_node_b);
    godot::ClassDB::bind_method(godot::D_METHOD("set_node_b", "val"), &OcctlJointInfo::set_node_b);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "node_b"), "set_node_b", "get_node_b");
    godot::ClassDB::bind_method(godot::D_METHOD("get_frame_a"), &OcctlJointInfo::get_frame_a);
    godot::ClassDB::bind_method(godot::D_METHOD("set_frame_a", "val"), &OcctlJointInfo::set_frame_a);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "frame_a"), "set_frame_a", "get_frame_a");
    godot::ClassDB::bind_method(godot::D_METHOD("get_frame_b"), &OcctlJointInfo::get_frame_b);
    godot::ClassDB::bind_method(godot::D_METHOD("set_frame_b", "val"), &OcctlJointInfo::set_frame_b);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "frame_b"), "set_frame_b", "get_frame_b");
    godot::ClassDB::bind_method(godot::D_METHOD("get_has_limit_min"), &OcctlJointInfo::get_has_limit_min);
    godot::ClassDB::bind_method(godot::D_METHOD("set_has_limit_min", "val"), &OcctlJointInfo::set_has_limit_min);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "has_limit_min"), "set_has_limit_min", "get_has_limit_min");
    godot::ClassDB::bind_method(godot::D_METHOD("get_limit_min"), &OcctlJointInfo::get_limit_min);
    godot::ClassDB::bind_method(godot::D_METHOD("set_limit_min", "val"), &OcctlJointInfo::set_limit_min);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "limit_min"), "set_limit_min", "get_limit_min");
    godot::ClassDB::bind_method(godot::D_METHOD("get_has_limit_max"), &OcctlJointInfo::get_has_limit_max);
    godot::ClassDB::bind_method(godot::D_METHOD("set_has_limit_max", "val"), &OcctlJointInfo::set_has_limit_max);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "has_limit_max"), "set_has_limit_max", "get_has_limit_max");
    godot::ClassDB::bind_method(godot::D_METHOD("get_limit_max"), &OcctlJointInfo::get_limit_max);
    godot::ClassDB::bind_method(godot::D_METHOD("set_limit_max", "val"), &OcctlJointInfo::set_limit_max);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "limit_max"), "set_limit_max", "get_limit_max");
    godot::ClassDB::bind_method(godot::D_METHOD("get_metadata_uid"), &OcctlJointInfo::get_metadata_uid);
    godot::ClassDB::bind_method(godot::D_METHOD("set_metadata_uid", "val"), &OcctlJointInfo::set_metadata_uid);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "metadata_uid"), "set_metadata_uid", "get_metadata_uid");
}

occtl_joint_info_t OcctlJointInfo::to_c() const {
    occtl_joint_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.id.bits = static_cast<uint64_t>(id);
    result.kind = static_cast<occtl_joint_kind_t>(kind);
    result.node_a.bits = static_cast<uint64_t>(node_a);
    result.node_b.bits = static_cast<uint64_t>(node_b);
    result.frame_a = frame_a->to_c();
    result.frame_b = frame_b->to_c();
    result.has_limit_min = has_limit_min;
    result.limit_min = limit_min;
    result.has_limit_max = has_limit_max;
    result.limit_max = limit_max;
    result.metadata_uid.bits = static_cast<uint64_t>(metadata_uid);
    return result;
}

Ref<OcctlJointInfo> OcctlJointInfo::from_c(const occtl_joint_info_t& val) {
    Ref<OcctlJointInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->id = static_cast<int64_t>(val.id.bits);
    r->kind = static_cast<int>(val.kind);
    r->node_a = static_cast<int64_t>(val.node_a.bits);
    r->node_b = static_cast<int64_t>(val.node_b.bits);
    r->frame_a = OcctlTransform::from_c(val.frame_a);
    r->frame_b = OcctlTransform::from_c(val.frame_b);
    r->has_limit_min = val.has_limit_min;
    r->limit_min = val.limit_min;
    r->has_limit_max = val.has_limit_max;
    r->limit_max = val.limit_max;
    r->metadata_uid = static_cast<int64_t>(val.metadata_uid.bits);
    return r;
}

void OcctlJointInfo::copy_from_c(const occtl_joint_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    id = static_cast<int64_t>(val.id.bits);
    kind = static_cast<int>(val.kind);
    node_a = static_cast<int64_t>(val.node_a.bits);
    node_b = static_cast<int64_t>(val.node_b.bits);
    frame_a = OcctlTransform::from_c(val.frame_a);
    frame_b = OcctlTransform::from_c(val.frame_b);
    has_limit_min = val.has_limit_min;
    limit_min = val.limit_min;
    has_limit_max = val.has_limit_max;
    limit_max = val.limit_max;
    metadata_uid = static_cast<int64_t>(val.metadata_uid.bits);
}
