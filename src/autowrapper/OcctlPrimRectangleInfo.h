#ifndef OCCTLPRIMRECTANGLEINFO_H
#define OCCTLPRIMRECTANGLEINFO_H

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
#include "occtl/occtl_prim_sketch.h"

#include "OcctlAxis2Placement.h"

using namespace godot;

class OcctlPrimRectangleInfo : public godot::RefCounted {
    GDCLASS(OcctlPrimRectangleInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    Ref<OcctlAxis2Placement> placement;
    double width;
    double height;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    Ref<OcctlAxis2Placement> get_placement() const;
    void set_placement(Ref<OcctlAxis2Placement> val);
    double get_width() const;
    void set_width(double val);
    double get_height() const;
    void set_height(double val);

    occtl_prim_rectangle_info_t to_c() const;
    static Ref<OcctlPrimRectangleInfo> from_c(const occtl_prim_rectangle_info_t& val);
    void copy_from_c(const occtl_prim_rectangle_info_t& val);
};

#endif // OCCTLPRIMRECTANGLEINFO_H
