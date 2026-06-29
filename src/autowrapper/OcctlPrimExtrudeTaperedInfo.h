#ifndef OCCTLPRIMEXTRUDETAPEREDINFO_H
#define OCCTLPRIMEXTRUDETAPEREDINFO_H

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

using namespace godot;

class OcctlPrimExtrudeTaperedInfo : public godot::RefCounted {
    GDCLASS(OcctlPrimExtrudeTaperedInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t profile_face;
    double height;
    double taper_angle;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_profile_face() const;
    void set_profile_face(int64_t val);
    double get_height() const;
    void set_height(double val);
    double get_taper_angle() const;
    void set_taper_angle(double val);

    occtl_prim_extrude_tapered_info_t to_c() const;
    static Ref<OcctlPrimExtrudeTaperedInfo> from_c(const occtl_prim_extrude_tapered_info_t& val);
    void copy_from_c(const occtl_prim_extrude_tapered_info_t& val);
};

#endif // OCCTLPRIMEXTRUDETAPEREDINFO_H
