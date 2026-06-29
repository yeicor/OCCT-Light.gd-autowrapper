#include "OcctlRefId.h"


int64_t OcctlRefId::get_bits() const { return bits; }
void OcctlRefId::set_bits(int64_t val) { bits = val; }

void OcctlRefId::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_bits"), &OcctlRefId::get_bits);
    godot::ClassDB::bind_method(godot::D_METHOD("set_bits", "val"), &OcctlRefId::set_bits);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "bits"), "set_bits", "get_bits");
}

occtl_ref_id_t OcctlRefId::to_c() const {
    occtl_ref_id_t result = {};
    result.bits = bits;
    return result;
}

Ref<OcctlRefId> OcctlRefId::from_c(const occtl_ref_id_t& val) {
    Ref<OcctlRefId> r;
    r.instantiate();
    r->bits = val.bits;
    return r;
}

void OcctlRefId::copy_from_c(const occtl_ref_id_t& val) {
    bits = val.bits;
}
