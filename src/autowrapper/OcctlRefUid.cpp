#include "OcctlRefUid.h"


int64_t OcctlRefUid::get_bits() const { return bits; }
void OcctlRefUid::set_bits(int64_t val) { bits = val; }

void OcctlRefUid::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_bits"), &OcctlRefUid::get_bits);
    godot::ClassDB::bind_method(godot::D_METHOD("set_bits", "val"), &OcctlRefUid::set_bits);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "bits"), "set_bits", "get_bits");
}

occtl_ref_uid_t OcctlRefUid::to_c() const {
    occtl_ref_uid_t result = {};
    result.bits = bits;
    return result;
}

Ref<OcctlRefUid> OcctlRefUid::from_c(const occtl_ref_uid_t& val) {
    Ref<OcctlRefUid> r;
    r.instantiate();
    r->bits = val.bits;
    return r;
}

void OcctlRefUid::copy_from_c(const occtl_ref_uid_t& val) {
    bits = val.bits;
}
