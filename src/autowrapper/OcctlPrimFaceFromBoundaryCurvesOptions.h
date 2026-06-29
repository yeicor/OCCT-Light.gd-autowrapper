#ifndef OCCTLPRIMFACEFROMBOUNDARYCURVESOPTIONS_H
#define OCCTLPRIMFACEFROMBOUNDARYCURVESOPTIONS_H

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
#include "occtl/occtl_prim_feature.h"

#include "OcctlSurfaceBoundaryCurvesCreateInfo.h"

using namespace godot;

class OcctlPrimFaceFromBoundaryCurvesOptions : public godot::RefCounted {
    GDCLASS(OcctlPrimFaceFromBoundaryCurvesOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    Ref<OcctlSurfaceBoundaryCurvesCreateInfo> surface;
    double tolerance;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    Ref<OcctlSurfaceBoundaryCurvesCreateInfo> get_surface() const;
    void set_surface(Ref<OcctlSurfaceBoundaryCurvesCreateInfo> val);
    double get_tolerance() const;
    void set_tolerance(double val);

    occtl_prim_face_from_boundary_curves_options_t to_c() const;
    static Ref<OcctlPrimFaceFromBoundaryCurvesOptions> from_c(const occtl_prim_face_from_boundary_curves_options_t& val);
    void copy_from_c(const occtl_prim_face_from_boundary_curves_options_t& val);
};

#endif // OCCTLPRIMFACEFROMBOUNDARYCURVESOPTIONS_H
