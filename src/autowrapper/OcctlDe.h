#ifndef OCCTLDE_H
#define OCCTLDE_H

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
#include "occtl/occtl_de.h"

#include "OcctlByteArray.h"
#include "OcctlDeFormatInfo.h"
#include "OcctlGraphHandle.h"
#include "OcctlNodeId.h"
#include "OcctlSize.h"
#include "OcctlStringArray.h"

using namespace godot;

class OcctlDe : public godot::RefCounted {
    GDCLASS(OcctlDe, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    void format_info_init(const Ref<OcctlDeFormatInfo>& info); // NOLINT
    Ref<OcctlGraphHandle> read(const String& path, const Ref<OcctlNodeId>& out_root); // NOLINT
    Ref<OcctlGraphHandle> read_memory(const String& format_id, const PackedByteArray& data, int size, const Ref<OcctlNodeId>& out_root); // NOLINT
    int write(const Ref<OcctlGraphHandle>& graph, int64_t root, const String& path); // NOLINT
    PackedByteArray write_memory(const Ref<OcctlGraphHandle>& graph, int64_t root, const String& format_id); // NOLINT
    int format_ids(int cap, const Ref<OcctlSize>& out_count); // NOLINT
    int format_count(const Ref<OcctlSize>& out_count); // NOLINT
    int format_info_at(int index, const Ref<OcctlDeFormatInfo>& out_info); // NOLINT
    int format_info_by_id(const String& format_id, const Ref<OcctlDeFormatInfo>& out_info); // NOLINT
    int format_extensions(const String& format_id, int cap, const Ref<OcctlSize>& out_count); // NOLINT
    int format_id_from_path(const String& path); // NOLINT
};

#endif // OCCTLDE_H
