#include "OcctlSelectDistanceToNodeSort.h"

#include "OcctlNodeId.h"

int OcctlSelectDistanceToNodeSort::get_struct_version() const { return struct_version; }
void OcctlSelectDistanceToNodeSort::set_struct_version(int val) { struct_version = val; }

int64_t OcctlSelectDistanceToNodeSort::get_p_next() const { return p_next; }
void OcctlSelectDistanceToNodeSort::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlSelectDistanceToNodeSort::get_target() const { return target; }
void OcctlSelectDistanceToNodeSort::set_target(int64_t val) { target = val; }

void OcctlSelectDistanceToNodeSort::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlSelectDistanceToNodeSort::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlSelectDistanceToNodeSort::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlSelectDistanceToNodeSort::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlSelectDistanceToNodeSort::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_target"), &OcctlSelectDistanceToNodeSort::get_target);
    godot::ClassDB::bind_method(godot::D_METHOD("set_target", "val"), &OcctlSelectDistanceToNodeSort::set_target);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "target"), "set_target", "get_target");
}

occtl_select_distance_to_node_sort_t OcctlSelectDistanceToNodeSort::to_c() const {
    occtl_select_distance_to_node_sort_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.target.bits = static_cast<uint64_t>(target);
    return result;
}

Ref<OcctlSelectDistanceToNodeSort> OcctlSelectDistanceToNodeSort::from_c(const occtl_select_distance_to_node_sort_t& val) {
    Ref<OcctlSelectDistanceToNodeSort> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->target = static_cast<int64_t>(val.target.bits);
    return r;
}

void OcctlSelectDistanceToNodeSort::copy_from_c(const occtl_select_distance_to_node_sort_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    target = static_cast<int64_t>(val.target.bits);
}
