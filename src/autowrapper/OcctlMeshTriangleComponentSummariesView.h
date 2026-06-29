#ifndef OCCTLMESHTRIANGLECOMPONENTSUMMARIESVIEW_H
#define OCCTLMESHTRIANGLECOMPONENTSUMMARIESVIEW_H

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

#include "OcctlMeshTriangleComponentSummary.h"
#include "OcctlNodeId.h"

using namespace godot;

class OcctlMeshTriangleComponentSummariesView : public godot::RefCounted {
    GDCLASS(OcctlMeshTriangleComponentSummariesView, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    Array summaries;
    mutable std::vector<occtl_mesh_triangle_component_summary_t> _cache_summaries;
    int component_count;
    int triangle_count;
    int64_t root;

    Array get_summaries() const;
    void set_summaries(Array val);
    int get_component_count() const;
    void set_component_count(int val);
    int get_triangle_count() const;
    void set_triangle_count(int val);
    int64_t get_root() const;
    void set_root(int64_t val);

    occtl_mesh_triangle_component_summaries_view_t to_c() const;
    static Ref<OcctlMeshTriangleComponentSummariesView> from_c(const occtl_mesh_triangle_component_summaries_view_t& val);
    void copy_from_c(const occtl_mesh_triangle_component_summaries_view_t& val);
};

#endif // OCCTLMESHTRIANGLECOMPONENTSUMMARIESVIEW_H
