#ifndef OCCTLNODEID_H
#define OCCTLNODEID_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/vector3.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/transform3d.hpp>
#include <godot_cpp/variant/aabb.hpp>
#include <godot_cpp/variant/color.hpp>
#include <cstdint>
#include <vector>
#include "occtl/occtl_topo_types.h"


using namespace godot;

class OcctlNodeId : public godot::RefCounted {
    GDCLASS(OcctlNodeId, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int64_t bits;

    int64_t get_bits() const;
    void set_bits(int64_t val);

    occtl_node_id_t to_c() const;
    static Ref<OcctlNodeId> from_c(const occtl_node_id_t& val);
    void copy_from_c(const occtl_node_id_t& val);
};

#endif // OCCTLNODEID_H
