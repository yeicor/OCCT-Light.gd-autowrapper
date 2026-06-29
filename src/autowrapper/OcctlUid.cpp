#include "OcctlUid.h"


int64_t OcctlUid::get_bits() const { return bits; }
void OcctlUid::set_bits(int64_t val) { bits = val; }

void OcctlUid::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_bits"), &OcctlUid::get_bits);
    godot::ClassDB::bind_method(godot::D_METHOD("set_bits", "val"), &OcctlUid::set_bits);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "bits"), "set_bits", "get_bits");
}

occtl_uid_t OcctlUid::to_c() const {
    occtl_uid_t result = {};
    result.bits = bits;
    return result;
}

Ref<OcctlUid> OcctlUid::from_c(const occtl_uid_t& val) {
    Ref<OcctlUid> r;
    r.instantiate();
    r->bits = val.bits;
    return r;
}

void OcctlUid::copy_from_c(const occtl_uid_t& val) {
    bits = val.bits;
}
