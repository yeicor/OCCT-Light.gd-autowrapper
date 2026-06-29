#include "OcctlCurveBezierSegmentsOptions.h"


int OcctlCurveBezierSegmentsOptions::get_struct_version() const { return struct_version; }
void OcctlCurveBezierSegmentsOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlCurveBezierSegmentsOptions::get_p_next() const { return p_next; }
void OcctlCurveBezierSegmentsOptions::set_p_next(int64_t val) { p_next = val; }

int OcctlCurveBezierSegmentsOptions::get_use_range() const { return use_range; }
void OcctlCurveBezierSegmentsOptions::set_use_range(int val) { use_range = val; }

double OcctlCurveBezierSegmentsOptions::get_u_first() const { return u_first; }
void OcctlCurveBezierSegmentsOptions::set_u_first(double val) { u_first = val; }

double OcctlCurveBezierSegmentsOptions::get_u_last() const { return u_last; }
void OcctlCurveBezierSegmentsOptions::set_u_last(double val) { u_last = val; }

double OcctlCurveBezierSegmentsOptions::get_parametric_tolerance() const { return parametric_tolerance; }
void OcctlCurveBezierSegmentsOptions::set_parametric_tolerance(double val) { parametric_tolerance = val; }

void OcctlCurveBezierSegmentsOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlCurveBezierSegmentsOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlCurveBezierSegmentsOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlCurveBezierSegmentsOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlCurveBezierSegmentsOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_use_range"), &OcctlCurveBezierSegmentsOptions::get_use_range);
    godot::ClassDB::bind_method(godot::D_METHOD("set_use_range", "val"), &OcctlCurveBezierSegmentsOptions::set_use_range);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "use_range"), "set_use_range", "get_use_range");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_first"), &OcctlCurveBezierSegmentsOptions::get_u_first);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_first", "val"), &OcctlCurveBezierSegmentsOptions::set_u_first);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "u_first"), "set_u_first", "get_u_first");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_last"), &OcctlCurveBezierSegmentsOptions::get_u_last);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_last", "val"), &OcctlCurveBezierSegmentsOptions::set_u_last);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "u_last"), "set_u_last", "get_u_last");
    godot::ClassDB::bind_method(godot::D_METHOD("get_parametric_tolerance"), &OcctlCurveBezierSegmentsOptions::get_parametric_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_parametric_tolerance", "val"), &OcctlCurveBezierSegmentsOptions::set_parametric_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "parametric_tolerance"), "set_parametric_tolerance", "get_parametric_tolerance");
}

occtl_curve_bezier_segments_options_t OcctlCurveBezierSegmentsOptions::to_c() const {
    occtl_curve_bezier_segments_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.use_range = use_range;
    result.u_first = u_first;
    result.u_last = u_last;
    result.parametric_tolerance = parametric_tolerance;
    return result;
}

Ref<OcctlCurveBezierSegmentsOptions> OcctlCurveBezierSegmentsOptions::from_c(const occtl_curve_bezier_segments_options_t& val) {
    Ref<OcctlCurveBezierSegmentsOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->use_range = val.use_range;
    r->u_first = val.u_first;
    r->u_last = val.u_last;
    r->parametric_tolerance = val.parametric_tolerance;
    return r;
}

void OcctlCurveBezierSegmentsOptions::copy_from_c(const occtl_curve_bezier_segments_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    use_range = val.use_range;
    u_first = val.u_first;
    u_last = val.u_last;
    parametric_tolerance = val.parametric_tolerance;
}
