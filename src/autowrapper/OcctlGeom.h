#ifndef OCCTLGEOM_H
#define OCCTLGEOM_H

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
#include "occtl/occtl_geom.h"

#include "OcctlAxis1Placement.h"
#include "OcctlAxis2Placement.h"
#include "OcctlAxis3Placement.h"
#include "OcctlDirection2.h"
#include "OcctlDirection3.h"
#include "OcctlDouble.h"
#include "OcctlPoint2.h"
#include "OcctlPoint3.h"
#include "OcctlTransform.h"
#include "OcctlVector2.h"
#include "OcctlVector3.h"

using namespace godot;

class OcctlGeom : public godot::RefCounted {
    GDCLASS(OcctlGeom, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    double point3_distance(const Ref<OcctlPoint3>& a, const Ref<OcctlPoint3>& b); // NOLINT
    Ref<OcctlPoint3> point3_midpoint(const Ref<OcctlPoint3>& a, const Ref<OcctlPoint3>& b); // NOLINT
    Ref<OcctlPoint3> point3_translate(const Ref<OcctlPoint3>& p, const Ref<OcctlVector3>& v); // NOLINT
    Ref<OcctlPoint3> transform_apply_point3(const Ref<OcctlTransform>& t, const Ref<OcctlPoint3>& p); // NOLINT
    double point2_distance(const Ref<OcctlPoint2>& a, const Ref<OcctlPoint2>& b); // NOLINT
    Ref<OcctlPoint2> point2_midpoint(const Ref<OcctlPoint2>& a, const Ref<OcctlPoint2>& b); // NOLINT
    double vector3_dot(const Ref<OcctlVector3>& a, const Ref<OcctlVector3>& b); // NOLINT
    Ref<OcctlVector3> vector3_cross(const Ref<OcctlVector3>& a, const Ref<OcctlVector3>& b); // NOLINT
    double vector3_magnitude(const Ref<OcctlVector3>& v); // NOLINT
    int vector3_normalized(const Ref<OcctlVector3>& v, const Ref<OcctlVector3>& out_result); // NOLINT
    int vector3_angle(const Ref<OcctlVector3>& a, const Ref<OcctlVector3>& b, const Ref<OcctlDouble>& out_radians); // NOLINT
    Ref<OcctlVector3> vector3_add(const Ref<OcctlVector3>& a, const Ref<OcctlVector3>& b); // NOLINT
    Ref<OcctlVector3> vector3_sub(const Ref<OcctlVector3>& a, const Ref<OcctlVector3>& b); // NOLINT
    Ref<OcctlVector3> vector3_scaled(const Ref<OcctlVector3>& v, double s); // NOLINT
    Ref<OcctlVector3> vector3_reversed(const Ref<OcctlVector3>& v); // NOLINT
    double vector2_dot(const Ref<OcctlVector2>& a, const Ref<OcctlVector2>& b); // NOLINT
    double vector2_cross(const Ref<OcctlVector2>& a, const Ref<OcctlVector2>& b); // NOLINT
    double vector2_magnitude(const Ref<OcctlVector2>& v); // NOLINT
    int vector2_normalized(const Ref<OcctlVector2>& v, const Ref<OcctlVector2>& out_result); // NOLINT
    int direction3_from_vector(const Ref<OcctlVector3>& v, const Ref<OcctlDirection3>& out_direction); // NOLINT
    double direction3_dot(const Ref<OcctlDirection3>& a, const Ref<OcctlDirection3>& b); // NOLINT
    Ref<OcctlVector3> direction3_cross(const Ref<OcctlDirection3>& a, const Ref<OcctlDirection3>& b); // NOLINT
    double direction3_angle(const Ref<OcctlDirection3>& a, const Ref<OcctlDirection3>& b); // NOLINT
    Ref<OcctlDirection3> direction3_reversed(const Ref<OcctlDirection3>& d); // NOLINT
    int direction3_transform(const Ref<OcctlDirection3>& d, const Ref<OcctlTransform>& t, const Ref<OcctlDirection3>& out_direction); // NOLINT
    int direction2_from_vector(const Ref<OcctlVector2>& v, const Ref<OcctlDirection2>& out_direction); // NOLINT
    double direction2_angle(const Ref<OcctlDirection2>& a, const Ref<OcctlDirection2>& b); // NOLINT
    Ref<OcctlTransform> transform_identity(void); // NOLINT
    Ref<OcctlTransform> transform_translation(const Ref<OcctlVector3>& v); // NOLINT
    int transform_rotation(const Ref<OcctlAxis1Placement>& axis, double angle, const Ref<OcctlTransform>& out_transform); // NOLINT
    int transform_scale(const Ref<OcctlPoint3>& center, double s, const Ref<OcctlTransform>& out_transform); // NOLINT
    Ref<OcctlTransform> transform_compose(const Ref<OcctlTransform>& first, const Ref<OcctlTransform>& second); // NOLINT
    int transform_inverted(const Ref<OcctlTransform>& t, const Ref<OcctlTransform>& out_transform); // NOLINT
    Ref<OcctlVector3> transform_apply_vector3(const Ref<OcctlTransform>& t, const Ref<OcctlVector3>& v); // NOLINT
    int transform_from_axis2(const Ref<OcctlAxis2Placement>& frame, const Ref<OcctlTransform>& out_transform); // NOLINT
    int transform_from_axis3(const Ref<OcctlAxis3Placement>& frame, const Ref<OcctlTransform>& out_transform); // NOLINT
};

#endif // OCCTLGEOM_H
