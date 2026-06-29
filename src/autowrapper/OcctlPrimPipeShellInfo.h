#ifndef OCCTLPRIMPIPESHELLINFO_H
#define OCCTLPRIMPIPESHELLINFO_H

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
#include "OcctlAxis2Placement.h"
#include "OcctlDirection3.h"

using namespace godot;

class OcctlPrimPipeShellInfo : public godot::RefCounted {
    GDCLASS(OcctlPrimPipeShellInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t spine_wire;
    PackedInt64Array profiles;
    int profile_count;
    int mode;
    Ref<OcctlAxis2Placement> mode_axis;
    Ref<OcctlDirection3> mode_binormal;
    int transition;
    int with_contact;
    int with_correction;
    int make_solid;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_spine_wire() const;
    void set_spine_wire(int64_t val);
    PackedInt64Array get_profiles() const;
    void set_profiles(PackedInt64Array val);
    int get_profile_count() const;
    void set_profile_count(int val);
    int get_mode() const;
    void set_mode(int val);
    Ref<OcctlAxis2Placement> get_mode_axis() const;
    void set_mode_axis(Ref<OcctlAxis2Placement> val);
    Ref<OcctlDirection3> get_mode_binormal() const;
    void set_mode_binormal(Ref<OcctlDirection3> val);
    int get_transition() const;
    void set_transition(int val);
    int get_with_contact() const;
    void set_with_contact(int val);
    int get_with_correction() const;
    void set_with_correction(int val);
    int get_make_solid() const;
    void set_make_solid(int val);

    occtl_prim_pipe_shell_info_t to_c() const;
    static Ref<OcctlPrimPipeShellInfo> from_c(const occtl_prim_pipe_shell_info_t& val);
    void copy_from_c(const occtl_prim_pipe_shell_info_t& val);
};

#endif // OCCTLPRIMPIPESHELLINFO_H
