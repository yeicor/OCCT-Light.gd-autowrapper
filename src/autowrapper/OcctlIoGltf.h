#ifndef OCCTLIOGLTF_H
#define OCCTLIOGLTF_H

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
#include "occtl/occtl_io_gltf.h"

#include "OcctlGraphHandle.h"
#include "OcctlIoGltfReadOptions.h"
#include "OcctlIoGltfWriteOptions.h"
#include "OcctlNodeId.h"

using namespace godot;

class OcctlIoGltf : public godot::RefCounted {
    GDCLASS(OcctlIoGltf, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    void read_options_init(const Ref<OcctlIoGltfReadOptions>& options); // NOLINT
    void write_options_init(const Ref<OcctlIoGltfWriteOptions>& options); // NOLINT
    Ref<OcctlGraphHandle> read(const String& path, const Ref<OcctlNodeId>& out_root, const Ref<OcctlIoGltfReadOptions>& options); // NOLINT
    int write(const Ref<OcctlGraphHandle>& graph, int64_t root, const String& path, const Ref<OcctlIoGltfWriteOptions>& options); // NOLINT
};

#endif // OCCTLIOGLTF_H
