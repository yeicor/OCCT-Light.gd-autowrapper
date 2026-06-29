#ifndef OCCTLTOPOOFFSETFEATURESOPTIONS_H
#define OCCTLTOPOOFFSETFEATURESOPTIONS_H

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

class OcctlTopoOffsetFeaturesOptions : public godot::RefCounted {
    GDCLASS(OcctlTopoOffsetFeaturesOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t root;
    PackedInt64Array selections;
    int selection_count;
    double base_offset;
    double selection_offset;
    double tolerance;
    int join;
    int intersection;
    int self_intersection;
    int remove_internal_edges;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_root() const;
    void set_root(int64_t val);
    PackedInt64Array get_selections() const;
    void set_selections(PackedInt64Array val);
    int get_selection_count() const;
    void set_selection_count(int val);
    double get_base_offset() const;
    void set_base_offset(double val);
    double get_selection_offset() const;
    void set_selection_offset(double val);
    double get_tolerance() const;
    void set_tolerance(double val);
    int get_join() const;
    void set_join(int val);
    int get_intersection() const;
    void set_intersection(int val);
    int get_self_intersection() const;
    void set_self_intersection(int val);
    int get_remove_internal_edges() const;
    void set_remove_internal_edges(int val);

    occtl_topo_offset_features_options_t to_c() const;
    static Ref<OcctlTopoOffsetFeaturesOptions> from_c(const occtl_topo_offset_features_options_t& val);
    void copy_from_c(const occtl_topo_offset_features_options_t& val);
};

#endif // OCCTLTOPOOFFSETFEATURESOPTIONS_H
