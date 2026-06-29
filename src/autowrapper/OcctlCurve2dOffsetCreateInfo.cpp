#include "OcctlCurve2dOffsetCreateInfo.h"

#include "OcctlRepId.h"

int OcctlCurve2dOffsetCreateInfo::get_struct_version() const { return struct_version; }
void OcctlCurve2dOffsetCreateInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlCurve2dOffsetCreateInfo::get_p_next() const { return p_next; }
void OcctlCurve2dOffsetCreateInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlCurve2dOffsetCreateInfo::get_basis() const { return basis; }
void OcctlCurve2dOffsetCreateInfo::set_basis(int64_t val) { basis = val; }

double OcctlCurve2dOffsetCreateInfo::get_offset() const { return offset; }
void OcctlCurve2dOffsetCreateInfo::set_offset(double val) { offset = val; }

void OcctlCurve2dOffsetCreateInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlCurve2dOffsetCreateInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlCurve2dOffsetCreateInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlCurve2dOffsetCreateInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlCurve2dOffsetCreateInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_basis"), &OcctlCurve2dOffsetCreateInfo::get_basis);
    godot::ClassDB::bind_method(godot::D_METHOD("set_basis", "val"), &OcctlCurve2dOffsetCreateInfo::set_basis);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "basis"), "set_basis", "get_basis");
    godot::ClassDB::bind_method(godot::D_METHOD("get_offset"), &OcctlCurve2dOffsetCreateInfo::get_offset);
    godot::ClassDB::bind_method(godot::D_METHOD("set_offset", "val"), &OcctlCurve2dOffsetCreateInfo::set_offset);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "offset"), "set_offset", "get_offset");
}

occtl_curve2d_offset_create_info_t OcctlCurve2dOffsetCreateInfo::to_c() const {
    occtl_curve2d_offset_create_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.basis.bits = static_cast<uint64_t>(basis);
    result.offset = offset;
    return result;
}

Ref<OcctlCurve2dOffsetCreateInfo> OcctlCurve2dOffsetCreateInfo::from_c(const occtl_curve2d_offset_create_info_t& val) {
    Ref<OcctlCurve2dOffsetCreateInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->basis = static_cast<int64_t>(val.basis.bits);
    r->offset = val.offset;
    return r;
}

void OcctlCurve2dOffsetCreateInfo::copy_from_c(const occtl_curve2d_offset_create_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    basis = static_cast<int64_t>(val.basis.bits);
    offset = val.offset;
}
