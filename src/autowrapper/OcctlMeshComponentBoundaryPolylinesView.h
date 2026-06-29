#ifndef OCCTLMESHCOMPONENTBOUNDARYPOLYLINESVIEW_H
#define OCCTLMESHCOMPONENTBOUNDARYPOLYLINESVIEW_H

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
#include "OcctlMeshComponentBoundaryPolyline.h"
#include "OcctlNodeId.h"

using namespace godot;

class OcctlMeshComponentBoundaryPolylinesView : public godot::RefCounted {
    GDCLASS(OcctlMeshComponentBoundaryPolylinesView, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    Array points;
    mutable std::vector<occtl_point3_t> _cache_points;
    int point_count;
    Array polylines;
    mutable std::vector<occtl_mesh_component_boundary_polyline_t> _cache_polylines;
    int polyline_count;
    int component_id;
    int64_t root;

    Array get_points() const;
    void set_points(Array val);
    int get_point_count() const;
    void set_point_count(int val);
    Array get_polylines() const;
    void set_polylines(Array val);
    int get_polyline_count() const;
    void set_polyline_count(int val);
    int get_component_id() const;
    void set_component_id(int val);
    int64_t get_root() const;
    void set_root(int64_t val);

    occtl_mesh_component_boundary_polylines_view_t to_c() const;
    static Ref<OcctlMeshComponentBoundaryPolylinesView> from_c(const occtl_mesh_component_boundary_polylines_view_t& val);
    void copy_from_c(const occtl_mesh_component_boundary_polylines_view_t& val);
};

#endif // OCCTLMESHCOMPONENTBOUNDARYPOLYLINESVIEW_H
