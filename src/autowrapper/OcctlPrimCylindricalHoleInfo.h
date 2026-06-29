#ifndef OCCTLPRIMCYLINDRICALHOLEINFO_H
#define OCCTLPRIMCYLINDRICALHOLEINFO_H

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
#include "OcctlAxis1Placement.h"

using namespace godot;

class OcctlPrimCylindricalHoleInfo : public godot::RefCounted {
    GDCLASS(OcctlPrimCylindricalHoleInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t base_shape;
    Ref<OcctlAxis1Placement> axis;
    double radius;
    int kind;
    double p_from;
    double p_to;
    double length;
    int with_control;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_base_shape() const;
    void set_base_shape(int64_t val);
    Ref<OcctlAxis1Placement> get_axis() const;
    void set_axis(Ref<OcctlAxis1Placement> val);
    double get_radius() const;
    void set_radius(double val);
    int get_kind() const;
    void set_kind(int val);
    double get_p_from() const;
    void set_p_from(double val);
    double get_p_to() const;
    void set_p_to(double val);
    double get_length() const;
    void set_length(double val);
    int get_with_control() const;
    void set_with_control(int val);

    occtl_prim_cylindrical_hole_info_t to_c() const;
    static Ref<OcctlPrimCylindricalHoleInfo> from_c(const occtl_prim_cylindrical_hole_info_t& val);
    void copy_from_c(const occtl_prim_cylindrical_hole_info_t& val);
};

#endif // OCCTLPRIMCYLINDRICALHOLEINFO_H
