#ifndef OCCTLTOPOFILLINGOPTIONS_H
#define OCCTLTOPOFILLINGOPTIONS_H

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

class OcctlTopoFillingOptions : public godot::RefCounted {
    GDCLASS(OcctlTopoFillingOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    PackedInt64Array edges;
    int edge_count;
    int continuity;
    int degree;
    int point_count_on_curve;
    int iteration_count;
    int anisotropic;
    double tolerance_2d;
    double tolerance_3d;
    double angular_tolerance;
    double curvature_tolerance;
    int max_degree;
    int max_segments;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    PackedInt64Array get_edges() const;
    void set_edges(PackedInt64Array val);
    int get_edge_count() const;
    void set_edge_count(int val);
    int get_continuity() const;
    void set_continuity(int val);
    int get_degree() const;
    void set_degree(int val);
    int get_point_count_on_curve() const;
    void set_point_count_on_curve(int val);
    int get_iteration_count() const;
    void set_iteration_count(int val);
    int get_anisotropic() const;
    void set_anisotropic(int val);
    double get_tolerance_2d() const;
    void set_tolerance_2d(double val);
    double get_tolerance_3d() const;
    void set_tolerance_3d(double val);
    double get_angular_tolerance() const;
    void set_angular_tolerance(double val);
    double get_curvature_tolerance() const;
    void set_curvature_tolerance(double val);
    int get_max_degree() const;
    void set_max_degree(int val);
    int get_max_segments() const;
    void set_max_segments(int val);

    occtl_topo_filling_options_t to_c() const;
    static Ref<OcctlTopoFillingOptions> from_c(const occtl_topo_filling_options_t& val);
    void copy_from_c(const occtl_topo_filling_options_t& val);
};

#endif // OCCTLTOPOFILLINGOPTIONS_H
