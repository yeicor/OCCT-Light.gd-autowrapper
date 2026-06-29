#ifndef OCCTLBOOL_H
#define OCCTLBOOL_H

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
#include "occtl/occtl_bool.h"

#include "OcctlBoolOptions.h"
#include "OcctlGraphHandle.h"
#include "OcctlNodeId.h"

using namespace godot;

class OcctlBool : public godot::RefCounted {
    GDCLASS(OcctlBool, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    void options_init(const Ref<OcctlBoolOptions>& options); // NOLINT
    int fuse(const Ref<OcctlGraphHandle>& graph, const PackedInt64Array& objects, const PackedInt64Array& tools, const Ref<OcctlBoolOptions>& opts, const Ref<OcctlNodeId>& out_root); // NOLINT
    int cut(const Ref<OcctlGraphHandle>& graph, const PackedInt64Array& objects, const PackedInt64Array& tools, const Ref<OcctlBoolOptions>& opts, const Ref<OcctlNodeId>& out_root); // NOLINT
    int common(const Ref<OcctlGraphHandle>& graph, const PackedInt64Array& objects, const PackedInt64Array& tools, const Ref<OcctlBoolOptions>& opts, const Ref<OcctlNodeId>& out_root); // NOLINT
    int section(const Ref<OcctlGraphHandle>& graph, const PackedInt64Array& objects, const PackedInt64Array& tools, const Ref<OcctlBoolOptions>& opts, const Ref<OcctlNodeId>& out_root); // NOLINT
    int split(const Ref<OcctlGraphHandle>& graph, const PackedInt64Array& objects, const PackedInt64Array& tools, const Ref<OcctlBoolOptions>& opts, const Ref<OcctlNodeId>& out_root); // NOLINT
};

#endif // OCCTLBOOL_H
