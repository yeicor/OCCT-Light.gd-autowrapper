#ifndef OCCTLGRAPHUVBOUNDS_H
#define OCCTLGRAPHUVBOUNDS_H

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
#include "occtl/occtl_topo_build.h"


using namespace godot;

class OcctlGraphUvBounds : public godot::RefCounted {
    GDCLASS(OcctlGraphUvBounds, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    double u_min;
    double u_max;
    double v_min;
    double v_max;
    int is_natural_restriction;

    double get_u_min() const;
    void set_u_min(double val);
    double get_u_max() const;
    void set_u_max(double val);
    double get_v_min() const;
    void set_v_min(double val);
    double get_v_max() const;
    void set_v_max(double val);
    int get_is_natural_restriction() const;
    void set_is_natural_restriction(int val);

    occtl_graph_uv_bounds_t to_c() const;
    static Ref<OcctlGraphUvBounds> from_c(const occtl_graph_uv_bounds_t& val);
    void copy_from_c(const occtl_graph_uv_bounds_t& val);
};

#endif // OCCTLGRAPHUVBOUNDS_H
