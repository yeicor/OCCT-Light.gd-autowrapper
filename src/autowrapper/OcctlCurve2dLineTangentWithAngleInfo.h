#ifndef OCCTLCURVE2DLINETANGENTWITHANGLEINFO_H
#define OCCTLCURVE2DLINETANGENTWITHANGLEINFO_H

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
#include "occtl/occtl_curves2d.h"

#include "OcctlRepId.h"
#include "OcctlGeom2dLine.h"

using namespace godot;

class OcctlCurve2dLineTangentWithAngleInfo : public godot::RefCounted {
    GDCLASS(OcctlCurve2dLineTangentWithAngleInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t curve;
    int qualifier;
    Ref<OcctlGeom2dLine> reference_line;
    double angle_radians;
    int use_initial_parameter;
    double initial_parameter;
    double tolerance;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_curve() const;
    void set_curve(int64_t val);
    int get_qualifier() const;
    void set_qualifier(int val);
    Ref<OcctlGeom2dLine> get_reference_line() const;
    void set_reference_line(Ref<OcctlGeom2dLine> val);
    double get_angle_radians() const;
    void set_angle_radians(double val);
    int get_use_initial_parameter() const;
    void set_use_initial_parameter(int val);
    double get_initial_parameter() const;
    void set_initial_parameter(double val);
    double get_tolerance() const;
    void set_tolerance(double val);

    occtl_curve2d_line_tangent_with_angle_info_t to_c() const;
    static Ref<OcctlCurve2dLineTangentWithAngleInfo> from_c(const occtl_curve2d_line_tangent_with_angle_info_t& val);
    void copy_from_c(const occtl_curve2d_line_tangent_with_angle_info_t& val);
};

#endif // OCCTLCURVE2DLINETANGENTWITHANGLEINFO_H
