#ifndef OCCTLMESHOPTIONS_H
#define OCCTLMESHOPTIONS_H

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
#include "occtl/occtl_mesh.h"

#include "OcctlAabb3.h"

using namespace godot;

class OcctlMeshOptions : public godot::RefCounted {
    GDCLASS(OcctlMeshOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    double deflection;
    double angle;
    double deflection_interior;
    double angle_interior;
    double min_size;
    int in_parallel;
    int relative;
    int internal_vertices_mode;
    int control_surface_deflection;
    int control_surface_deflection_all;
    int clean_model;
    int adjust_min_size;
    int force_face_deflection;
    int allow_quality_decrease;
    int use_bbox;
    Ref<OcctlAabb3> bbox;
    double deviation_coefficient;
    double deviation_angle;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    double get_deflection() const;
    void set_deflection(double val);
    double get_angle() const;
    void set_angle(double val);
    double get_deflection_interior() const;
    void set_deflection_interior(double val);
    double get_angle_interior() const;
    void set_angle_interior(double val);
    double get_min_size() const;
    void set_min_size(double val);
    int get_in_parallel() const;
    void set_in_parallel(int val);
    int get_relative() const;
    void set_relative(int val);
    int get_internal_vertices_mode() const;
    void set_internal_vertices_mode(int val);
    int get_control_surface_deflection() const;
    void set_control_surface_deflection(int val);
    int get_control_surface_deflection_all() const;
    void set_control_surface_deflection_all(int val);
    int get_clean_model() const;
    void set_clean_model(int val);
    int get_adjust_min_size() const;
    void set_adjust_min_size(int val);
    int get_force_face_deflection() const;
    void set_force_face_deflection(int val);
    int get_allow_quality_decrease() const;
    void set_allow_quality_decrease(int val);
    int get_use_bbox() const;
    void set_use_bbox(int val);
    Ref<OcctlAabb3> get_bbox() const;
    void set_bbox(Ref<OcctlAabb3> val);
    double get_deviation_coefficient() const;
    void set_deviation_coefficient(double val);
    double get_deviation_angle() const;
    void set_deviation_angle(double val);

    occtl_mesh_options_t to_c() const;
    static Ref<OcctlMeshOptions> from_c(const occtl_mesh_options_t& val);
    void copy_from_c(const occtl_mesh_options_t& val);
};

#endif // OCCTLMESHOPTIONS_H
