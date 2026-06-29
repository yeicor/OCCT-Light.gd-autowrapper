#ifndef OCCTLPRIMBRAKEFORMEDOPTIONS_H
#define OCCTLPRIMBRAKEFORMEDOPTIONS_H

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
#include "occtl/occtl_prim_feature.h"

#include "OcctlNodeId.h"

using namespace godot;

class OcctlPrimBrakeFormedOptions : public godot::RefCounted {
    GDCLASS(OcctlPrimBrakeFormedOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t line;
    double thickness;
    PackedFloat64Array station_widths;
    int station_width_count;
    int side;
    int join;
    int approximate;
    double tolerance;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_line() const;
    void set_line(int64_t val);
    double get_thickness() const;
    void set_thickness(double val);
    PackedFloat64Array get_station_widths() const;
    void set_station_widths(PackedFloat64Array val);
    int get_station_width_count() const;
    void set_station_width_count(int val);
    int get_side() const;
    void set_side(int val);
    int get_join() const;
    void set_join(int val);
    int get_approximate() const;
    void set_approximate(int val);
    double get_tolerance() const;
    void set_tolerance(double val);

    occtl_prim_brake_formed_options_t to_c() const;
    static Ref<OcctlPrimBrakeFormedOptions> from_c(const occtl_prim_brake_formed_options_t& val);
    void copy_from_c(const occtl_prim_brake_formed_options_t& val);
};

#endif // OCCTLPRIMBRAKEFORMEDOPTIONS_H
