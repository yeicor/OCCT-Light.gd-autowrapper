#ifndef OCCTLIOPLY_H
#define OCCTLIOPLY_H

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
#include "occtl/occtl_io_ply.h"

#include "OcctlGraphHandle.h"
#include "OcctlIoPlyWriteOptions.h"

using namespace godot;

class OcctlIoPly : public godot::RefCounted {
    GDCLASS(OcctlIoPly, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    void write_options_init(const Ref<OcctlIoPlyWriteOptions>& options); // NOLINT
    int write(const Ref<OcctlGraphHandle>& graph, int64_t root, const String& path, const Ref<OcctlIoPlyWriteOptions>& options); // NOLINT
};

#endif // OCCTLIOPLY_H
