#ifndef OCCTLTOPODISTANCEPAIR_H
#define OCCTLTOPODISTANCEPAIR_H

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

#include "OcctlPoint3.h"
#include "OcctlNodeId.h"

using namespace godot;

class OcctlTopoDistancePair : public godot::RefCounted {
    GDCLASS(OcctlTopoDistancePair, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    double distance;
    Ref<OcctlPoint3> point_a;
    Ref<OcctlPoint3> point_b;
    int64_t support_a;
    int64_t support_b;
    int inner_solution;
    int solution_count;

    double get_distance() const;
    void set_distance(double val);
    Ref<OcctlPoint3> get_point_a() const;
    void set_point_a(Ref<OcctlPoint3> val);
    Ref<OcctlPoint3> get_point_b() const;
    void set_point_b(Ref<OcctlPoint3> val);
    int64_t get_support_a() const;
    void set_support_a(int64_t val);
    int64_t get_support_b() const;
    void set_support_b(int64_t val);
    int get_inner_solution() const;
    void set_inner_solution(int val);
    int get_solution_count() const;
    void set_solution_count(int val);

    occtl_topo_distance_pair_t to_c() const;
    static Ref<OcctlTopoDistancePair> from_c(const occtl_topo_distance_pair_t& val);
    void copy_from_c(const occtl_topo_distance_pair_t& val);
};

#endif // OCCTLTOPODISTANCEPAIR_H
