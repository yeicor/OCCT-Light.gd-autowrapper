#include "OcctlCurve2dLineTangentWithAngleInfo.h"

#include "OcctlRepId.h"
#include "OcctlGeom2dLine.h"

int OcctlCurve2dLineTangentWithAngleInfo::get_struct_version() const { return struct_version; }
void OcctlCurve2dLineTangentWithAngleInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlCurve2dLineTangentWithAngleInfo::get_p_next() const { return p_next; }
void OcctlCurve2dLineTangentWithAngleInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlCurve2dLineTangentWithAngleInfo::get_curve() const { return curve; }
void OcctlCurve2dLineTangentWithAngleInfo::set_curve(int64_t val) { curve = val; }

int OcctlCurve2dLineTangentWithAngleInfo::get_qualifier() const { return qualifier; }
void OcctlCurve2dLineTangentWithAngleInfo::set_qualifier(int val) { qualifier = val; }

Ref<OcctlGeom2dLine> OcctlCurve2dLineTangentWithAngleInfo::get_reference_line() const { return reference_line; }
void OcctlCurve2dLineTangentWithAngleInfo::set_reference_line(Ref<OcctlGeom2dLine> val) { reference_line = val; }

double OcctlCurve2dLineTangentWithAngleInfo::get_angle_radians() const { return angle_radians; }
void OcctlCurve2dLineTangentWithAngleInfo::set_angle_radians(double val) { angle_radians = val; }

int OcctlCurve2dLineTangentWithAngleInfo::get_use_initial_parameter() const { return use_initial_parameter; }
void OcctlCurve2dLineTangentWithAngleInfo::set_use_initial_parameter(int val) { use_initial_parameter = val; }

double OcctlCurve2dLineTangentWithAngleInfo::get_initial_parameter() const { return initial_parameter; }
void OcctlCurve2dLineTangentWithAngleInfo::set_initial_parameter(double val) { initial_parameter = val; }

double OcctlCurve2dLineTangentWithAngleInfo::get_tolerance() const { return tolerance; }
void OcctlCurve2dLineTangentWithAngleInfo::set_tolerance(double val) { tolerance = val; }

void OcctlCurve2dLineTangentWithAngleInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlCurve2dLineTangentWithAngleInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlCurve2dLineTangentWithAngleInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlCurve2dLineTangentWithAngleInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlCurve2dLineTangentWithAngleInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_curve"), &OcctlCurve2dLineTangentWithAngleInfo::get_curve);
    godot::ClassDB::bind_method(godot::D_METHOD("set_curve", "val"), &OcctlCurve2dLineTangentWithAngleInfo::set_curve);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "curve"), "set_curve", "get_curve");
    godot::ClassDB::bind_method(godot::D_METHOD("get_qualifier"), &OcctlCurve2dLineTangentWithAngleInfo::get_qualifier);
    godot::ClassDB::bind_method(godot::D_METHOD("set_qualifier", "val"), &OcctlCurve2dLineTangentWithAngleInfo::set_qualifier);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "qualifier"), "set_qualifier", "get_qualifier");
    godot::ClassDB::bind_method(godot::D_METHOD("get_reference_line"), &OcctlCurve2dLineTangentWithAngleInfo::get_reference_line);
    godot::ClassDB::bind_method(godot::D_METHOD("set_reference_line", "val"), &OcctlCurve2dLineTangentWithAngleInfo::set_reference_line);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "reference_line"), "set_reference_line", "get_reference_line");
    godot::ClassDB::bind_method(godot::D_METHOD("get_angle_radians"), &OcctlCurve2dLineTangentWithAngleInfo::get_angle_radians);
    godot::ClassDB::bind_method(godot::D_METHOD("set_angle_radians", "val"), &OcctlCurve2dLineTangentWithAngleInfo::set_angle_radians);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "angle_radians"), "set_angle_radians", "get_angle_radians");
    godot::ClassDB::bind_method(godot::D_METHOD("get_use_initial_parameter"), &OcctlCurve2dLineTangentWithAngleInfo::get_use_initial_parameter);
    godot::ClassDB::bind_method(godot::D_METHOD("set_use_initial_parameter", "val"), &OcctlCurve2dLineTangentWithAngleInfo::set_use_initial_parameter);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "use_initial_parameter"), "set_use_initial_parameter", "get_use_initial_parameter");
    godot::ClassDB::bind_method(godot::D_METHOD("get_initial_parameter"), &OcctlCurve2dLineTangentWithAngleInfo::get_initial_parameter);
    godot::ClassDB::bind_method(godot::D_METHOD("set_initial_parameter", "val"), &OcctlCurve2dLineTangentWithAngleInfo::set_initial_parameter);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "initial_parameter"), "set_initial_parameter", "get_initial_parameter");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlCurve2dLineTangentWithAngleInfo::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlCurve2dLineTangentWithAngleInfo::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
}

occtl_curve2d_line_tangent_with_angle_info_t OcctlCurve2dLineTangentWithAngleInfo::to_c() const {
    occtl_curve2d_line_tangent_with_angle_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.curve.bits = static_cast<uint64_t>(curve);
    result.qualifier = static_cast<occtl_curve2d_tangency_qualifier_t>(qualifier);
    result.reference_line = reference_line->to_c();
    result.angle_radians = angle_radians;
    result.use_initial_parameter = use_initial_parameter;
    result.initial_parameter = initial_parameter;
    result.tolerance = tolerance;
    return result;
}

Ref<OcctlCurve2dLineTangentWithAngleInfo> OcctlCurve2dLineTangentWithAngleInfo::from_c(const occtl_curve2d_line_tangent_with_angle_info_t& val) {
    Ref<OcctlCurve2dLineTangentWithAngleInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->curve = static_cast<int64_t>(val.curve.bits);
    r->qualifier = static_cast<int>(val.qualifier);
    r->reference_line = OcctlGeom2dLine::from_c(val.reference_line);
    r->angle_radians = val.angle_radians;
    r->use_initial_parameter = val.use_initial_parameter;
    r->initial_parameter = val.initial_parameter;
    r->tolerance = val.tolerance;
    return r;
}

void OcctlCurve2dLineTangentWithAngleInfo::copy_from_c(const occtl_curve2d_line_tangent_with_angle_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    curve = static_cast<int64_t>(val.curve.bits);
    qualifier = static_cast<int>(val.qualifier);
    reference_line = OcctlGeom2dLine::from_c(val.reference_line);
    angle_radians = val.angle_radians;
    use_initial_parameter = val.use_initial_parameter;
    initial_parameter = val.initial_parameter;
    tolerance = val.tolerance;
}
