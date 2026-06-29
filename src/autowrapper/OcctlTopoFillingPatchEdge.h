#ifndef OCCTLTOPOFILLINGPATCHEDGE_H
#define OCCTLTOPOFILLINGPATCHEDGE_H

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
#include "occtl/occtl_topo_algo.h"

#include "OcctlNodeId.h"

using namespace godot;

class OcctlTopoFillingPatchEdge : public godot::RefCounted {
    GDCLASS(OcctlTopoFillingPatchEdge, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int64_t edge;
    int64_t support_face;
    int continuity;
    int is_boundary;

    int64_t get_edge() const;
    void set_edge(int64_t val);
    int64_t get_support_face() const;
    void set_support_face(int64_t val);
    int get_continuity() const;
    void set_continuity(int val);
    int get_is_boundary() const;
    void set_is_boundary(int val);

    occtl_topo_filling_patch_edge_t to_c() const;
    static Ref<OcctlTopoFillingPatchEdge> from_c(const occtl_topo_filling_patch_edge_t& val);
    void copy_from_c(const occtl_topo_filling_patch_edge_t& val);
};

#endif // OCCTLTOPOFILLINGPATCHEDGE_H
