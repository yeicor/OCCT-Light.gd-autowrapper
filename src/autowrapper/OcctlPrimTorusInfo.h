#ifndef OCCTLPRIMTORUSINFO_H
#define OCCTLPRIMTORUSINFO_H

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
#include "occtl/occtl_prim_solid.h"

#include "OcctlAxis2Placement.h"

using namespace godot;

class OcctlPrimTorusInfo : public godot::RefCounted {
    GDCLASS(OcctlPrimTorusInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    Ref<OcctlAxis2Placement> placement;
    double r1;
    double r2;
    double angle1;
    double angle2;
    double angle;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    Ref<OcctlAxis2Placement> get_placement() const;
    void set_placement(Ref<OcctlAxis2Placement> val);
    double get_r1() const;
    void set_r1(double val);
    double get_r2() const;
    void set_r2(double val);
    double get_angle1() const;
    void set_angle1(double val);
    double get_angle2() const;
    void set_angle2(double val);
    double get_angle() const;
    void set_angle(double val);

    occtl_prim_torus_info_t to_c() const;
    static Ref<OcctlPrimTorusInfo> from_c(const occtl_prim_torus_info_t& val);
    void copy_from_c(const occtl_prim_torus_info_t& val);
};

#endif // OCCTLPRIMTORUSINFO_H
