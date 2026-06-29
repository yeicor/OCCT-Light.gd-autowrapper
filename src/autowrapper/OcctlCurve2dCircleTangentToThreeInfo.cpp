#include "OcctlCurve2dCircleTangentToThreeInfo.h"

#include "OcctlRepId.h"

int OcctlCurve2dCircleTangentToThreeInfo::get_struct_version() const { return struct_version; }
void OcctlCurve2dCircleTangentToThreeInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlCurve2dCircleTangentToThreeInfo::get_p_next() const { return p_next; }
void OcctlCurve2dCircleTangentToThreeInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlCurve2dCircleTangentToThreeInfo::get_curve_a() const { return curve_a; }
void OcctlCurve2dCircleTangentToThreeInfo::set_curve_a(int64_t val) { curve_a = val; }

int OcctlCurve2dCircleTangentToThreeInfo::get_qualifier_a() const { return qualifier_a; }
void OcctlCurve2dCircleTangentToThreeInfo::set_qualifier_a(int val) { qualifier_a = val; }

int64_t OcctlCurve2dCircleTangentToThreeInfo::get_curve_b() const { return curve_b; }
void OcctlCurve2dCircleTangentToThreeInfo::set_curve_b(int64_t val) { curve_b = val; }

int OcctlCurve2dCircleTangentToThreeInfo::get_qualifier_b() const { return qualifier_b; }
void OcctlCurve2dCircleTangentToThreeInfo::set_qualifier_b(int val) { qualifier_b = val; }

int64_t OcctlCurve2dCircleTangentToThreeInfo::get_curve_c() const { return curve_c; }
void OcctlCurve2dCircleTangentToThreeInfo::set_curve_c(int64_t val) { curve_c = val; }

int OcctlCurve2dCircleTangentToThreeInfo::get_qualifier_c() const { return qualifier_c; }
void OcctlCurve2dCircleTangentToThreeInfo::set_qualifier_c(int val) { qualifier_c = val; }

double OcctlCurve2dCircleTangentToThreeInfo::get_initial_parameter_a() const { return initial_parameter_a; }
void OcctlCurve2dCircleTangentToThreeInfo::set_initial_parameter_a(double val) { initial_parameter_a = val; }

double OcctlCurve2dCircleTangentToThreeInfo::get_initial_parameter_b() const { return initial_parameter_b; }
void OcctlCurve2dCircleTangentToThreeInfo::set_initial_parameter_b(double val) { initial_parameter_b = val; }

double OcctlCurve2dCircleTangentToThreeInfo::get_initial_parameter_c() const { return initial_parameter_c; }
void OcctlCurve2dCircleTangentToThreeInfo::set_initial_parameter_c(double val) { initial_parameter_c = val; }

double OcctlCurve2dCircleTangentToThreeInfo::get_tolerance() const { return tolerance; }
void OcctlCurve2dCircleTangentToThreeInfo::set_tolerance(double val) { tolerance = val; }

void OcctlCurve2dCircleTangentToThreeInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlCurve2dCircleTangentToThreeInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlCurve2dCircleTangentToThreeInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlCurve2dCircleTangentToThreeInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlCurve2dCircleTangentToThreeInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_curve_a"), &OcctlCurve2dCircleTangentToThreeInfo::get_curve_a);
    godot::ClassDB::bind_method(godot::D_METHOD("set_curve_a", "val"), &OcctlCurve2dCircleTangentToThreeInfo::set_curve_a);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "curve_a"), "set_curve_a", "get_curve_a");
    godot::ClassDB::bind_method(godot::D_METHOD("get_qualifier_a"), &OcctlCurve2dCircleTangentToThreeInfo::get_qualifier_a);
    godot::ClassDB::bind_method(godot::D_METHOD("set_qualifier_a", "val"), &OcctlCurve2dCircleTangentToThreeInfo::set_qualifier_a);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "qualifier_a"), "set_qualifier_a", "get_qualifier_a");
    godot::ClassDB::bind_method(godot::D_METHOD("get_curve_b"), &OcctlCurve2dCircleTangentToThreeInfo::get_curve_b);
    godot::ClassDB::bind_method(godot::D_METHOD("set_curve_b", "val"), &OcctlCurve2dCircleTangentToThreeInfo::set_curve_b);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "curve_b"), "set_curve_b", "get_curve_b");
    godot::ClassDB::bind_method(godot::D_METHOD("get_qualifier_b"), &OcctlCurve2dCircleTangentToThreeInfo::get_qualifier_b);
    godot::ClassDB::bind_method(godot::D_METHOD("set_qualifier_b", "val"), &OcctlCurve2dCircleTangentToThreeInfo::set_qualifier_b);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "qualifier_b"), "set_qualifier_b", "get_qualifier_b");
    godot::ClassDB::bind_method(godot::D_METHOD("get_curve_c"), &OcctlCurve2dCircleTangentToThreeInfo::get_curve_c);
    godot::ClassDB::bind_method(godot::D_METHOD("set_curve_c", "val"), &OcctlCurve2dCircleTangentToThreeInfo::set_curve_c);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "curve_c"), "set_curve_c", "get_curve_c");
    godot::ClassDB::bind_method(godot::D_METHOD("get_qualifier_c"), &OcctlCurve2dCircleTangentToThreeInfo::get_qualifier_c);
    godot::ClassDB::bind_method(godot::D_METHOD("set_qualifier_c", "val"), &OcctlCurve2dCircleTangentToThreeInfo::set_qualifier_c);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "qualifier_c"), "set_qualifier_c", "get_qualifier_c");
    godot::ClassDB::bind_method(godot::D_METHOD("get_initial_parameter_a"), &OcctlCurve2dCircleTangentToThreeInfo::get_initial_parameter_a);
    godot::ClassDB::bind_method(godot::D_METHOD("set_initial_parameter_a", "val"), &OcctlCurve2dCircleTangentToThreeInfo::set_initial_parameter_a);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "initial_parameter_a"), "set_initial_parameter_a", "get_initial_parameter_a");
    godot::ClassDB::bind_method(godot::D_METHOD("get_initial_parameter_b"), &OcctlCurve2dCircleTangentToThreeInfo::get_initial_parameter_b);
    godot::ClassDB::bind_method(godot::D_METHOD("set_initial_parameter_b", "val"), &OcctlCurve2dCircleTangentToThreeInfo::set_initial_parameter_b);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "initial_parameter_b"), "set_initial_parameter_b", "get_initial_parameter_b");
    godot::ClassDB::bind_method(godot::D_METHOD("get_initial_parameter_c"), &OcctlCurve2dCircleTangentToThreeInfo::get_initial_parameter_c);
    godot::ClassDB::bind_method(godot::D_METHOD("set_initial_parameter_c", "val"), &OcctlCurve2dCircleTangentToThreeInfo::set_initial_parameter_c);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "initial_parameter_c"), "set_initial_parameter_c", "get_initial_parameter_c");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlCurve2dCircleTangentToThreeInfo::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlCurve2dCircleTangentToThreeInfo::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
}

occtl_curve2d_circle_tangent_to_three_info_t OcctlCurve2dCircleTangentToThreeInfo::to_c() const {
    occtl_curve2d_circle_tangent_to_three_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.curve_a.bits = static_cast<uint64_t>(curve_a);
    result.qualifier_a = static_cast<occtl_curve2d_tangency_qualifier_t>(qualifier_a);
    result.curve_b.bits = static_cast<uint64_t>(curve_b);
    result.qualifier_b = static_cast<occtl_curve2d_tangency_qualifier_t>(qualifier_b);
    result.curve_c.bits = static_cast<uint64_t>(curve_c);
    result.qualifier_c = static_cast<occtl_curve2d_tangency_qualifier_t>(qualifier_c);
    result.initial_parameter_a = initial_parameter_a;
    result.initial_parameter_b = initial_parameter_b;
    result.initial_parameter_c = initial_parameter_c;
    result.tolerance = tolerance;
    return result;
}

Ref<OcctlCurve2dCircleTangentToThreeInfo> OcctlCurve2dCircleTangentToThreeInfo::from_c(const occtl_curve2d_circle_tangent_to_three_info_t& val) {
    Ref<OcctlCurve2dCircleTangentToThreeInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->curve_a = static_cast<int64_t>(val.curve_a.bits);
    r->qualifier_a = static_cast<int>(val.qualifier_a);
    r->curve_b = static_cast<int64_t>(val.curve_b.bits);
    r->qualifier_b = static_cast<int>(val.qualifier_b);
    r->curve_c = static_cast<int64_t>(val.curve_c.bits);
    r->qualifier_c = static_cast<int>(val.qualifier_c);
    r->initial_parameter_a = val.initial_parameter_a;
    r->initial_parameter_b = val.initial_parameter_b;
    r->initial_parameter_c = val.initial_parameter_c;
    r->tolerance = val.tolerance;
    return r;
}

void OcctlCurve2dCircleTangentToThreeInfo::copy_from_c(const occtl_curve2d_circle_tangent_to_three_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    curve_a = static_cast<int64_t>(val.curve_a.bits);
    qualifier_a = static_cast<int>(val.qualifier_a);
    curve_b = static_cast<int64_t>(val.curve_b.bits);
    qualifier_b = static_cast<int>(val.qualifier_b);
    curve_c = static_cast<int64_t>(val.curve_c.bits);
    qualifier_c = static_cast<int>(val.qualifier_c);
    initial_parameter_a = val.initial_parameter_a;
    initial_parameter_b = val.initial_parameter_b;
    initial_parameter_c = val.initial_parameter_c;
    tolerance = val.tolerance;
}
