#ifndef OCCTLCURVE2DBLENDARCINFO_H
#define OCCTLCURVE2DBLENDARCINFO_H

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

class OcctlCurve2dBlendArcInfo : public godot::RefCounted {
    GDCLASS(OcctlCurve2dBlendArcInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t curve_a;
    int qualifier_a;
    int64_t curve_b;
    int qualifier_b;
    double radius;
    int long_arc;
    double tolerance;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_curve_a() const;
    void set_curve_a(int64_t val);
    int get_qualifier_a() const;
    void set_qualifier_a(int val);
    int64_t get_curve_b() const;
    void set_curve_b(int64_t val);
    int get_qualifier_b() const;
    void set_qualifier_b(int val);
    double get_radius() const;
    void set_radius(double val);
    int get_long_arc() const;
    void set_long_arc(int val);
    double get_tolerance() const;
    void set_tolerance(double val);

    occtl_curve2d_blend_arc_info_t to_c() const;
    static Ref<OcctlCurve2dBlendArcInfo> from_c(const occtl_curve2d_blend_arc_info_t& val);
    void copy_from_c(const occtl_curve2d_blend_arc_info_t& val);
};

#endif // OCCTLCURVE2DBLENDARCINFO_H
