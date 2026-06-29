#include "OcctlSurfaceOffsetCreateInfo.h"

#include "OcctlRepId.h"

int OcctlSurfaceOffsetCreateInfo::get_struct_version() const { return struct_version; }
void OcctlSurfaceOffsetCreateInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlSurfaceOffsetCreateInfo::get_p_next() const { return p_next; }
void OcctlSurfaceOffsetCreateInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlSurfaceOffsetCreateInfo::get_basis() const { return basis; }
void OcctlSurfaceOffsetCreateInfo::set_basis(int64_t val) { basis = val; }

double OcctlSurfaceOffsetCreateInfo::get_offset() const { return offset; }
void OcctlSurfaceOffsetCreateInfo::set_offset(double val) { offset = val; }

void OcctlSurfaceOffsetCreateInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlSurfaceOffsetCreateInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlSurfaceOffsetCreateInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlSurfaceOffsetCreateInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlSurfaceOffsetCreateInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_basis"), &OcctlSurfaceOffsetCreateInfo::get_basis);
    godot::ClassDB::bind_method(godot::D_METHOD("set_basis", "val"), &OcctlSurfaceOffsetCreateInfo::set_basis);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "basis"), "set_basis", "get_basis");
    godot::ClassDB::bind_method(godot::D_METHOD("get_offset"), &OcctlSurfaceOffsetCreateInfo::get_offset);
    godot::ClassDB::bind_method(godot::D_METHOD("set_offset", "val"), &OcctlSurfaceOffsetCreateInfo::set_offset);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "offset"), "set_offset", "get_offset");
}

occtl_surface_offset_create_info_t OcctlSurfaceOffsetCreateInfo::to_c() const {
    occtl_surface_offset_create_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.basis.bits = static_cast<uint64_t>(basis);
    result.offset = offset;
    return result;
}

Ref<OcctlSurfaceOffsetCreateInfo> OcctlSurfaceOffsetCreateInfo::from_c(const occtl_surface_offset_create_info_t& val) {
    Ref<OcctlSurfaceOffsetCreateInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->basis = static_cast<int64_t>(val.basis.bits);
    r->offset = val.offset;
    return r;
}

void OcctlSurfaceOffsetCreateInfo::copy_from_c(const occtl_surface_offset_create_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    basis = static_cast<int64_t>(val.basis.bits);
    offset = val.offset;
}
