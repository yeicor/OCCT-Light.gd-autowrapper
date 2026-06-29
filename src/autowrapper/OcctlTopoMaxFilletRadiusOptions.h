#ifndef OCCTLTOPOMAXFILLETRADIUSOPTIONS_H
#define OCCTLTOPOMAXFILLETRADIUSOPTIONS_H

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

class OcctlTopoMaxFilletRadiusOptions : public godot::RefCounted {
    GDCLASS(OcctlTopoMaxFilletRadiusOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t root;
    PackedInt64Array edges;
    int edge_count;
    double min_radius;
    double max_radius;
    double tolerance;
    int max_iterations;

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
    double get_min_radius() const;
    void set_min_radius(double val);
    double get_max_radius() const;
    void set_max_radius(double val);
    double get_tolerance() const;
    void set_tolerance(double val);
    int get_max_iterations() const;
    void set_max_iterations(int val);

    occtl_topo_max_fillet_radius_options_t to_c() const;
    static Ref<OcctlTopoMaxFilletRadiusOptions> from_c(const occtl_topo_max_fillet_radius_options_t& val);
    void copy_from_c(const occtl_topo_max_fillet_radius_options_t& val);
};

#endif // OCCTLTOPOMAXFILLETRADIUSOPTIONS_H
