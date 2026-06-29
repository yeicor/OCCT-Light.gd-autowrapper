#include "OcctlTopoTouchHit.h"

#include "OcctlNodeId.h"
#include "OcctlPoint3.h"

int64_t OcctlTopoTouchHit::get_node_a() const { return node_a; }
void OcctlTopoTouchHit::set_node_a(int64_t val) { node_a = val; }

int64_t OcctlTopoTouchHit::get_node_b() const { return node_b; }
void OcctlTopoTouchHit::set_node_b(int64_t val) { node_b = val; }

int64_t OcctlTopoTouchHit::get_support_a() const { return support_a; }
void OcctlTopoTouchHit::set_support_a(int64_t val) { support_a = val; }

int64_t OcctlTopoTouchHit::get_support_b() const { return support_b; }
void OcctlTopoTouchHit::set_support_b(int64_t val) { support_b = val; }

Ref<OcctlPoint3> OcctlTopoTouchHit::get_point_a() const { return point_a; }
void OcctlTopoTouchHit::set_point_a(Ref<OcctlPoint3> val) { point_a = val; }

Ref<OcctlPoint3> OcctlTopoTouchHit::get_point_b() const { return point_b; }
void OcctlTopoTouchHit::set_point_b(Ref<OcctlPoint3> val) { point_b = val; }

double OcctlTopoTouchHit::get_distance() const { return distance; }
void OcctlTopoTouchHit::set_distance(double val) { distance = val; }

int OcctlTopoTouchHit::get_inner_solution() const { return inner_solution; }
void OcctlTopoTouchHit::set_inner_solution(int val) { inner_solution = val; }

void OcctlTopoTouchHit::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_node_a"), &OcctlTopoTouchHit::get_node_a);
    godot::ClassDB::bind_method(godot::D_METHOD("set_node_a", "val"), &OcctlTopoTouchHit::set_node_a);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "node_a"), "set_node_a", "get_node_a");
    godot::ClassDB::bind_method(godot::D_METHOD("get_node_b"), &OcctlTopoTouchHit::get_node_b);
    godot::ClassDB::bind_method(godot::D_METHOD("set_node_b", "val"), &OcctlTopoTouchHit::set_node_b);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "node_b"), "set_node_b", "get_node_b");
    godot::ClassDB::bind_method(godot::D_METHOD("get_support_a"), &OcctlTopoTouchHit::get_support_a);
    godot::ClassDB::bind_method(godot::D_METHOD("set_support_a", "val"), &OcctlTopoTouchHit::set_support_a);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "support_a"), "set_support_a", "get_support_a");
    godot::ClassDB::bind_method(godot::D_METHOD("get_support_b"), &OcctlTopoTouchHit::get_support_b);
    godot::ClassDB::bind_method(godot::D_METHOD("set_support_b", "val"), &OcctlTopoTouchHit::set_support_b);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "support_b"), "set_support_b", "get_support_b");
    godot::ClassDB::bind_method(godot::D_METHOD("get_point_a"), &OcctlTopoTouchHit::get_point_a);
    godot::ClassDB::bind_method(godot::D_METHOD("set_point_a", "val"), &OcctlTopoTouchHit::set_point_a);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "point_a"), "set_point_a", "get_point_a");
    godot::ClassDB::bind_method(godot::D_METHOD("get_point_b"), &OcctlTopoTouchHit::get_point_b);
    godot::ClassDB::bind_method(godot::D_METHOD("set_point_b", "val"), &OcctlTopoTouchHit::set_point_b);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "point_b"), "set_point_b", "get_point_b");
    godot::ClassDB::bind_method(godot::D_METHOD("get_distance"), &OcctlTopoTouchHit::get_distance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_distance", "val"), &OcctlTopoTouchHit::set_distance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "distance"), "set_distance", "get_distance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_inner_solution"), &OcctlTopoTouchHit::get_inner_solution);
    godot::ClassDB::bind_method(godot::D_METHOD("set_inner_solution", "val"), &OcctlTopoTouchHit::set_inner_solution);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "inner_solution"), "set_inner_solution", "get_inner_solution");
}

occtl_topo_touch_hit_t OcctlTopoTouchHit::to_c() const {
    occtl_topo_touch_hit_t result = {};
    result.node_a.bits = static_cast<uint64_t>(node_a);
    result.node_b.bits = static_cast<uint64_t>(node_b);
    result.support_a.bits = static_cast<uint64_t>(support_a);
    result.support_b.bits = static_cast<uint64_t>(support_b);
    result.point_a = point_a->to_c();
    result.point_b = point_b->to_c();
    result.distance = distance;
    result.inner_solution = inner_solution;
    return result;
}

Ref<OcctlTopoTouchHit> OcctlTopoTouchHit::from_c(const occtl_topo_touch_hit_t& val) {
    Ref<OcctlTopoTouchHit> r;
    r.instantiate();
    r->node_a = static_cast<int64_t>(val.node_a.bits);
    r->node_b = static_cast<int64_t>(val.node_b.bits);
    r->support_a = static_cast<int64_t>(val.support_a.bits);
    r->support_b = static_cast<int64_t>(val.support_b.bits);
    r->point_a = OcctlPoint3::from_c(val.point_a);
    r->point_b = OcctlPoint3::from_c(val.point_b);
    r->distance = val.distance;
    r->inner_solution = val.inner_solution;
    return r;
}

void OcctlTopoTouchHit::copy_from_c(const occtl_topo_touch_hit_t& val) {
    node_a = static_cast<int64_t>(val.node_a.bits);
    node_b = static_cast<int64_t>(val.node_b.bits);
    support_a = static_cast<int64_t>(val.support_a.bits);
    support_b = static_cast<int64_t>(val.support_b.bits);
    point_a = OcctlPoint3::from_c(val.point_a);
    point_b = OcctlPoint3::from_c(val.point_b);
    distance = val.distance;
    inner_solution = val.inner_solution;
}
