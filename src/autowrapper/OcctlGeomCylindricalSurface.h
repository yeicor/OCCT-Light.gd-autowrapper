#ifndef OCCTLGEOMCYLINDRICALSURFACE_H
#define OCCTLGEOMCYLINDRICALSURFACE_H

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

#include "OcctlAxis3Placement.h"

using namespace godot;

class OcctlGeomCylindricalSurface : public godot::RefCounted {
    GDCLASS(OcctlGeomCylindricalSurface, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    Ref<OcctlAxis3Placement> position;
    double radius;

    Ref<OcctlAxis3Placement> get_position() const;
    void set_position(Ref<OcctlAxis3Placement> val);
    double get_radius() const;
    void set_radius(double val);

    occtl_geom_cylindrical_surface_t to_c() const;
    static Ref<OcctlGeomCylindricalSurface> from_c(const occtl_geom_cylindrical_surface_t& val);
    void copy_from_c(const occtl_geom_cylindrical_surface_t& val);
};

#endif // OCCTLGEOMCYLINDRICALSURFACE_H
