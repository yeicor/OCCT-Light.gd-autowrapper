#ifndef OCCTLTRIANGULATIONVIEW_H
#define OCCTLTRIANGULATIONVIEW_H

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
#include "occtl/occtl_mesh.h"

#include "OcctlUid.h"

using namespace godot;

class OcctlTriangulationView : public godot::RefCounted {
    GDCLASS(OcctlTriangulationView, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    PackedFloat64Array nodes;
    int node_count;
    PackedFloat64Array normals;
    PackedFloat64Array uvs;
    PackedInt32Array triangles;
    int triangle_count;
    double deflection;
    int64_t source_uid;

    PackedFloat64Array get_nodes() const;
    void set_nodes(PackedFloat64Array val);
    int get_node_count() const;
    void set_node_count(int val);
    PackedFloat64Array get_normals() const;
    void set_normals(PackedFloat64Array val);
    PackedFloat64Array get_uvs() const;
    void set_uvs(PackedFloat64Array val);
    PackedInt32Array get_triangles() const;
    void set_triangles(PackedInt32Array val);
    int get_triangle_count() const;
    void set_triangle_count(int val);
    double get_deflection() const;
    void set_deflection(double val);
    int64_t get_source_uid() const;
    void set_source_uid(int64_t val);

    occtl_triangulation_view_t to_c() const;
    static Ref<OcctlTriangulationView> from_c(const occtl_triangulation_view_t& val);
    void copy_from_c(const occtl_triangulation_view_t& val);
};

#endif // OCCTLTRIANGULATIONVIEW_H
