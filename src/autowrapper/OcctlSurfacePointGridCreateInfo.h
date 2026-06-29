#ifndef OCCTLSURFACEPOINTGRIDCREATEINFO_H
#define OCCTLSURFACEPOINTGRIDCREATEINFO_H

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
#include "occtl/occtl_surfaces.h"

#include "OcctlPoint3.h"

using namespace godot;

class OcctlSurfacePointGridCreateInfo : public godot::RefCounted {
    GDCLASS(OcctlSurfacePointGridCreateInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    Array points;
    mutable std::vector<occtl_point3_t> _cache_points;
    int u_point_count;
    int v_point_count;
    int mode;
    int degree_min;
    int degree_max;
    int is_u_periodic;
    double tolerance;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    Array get_points() const;
    void set_points(Array val);
    int get_u_point_count() const;
    void set_u_point_count(int val);
    int get_v_point_count() const;
    void set_v_point_count(int val);
    int get_mode() const;
    void set_mode(int val);
    int get_degree_min() const;
    void set_degree_min(int val);
    int get_degree_max() const;
    void set_degree_max(int val);
    int get_is_u_periodic() const;
    void set_is_u_periodic(int val);
    double get_tolerance() const;
    void set_tolerance(double val);

    occtl_surface_point_grid_create_info_t to_c() const;
    static Ref<OcctlSurfacePointGridCreateInfo> from_c(const occtl_surface_point_grid_create_info_t& val);
    void copy_from_c(const occtl_surface_point_grid_create_info_t& val);
};

#endif // OCCTLSURFACEPOINTGRIDCREATEINFO_H
