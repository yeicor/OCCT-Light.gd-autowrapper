#ifndef OCCTLHEAL_H
#define OCCTLHEAL_H

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
#include "occtl/occtl_heal.h"

#include "OcctlGraphHandle.h"
#include "OcctlHealOptions.h"
#include "OcctlHealUnifySameDomainOptions.h"
#include "OcctlNodeId.h"

using namespace godot;

class OcctlHeal : public godot::RefCounted {
    GDCLASS(OcctlHeal, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    void options_init(const Ref<OcctlHealOptions>& options); // NOLINT
    void unify_same_domain_options_init(const Ref<OcctlHealUnifySameDomainOptions>& options); // NOLINT
    int shape(const Ref<OcctlGraphHandle>& graph, int64_t node_id, const Ref<OcctlHealOptions>& options); // NOLINT
    int unify_same_domain(const Ref<OcctlGraphHandle>& graph, int64_t node_id, const Ref<OcctlHealUnifySameDomainOptions>& options, const Ref<OcctlNodeId>& out_root); // NOLINT
};

#endif // OCCTLHEAL_H
