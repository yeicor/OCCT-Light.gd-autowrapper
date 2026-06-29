#ifndef OCCTLSELECTGROUPOPTIONS_H
#define OCCTLSELECTGROUPOPTIONS_H

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
#include "occtl/occtl_topo_build.h"


using namespace godot;

class OcctlSelectGroupOptions : public godot::RefCounted {
    GDCLASS(OcctlSelectGroupOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int key;
    int axis;
    double tolerance;
    float color_tolerance;
    int include_missing;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int get_key() const;
    void set_key(int val);
    int get_axis() const;
    void set_axis(int val);
    double get_tolerance() const;
    void set_tolerance(double val);
    float get_color_tolerance() const;
    void set_color_tolerance(float val);
    int get_include_missing() const;
    void set_include_missing(int val);

    occtl_select_group_options_t to_c() const;
    static Ref<OcctlSelectGroupOptions> from_c(const occtl_select_group_options_t& val);
    void copy_from_c(const occtl_select_group_options_t& val);
};

#endif // OCCTLSELECTGROUPOPTIONS_H
