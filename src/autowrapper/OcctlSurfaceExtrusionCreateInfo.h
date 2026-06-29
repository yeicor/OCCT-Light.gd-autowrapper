#ifndef OCCTLSURFACEEXTRUSIONCREATEINFO_H
#define OCCTLSURFACEEXTRUSIONCREATEINFO_H

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
#include "OcctlVector3.h"

using namespace godot;

class OcctlSurfaceExtrusionCreateInfo : public godot::RefCounted {
    GDCLASS(OcctlSurfaceExtrusionCreateInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t basis;
    Ref<OcctlVector3> direction;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_basis() const;
    void set_basis(int64_t val);
    Ref<OcctlVector3> get_direction() const;
    void set_direction(Ref<OcctlVector3> val);

    occtl_surface_extrusion_create_info_t to_c() const;
    static Ref<OcctlSurfaceExtrusionCreateInfo> from_c(const occtl_surface_extrusion_create_info_t& val);
    void copy_from_c(const occtl_surface_extrusion_create_info_t& val);
};

#endif // OCCTLSURFACEEXTRUSIONCREATEINFO_H
