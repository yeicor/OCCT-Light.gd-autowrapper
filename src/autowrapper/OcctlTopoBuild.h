#ifndef OCCTLTOPOBUILD_H
#define OCCTLTOPOBUILD_H

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
#include "occtl/occtl_topo_build.h"

#include "OcctlDouble.h"
#include "OcctlGraphHandle.h"
#include "OcctlGraphMassProperties.h"
#include "OcctlGraphObb.h"
#include "OcctlGraphUvBounds.h"
#include "OcctlInt32.h"
#include "OcctlNodeId.h"
#include "OcctlPoint2.h"
#include "OcctlPoint3.h"
#include "OcctlSelectBbox.h"
#include "OcctlSelectGroupIterHandle.h"
#include "OcctlSelectGroupOptions.h"
#include "OcctlSelectGroupView.h"
#include "OcctlSelectIterHandle.h"
#include "OcctlSelectOptions.h"
#include "OcctlSize.h"
#include "OcctlTopoEdgesToWiresOptions.h"
#include "OcctlTopoFaceChamfer2dOptions.h"
#include "OcctlTopoMakeCompoundInfo.h"
#include "OcctlTopoMakeCompsolidInfo.h"
#include "OcctlTopoMakeEdgeInfo.h"
#include "OcctlTopoMakeFaceFromWiresAutoOptions.h"
#include "OcctlTopoMakeFaceInfo.h"
#include "OcctlTopoMakeShellInfo.h"
#include "OcctlTopoMakeSolidInfo.h"
#include "OcctlTopoMakeVertexInfo.h"
#include "OcctlTopoMakeWireInfo.h"
#include "OcctlTopoWireChamfer2dOptions.h"
#include "OcctlTopoWireFixDegenerateEdgesOptions.h"
#include "OcctlTopoWireOffset2dOptions.h"
#include "OcctlTransform.h"
#include "OcctlVector3.h"

using namespace godot;

class OcctlTopoBuild : public godot::RefCounted {
    GDCLASS(OcctlTopoBuild, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    void topo_make_vertex_info_init(const Ref<OcctlTopoMakeVertexInfo>& info); // NOLINT
    void topo_make_edge_info_init(const Ref<OcctlTopoMakeEdgeInfo>& info); // NOLINT
    void topo_make_wire_info_init(const Ref<OcctlTopoMakeWireInfo>& info); // NOLINT
    void topo_edges_to_wires_options_init(const Ref<OcctlTopoEdgesToWiresOptions>& options); // NOLINT
    void topo_wire_offset_2d_options_init(const Ref<OcctlTopoWireOffset2dOptions>& options); // NOLINT
    void topo_wire_fix_degenerate_options_init(const Ref<OcctlTopoWireFixDegenerateEdgesOptions>& options); // NOLINT
    void topo_face_chamfer_2d_options_init(const Ref<OcctlTopoFaceChamfer2dOptions>& options); // NOLINT
    void topo_wire_chamfer_2d_options_init(const Ref<OcctlTopoWireChamfer2dOptions>& options); // NOLINT
    void topo_make_face_info_init(const Ref<OcctlTopoMakeFaceInfo>& info); // NOLINT
    void topo_make_face_from_wires_auto_options_init(const Ref<OcctlTopoMakeFaceFromWiresAutoOptions>& options); // NOLINT
    void topo_make_shell_info_init(const Ref<OcctlTopoMakeShellInfo>& info); // NOLINT
    void topo_make_solid_info_init(const Ref<OcctlTopoMakeSolidInfo>& info); // NOLINT
    void topo_make_compound_info_init(const Ref<OcctlTopoMakeCompoundInfo>& info); // NOLINT
    int topo_make_vertex(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoMakeVertexInfo>& info, const Ref<OcctlNodeId>& out_vertex); // NOLINT
    int topo_make_edge(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoMakeEdgeInfo>& info, const Ref<OcctlNodeId>& out_edge); // NOLINT
    int topo_make_wire(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoMakeWireInfo>& info, const Ref<OcctlNodeId>& out_wire); // NOLINT
    PackedInt64Array topo_edges_to_wires(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoEdgesToWiresOptions>& options); // NOLINT
    int topo_wire_offset_2d(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoWireOffset2dOptions>& options, const Ref<OcctlNodeId>& out_wire); // NOLINT
    int topo_curves_to_wire(const Ref<OcctlGraphHandle>& graph, const PackedInt64Array& curve_ids, const Ref<OcctlNodeId>& out_wire); // NOLINT
    int topo_wire_fix_degenerate(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoWireFixDegenerateEdgesOptions>& options, const Ref<OcctlSize>& out_removed); // NOLINT
    int topo_face_chamfer_2d(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoFaceChamfer2dOptions>& options, const Ref<OcctlNodeId>& out_face); // NOLINT
    int topo_wire_chamfer_2d(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoWireChamfer2dOptions>& options, const Ref<OcctlNodeId>& out_wire); // NOLINT
    int topo_make_face(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoMakeFaceInfo>& info, const Ref<OcctlNodeId>& out_face); // NOLINT
    int topo_make_face_from_wires_auto(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoMakeFaceFromWiresAutoOptions>& options, const Ref<OcctlNodeId>& out_face); // NOLINT
    int topo_make_shell(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoMakeShellInfo>& info, const Ref<OcctlNodeId>& out_shell); // NOLINT
    int topo_make_solid(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoMakeSolidInfo>& info, const Ref<OcctlNodeId>& out_solid); // NOLINT
    int topo_make_compound(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoMakeCompoundInfo>& info, const Ref<OcctlNodeId>& out_compound); // NOLINT
    void topo_make_compsolid_info_init(const Ref<OcctlTopoMakeCompsolidInfo>& info); // NOLINT
    int topo_make_compsolid(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoMakeCompsolidInfo>& info, const Ref<OcctlNodeId>& out_compsolid); // NOLINT
    int topo_remove(const Ref<OcctlGraphHandle>& graph, int64_t id); // NOLINT
    int topo_remove_subgraph(const Ref<OcctlGraphHandle>& graph, int64_t id); // NOLINT
    int graph_begin_batch(const Ref<OcctlGraphHandle>& graph); // NOLINT
    int batch_commit(int64_t batch); // NOLINT
    int batch_abort(int64_t batch); // NOLINT
    int topo_replace_edge_curve(const Ref<OcctlGraphHandle>& graph, int64_t edge, int64_t curve_id); // NOLINT
    int topo_replace_face_surface(const Ref<OcctlGraphHandle>& graph, int64_t face, int64_t surface_id); // NOLINT
    int topo_replace_coedge_pcurve(const Ref<OcctlGraphHandle>& graph, int64_t coedge, int64_t pcurve_id); // NOLINT
    int topo_add_pcurve(const Ref<OcctlGraphHandle>& graph, int64_t edge, int64_t face, int64_t pcurve_id, double first, double last, int orientation); // NOLINT
    int topo_shell_add_face(const Ref<OcctlGraphHandle>& graph, int64_t shell, int64_t face, int orientation); // NOLINT
    int topo_shell_remove_face(const Ref<OcctlGraphHandle>& graph, int64_t shell, int64_t face); // NOLINT
    int topo_face_add_holes(const Ref<OcctlGraphHandle>& graph, int64_t face, const PackedInt64Array& holes); // NOLINT
    int topo_face_remove_holes(const Ref<OcctlGraphHandle>& graph, int64_t face, const PackedInt64Array& holes); // NOLINT
    int topo_solid_add_shell(const Ref<OcctlGraphHandle>& graph, int64_t solid, int64_t shell, int orientation); // NOLINT
    int topo_solid_remove_shell(const Ref<OcctlGraphHandle>& graph, int64_t solid, int64_t shell); // NOLINT
    int topo_compound_add_child(const Ref<OcctlGraphHandle>& graph, int64_t compound, int64_t child, int orientation); // NOLINT
    int topo_compound_remove_child(const Ref<OcctlGraphHandle>& graph, int64_t compound, int64_t child); // NOLINT
    int topo_edge_split(const Ref<OcctlGraphHandle>& graph, int64_t edge, double parameter, const Ref<OcctlNodeId>& out_edge1, const Ref<OcctlNodeId>& out_edge2); // NOLINT
    int topo_edge_add_internal_vertex(const Ref<OcctlGraphHandle>& graph, int64_t edge, int64_t vertex); // NOLINT
    int topo_edge_remove_vertex(const Ref<OcctlGraphHandle>& graph, int64_t edge, int64_t vertex); // NOLINT
    int topo_edge_continuity(const Ref<OcctlGraphHandle>& graph, int64_t edge, int64_t faceA, int64_t faceB, const Ref<OcctlInt32>& out_continuity); // NOLINT
    int topo_edge_has_continuity(const Ref<OcctlGraphHandle>& graph, int64_t edge, int64_t faceA, int64_t faceB, const Ref<OcctlInt32>& out_has_continuity); // NOLINT
    int topo_edge_max_continuity(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlInt32>& out_continuity); // NOLINT
    int topo_coedge_orientation(const Ref<OcctlGraphHandle>& graph, int64_t coedge, const Ref<OcctlInt32>& out_orientation); // NOLINT
    int topo_edge_find_coedge_on_face(const Ref<OcctlGraphHandle>& graph, int64_t edge, int64_t face, const Ref<OcctlNodeId>& out_coedge); // NOLINT
    int topo_edge_find_coedge_on_face_oriented(const Ref<OcctlGraphHandle>& graph, int64_t edge, int64_t face, int orientation, const Ref<OcctlNodeId>& out_coedge); // NOLINT
    int topo_vertex_point_in_usage(const Ref<OcctlGraphHandle>& graph, int64_t vertex, int64_t parent, const Ref<OcctlPoint3>& out_point); // NOLINT
    int topo_vertex_pcurve_parameter(const Ref<OcctlGraphHandle>& graph, int64_t vertex, int64_t coedge, const Ref<OcctlDouble>& out_u); // NOLINT
    int topo_edge_has_polygon3d(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlInt32>& out_has_polygon3d); // NOLINT
    int topo_coedge_has_polygon_on_surface(const Ref<OcctlGraphHandle>& graph, int64_t coedge, const Ref<OcctlInt32>& out_has_polygon_on_surface); // NOLINT
    int topo_face_uv_bounds_restricted(const Ref<OcctlGraphHandle>& graph, int64_t face, double umin, double umax, double vmin, double vmax, double u, double v, const Ref<OcctlPoint3>& out_point, const Ref<OcctlVector3>& out_d1u, const Ref<OcctlVector3>& out_d1v); // NOLINT
    int topo_set_vertex_point(const Ref<OcctlGraphHandle>& graph, int64_t vertex, const Ref<OcctlPoint3>& point); // NOLINT
    int topo_set_vertex_tolerance(const Ref<OcctlGraphHandle>& graph, int64_t vertex, double tol); // NOLINT
    int topo_set_edge_tolerance(const Ref<OcctlGraphHandle>& graph, int64_t edge, double tol); // NOLINT
    int topo_set_face_tolerance(const Ref<OcctlGraphHandle>& graph, int64_t face, double tol); // NOLINT
    int topo_set_edge_param_range(const Ref<OcctlGraphHandle>& graph, int64_t edge, double first, double last); // NOLINT
    int topo_set_edge_same_parameter(const Ref<OcctlGraphHandle>& graph, int64_t edge, int flag); // NOLINT
    int topo_set_edge_same_range(const Ref<OcctlGraphHandle>& graph, int64_t edge, int flag); // NOLINT
    int topo_set_edge_is_degenerate(const Ref<OcctlGraphHandle>& graph, int64_t edge, int flag); // NOLINT
    int topo_set_edge_is_closed(const Ref<OcctlGraphHandle>& graph, int64_t edge, int flag); // NOLINT
    int topo_set_wire_is_closed(const Ref<OcctlGraphHandle>& graph, int64_t wire, int flag); // NOLINT
    int topo_set_shell_is_closed(const Ref<OcctlGraphHandle>& graph, int64_t shell, int flag); // NOLINT
    int topo_set_face_natural_restriction(const Ref<OcctlGraphHandle>& graph, int64_t face, int flag); // NOLINT
    int topo_set_coedge_param_range(const Ref<OcctlGraphHandle>& graph, int64_t coedge, double first, double last); // NOLINT
    int topo_set_coedge_uv_box(const Ref<OcctlGraphHandle>& graph, int64_t coedge, const Ref<OcctlPoint2>& uv_lo, const Ref<OcctlPoint2>& uv_hi); // NOLINT
    int graph_clear_cached(const Ref<OcctlGraphHandle>& graph, int64_t node, int64_t ref); // NOLINT
    void select_options_init(const Ref<OcctlSelectOptions>& options); // NOLINT
    void select_group_options_init(const Ref<OcctlSelectGroupOptions>& options); // NOLINT
    void select_group_view_init(const Ref<OcctlSelectGroupView>& view); // NOLINT
    int graph_bbox_get(const Ref<OcctlGraphHandle>& graph, int64_t node, const Ref<OcctlSelectBbox>& out_bbox); // NOLINT
    int graph_obb_get(const Ref<OcctlGraphHandle>& graph, int64_t node, const Ref<OcctlGraphObb>& out_obb); // NOLINT
    int graph_face_uv_bounds_get(const Ref<OcctlGraphHandle>& graph, int64_t face, const Ref<OcctlGraphUvBounds>& out_uv_bounds); // NOLINT
    int graph_measure_get(const Ref<OcctlGraphHandle>& graph, int64_t node, int kind, const Ref<OcctlDouble>& out_value); // NOLINT
    int graph_mass_properties_get(const Ref<OcctlGraphHandle>& graph, int64_t node, const Ref<OcctlGraphMassProperties>& out_properties); // NOLINT
    int graph_edge_curve_kind_get(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlInt32>& out_kind); // NOLINT
    int graph_face_surface_kind_get(const Ref<OcctlGraphHandle>& graph, int64_t face, const Ref<OcctlInt32>& out_kind); // NOLINT
    PackedInt64Array graph_descendant_vertices_get(const Ref<OcctlGraphHandle>& graph, int64_t node); // NOLINT
    PackedInt64Array graph_descendant_edges_get(const Ref<OcctlGraphHandle>& graph, int64_t node); // NOLINT
    PackedInt64Array graph_descendant_faces_get(const Ref<OcctlGraphHandle>& graph, int64_t node); // NOLINT
    PackedInt64Array graph_descendants_get(const Ref<OcctlGraphHandle>& graph, int64_t node, int descendant_kind); // NOLINT
    PackedInt64Array graph_adjacent_faces_get(const Ref<OcctlGraphHandle>& graph, int64_t face); // NOLINT
    PackedInt64Array graph_adjacent_edges_get(const Ref<OcctlGraphHandle>& graph, int64_t edge); // NOLINT
    int graph_pair_distance_get(const Ref<OcctlGraphHandle>& graph, int64_t first, int64_t second, const Ref<OcctlDouble>& out_distance); // NOLINT
    Ref<OcctlSelectIterHandle> select_iter_create(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSelectOptions>& options); // NOLINT
    Ref<OcctlSelectIterHandle> select_tagged_iter_create(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSelectOptions>& options, const String& tag); // NOLINT
    int select_iter_next(const Ref<OcctlSelectIterHandle>& iter, const Ref<OcctlNodeId>& out_node); // NOLINT
    void select_iter_free(const Ref<OcctlSelectIterHandle>& iter); // NOLINT
    Ref<OcctlSelectGroupIterHandle> select_group_iter_create(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSelectOptions>& select_options, const Ref<OcctlSelectGroupOptions>& group_options); // NOLINT
    int select_group_iter_next(const Ref<OcctlSelectGroupIterHandle>& iter, const Ref<OcctlSelectGroupView>& out_view); // NOLINT
    void select_group_iter_free(const Ref<OcctlSelectGroupIterHandle>& iter); // NOLINT
    Ref<OcctlGraphHandle> graph_clone(const Ref<OcctlGraphHandle>& source); // NOLINT
    int graph_compact(const Ref<OcctlGraphHandle>& graph); // NOLINT
    int topo_remove_with_replacement(const Ref<OcctlGraphHandle>& graph, int64_t node, int64_t replacement); // NOLINT
    int topo_remove_ref(const Ref<OcctlGraphHandle>& graph, int64_t ref_id); // NOLINT
    int topo_remove_rep(const Ref<OcctlGraphHandle>& graph, int64_t rep_id); // NOLINT
    int topo_cleanup_removed_refs(const Ref<OcctlGraphHandle>& graph); // NOLINT
    int topo_set_edge_start_vertex(const Ref<OcctlGraphHandle>& graph, int64_t edge, int64_t vertex); // NOLINT
    int topo_set_edge_end_vertex(const Ref<OcctlGraphHandle>& graph, int64_t edge, int64_t vertex); // NOLINT
    int topo_set_ref_orientation(const Ref<OcctlGraphHandle>& graph, int64_t ref_id, int orientation); // NOLINT
    int topo_set_ref_location(const Ref<OcctlGraphHandle>& graph, int64_t ref_id, const Ref<OcctlTransform>& transform); // NOLINT
    int topo_set_wire_ref_is_outer(const Ref<OcctlGraphHandle>& graph, int64_t ref_id, int flag); // NOLINT
};

#endif // OCCTLTOPOBUILD_H
