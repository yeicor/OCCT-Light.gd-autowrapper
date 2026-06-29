#ifndef OCCTLVECTOR3_H
#define OCCTLVECTOR3_H

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

class OcctlVector3 : public godot::RefCounted {
    GDCLASS(OcctlVector3, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    double x;
    double y;
    double z;

    double get_x() const;
    void set_x(double val);
    double get_y() const;
    void set_y(double val);
    double get_z() const;
    void set_z(double val);

    occtl_vector3_t to_c() const;
    static Ref<OcctlVector3> from_c(const occtl_vector3_t& val);
    void copy_from_c(const occtl_vector3_t& val);

    static Ref<OcctlVector3> from_vector3(Vector3 v); // NOLINT
};

#endif // OCCTLVECTOR3_H
