#ifndef OCCTLVERTEXVIEW_H
#define OCCTLVERTEXVIEW_H

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
#include "occtl/occtl_topo.h"

#include "OcctlPoint3.h"

using namespace godot;

class OcctlVertexView : public godot::RefCounted {
    GDCLASS(OcctlVertexView, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    Ref<OcctlPoint3> point;
    double tolerance;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    Ref<OcctlPoint3> get_point() const;
    void set_point(Ref<OcctlPoint3> val);
    double get_tolerance() const;
    void set_tolerance(double val);

    occtl_vertex_view_t to_c() const;
    static Ref<OcctlVertexView> from_c(const occtl_vertex_view_t& val);
    void copy_from_c(const occtl_vertex_view_t& val);
};

#endif // OCCTLVERTEXVIEW_H
