#include "OcctlTopoDistancePair.h"

#include "OcctlPoint3.h"
#include "OcctlNodeId.h"

double OcctlTopoDistancePair::get_distance() const { return distance; }
void OcctlTopoDistancePair::set_distance(double val) { distance = val; }

Ref<OcctlPoint3> OcctlTopoDistancePair::get_point_a() const { return point_a; }
void OcctlTopoDistancePair::set_point_a(Ref<OcctlPoint3> val) { point_a = val; }

Ref<OcctlPoint3> OcctlTopoDistancePair::get_point_b() const { return point_b; }
void OcctlTopoDistancePair::set_point_b(Ref<OcctlPoint3> val) { point_b = val; }

int64_t OcctlTopoDistancePair::get_support_a() const { return support_a; }
void OcctlTopoDistancePair::set_support_a(int64_t val) { support_a = val; }

int64_t OcctlTopoDistancePair::get_support_b() const { return support_b; }
void OcctlTopoDistancePair::set_support_b(int64_t val) { support_b = val; }

int OcctlTopoDistancePair::get_inner_solution() const { return inner_solution; }
void OcctlTopoDistancePair::set_inner_solution(int val) { inner_solution = val; }

int OcctlTopoDistancePair::get_solution_count() const { return solution_count; }
void OcctlTopoDistancePair::set_solution_count(int val) { solution_count = val; }

void OcctlTopoDistancePair::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_distance"), &OcctlTopoDistancePair::get_distance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_distance", "val"), &OcctlTopoDistancePair::set_distance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "distance"), "set_distance", "get_distance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_point_a"), &OcctlTopoDistancePair::get_point_a);
    godot::ClassDB::bind_method(godot::D_METHOD("set_point_a", "val"), &OcctlTopoDistancePair::set_point_a);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "point_a"), "set_point_a", "get_point_a");
    godot::ClassDB::bind_method(godot::D_METHOD("get_point_b"), &OcctlTopoDistancePair::get_point_b);
    godot::ClassDB::bind_method(godot::D_METHOD("set_point_b", "val"), &OcctlTopoDistancePair::set_point_b);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "point_b"), "set_point_b", "get_point_b");
    godot::ClassDB::bind_method(godot::D_METHOD("get_support_a"), &OcctlTopoDistancePair::get_support_a);
    godot::ClassDB::bind_method(godot::D_METHOD("set_support_a", "val"), &OcctlTopoDistancePair::set_support_a);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "support_a"), "set_support_a", "get_support_a");
    godot::ClassDB::bind_method(godot::D_METHOD("get_support_b"), &OcctlTopoDistancePair::get_support_b);
    godot::ClassDB::bind_method(godot::D_METHOD("set_support_b", "val"), &OcctlTopoDistancePair::set_support_b);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "support_b"), "set_support_b", "get_support_b");
    godot::ClassDB::bind_method(godot::D_METHOD("get_inner_solution"), &OcctlTopoDistancePair::get_inner_solution);
    godot::ClassDB::bind_method(godot::D_METHOD("set_inner_solution", "val"), &OcctlTopoDistancePair::set_inner_solution);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "inner_solution"), "set_inner_solution", "get_inner_solution");
    godot::ClassDB::bind_method(godot::D_METHOD("get_solution_count"), &OcctlTopoDistancePair::get_solution_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_solution_count", "val"), &OcctlTopoDistancePair::set_solution_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "solution_count"), "set_solution_count", "get_solution_count");
}

occtl_topo_distance_pair_t OcctlTopoDistancePair::to_c() const {
    occtl_topo_distance_pair_t result = {};
    result.distance = distance;
    result.point_a = point_a->to_c();
    result.point_b = point_b->to_c();
    result.support_a.bits = static_cast<uint64_t>(support_a);
    result.support_b.bits = static_cast<uint64_t>(support_b);
    result.inner_solution = inner_solution;
    result.solution_count = solution_count;
    return result;
}

Ref<OcctlTopoDistancePair> OcctlTopoDistancePair::from_c(const occtl_topo_distance_pair_t& val) {
    Ref<OcctlTopoDistancePair> r;
    r.instantiate();
    r->distance = val.distance;
    r->point_a = OcctlPoint3::from_c(val.point_a);
    r->point_b = OcctlPoint3::from_c(val.point_b);
    r->support_a = static_cast<int64_t>(val.support_a.bits);
    r->support_b = static_cast<int64_t>(val.support_b.bits);
    r->inner_solution = val.inner_solution;
    r->solution_count = val.solution_count;
    return r;
}

void OcctlTopoDistancePair::copy_from_c(const occtl_topo_distance_pair_t& val) {
    distance = val.distance;
    point_a = OcctlPoint3::from_c(val.point_a);
    point_b = OcctlPoint3::from_c(val.point_b);
    support_a = static_cast<int64_t>(val.support_a.bits);
    support_b = static_cast<int64_t>(val.support_b.bits);
    inner_solution = val.inner_solution;
    solution_count = val.solution_count;
}
