#ifndef OCCTLSURFACEGORDONCREATEINFO_H
#define OCCTLSURFACEGORDONCREATEINFO_H

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

class OcctlSurfaceGordonCreateInfo : public godot::RefCounted {
    GDCLASS(OcctlSurfaceGordonCreateInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    PackedInt64Array profiles;
    int profile_count;
    PackedInt64Array guides;
    int guide_count;
    double tolerance;
    int parallel;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    PackedInt64Array get_profiles() const;
    void set_profiles(PackedInt64Array val);
    int get_profile_count() const;
    void set_profile_count(int val);
    PackedInt64Array get_guides() const;
    void set_guides(PackedInt64Array val);
    int get_guide_count() const;
    void set_guide_count(int val);
    double get_tolerance() const;
    void set_tolerance(double val);
    int get_parallel() const;
    void set_parallel(int val);

    occtl_surface_gordon_create_info_t to_c() const;
    static Ref<OcctlSurfaceGordonCreateInfo> from_c(const occtl_surface_gordon_create_info_t& val);
    void copy_from_c(const occtl_surface_gordon_create_info_t& val);
};

#endif // OCCTLSURFACEGORDONCREATEINFO_H
