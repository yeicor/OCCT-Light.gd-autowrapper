#ifndef OCCTLCURVEINTERPOLATEDINFO_H
#define OCCTLCURVEINTERPOLATEDINFO_H

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

class OcctlCurveInterpolatedInfo : public godot::RefCounted {
    GDCLASS(OcctlCurveInterpolatedInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    Array points;
    mutable std::vector<occtl_point3_t> _cache_points;
    int point_count;
    int is_periodic;
    double tolerance;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    Array get_points() const;
    void set_points(Array val);
    int get_point_count() const;
    void set_point_count(int val);
    int get_is_periodic() const;
    void set_is_periodic(int val);
    double get_tolerance() const;
    void set_tolerance(double val);

    occtl_curve_interpolated_info_t to_c() const;
    static Ref<OcctlCurveInterpolatedInfo> from_c(const occtl_curve_interpolated_info_t& val);
    void copy_from_c(const occtl_curve_interpolated_info_t& val);
};

#endif // OCCTLCURVEINTERPOLATEDINFO_H
