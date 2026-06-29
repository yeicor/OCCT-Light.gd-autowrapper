#ifndef OCCTLPRIMFILLET2DINFO_H
#define OCCTLPRIMFILLET2DINFO_H

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
#include "occtl/occtl_prim_sketch.h"

#include "OcctlNodeId.h"

using namespace godot;

class OcctlPrimFillet2dInfo : public godot::RefCounted {
    GDCLASS(OcctlPrimFillet2dInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t face;
    PackedInt64Array vertices;
    int vertex_count;
    double radius;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_face() const;
    void set_face(int64_t val);
    PackedInt64Array get_vertices() const;
    void set_vertices(PackedInt64Array val);
    int get_vertex_count() const;
    void set_vertex_count(int val);
    double get_radius() const;
    void set_radius(double val);

    occtl_prim_fillet_2d_info_t to_c() const;
    static Ref<OcctlPrimFillet2dInfo> from_c(const occtl_prim_fillet_2d_info_t& val);
    void copy_from_c(const occtl_prim_fillet_2d_info_t& val);
};

#endif // OCCTLPRIMFILLET2DINFO_H
