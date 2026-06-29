#include "OcctlJointId.h"


int64_t OcctlJointId::get_bits() const { return bits; }
void OcctlJointId::set_bits(int64_t val) { bits = val; }

void OcctlJointId::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_bits"), &OcctlJointId::get_bits);
    godot::ClassDB::bind_method(godot::D_METHOD("set_bits", "val"), &OcctlJointId::set_bits);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "bits"), "set_bits", "get_bits");
}

occtl_joint_id_t OcctlJointId::to_c() const {
    occtl_joint_id_t result = {};
    result.bits = bits;
    return result;
}

Ref<OcctlJointId> OcctlJointId::from_c(const occtl_joint_id_t& val) {
    Ref<OcctlJointId> r;
    r.instantiate();
    r->bits = val.bits;
    return r;
}

void OcctlJointId::copy_from_c(const occtl_joint_id_t& val) {
    bits = val.bits;
}
