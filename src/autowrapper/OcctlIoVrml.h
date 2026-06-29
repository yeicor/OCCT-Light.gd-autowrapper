#ifndef OCCTLIOVRML_H
#define OCCTLIOVRML_H

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
#include "occtl/occtl_io_vrml.h"

#include "OcctlByteArray.h"
#include "OcctlGraphHandle.h"
#include "OcctlIoVrmlReadOptions.h"
#include "OcctlIoVrmlWriteOptions.h"
#include "OcctlNodeId.h"
#include "OcctlSize.h"

using namespace godot;

class OcctlIoVrml : public godot::RefCounted {
    GDCLASS(OcctlIoVrml, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    void read_options_init(const Ref<OcctlIoVrmlReadOptions>& options); // NOLINT
    void write_options_init(const Ref<OcctlIoVrmlWriteOptions>& options); // NOLINT
    Ref<OcctlGraphHandle> read(const String& path, const Ref<OcctlNodeId>& out_root, const Ref<OcctlIoVrmlReadOptions>& options); // NOLINT
    int write(const Ref<OcctlGraphHandle>& graph, int64_t root, const String& path, const Ref<OcctlIoVrmlWriteOptions>& options); // NOLINT
    Ref<OcctlGraphHandle> read_memory(const PackedByteArray& data, int size, const Ref<OcctlNodeId>& out_root, const Ref<OcctlIoVrmlReadOptions>& options); // NOLINT
    PackedByteArray write_memory(const Ref<OcctlGraphHandle>& graph, int64_t root, const Ref<OcctlIoVrmlWriteOptions>& options); // NOLINT
};

#endif // OCCTLIOVRML_H
