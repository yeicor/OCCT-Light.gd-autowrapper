#ifndef OCCTLBOOLOPTIONS_H
#define OCCTLBOOLOPTIONS_H

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
#include "occtl/occtl_bool.h"


using namespace godot;

class OcctlBoolOptions : public godot::RefCounted {
    GDCLASS(OcctlBoolOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    double fuzzy_value;
    int run_parallel;
    int simplify_result;
    double simplify_angular_tolerance;
    int build_history;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    double get_fuzzy_value() const;
    void set_fuzzy_value(double val);
    int get_run_parallel() const;
    void set_run_parallel(int val);
    int get_simplify_result() const;
    void set_simplify_result(int val);
    double get_simplify_angular_tolerance() const;
    void set_simplify_angular_tolerance(double val);
    int get_build_history() const;
    void set_build_history(int val);

    occtl_bool_options_t to_c() const;
    static Ref<OcctlBoolOptions> from_c(const occtl_bool_options_t& val);
    void copy_from_c(const occtl_bool_options_t& val);
};

#endif // OCCTLBOOLOPTIONS_H
