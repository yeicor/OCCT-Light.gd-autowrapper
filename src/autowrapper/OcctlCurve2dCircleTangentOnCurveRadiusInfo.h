#ifndef OCCTLCURVE2DCIRCLETANGENTONCURVERADIUSINFO_H
#define OCCTLCURVE2DCIRCLETANGENTONCURVERADIUSINFO_H

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

using namespace godot;

class OcctlCurve2dCircleTangentOnCurveRadiusInfo : public godot::RefCounted {
    GDCLASS(OcctlCurve2dCircleTangentOnCurveRadiusInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t curve;
    int qualifier;
    int64_t center_curve;
    double radius;
    double tolerance;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_curve() const;
    void set_curve(int64_t val);
    int get_qualifier() const;
    void set_qualifier(int val);
    int64_t get_center_curve() const;
    void set_center_curve(int64_t val);
    double get_radius() const;
    void set_radius(double val);
    double get_tolerance() const;
    void set_tolerance(double val);

    occtl_curve2d_circle_tangent_on_curve_radius_info_t to_c() const;
    static Ref<OcctlCurve2dCircleTangentOnCurveRadiusInfo> from_c(const occtl_curve2d_circle_tangent_on_curve_radius_info_t& val);
    void copy_from_c(const occtl_curve2d_circle_tangent_on_curve_radius_info_t& val);
};

#endif // OCCTLCURVE2DCIRCLETANGENTONCURVERADIUSINFO_H
