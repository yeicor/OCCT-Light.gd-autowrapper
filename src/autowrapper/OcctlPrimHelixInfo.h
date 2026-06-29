#ifndef OCCTLPRIMHELIXINFO_H
#define OCCTLPRIMHELIXINFO_H

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

class OcctlPrimHelixInfo : public godot::RefCounted {
    GDCLASS(OcctlPrimHelixInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    Ref<OcctlAxis2Placement> placement;
    double radius;
    double pitch;
    double height;
    int left_handed;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    Ref<OcctlAxis2Placement> get_placement() const;
    void set_placement(Ref<OcctlAxis2Placement> val);
    double get_radius() const;
    void set_radius(double val);
    double get_pitch() const;
    void set_pitch(double val);
    double get_height() const;
    void set_height(double val);
    int get_left_handed() const;
    void set_left_handed(int val);

    occtl_prim_helix_info_t to_c() const;
    static Ref<OcctlPrimHelixInfo> from_c(const occtl_prim_helix_info_t& val);
    void copy_from_c(const occtl_prim_helix_info_t& val);
};

#endif // OCCTLPRIMHELIXINFO_H
