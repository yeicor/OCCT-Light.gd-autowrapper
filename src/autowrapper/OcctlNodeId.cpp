#include "OcctlNodeId.h"


int64_t OcctlNodeId::get_bits() const { return bits; }
void OcctlNodeId::set_bits(int64_t val) { bits = val; }

void OcctlNodeId::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_bits"), &OcctlNodeId::get_bits);
    godot::ClassDB::bind_method(godot::D_METHOD("set_bits", "val"), &OcctlNodeId::set_bits);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "bits"), "set_bits", "get_bits");
}

occtl_node_id_t OcctlNodeId::to_c() const {
    occtl_node_id_t result = {};
    result.bits = bits;
    return result;
}

Ref<OcctlNodeId> OcctlNodeId::from_c(const occtl_node_id_t& val) {
    Ref<OcctlNodeId> r;
    r.instantiate();
    r->bits = val.bits;
    return r;
}

void OcctlNodeId::copy_from_c(const occtl_node_id_t& val) {
    bits = val.bits;
}
