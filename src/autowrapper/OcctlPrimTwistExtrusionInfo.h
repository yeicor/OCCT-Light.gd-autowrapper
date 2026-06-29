#ifndef OCCTLPRIMTWISTEXTRUSIONINFO_H
#define OCCTLPRIMTWISTEXTRUSIONINFO_H

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
#include "occtl/occtl_prim_sweep.h"

#include "OcctlNodeId.h"
#include "OcctlAxis1Placement.h"

using namespace godot;

class OcctlPrimTwistExtrusionInfo : public godot::RefCounted {
    GDCLASS(OcctlPrimTwistExtrusionInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t profile_wire;
    Ref<OcctlAxis1Placement> axis;
    double height;
    double angle;
    int section_count;
    int make_solid;
    int ruled;
    double pres3d;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_profile_wire() const;
    void set_profile_wire(int64_t val);
    Ref<OcctlAxis1Placement> get_axis() const;
    void set_axis(Ref<OcctlAxis1Placement> val);
    double get_height() const;
    void set_height(double val);
    double get_angle() const;
    void set_angle(double val);
    int get_section_count() const;
    void set_section_count(int val);
    int get_make_solid() const;
    void set_make_solid(int val);
    int get_ruled() const;
    void set_ruled(int val);
    double get_pres3d() const;
    void set_pres3d(double val);

    occtl_prim_twist_extrusion_info_t to_c() const;
    static Ref<OcctlPrimTwistExtrusionInfo> from_c(const occtl_prim_twist_extrusion_info_t& val);
    void copy_from_c(const occtl_prim_twist_extrusion_info_t& val);
};

#endif // OCCTLPRIMTWISTEXTRUSIONINFO_H
