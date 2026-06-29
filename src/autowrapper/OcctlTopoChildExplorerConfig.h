#ifndef OCCTLTOPOCHILDEXPLORERCONFIG_H
#define OCCTLTOPOCHILDEXPLORERCONFIG_H

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
#include "occtl/occtl_topo_relation.h"


using namespace godot;

class OcctlTopoChildExplorerConfig : public godot::RefCounted {
    GDCLASS(OcctlTopoChildExplorerConfig, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int mode;
    int target_kind;
    int avoid_kind;
    int emit_avoid_kind;
    int accumulate_location;
    int accumulate_orientation;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int get_mode() const;
    void set_mode(int val);
    int get_target_kind() const;
    void set_target_kind(int val);
    int get_avoid_kind() const;
    void set_avoid_kind(int val);
    int get_emit_avoid_kind() const;
    void set_emit_avoid_kind(int val);
    int get_accumulate_location() const;
    void set_accumulate_location(int val);
    int get_accumulate_orientation() const;
    void set_accumulate_orientation(int val);

    occtl_topo_child_explorer_config_t to_c() const;
    static Ref<OcctlTopoChildExplorerConfig> from_c(const occtl_topo_child_explorer_config_t& val);
    void copy_from_c(const occtl_topo_child_explorer_config_t& val);
};

#endif // OCCTLTOPOCHILDEXPLORERCONFIG_H
