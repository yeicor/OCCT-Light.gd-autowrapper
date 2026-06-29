#ifndef OCCTLTRANSFORM_H
#define OCCTLTRANSFORM_H

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

class OcctlTransform : public godot::RefCounted {
    GDCLASS(OcctlTransform, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    PackedFloat64Array m;

    PackedFloat64Array get_m() const;
    void set_m(PackedFloat64Array val);

    occtl_transform_t to_c() const;
    static Ref<OcctlTransform> from_c(const occtl_transform_t& val);
    void copy_from_c(const occtl_transform_t& val);

    static Ref<OcctlTransform> from_transform3d(Transform3D t); // NOLINT
};

#endif // OCCTLTRANSFORM_H
