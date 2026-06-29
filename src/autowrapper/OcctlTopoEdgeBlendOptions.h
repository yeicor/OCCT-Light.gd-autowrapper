#ifndef OCCTLTOPOEDGEBLENDOPTIONS_H
#define OCCTLTOPOEDGEBLENDOPTIONS_H

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

class OcctlTopoEdgeBlendOptions : public godot::RefCounted {
    GDCLASS(OcctlTopoEdgeBlendOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t root;
    PackedInt64Array edges;
    int edge_count;
    double radius;
    int chamfer_mode;
    double chamfer_dist1;
    double chamfer_dist2;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_root() const;
    void set_root(int64_t val);
    PackedInt64Array get_edges() const;
    void set_edges(PackedInt64Array val);
    int get_edge_count() const;
    void set_edge_count(int val);
    double get_radius() const;
    void set_radius(double val);
    int get_chamfer_mode() const;
    void set_chamfer_mode(int val);
    double get_chamfer_dist1() const;
    void set_chamfer_dist1(double val);
    double get_chamfer_dist2() const;
    void set_chamfer_dist2(double val);

    occtl_topo_edge_blend_options_t to_c() const;
    static Ref<OcctlTopoEdgeBlendOptions> from_c(const occtl_topo_edge_blend_options_t& val);
    void copy_from_c(const occtl_topo_edge_blend_options_t& val);
};

#endif // OCCTLTOPOEDGEBLENDOPTIONS_H
