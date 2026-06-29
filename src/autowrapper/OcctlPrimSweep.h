#ifndef OCCTLPRIMSWEEP_H
#define OCCTLPRIMSWEEP_H

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
#include "occtl/occtl_prim_sweep.h"

#include "OcctlGraphHandle.h"
#include "OcctlNodeId.h"
#include "OcctlPrimExtrudeTwistInfo.h"
#include "OcctlPrimLoftInfo.h"
#include "OcctlPrimOffsetShapeInfo.h"
#include "OcctlPrimPipeInfo.h"
#include "OcctlPrimPipeShellInfo.h"
#include "OcctlPrimPipeShellInterpolatedLawInfo.h"
#include "OcctlPrimPipeShellLinearLawInfo.h"
#include "OcctlPrimPrismInfo.h"
#include "OcctlPrimRevolInfo.h"
#include "OcctlPrimThickSolidInfo.h"
#include "OcctlPrimTwistExtrusionInfo.h"

using namespace godot;

class OcctlPrimSweep : public godot::RefCounted {
    GDCLASS(OcctlPrimSweep, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    void prism_info_init(const Ref<OcctlPrimPrismInfo>& info); // NOLINT
    int make_prism(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimPrismInfo>& info, const Ref<OcctlNodeId>& out_shape); // NOLINT
    void twist_extrusion_info_init(const Ref<OcctlPrimTwistExtrusionInfo>& info); // NOLINT
    int make_twist_extrusion(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimTwistExtrusionInfo>& info, const Ref<OcctlNodeId>& out_shape); // NOLINT
    void extrude_twist_info_init(const Ref<OcctlPrimExtrudeTwistInfo>& info); // NOLINT
    int make_extrude_twist(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimExtrudeTwistInfo>& info, const Ref<OcctlNodeId>& out_shape); // NOLINT
    void revol_info_init(const Ref<OcctlPrimRevolInfo>& info); // NOLINT
    int make_revol(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimRevolInfo>& info, const Ref<OcctlNodeId>& out_shape); // NOLINT
    void pipe_info_init(const Ref<OcctlPrimPipeInfo>& info); // NOLINT
    int make_pipe(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimPipeInfo>& info, const Ref<OcctlNodeId>& out_shape); // NOLINT
    void loft_info_init(const Ref<OcctlPrimLoftInfo>& info); // NOLINT
    int make_loft(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimLoftInfo>& info, const Ref<OcctlNodeId>& out_shape); // NOLINT
    void pipe_shell_info_init(const Ref<OcctlPrimPipeShellInfo>& info); // NOLINT
    int make_pipe_shell(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimPipeShellInfo>& info, const Ref<OcctlNodeId>& out_shape); // NOLINT
    void pipe_shell_linear_law_info_init(const Ref<OcctlPrimPipeShellLinearLawInfo>& info); // NOLINT
    int make_pipe_shell_linear_law(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimPipeShellLinearLawInfo>& info, const Ref<OcctlNodeId>& out_shape); // NOLINT
    void pipe_shell_interpolated_law_info_init(const Ref<OcctlPrimPipeShellInterpolatedLawInfo>& info); // NOLINT
    int make_pipe_shell_interpolated_law(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimPipeShellInterpolatedLawInfo>& info, const Ref<OcctlNodeId>& out_shape); // NOLINT
    void offset_shape_info_init(const Ref<OcctlPrimOffsetShapeInfo>& info); // NOLINT
    int make_offset_shape(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimOffsetShapeInfo>& info, const Ref<OcctlNodeId>& out_shape); // NOLINT
    void thick_solid_info_init(const Ref<OcctlPrimThickSolidInfo>& info); // NOLINT
    int make_thick_solid(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimThickSolidInfo>& info, const Ref<OcctlNodeId>& out_solid); // NOLINT
};

#endif // OCCTLPRIMSWEEP_H
