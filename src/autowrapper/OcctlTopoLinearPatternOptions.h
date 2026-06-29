#ifndef OCCTLTOPOLINEARPATTERNOPTIONS_H
#define OCCTLTOPOLINEARPATTERNOPTIONS_H

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

#include "OcctlVector3.h"

using namespace godot;

class OcctlTopoLinearPatternOptions : public godot::RefCounted {
    GDCLASS(OcctlTopoLinearPatternOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    Ref<OcctlVector3> direction;
    int count;
    double step;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    Ref<OcctlVector3> get_direction() const;
    void set_direction(Ref<OcctlVector3> val);
    int get_count() const;
    void set_count(int val);
    double get_step() const;
    void set_step(double val);

    occtl_topo_linear_pattern_options_t to_c() const;
    static Ref<OcctlTopoLinearPatternOptions> from_c(const occtl_topo_linear_pattern_options_t& val);
    void copy_from_c(const occtl_topo_linear_pattern_options_t& val);
};

#endif // OCCTLTOPOLINEARPATTERNOPTIONS_H
