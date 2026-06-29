#ifndef OCCTLTOPORELATIONOPTIONS_H
#define OCCTLTOPORELATIONOPTIONS_H

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

class OcctlTopoRelationOptions : public godot::RefCounted {
    GDCLASS(OcctlTopoRelationOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    double tolerance;
    int include_tangent_contacts;
    int include_overlaps;
    int include_lower_dimension_results;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    double get_tolerance() const;
    void set_tolerance(double val);
    int get_include_tangent_contacts() const;
    void set_include_tangent_contacts(int val);
    int get_include_overlaps() const;
    void set_include_overlaps(int val);
    int get_include_lower_dimension_results() const;
    void set_include_lower_dimension_results(int val);

    occtl_topo_relation_options_t to_c() const;
    static Ref<OcctlTopoRelationOptions> from_c(const occtl_topo_relation_options_t& val);
    void copy_from_c(const occtl_topo_relation_options_t& val);
};

#endif // OCCTLTOPORELATIONOPTIONS_H
