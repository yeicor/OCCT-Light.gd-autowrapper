#ifndef OCCTLPRIMREVOLINFO_H
#define OCCTLPRIMREVOLINFO_H

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

class OcctlPrimRevolInfo : public godot::RefCounted {
    GDCLASS(OcctlPrimRevolInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t profile;
    Ref<OcctlAxis1Placement> axis;
    double angle;
    int copy;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_profile() const;
    void set_profile(int64_t val);
    Ref<OcctlAxis1Placement> get_axis() const;
    void set_axis(Ref<OcctlAxis1Placement> val);
    double get_angle() const;
    void set_angle(double val);
    int get_copy() const;
    void set_copy(int val);

    occtl_prim_revol_info_t to_c() const;
    static Ref<OcctlPrimRevolInfo> from_c(const occtl_prim_revol_info_t& val);
    void copy_from_c(const occtl_prim_revol_info_t& val);
};

#endif // OCCTLPRIMREVOLINFO_H
