#ifndef OCCTLSURFACEREVOLUTIONCREATEINFO_H
#define OCCTLSURFACEREVOLUTIONCREATEINFO_H

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
#include "OcctlAxis1Placement.h"

using namespace godot;

class OcctlSurfaceRevolutionCreateInfo : public godot::RefCounted {
    GDCLASS(OcctlSurfaceRevolutionCreateInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t basis;
    Ref<OcctlAxis1Placement> axis;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_basis() const;
    void set_basis(int64_t val);
    Ref<OcctlAxis1Placement> get_axis() const;
    void set_axis(Ref<OcctlAxis1Placement> val);

    occtl_surface_revolution_create_info_t to_c() const;
    static Ref<OcctlSurfaceRevolutionCreateInfo> from_c(const occtl_surface_revolution_create_info_t& val);
    void copy_from_c(const occtl_surface_revolution_create_info_t& val);
};

#endif // OCCTLSURFACEREVOLUTIONCREATEINFO_H
