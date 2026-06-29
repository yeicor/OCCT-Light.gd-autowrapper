#include "OcctlOrientedNode.h"

#include "OcctlNodeId.h"

int64_t OcctlOrientedNode::get_id() const { return id; }
void OcctlOrientedNode::set_id(int64_t val) { id = val; }

int OcctlOrientedNode::get_orientation() const { return orientation; }
void OcctlOrientedNode::set_orientation(int val) { orientation = val; }

void OcctlOrientedNode::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_id"), &OcctlOrientedNode::get_id);
    godot::ClassDB::bind_method(godot::D_METHOD("set_id", "val"), &OcctlOrientedNode::set_id);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "id"), "set_id", "get_id");
    godot::ClassDB::bind_method(godot::D_METHOD("get_orientation"), &OcctlOrientedNode::get_orientation);
    godot::ClassDB::bind_method(godot::D_METHOD("set_orientation", "val"), &OcctlOrientedNode::set_orientation);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "orientation"), "set_orientation", "get_orientation");
}

occtl_oriented_node_t OcctlOrientedNode::to_c() const {
    occtl_oriented_node_t result = {};
    result.id.bits = static_cast<uint64_t>(id);
    result.orientation = static_cast<occtl_orientation_t>(orientation);
    return result;
}

Ref<OcctlOrientedNode> OcctlOrientedNode::from_c(const occtl_oriented_node_t& val) {
    Ref<OcctlOrientedNode> r;
    r.instantiate();
    r->id = static_cast<int64_t>(val.id.bits);
    r->orientation = static_cast<int>(val.orientation);
    return r;
}

void OcctlOrientedNode::copy_from_c(const occtl_oriented_node_t& val) {
    id = static_cast<int64_t>(val.id.bits);
    orientation = static_cast<int>(val.orientation);
}
