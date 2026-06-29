#ifndef OCCTLPRIMPIPEINFO_H
#define OCCTLPRIMPIPEINFO_H

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

using namespace godot;

class OcctlPrimPipeInfo : public godot::RefCounted {
    GDCLASS(OcctlPrimPipeInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t profile;
    int64_t spine_wire;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_profile() const;
    void set_profile(int64_t val);
    int64_t get_spine_wire() const;
    void set_spine_wire(int64_t val);

    occtl_prim_pipe_info_t to_c() const;
    static Ref<OcctlPrimPipeInfo> from_c(const occtl_prim_pipe_info_t& val);
    void copy_from_c(const occtl_prim_pipe_info_t& val);
};

#endif // OCCTLPRIMPIPEINFO_H
