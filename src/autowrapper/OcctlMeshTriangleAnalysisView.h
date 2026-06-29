#ifndef OCCTLMESHTRIANGLEANALYSISVIEW_H
#define OCCTLMESHTRIANGLEANALYSISVIEW_H

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

class OcctlMeshTriangleAnalysisView : public godot::RefCounted {
    GDCLASS(OcctlMeshTriangleAnalysisView, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    PackedFloat64Array triangle_normals;
    PackedInt32Array triangle_adjacency;
    int triangle_count;
    int face_count;
    int64_t root;

    PackedFloat64Array get_triangle_normals() const;
    void set_triangle_normals(PackedFloat64Array val);
    PackedInt32Array get_triangle_adjacency() const;
    void set_triangle_adjacency(PackedInt32Array val);
    int get_triangle_count() const;
    void set_triangle_count(int val);
    int get_face_count() const;
    void set_face_count(int val);
    int64_t get_root() const;
    void set_root(int64_t val);

    occtl_mesh_triangle_analysis_view_t to_c() const;
    static Ref<OcctlMeshTriangleAnalysisView> from_c(const occtl_mesh_triangle_analysis_view_t& val);
    void copy_from_c(const occtl_mesh_triangle_analysis_view_t& val);
};

#endif // OCCTLMESHTRIANGLEANALYSISVIEW_H
