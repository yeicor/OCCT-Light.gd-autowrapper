#ifndef OCCTLCURVEINTERSECTIONPOINT_H
#define OCCTLCURVEINTERSECTIONPOINT_H

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

#include "OcctlPoint3.h"

using namespace godot;

class OcctlCurveIntersectionPoint : public godot::RefCounted {
    GDCLASS(OcctlCurveIntersectionPoint, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    Ref<OcctlPoint3> point;
    double param_a;
    double param_b;

    Ref<OcctlPoint3> get_point() const;
    void set_point(Ref<OcctlPoint3> val);
    double get_param_a() const;
    void set_param_a(double val);
    double get_param_b() const;
    void set_param_b(double val);

    occtl_curve_intersection_point_t to_c() const;
    static Ref<OcctlCurveIntersectionPoint> from_c(const occtl_curve_intersection_point_t& val);
    void copy_from_c(const occtl_curve_intersection_point_t& val);
};

#endif // OCCTLCURVEINTERSECTIONPOINT_H
