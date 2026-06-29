#ifndef OCCTLMESHFROMBUFFERSOPTIONS_H
#define OCCTLMESHFROMBUFFERSOPTIONS_H

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


using namespace godot;

class OcctlMeshFromBuffersOptions : public godot::RefCounted {
    GDCLASS(OcctlMeshFromBuffersOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    PackedFloat64Array nodes;
    int node_count;
    PackedInt32Array triangles;
    int triangle_count;
    double deflection;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    PackedFloat64Array get_nodes() const;
    void set_nodes(PackedFloat64Array val);
    int get_node_count() const;
    void set_node_count(int val);
    PackedInt32Array get_triangles() const;
    void set_triangles(PackedInt32Array val);
    int get_triangle_count() const;
    void set_triangle_count(int val);
    double get_deflection() const;
    void set_deflection(double val);

    occtl_mesh_from_buffers_options_t to_c() const;
    static Ref<OcctlMeshFromBuffersOptions> from_c(const occtl_mesh_from_buffers_options_t& val);
    void copy_from_c(const occtl_mesh_from_buffers_options_t& val);
};

#endif // OCCTLMESHFROMBUFFERSOPTIONS_H
