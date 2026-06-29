#ifndef OCCTLHEALUNIFYSAMEDOMAINOPTIONS_H
#define OCCTLHEALUNIFYSAMEDOMAINOPTIONS_H

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
#include "occtl/occtl_heal.h"


using namespace godot;

class OcctlHealUnifySameDomainOptions : public godot::RefCounted {
    GDCLASS(OcctlHealUnifySameDomainOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int unify_edges;
    int unify_faces;
    int concat_bspline;
    int allow_internal_edges;
    int safe_input;
    double linear_tolerance;
    double angular_tolerance;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int get_unify_edges() const;
    void set_unify_edges(int val);
    int get_unify_faces() const;
    void set_unify_faces(int val);
    int get_concat_bspline() const;
    void set_concat_bspline(int val);
    int get_allow_internal_edges() const;
    void set_allow_internal_edges(int val);
    int get_safe_input() const;
    void set_safe_input(int val);
    double get_linear_tolerance() const;
    void set_linear_tolerance(double val);
    double get_angular_tolerance() const;
    void set_angular_tolerance(double val);

    occtl_heal_unify_same_domain_options_t to_c() const;
    static Ref<OcctlHealUnifySameDomainOptions> from_c(const occtl_heal_unify_same_domain_options_t& val);
    void copy_from_c(const occtl_heal_unify_same_domain_options_t& val);
};

#endif // OCCTLHEALUNIFYSAMEDOMAINOPTIONS_H
