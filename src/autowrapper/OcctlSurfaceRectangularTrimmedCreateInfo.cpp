#include "OcctlSurfaceRectangularTrimmedCreateInfo.h"

#include "OcctlRepId.h"

int OcctlSurfaceRectangularTrimmedCreateInfo::get_struct_version() const { return struct_version; }
void OcctlSurfaceRectangularTrimmedCreateInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlSurfaceRectangularTrimmedCreateInfo::get_p_next() const { return p_next; }
void OcctlSurfaceRectangularTrimmedCreateInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlSurfaceRectangularTrimmedCreateInfo::get_basis() const { return basis; }
void OcctlSurfaceRectangularTrimmedCreateInfo::set_basis(int64_t val) { basis = val; }

double OcctlSurfaceRectangularTrimmedCreateInfo::get_u_first() const { return u_first; }
void OcctlSurfaceRectangularTrimmedCreateInfo::set_u_first(double val) { u_first = val; }

double OcctlSurfaceRectangularTrimmedCreateInfo::get_u_last() const { return u_last; }
void OcctlSurfaceRectangularTrimmedCreateInfo::set_u_last(double val) { u_last = val; }

double OcctlSurfaceRectangularTrimmedCreateInfo::get_v_first() const { return v_first; }
void OcctlSurfaceRectangularTrimmedCreateInfo::set_v_first(double val) { v_first = val; }

double OcctlSurfaceRectangularTrimmedCreateInfo::get_v_last() const { return v_last; }
void OcctlSurfaceRectangularTrimmedCreateInfo::set_v_last(double val) { v_last = val; }

int OcctlSurfaceRectangularTrimmedCreateInfo::get_u_sense() const { return u_sense; }
void OcctlSurfaceRectangularTrimmedCreateInfo::set_u_sense(int val) { u_sense = val; }

int OcctlSurfaceRectangularTrimmedCreateInfo::get_v_sense() const { return v_sense; }
void OcctlSurfaceRectangularTrimmedCreateInfo::set_v_sense(int val) { v_sense = val; }

void OcctlSurfaceRectangularTrimmedCreateInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlSurfaceRectangularTrimmedCreateInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlSurfaceRectangularTrimmedCreateInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlSurfaceRectangularTrimmedCreateInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlSurfaceRectangularTrimmedCreateInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_basis"), &OcctlSurfaceRectangularTrimmedCreateInfo::get_basis);
    godot::ClassDB::bind_method(godot::D_METHOD("set_basis", "val"), &OcctlSurfaceRectangularTrimmedCreateInfo::set_basis);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "basis"), "set_basis", "get_basis");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_first"), &OcctlSurfaceRectangularTrimmedCreateInfo::get_u_first);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_first", "val"), &OcctlSurfaceRectangularTrimmedCreateInfo::set_u_first);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "u_first"), "set_u_first", "get_u_first");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_last"), &OcctlSurfaceRectangularTrimmedCreateInfo::get_u_last);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_last", "val"), &OcctlSurfaceRectangularTrimmedCreateInfo::set_u_last);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "u_last"), "set_u_last", "get_u_last");
    godot::ClassDB::bind_method(godot::D_METHOD("get_v_first"), &OcctlSurfaceRectangularTrimmedCreateInfo::get_v_first);
    godot::ClassDB::bind_method(godot::D_METHOD("set_v_first", "val"), &OcctlSurfaceRectangularTrimmedCreateInfo::set_v_first);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "v_first"), "set_v_first", "get_v_first");
    godot::ClassDB::bind_method(godot::D_METHOD("get_v_last"), &OcctlSurfaceRectangularTrimmedCreateInfo::get_v_last);
    godot::ClassDB::bind_method(godot::D_METHOD("set_v_last", "val"), &OcctlSurfaceRectangularTrimmedCreateInfo::set_v_last);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "v_last"), "set_v_last", "get_v_last");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_sense"), &OcctlSurfaceRectangularTrimmedCreateInfo::get_u_sense);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_sense", "val"), &OcctlSurfaceRectangularTrimmedCreateInfo::set_u_sense);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "u_sense"), "set_u_sense", "get_u_sense");
    godot::ClassDB::bind_method(godot::D_METHOD("get_v_sense"), &OcctlSurfaceRectangularTrimmedCreateInfo::get_v_sense);
    godot::ClassDB::bind_method(godot::D_METHOD("set_v_sense", "val"), &OcctlSurfaceRectangularTrimmedCreateInfo::set_v_sense);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "v_sense"), "set_v_sense", "get_v_sense");
}

occtl_surface_rectangular_trimmed_create_info_t OcctlSurfaceRectangularTrimmedCreateInfo::to_c() const {
    occtl_surface_rectangular_trimmed_create_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.basis.bits = static_cast<uint64_t>(basis);
    result.u_first = u_first;
    result.u_last = u_last;
    result.v_first = v_first;
    result.v_last = v_last;
    result.u_sense = u_sense;
    result.v_sense = v_sense;
    return result;
}

Ref<OcctlSurfaceRectangularTrimmedCreateInfo> OcctlSurfaceRectangularTrimmedCreateInfo::from_c(const occtl_surface_rectangular_trimmed_create_info_t& val) {
    Ref<OcctlSurfaceRectangularTrimmedCreateInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->basis = static_cast<int64_t>(val.basis.bits);
    r->u_first = val.u_first;
    r->u_last = val.u_last;
    r->v_first = val.v_first;
    r->v_last = val.v_last;
    r->u_sense = val.u_sense;
    r->v_sense = val.v_sense;
    return r;
}

void OcctlSurfaceRectangularTrimmedCreateInfo::copy_from_c(const occtl_surface_rectangular_trimmed_create_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    basis = static_cast<int64_t>(val.basis.bits);
    u_first = val.u_first;
    u_last = val.u_last;
    v_first = val.v_first;
    v_last = val.v_last;
    u_sense = val.u_sense;
    v_sense = val.v_sense;
}
