#ifndef OCCTLIOIGES_H
#define OCCTLIOIGES_H

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
#include "occtl/occtl_io_iges.h"

#include "OcctlGraphHandle.h"
#include "OcctlIoIgesReadOptions.h"
#include "OcctlIoIgesWriteOptions.h"
#include "OcctlNodeId.h"

using namespace godot;

class OcctlIoIges : public godot::RefCounted {
    GDCLASS(OcctlIoIges, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    void read_options_init(const Ref<OcctlIoIgesReadOptions>& options); // NOLINT
    void write_options_init(const Ref<OcctlIoIgesWriteOptions>& options); // NOLINT
    Ref<OcctlGraphHandle> read(const String& path, const Ref<OcctlNodeId>& out_root, const Ref<OcctlIoIgesReadOptions>& options); // NOLINT
    int write(const Ref<OcctlGraphHandle>& graph, int64_t root, const String& path, const Ref<OcctlIoIgesWriteOptions>& options); // NOLINT
};

#endif // OCCTLIOIGES_H
