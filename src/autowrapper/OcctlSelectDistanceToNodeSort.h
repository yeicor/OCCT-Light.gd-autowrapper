#ifndef OCCTLSELECTDISTANCETONODESORT_H
#define OCCTLSELECTDISTANCETONODESORT_H

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
#include "occtl/occtl_topo_build.h"

#include "OcctlNodeId.h"

using namespace godot;

class OcctlSelectDistanceToNodeSort : public godot::RefCounted {
    GDCLASS(OcctlSelectDistanceToNodeSort, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t target;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_target() const;
    void set_target(int64_t val);

    occtl_select_distance_to_node_sort_t to_c() const;
    static Ref<OcctlSelectDistanceToNodeSort> from_c(const occtl_select_distance_to_node_sort_t& val);
    void copy_from_c(const occtl_select_distance_to_node_sort_t& val);
};

#endif // OCCTLSELECTDISTANCETONODESORT_H
