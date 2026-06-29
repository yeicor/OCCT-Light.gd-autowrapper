#ifndef OCCTLEDGEVIEW_H
#define OCCTLEDGEVIEW_H

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
#include "occtl/occtl_topo.h"

#include "OcctlNodeId.h"

using namespace godot;

class OcctlEdgeView : public godot::RefCounted {
    GDCLASS(OcctlEdgeView, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    double t_min;
    double t_max;
    double tolerance;
    int64_t start_vertex;
    int64_t end_vertex;
    int internal_vertex_count;
    int face_count;
    int has_curve;
    int is_degenerated;
    int is_closed;
    int same_parameter;
    int same_range;
    int is_manifold;
    int is_boundary;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    double get_t_min() const;
    void set_t_min(double val);
    double get_t_max() const;
    void set_t_max(double val);
    double get_tolerance() const;
    void set_tolerance(double val);
    int64_t get_start_vertex() const;
    void set_start_vertex(int64_t val);
    int64_t get_end_vertex() const;
    void set_end_vertex(int64_t val);
    int get_internal_vertex_count() const;
    void set_internal_vertex_count(int val);
    int get_face_count() const;
    void set_face_count(int val);
    int get_has_curve() const;
    void set_has_curve(int val);
    int get_is_degenerated() const;
    void set_is_degenerated(int val);
    int get_is_closed() const;
    void set_is_closed(int val);
    int get_same_parameter() const;
    void set_same_parameter(int val);
    int get_same_range() const;
    void set_same_range(int val);
    int get_is_manifold() const;
    void set_is_manifold(int val);
    int get_is_boundary() const;
    void set_is_boundary(int val);

    occtl_edge_view_t to_c() const;
    static Ref<OcctlEdgeView> from_c(const occtl_edge_view_t& val);
    void copy_from_c(const occtl_edge_view_t& val);
};

#endif // OCCTLEDGEVIEW_H
