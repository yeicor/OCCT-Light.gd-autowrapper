#ifndef OCCTLPRIM_H
#define OCCTLPRIM_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/packed_byte_array.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/vector3.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/transform3d.hpp>
#include <godot_cpp/variant/aabb.hpp>
#include <godot_cpp/variant/color.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <cstdint>
#include "occtl/occtl_prim.h"


using namespace godot;

class OcctlPrim : public godot::RefCounted {
    GDCLASS(OcctlPrim, godot::RefCounted)
protected:
    static void _bind_methods();
public:
};

#endif // OCCTLPRIM_H
