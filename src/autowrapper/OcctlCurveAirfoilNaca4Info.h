#ifndef OCCTLCURVEAIRFOILNACA4INFO_H
#define OCCTLCURVEAIRFOILNACA4INFO_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/vector3.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/transform3d.hpp>
#include <godot_cpp/variant/aabb.hpp>
#include <godot_cpp/variant/color.hpp>
#include <cstdint>
#include <vector>
#include "occtl/occtl_curves.h"


using namespace godot;

class OcctlCurveAirfoilNaca4Info : public godot::RefCounted {
    GDCLASS(OcctlCurveAirfoilNaca4Info, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    double max_camber;
    double camber_position;
    double thickness;
    double chord_length;
    int point_count;
    int finite_trailing_edge;
    int degree_min;
    int degree_max;
    double tolerance;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    double get_max_camber() const;
    void set_max_camber(double val);
    double get_camber_position() const;
    void set_camber_position(double val);
    double get_thickness() const;
    void set_thickness(double val);
    double get_chord_length() const;
    void set_chord_length(double val);
    int get_point_count() const;
    void set_point_count(int val);
    int get_finite_trailing_edge() const;
    void set_finite_trailing_edge(int val);
    int get_degree_min() const;
    void set_degree_min(int val);
    int get_degree_max() const;
    void set_degree_max(int val);
    double get_tolerance() const;
    void set_tolerance(double val);

    occtl_curve_airfoil_naca4_info_t to_c() const;
    static Ref<OcctlCurveAirfoilNaca4Info> from_c(const occtl_curve_airfoil_naca4_info_t& val);
    void copy_from_c(const occtl_curve_airfoil_naca4_info_t& val);
};

#endif // OCCTLCURVEAIRFOILNACA4INFO_H
