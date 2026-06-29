#include "OcctlCurveTrimmedCreateInfo.h"

#include "OcctlRepId.h"

int OcctlCurveTrimmedCreateInfo::get_struct_version() const { return struct_version; }
void OcctlCurveTrimmedCreateInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlCurveTrimmedCreateInfo::get_p_next() const { return p_next; }
void OcctlCurveTrimmedCreateInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlCurveTrimmedCreateInfo::get_basis() const { return basis; }
void OcctlCurveTrimmedCreateInfo::set_basis(int64_t val) { basis = val; }

double OcctlCurveTrimmedCreateInfo::get_u_first() const { return u_first; }
void OcctlCurveTrimmedCreateInfo::set_u_first(double val) { u_first = val; }

double OcctlCurveTrimmedCreateInfo::get_u_last() const { return u_last; }
void OcctlCurveTrimmedCreateInfo::set_u_last(double val) { u_last = val; }

int OcctlCurveTrimmedCreateInfo::get_sense() const { return sense; }
void OcctlCurveTrimmedCreateInfo::set_sense(int val) { sense = val; }

void OcctlCurveTrimmedCreateInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlCurveTrimmedCreateInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlCurveTrimmedCreateInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlCurveTrimmedCreateInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlCurveTrimmedCreateInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_basis"), &OcctlCurveTrimmedCreateInfo::get_basis);
    godot::ClassDB::bind_method(godot::D_METHOD("set_basis", "val"), &OcctlCurveTrimmedCreateInfo::set_basis);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "basis"), "set_basis", "get_basis");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_first"), &OcctlCurveTrimmedCreateInfo::get_u_first);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_first", "val"), &OcctlCurveTrimmedCreateInfo::set_u_first);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "u_first"), "set_u_first", "get_u_first");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_last"), &OcctlCurveTrimmedCreateInfo::get_u_last);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_last", "val"), &OcctlCurveTrimmedCreateInfo::set_u_last);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "u_last"), "set_u_last", "get_u_last");
    godot::ClassDB::bind_method(godot::D_METHOD("get_sense"), &OcctlCurveTrimmedCreateInfo::get_sense);
    godot::ClassDB::bind_method(godot::D_METHOD("set_sense", "val"), &OcctlCurveTrimmedCreateInfo::set_sense);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "sense"), "set_sense", "get_sense");
}

occtl_curve_trimmed_create_info_t OcctlCurveTrimmedCreateInfo::to_c() const {
    occtl_curve_trimmed_create_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.basis.bits = static_cast<uint64_t>(basis);
    result.u_first = u_first;
    result.u_last = u_last;
    result.sense = sense;
    return result;
}

Ref<OcctlCurveTrimmedCreateInfo> OcctlCurveTrimmedCreateInfo::from_c(const occtl_curve_trimmed_create_info_t& val) {
    Ref<OcctlCurveTrimmedCreateInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->basis = static_cast<int64_t>(val.basis.bits);
    r->u_first = val.u_first;
    r->u_last = val.u_last;
    r->sense = val.sense;
    return r;
}

void OcctlCurveTrimmedCreateInfo::copy_from_c(const occtl_curve_trimmed_create_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    basis = static_cast<int64_t>(val.basis.bits);
    u_first = val.u_first;
    u_last = val.u_last;
    sense = val.sense;
}
