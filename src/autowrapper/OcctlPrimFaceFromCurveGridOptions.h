#ifndef OCCTLPRIMFACEFROMCURVEGRIDOPTIONS_H
#define OCCTLPRIMFACEFROMCURVEGRIDOPTIONS_H

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

#include "OcctlSurfaceCurveGridCreateInfo.h"

using namespace godot;

class OcctlPrimFaceFromCurveGridOptions : public godot::RefCounted {
    GDCLASS(OcctlPrimFaceFromCurveGridOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    Ref<OcctlSurfaceCurveGridCreateInfo> surface;
    double tolerance;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    Ref<OcctlSurfaceCurveGridCreateInfo> get_surface() const;
    void set_surface(Ref<OcctlSurfaceCurveGridCreateInfo> val);
    double get_tolerance() const;
    void set_tolerance(double val);

    occtl_prim_face_from_curve_grid_options_t to_c() const;
    static Ref<OcctlPrimFaceFromCurveGridOptions> from_c(const occtl_prim_face_from_curve_grid_options_t& val);
    void copy_from_c(const occtl_prim_face_from_curve_grid_options_t& val);
};

#endif // OCCTLPRIMFACEFROMCURVEGRIDOPTIONS_H
