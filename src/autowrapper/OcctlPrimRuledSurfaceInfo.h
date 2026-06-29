#ifndef OCCTLPRIMRULEDSURFACEINFO_H
#define OCCTLPRIMRULEDSURFACEINFO_H

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
#include "occtl/occtl_prim_feature.h"

#include "OcctlNodeId.h"

using namespace godot;

class OcctlPrimRuledSurfaceInfo : public godot::RefCounted {
    GDCLASS(OcctlPrimRuledSurfaceInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t section_a;
    int64_t section_b;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_section_a() const;
    void set_section_a(int64_t val);
    int64_t get_section_b() const;
    void set_section_b(int64_t val);

    occtl_prim_ruled_surface_info_t to_c() const;
    static Ref<OcctlPrimRuledSurfaceInfo> from_c(const occtl_prim_ruled_surface_info_t& val);
    void copy_from_c(const occtl_prim_ruled_surface_info_t& val);
};

#endif // OCCTLPRIMRULEDSURFACEINFO_H
