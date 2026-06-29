#ifndef OCCTLMESHCOMPONENTBOUNDARYPOLYLINE_H
#define OCCTLMESHCOMPONENTBOUNDARYPOLYLINE_H

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

class OcctlMeshComponentBoundaryPolyline : public godot::RefCounted {
    GDCLASS(OcctlMeshComponentBoundaryPolyline, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int first_point;
    int point_count;
    int is_closed;

    int get_first_point() const;
    void set_first_point(int val);
    int get_point_count() const;
    void set_point_count(int val);
    int get_is_closed() const;
    void set_is_closed(int val);

    occtl_mesh_component_boundary_polyline_t to_c() const;
    static Ref<OcctlMeshComponentBoundaryPolyline> from_c(const occtl_mesh_component_boundary_polyline_t& val);
    void copy_from_c(const occtl_mesh_component_boundary_polyline_t& val);
};

#endif // OCCTLMESHCOMPONENTBOUNDARYPOLYLINE_H
