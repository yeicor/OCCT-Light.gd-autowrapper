#ifndef OCCTLTOPO_H
#define OCCTLTOPO_H

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
#include "occtl/occtl_topo.h"

#include "OcctlByteArray.h"
#include "OcctlCoedgeView.h"
#include "OcctlColorRgba.h"
#include "OcctlCompoundView.h"
#include "OcctlDouble.h"
#include "OcctlEdgeView.h"
#include "OcctlFaceView.h"
#include "OcctlGraphHandle.h"
#include "OcctlInt32.h"
#include "OcctlJointId.h"
#include "OcctlJointInfo.h"
#include "OcctlMaterialInfo.h"
#include "OcctlMetadataKeyView.h"
#include "OcctlNodeId.h"
#include "OcctlNodeIterHandle.h"
#include "OcctlPoint2.h"
#include "OcctlPoint3.h"
#include "OcctlRefId.h"
#include "OcctlRefUid.h"
#include "OcctlRepId.h"
#include "OcctlRepUid.h"
#include "OcctlShellView.h"
#include "OcctlSize.h"
#include "OcctlSolidView.h"
#include "OcctlTagView.h"
#include "OcctlTopoMakeProductInfo.h"
#include "OcctlTransform.h"
#include "OcctlUid.h"
#include "OcctlUint32.h"
#include "OcctlVector2.h"
#include "OcctlVector3.h"
#include "OcctlVertexView.h"
#include "OcctlWireView.h"

using namespace godot;

class OcctlTopo : public godot::RefCounted {
    GDCLASS(OcctlTopo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    Ref<OcctlGraphHandle> graph_create(void); // NOLINT
    void graph_free(const Ref<OcctlGraphHandle>& graph); // NOLINT
    int graph_node_id_from_uid(const Ref<OcctlGraphHandle>& graph, int64_t uid, const Ref<OcctlNodeId>& out_node_id); // NOLINT
    int graph_uid_from_node_id(const Ref<OcctlGraphHandle>& graph, int64_t id, const Ref<OcctlUid>& out_uid); // NOLINT
    PackedInt64Array graph_history_modified(const Ref<OcctlGraphHandle>& graph, int64_t input_uid); // NOLINT
    PackedInt64Array graph_history_generated(const Ref<OcctlGraphHandle>& graph, int64_t input_uid); // NOLINT
    PackedInt64Array graph_history_deleted_all(const Ref<OcctlGraphHandle>& graph); // NOLINT
    int graph_ref_id_from_ref_uid(const Ref<OcctlGraphHandle>& graph, int64_t ref_uid, const Ref<OcctlRefId>& out_ref_id); // NOLINT
    int graph_ref_uid_from_ref_id(const Ref<OcctlGraphHandle>& graph, int64_t ref_id, const Ref<OcctlRefUid>& out_ref_uid); // NOLINT
    int graph_rep_id_from_rep_uid(const Ref<OcctlGraphHandle>& graph, int64_t rep_uid, const Ref<OcctlRepId>& out_rep_id); // NOLINT
    int graph_rep_uid_from_rep_id(const Ref<OcctlGraphHandle>& graph, int64_t rep_id, const Ref<OcctlRepUid>& out_rep_uid); // NOLINT
    int ref_uid_to_bytes(int64_t ref_uid, const Ref<OcctlByteArray>& out_bytes); // NOLINT
    int ref_uid_from_bytes(const PackedByteArray& in_bytes, const Ref<OcctlRefUid>& out_ref_uid); // NOLINT
    int rep_uid_to_bytes(int64_t rep_uid, const Ref<OcctlByteArray>& out_bytes); // NOLINT
    int rep_uid_from_bytes(const PackedByteArray& in_bytes, const Ref<OcctlRepUid>& out_rep_uid); // NOLINT
    Dictionary graph_uid_table(const Ref<OcctlGraphHandle>& graph); // NOLINT
    Dictionary graph_ref_uid_table(const Ref<OcctlGraphHandle>& graph); // NOLINT
    int graph_node_kind(const Ref<OcctlGraphHandle>& graph, int64_t id, const Ref<OcctlInt32>& out_kind); // NOLINT
    int graph_uid_kind(const Ref<OcctlGraphHandle>& graph, int64_t uid, const Ref<OcctlInt32>& out_kind); // NOLINT
    int graph_ref_kind(const Ref<OcctlGraphHandle>& graph, int64_t id, const Ref<OcctlInt32>& out_kind); // NOLINT
    int graph_ref_uid_kind(const Ref<OcctlGraphHandle>& graph, int64_t ref_uid, const Ref<OcctlInt32>& out_kind); // NOLINT
    int graph_rep_kind(const Ref<OcctlGraphHandle>& graph, int64_t id, const Ref<OcctlInt32>& out_kind); // NOLINT
    int graph_solid_count(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSize>& out_count); // NOLINT
    int graph_shell_count(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSize>& out_count); // NOLINT
    int graph_face_count(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSize>& out_count); // NOLINT
    int graph_wire_count(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSize>& out_count); // NOLINT
    int graph_edge_count(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSize>& out_count); // NOLINT
    int graph_vertex_count(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSize>& out_count); // NOLINT
    int graph_compound_count(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSize>& out_count); // NOLINT
    int graph_compsolid_count(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSize>& out_count); // NOLINT
    int graph_coedge_count(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSize>& out_count); // NOLINT
    int graph_product_count(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSize>& out_count); // NOLINT
    int graph_occurrence_count(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSize>& out_count); // NOLINT
    int graph_node_count(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSize>& out_count); // NOLINT
    int topo_vertex_point(const Ref<OcctlGraphHandle>& graph, int64_t vertex, const Ref<OcctlPoint3>& out_point); // NOLINT
    int topo_vertex_tolerance(const Ref<OcctlGraphHandle>& graph, int64_t vertex, const Ref<OcctlDouble>& out_tolerance); // NOLINT
    int topo_vertex_edge_count(const Ref<OcctlGraphHandle>& graph, int64_t vertex, const Ref<OcctlUint32>& out_count); // NOLINT
    int topo_edge_range(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlDouble>& out_first, const Ref<OcctlDouble>& out_last); // NOLINT
    int topo_edge_tolerance(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlDouble>& out_tolerance); // NOLINT
    int topo_edge_is_degenerated(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlInt32>& out_is_degenerated); // NOLINT
    int topo_edge_has_curve(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlInt32>& out_has_curve); // NOLINT
    int topo_edge_curve_kind(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlInt32>& out_kind); // NOLINT
    int topo_edge_start_vertex(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlNodeId>& out_vertex); // NOLINT
    int topo_edge_end_vertex(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlNodeId>& out_vertex); // NOLINT
    int topo_coedge_is_seam(const Ref<OcctlGraphHandle>& graph, int64_t coedge, const Ref<OcctlInt32>& out_is_seam); // NOLINT
    int topo_coedge_edge_of(const Ref<OcctlGraphHandle>& graph, int64_t coedge, const Ref<OcctlNodeId>& out_edge); // NOLINT
    int topo_coedge_face_of(const Ref<OcctlGraphHandle>& graph, int64_t coedge, const Ref<OcctlNodeId>& out_face); // NOLINT
    int topo_face_tolerance(const Ref<OcctlGraphHandle>& graph, int64_t face, const Ref<OcctlDouble>& out_tolerance); // NOLINT
    int topo_face_wire_count(const Ref<OcctlGraphHandle>& graph, int64_t face, const Ref<OcctlUint32>& out_count); // NOLINT
    int topo_face_outer_wire(const Ref<OcctlGraphHandle>& graph, int64_t face, const Ref<OcctlNodeId>& out_wire); // NOLINT
    int topo_face_uv_bounds(const Ref<OcctlGraphHandle>& graph, int64_t face, const Ref<OcctlDouble>& out_umin, const Ref<OcctlDouble>& out_umax, const Ref<OcctlDouble>& out_vmin, const Ref<OcctlDouble>& out_vmax); // NOLINT
    int topo_edge_eval(const Ref<OcctlGraphHandle>& graph, int64_t edge, double u, const Ref<OcctlPoint3>& out_p); // NOLINT
    int topo_edge_eval_d1(const Ref<OcctlGraphHandle>& graph, int64_t edge, double u, const Ref<OcctlPoint3>& out_p, const Ref<OcctlVector3>& out_d1); // NOLINT
    int topo_edge_eval_d2(const Ref<OcctlGraphHandle>& graph, int64_t edge, double u, const Ref<OcctlPoint3>& out_p, const Ref<OcctlVector3>& out_d1, const Ref<OcctlVector3>& out_d2); // NOLINT
    int topo_edge_eval_d3(const Ref<OcctlGraphHandle>& graph, int64_t edge, double u, const Ref<OcctlPoint3>& out_p, const Ref<OcctlVector3>& out_d1, const Ref<OcctlVector3>& out_d2, const Ref<OcctlVector3>& out_d3); // NOLINT
    int topo_edge_eval_dn(const Ref<OcctlGraphHandle>& graph, int64_t edge, double u, int n, const Ref<OcctlVector3>& out_dn); // NOLINT
    int topo_coedge_pcurve_eval(const Ref<OcctlGraphHandle>& graph, int64_t coedge, double u, const Ref<OcctlPoint2>& out_uv); // NOLINT
    int topo_coedge_pcurve_eval_d1(const Ref<OcctlGraphHandle>& graph, int64_t coedge, double u, const Ref<OcctlPoint2>& out_uv, const Ref<OcctlVector2>& out_d1); // NOLINT
    int topo_coedge_pcurve_eval_d2(const Ref<OcctlGraphHandle>& graph, int64_t coedge, double u, const Ref<OcctlPoint2>& out_uv, const Ref<OcctlVector2>& out_d1, const Ref<OcctlVector2>& out_d2); // NOLINT
    int topo_coedge_pcurve_eval_d3(const Ref<OcctlGraphHandle>& graph, int64_t coedge, double u, const Ref<OcctlPoint2>& out_uv, const Ref<OcctlVector2>& out_d1, const Ref<OcctlVector2>& out_d2, const Ref<OcctlVector2>& out_d3); // NOLINT
    int topo_coedge_pcurve_eval_dn(const Ref<OcctlGraphHandle>& graph, int64_t coedge, double u, int n, const Ref<OcctlVector2>& out_dn); // NOLINT
    int topo_face_eval(const Ref<OcctlGraphHandle>& graph, int64_t face, double u, double v, const Ref<OcctlPoint3>& out_p); // NOLINT
    int topo_face_eval_d1(const Ref<OcctlGraphHandle>& graph, int64_t face, double u, double v, const Ref<OcctlPoint3>& out_p, const Ref<OcctlVector3>& out_d1u, const Ref<OcctlVector3>& out_d1v); // NOLINT
    int topo_face_eval_d2(const Ref<OcctlGraphHandle>& graph, int64_t face, double u, double v, const Ref<OcctlPoint3>& out_p, const Ref<OcctlVector3>& out_d1u, const Ref<OcctlVector3>& out_d1v, const Ref<OcctlVector3>& out_d2u, const Ref<OcctlVector3>& out_d2v, const Ref<OcctlVector3>& out_d2uv); // NOLINT
    int topo_face_eval_d3(const Ref<OcctlGraphHandle>& graph, int64_t face, double u, double v, const Ref<OcctlPoint3>& out_p, const Ref<OcctlVector3>& out_d1u, const Ref<OcctlVector3>& out_d1v, const Ref<OcctlVector3>& out_d2u, const Ref<OcctlVector3>& out_d2v, const Ref<OcctlVector3>& out_d2uv, const Ref<OcctlVector3>& out_d3u, const Ref<OcctlVector3>& out_d3v, const Ref<OcctlVector3>& out_d3uuv, const Ref<OcctlVector3>& out_d3uvv); // NOLINT
    int topo_face_eval_dn(const Ref<OcctlGraphHandle>& graph, int64_t face, double u, double v, int nu, int nv, const Ref<OcctlVector3>& out_dn); // NOLINT
    int topo_face_has_surface(const Ref<OcctlGraphHandle>& graph, int64_t face, const Ref<OcctlInt32>& out_has_surface); // NOLINT
    int topo_face_surface_kind(const Ref<OcctlGraphHandle>& graph, int64_t face, const Ref<OcctlInt32>& out_kind); // NOLINT
    int topo_wire_is_closed(const Ref<OcctlGraphHandle>& graph, int64_t wire, const Ref<OcctlInt32>& out_is_closed); // NOLINT
    int topo_wire_coedge_count(const Ref<OcctlGraphHandle>& graph, int64_t wire, const Ref<OcctlUint32>& out_count); // NOLINT
    int topo_shell_is_closed(const Ref<OcctlGraphHandle>& graph, int64_t shell, const Ref<OcctlInt32>& out_is_closed); // NOLINT
    int topo_shell_face_count(const Ref<OcctlGraphHandle>& graph, int64_t shell, const Ref<OcctlUint32>& out_count); // NOLINT
    int topo_vertex_parameter(const Ref<OcctlGraphHandle>& graph, int64_t vertex, int64_t edge, const Ref<OcctlDouble>& out_parameter); // NOLINT
    int topo_vertex_parameters(const Ref<OcctlGraphHandle>& graph, int64_t vertex, int64_t face, const Ref<OcctlPoint2>& out_uv); // NOLINT
    int topo_edge_same_parameter(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlInt32>& out_has_same_parameter); // NOLINT
    int topo_edge_same_range(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlInt32>& out_has_same_range); // NOLINT
    int topo_edge_is_manifold(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlInt32>& out_is_manifold); // NOLINT
    int topo_edge_is_boundary(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlInt32>& out_is_boundary); // NOLINT
    int topo_edge_is_seam_on_face(const Ref<OcctlGraphHandle>& graph, int64_t edge, int64_t face, const Ref<OcctlInt32>& out_is_seam); // NOLINT
    int topo_edge_face_count(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlUint32>& out_count); // NOLINT
    int topo_coedge_is_reversed(const Ref<OcctlGraphHandle>& graph, int64_t coedge, const Ref<OcctlInt32>& out_is_reversed); // NOLINT
    int topo_coedge_has_pcurve(const Ref<OcctlGraphHandle>& graph, int64_t coedge, const Ref<OcctlInt32>& out_has_pcurve); // NOLINT
    int topo_coedge_pcurve_parameter(const Ref<OcctlGraphHandle>& graph, int64_t coedge, int64_t vertex, const Ref<OcctlDouble>& out_parameter); // NOLINT
    int topo_coedge_range(const Ref<OcctlGraphHandle>& graph, int64_t coedge, const Ref<OcctlDouble>& out_first, const Ref<OcctlDouble>& out_last); // NOLINT
    int topo_coedge_uv_points(const Ref<OcctlGraphHandle>& graph, int64_t coedge, const Ref<OcctlPoint2>& out_uv_start, const Ref<OcctlPoint2>& out_uv_end); // NOLINT
    int topo_coedge_seam_pair(const Ref<OcctlGraphHandle>& graph, int64_t coedge, const Ref<OcctlNodeId>& out_pair); // NOLINT
    int topo_face_natural_restriction(const Ref<OcctlGraphHandle>& graph, int64_t face, const Ref<OcctlInt32>& out_has_natural_restriction); // NOLINT
    int topo_face_has_triangulation(const Ref<OcctlGraphHandle>& graph, int64_t face, const Ref<OcctlInt32>& out_has_triangulation); // NOLINT
    int topo_wire_distinct_edge_count(const Ref<OcctlGraphHandle>& graph, int64_t wire, const Ref<OcctlUint32>& out_count); // NOLINT
    int topo_wire_face_of(const Ref<OcctlGraphHandle>& graph, int64_t wire, const Ref<OcctlNodeId>& out_face); // NOLINT
    int topo_wire_is_outer(const Ref<OcctlGraphHandle>& graph, int64_t wire, const Ref<OcctlInt32>& out_is_outer); // NOLINT
    int topo_solid_shell_count(const Ref<OcctlGraphHandle>& graph, int64_t solid, const Ref<OcctlUint32>& out_count); // NOLINT
    int topo_wire_edge_count(const Ref<OcctlGraphHandle>& graph, int64_t wire, const Ref<OcctlUint32>& out_count); // NOLINT
    int topo_edge_vertex_count(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlUint32>& out_count); // NOLINT
    int topo_compound_child_count(const Ref<OcctlGraphHandle>& graph, int64_t compound, const Ref<OcctlUint32>& out_count); // NOLINT
    int topo_compsolid_solid_count(const Ref<OcctlGraphHandle>& graph, int64_t compsolid, const Ref<OcctlUint32>& out_count); // NOLINT
    int topo_product_occurrence_count(const Ref<OcctlGraphHandle>& graph, int64_t product, const Ref<OcctlUint32>& out_count); // NOLINT
    int node_iter_next(const Ref<OcctlNodeIterHandle>& iter, const Ref<OcctlNodeId>& out_id); // NOLINT
    void node_iter_free(const Ref<OcctlNodeIterHandle>& iter); // NOLINT
    Ref<OcctlNodeIterHandle> graph_solid_iter_create(const Ref<OcctlGraphHandle>& graph); // NOLINT
    Ref<OcctlNodeIterHandle> graph_shell_iter_create(const Ref<OcctlGraphHandle>& graph); // NOLINT
    Ref<OcctlNodeIterHandle> graph_face_iter_create(const Ref<OcctlGraphHandle>& graph); // NOLINT
    Ref<OcctlNodeIterHandle> graph_wire_iter_create(const Ref<OcctlGraphHandle>& graph); // NOLINT
    Ref<OcctlNodeIterHandle> graph_edge_iter_create(const Ref<OcctlGraphHandle>& graph); // NOLINT
    Ref<OcctlNodeIterHandle> graph_vertex_iter_create(const Ref<OcctlGraphHandle>& graph); // NOLINT
    Ref<OcctlNodeIterHandle> graph_compound_iter_create(const Ref<OcctlGraphHandle>& graph); // NOLINT
    Ref<OcctlNodeIterHandle> graph_compsolid_iter_create(const Ref<OcctlGraphHandle>& graph); // NOLINT
    Ref<OcctlNodeIterHandle> graph_coedge_iter_create(const Ref<OcctlGraphHandle>& graph); // NOLINT
    Ref<OcctlNodeIterHandle> graph_product_iter_create(const Ref<OcctlGraphHandle>& graph); // NOLINT
    Ref<OcctlNodeIterHandle> graph_occurrence_iter_create(const Ref<OcctlGraphHandle>& graph); // NOLINT
    Ref<OcctlNodeIterHandle> graph_root_product_iter_create(const Ref<OcctlGraphHandle>& graph); // NOLINT
    Ref<OcctlNodeIterHandle> topo_shells_of_solid_iter_create(const Ref<OcctlGraphHandle>& graph, int64_t solid); // NOLINT
    Ref<OcctlNodeIterHandle> topo_faces_of_shell_iter_create(const Ref<OcctlGraphHandle>& graph, int64_t shell); // NOLINT
    Ref<OcctlNodeIterHandle> topo_wires_of_face_iter_create(const Ref<OcctlGraphHandle>& graph, int64_t face); // NOLINT
    Ref<OcctlNodeIterHandle> topo_coedges_of_wire_iter_create(const Ref<OcctlGraphHandle>& graph, int64_t wire); // NOLINT
    Ref<OcctlNodeIterHandle> topo_edges_of_wire_iter_create(const Ref<OcctlGraphHandle>& graph, int64_t wire); // NOLINT
    Ref<OcctlNodeIterHandle> topo_wire_explorer_create(const Ref<OcctlGraphHandle>& graph, int64_t wire); // NOLINT
    Ref<OcctlNodeIterHandle> topo_occurrences_of_product_iter_create(const Ref<OcctlGraphHandle>& graph, int64_t product); // NOLINT
    Ref<OcctlNodeIterHandle> topo_vertices_of_edge_iter_create(const Ref<OcctlGraphHandle>& graph, int64_t edge); // NOLINT
    int graph_for_each(const Ref<OcctlGraphHandle>& graph, int64_t kind_mask, const Callable& callable); // NOLINT
    int graph_for_each_ref(const Ref<OcctlGraphHandle>& graph, int64_t ref_kind_mask, const Callable& callable); // NOLINT
    int graph_for_each_rep(const Ref<OcctlGraphHandle>& graph, int64_t rep_kind_mask, const Callable& callable); // NOLINT
    int topo_for_each_related(const Ref<OcctlGraphHandle>& graph, int64_t node, const Callable& callable); // NOLINT
    int graph_color_set(const Ref<OcctlGraphHandle>& graph, int64_t target, const Ref<OcctlColorRgba>& color); // NOLINT
    int graph_color_get(const Ref<OcctlGraphHandle>& graph, int64_t target, const Ref<OcctlColorRgba>& out_color); // NOLINT
    Dictionary graph_color_entries(const Ref<OcctlGraphHandle>& graph); // NOLINT
    int graph_color_unset(const Ref<OcctlGraphHandle>& graph, int64_t target); // NOLINT
    int graph_name_set(const Ref<OcctlGraphHandle>& graph, int64_t target, const String& name); // NOLINT
    String graph_name_get(const Ref<OcctlGraphHandle>& graph, int64_t target); // NOLINT
    PackedInt64Array graph_name_nodes(const Ref<OcctlGraphHandle>& graph); // NOLINT
    int graph_material_set(const Ref<OcctlGraphHandle>& graph, int64_t target, const Ref<OcctlMaterialInfo>& info); // NOLINT
    String graph_material_get(const Ref<OcctlGraphHandle>& graph, int64_t target, const Ref<OcctlMaterialInfo>& out_info); // NOLINT
    PackedInt64Array graph_material_nodes(const Ref<OcctlGraphHandle>& graph); // NOLINT
    int graph_material_unset(const Ref<OcctlGraphHandle>& graph, int64_t target); // NOLINT
    int graph_units_set(const Ref<OcctlGraphHandle>& graph, double length_unit_to_meter, const String& name); // NOLINT
    String graph_units_get(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlDouble>& out_length_unit_to_meter); // NOLINT
    int graph_node_metadata_set(const Ref<OcctlGraphHandle>& graph, int64_t target, const String& key, const String& value); // NOLINT
    String graph_node_metadata_get(const Ref<OcctlGraphHandle>& graph, int64_t target, const String& key); // NOLINT
    Array graph_node_metadata_keys(const Ref<OcctlGraphHandle>& graph, int64_t target); // NOLINT
    PackedInt64Array graph_node_metadata_nodes(const Ref<OcctlGraphHandle>& graph); // NOLINT
    int graph_metadata_set(const Ref<OcctlGraphHandle>& graph, const String& key, const String& value); // NOLINT
    String graph_metadata_get(const Ref<OcctlGraphHandle>& graph, const String& key); // NOLINT
    Array graph_metadata_keys(const Ref<OcctlGraphHandle>& graph); // NOLINT
    int graph_metadata_unset(const Ref<OcctlGraphHandle>& graph, const String& key); // NOLINT
    int graph_node_metadata_unset(const Ref<OcctlGraphHandle>& graph, int64_t target, const String& key); // NOLINT
    int graph_tag_add(const Ref<OcctlGraphHandle>& graph, int64_t target, const String& tag); // NOLINT
    int graph_tag_remove(const Ref<OcctlGraphHandle>& graph, int64_t target, const String& tag); // NOLINT
    int graph_tag_has(const Ref<OcctlGraphHandle>& graph, int64_t target, const String& tag, const Ref<OcctlInt32>& out_has_tag); // NOLINT
    Array graph_tag_list(const Ref<OcctlGraphHandle>& graph, int64_t target); // NOLINT
    PackedInt64Array graph_tag_nodes(const Ref<OcctlGraphHandle>& graph, const String& tag); // NOLINT
    void joint_info_init(const Ref<OcctlJointInfo>& info); // NOLINT
    int joint_create(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlJointInfo>& info, const Ref<OcctlJointId>& out_joint); // NOLINT
    int joint_get(const Ref<OcctlGraphHandle>& graph, int64_t joint, const Ref<OcctlJointInfo>& out_info); // NOLINT
    int joint_remove(const Ref<OcctlGraphHandle>& graph, int64_t joint); // NOLINT
    PackedInt64Array joint_list(const Ref<OcctlGraphHandle>& graph, int64_t node); // NOLINT
    void topo_make_product_info_init(const Ref<OcctlTopoMakeProductInfo>& info); // NOLINT
    int topo_make_product(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoMakeProductInfo>& info, const Ref<OcctlNodeId>& out_product); // NOLINT
    int topo_link_product(const Ref<OcctlGraphHandle>& graph, int64_t product, int64_t root, const Ref<OcctlTransform>& placement); // NOLINT
    int topo_link_product_occurrence(const Ref<OcctlGraphHandle>& graph, int64_t product, int64_t root, const Ref<OcctlTransform>& placement, const Ref<OcctlNodeId>& out_occurrence); // NOLINT
    int topo_link_products(const Ref<OcctlGraphHandle>& graph, int64_t parentProduct, int64_t childProduct, const Ref<OcctlTransform>& placement, int64_t parentOccurrence); // NOLINT
    int topo_link_products_occurrence(const Ref<OcctlGraphHandle>& graph, int64_t parentProduct, int64_t childProduct, const Ref<OcctlTransform>& placement, int64_t parentOccurrence, const Ref<OcctlNodeId>& out_occurrence); // NOLINT
    int topo_remove_occurrence(const Ref<OcctlGraphHandle>& graph, int64_t occurrence_ref); // NOLINT
    int topo_occurrence_set_transform(const Ref<OcctlGraphHandle>& graph, int64_t occurrence, const Ref<OcctlTransform>& transform); // NOLINT
    int topo_occurrence_transform(const Ref<OcctlGraphHandle>& graph, int64_t occurrence, const Ref<OcctlTransform>& out_transform); // NOLINT
    int topo_occurrence_world_transform(const Ref<OcctlGraphHandle>& graph, int64_t root, int64_t occurrence, const Ref<OcctlTransform>& out_transform); // NOLINT
    void edge_view_init(const Ref<OcctlEdgeView>& view); // NOLINT
    int topo_edge_view(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlEdgeView>& view); // NOLINT
    void coedge_view_init(const Ref<OcctlCoedgeView>& view); // NOLINT
    int topo_coedge_view(const Ref<OcctlGraphHandle>& graph, int64_t coedge, const Ref<OcctlCoedgeView>& view); // NOLINT
    void face_view_init(const Ref<OcctlFaceView>& view); // NOLINT
    int topo_face_view(const Ref<OcctlGraphHandle>& graph, int64_t face, const Ref<OcctlFaceView>& view); // NOLINT
    void vertex_view_init(const Ref<OcctlVertexView>& view); // NOLINT
    int topo_vertex_view(const Ref<OcctlGraphHandle>& graph, int64_t vertex, const Ref<OcctlVertexView>& view); // NOLINT
    void wire_view_init(const Ref<OcctlWireView>& view); // NOLINT
    int topo_wire_view(const Ref<OcctlGraphHandle>& graph, int64_t wire, const Ref<OcctlWireView>& view); // NOLINT
    void shell_view_init(const Ref<OcctlShellView>& view); // NOLINT
    int topo_shell_view(const Ref<OcctlGraphHandle>& graph, int64_t shell, const Ref<OcctlShellView>& view); // NOLINT
    void solid_view_init(const Ref<OcctlSolidView>& view); // NOLINT
    int topo_solid_view(const Ref<OcctlGraphHandle>& graph, int64_t solid, const Ref<OcctlSolidView>& view); // NOLINT
    void compound_view_init(const Ref<OcctlCompoundView>& view); // NOLINT
    int topo_compound_view(const Ref<OcctlGraphHandle>& graph, int64_t compound, const Ref<OcctlCompoundView>& view); // NOLINT
};

#endif // OCCTLTOPO_H
