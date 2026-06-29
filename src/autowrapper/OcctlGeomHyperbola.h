#ifndef OCCTLGEOMHYPERBOLA_H
#define OCCTLGEOMHYPERBOLA_H

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

#include "OcctlAxis2Placement.h"

using namespace godot;

class OcctlGeomHyperbola : public godot::RefCounted {
    GDCLASS(OcctlGeomHyperbola, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    Ref<OcctlAxis2Placement> position;
    double major_radius;
    double minor_radius;

    Ref<OcctlAxis2Placement> get_position() const;
    void set_position(Ref<OcctlAxis2Placement> val);
    double get_major_radius() const;
    void set_major_radius(double val);
    double get_minor_radius() const;
    void set_minor_radius(double val);

    occtl_geom_hyperbola_t to_c() const;
    static Ref<OcctlGeomHyperbola> from_c(const occtl_geom_hyperbola_t& val);
    void copy_from_c(const occtl_geom_hyperbola_t& val);
};

#endif // OCCTLGEOMHYPERBOLA_H
