#ifndef OCCTLPRIMPOLYLINEINFO_H
#define OCCTLPRIMPOLYLINEINFO_H

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

#include "OcctlPoint3.h"

using namespace godot;

class OcctlPrimPolylineInfo : public godot::RefCounted {
    GDCLASS(OcctlPrimPolylineInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    Array points;
    mutable std::vector<occtl_point3_t> _cache_points;
    int point_count;
    int closed;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    Array get_points() const;
    void set_points(Array val);
    int get_point_count() const;
    void set_point_count(int val);
    int get_closed() const;
    void set_closed(int val);

    occtl_prim_polyline_info_t to_c() const;
    static Ref<OcctlPrimPolylineInfo> from_c(const occtl_prim_polyline_info_t& val);
    void copy_from_c(const occtl_prim_polyline_info_t& val);
};

#endif // OCCTLPRIMPOLYLINEINFO_H
