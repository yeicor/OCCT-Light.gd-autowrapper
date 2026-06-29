#ifndef OCCTLTOPOTOUCHHIT_H
#define OCCTLTOPOTOUCHHIT_H

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
#include "OcctlPoint3.h"

using namespace godot;

class OcctlTopoTouchHit : public godot::RefCounted {
    GDCLASS(OcctlTopoTouchHit, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int64_t node_a;
    int64_t node_b;
    int64_t support_a;
    int64_t support_b;
    Ref<OcctlPoint3> point_a;
    Ref<OcctlPoint3> point_b;
    double distance;
    int inner_solution;

    int64_t get_node_a() const;
    void set_node_a(int64_t val);
    int64_t get_node_b() const;
    void set_node_b(int64_t val);
    int64_t get_support_a() const;
    void set_support_a(int64_t val);
    int64_t get_support_b() const;
    void set_support_b(int64_t val);
    Ref<OcctlPoint3> get_point_a() const;
    void set_point_a(Ref<OcctlPoint3> val);
    Ref<OcctlPoint3> get_point_b() const;
    void set_point_b(Ref<OcctlPoint3> val);
    double get_distance() const;
    void set_distance(double val);
    int get_inner_solution() const;
    void set_inner_solution(int val);

    occtl_topo_touch_hit_t to_c() const;
    static Ref<OcctlTopoTouchHit> from_c(const occtl_topo_touch_hit_t& val);
    void copy_from_c(const occtl_topo_touch_hit_t& val);
};

#endif // OCCTLTOPOTOUCHHIT_H
