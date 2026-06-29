#ifndef OCCTLFACEVIEW_H
#define OCCTLFACEVIEW_H

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

#include "OcctlNodeId.h"

using namespace godot;

class OcctlFaceView : public godot::RefCounted {
    GDCLASS(OcctlFaceView, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    double u_min;
    double u_max;
    double v_min;
    double v_max;
    double tolerance;
    int64_t outer_wire;
    int wire_count;
    int has_surface;
    int has_triangulation;
    int natural_restriction;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    double get_u_min() const;
    void set_u_min(double val);
    double get_u_max() const;
    void set_u_max(double val);
    double get_v_min() const;
    void set_v_min(double val);
    double get_v_max() const;
    void set_v_max(double val);
    double get_tolerance() const;
    void set_tolerance(double val);
    int64_t get_outer_wire() const;
    void set_outer_wire(int64_t val);
    int get_wire_count() const;
    void set_wire_count(int val);
    int get_has_surface() const;
    void set_has_surface(int val);
    int get_has_triangulation() const;
    void set_has_triangulation(int val);
    int get_natural_restriction() const;
    void set_natural_restriction(int val);

    occtl_face_view_t to_c() const;
    static Ref<OcctlFaceView> from_c(const occtl_face_view_t& val);
    void copy_from_c(const occtl_face_view_t& val);
};

#endif // OCCTLFACEVIEW_H
