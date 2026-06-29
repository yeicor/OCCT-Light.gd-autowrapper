#include "OcctlSurfaceExtrusionCreateInfo.h"

#include "OcctlRepId.h"
#include "OcctlVector3.h"

int OcctlSurfaceExtrusionCreateInfo::get_struct_version() const { return struct_version; }
void OcctlSurfaceExtrusionCreateInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlSurfaceExtrusionCreateInfo::get_p_next() const { return p_next; }
void OcctlSurfaceExtrusionCreateInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlSurfaceExtrusionCreateInfo::get_basis() const { return basis; }
void OcctlSurfaceExtrusionCreateInfo::set_basis(int64_t val) { basis = val; }

Ref<OcctlVector3> OcctlSurfaceExtrusionCreateInfo::get_direction() const { return direction; }
void OcctlSurfaceExtrusionCreateInfo::set_direction(Ref<OcctlVector3> val) { direction = val; }

void OcctlSurfaceExtrusionCreateInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlSurfaceExtrusionCreateInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlSurfaceExtrusionCreateInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlSurfaceExtrusionCreateInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlSurfaceExtrusionCreateInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_basis"), &OcctlSurfaceExtrusionCreateInfo::get_basis);
    godot::ClassDB::bind_method(godot::D_METHOD("set_basis", "val"), &OcctlSurfaceExtrusionCreateInfo::set_basis);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "basis"), "set_basis", "get_basis");
    godot::ClassDB::bind_method(godot::D_METHOD("get_direction"), &OcctlSurfaceExtrusionCreateInfo::get_direction);
    godot::ClassDB::bind_method(godot::D_METHOD("set_direction", "val"), &OcctlSurfaceExtrusionCreateInfo::set_direction);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "direction"), "set_direction", "get_direction");
}

occtl_surface_extrusion_create_info_t OcctlSurfaceExtrusionCreateInfo::to_c() const {
    occtl_surface_extrusion_create_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.basis.bits = static_cast<uint64_t>(basis);
    result.direction = direction->to_c();
    return result;
}

Ref<OcctlSurfaceExtrusionCreateInfo> OcctlSurfaceExtrusionCreateInfo::from_c(const occtl_surface_extrusion_create_info_t& val) {
    Ref<OcctlSurfaceExtrusionCreateInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->basis = static_cast<int64_t>(val.basis.bits);
    r->direction = OcctlVector3::from_c(val.direction);
    return r;
}

void OcctlSurfaceExtrusionCreateInfo::copy_from_c(const occtl_surface_extrusion_create_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    basis = static_cast<int64_t>(val.basis.bits);
    direction = OcctlVector3::from_c(val.direction);
}
