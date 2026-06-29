#ifndef OCCTLMESHTRIANGLECOMPONENTTRIANGLESVIEW_H
#define OCCTLMESHTRIANGLECOMPONENTTRIANGLESVIEW_H

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

#include "OcctlNodeId.h"

using namespace godot;

class OcctlMeshTriangleComponentTrianglesView : public godot::RefCounted {
    GDCLASS(OcctlMeshTriangleComponentTrianglesView, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    PackedInt32Array triangles;
    int triangle_count;
    int component_id;
    int64_t root;

    PackedInt32Array get_triangles() const;
    void set_triangles(PackedInt32Array val);
    int get_triangle_count() const;
    void set_triangle_count(int val);
    int get_component_id() const;
    void set_component_id(int val);
    int64_t get_root() const;
    void set_root(int64_t val);

    occtl_mesh_triangle_component_triangles_view_t to_c() const;
    static Ref<OcctlMeshTriangleComponentTrianglesView> from_c(const occtl_mesh_triangle_component_triangles_view_t& val);
    void copy_from_c(const occtl_mesh_triangle_component_triangles_view_t& val);
};

#endif // OCCTLMESHTRIANGLECOMPONENTTRIANGLESVIEW_H
