#ifndef OCCTLGRAPHOBB_H
#define OCCTLGRAPHOBB_H

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

#include "OcctlPoint3.h"
#include "OcctlDirection3.h"

using namespace godot;

class OcctlGraphObb : public godot::RefCounted {
    GDCLASS(OcctlGraphObb, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    Ref<OcctlPoint3> center;
    Ref<OcctlDirection3> x_direction;
    Ref<OcctlDirection3> y_direction;
    Ref<OcctlDirection3> z_direction;
    double x_half_size;
    double y_half_size;
    double z_half_size;

    Ref<OcctlPoint3> get_center() const;
    void set_center(Ref<OcctlPoint3> val);
    Ref<OcctlDirection3> get_x_direction() const;
    void set_x_direction(Ref<OcctlDirection3> val);
    Ref<OcctlDirection3> get_y_direction() const;
    void set_y_direction(Ref<OcctlDirection3> val);
    Ref<OcctlDirection3> get_z_direction() const;
    void set_z_direction(Ref<OcctlDirection3> val);
    double get_x_half_size() const;
    void set_x_half_size(double val);
    double get_y_half_size() const;
    void set_y_half_size(double val);
    double get_z_half_size() const;
    void set_z_half_size(double val);

    occtl_graph_obb_t to_c() const;
    static Ref<OcctlGraphObb> from_c(const occtl_graph_obb_t& val);
    void copy_from_c(const occtl_graph_obb_t& val);
};

#endif // OCCTLGRAPHOBB_H
