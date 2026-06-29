#include "OcctlCurveOffsetCreateInfo.h"

#include "OcctlRepId.h"
#include "OcctlVector3.h"

int OcctlCurveOffsetCreateInfo::get_struct_version() const { return struct_version; }
void OcctlCurveOffsetCreateInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlCurveOffsetCreateInfo::get_p_next() const { return p_next; }
void OcctlCurveOffsetCreateInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlCurveOffsetCreateInfo::get_basis() const { return basis; }
void OcctlCurveOffsetCreateInfo::set_basis(int64_t val) { basis = val; }

Ref<OcctlVector3> OcctlCurveOffsetCreateInfo::get_offset_dir() const { return offset_dir; }
void OcctlCurveOffsetCreateInfo::set_offset_dir(Ref<OcctlVector3> val) { offset_dir = val; }

double OcctlCurveOffsetCreateInfo::get_offset() const { return offset; }
void OcctlCurveOffsetCreateInfo::set_offset(double val) { offset = val; }

void OcctlCurveOffsetCreateInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlCurveOffsetCreateInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlCurveOffsetCreateInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlCurveOffsetCreateInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlCurveOffsetCreateInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_basis"), &OcctlCurveOffsetCreateInfo::get_basis);
    godot::ClassDB::bind_method(godot::D_METHOD("set_basis", "val"), &OcctlCurveOffsetCreateInfo::set_basis);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "basis"), "set_basis", "get_basis");
    godot::ClassDB::bind_method(godot::D_METHOD("get_offset_dir"), &OcctlCurveOffsetCreateInfo::get_offset_dir);
    godot::ClassDB::bind_method(godot::D_METHOD("set_offset_dir", "val"), &OcctlCurveOffsetCreateInfo::set_offset_dir);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "offset_dir"), "set_offset_dir", "get_offset_dir");
    godot::ClassDB::bind_method(godot::D_METHOD("get_offset"), &OcctlCurveOffsetCreateInfo::get_offset);
    godot::ClassDB::bind_method(godot::D_METHOD("set_offset", "val"), &OcctlCurveOffsetCreateInfo::set_offset);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "offset"), "set_offset", "get_offset");
}

occtl_curve_offset_create_info_t OcctlCurveOffsetCreateInfo::to_c() const {
    occtl_curve_offset_create_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.basis.bits = static_cast<uint64_t>(basis);
    result.offset_dir = offset_dir->to_c();
    result.offset = offset;
    return result;
}

Ref<OcctlCurveOffsetCreateInfo> OcctlCurveOffsetCreateInfo::from_c(const occtl_curve_offset_create_info_t& val) {
    Ref<OcctlCurveOffsetCreateInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->basis = static_cast<int64_t>(val.basis.bits);
    r->offset_dir = OcctlVector3::from_c(val.offset_dir);
    r->offset = val.offset;
    return r;
}

void OcctlCurveOffsetCreateInfo::copy_from_c(const occtl_curve_offset_create_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    basis = static_cast<int64_t>(val.basis.bits);
    offset_dir = OcctlVector3::from_c(val.offset_dir);
    offset = val.offset;
}
