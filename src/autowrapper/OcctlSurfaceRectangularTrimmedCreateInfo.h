#ifndef OCCTLSURFACERECTANGULARTRIMMEDCREATEINFO_H
#define OCCTLSURFACERECTANGULARTRIMMEDCREATEINFO_H

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

class OcctlSurfaceRectangularTrimmedCreateInfo : public godot::RefCounted {
    GDCLASS(OcctlSurfaceRectangularTrimmedCreateInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t basis;
    double u_first;
    double u_last;
    double v_first;
    double v_last;
    int u_sense;
    int v_sense;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_basis() const;
    void set_basis(int64_t val);
    double get_u_first() const;
    void set_u_first(double val);
    double get_u_last() const;
    void set_u_last(double val);
    double get_v_first() const;
    void set_v_first(double val);
    double get_v_last() const;
    void set_v_last(double val);
    int get_u_sense() const;
    void set_u_sense(int val);
    int get_v_sense() const;
    void set_v_sense(int val);

    occtl_surface_rectangular_trimmed_create_info_t to_c() const;
    static Ref<OcctlSurfaceRectangularTrimmedCreateInfo> from_c(const occtl_surface_rectangular_trimmed_create_info_t& val);
    void copy_from_c(const occtl_surface_rectangular_trimmed_create_info_t& val);
};

#endif // OCCTLSURFACERECTANGULARTRIMMEDCREATEINFO_H
