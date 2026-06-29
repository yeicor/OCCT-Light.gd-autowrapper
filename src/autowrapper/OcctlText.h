#ifndef OCCTLTEXT_H
#define OCCTLTEXT_H

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
#include "occtl/occtl_text.h"

#include "OcctlGraphHandle.h"
#include "OcctlNodeId.h"
#include "OcctlTextInfo.h"
#include "OcctlTextLayoutOptions.h"
#include "OcctlTextMetrics.h"

using namespace godot;

class OcctlText : public godot::RefCounted {
    GDCLASS(OcctlText, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    void info_init(const Ref<OcctlTextInfo>& info); // NOLINT
    void layout_options_init(const Ref<OcctlTextLayoutOptions>& options); // NOLINT
    void metrics_init(const Ref<OcctlTextMetrics>& metrics); // NOLINT
    int measure(const Ref<OcctlTextInfo>& info, const Ref<OcctlTextMetrics>& out_metrics); // NOLINT
    int make_faces(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTextInfo>& info, const Ref<OcctlNodeId>& out_compound); // NOLINT
    int make_wires(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTextInfo>& info, const Ref<OcctlNodeId>& out_compound); // NOLINT
};

#endif // OCCTLTEXT_H
