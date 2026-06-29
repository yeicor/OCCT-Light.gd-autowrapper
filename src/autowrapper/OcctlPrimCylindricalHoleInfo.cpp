#include "OcctlPrimCylindricalHoleInfo.h"

#include "OcctlNodeId.h"
#include "OcctlAxis1Placement.h"

int OcctlPrimCylindricalHoleInfo::get_struct_version() const { return struct_version; }
void OcctlPrimCylindricalHoleInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimCylindricalHoleInfo::get_p_next() const { return p_next; }
void OcctlPrimCylindricalHoleInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlPrimCylindricalHoleInfo::get_base_shape() const { return base_shape; }
void OcctlPrimCylindricalHoleInfo::set_base_shape(int64_t val) { base_shape = val; }

Ref<OcctlAxis1Placement> OcctlPrimCylindricalHoleInfo::get_axis() const { return axis; }
void OcctlPrimCylindricalHoleInfo::set_axis(Ref<OcctlAxis1Placement> val) { axis = val; }

double OcctlPrimCylindricalHoleInfo::get_radius() const { return radius; }
void OcctlPrimCylindricalHoleInfo::set_radius(double val) { radius = val; }

int OcctlPrimCylindricalHoleInfo::get_kind() const { return kind; }
void OcctlPrimCylindricalHoleInfo::set_kind(int val) { kind = val; }

double OcctlPrimCylindricalHoleInfo::get_p_from() const { return p_from; }
void OcctlPrimCylindricalHoleInfo::set_p_from(double val) { p_from = val; }

double OcctlPrimCylindricalHoleInfo::get_p_to() const { return p_to; }
void OcctlPrimCylindricalHoleInfo::set_p_to(double val) { p_to = val; }

double OcctlPrimCylindricalHoleInfo::get_length() const { return length; }
void OcctlPrimCylindricalHoleInfo::set_length(double val) { length = val; }

int OcctlPrimCylindricalHoleInfo::get_with_control() const { return with_control; }
void OcctlPrimCylindricalHoleInfo::set_with_control(int val) { with_control = val; }

void OcctlPrimCylindricalHoleInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimCylindricalHoleInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimCylindricalHoleInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimCylindricalHoleInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimCylindricalHoleInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_base_shape"), &OcctlPrimCylindricalHoleInfo::get_base_shape);
    godot::ClassDB::bind_method(godot::D_METHOD("set_base_shape", "val"), &OcctlPrimCylindricalHoleInfo::set_base_shape);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "base_shape"), "set_base_shape", "get_base_shape");
    godot::ClassDB::bind_method(godot::D_METHOD("get_axis"), &OcctlPrimCylindricalHoleInfo::get_axis);
    godot::ClassDB::bind_method(godot::D_METHOD("set_axis", "val"), &OcctlPrimCylindricalHoleInfo::set_axis);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "axis"), "set_axis", "get_axis");
    godot::ClassDB::bind_method(godot::D_METHOD("get_radius"), &OcctlPrimCylindricalHoleInfo::get_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_radius", "val"), &OcctlPrimCylindricalHoleInfo::set_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "radius"), "set_radius", "get_radius");
    godot::ClassDB::bind_method(godot::D_METHOD("get_kind"), &OcctlPrimCylindricalHoleInfo::get_kind);
    godot::ClassDB::bind_method(godot::D_METHOD("set_kind", "val"), &OcctlPrimCylindricalHoleInfo::set_kind);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "kind"), "set_kind", "get_kind");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_from"), &OcctlPrimCylindricalHoleInfo::get_p_from);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_from", "val"), &OcctlPrimCylindricalHoleInfo::set_p_from);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "p_from"), "set_p_from", "get_p_from");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_to"), &OcctlPrimCylindricalHoleInfo::get_p_to);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_to", "val"), &OcctlPrimCylindricalHoleInfo::set_p_to);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "p_to"), "set_p_to", "get_p_to");
    godot::ClassDB::bind_method(godot::D_METHOD("get_length"), &OcctlPrimCylindricalHoleInfo::get_length);
    godot::ClassDB::bind_method(godot::D_METHOD("set_length", "val"), &OcctlPrimCylindricalHoleInfo::set_length);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "length"), "set_length", "get_length");
    godot::ClassDB::bind_method(godot::D_METHOD("get_with_control"), &OcctlPrimCylindricalHoleInfo::get_with_control);
    godot::ClassDB::bind_method(godot::D_METHOD("set_with_control", "val"), &OcctlPrimCylindricalHoleInfo::set_with_control);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "with_control"), "set_with_control", "get_with_control");
}

occtl_prim_cylindrical_hole_info_t OcctlPrimCylindricalHoleInfo::to_c() const {
    occtl_prim_cylindrical_hole_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.base_shape.bits = static_cast<uint64_t>(base_shape);
    result.axis = axis->to_c();
    result.radius = radius;
    result.kind = static_cast<occtl_prim_cylindrical_hole_kind_t>(kind);
    result.p_from = p_from;
    result.p_to = p_to;
    result.length = length;
    result.with_control = with_control;
    return result;
}

Ref<OcctlPrimCylindricalHoleInfo> OcctlPrimCylindricalHoleInfo::from_c(const occtl_prim_cylindrical_hole_info_t& val) {
    Ref<OcctlPrimCylindricalHoleInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->base_shape = static_cast<int64_t>(val.base_shape.bits);
    r->axis = OcctlAxis1Placement::from_c(val.axis);
    r->radius = val.radius;
    r->kind = static_cast<int>(val.kind);
    r->p_from = val.p_from;
    r->p_to = val.p_to;
    r->length = val.length;
    r->with_control = val.with_control;
    return r;
}

void OcctlPrimCylindricalHoleInfo::copy_from_c(const occtl_prim_cylindrical_hole_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    base_shape = static_cast<int64_t>(val.base_shape.bits);
    axis = OcctlAxis1Placement::from_c(val.axis);
    radius = val.radius;
    kind = static_cast<int>(val.kind);
    p_from = val.p_from;
    p_to = val.p_to;
    length = val.length;
    with_control = val.with_control;
}
