#ifndef OCCTLORIENTEDNODE_H
#define OCCTLORIENTEDNODE_H

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
#include "occtl/occtl_topo_relation.h"

#include "OcctlNodeId.h"

using namespace godot;

class OcctlOrientedNode : public godot::RefCounted {
    GDCLASS(OcctlOrientedNode, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int64_t id;
    int orientation;

    int64_t get_id() const;
    void set_id(int64_t val);
    int get_orientation() const;
    void set_orientation(int val);

    occtl_oriented_node_t to_c() const;
    static Ref<OcctlOrientedNode> from_c(const occtl_oriented_node_t& val);
    void copy_from_c(const occtl_oriented_node_t& val);
};

#endif // OCCTLORIENTEDNODE_H
