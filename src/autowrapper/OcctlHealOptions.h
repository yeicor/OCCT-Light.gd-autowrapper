#ifndef OCCTLHEALOPTIONS_H
#define OCCTLHEALOPTIONS_H

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
#include "occtl/occtl_heal.h"


using namespace godot;

class OcctlHealOptions : public godot::RefCounted {
    GDCLASS(OcctlHealOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int mode;
    double tolerance;
    int fix_same_parameter;
    int fix_small_edges;
    int fix_face_orient;
    int fix_missing_seam;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int get_mode() const;
    void set_mode(int val);
    double get_tolerance() const;
    void set_tolerance(double val);
    int get_fix_same_parameter() const;
    void set_fix_same_parameter(int val);
    int get_fix_small_edges() const;
    void set_fix_small_edges(int val);
    int get_fix_face_orient() const;
    void set_fix_face_orient(int val);
    int get_fix_missing_seam() const;
    void set_fix_missing_seam(int val);

    occtl_heal_options_t to_c() const;
    static Ref<OcctlHealOptions> from_c(const occtl_heal_options_t& val);
    void copy_from_c(const occtl_heal_options_t& val);
};

#endif // OCCTLHEALOPTIONS_H
