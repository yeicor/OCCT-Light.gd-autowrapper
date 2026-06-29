#ifndef OCCTLCURVEBEZIERSEGMENTSOPTIONS_H
#define OCCTLCURVEBEZIERSEGMENTSOPTIONS_H

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
#include "occtl/occtl_curves_common.h"


using namespace godot;

class OcctlCurveBezierSegmentsOptions : public godot::RefCounted {
    GDCLASS(OcctlCurveBezierSegmentsOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int use_range;
    double u_first;
    double u_last;
    double parametric_tolerance;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int get_use_range() const;
    void set_use_range(int val);
    double get_u_first() const;
    void set_u_first(double val);
    double get_u_last() const;
    void set_u_last(double val);
    double get_parametric_tolerance() const;
    void set_parametric_tolerance(double val);

    occtl_curve_bezier_segments_options_t to_c() const;
    static Ref<OcctlCurveBezierSegmentsOptions> from_c(const occtl_curve_bezier_segments_options_t& val);
    void copy_from_c(const occtl_curve_bezier_segments_options_t& val);
};

#endif // OCCTLCURVEBEZIERSEGMENTSOPTIONS_H
