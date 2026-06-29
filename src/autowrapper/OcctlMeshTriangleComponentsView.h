#ifndef OCCTLMESHTRIANGLECOMPONENTSVIEW_H
#define OCCTLMESHTRIANGLECOMPONENTSVIEW_H

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

class OcctlMeshTriangleComponentsView : public godot::RefCounted {
    GDCLASS(OcctlMeshTriangleComponentsView, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    PackedInt32Array triangle_component_ids;
    int triangle_count;
    PackedInt32Array component_sizes;
    int component_count;
    int64_t root;

    PackedInt32Array get_triangle_component_ids() const;
    void set_triangle_component_ids(PackedInt32Array val);
    int get_triangle_count() const;
    void set_triangle_count(int val);
    PackedInt32Array get_component_sizes() const;
    void set_component_sizes(PackedInt32Array val);
    int get_component_count() const;
    void set_component_count(int val);
    int64_t get_root() const;
    void set_root(int64_t val);

    occtl_mesh_triangle_components_view_t to_c() const;
    static Ref<OcctlMeshTriangleComponentsView> from_c(const occtl_mesh_triangle_components_view_t& val);
    void copy_from_c(const occtl_mesh_triangle_components_view_t& val);
};

#endif // OCCTLMESHTRIANGLECOMPONENTSVIEW_H
