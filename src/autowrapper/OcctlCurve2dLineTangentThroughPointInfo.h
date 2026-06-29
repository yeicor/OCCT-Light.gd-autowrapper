#ifndef OCCTLCURVE2DLINETANGENTTHROUGHPOINTINFO_H
#define OCCTLCURVE2DLINETANGENTTHROUGHPOINTINFO_H

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
#include "occtl/occtl_curves2d.h"

#include "OcctlRepId.h"
#include "OcctlPoint2.h"

using namespace godot;

class OcctlCurve2dLineTangentThroughPointInfo : public godot::RefCounted {
    GDCLASS(OcctlCurve2dLineTangentThroughPointInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t curve;
    int qualifier;
    Ref<OcctlPoint2> point;
    double tolerance;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_curve() const;
    void set_curve(int64_t val);
    int get_qualifier() const;
    void set_qualifier(int val);
    Ref<OcctlPoint2> get_point() const;
    void set_point(Ref<OcctlPoint2> val);
    double get_tolerance() const;
    void set_tolerance(double val);

    occtl_curve2d_line_tangent_through_point_info_t to_c() const;
    static Ref<OcctlCurve2dLineTangentThroughPointInfo> from_c(const occtl_curve2d_line_tangent_through_point_info_t& val);
    void copy_from_c(const occtl_curve2d_line_tangent_through_point_info_t& val);
};

#endif // OCCTLCURVE2DLINETANGENTTHROUGHPOINTINFO_H
