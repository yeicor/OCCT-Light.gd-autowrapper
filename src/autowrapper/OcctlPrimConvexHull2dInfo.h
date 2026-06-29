#ifndef OCCTLPRIMCONVEXHULL2DINFO_H
#define OCCTLPRIMCONVEXHULL2DINFO_H

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

#include "OcctlAxis2Placement.h"
#include "OcctlPoint3.h"
#include "OcctlNodeId.h"

using namespace godot;

class OcctlPrimConvexHull2dInfo : public godot::RefCounted {
    GDCLASS(OcctlPrimConvexHull2dInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    Ref<OcctlAxis2Placement> placement;
    Array points;
    mutable std::vector<occtl_point3_t> _cache_points;
    int point_count;
    PackedInt64Array vertices;
    int vertex_count;
    double tolerance;
    int make_face;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    Ref<OcctlAxis2Placement> get_placement() const;
    void set_placement(Ref<OcctlAxis2Placement> val);
    Array get_points() const;
    void set_points(Array val);
    int get_point_count() const;
    void set_point_count(int val);
    PackedInt64Array get_vertices() const;
    void set_vertices(PackedInt64Array val);
    int get_vertex_count() const;
    void set_vertex_count(int val);
    double get_tolerance() const;
    void set_tolerance(double val);
    int get_make_face() const;
    void set_make_face(int val);

    occtl_prim_convex_hull_2d_info_t to_c() const;
    static Ref<OcctlPrimConvexHull2dInfo> from_c(const occtl_prim_convex_hull_2d_info_t& val);
    void copy_from_c(const occtl_prim_convex_hull_2d_info_t& val);
};

#endif // OCCTLPRIMCONVEXHULL2DINFO_H
