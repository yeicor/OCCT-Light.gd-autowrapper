#include "OcctlRepId.h"


int64_t OcctlRepId::get_bits() const { return bits; }
void OcctlRepId::set_bits(int64_t val) { bits = val; }

void OcctlRepId::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_bits"), &OcctlRepId::get_bits);
    godot::ClassDB::bind_method(godot::D_METHOD("set_bits", "val"), &OcctlRepId::set_bits);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "bits"), "set_bits", "get_bits");
}

occtl_rep_id_t OcctlRepId::to_c() const {
    occtl_rep_id_t result = {};
    result.bits = bits;
    return result;
}

Ref<OcctlRepId> OcctlRepId::from_c(const occtl_rep_id_t& val) {
    Ref<OcctlRepId> r;
    r.instantiate();
    r->bits = val.bits;
    return r;
}

void OcctlRepId::copy_from_c(const occtl_rep_id_t& val) {
    bits = val.bits;
}
