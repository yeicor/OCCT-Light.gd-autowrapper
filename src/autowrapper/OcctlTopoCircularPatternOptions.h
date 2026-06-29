#ifndef OCCTLTOPOCIRCULARPATTERNOPTIONS_H
#define OCCTLTOPOCIRCULARPATTERNOPTIONS_H

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
#include "occtl/occtl_topo_algo.h"

#include "OcctlAxis1Placement.h"

using namespace godot;

class OcctlTopoCircularPatternOptions : public godot::RefCounted {
    GDCLASS(OcctlTopoCircularPatternOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    Ref<OcctlAxis1Placement> axis;
    int count;
    double angle;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    Ref<OcctlAxis1Placement> get_axis() const;
    void set_axis(Ref<OcctlAxis1Placement> val);
    int get_count() const;
    void set_count(int val);
    double get_angle() const;
    void set_angle(double val);

    occtl_topo_circular_pattern_options_t to_c() const;
    static Ref<OcctlTopoCircularPatternOptions> from_c(const occtl_topo_circular_pattern_options_t& val);
    void copy_from_c(const occtl_topo_circular_pattern_options_t& val);
};

#endif // OCCTLTOPOCIRCULARPATTERNOPTIONS_H
