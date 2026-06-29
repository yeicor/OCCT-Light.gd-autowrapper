#include "OcctlSurfaceRevolutionCreateInfo.h"

#include "OcctlRepId.h"
#include "OcctlAxis1Placement.h"

int OcctlSurfaceRevolutionCreateInfo::get_struct_version() const { return struct_version; }
void OcctlSurfaceRevolutionCreateInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlSurfaceRevolutionCreateInfo::get_p_next() const { return p_next; }
void OcctlSurfaceRevolutionCreateInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlSurfaceRevolutionCreateInfo::get_basis() const { return basis; }
void OcctlSurfaceRevolutionCreateInfo::set_basis(int64_t val) { basis = val; }

Ref<OcctlAxis1Placement> OcctlSurfaceRevolutionCreateInfo::get_axis() const { return axis; }
void OcctlSurfaceRevolutionCreateInfo::set_axis(Ref<OcctlAxis1Placement> val) { axis = val; }

void OcctlSurfaceRevolutionCreateInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlSurfaceRevolutionCreateInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlSurfaceRevolutionCreateInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlSurfaceRevolutionCreateInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlSurfaceRevolutionCreateInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_basis"), &OcctlSurfaceRevolutionCreateInfo::get_basis);
    godot::ClassDB::bind_method(godot::D_METHOD("set_basis", "val"), &OcctlSurfaceRevolutionCreateInfo::set_basis);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "basis"), "set_basis", "get_basis");
    godot::ClassDB::bind_method(godot::D_METHOD("get_axis"), &OcctlSurfaceRevolutionCreateInfo::get_axis);
    godot::ClassDB::bind_method(godot::D_METHOD("set_axis", "val"), &OcctlSurfaceRevolutionCreateInfo::set_axis);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "axis"), "set_axis", "get_axis");
}

occtl_surface_revolution_create_info_t OcctlSurfaceRevolutionCreateInfo::to_c() const {
    occtl_surface_revolution_create_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.basis.bits = static_cast<uint64_t>(basis);
    result.axis = axis->to_c();
    return result;
}

Ref<OcctlSurfaceRevolutionCreateInfo> OcctlSurfaceRevolutionCreateInfo::from_c(const occtl_surface_revolution_create_info_t& val) {
    Ref<OcctlSurfaceRevolutionCreateInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->basis = static_cast<int64_t>(val.basis.bits);
    r->axis = OcctlAxis1Placement::from_c(val.axis);
    return r;
}

void OcctlSurfaceRevolutionCreateInfo::copy_from_c(const occtl_surface_revolution_create_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    basis = static_cast<int64_t>(val.basis.bits);
    axis = OcctlAxis1Placement::from_c(val.axis);
}
