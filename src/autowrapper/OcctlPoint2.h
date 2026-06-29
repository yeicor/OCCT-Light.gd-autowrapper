#ifndef OCCTLPOINT2_H
#define OCCTLPOINT2_H

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
#include "occtl/occtl_geom.h"


using namespace godot;

class OcctlPoint2 : public godot::RefCounted {
    GDCLASS(OcctlPoint2, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    double x;
    double y;

    double get_x() const;
    void set_x(double val);
    double get_y() const;
    void set_y(double val);

    occtl_point2_t to_c() const;
    static Ref<OcctlPoint2> from_c(const occtl_point2_t& val);
    void copy_from_c(const occtl_point2_t& val);

    static Ref<OcctlPoint2> from_vector2(Vector2 v); // NOLINT
};

#endif // OCCTLPOINT2_H
