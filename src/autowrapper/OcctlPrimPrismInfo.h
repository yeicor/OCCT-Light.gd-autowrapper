#ifndef OCCTLPRIMPRISMINFO_H
#define OCCTLPRIMPRISMINFO_H

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
#include "OcctlVector3.h"

using namespace godot;

class OcctlPrimPrismInfo : public godot::RefCounted {
    GDCLASS(OcctlPrimPrismInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t profile;
    Ref<OcctlVector3> direction;
    int copy;
    int canonize;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_profile() const;
    void set_profile(int64_t val);
    Ref<OcctlVector3> get_direction() const;
    void set_direction(Ref<OcctlVector3> val);
    int get_copy() const;
    void set_copy(int val);
    int get_canonize() const;
    void set_canonize(int val);

    occtl_prim_prism_info_t to_c() const;
    static Ref<OcctlPrimPrismInfo> from_c(const occtl_prim_prism_info_t& val);
    void copy_from_c(const occtl_prim_prism_info_t& val);
};

#endif // OCCTLPRIMPRISMINFO_H
