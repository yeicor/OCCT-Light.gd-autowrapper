#ifndef OCCTLTOPOALGO_H
#define OCCTLTOPOALGO_H

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
#include "occtl/occtl_topo_algo.h"

#include "OcctlDirection3.h"
#include "OcctlDouble.h"
#include "OcctlGraphHandle.h"
#include "OcctlNodeId.h"
#include "OcctlPoint3.h"
#include "OcctlSize.h"
#include "OcctlTopoCheckIssue.h"
#include "OcctlTopoCircularPatternOptions.h"
#include "OcctlTopoDefeatureOptions.h"
#include "OcctlTopoDraftFacesOptions.h"
#include "OcctlTopoEdgeBlendOptions.h"
#include "OcctlTopoExtrudeFacesOptions.h"
#include "OcctlTopoFaceToArcsOptions.h"
#include "OcctlTopoFilletOptions.h"
#include "OcctlTopoFillingOptions.h"
#include "OcctlTopoFillingPatchOptions.h"
#include "OcctlTopoHlrOptions.h"
#include "OcctlTopoHlrResult.h"
#include "OcctlTopoLinearPatternOptions.h"
#include "OcctlTopoMaxFilletRadiusOptions.h"
#include "OcctlTopoOffsetFeaturesOptions.h"
#include "OcctlTopoProjectFaceDirectionOptions.h"
#include "OcctlTopoProjectOnFaceOptions.h"
#include "OcctlTopoSameParameterOptions.h"
#include "OcctlTopoSectionByPlanesOptions.h"
#include "OcctlTopoSewOptions.h"
#include "OcctlTopoSewResult.h"
#include "OcctlTopoSplitByPlaneOptions.h"
#include "OcctlTopoWrapOnFaceOptions.h"
#include "OcctlTransform.h"
#include "OcctlUint32.h"

using namespace godot;

class OcctlTopoAlgo : public godot::RefCounted {
    GDCLASS(OcctlTopoAlgo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    void sew_options_init(const Ref<OcctlTopoSewOptions>& options); // NOLINT
    void sew_result_init(const Ref<OcctlTopoSewResult>& result); // NOLINT
    int sew(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoSewOptions>& options, const Ref<OcctlTopoSewResult>& out_result); // NOLINT
    void same_parameter_options_init(const Ref<OcctlTopoSameParameterOptions>& options); // NOLINT
    int recompute_same_parameter(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoSameParameterOptions>& options, const Ref<OcctlUint32>& out_c0_fallback_count, const Ref<OcctlUint32>& out_approx_fallback_count); // NOLINT
    Array check(const Ref<OcctlGraphHandle>& graph); // NOLINT
    void fillet_options_init(const Ref<OcctlTopoFilletOptions>& opts); // NOLINT
    Ref<OcctlGraphHandle> fillet(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoFilletOptions>& opts, const Ref<OcctlNodeId>& out_root); // NOLINT
    void edge_blend_options_init(const Ref<OcctlTopoEdgeBlendOptions>& opts); // NOLINT
    Ref<OcctlGraphHandle> blend_edges(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoEdgeBlendOptions>& options, const Ref<OcctlNodeId>& out_root); // NOLINT
    void max_fillet_radius_options_init(const Ref<OcctlTopoMaxFilletRadiusOptions>& opts); // NOLINT
    int max_fillet_radius(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoMaxFilletRadiusOptions>& options, const Ref<OcctlDouble>& out_radius); // NOLINT
    Ref<OcctlGraphHandle> transformed(const Ref<OcctlGraphHandle>& graph, int64_t root, const Ref<OcctlTransform>& transform, const Ref<OcctlNodeId>& out_root); // NOLINT
    void project_on_face_options_init(const Ref<OcctlTopoProjectOnFaceOptions>& opts); // NOLINT
    Ref<OcctlGraphHandle> project_on_face(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoProjectOnFaceOptions>& options, const Ref<OcctlNodeId>& out_root); // NOLINT
    void wrap_on_face_options_init(const Ref<OcctlTopoWrapOnFaceOptions>& opts); // NOLINT
    Ref<OcctlGraphHandle> wrap_on_face(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoWrapOnFaceOptions>& options, const Ref<OcctlNodeId>& out_root); // NOLINT
    void project_face_direction_options_init(const Ref<OcctlTopoProjectFaceDirectionOptions>& opts); // NOLINT
    Ref<OcctlGraphHandle> project_face_along_direction(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoProjectFaceDirectionOptions>& options, const Ref<OcctlNodeId>& out_root); // NOLINT
    void face_to_arcs_options_init(const Ref<OcctlTopoFaceToArcsOptions>& opts); // NOLINT
    Ref<OcctlGraphHandle> face_to_arcs(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoFaceToArcsOptions>& options, const Ref<OcctlNodeId>& out_root); // NOLINT
    void hlr_result_init(const Ref<OcctlTopoHlrResult>& result); // NOLINT
    void hlr_options_init(const Ref<OcctlTopoHlrOptions>& options); // NOLINT
    int make_hlr_projection(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoHlrOptions>& options, const Ref<OcctlTopoHlrResult>& out_result); // NOLINT
    void draft_faces_options_init(const Ref<OcctlTopoDraftFacesOptions>& opts); // NOLINT
    Ref<OcctlGraphHandle> draft_faces(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoDraftFacesOptions>& options, const Ref<OcctlNodeId>& out_root); // NOLINT
    void defeature_options_init(const Ref<OcctlTopoDefeatureOptions>& opts); // NOLINT
    Ref<OcctlGraphHandle> defeature(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoDefeatureOptions>& options, const Ref<OcctlNodeId>& out_root); // NOLINT
    void offset_features_options_init(const Ref<OcctlTopoOffsetFeaturesOptions>& opts); // NOLINT
    Ref<OcctlGraphHandle> make_offset_features(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoOffsetFeaturesOptions>& options, const Ref<OcctlNodeId>& out_root); // NOLINT
    void filling_options_init(const Ref<OcctlTopoFillingOptions>& opts); // NOLINT
    Ref<OcctlGraphHandle> make_filling(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoFillingOptions>& options, const Ref<OcctlNodeId>& out_root); // NOLINT
    void filling_patch_options_init(const Ref<OcctlTopoFillingPatchOptions>& opts); // NOLINT
    Ref<OcctlGraphHandle> make_filling_patch(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoFillingPatchOptions>& options, const Ref<OcctlNodeId>& out_root); // NOLINT
    void split_by_plane_options_init(const Ref<OcctlTopoSplitByPlaneOptions>& opts); // NOLINT
    Ref<OcctlGraphHandle> make_split_by_plane(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoSplitByPlaneOptions>& options, const Ref<OcctlNodeId>& out_root); // NOLINT
    void section_by_planes_options_init(const Ref<OcctlTopoSectionByPlanesOptions>& opts); // NOLINT
    Ref<OcctlGraphHandle> make_sections_by_planes(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoSectionByPlanesOptions>& options, const Ref<OcctlNodeId>& out_root); // NOLINT
    void extrude_faces_options_init(const Ref<OcctlTopoExtrudeFacesOptions>& opts); // NOLINT
    Ref<OcctlGraphHandle> make_face_extrusion(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoExtrudeFacesOptions>& options, const Ref<OcctlNodeId>& out_root); // NOLINT
    Ref<OcctlGraphHandle> mirrored(const Ref<OcctlGraphHandle>& graph, int64_t root, const Ref<OcctlPoint3>& point, const Ref<OcctlDirection3>& normal, const Ref<OcctlNodeId>& out_root); // NOLINT
    void linear_pattern_options_init(const Ref<OcctlTopoLinearPatternOptions>& opts); // NOLINT
    Ref<OcctlGraphHandle> make_linear_pattern(const Ref<OcctlGraphHandle>& graph, int64_t root, const Ref<OcctlTopoLinearPatternOptions>& opts, const Ref<OcctlNodeId>& out_root); // NOLINT
    void circular_pattern_options_init(const Ref<OcctlTopoCircularPatternOptions>& opts); // NOLINT
    Ref<OcctlGraphHandle> make_circular_pattern(const Ref<OcctlGraphHandle>& graph, int64_t root, const Ref<OcctlTopoCircularPatternOptions>& opts, const Ref<OcctlNodeId>& out_root); // NOLINT
};

#endif // OCCTLTOPOALGO_H
