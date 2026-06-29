#ifndef OCCTLAABB3_H
#define OCCTLAABB3_H

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
#include "occtl/occtl_mesh.h"

#include "OcctlPoint3.h"

using namespace godot;

class OcctlAabb3 : public godot::RefCounted {
    GDCLASS(OcctlAabb3, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    Ref<OcctlPoint3> min;
    Ref<OcctlPoint3> max;

    Ref<OcctlPoint3> get_min() const;
    void set_min(Ref<OcctlPoint3> val);
    Ref<OcctlPoint3> get_max() const;
    void set_max(Ref<OcctlPoint3> val);

    occtl_aabb3_t to_c() const;
    static Ref<OcctlAabb3> from_c(const occtl_aabb3_t& val);
    void copy_from_c(const occtl_aabb3_t& val);

    static Ref<OcctlAabb3> from_aabb(AABB a); // NOLINT
};

#endif // OCCTLAABB3_H
