#ifndef OCCTLPRIMFEATURE_H
#define OCCTLPRIMFEATURE_H

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
#include "occtl/occtl_prim_feature.h"

#include "OcctlGraphHandle.h"
#include "OcctlNodeId.h"
#include "OcctlPrimBrakeFormedOptions.h"
#include "OcctlPrimCylindricalHoleInfo.h"
#include "OcctlPrimDraftPrismInfo.h"
#include "OcctlPrimExtrudeTaperedInfo.h"
#include "OcctlPrimExtrudeUntilInfo.h"
#include "OcctlPrimFaceFromBoundaryCurvesOptions.h"
#include "OcctlPrimFaceFromCurveGridOptions.h"
#include "OcctlPrimFaceFromPointGridOptions.h"
#include "OcctlPrimFaceFromSurfaceOptions.h"
#include "OcctlPrimFeatDraftPrismInfo.h"
#include "OcctlPrimFeatPrismInfo.h"
#include "OcctlPrimRuledSurfaceInfo.h"

using namespace godot;

class OcctlPrimFeature : public godot::RefCounted {
    GDCLASS(OcctlPrimFeature, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    void face_from_surface_options_init(const Ref<OcctlPrimFaceFromSurfaceOptions>& options); // NOLINT
    int make_face_from_surface(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimFaceFromSurfaceOptions>& options, const Ref<OcctlNodeId>& out_face); // NOLINT
    void face_from_point_grid_options_init(const Ref<OcctlPrimFaceFromPointGridOptions>& options); // NOLINT
    int make_face_from_point_grid(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimFaceFromPointGridOptions>& options, const Ref<OcctlNodeId>& out_face); // NOLINT
    void face_from_boundary_curves_options_init(const Ref<OcctlPrimFaceFromBoundaryCurvesOptions>& options); // NOLINT
    int make_face_from_boundary_curves(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimFaceFromBoundaryCurvesOptions>& options, const Ref<OcctlNodeId>& out_face); // NOLINT
    void face_from_curve_grid_options_init(const Ref<OcctlPrimFaceFromCurveGridOptions>& options); // NOLINT
    int make_face_from_curve_grid(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimFaceFromCurveGridOptions>& options, const Ref<OcctlNodeId>& out_face); // NOLINT
    void brake_formed_options_init(const Ref<OcctlPrimBrakeFormedOptions>& opts); // NOLINT
    Ref<OcctlGraphHandle> make_brake_formed(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimBrakeFormedOptions>& options, const Ref<OcctlNodeId>& out_root); // NOLINT
    void draft_prism_info_init(const Ref<OcctlPrimDraftPrismInfo>& info); // NOLINT
    int make_draft_prism(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimDraftPrismInfo>& info, const Ref<OcctlNodeId>& out_shape); // NOLINT
    void extrude_tapered_info_init(const Ref<OcctlPrimExtrudeTaperedInfo>& info); // NOLINT
    int make_extrude_tapered(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimExtrudeTaperedInfo>& info, const Ref<OcctlNodeId>& out_shape); // NOLINT
    void ruled_surface_info_init(const Ref<OcctlPrimRuledSurfaceInfo>& info); // NOLINT
    int make_ruled_surface(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimRuledSurfaceInfo>& info, const Ref<OcctlNodeId>& out_shape); // NOLINT
    void feat_prism_info_init(const Ref<OcctlPrimFeatPrismInfo>& info); // NOLINT
    int make_feat_prism(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimFeatPrismInfo>& info, const Ref<OcctlNodeId>& out_shape); // NOLINT
    void extrude_until_info_init(const Ref<OcctlPrimExtrudeUntilInfo>& info); // NOLINT
    int make_extrude_until(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimExtrudeUntilInfo>& info, const Ref<OcctlNodeId>& out_shape); // NOLINT
    void feat_draft_prism_info_init(const Ref<OcctlPrimFeatDraftPrismInfo>& info); // NOLINT
    int make_feat_draft_prism(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimFeatDraftPrismInfo>& info, const Ref<OcctlNodeId>& out_shape); // NOLINT
    void cylindrical_hole_info_init(const Ref<OcctlPrimCylindricalHoleInfo>& info); // NOLINT
    int make_cylindrical_hole(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimCylindricalHoleInfo>& info, const Ref<OcctlNodeId>& out_shape); // NOLINT
};

#endif // OCCTLPRIMFEATURE_H
