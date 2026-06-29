#include "OcctlRepUid.h"


int64_t OcctlRepUid::get_bits() const { return bits; }
void OcctlRepUid::set_bits(int64_t val) { bits = val; }

void OcctlRepUid::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_bits"), &OcctlRepUid::get_bits);
    godot::ClassDB::bind_method(godot::D_METHOD("set_bits", "val"), &OcctlRepUid::set_bits);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "bits"), "set_bits", "get_bits");
}

occtl_rep_uid_t OcctlRepUid::to_c() const {
    occtl_rep_uid_t result = {};
    result.bits = bits;
    return result;
}

Ref<OcctlRepUid> OcctlRepUid::from_c(const occtl_rep_uid_t& val) {
    Ref<OcctlRepUid> r;
    r.instantiate();
    r->bits = val.bits;
    return r;
}

void OcctlRepUid::copy_from_c(const occtl_rep_uid_t& val) {
    bits = val.bits;
}
