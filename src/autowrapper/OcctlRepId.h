#ifndef OCCTLREPID_H
#define OCCTLREPID_H

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
#include "occtl/occtl_core.h"


using namespace godot;

class OcctlRepId : public godot::RefCounted {
    GDCLASS(OcctlRepId, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int64_t bits;

    int64_t get_bits() const;
    void set_bits(int64_t val);

    occtl_rep_id_t to_c() const;
    static Ref<OcctlRepId> from_c(const occtl_rep_id_t& val);
    void copy_from_c(const occtl_rep_id_t& val);
};

#endif // OCCTLREPID_H
