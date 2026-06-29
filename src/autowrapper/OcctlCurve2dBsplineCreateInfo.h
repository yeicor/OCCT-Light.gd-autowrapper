#ifndef OCCTLCURVE2DBSPLINECREATEINFO_H
#define OCCTLCURVE2DBSPLINECREATEINFO_H

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

#include "OcctlPoint2.h"

using namespace godot;

class OcctlCurve2dBsplineCreateInfo : public godot::RefCounted {
    GDCLASS(OcctlCurve2dBsplineCreateInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    Array poles;
    mutable std::vector<occtl_point2_t> _cache_poles;
    int pole_count;
    PackedFloat64Array weights;
    PackedFloat64Array knots;
    PackedInt32Array multiplicities;
    int knot_count;
    int degree;
    int is_periodic;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    Array get_poles() const;
    void set_poles(Array val);
    int get_pole_count() const;
    void set_pole_count(int val);
    PackedFloat64Array get_weights() const;
    void set_weights(PackedFloat64Array val);
    PackedFloat64Array get_knots() const;
    void set_knots(PackedFloat64Array val);
    PackedInt32Array get_multiplicities() const;
    void set_multiplicities(PackedInt32Array val);
    int get_knot_count() const;
    void set_knot_count(int val);
    int get_degree() const;
    void set_degree(int val);
    int get_is_periodic() const;
    void set_is_periodic(int val);

    occtl_curve2d_bspline_create_info_t to_c() const;
    static Ref<OcctlCurve2dBsplineCreateInfo> from_c(const occtl_curve2d_bspline_create_info_t& val);
    void copy_from_c(const occtl_curve2d_bspline_create_info_t& val);
};

#endif // OCCTLCURVE2DBSPLINECREATEINFO_H
