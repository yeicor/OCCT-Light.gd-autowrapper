#ifndef OCCTLSURFACECURVEGRIDCREATEINFO_H
#define OCCTLSURFACECURVEGRIDCREATEINFO_H

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

#include "OcctlRepId.h"

using namespace godot;

class OcctlSurfaceCurveGridCreateInfo : public godot::RefCounted {
    GDCLASS(OcctlSurfaceCurveGridCreateInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    PackedInt64Array u_curves;
    int u_curve_count;
    PackedInt64Array v_curves;
    int v_curve_count;
    double tolerance;
    int parallel;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    PackedInt64Array get_u_curves() const;
    void set_u_curves(PackedInt64Array val);
    int get_u_curve_count() const;
    void set_u_curve_count(int val);
    PackedInt64Array get_v_curves() const;
    void set_v_curves(PackedInt64Array val);
    int get_v_curve_count() const;
    void set_v_curve_count(int val);
    double get_tolerance() const;
    void set_tolerance(double val);
    int get_parallel() const;
    void set_parallel(int val);

    occtl_surface_curve_grid_create_info_t to_c() const;
    static Ref<OcctlSurfaceCurveGridCreateInfo> from_c(const occtl_surface_curve_grid_create_info_t& val);
    void copy_from_c(const occtl_surface_curve_grid_create_info_t& val);
};

#endif // OCCTLSURFACECURVEGRIDCREATEINFO_H
