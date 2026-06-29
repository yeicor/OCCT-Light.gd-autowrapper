#ifndef OCCTLPRIMARCCENTERINFO_H
#define OCCTLPRIMARCCENTERINFO_H

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

class OcctlPrimArcCenterInfo : public godot::RefCounted {
    GDCLASS(OcctlPrimArcCenterInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    Ref<OcctlAxis2Placement> placement;
    double radius;
    double start_angle;
    double end_angle;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    Ref<OcctlAxis2Placement> get_placement() const;
    void set_placement(Ref<OcctlAxis2Placement> val);
    double get_radius() const;
    void set_radius(double val);
    double get_start_angle() const;
    void set_start_angle(double val);
    double get_end_angle() const;
    void set_end_angle(double val);

    occtl_prim_arc_center_info_t to_c() const;
    static Ref<OcctlPrimArcCenterInfo> from_c(const occtl_prim_arc_center_info_t& val);
    void copy_from_c(const occtl_prim_arc_center_info_t& val);
};

#endif // OCCTLPRIMARCCENTERINFO_H
