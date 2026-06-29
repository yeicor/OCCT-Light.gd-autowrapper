#ifndef OCCTLIOBREP_H
#define OCCTLIOBREP_H

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
#include "occtl/occtl_io_brep.h"

#include "OcctlGraphHandle.h"
#include "OcctlIoBrepWriteOptions.h"
#include "OcctlNodeId.h"

using namespace godot;

class OcctlIoBrep : public godot::RefCounted {
    GDCLASS(OcctlIoBrep, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    void write_options_init(const Ref<OcctlIoBrepWriteOptions>& options); // NOLINT
    Ref<OcctlGraphHandle> read(const String& path, const Ref<OcctlNodeId>& out_root); // NOLINT
    int write(const Ref<OcctlGraphHandle>& graph, int64_t root, const String& path, const Ref<OcctlIoBrepWriteOptions>& options); // NOLINT
};

#endif // OCCTLIOBREP_H
