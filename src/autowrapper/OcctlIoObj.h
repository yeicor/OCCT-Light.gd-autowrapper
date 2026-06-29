#ifndef OCCTLIOOBJ_H
#define OCCTLIOOBJ_H

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
#include "occtl/occtl_io_obj.h"

#include "OcctlGraphHandle.h"
#include "OcctlIoObjReadOptions.h"
#include "OcctlIoObjWriteOptions.h"
#include "OcctlNodeId.h"

using namespace godot;

class OcctlIoObj : public godot::RefCounted {
    GDCLASS(OcctlIoObj, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    void read_options_init(const Ref<OcctlIoObjReadOptions>& options); // NOLINT
    void write_options_init(const Ref<OcctlIoObjWriteOptions>& options); // NOLINT
    Ref<OcctlGraphHandle> read(const String& path, const Ref<OcctlNodeId>& out_root, const Ref<OcctlIoObjReadOptions>& options); // NOLINT
    int write(const Ref<OcctlGraphHandle>& graph, int64_t root, const String& path, const Ref<OcctlIoObjWriteOptions>& options); // NOLINT
};

#endif // OCCTLIOOBJ_H
