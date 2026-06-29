#ifndef OCCTLTOPOSEWOPTIONS_H
#define OCCTLTOPOSEWOPTIONS_H

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


using namespace godot;

class OcctlTopoSewOptions : public godot::RefCounted {
    GDCLASS(OcctlTopoSewOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    double tolerance;
    double min_tolerance;
    double max_tolerance;
    int cutting;
    int same_parameter_mode;
    int non_manifold_mode;
    int parallel;
    int history_mode;
    int face_analysis;
    int floating_edges_mode;
    int local_tolerances_mode;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    double get_tolerance() const;
    void set_tolerance(double val);
    double get_min_tolerance() const;
    void set_min_tolerance(double val);
    double get_max_tolerance() const;
    void set_max_tolerance(double val);
    int get_cutting() const;
    void set_cutting(int val);
    int get_same_parameter_mode() const;
    void set_same_parameter_mode(int val);
    int get_non_manifold_mode() const;
    void set_non_manifold_mode(int val);
    int get_parallel() const;
    void set_parallel(int val);
    int get_history_mode() const;
    void set_history_mode(int val);
    int get_face_analysis() const;
    void set_face_analysis(int val);
    int get_floating_edges_mode() const;
    void set_floating_edges_mode(int val);
    int get_local_tolerances_mode() const;
    void set_local_tolerances_mode(int val);

    occtl_topo_sew_options_t to_c() const;
    static Ref<OcctlTopoSewOptions> from_c(const occtl_topo_sew_options_t& val);
    void copy_from_c(const occtl_topo_sew_options_t& val);
};

#endif // OCCTLTOPOSEWOPTIONS_H
