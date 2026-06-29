#include "OcctlTopoAxisHit.h"

#include "OcctlNodeId.h"
#include "OcctlPoint3.h"
#include "OcctlPoint2.h"
#include "OcctlDirection3.h"

int64_t OcctlTopoAxisHit::get_face() const { return face; }
void OcctlTopoAxisHit::set_face(int64_t val) { face = val; }

Ref<OcctlPoint3> OcctlTopoAxisHit::get_point() const { return point; }
void OcctlTopoAxisHit::set_point(Ref<OcctlPoint3> val) { point = val; }

Ref<OcctlPoint2> OcctlTopoAxisHit::get_uv() const { return uv; }
void OcctlTopoAxisHit::set_uv(Ref<OcctlPoint2> val) { uv = val; }

double OcctlTopoAxisHit::get_parameter() const { return parameter; }
void OcctlTopoAxisHit::set_parameter(double val) { parameter = val; }

Ref<OcctlDirection3> OcctlTopoAxisHit::get_normal() const { return normal; }
void OcctlTopoAxisHit::set_normal(Ref<OcctlDirection3> val) { normal = val; }

int OcctlTopoAxisHit::get_has_normal() const { return has_normal; }
void OcctlTopoAxisHit::set_has_normal(int val) { has_normal = val; }

int OcctlTopoAxisHit::get_location() const { return location; }
void OcctlTopoAxisHit::set_location(int val) { location = val; }

void OcctlTopoAxisHit::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_face"), &OcctlTopoAxisHit::get_face);
    godot::ClassDB::bind_method(godot::D_METHOD("set_face", "val"), &OcctlTopoAxisHit::set_face);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "face"), "set_face", "get_face");
    godot::ClassDB::bind_method(godot::D_METHOD("get_point"), &OcctlTopoAxisHit::get_point);
    godot::ClassDB::bind_method(godot::D_METHOD("set_point", "val"), &OcctlTopoAxisHit::set_point);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "point"), "set_point", "get_point");
    godot::ClassDB::bind_method(godot::D_METHOD("get_uv"), &OcctlTopoAxisHit::get_uv);
    godot::ClassDB::bind_method(godot::D_METHOD("set_uv", "val"), &OcctlTopoAxisHit::set_uv);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "uv"), "set_uv", "get_uv");
    godot::ClassDB::bind_method(godot::D_METHOD("get_parameter"), &OcctlTopoAxisHit::get_parameter);
    godot::ClassDB::bind_method(godot::D_METHOD("set_parameter", "val"), &OcctlTopoAxisHit::set_parameter);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "parameter"), "set_parameter", "get_parameter");
    godot::ClassDB::bind_method(godot::D_METHOD("get_normal"), &OcctlTopoAxisHit::get_normal);
    godot::ClassDB::bind_method(godot::D_METHOD("set_normal", "val"), &OcctlTopoAxisHit::set_normal);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "normal"), "set_normal", "get_normal");
    godot::ClassDB::bind_method(godot::D_METHOD("get_has_normal"), &OcctlTopoAxisHit::get_has_normal);
    godot::ClassDB::bind_method(godot::D_METHOD("set_has_normal", "val"), &OcctlTopoAxisHit::set_has_normal);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "has_normal"), "set_has_normal", "get_has_normal");
    godot::ClassDB::bind_method(godot::D_METHOD("get_location"), &OcctlTopoAxisHit::get_location);
    godot::ClassDB::bind_method(godot::D_METHOD("set_location", "val"), &OcctlTopoAxisHit::set_location);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "location"), "set_location", "get_location");
}

occtl_topo_axis_hit_t OcctlTopoAxisHit::to_c() const {
    occtl_topo_axis_hit_t result = {};
    result.face.bits = static_cast<uint64_t>(face);
    result.point = point->to_c();
    result.uv = uv->to_c();
    result.parameter = parameter;
    result.normal = normal->to_c();
    result.has_normal = has_normal;
    result.location = static_cast<occtl_topo_point_class_t>(location);
    return result;
}

Ref<OcctlTopoAxisHit> OcctlTopoAxisHit::from_c(const occtl_topo_axis_hit_t& val) {
    Ref<OcctlTopoAxisHit> r;
    r.instantiate();
    r->face = static_cast<int64_t>(val.face.bits);
    r->point = OcctlPoint3::from_c(val.point);
    r->uv = OcctlPoint2::from_c(val.uv);
    r->parameter = val.parameter;
    r->normal = OcctlDirection3::from_c(val.normal);
    r->has_normal = val.has_normal;
    r->location = static_cast<int>(val.location);
    return r;
}

void OcctlTopoAxisHit::copy_from_c(const occtl_topo_axis_hit_t& val) {
    face = static_cast<int64_t>(val.face.bits);
    point = OcctlPoint3::from_c(val.point);
    uv = OcctlPoint2::from_c(val.uv);
    parameter = val.parameter;
    normal = OcctlDirection3::from_c(val.normal);
    has_normal = val.has_normal;
    location = static_cast<int>(val.location);
}
