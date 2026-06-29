#ifndef OCCTLAXIS2PLACEMENT2D_H
#define OCCTLAXIS2PLACEMENT2D_H

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

#include "OcctlPoint2.h"
#include "OcctlDirection2.h"

using namespace godot;

class OcctlAxis2Placement2d : public godot::RefCounted {
    GDCLASS(OcctlAxis2Placement2d, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    Ref<OcctlPoint2> location;
    Ref<OcctlDirection2> x_dir;

    Ref<OcctlPoint2> get_location() const;
    void set_location(Ref<OcctlPoint2> val);
    Ref<OcctlDirection2> get_x_dir() const;
    void set_x_dir(Ref<OcctlDirection2> val);

    occtl_axis2_placement2d_t to_c() const;
    static Ref<OcctlAxis2Placement2d> from_c(const occtl_axis2_placement2d_t& val);
    void copy_from_c(const occtl_axis2_placement2d_t& val);

    static Ref<OcctlAxis2Placement2d> from_components(Vector2 point, Vector2 z_dir, Vector2 x_dir); // NOLINT
};

#endif // OCCTLAXIS2PLACEMENT2D_H
