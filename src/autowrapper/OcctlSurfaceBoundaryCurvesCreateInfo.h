#ifndef OCCTLSURFACEBOUNDARYCURVESCREATEINFO_H
#define OCCTLSURFACEBOUNDARYCURVESCREATEINFO_H

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

class OcctlSurfaceBoundaryCurvesCreateInfo : public godot::RefCounted {
    GDCLASS(OcctlSurfaceBoundaryCurvesCreateInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    PackedInt64Array curves;
    int curve_count;
    int style;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    PackedInt64Array get_curves() const;
    void set_curves(PackedInt64Array val);
    int get_curve_count() const;
    void set_curve_count(int val);
    int get_style() const;
    void set_style(int val);

    occtl_surface_boundary_curves_create_info_t to_c() const;
    static Ref<OcctlSurfaceBoundaryCurvesCreateInfo> from_c(const occtl_surface_boundary_curves_create_info_t& val);
    void copy_from_c(const occtl_surface_boundary_curves_create_info_t& val);
};

#endif // OCCTLSURFACEBOUNDARYCURVESCREATEINFO_H
