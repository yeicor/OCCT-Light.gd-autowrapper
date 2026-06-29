#ifndef OCCTLAXIS2PLACEMENT_H
#define OCCTLAXIS2PLACEMENT_H

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

#include "OcctlPoint3.h"
#include "OcctlDirection3.h"

using namespace godot;

class OcctlAxis2Placement : public godot::RefCounted {
    GDCLASS(OcctlAxis2Placement, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    Ref<OcctlPoint3> location;
    Ref<OcctlDirection3> x_dir;
    Ref<OcctlDirection3> x_dir_ref;

    Ref<OcctlPoint3> get_location() const;
    void set_location(Ref<OcctlPoint3> val);
    Ref<OcctlDirection3> get_x_dir() const;
    void set_x_dir(Ref<OcctlDirection3> val);
    Ref<OcctlDirection3> get_x_dir_ref() const;
    void set_x_dir_ref(Ref<OcctlDirection3> val);

    occtl_axis2_placement_t to_c() const;
    static Ref<OcctlAxis2Placement> from_c(const occtl_axis2_placement_t& val);
    void copy_from_c(const occtl_axis2_placement_t& val);

    static Ref<OcctlAxis2Placement> from_components(Vector3 point, Vector3 z_dir, Vector3 x_dir); // NOLINT
};

#endif // OCCTLAXIS2PLACEMENT_H
