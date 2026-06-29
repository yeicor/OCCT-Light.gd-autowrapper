#include "OcctlGeom.h"

#include "occtl/occtl_geom.h"

void OcctlGeom::_bind_methods() {
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_geom_continuity_t", "OCCTL_GEOM_CONTINUITY_C0", OCCTL_GEOM_CONTINUITY_C0);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_geom_continuity_t", "OCCTL_GEOM_CONTINUITY_G1", OCCTL_GEOM_CONTINUITY_G1);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_geom_continuity_t", "OCCTL_GEOM_CONTINUITY_C1", OCCTL_GEOM_CONTINUITY_C1);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_geom_continuity_t", "OCCTL_GEOM_CONTINUITY_G2", OCCTL_GEOM_CONTINUITY_G2);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_geom_continuity_t", "OCCTL_GEOM_CONTINUITY_C2", OCCTL_GEOM_CONTINUITY_C2);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_geom_continuity_t", "OCCTL_GEOM_CONTINUITY_C3", OCCTL_GEOM_CONTINUITY_C3);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_geom_continuity_t", "OCCTL_GEOM_CONTINUITY_CN", OCCTL_GEOM_CONTINUITY_CN);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_geom_continuity_t", "OCCTL_GEOM_CONTINUITY_RESERVED_FUTURE", OCCTL_GEOM_CONTINUITY_RESERVED_FUTURE);
    godot::ClassDB::bind_method(godot::D_METHOD("point3_distance", "a", "b"), &OcctlGeom::point3_distance);
    godot::ClassDB::bind_method(godot::D_METHOD("point3_midpoint", "a", "b"), &OcctlGeom::point3_midpoint);
    godot::ClassDB::bind_method(godot::D_METHOD("point3_translate", "p", "v"), &OcctlGeom::point3_translate);
    godot::ClassDB::bind_method(godot::D_METHOD("transform_apply_point3", "t", "p"), &OcctlGeom::transform_apply_point3);
    godot::ClassDB::bind_method(godot::D_METHOD("point2_distance", "a", "b"), &OcctlGeom::point2_distance);
    godot::ClassDB::bind_method(godot::D_METHOD("point2_midpoint", "a", "b"), &OcctlGeom::point2_midpoint);
    godot::ClassDB::bind_method(godot::D_METHOD("vector3_dot", "a", "b"), &OcctlGeom::vector3_dot);
    godot::ClassDB::bind_method(godot::D_METHOD("vector3_cross", "a", "b"), &OcctlGeom::vector3_cross);
    godot::ClassDB::bind_method(godot::D_METHOD("vector3_magnitude", "v"), &OcctlGeom::vector3_magnitude);
    godot::ClassDB::bind_method(godot::D_METHOD("vector3_normalized", "v", "out_result"), &OcctlGeom::vector3_normalized);
    godot::ClassDB::bind_method(godot::D_METHOD("vector3_angle", "a", "b", "out_radians"), &OcctlGeom::vector3_angle);
    godot::ClassDB::bind_method(godot::D_METHOD("vector3_add", "a", "b"), &OcctlGeom::vector3_add);
    godot::ClassDB::bind_method(godot::D_METHOD("vector3_sub", "a", "b"), &OcctlGeom::vector3_sub);
    godot::ClassDB::bind_method(godot::D_METHOD("vector3_scaled", "v", "s"), &OcctlGeom::vector3_scaled);
    godot::ClassDB::bind_method(godot::D_METHOD("vector3_reversed", "v"), &OcctlGeom::vector3_reversed);
    godot::ClassDB::bind_method(godot::D_METHOD("vector2_dot", "a", "b"), &OcctlGeom::vector2_dot);
    godot::ClassDB::bind_method(godot::D_METHOD("vector2_cross", "a", "b"), &OcctlGeom::vector2_cross);
    godot::ClassDB::bind_method(godot::D_METHOD("vector2_magnitude", "v"), &OcctlGeom::vector2_magnitude);
    godot::ClassDB::bind_method(godot::D_METHOD("vector2_normalized", "v", "out_result"), &OcctlGeom::vector2_normalized);
    godot::ClassDB::bind_method(godot::D_METHOD("direction3_from_vector", "v", "out_direction"), &OcctlGeom::direction3_from_vector);
    godot::ClassDB::bind_method(godot::D_METHOD("direction3_dot", "a", "b"), &OcctlGeom::direction3_dot);
    godot::ClassDB::bind_method(godot::D_METHOD("direction3_cross", "a", "b"), &OcctlGeom::direction3_cross);
    godot::ClassDB::bind_method(godot::D_METHOD("direction3_angle", "a", "b"), &OcctlGeom::direction3_angle);
    godot::ClassDB::bind_method(godot::D_METHOD("direction3_reversed", "d"), &OcctlGeom::direction3_reversed);
    godot::ClassDB::bind_method(godot::D_METHOD("direction3_transform", "d", "t", "out_direction"), &OcctlGeom::direction3_transform);
    godot::ClassDB::bind_method(godot::D_METHOD("direction2_from_vector", "v", "out_direction"), &OcctlGeom::direction2_from_vector);
    godot::ClassDB::bind_method(godot::D_METHOD("direction2_angle", "a", "b"), &OcctlGeom::direction2_angle);
    godot::ClassDB::bind_method(godot::D_METHOD("transform_identity"), &OcctlGeom::transform_identity);
    godot::ClassDB::bind_method(godot::D_METHOD("transform_translation", "v"), &OcctlGeom::transform_translation);
    godot::ClassDB::bind_method(godot::D_METHOD("transform_rotation", "axis", "angle", "out_transform"), &OcctlGeom::transform_rotation);
    godot::ClassDB::bind_method(godot::D_METHOD("transform_scale", "center", "s", "out_transform"), &OcctlGeom::transform_scale);
    godot::ClassDB::bind_method(godot::D_METHOD("transform_compose", "first", "second"), &OcctlGeom::transform_compose);
    godot::ClassDB::bind_method(godot::D_METHOD("transform_inverted", "t", "out_transform"), &OcctlGeom::transform_inverted);
    godot::ClassDB::bind_method(godot::D_METHOD("transform_apply_vector3", "t", "v"), &OcctlGeom::transform_apply_vector3);
    godot::ClassDB::bind_method(godot::D_METHOD("transform_from_axis2", "frame", "out_transform"), &OcctlGeom::transform_from_axis2);
    godot::ClassDB::bind_method(godot::D_METHOD("transform_from_axis3", "frame", "out_transform"), &OcctlGeom::transform_from_axis3);
}

double OcctlGeom::point3_distance(const Ref<OcctlPoint3>& a, const Ref<OcctlPoint3>& b) { // NOLINT
    auto _result = ::occtl_point3_distance(a->to_c(), b->to_c());
    return _result;
}

Ref<OcctlPoint3> OcctlGeom::point3_midpoint(const Ref<OcctlPoint3>& a, const Ref<OcctlPoint3>& b) { // NOLINT
    auto _result = ::occtl_point3_midpoint(a->to_c(), b->to_c());
    return OcctlPoint3::from_c(_result);
}

Ref<OcctlPoint3> OcctlGeom::point3_translate(const Ref<OcctlPoint3>& p, const Ref<OcctlVector3>& v) { // NOLINT
    auto _result = ::occtl_point3_translate(p->to_c(), v->to_c());
    return OcctlPoint3::from_c(_result);
}

Ref<OcctlPoint3> OcctlGeom::transform_apply_point3(const Ref<OcctlTransform>& t, const Ref<OcctlPoint3>& p) { // NOLINT
    auto _result = ::occtl_transform_apply_point3(t->to_c(), p->to_c());
    return OcctlPoint3::from_c(_result);
}

double OcctlGeom::point2_distance(const Ref<OcctlPoint2>& a, const Ref<OcctlPoint2>& b) { // NOLINT
    auto _result = ::occtl_point2_distance(a->to_c(), b->to_c());
    return _result;
}

Ref<OcctlPoint2> OcctlGeom::point2_midpoint(const Ref<OcctlPoint2>& a, const Ref<OcctlPoint2>& b) { // NOLINT
    auto _result = ::occtl_point2_midpoint(a->to_c(), b->to_c());
    return OcctlPoint2::from_c(_result);
}

double OcctlGeom::vector3_dot(const Ref<OcctlVector3>& a, const Ref<OcctlVector3>& b) { // NOLINT
    auto _result = ::occtl_vector3_dot(a->to_c(), b->to_c());
    return _result;
}

Ref<OcctlVector3> OcctlGeom::vector3_cross(const Ref<OcctlVector3>& a, const Ref<OcctlVector3>& b) { // NOLINT
    auto _result = ::occtl_vector3_cross(a->to_c(), b->to_c());
    return OcctlVector3::from_c(_result);
}

double OcctlGeom::vector3_magnitude(const Ref<OcctlVector3>& v) { // NOLINT
    auto _result = ::occtl_vector3_magnitude(v->to_c());
    return _result;
}

int OcctlGeom::vector3_normalized(const Ref<OcctlVector3>& v, const Ref<OcctlVector3>& out_result) { // NOLINT
    occtl_vector3_t _out_result_val = {};
    occtl_status_t _status = ::occtl_vector3_normalized(v->to_c(), &_out_result_val);
    if (out_result.is_valid()) out_result->copy_from_c(_out_result_val);
    return static_cast<int>(_status);
}

int OcctlGeom::vector3_angle(const Ref<OcctlVector3>& a, const Ref<OcctlVector3>& b, const Ref<OcctlDouble>& out_radians) { // NOLINT
    double _out_radians_val = {};
    occtl_status_t _status = ::occtl_vector3_angle(a->to_c(), b->to_c(), &_out_radians_val);
    if (out_radians.is_valid()) out_radians->copy_from_c(_out_radians_val);
    return static_cast<int>(_status);
}

Ref<OcctlVector3> OcctlGeom::vector3_add(const Ref<OcctlVector3>& a, const Ref<OcctlVector3>& b) { // NOLINT
    auto _result = ::occtl_vector3_add(a->to_c(), b->to_c());
    return OcctlVector3::from_c(_result);
}

Ref<OcctlVector3> OcctlGeom::vector3_sub(const Ref<OcctlVector3>& a, const Ref<OcctlVector3>& b) { // NOLINT
    auto _result = ::occtl_vector3_sub(a->to_c(), b->to_c());
    return OcctlVector3::from_c(_result);
}

Ref<OcctlVector3> OcctlGeom::vector3_scaled(const Ref<OcctlVector3>& v, double s) { // NOLINT
    auto _result = ::occtl_vector3_scaled(v->to_c(), s);
    return OcctlVector3::from_c(_result);
}

Ref<OcctlVector3> OcctlGeom::vector3_reversed(const Ref<OcctlVector3>& v) { // NOLINT
    auto _result = ::occtl_vector3_reversed(v->to_c());
    return OcctlVector3::from_c(_result);
}

double OcctlGeom::vector2_dot(const Ref<OcctlVector2>& a, const Ref<OcctlVector2>& b) { // NOLINT
    auto _result = ::occtl_vector2_dot(a->to_c(), b->to_c());
    return _result;
}

double OcctlGeom::vector2_cross(const Ref<OcctlVector2>& a, const Ref<OcctlVector2>& b) { // NOLINT
    auto _result = ::occtl_vector2_cross(a->to_c(), b->to_c());
    return _result;
}

double OcctlGeom::vector2_magnitude(const Ref<OcctlVector2>& v) { // NOLINT
    auto _result = ::occtl_vector2_magnitude(v->to_c());
    return _result;
}

int OcctlGeom::vector2_normalized(const Ref<OcctlVector2>& v, const Ref<OcctlVector2>& out_result) { // NOLINT
    occtl_vector2_t _out_result_val = {};
    occtl_status_t _status = ::occtl_vector2_normalized(v->to_c(), &_out_result_val);
    if (out_result.is_valid()) out_result->copy_from_c(_out_result_val);
    return static_cast<int>(_status);
}

int OcctlGeom::direction3_from_vector(const Ref<OcctlVector3>& v, const Ref<OcctlDirection3>& out_direction) { // NOLINT
    occtl_direction3_t _out_direction_val = {};
    occtl_status_t _status = ::occtl_direction3_from_vector(v->to_c(), &_out_direction_val);
    if (out_direction.is_valid()) out_direction->copy_from_c(_out_direction_val);
    return static_cast<int>(_status);
}

double OcctlGeom::direction3_dot(const Ref<OcctlDirection3>& a, const Ref<OcctlDirection3>& b) { // NOLINT
    auto _result = ::occtl_direction3_dot(a->to_c(), b->to_c());
    return _result;
}

Ref<OcctlVector3> OcctlGeom::direction3_cross(const Ref<OcctlDirection3>& a, const Ref<OcctlDirection3>& b) { // NOLINT
    auto _result = ::occtl_direction3_cross(a->to_c(), b->to_c());
    return OcctlVector3::from_c(_result);
}

double OcctlGeom::direction3_angle(const Ref<OcctlDirection3>& a, const Ref<OcctlDirection3>& b) { // NOLINT
    auto _result = ::occtl_direction3_angle(a->to_c(), b->to_c());
    return _result;
}

Ref<OcctlDirection3> OcctlGeom::direction3_reversed(const Ref<OcctlDirection3>& d) { // NOLINT
    auto _result = ::occtl_direction3_reversed(d->to_c());
    return OcctlDirection3::from_c(_result);
}

int OcctlGeom::direction3_transform(const Ref<OcctlDirection3>& d, const Ref<OcctlTransform>& t, const Ref<OcctlDirection3>& out_direction) { // NOLINT
    occtl_direction3_t _out_direction_val = {};
    occtl_status_t _status = ::occtl_direction3_transform(d->to_c(), t->to_c(), &_out_direction_val);
    if (out_direction.is_valid()) out_direction->copy_from_c(_out_direction_val);
    return static_cast<int>(_status);
}

int OcctlGeom::direction2_from_vector(const Ref<OcctlVector2>& v, const Ref<OcctlDirection2>& out_direction) { // NOLINT
    occtl_direction2_t _out_direction_val = {};
    occtl_status_t _status = ::occtl_direction2_from_vector(v->to_c(), &_out_direction_val);
    if (out_direction.is_valid()) out_direction->copy_from_c(_out_direction_val);
    return static_cast<int>(_status);
}

double OcctlGeom::direction2_angle(const Ref<OcctlDirection2>& a, const Ref<OcctlDirection2>& b) { // NOLINT
    auto _result = ::occtl_direction2_angle(a->to_c(), b->to_c());
    return _result;
}

Ref<OcctlTransform> OcctlGeom::transform_identity(void) { // NOLINT
    auto _result = ::occtl_transform_identity();
    return OcctlTransform::from_c(_result);
}

Ref<OcctlTransform> OcctlGeom::transform_translation(const Ref<OcctlVector3>& v) { // NOLINT
    auto _result = ::occtl_transform_translation(v->to_c());
    return OcctlTransform::from_c(_result);
}

int OcctlGeom::transform_rotation(const Ref<OcctlAxis1Placement>& axis, double angle, const Ref<OcctlTransform>& out_transform) { // NOLINT
    occtl_transform_t _out_transform_val = {};
    occtl_status_t _status = ::occtl_transform_rotation(axis->to_c(), angle, &_out_transform_val);
    if (out_transform.is_valid()) out_transform->copy_from_c(_out_transform_val);
    return static_cast<int>(_status);
}

int OcctlGeom::transform_scale(const Ref<OcctlPoint3>& center, double s, const Ref<OcctlTransform>& out_transform) { // NOLINT
    occtl_transform_t _out_transform_val = {};
    occtl_status_t _status = ::occtl_transform_scale(center->to_c(), s, &_out_transform_val);
    if (out_transform.is_valid()) out_transform->copy_from_c(_out_transform_val);
    return static_cast<int>(_status);
}

Ref<OcctlTransform> OcctlGeom::transform_compose(const Ref<OcctlTransform>& first, const Ref<OcctlTransform>& second) { // NOLINT
    auto _result = ::occtl_transform_compose(first->to_c(), second->to_c());
    return OcctlTransform::from_c(_result);
}

int OcctlGeom::transform_inverted(const Ref<OcctlTransform>& t, const Ref<OcctlTransform>& out_transform) { // NOLINT
    occtl_transform_t _out_transform_val = {};
    occtl_status_t _status = ::occtl_transform_inverted(t->to_c(), &_out_transform_val);
    if (out_transform.is_valid()) out_transform->copy_from_c(_out_transform_val);
    return static_cast<int>(_status);
}

Ref<OcctlVector3> OcctlGeom::transform_apply_vector3(const Ref<OcctlTransform>& t, const Ref<OcctlVector3>& v) { // NOLINT
    auto _result = ::occtl_transform_apply_vector3(t->to_c(), v->to_c());
    return OcctlVector3::from_c(_result);
}

int OcctlGeom::transform_from_axis2(const Ref<OcctlAxis2Placement>& frame, const Ref<OcctlTransform>& out_transform) { // NOLINT
    occtl_transform_t _out_transform_val = {};
    occtl_status_t _status = ::occtl_transform_from_axis2(frame->to_c(), &_out_transform_val);
    if (out_transform.is_valid()) out_transform->copy_from_c(_out_transform_val);
    return static_cast<int>(_status);
}

int OcctlGeom::transform_from_axis3(const Ref<OcctlAxis3Placement>& frame, const Ref<OcctlTransform>& out_transform) { // NOLINT
    occtl_transform_t _out_transform_val = {};
    occtl_status_t _status = ::occtl_transform_from_axis3(frame->to_c(), &_out_transform_val);
    if (out_transform.is_valid()) out_transform->copy_from_c(_out_transform_val);
    return static_cast<int>(_status);
}
