#ifndef OCCTLPOLYGONONTRIVIEW_H
#define OCCTLPOLYGONONTRIVIEW_H

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

class OcctlPolygonOnTriView : public godot::RefCounted {
    GDCLASS(OcctlPolygonOnTriView, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    PackedInt32Array node_indices;
    int node_count;
    PackedFloat64Array parameters;
    double deflection;
    int64_t source_uid;

    PackedInt32Array get_node_indices() const;
    void set_node_indices(PackedInt32Array val);
    int get_node_count() const;
    void set_node_count(int val);
    PackedFloat64Array get_parameters() const;
    void set_parameters(PackedFloat64Array val);
    double get_deflection() const;
    void set_deflection(double val);
    int64_t get_source_uid() const;
    void set_source_uid(int64_t val);

    occtl_polygon_on_tri_view_t to_c() const;
    static Ref<OcctlPolygonOnTriView> from_c(const occtl_polygon_on_tri_view_t& val);
    void copy_from_c(const occtl_polygon_on_tri_view_t& val);
};

#endif // OCCTLPOLYGONONTRIVIEW_H
