#ifndef OCCTLMESHTRIANGLESPHERECOMPONENT_H
#define OCCTLMESHTRIANGLESPHERECOMPONENT_H

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

#include "OcctlPoint3.h"
#include "OcctlAabb3.h"

using namespace godot;

class OcctlMeshTriangleSphereComponent : public godot::RefCounted {
    GDCLASS(OcctlMeshTriangleSphereComponent, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int component_id;
    int triangle_count;
    double area;
    Ref<OcctlPoint3> center;
    double radius;
    Ref<OcctlAabb3> bounds;
    double max_distance;

    int get_component_id() const;
    void set_component_id(int val);
    int get_triangle_count() const;
    void set_triangle_count(int val);
    double get_area() const;
    void set_area(double val);
    Ref<OcctlPoint3> get_center() const;
    void set_center(Ref<OcctlPoint3> val);
    double get_radius() const;
    void set_radius(double val);
    Ref<OcctlAabb3> get_bounds() const;
    void set_bounds(Ref<OcctlAabb3> val);
    double get_max_distance() const;
    void set_max_distance(double val);

    occtl_mesh_triangle_sphere_component_t to_c() const;
    static Ref<OcctlMeshTriangleSphereComponent> from_c(const occtl_mesh_triangle_sphere_component_t& val);
    void copy_from_c(const occtl_mesh_triangle_sphere_component_t& val);
};

#endif // OCCTLMESHTRIANGLESPHERECOMPONENT_H
