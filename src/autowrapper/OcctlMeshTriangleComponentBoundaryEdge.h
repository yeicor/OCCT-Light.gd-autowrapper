#ifndef OCCTLMESHTRIANGLECOMPONENTBOUNDARYEDGE_H
#define OCCTLMESHTRIANGLECOMPONENTBOUNDARYEDGE_H

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

class OcctlMeshTriangleComponentBoundaryEdge : public godot::RefCounted {
    GDCLASS(OcctlMeshTriangleComponentBoundaryEdge, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int triangle;
    int local_edge;
    int node0;
    int node1;
    int adjacent_triangle;

    int get_triangle() const;
    void set_triangle(int val);
    int get_local_edge() const;
    void set_local_edge(int val);
    int get_node0() const;
    void set_node0(int val);
    int get_node1() const;
    void set_node1(int val);
    int get_adjacent_triangle() const;
    void set_adjacent_triangle(int val);

    occtl_mesh_triangle_component_boundary_edge_t to_c() const;
    static Ref<OcctlMeshTriangleComponentBoundaryEdge> from_c(const occtl_mesh_triangle_component_boundary_edge_t& val);
    void copy_from_c(const occtl_mesh_triangle_component_boundary_edge_t& val);
};

#endif // OCCTLMESHTRIANGLECOMPONENTBOUNDARYEDGE_H
