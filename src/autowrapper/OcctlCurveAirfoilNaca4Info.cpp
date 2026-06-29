#include "OcctlCurveAirfoilNaca4Info.h"


int OcctlCurveAirfoilNaca4Info::get_struct_version() const { return struct_version; }
void OcctlCurveAirfoilNaca4Info::set_struct_version(int val) { struct_version = val; }

int64_t OcctlCurveAirfoilNaca4Info::get_p_next() const { return p_next; }
void OcctlCurveAirfoilNaca4Info::set_p_next(int64_t val) { p_next = val; }

double OcctlCurveAirfoilNaca4Info::get_max_camber() const { return max_camber; }
void OcctlCurveAirfoilNaca4Info::set_max_camber(double val) { max_camber = val; }

double OcctlCurveAirfoilNaca4Info::get_camber_position() const { return camber_position; }
void OcctlCurveAirfoilNaca4Info::set_camber_position(double val) { camber_position = val; }

double OcctlCurveAirfoilNaca4Info::get_thickness() const { return thickness; }
void OcctlCurveAirfoilNaca4Info::set_thickness(double val) { thickness = val; }

double OcctlCurveAirfoilNaca4Info::get_chord_length() const { return chord_length; }
void OcctlCurveAirfoilNaca4Info::set_chord_length(double val) { chord_length = val; }

int OcctlCurveAirfoilNaca4Info::get_point_count() const { return point_count; }
void OcctlCurveAirfoilNaca4Info::set_point_count(int val) { point_count = val; }

int OcctlCurveAirfoilNaca4Info::get_finite_trailing_edge() const { return finite_trailing_edge; }
void OcctlCurveAirfoilNaca4Info::set_finite_trailing_edge(int val) { finite_trailing_edge = val; }

int OcctlCurveAirfoilNaca4Info::get_degree_min() const { return degree_min; }
void OcctlCurveAirfoilNaca4Info::set_degree_min(int val) { degree_min = val; }

int OcctlCurveAirfoilNaca4Info::get_degree_max() const { return degree_max; }
void OcctlCurveAirfoilNaca4Info::set_degree_max(int val) { degree_max = val; }

double OcctlCurveAirfoilNaca4Info::get_tolerance() const { return tolerance; }
void OcctlCurveAirfoilNaca4Info::set_tolerance(double val) { tolerance = val; }

void OcctlCurveAirfoilNaca4Info::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlCurveAirfoilNaca4Info::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlCurveAirfoilNaca4Info::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlCurveAirfoilNaca4Info::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlCurveAirfoilNaca4Info::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_max_camber"), &OcctlCurveAirfoilNaca4Info::get_max_camber);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max_camber", "val"), &OcctlCurveAirfoilNaca4Info::set_max_camber);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max_camber"), "set_max_camber", "get_max_camber");
    godot::ClassDB::bind_method(godot::D_METHOD("get_camber_position"), &OcctlCurveAirfoilNaca4Info::get_camber_position);
    godot::ClassDB::bind_method(godot::D_METHOD("set_camber_position", "val"), &OcctlCurveAirfoilNaca4Info::set_camber_position);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "camber_position"), "set_camber_position", "get_camber_position");
    godot::ClassDB::bind_method(godot::D_METHOD("get_thickness"), &OcctlCurveAirfoilNaca4Info::get_thickness);
    godot::ClassDB::bind_method(godot::D_METHOD("set_thickness", "val"), &OcctlCurveAirfoilNaca4Info::set_thickness);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "thickness"), "set_thickness", "get_thickness");
    godot::ClassDB::bind_method(godot::D_METHOD("get_chord_length"), &OcctlCurveAirfoilNaca4Info::get_chord_length);
    godot::ClassDB::bind_method(godot::D_METHOD("set_chord_length", "val"), &OcctlCurveAirfoilNaca4Info::set_chord_length);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "chord_length"), "set_chord_length", "get_chord_length");
    godot::ClassDB::bind_method(godot::D_METHOD("get_point_count"), &OcctlCurveAirfoilNaca4Info::get_point_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_point_count", "val"), &OcctlCurveAirfoilNaca4Info::set_point_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "point_count"), "set_point_count", "get_point_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_finite_trailing_edge"), &OcctlCurveAirfoilNaca4Info::get_finite_trailing_edge);
    godot::ClassDB::bind_method(godot::D_METHOD("set_finite_trailing_edge", "val"), &OcctlCurveAirfoilNaca4Info::set_finite_trailing_edge);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "finite_trailing_edge"), "set_finite_trailing_edge", "get_finite_trailing_edge");
    godot::ClassDB::bind_method(godot::D_METHOD("get_degree_min"), &OcctlCurveAirfoilNaca4Info::get_degree_min);
    godot::ClassDB::bind_method(godot::D_METHOD("set_degree_min", "val"), &OcctlCurveAirfoilNaca4Info::set_degree_min);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "degree_min"), "set_degree_min", "get_degree_min");
    godot::ClassDB::bind_method(godot::D_METHOD("get_degree_max"), &OcctlCurveAirfoilNaca4Info::get_degree_max);
    godot::ClassDB::bind_method(godot::D_METHOD("set_degree_max", "val"), &OcctlCurveAirfoilNaca4Info::set_degree_max);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "degree_max"), "set_degree_max", "get_degree_max");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlCurveAirfoilNaca4Info::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlCurveAirfoilNaca4Info::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
}

occtl_curve_airfoil_naca4_info_t OcctlCurveAirfoilNaca4Info::to_c() const {
    occtl_curve_airfoil_naca4_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.max_camber = max_camber;
    result.camber_position = camber_position;
    result.thickness = thickness;
    result.chord_length = chord_length;
    result.point_count = point_count;
    result.finite_trailing_edge = finite_trailing_edge;
    result.degree_min = degree_min;
    result.degree_max = degree_max;
    result.tolerance = tolerance;
    return result;
}

Ref<OcctlCurveAirfoilNaca4Info> OcctlCurveAirfoilNaca4Info::from_c(const occtl_curve_airfoil_naca4_info_t& val) {
    Ref<OcctlCurveAirfoilNaca4Info> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->max_camber = val.max_camber;
    r->camber_position = val.camber_position;
    r->thickness = val.thickness;
    r->chord_length = val.chord_length;
    r->point_count = val.point_count;
    r->finite_trailing_edge = val.finite_trailing_edge;
    r->degree_min = val.degree_min;
    r->degree_max = val.degree_max;
    r->tolerance = val.tolerance;
    return r;
}

void OcctlCurveAirfoilNaca4Info::copy_from_c(const occtl_curve_airfoil_naca4_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    max_camber = val.max_camber;
    camber_position = val.camber_position;
    thickness = val.thickness;
    chord_length = val.chord_length;
    point_count = val.point_count;
    finite_trailing_edge = val.finite_trailing_edge;
    degree_min = val.degree_min;
    degree_max = val.degree_max;
    tolerance = val.tolerance;
}
