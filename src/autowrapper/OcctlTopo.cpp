#include "OcctlTopo.h"

#include "occtl/occtl_topo.h"

#include <vector>

namespace {
struct _CallbackContext {
    Callable callable;
};

OCCTL_CALL occtl_status_t _occtl_node_visitor_bridge(occtl_node_id_t node, void* user_data) {
    auto* ctx = static_cast<_CallbackContext*>(user_data);
    Variant _result = ctx->callable.call(static_cast<int64_t>(node.bits));
    return static_cast<occtl_status_t>(static_cast<int64_t>(_result));
}
OCCTL_CALL occtl_status_t _occtl_ref_visitor_bridge(occtl_ref_id_t ref, void* user_data) {
    auto* ctx = static_cast<_CallbackContext*>(user_data);
    Variant _result = ctx->callable.call(static_cast<int64_t>(ref.bits));
    return static_cast<occtl_status_t>(static_cast<int64_t>(_result));
}
OCCTL_CALL occtl_status_t _occtl_rep_visitor_bridge(occtl_rep_id_t rep, void* user_data) {
    auto* ctx = static_cast<_CallbackContext*>(user_data);
    Variant _result = ctx->callable.call(static_cast<int64_t>(rep.bits));
    return static_cast<occtl_status_t>(static_cast<int64_t>(_result));
}
} // namespace

void OcctlTopo::_bind_methods() {
    BIND_CONSTANT(OCCTL_TOPO_MAKE_PRODUCT_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_EDGE_VIEW_VERSION_1);
    BIND_CONSTANT(OCCTL_COEDGE_VIEW_VERSION_1);
    BIND_CONSTANT(OCCTL_FACE_VIEW_VERSION_1);
    BIND_CONSTANT(OCCTL_VERTEX_VIEW_VERSION_1);
    BIND_CONSTANT(OCCTL_WIRE_VIEW_VERSION_1);
    BIND_CONSTANT(OCCTL_SHELL_VIEW_VERSION_1);
    BIND_CONSTANT(OCCTL_SOLID_VIEW_VERSION_1);
    BIND_CONSTANT(OCCTL_COMPOUND_VIEW_VERSION_1);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_create"), &OcctlTopo::graph_create);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_free", "graph"), &OcctlTopo::graph_free);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_node_id_from_uid", "graph", "uid", "out_node_id"), &OcctlTopo::graph_node_id_from_uid);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_uid_from_node_id", "graph", "id", "out_uid"), &OcctlTopo::graph_uid_from_node_id);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_history_modified", "graph", "input_uid"), &OcctlTopo::graph_history_modified);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_history_generated", "graph", "input_uid"), &OcctlTopo::graph_history_generated);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_history_deleted_all", "graph"), &OcctlTopo::graph_history_deleted_all);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_ref_id_from_ref_uid", "graph", "ref_uid", "out_ref_id"), &OcctlTopo::graph_ref_id_from_ref_uid);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_ref_uid_from_ref_id", "graph", "ref_id", "out_ref_uid"), &OcctlTopo::graph_ref_uid_from_ref_id);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_rep_id_from_rep_uid", "graph", "rep_uid", "out_rep_id"), &OcctlTopo::graph_rep_id_from_rep_uid);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_rep_uid_from_rep_id", "graph", "rep_id", "out_rep_uid"), &OcctlTopo::graph_rep_uid_from_rep_id);
    godot::ClassDB::bind_method(godot::D_METHOD("ref_uid_to_bytes", "ref_uid", "out_bytes"), &OcctlTopo::ref_uid_to_bytes);
    godot::ClassDB::bind_method(godot::D_METHOD("ref_uid_from_bytes", "in_bytes", "out_ref_uid"), &OcctlTopo::ref_uid_from_bytes);
    godot::ClassDB::bind_method(godot::D_METHOD("rep_uid_to_bytes", "rep_uid", "out_bytes"), &OcctlTopo::rep_uid_to_bytes);
    godot::ClassDB::bind_method(godot::D_METHOD("rep_uid_from_bytes", "in_bytes", "out_rep_uid"), &OcctlTopo::rep_uid_from_bytes);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_uid_table", "graph"), &OcctlTopo::graph_uid_table);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_ref_uid_table", "graph"), &OcctlTopo::graph_ref_uid_table);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_node_kind", "graph", "id", "out_kind"), &OcctlTopo::graph_node_kind);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_uid_kind", "graph", "uid", "out_kind"), &OcctlTopo::graph_uid_kind);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_ref_kind", "graph", "id", "out_kind"), &OcctlTopo::graph_ref_kind);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_ref_uid_kind", "graph", "ref_uid", "out_kind"), &OcctlTopo::graph_ref_uid_kind);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_rep_kind", "graph", "id", "out_kind"), &OcctlTopo::graph_rep_kind);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_solid_count", "graph", "out_count"), &OcctlTopo::graph_solid_count);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_shell_count", "graph", "out_count"), &OcctlTopo::graph_shell_count);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_face_count", "graph", "out_count"), &OcctlTopo::graph_face_count);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_wire_count", "graph", "out_count"), &OcctlTopo::graph_wire_count);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_edge_count", "graph", "out_count"), &OcctlTopo::graph_edge_count);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_vertex_count", "graph", "out_count"), &OcctlTopo::graph_vertex_count);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_compound_count", "graph", "out_count"), &OcctlTopo::graph_compound_count);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_compsolid_count", "graph", "out_count"), &OcctlTopo::graph_compsolid_count);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_coedge_count", "graph", "out_count"), &OcctlTopo::graph_coedge_count);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_product_count", "graph", "out_count"), &OcctlTopo::graph_product_count);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_occurrence_count", "graph", "out_count"), &OcctlTopo::graph_occurrence_count);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_node_count", "graph", "out_count"), &OcctlTopo::graph_node_count);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_vertex_point", "graph", "vertex", "out_point"), &OcctlTopo::topo_vertex_point);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_vertex_tolerance", "graph", "vertex", "out_tolerance"), &OcctlTopo::topo_vertex_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_vertex_edge_count", "graph", "vertex", "out_count"), &OcctlTopo::topo_vertex_edge_count);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_range", "graph", "edge", "out_first", "out_last"), &OcctlTopo::topo_edge_range);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_tolerance", "graph", "edge", "out_tolerance"), &OcctlTopo::topo_edge_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_is_degenerated", "graph", "edge", "out_is_degenerated"), &OcctlTopo::topo_edge_is_degenerated);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_has_curve", "graph", "edge", "out_has_curve"), &OcctlTopo::topo_edge_has_curve);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_curve_kind", "graph", "edge", "out_kind"), &OcctlTopo::topo_edge_curve_kind);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_start_vertex", "graph", "edge", "out_vertex"), &OcctlTopo::topo_edge_start_vertex);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_end_vertex", "graph", "edge", "out_vertex"), &OcctlTopo::topo_edge_end_vertex);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_coedge_is_seam", "graph", "coedge", "out_is_seam"), &OcctlTopo::topo_coedge_is_seam);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_coedge_edge_of", "graph", "coedge", "out_edge"), &OcctlTopo::topo_coedge_edge_of);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_coedge_face_of", "graph", "coedge", "out_face"), &OcctlTopo::topo_coedge_face_of);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_face_tolerance", "graph", "face", "out_tolerance"), &OcctlTopo::topo_face_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_face_wire_count", "graph", "face", "out_count"), &OcctlTopo::topo_face_wire_count);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_face_outer_wire", "graph", "face", "out_wire"), &OcctlTopo::topo_face_outer_wire);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_face_uv_bounds", "graph", "face", "out_umin", "out_umax", "out_vmin", "out_vmax"), &OcctlTopo::topo_face_uv_bounds);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_eval", "graph", "edge", "u", "out_p"), &OcctlTopo::topo_edge_eval);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_eval_d1", "graph", "edge", "u", "out_p", "out_d1"), &OcctlTopo::topo_edge_eval_d1);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_eval_d2", "graph", "edge", "u", "out_p", "out_d1", "out_d2"), &OcctlTopo::topo_edge_eval_d2);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_eval_d3", "graph", "edge", "u", "out_p", "out_d1", "out_d2", "out_d3"), &OcctlTopo::topo_edge_eval_d3);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_eval_dn", "graph", "edge", "u", "n", "out_dn"), &OcctlTopo::topo_edge_eval_dn);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_coedge_pcurve_eval", "graph", "coedge", "u", "out_uv"), &OcctlTopo::topo_coedge_pcurve_eval);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_coedge_pcurve_eval_d1", "graph", "coedge", "u", "out_uv", "out_d1"), &OcctlTopo::topo_coedge_pcurve_eval_d1);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_coedge_pcurve_eval_d2", "graph", "coedge", "u", "out_uv", "out_d1", "out_d2"), &OcctlTopo::topo_coedge_pcurve_eval_d2);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_coedge_pcurve_eval_d3", "graph", "coedge", "u", "out_uv", "out_d1", "out_d2", "out_d3"), &OcctlTopo::topo_coedge_pcurve_eval_d3);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_coedge_pcurve_eval_dn", "graph", "coedge", "u", "n", "out_dn"), &OcctlTopo::topo_coedge_pcurve_eval_dn);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_face_eval", "graph", "face", "u", "v", "out_p"), &OcctlTopo::topo_face_eval);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_face_eval_d1", "graph", "face", "u", "v", "out_p", "out_d1u", "out_d1v"), &OcctlTopo::topo_face_eval_d1);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_face_eval_d2", "graph", "face", "u", "v", "out_p", "out_d1u", "out_d1v", "out_d2u", "out_d2v", "out_d2uv"), &OcctlTopo::topo_face_eval_d2);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_face_eval_d3", "graph", "face", "u", "v", "out_p", "out_d1u", "out_d1v", "out_d2u", "out_d2v", "out_d2uv", "out_d3u", "out_d3v", "out_d3uuv", "out_d3uvv"), &OcctlTopo::topo_face_eval_d3);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_face_eval_dn", "graph", "face", "u", "v", "nu", "nv", "out_dn"), &OcctlTopo::topo_face_eval_dn);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_face_has_surface", "graph", "face", "out_has_surface"), &OcctlTopo::topo_face_has_surface);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_face_surface_kind", "graph", "face", "out_kind"), &OcctlTopo::topo_face_surface_kind);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_wire_is_closed", "graph", "wire", "out_is_closed"), &OcctlTopo::topo_wire_is_closed);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_wire_coedge_count", "graph", "wire", "out_count"), &OcctlTopo::topo_wire_coedge_count);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_shell_is_closed", "graph", "shell", "out_is_closed"), &OcctlTopo::topo_shell_is_closed);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_shell_face_count", "graph", "shell", "out_count"), &OcctlTopo::topo_shell_face_count);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_vertex_parameter", "graph", "vertex", "edge", "out_parameter"), &OcctlTopo::topo_vertex_parameter);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_vertex_parameters", "graph", "vertex", "face", "out_uv"), &OcctlTopo::topo_vertex_parameters);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_same_parameter", "graph", "edge", "out_has_same_parameter"), &OcctlTopo::topo_edge_same_parameter);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_same_range", "graph", "edge", "out_has_same_range"), &OcctlTopo::topo_edge_same_range);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_is_manifold", "graph", "edge", "out_is_manifold"), &OcctlTopo::topo_edge_is_manifold);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_is_boundary", "graph", "edge", "out_is_boundary"), &OcctlTopo::topo_edge_is_boundary);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_is_seam_on_face", "graph", "edge", "face", "out_is_seam"), &OcctlTopo::topo_edge_is_seam_on_face);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_face_count", "graph", "edge", "out_count"), &OcctlTopo::topo_edge_face_count);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_coedge_is_reversed", "graph", "coedge", "out_is_reversed"), &OcctlTopo::topo_coedge_is_reversed);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_coedge_has_pcurve", "graph", "coedge", "out_has_pcurve"), &OcctlTopo::topo_coedge_has_pcurve);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_coedge_pcurve_parameter", "graph", "coedge", "vertex", "out_parameter"), &OcctlTopo::topo_coedge_pcurve_parameter);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_coedge_range", "graph", "coedge", "out_first", "out_last"), &OcctlTopo::topo_coedge_range);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_coedge_uv_points", "graph", "coedge", "out_uv_start", "out_uv_end"), &OcctlTopo::topo_coedge_uv_points);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_coedge_seam_pair", "graph", "coedge", "out_pair"), &OcctlTopo::topo_coedge_seam_pair);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_face_natural_restriction", "graph", "face", "out_has_natural_restriction"), &OcctlTopo::topo_face_natural_restriction);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_face_has_triangulation", "graph", "face", "out_has_triangulation"), &OcctlTopo::topo_face_has_triangulation);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_wire_distinct_edge_count", "graph", "wire", "out_count"), &OcctlTopo::topo_wire_distinct_edge_count);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_wire_face_of", "graph", "wire", "out_face"), &OcctlTopo::topo_wire_face_of);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_wire_is_outer", "graph", "wire", "out_is_outer"), &OcctlTopo::topo_wire_is_outer);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_solid_shell_count", "graph", "solid", "out_count"), &OcctlTopo::topo_solid_shell_count);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_wire_edge_count", "graph", "wire", "out_count"), &OcctlTopo::topo_wire_edge_count);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_vertex_count", "graph", "edge", "out_count"), &OcctlTopo::topo_edge_vertex_count);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_compound_child_count", "graph", "compound", "out_count"), &OcctlTopo::topo_compound_child_count);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_compsolid_solid_count", "graph", "compsolid", "out_count"), &OcctlTopo::topo_compsolid_solid_count);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_product_occurrence_count", "graph", "product", "out_count"), &OcctlTopo::topo_product_occurrence_count);
    godot::ClassDB::bind_method(godot::D_METHOD("node_iter_next", "iter", "out_id"), &OcctlTopo::node_iter_next);
    godot::ClassDB::bind_method(godot::D_METHOD("node_iter_free", "iter"), &OcctlTopo::node_iter_free);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_solid_iter_create", "graph"), &OcctlTopo::graph_solid_iter_create);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_shell_iter_create", "graph"), &OcctlTopo::graph_shell_iter_create);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_face_iter_create", "graph"), &OcctlTopo::graph_face_iter_create);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_wire_iter_create", "graph"), &OcctlTopo::graph_wire_iter_create);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_edge_iter_create", "graph"), &OcctlTopo::graph_edge_iter_create);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_vertex_iter_create", "graph"), &OcctlTopo::graph_vertex_iter_create);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_compound_iter_create", "graph"), &OcctlTopo::graph_compound_iter_create);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_compsolid_iter_create", "graph"), &OcctlTopo::graph_compsolid_iter_create);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_coedge_iter_create", "graph"), &OcctlTopo::graph_coedge_iter_create);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_product_iter_create", "graph"), &OcctlTopo::graph_product_iter_create);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_occurrence_iter_create", "graph"), &OcctlTopo::graph_occurrence_iter_create);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_root_product_iter_create", "graph"), &OcctlTopo::graph_root_product_iter_create);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_shells_of_solid_iter_create", "graph", "solid"), &OcctlTopo::topo_shells_of_solid_iter_create);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_faces_of_shell_iter_create", "graph", "shell"), &OcctlTopo::topo_faces_of_shell_iter_create);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_wires_of_face_iter_create", "graph", "face"), &OcctlTopo::topo_wires_of_face_iter_create);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_coedges_of_wire_iter_create", "graph", "wire"), &OcctlTopo::topo_coedges_of_wire_iter_create);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edges_of_wire_iter_create", "graph", "wire"), &OcctlTopo::topo_edges_of_wire_iter_create);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_wire_explorer_create", "graph", "wire"), &OcctlTopo::topo_wire_explorer_create);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_occurrences_of_product_iter_create", "graph", "product"), &OcctlTopo::topo_occurrences_of_product_iter_create);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_vertices_of_edge_iter_create", "graph", "edge"), &OcctlTopo::topo_vertices_of_edge_iter_create);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_for_each", "graph", "kind_mask", "callable"), &OcctlTopo::graph_for_each);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_for_each_ref", "graph", "ref_kind_mask", "callable"), &OcctlTopo::graph_for_each_ref);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_for_each_rep", "graph", "rep_kind_mask", "callable"), &OcctlTopo::graph_for_each_rep);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_for_each_related", "graph", "node", "callable"), &OcctlTopo::topo_for_each_related);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_color_set", "graph", "target", "color"), &OcctlTopo::graph_color_set);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_color_get", "graph", "target", "out_color"), &OcctlTopo::graph_color_get);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_color_entries", "graph"), &OcctlTopo::graph_color_entries);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_color_unset", "graph", "target"), &OcctlTopo::graph_color_unset);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_name_set", "graph", "target", "name"), &OcctlTopo::graph_name_set);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_name_get", "graph", "target"), &OcctlTopo::graph_name_get);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_name_nodes", "graph"), &OcctlTopo::graph_name_nodes);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_material_set", "graph", "target", "info"), &OcctlTopo::graph_material_set, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("graph_material_get", "graph", "target", "out_info"), &OcctlTopo::graph_material_get);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_material_nodes", "graph"), &OcctlTopo::graph_material_nodes);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_material_unset", "graph", "target"), &OcctlTopo::graph_material_unset);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_units_set", "graph", "length_unit_to_meter", "name"), &OcctlTopo::graph_units_set);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_units_get", "graph", "out_length_unit_to_meter"), &OcctlTopo::graph_units_get);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_node_metadata_set", "graph", "target", "key", "value"), &OcctlTopo::graph_node_metadata_set);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_node_metadata_get", "graph", "target", "key"), &OcctlTopo::graph_node_metadata_get);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_node_metadata_keys", "graph", "target"), &OcctlTopo::graph_node_metadata_keys);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_node_metadata_nodes", "graph"), &OcctlTopo::graph_node_metadata_nodes);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_metadata_set", "graph", "key", "value"), &OcctlTopo::graph_metadata_set);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_metadata_get", "graph", "key"), &OcctlTopo::graph_metadata_get);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_metadata_keys", "graph"), &OcctlTopo::graph_metadata_keys);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_metadata_unset", "graph", "key"), &OcctlTopo::graph_metadata_unset);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_node_metadata_unset", "graph", "target", "key"), &OcctlTopo::graph_node_metadata_unset);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_tag_add", "graph", "target", "tag"), &OcctlTopo::graph_tag_add);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_tag_remove", "graph", "target", "tag"), &OcctlTopo::graph_tag_remove);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_tag_has", "graph", "target", "tag", "out_has_tag"), &OcctlTopo::graph_tag_has);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_tag_list", "graph", "target"), &OcctlTopo::graph_tag_list);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_tag_nodes", "graph", "tag"), &OcctlTopo::graph_tag_nodes);
    godot::ClassDB::bind_method(godot::D_METHOD("joint_info_init", "info"), &OcctlTopo::joint_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("joint_create", "graph", "info", "out_joint"), &OcctlTopo::joint_create, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("joint_get", "graph", "joint", "out_info"), &OcctlTopo::joint_get);
    godot::ClassDB::bind_method(godot::D_METHOD("joint_remove", "graph", "joint"), &OcctlTopo::joint_remove);
    godot::ClassDB::bind_method(godot::D_METHOD("joint_list", "graph", "node"), &OcctlTopo::joint_list);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_make_product_info_init", "info"), &OcctlTopo::topo_make_product_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_make_product", "graph", "info", "out_product"), &OcctlTopo::topo_make_product, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("topo_link_product", "graph", "product", "root", "placement"), &OcctlTopo::topo_link_product);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_link_product_occurrence", "graph", "product", "root", "placement", "out_occurrence"), &OcctlTopo::topo_link_product_occurrence);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_link_products", "graph", "parentProduct", "childProduct", "placement", "parentOccurrence"), &OcctlTopo::topo_link_products);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_link_products_occurrence", "graph", "parentProduct", "childProduct", "placement", "parentOccurrence", "out_occurrence"), &OcctlTopo::topo_link_products_occurrence);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_remove_occurrence", "graph", "occurrence_ref"), &OcctlTopo::topo_remove_occurrence);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_occurrence_set_transform", "graph", "occurrence", "transform"), &OcctlTopo::topo_occurrence_set_transform);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_occurrence_transform", "graph", "occurrence", "out_transform"), &OcctlTopo::topo_occurrence_transform);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_occurrence_world_transform", "graph", "root", "occurrence", "out_transform"), &OcctlTopo::topo_occurrence_world_transform);
    godot::ClassDB::bind_method(godot::D_METHOD("edge_view_init", "view"), &OcctlTopo::edge_view_init);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_edge_view", "graph", "edge", "view"), &OcctlTopo::topo_edge_view);
    godot::ClassDB::bind_method(godot::D_METHOD("coedge_view_init", "view"), &OcctlTopo::coedge_view_init);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_coedge_view", "graph", "coedge", "view"), &OcctlTopo::topo_coedge_view);
    godot::ClassDB::bind_method(godot::D_METHOD("face_view_init", "view"), &OcctlTopo::face_view_init);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_face_view", "graph", "face", "view"), &OcctlTopo::topo_face_view);
    godot::ClassDB::bind_method(godot::D_METHOD("vertex_view_init", "view"), &OcctlTopo::vertex_view_init);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_vertex_view", "graph", "vertex", "view"), &OcctlTopo::topo_vertex_view);
    godot::ClassDB::bind_method(godot::D_METHOD("wire_view_init", "view"), &OcctlTopo::wire_view_init);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_wire_view", "graph", "wire", "view"), &OcctlTopo::topo_wire_view);
    godot::ClassDB::bind_method(godot::D_METHOD("shell_view_init", "view"), &OcctlTopo::shell_view_init);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_shell_view", "graph", "shell", "view"), &OcctlTopo::topo_shell_view);
    godot::ClassDB::bind_method(godot::D_METHOD("solid_view_init", "view"), &OcctlTopo::solid_view_init);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_solid_view", "graph", "solid", "view"), &OcctlTopo::topo_solid_view);
    godot::ClassDB::bind_method(godot::D_METHOD("compound_view_init", "view"), &OcctlTopo::compound_view_init);
    godot::ClassDB::bind_method(godot::D_METHOD("topo_compound_view", "graph", "compound", "view"), &OcctlTopo::topo_compound_view);
}

Ref<OcctlGraphHandle> OcctlTopo::graph_create(void) { // NOLINT
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_status_t _status = ::occtl_graph_create(&_out_graph_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

void OcctlTopo::graph_free(const Ref<OcctlGraphHandle>& graph) { // NOLINT
    ::occtl_graph_free(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->release() : 0)));
}

int OcctlTopo::graph_node_id_from_uid(const Ref<OcctlGraphHandle>& graph, int64_t uid, const Ref<OcctlNodeId>& out_node_id) { // NOLINT
    occtl_node_id_t _out_node_id_val = {};
    occtl_status_t _status = ::occtl_graph_node_id_from_uid(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_uid_t{static_cast<uint64_t>(uid)}, &_out_node_id_val);
    if (out_node_id.is_valid()) out_node_id->copy_from_c(_out_node_id_val);
    return static_cast<int>(_status);
}

int OcctlTopo::graph_uid_from_node_id(const Ref<OcctlGraphHandle>& graph, int64_t id, const Ref<OcctlUid>& out_uid) { // NOLINT
    occtl_uid_t _out_uid_val = {};
    occtl_status_t _status = ::occtl_graph_uid_from_node_id(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(id)}, &_out_uid_val);
    if (out_uid.is_valid()) out_uid->copy_from_c(_out_uid_val);
    return static_cast<int>(_status);
}

PackedInt64Array OcctlTopo::graph_history_modified(const Ref<OcctlGraphHandle>& graph, int64_t input_uid) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_graph_history_modified(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_uid_t{static_cast<uint64_t>(input_uid)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt64Array(); }
    std::vector<occtl_uid_t> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_graph_history_modified(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_uid_t{static_cast<uint64_t>(input_uid)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_buf_buf[_i].bits);
    return _result;
}

PackedInt64Array OcctlTopo::graph_history_generated(const Ref<OcctlGraphHandle>& graph, int64_t input_uid) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_graph_history_generated(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_uid_t{static_cast<uint64_t>(input_uid)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt64Array(); }
    std::vector<occtl_uid_t> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_graph_history_generated(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_uid_t{static_cast<uint64_t>(input_uid)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_buf_buf[_i].bits);
    return _result;
}

PackedInt64Array OcctlTopo::graph_history_deleted_all(const Ref<OcctlGraphHandle>& graph) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_graph_history_deleted_all(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt64Array(); }
    std::vector<occtl_uid_t> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_graph_history_deleted_all(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_buf_buf[_i].bits);
    return _result;
}

int OcctlTopo::graph_ref_id_from_ref_uid(const Ref<OcctlGraphHandle>& graph, int64_t ref_uid, const Ref<OcctlRefId>& out_ref_id) { // NOLINT
    occtl_ref_id_t _out_ref_id_val = {};
    occtl_status_t _status = ::occtl_graph_ref_id_from_ref_uid(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_ref_uid_t{static_cast<uint64_t>(ref_uid)}, &_out_ref_id_val);
    if (out_ref_id.is_valid()) out_ref_id->copy_from_c(_out_ref_id_val);
    return static_cast<int>(_status);
}

int OcctlTopo::graph_ref_uid_from_ref_id(const Ref<OcctlGraphHandle>& graph, int64_t ref_id, const Ref<OcctlRefUid>& out_ref_uid) { // NOLINT
    occtl_ref_uid_t _out_ref_uid_val = {};
    occtl_status_t _status = ::occtl_graph_ref_uid_from_ref_id(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_ref_id_t{static_cast<uint64_t>(ref_id)}, &_out_ref_uid_val);
    if (out_ref_uid.is_valid()) out_ref_uid->copy_from_c(_out_ref_uid_val);
    return static_cast<int>(_status);
}

int OcctlTopo::graph_rep_id_from_rep_uid(const Ref<OcctlGraphHandle>& graph, int64_t rep_uid, const Ref<OcctlRepId>& out_rep_id) { // NOLINT
    occtl_rep_id_t _out_rep_id_val = {};
    occtl_status_t _status = ::occtl_graph_rep_id_from_rep_uid(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_uid_t{static_cast<uint64_t>(rep_uid)}, &_out_rep_id_val);
    if (out_rep_id.is_valid()) out_rep_id->copy_from_c(_out_rep_id_val);
    return static_cast<int>(_status);
}

int OcctlTopo::graph_rep_uid_from_rep_id(const Ref<OcctlGraphHandle>& graph, int64_t rep_id, const Ref<OcctlRepUid>& out_rep_uid) { // NOLINT
    occtl_rep_uid_t _out_rep_uid_val = {};
    occtl_status_t _status = ::occtl_graph_rep_uid_from_rep_id(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(rep_id)}, &_out_rep_uid_val);
    if (out_rep_uid.is_valid()) out_rep_uid->copy_from_c(_out_rep_uid_val);
    return static_cast<int>(_status);
}

int OcctlTopo::ref_uid_to_bytes(int64_t ref_uid, const Ref<OcctlByteArray>& out_bytes) { // NOLINT
    uint8_t _out_bytes_buf[16] = {};
    occtl_status_t _status = ::occtl_ref_uid_to_bytes(occtl_ref_uid_t{static_cast<uint64_t>(ref_uid)}, _out_bytes_buf);
    if (out_bytes.is_valid()) {
        PackedByteArray _ba;
        _ba.resize(16);
        for (int _i = 0; _i < 16; ++_i) _ba[_i] = _out_bytes_buf[_i];
        out_bytes->copy_from_c(_ba);
    }
    return static_cast<int>(_status);
}

int OcctlTopo::ref_uid_from_bytes(const PackedByteArray& in_bytes, const Ref<OcctlRefUid>& out_ref_uid) { // NOLINT
    const uint8_t* _in_bytes_c = in_bytes.ptr();
    occtl_ref_uid_t _out_ref_uid_val = {};
    occtl_status_t _status = ::occtl_ref_uid_from_bytes(_in_bytes_c, &_out_ref_uid_val);
    if (out_ref_uid.is_valid()) out_ref_uid->copy_from_c(_out_ref_uid_val);
    return static_cast<int>(_status);
}

int OcctlTopo::rep_uid_to_bytes(int64_t rep_uid, const Ref<OcctlByteArray>& out_bytes) { // NOLINT
    uint8_t _out_bytes_buf[16] = {};
    occtl_status_t _status = ::occtl_rep_uid_to_bytes(occtl_rep_uid_t{static_cast<uint64_t>(rep_uid)}, _out_bytes_buf);
    if (out_bytes.is_valid()) {
        PackedByteArray _ba;
        _ba.resize(16);
        for (int _i = 0; _i < 16; ++_i) _ba[_i] = _out_bytes_buf[_i];
        out_bytes->copy_from_c(_ba);
    }
    return static_cast<int>(_status);
}

int OcctlTopo::rep_uid_from_bytes(const PackedByteArray& in_bytes, const Ref<OcctlRepUid>& out_rep_uid) { // NOLINT
    const uint8_t* _in_bytes_c = in_bytes.ptr();
    occtl_rep_uid_t _out_rep_uid_val = {};
    occtl_status_t _status = ::occtl_rep_uid_from_bytes(_in_bytes_c, &_out_rep_uid_val);
    if (out_rep_uid.is_valid()) out_rep_uid->copy_from_c(_out_rep_uid_val);
    return static_cast<int>(_status);
}

Dictionary OcctlTopo::graph_uid_table(const Ref<OcctlGraphHandle>& graph) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_graph_uid_table(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), nullptr, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return Dictionary(); }
    std::vector<occtl_uid_t> _out_uids_buf(_out_count_cnt);
    std::vector<occtl_node_id_t> _out_nodes_buf(_out_count_cnt);
    _err = ::occtl_graph_uid_table(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _out_uids_buf.data(), _out_nodes_buf.data(), _out_count_cnt, &_out_count_cnt);
    Dictionary _result;
    PackedInt64Array _uids;
    _uids.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _uids[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_uids_buf[_i].bits);
    _result["uids"] = _uids;
    PackedInt64Array _nodes;
    _nodes.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _nodes[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_nodes_buf[_i].bits);
    _result["nodes"] = _nodes;
    return _result;
}

Dictionary OcctlTopo::graph_ref_uid_table(const Ref<OcctlGraphHandle>& graph) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_graph_ref_uid_table(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), nullptr, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return Dictionary(); }
    std::vector<occtl_ref_uid_t> _out_ref_uids_buf(_out_count_cnt);
    std::vector<occtl_ref_id_t> _out_refs_buf(_out_count_cnt);
    _err = ::occtl_graph_ref_uid_table(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _out_ref_uids_buf.data(), _out_refs_buf.data(), _out_count_cnt, &_out_count_cnt);
    Dictionary _result;
    PackedInt64Array _ref_uids;
    _ref_uids.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _ref_uids[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_ref_uids_buf[_i].bits);
    _result["ref_uids"] = _ref_uids;
    PackedInt64Array _refs;
    _refs.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _refs[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_refs_buf[_i].bits);
    _result["refs"] = _refs;
    return _result;
}

int OcctlTopo::graph_node_kind(const Ref<OcctlGraphHandle>& graph, int64_t id, const Ref<OcctlInt32>& out_kind) { // NOLINT
    occtl_node_kind_t _out_kind_val = {};
    occtl_status_t _status = ::occtl_graph_node_kind(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(id)}, &_out_kind_val);
    if (out_kind.is_valid()) out_kind->copy_from_c(_out_kind_val);
    return static_cast<int>(_status);
}

int OcctlTopo::graph_uid_kind(const Ref<OcctlGraphHandle>& graph, int64_t uid, const Ref<OcctlInt32>& out_kind) { // NOLINT
    occtl_node_kind_t _out_kind_val = {};
    occtl_status_t _status = ::occtl_graph_uid_kind(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_uid_t{static_cast<uint64_t>(uid)}, &_out_kind_val);
    if (out_kind.is_valid()) out_kind->copy_from_c(_out_kind_val);
    return static_cast<int>(_status);
}

int OcctlTopo::graph_ref_kind(const Ref<OcctlGraphHandle>& graph, int64_t id, const Ref<OcctlInt32>& out_kind) { // NOLINT
    occtl_ref_kind_t _out_kind_val = {};
    occtl_status_t _status = ::occtl_graph_ref_kind(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_ref_id_t{static_cast<uint64_t>(id)}, &_out_kind_val);
    if (out_kind.is_valid()) out_kind->copy_from_c(_out_kind_val);
    return static_cast<int>(_status);
}

int OcctlTopo::graph_ref_uid_kind(const Ref<OcctlGraphHandle>& graph, int64_t ref_uid, const Ref<OcctlInt32>& out_kind) { // NOLINT
    occtl_ref_kind_t _out_kind_val = {};
    occtl_status_t _status = ::occtl_graph_ref_uid_kind(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_ref_uid_t{static_cast<uint64_t>(ref_uid)}, &_out_kind_val);
    if (out_kind.is_valid()) out_kind->copy_from_c(_out_kind_val);
    return static_cast<int>(_status);
}

int OcctlTopo::graph_rep_kind(const Ref<OcctlGraphHandle>& graph, int64_t id, const Ref<OcctlInt32>& out_kind) { // NOLINT
    occtl_rep_kind_t _out_kind_val = {};
    occtl_status_t _status = ::occtl_graph_rep_kind(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_rep_id_t{static_cast<uint64_t>(id)}, &_out_kind_val);
    if (out_kind.is_valid()) out_kind->copy_from_c(_out_kind_val);
    return static_cast<int>(_status);
}

int OcctlTopo::graph_solid_count(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSize>& out_count) { // NOLINT
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_graph_solid_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlTopo::graph_shell_count(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSize>& out_count) { // NOLINT
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_graph_shell_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlTopo::graph_face_count(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSize>& out_count) { // NOLINT
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_graph_face_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlTopo::graph_wire_count(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSize>& out_count) { // NOLINT
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_graph_wire_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlTopo::graph_edge_count(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSize>& out_count) { // NOLINT
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_graph_edge_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlTopo::graph_vertex_count(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSize>& out_count) { // NOLINT
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_graph_vertex_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlTopo::graph_compound_count(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSize>& out_count) { // NOLINT
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_graph_compound_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlTopo::graph_compsolid_count(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSize>& out_count) { // NOLINT
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_graph_compsolid_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlTopo::graph_coedge_count(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSize>& out_count) { // NOLINT
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_graph_coedge_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlTopo::graph_product_count(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSize>& out_count) { // NOLINT
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_graph_product_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlTopo::graph_occurrence_count(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSize>& out_count) { // NOLINT
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_graph_occurrence_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlTopo::graph_node_count(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlSize>& out_count) { // NOLINT
    size_t _out_count_val = {};
    occtl_status_t _status = ::occtl_graph_node_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_vertex_point(const Ref<OcctlGraphHandle>& graph, int64_t vertex, const Ref<OcctlPoint3>& out_point) { // NOLINT
    occtl_point3_t _out_point_val = {};
    occtl_status_t _status = ::occtl_topo_vertex_point(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(vertex)}, &_out_point_val);
    if (out_point.is_valid()) out_point->copy_from_c(_out_point_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_vertex_tolerance(const Ref<OcctlGraphHandle>& graph, int64_t vertex, const Ref<OcctlDouble>& out_tolerance) { // NOLINT
    double _out_tolerance_val = {};
    occtl_status_t _status = ::occtl_topo_vertex_tolerance(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(vertex)}, &_out_tolerance_val);
    if (out_tolerance.is_valid()) out_tolerance->copy_from_c(_out_tolerance_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_vertex_edge_count(const Ref<OcctlGraphHandle>& graph, int64_t vertex, const Ref<OcctlUint32>& out_count) { // NOLINT
    uint32_t _out_count_val = {};
    occtl_status_t _status = ::occtl_topo_vertex_edge_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(vertex)}, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_edge_range(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlDouble>& out_first, const Ref<OcctlDouble>& out_last) { // NOLINT
    double _out_first_val = {};
    double _out_last_val = {};
    occtl_status_t _status = ::occtl_topo_edge_range(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, &_out_first_val, &_out_last_val);
    if (out_first.is_valid()) out_first->copy_from_c(_out_first_val);
    if (out_last.is_valid()) out_last->copy_from_c(_out_last_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_edge_tolerance(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlDouble>& out_tolerance) { // NOLINT
    double _out_tolerance_val = {};
    occtl_status_t _status = ::occtl_topo_edge_tolerance(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, &_out_tolerance_val);
    if (out_tolerance.is_valid()) out_tolerance->copy_from_c(_out_tolerance_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_edge_is_degenerated(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlInt32>& out_is_degenerated) { // NOLINT
    int32_t _out_is_degenerated_val = {};
    occtl_status_t _status = ::occtl_topo_edge_is_degenerated(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, &_out_is_degenerated_val);
    if (out_is_degenerated.is_valid()) out_is_degenerated->copy_from_c(_out_is_degenerated_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_edge_has_curve(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlInt32>& out_has_curve) { // NOLINT
    int32_t _out_has_curve_val = {};
    occtl_status_t _status = ::occtl_topo_edge_has_curve(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, &_out_has_curve_val);
    if (out_has_curve.is_valid()) out_has_curve->copy_from_c(_out_has_curve_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_edge_curve_kind(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlInt32>& out_kind) { // NOLINT
    occtl_curve_kind_t _out_kind_val = {};
    occtl_status_t _status = ::occtl_topo_edge_curve_kind(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, &_out_kind_val);
    if (out_kind.is_valid()) out_kind->copy_from_c(_out_kind_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_edge_start_vertex(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlNodeId>& out_vertex) { // NOLINT
    occtl_node_id_t _out_vertex_val = {};
    occtl_status_t _status = ::occtl_topo_edge_start_vertex(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, &_out_vertex_val);
    if (out_vertex.is_valid()) out_vertex->copy_from_c(_out_vertex_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_edge_end_vertex(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlNodeId>& out_vertex) { // NOLINT
    occtl_node_id_t _out_vertex_val = {};
    occtl_status_t _status = ::occtl_topo_edge_end_vertex(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, &_out_vertex_val);
    if (out_vertex.is_valid()) out_vertex->copy_from_c(_out_vertex_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_coedge_is_seam(const Ref<OcctlGraphHandle>& graph, int64_t coedge, const Ref<OcctlInt32>& out_is_seam) { // NOLINT
    int32_t _out_is_seam_val = {};
    occtl_status_t _status = ::occtl_topo_coedge_is_seam(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(coedge)}, &_out_is_seam_val);
    if (out_is_seam.is_valid()) out_is_seam->copy_from_c(_out_is_seam_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_coedge_edge_of(const Ref<OcctlGraphHandle>& graph, int64_t coedge, const Ref<OcctlNodeId>& out_edge) { // NOLINT
    occtl_node_id_t _out_edge_val = {};
    occtl_status_t _status = ::occtl_topo_coedge_edge_of(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(coedge)}, &_out_edge_val);
    if (out_edge.is_valid()) out_edge->copy_from_c(_out_edge_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_coedge_face_of(const Ref<OcctlGraphHandle>& graph, int64_t coedge, const Ref<OcctlNodeId>& out_face) { // NOLINT
    occtl_node_id_t _out_face_val = {};
    occtl_status_t _status = ::occtl_topo_coedge_face_of(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(coedge)}, &_out_face_val);
    if (out_face.is_valid()) out_face->copy_from_c(_out_face_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_face_tolerance(const Ref<OcctlGraphHandle>& graph, int64_t face, const Ref<OcctlDouble>& out_tolerance) { // NOLINT
    double _out_tolerance_val = {};
    occtl_status_t _status = ::occtl_topo_face_tolerance(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, &_out_tolerance_val);
    if (out_tolerance.is_valid()) out_tolerance->copy_from_c(_out_tolerance_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_face_wire_count(const Ref<OcctlGraphHandle>& graph, int64_t face, const Ref<OcctlUint32>& out_count) { // NOLINT
    uint32_t _out_count_val = {};
    occtl_status_t _status = ::occtl_topo_face_wire_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_face_outer_wire(const Ref<OcctlGraphHandle>& graph, int64_t face, const Ref<OcctlNodeId>& out_wire) { // NOLINT
    occtl_node_id_t _out_wire_val = {};
    occtl_status_t _status = ::occtl_topo_face_outer_wire(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, &_out_wire_val);
    if (out_wire.is_valid()) out_wire->copy_from_c(_out_wire_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_face_uv_bounds(const Ref<OcctlGraphHandle>& graph, int64_t face, const Ref<OcctlDouble>& out_umin, const Ref<OcctlDouble>& out_umax, const Ref<OcctlDouble>& out_vmin, const Ref<OcctlDouble>& out_vmax) { // NOLINT
    double _out_umin_val = {};
    double _out_umax_val = {};
    double _out_vmin_val = {};
    double _out_vmax_val = {};
    occtl_status_t _status = ::occtl_topo_face_uv_bounds(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, &_out_umin_val, &_out_umax_val, &_out_vmin_val, &_out_vmax_val);
    if (out_umin.is_valid()) out_umin->copy_from_c(_out_umin_val);
    if (out_umax.is_valid()) out_umax->copy_from_c(_out_umax_val);
    if (out_vmin.is_valid()) out_vmin->copy_from_c(_out_vmin_val);
    if (out_vmax.is_valid()) out_vmax->copy_from_c(_out_vmax_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_edge_eval(const Ref<OcctlGraphHandle>& graph, int64_t edge, double u, const Ref<OcctlPoint3>& out_p) { // NOLINT
    occtl_point3_t _out_p_val = {};
    occtl_status_t _status = ::occtl_topo_edge_eval(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, u, &_out_p_val);
    if (out_p.is_valid()) out_p->copy_from_c(_out_p_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_edge_eval_d1(const Ref<OcctlGraphHandle>& graph, int64_t edge, double u, const Ref<OcctlPoint3>& out_p, const Ref<OcctlVector3>& out_d1) { // NOLINT
    occtl_point3_t _out_p_val = {};
    occtl_vector3_t _out_d1_val = {};
    occtl_status_t _status = ::occtl_topo_edge_eval_d1(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, u, &_out_p_val, &_out_d1_val);
    if (out_p.is_valid()) out_p->copy_from_c(_out_p_val);
    if (out_d1.is_valid()) out_d1->copy_from_c(_out_d1_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_edge_eval_d2(const Ref<OcctlGraphHandle>& graph, int64_t edge, double u, const Ref<OcctlPoint3>& out_p, const Ref<OcctlVector3>& out_d1, const Ref<OcctlVector3>& out_d2) { // NOLINT
    occtl_point3_t _out_p_val = {};
    occtl_vector3_t _out_d1_val = {};
    occtl_vector3_t _out_d2_val = {};
    occtl_status_t _status = ::occtl_topo_edge_eval_d2(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, u, &_out_p_val, &_out_d1_val, &_out_d2_val);
    if (out_p.is_valid()) out_p->copy_from_c(_out_p_val);
    if (out_d1.is_valid()) out_d1->copy_from_c(_out_d1_val);
    if (out_d2.is_valid()) out_d2->copy_from_c(_out_d2_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_edge_eval_d3(const Ref<OcctlGraphHandle>& graph, int64_t edge, double u, const Ref<OcctlPoint3>& out_p, const Ref<OcctlVector3>& out_d1, const Ref<OcctlVector3>& out_d2, const Ref<OcctlVector3>& out_d3) { // NOLINT
    occtl_point3_t _out_p_val = {};
    occtl_vector3_t _out_d1_val = {};
    occtl_vector3_t _out_d2_val = {};
    occtl_vector3_t _out_d3_val = {};
    occtl_status_t _status = ::occtl_topo_edge_eval_d3(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, u, &_out_p_val, &_out_d1_val, &_out_d2_val, &_out_d3_val);
    if (out_p.is_valid()) out_p->copy_from_c(_out_p_val);
    if (out_d1.is_valid()) out_d1->copy_from_c(_out_d1_val);
    if (out_d2.is_valid()) out_d2->copy_from_c(_out_d2_val);
    if (out_d3.is_valid()) out_d3->copy_from_c(_out_d3_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_edge_eval_dn(const Ref<OcctlGraphHandle>& graph, int64_t edge, double u, int n, const Ref<OcctlVector3>& out_dn) { // NOLINT
    occtl_vector3_t _out_dn_val = {};
    occtl_status_t _status = ::occtl_topo_edge_eval_dn(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, u, n, &_out_dn_val);
    if (out_dn.is_valid()) out_dn->copy_from_c(_out_dn_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_coedge_pcurve_eval(const Ref<OcctlGraphHandle>& graph, int64_t coedge, double u, const Ref<OcctlPoint2>& out_uv) { // NOLINT
    occtl_point2_t _out_uv_val = {};
    occtl_status_t _status = ::occtl_topo_coedge_pcurve_eval(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(coedge)}, u, &_out_uv_val);
    if (out_uv.is_valid()) out_uv->copy_from_c(_out_uv_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_coedge_pcurve_eval_d1(const Ref<OcctlGraphHandle>& graph, int64_t coedge, double u, const Ref<OcctlPoint2>& out_uv, const Ref<OcctlVector2>& out_d1) { // NOLINT
    occtl_point2_t _out_uv_val = {};
    occtl_vector2_t _out_d1_val = {};
    occtl_status_t _status = ::occtl_topo_coedge_pcurve_eval_d1(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(coedge)}, u, &_out_uv_val, &_out_d1_val);
    if (out_uv.is_valid()) out_uv->copy_from_c(_out_uv_val);
    if (out_d1.is_valid()) out_d1->copy_from_c(_out_d1_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_coedge_pcurve_eval_d2(const Ref<OcctlGraphHandle>& graph, int64_t coedge, double u, const Ref<OcctlPoint2>& out_uv, const Ref<OcctlVector2>& out_d1, const Ref<OcctlVector2>& out_d2) { // NOLINT
    occtl_point2_t _out_uv_val = {};
    occtl_vector2_t _out_d1_val = {};
    occtl_vector2_t _out_d2_val = {};
    occtl_status_t _status = ::occtl_topo_coedge_pcurve_eval_d2(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(coedge)}, u, &_out_uv_val, &_out_d1_val, &_out_d2_val);
    if (out_uv.is_valid()) out_uv->copy_from_c(_out_uv_val);
    if (out_d1.is_valid()) out_d1->copy_from_c(_out_d1_val);
    if (out_d2.is_valid()) out_d2->copy_from_c(_out_d2_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_coedge_pcurve_eval_d3(const Ref<OcctlGraphHandle>& graph, int64_t coedge, double u, const Ref<OcctlPoint2>& out_uv, const Ref<OcctlVector2>& out_d1, const Ref<OcctlVector2>& out_d2, const Ref<OcctlVector2>& out_d3) { // NOLINT
    occtl_point2_t _out_uv_val = {};
    occtl_vector2_t _out_d1_val = {};
    occtl_vector2_t _out_d2_val = {};
    occtl_vector2_t _out_d3_val = {};
    occtl_status_t _status = ::occtl_topo_coedge_pcurve_eval_d3(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(coedge)}, u, &_out_uv_val, &_out_d1_val, &_out_d2_val, &_out_d3_val);
    if (out_uv.is_valid()) out_uv->copy_from_c(_out_uv_val);
    if (out_d1.is_valid()) out_d1->copy_from_c(_out_d1_val);
    if (out_d2.is_valid()) out_d2->copy_from_c(_out_d2_val);
    if (out_d3.is_valid()) out_d3->copy_from_c(_out_d3_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_coedge_pcurve_eval_dn(const Ref<OcctlGraphHandle>& graph, int64_t coedge, double u, int n, const Ref<OcctlVector2>& out_dn) { // NOLINT
    occtl_vector2_t _out_dn_val = {};
    occtl_status_t _status = ::occtl_topo_coedge_pcurve_eval_dn(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(coedge)}, u, n, &_out_dn_val);
    if (out_dn.is_valid()) out_dn->copy_from_c(_out_dn_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_face_eval(const Ref<OcctlGraphHandle>& graph, int64_t face, double u, double v, const Ref<OcctlPoint3>& out_p) { // NOLINT
    occtl_point3_t _out_p_val = {};
    occtl_status_t _status = ::occtl_topo_face_eval(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, u, v, &_out_p_val);
    if (out_p.is_valid()) out_p->copy_from_c(_out_p_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_face_eval_d1(const Ref<OcctlGraphHandle>& graph, int64_t face, double u, double v, const Ref<OcctlPoint3>& out_p, const Ref<OcctlVector3>& out_d1u, const Ref<OcctlVector3>& out_d1v) { // NOLINT
    occtl_point3_t _out_p_val = {};
    occtl_vector3_t _out_d1u_val = {};
    occtl_vector3_t _out_d1v_val = {};
    occtl_status_t _status = ::occtl_topo_face_eval_d1(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, u, v, &_out_p_val, &_out_d1u_val, &_out_d1v_val);
    if (out_p.is_valid()) out_p->copy_from_c(_out_p_val);
    if (out_d1u.is_valid()) out_d1u->copy_from_c(_out_d1u_val);
    if (out_d1v.is_valid()) out_d1v->copy_from_c(_out_d1v_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_face_eval_d2(const Ref<OcctlGraphHandle>& graph, int64_t face, double u, double v, const Ref<OcctlPoint3>& out_p, const Ref<OcctlVector3>& out_d1u, const Ref<OcctlVector3>& out_d1v, const Ref<OcctlVector3>& out_d2u, const Ref<OcctlVector3>& out_d2v, const Ref<OcctlVector3>& out_d2uv) { // NOLINT
    occtl_point3_t _out_p_val = {};
    occtl_vector3_t _out_d1u_val = {};
    occtl_vector3_t _out_d1v_val = {};
    occtl_vector3_t _out_d2u_val = {};
    occtl_vector3_t _out_d2v_val = {};
    occtl_vector3_t _out_d2uv_val = {};
    occtl_status_t _status = ::occtl_topo_face_eval_d2(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, u, v, &_out_p_val, &_out_d1u_val, &_out_d1v_val, &_out_d2u_val, &_out_d2v_val, &_out_d2uv_val);
    if (out_p.is_valid()) out_p->copy_from_c(_out_p_val);
    if (out_d1u.is_valid()) out_d1u->copy_from_c(_out_d1u_val);
    if (out_d1v.is_valid()) out_d1v->copy_from_c(_out_d1v_val);
    if (out_d2u.is_valid()) out_d2u->copy_from_c(_out_d2u_val);
    if (out_d2v.is_valid()) out_d2v->copy_from_c(_out_d2v_val);
    if (out_d2uv.is_valid()) out_d2uv->copy_from_c(_out_d2uv_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_face_eval_d3(const Ref<OcctlGraphHandle>& graph, int64_t face, double u, double v, const Ref<OcctlPoint3>& out_p, const Ref<OcctlVector3>& out_d1u, const Ref<OcctlVector3>& out_d1v, const Ref<OcctlVector3>& out_d2u, const Ref<OcctlVector3>& out_d2v, const Ref<OcctlVector3>& out_d2uv, const Ref<OcctlVector3>& out_d3u, const Ref<OcctlVector3>& out_d3v, const Ref<OcctlVector3>& out_d3uuv, const Ref<OcctlVector3>& out_d3uvv) { // NOLINT
    occtl_point3_t _out_p_val = {};
    occtl_vector3_t _out_d1u_val = {};
    occtl_vector3_t _out_d1v_val = {};
    occtl_vector3_t _out_d2u_val = {};
    occtl_vector3_t _out_d2v_val = {};
    occtl_vector3_t _out_d2uv_val = {};
    occtl_vector3_t _out_d3u_val = {};
    occtl_vector3_t _out_d3v_val = {};
    occtl_vector3_t _out_d3uuv_val = {};
    occtl_vector3_t _out_d3uvv_val = {};
    occtl_status_t _status = ::occtl_topo_face_eval_d3(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, u, v, &_out_p_val, &_out_d1u_val, &_out_d1v_val, &_out_d2u_val, &_out_d2v_val, &_out_d2uv_val, &_out_d3u_val, &_out_d3v_val, &_out_d3uuv_val, &_out_d3uvv_val);
    if (out_p.is_valid()) out_p->copy_from_c(_out_p_val);
    if (out_d1u.is_valid()) out_d1u->copy_from_c(_out_d1u_val);
    if (out_d1v.is_valid()) out_d1v->copy_from_c(_out_d1v_val);
    if (out_d2u.is_valid()) out_d2u->copy_from_c(_out_d2u_val);
    if (out_d2v.is_valid()) out_d2v->copy_from_c(_out_d2v_val);
    if (out_d2uv.is_valid()) out_d2uv->copy_from_c(_out_d2uv_val);
    if (out_d3u.is_valid()) out_d3u->copy_from_c(_out_d3u_val);
    if (out_d3v.is_valid()) out_d3v->copy_from_c(_out_d3v_val);
    if (out_d3uuv.is_valid()) out_d3uuv->copy_from_c(_out_d3uuv_val);
    if (out_d3uvv.is_valid()) out_d3uvv->copy_from_c(_out_d3uvv_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_face_eval_dn(const Ref<OcctlGraphHandle>& graph, int64_t face, double u, double v, int nu, int nv, const Ref<OcctlVector3>& out_dn) { // NOLINT
    occtl_vector3_t _out_dn_val = {};
    occtl_status_t _status = ::occtl_topo_face_eval_dn(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, u, v, nu, nv, &_out_dn_val);
    if (out_dn.is_valid()) out_dn->copy_from_c(_out_dn_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_face_has_surface(const Ref<OcctlGraphHandle>& graph, int64_t face, const Ref<OcctlInt32>& out_has_surface) { // NOLINT
    int32_t _out_has_surface_val = {};
    occtl_status_t _status = ::occtl_topo_face_has_surface(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, &_out_has_surface_val);
    if (out_has_surface.is_valid()) out_has_surface->copy_from_c(_out_has_surface_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_face_surface_kind(const Ref<OcctlGraphHandle>& graph, int64_t face, const Ref<OcctlInt32>& out_kind) { // NOLINT
    occtl_surface_kind_t _out_kind_val = {};
    occtl_status_t _status = ::occtl_topo_face_surface_kind(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, &_out_kind_val);
    if (out_kind.is_valid()) out_kind->copy_from_c(_out_kind_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_wire_is_closed(const Ref<OcctlGraphHandle>& graph, int64_t wire, const Ref<OcctlInt32>& out_is_closed) { // NOLINT
    int32_t _out_is_closed_val = {};
    occtl_status_t _status = ::occtl_topo_wire_is_closed(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(wire)}, &_out_is_closed_val);
    if (out_is_closed.is_valid()) out_is_closed->copy_from_c(_out_is_closed_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_wire_coedge_count(const Ref<OcctlGraphHandle>& graph, int64_t wire, const Ref<OcctlUint32>& out_count) { // NOLINT
    uint32_t _out_count_val = {};
    occtl_status_t _status = ::occtl_topo_wire_coedge_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(wire)}, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_shell_is_closed(const Ref<OcctlGraphHandle>& graph, int64_t shell, const Ref<OcctlInt32>& out_is_closed) { // NOLINT
    int32_t _out_is_closed_val = {};
    occtl_status_t _status = ::occtl_topo_shell_is_closed(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(shell)}, &_out_is_closed_val);
    if (out_is_closed.is_valid()) out_is_closed->copy_from_c(_out_is_closed_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_shell_face_count(const Ref<OcctlGraphHandle>& graph, int64_t shell, const Ref<OcctlUint32>& out_count) { // NOLINT
    uint32_t _out_count_val = {};
    occtl_status_t _status = ::occtl_topo_shell_face_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(shell)}, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_vertex_parameter(const Ref<OcctlGraphHandle>& graph, int64_t vertex, int64_t edge, const Ref<OcctlDouble>& out_parameter) { // NOLINT
    double _out_parameter_val = {};
    occtl_status_t _status = ::occtl_topo_vertex_parameter(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(vertex)}, occtl_node_id_t{static_cast<uint64_t>(edge)}, &_out_parameter_val);
    if (out_parameter.is_valid()) out_parameter->copy_from_c(_out_parameter_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_vertex_parameters(const Ref<OcctlGraphHandle>& graph, int64_t vertex, int64_t face, const Ref<OcctlPoint2>& out_uv) { // NOLINT
    occtl_point2_t _out_uv_val = {};
    occtl_status_t _status = ::occtl_topo_vertex_parameters(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(vertex)}, occtl_node_id_t{static_cast<uint64_t>(face)}, &_out_uv_val);
    if (out_uv.is_valid()) out_uv->copy_from_c(_out_uv_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_edge_same_parameter(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlInt32>& out_has_same_parameter) { // NOLINT
    int32_t _out_has_same_parameter_val = {};
    occtl_status_t _status = ::occtl_topo_edge_same_parameter(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, &_out_has_same_parameter_val);
    if (out_has_same_parameter.is_valid()) out_has_same_parameter->copy_from_c(_out_has_same_parameter_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_edge_same_range(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlInt32>& out_has_same_range) { // NOLINT
    int32_t _out_has_same_range_val = {};
    occtl_status_t _status = ::occtl_topo_edge_same_range(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, &_out_has_same_range_val);
    if (out_has_same_range.is_valid()) out_has_same_range->copy_from_c(_out_has_same_range_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_edge_is_manifold(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlInt32>& out_is_manifold) { // NOLINT
    int32_t _out_is_manifold_val = {};
    occtl_status_t _status = ::occtl_topo_edge_is_manifold(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, &_out_is_manifold_val);
    if (out_is_manifold.is_valid()) out_is_manifold->copy_from_c(_out_is_manifold_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_edge_is_boundary(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlInt32>& out_is_boundary) { // NOLINT
    int32_t _out_is_boundary_val = {};
    occtl_status_t _status = ::occtl_topo_edge_is_boundary(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, &_out_is_boundary_val);
    if (out_is_boundary.is_valid()) out_is_boundary->copy_from_c(_out_is_boundary_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_edge_is_seam_on_face(const Ref<OcctlGraphHandle>& graph, int64_t edge, int64_t face, const Ref<OcctlInt32>& out_is_seam) { // NOLINT
    int32_t _out_is_seam_val = {};
    occtl_status_t _status = ::occtl_topo_edge_is_seam_on_face(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, occtl_node_id_t{static_cast<uint64_t>(face)}, &_out_is_seam_val);
    if (out_is_seam.is_valid()) out_is_seam->copy_from_c(_out_is_seam_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_edge_face_count(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlUint32>& out_count) { // NOLINT
    uint32_t _out_count_val = {};
    occtl_status_t _status = ::occtl_topo_edge_face_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_coedge_is_reversed(const Ref<OcctlGraphHandle>& graph, int64_t coedge, const Ref<OcctlInt32>& out_is_reversed) { // NOLINT
    int32_t _out_is_reversed_val = {};
    occtl_status_t _status = ::occtl_topo_coedge_is_reversed(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(coedge)}, &_out_is_reversed_val);
    if (out_is_reversed.is_valid()) out_is_reversed->copy_from_c(_out_is_reversed_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_coedge_has_pcurve(const Ref<OcctlGraphHandle>& graph, int64_t coedge, const Ref<OcctlInt32>& out_has_pcurve) { // NOLINT
    int32_t _out_has_pcurve_val = {};
    occtl_status_t _status = ::occtl_topo_coedge_has_pcurve(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(coedge)}, &_out_has_pcurve_val);
    if (out_has_pcurve.is_valid()) out_has_pcurve->copy_from_c(_out_has_pcurve_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_coedge_pcurve_parameter(const Ref<OcctlGraphHandle>& graph, int64_t coedge, int64_t vertex, const Ref<OcctlDouble>& out_parameter) { // NOLINT
    double _out_parameter_val = {};
    occtl_status_t _status = ::occtl_topo_coedge_pcurve_parameter(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(coedge)}, occtl_node_id_t{static_cast<uint64_t>(vertex)}, &_out_parameter_val);
    if (out_parameter.is_valid()) out_parameter->copy_from_c(_out_parameter_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_coedge_range(const Ref<OcctlGraphHandle>& graph, int64_t coedge, const Ref<OcctlDouble>& out_first, const Ref<OcctlDouble>& out_last) { // NOLINT
    double _out_first_val = {};
    double _out_last_val = {};
    occtl_status_t _status = ::occtl_topo_coedge_range(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(coedge)}, &_out_first_val, &_out_last_val);
    if (out_first.is_valid()) out_first->copy_from_c(_out_first_val);
    if (out_last.is_valid()) out_last->copy_from_c(_out_last_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_coedge_uv_points(const Ref<OcctlGraphHandle>& graph, int64_t coedge, const Ref<OcctlPoint2>& out_uv_start, const Ref<OcctlPoint2>& out_uv_end) { // NOLINT
    occtl_point2_t _out_uv_start_val = {};
    occtl_point2_t _out_uv_end_val = {};
    occtl_status_t _status = ::occtl_topo_coedge_uv_points(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(coedge)}, &_out_uv_start_val, &_out_uv_end_val);
    if (out_uv_start.is_valid()) out_uv_start->copy_from_c(_out_uv_start_val);
    if (out_uv_end.is_valid()) out_uv_end->copy_from_c(_out_uv_end_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_coedge_seam_pair(const Ref<OcctlGraphHandle>& graph, int64_t coedge, const Ref<OcctlNodeId>& out_pair) { // NOLINT
    occtl_node_id_t _out_pair_val = {};
    occtl_status_t _status = ::occtl_topo_coedge_seam_pair(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(coedge)}, &_out_pair_val);
    if (out_pair.is_valid()) out_pair->copy_from_c(_out_pair_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_face_natural_restriction(const Ref<OcctlGraphHandle>& graph, int64_t face, const Ref<OcctlInt32>& out_has_natural_restriction) { // NOLINT
    int32_t _out_has_natural_restriction_val = {};
    occtl_status_t _status = ::occtl_topo_face_natural_restriction(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, &_out_has_natural_restriction_val);
    if (out_has_natural_restriction.is_valid()) out_has_natural_restriction->copy_from_c(_out_has_natural_restriction_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_face_has_triangulation(const Ref<OcctlGraphHandle>& graph, int64_t face, const Ref<OcctlInt32>& out_has_triangulation) { // NOLINT
    int32_t _out_has_triangulation_val = {};
    occtl_status_t _status = ::occtl_topo_face_has_triangulation(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, &_out_has_triangulation_val);
    if (out_has_triangulation.is_valid()) out_has_triangulation->copy_from_c(_out_has_triangulation_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_wire_distinct_edge_count(const Ref<OcctlGraphHandle>& graph, int64_t wire, const Ref<OcctlUint32>& out_count) { // NOLINT
    uint32_t _out_count_val = {};
    occtl_status_t _status = ::occtl_topo_wire_distinct_edge_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(wire)}, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_wire_face_of(const Ref<OcctlGraphHandle>& graph, int64_t wire, const Ref<OcctlNodeId>& out_face) { // NOLINT
    occtl_node_id_t _out_face_val = {};
    occtl_status_t _status = ::occtl_topo_wire_face_of(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(wire)}, &_out_face_val);
    if (out_face.is_valid()) out_face->copy_from_c(_out_face_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_wire_is_outer(const Ref<OcctlGraphHandle>& graph, int64_t wire, const Ref<OcctlInt32>& out_is_outer) { // NOLINT
    int32_t _out_is_outer_val = {};
    occtl_status_t _status = ::occtl_topo_wire_is_outer(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(wire)}, &_out_is_outer_val);
    if (out_is_outer.is_valid()) out_is_outer->copy_from_c(_out_is_outer_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_solid_shell_count(const Ref<OcctlGraphHandle>& graph, int64_t solid, const Ref<OcctlUint32>& out_count) { // NOLINT
    uint32_t _out_count_val = {};
    occtl_status_t _status = ::occtl_topo_solid_shell_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(solid)}, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_wire_edge_count(const Ref<OcctlGraphHandle>& graph, int64_t wire, const Ref<OcctlUint32>& out_count) { // NOLINT
    uint32_t _out_count_val = {};
    occtl_status_t _status = ::occtl_topo_wire_edge_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(wire)}, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_edge_vertex_count(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlUint32>& out_count) { // NOLINT
    uint32_t _out_count_val = {};
    occtl_status_t _status = ::occtl_topo_edge_vertex_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_compound_child_count(const Ref<OcctlGraphHandle>& graph, int64_t compound, const Ref<OcctlUint32>& out_count) { // NOLINT
    uint32_t _out_count_val = {};
    occtl_status_t _status = ::occtl_topo_compound_child_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(compound)}, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_compsolid_solid_count(const Ref<OcctlGraphHandle>& graph, int64_t compsolid, const Ref<OcctlUint32>& out_count) { // NOLINT
    uint32_t _out_count_val = {};
    occtl_status_t _status = ::occtl_topo_compsolid_solid_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(compsolid)}, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_product_occurrence_count(const Ref<OcctlGraphHandle>& graph, int64_t product, const Ref<OcctlUint32>& out_count) { // NOLINT
    uint32_t _out_count_val = {};
    occtl_status_t _status = ::occtl_topo_product_occurrence_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(product)}, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlTopo::node_iter_next(const Ref<OcctlNodeIterHandle>& iter, const Ref<OcctlNodeId>& out_id) { // NOLINT
    occtl_node_id_t _out_id_val = {};
    occtl_status_t _status = ::occtl_node_iter_next(reinterpret_cast<occtl_node_iter_t*>(static_cast<uintptr_t>(iter.is_valid() ? iter->get_handle() : 0)), &_out_id_val);
    if (out_id.is_valid()) out_id->copy_from_c(_out_id_val);
    return static_cast<int>(_status);
}

void OcctlTopo::node_iter_free(const Ref<OcctlNodeIterHandle>& iter) { // NOLINT
    ::occtl_node_iter_free(reinterpret_cast<occtl_node_iter_t*>(static_cast<uintptr_t>(iter.is_valid() ? iter->release() : 0)));
}

Ref<OcctlNodeIterHandle> OcctlTopo::graph_solid_iter_create(const Ref<OcctlGraphHandle>& graph) { // NOLINT
    occtl_node_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_graph_solid_iter_create(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlNodeIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlNodeIterHandle>(); }
    Ref<OcctlNodeIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

Ref<OcctlNodeIterHandle> OcctlTopo::graph_shell_iter_create(const Ref<OcctlGraphHandle>& graph) { // NOLINT
    occtl_node_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_graph_shell_iter_create(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlNodeIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlNodeIterHandle>(); }
    Ref<OcctlNodeIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

Ref<OcctlNodeIterHandle> OcctlTopo::graph_face_iter_create(const Ref<OcctlGraphHandle>& graph) { // NOLINT
    occtl_node_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_graph_face_iter_create(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlNodeIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlNodeIterHandle>(); }
    Ref<OcctlNodeIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

Ref<OcctlNodeIterHandle> OcctlTopo::graph_wire_iter_create(const Ref<OcctlGraphHandle>& graph) { // NOLINT
    occtl_node_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_graph_wire_iter_create(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlNodeIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlNodeIterHandle>(); }
    Ref<OcctlNodeIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

Ref<OcctlNodeIterHandle> OcctlTopo::graph_edge_iter_create(const Ref<OcctlGraphHandle>& graph) { // NOLINT
    occtl_node_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_graph_edge_iter_create(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlNodeIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlNodeIterHandle>(); }
    Ref<OcctlNodeIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

Ref<OcctlNodeIterHandle> OcctlTopo::graph_vertex_iter_create(const Ref<OcctlGraphHandle>& graph) { // NOLINT
    occtl_node_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_graph_vertex_iter_create(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlNodeIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlNodeIterHandle>(); }
    Ref<OcctlNodeIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

Ref<OcctlNodeIterHandle> OcctlTopo::graph_compound_iter_create(const Ref<OcctlGraphHandle>& graph) { // NOLINT
    occtl_node_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_graph_compound_iter_create(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlNodeIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlNodeIterHandle>(); }
    Ref<OcctlNodeIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

Ref<OcctlNodeIterHandle> OcctlTopo::graph_compsolid_iter_create(const Ref<OcctlGraphHandle>& graph) { // NOLINT
    occtl_node_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_graph_compsolid_iter_create(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlNodeIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlNodeIterHandle>(); }
    Ref<OcctlNodeIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

Ref<OcctlNodeIterHandle> OcctlTopo::graph_coedge_iter_create(const Ref<OcctlGraphHandle>& graph) { // NOLINT
    occtl_node_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_graph_coedge_iter_create(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlNodeIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlNodeIterHandle>(); }
    Ref<OcctlNodeIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

Ref<OcctlNodeIterHandle> OcctlTopo::graph_product_iter_create(const Ref<OcctlGraphHandle>& graph) { // NOLINT
    occtl_node_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_graph_product_iter_create(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlNodeIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlNodeIterHandle>(); }
    Ref<OcctlNodeIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

Ref<OcctlNodeIterHandle> OcctlTopo::graph_occurrence_iter_create(const Ref<OcctlGraphHandle>& graph) { // NOLINT
    occtl_node_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_graph_occurrence_iter_create(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlNodeIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlNodeIterHandle>(); }
    Ref<OcctlNodeIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

Ref<OcctlNodeIterHandle> OcctlTopo::graph_root_product_iter_create(const Ref<OcctlGraphHandle>& graph) { // NOLINT
    occtl_node_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_graph_root_product_iter_create(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlNodeIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlNodeIterHandle>(); }
    Ref<OcctlNodeIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

Ref<OcctlNodeIterHandle> OcctlTopo::topo_shells_of_solid_iter_create(const Ref<OcctlGraphHandle>& graph, int64_t solid) { // NOLINT
    occtl_node_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_topo_shells_of_solid_iter_create(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(solid)}, &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlNodeIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlNodeIterHandle>(); }
    Ref<OcctlNodeIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

Ref<OcctlNodeIterHandle> OcctlTopo::topo_faces_of_shell_iter_create(const Ref<OcctlGraphHandle>& graph, int64_t shell) { // NOLINT
    occtl_node_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_topo_faces_of_shell_iter_create(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(shell)}, &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlNodeIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlNodeIterHandle>(); }
    Ref<OcctlNodeIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

Ref<OcctlNodeIterHandle> OcctlTopo::topo_wires_of_face_iter_create(const Ref<OcctlGraphHandle>& graph, int64_t face) { // NOLINT
    occtl_node_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_topo_wires_of_face_iter_create(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlNodeIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlNodeIterHandle>(); }
    Ref<OcctlNodeIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

Ref<OcctlNodeIterHandle> OcctlTopo::topo_coedges_of_wire_iter_create(const Ref<OcctlGraphHandle>& graph, int64_t wire) { // NOLINT
    occtl_node_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_topo_coedges_of_wire_iter_create(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(wire)}, &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlNodeIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlNodeIterHandle>(); }
    Ref<OcctlNodeIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

Ref<OcctlNodeIterHandle> OcctlTopo::topo_edges_of_wire_iter_create(const Ref<OcctlGraphHandle>& graph, int64_t wire) { // NOLINT
    occtl_node_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_topo_edges_of_wire_iter_create(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(wire)}, &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlNodeIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlNodeIterHandle>(); }
    Ref<OcctlNodeIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

Ref<OcctlNodeIterHandle> OcctlTopo::topo_wire_explorer_create(const Ref<OcctlGraphHandle>& graph, int64_t wire) { // NOLINT
    occtl_node_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_topo_wire_explorer_create(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(wire)}, &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlNodeIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlNodeIterHandle>(); }
    Ref<OcctlNodeIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

Ref<OcctlNodeIterHandle> OcctlTopo::topo_occurrences_of_product_iter_create(const Ref<OcctlGraphHandle>& graph, int64_t product) { // NOLINT
    occtl_node_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_topo_occurrences_of_product_iter_create(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(product)}, &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlNodeIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlNodeIterHandle>(); }
    Ref<OcctlNodeIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

Ref<OcctlNodeIterHandle> OcctlTopo::topo_vertices_of_edge_iter_create(const Ref<OcctlGraphHandle>& graph, int64_t edge) { // NOLINT
    occtl_node_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_topo_vertices_of_edge_iter_create(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlNodeIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlNodeIterHandle>(); }
    Ref<OcctlNodeIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

int OcctlTopo::graph_for_each(const Ref<OcctlGraphHandle>& graph, int64_t kind_mask, const Callable& callable) { // NOLINT
    _CallbackContext _ctx;
    _ctx.callable = callable;
    occtl_status_t _status = ::occtl_graph_for_each(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), kind_mask, _occtl_node_visitor_bridge, &_ctx);
    return static_cast<int>(_status);
}

int OcctlTopo::graph_for_each_ref(const Ref<OcctlGraphHandle>& graph, int64_t ref_kind_mask, const Callable& callable) { // NOLINT
    _CallbackContext _ctx;
    _ctx.callable = callable;
    occtl_status_t _status = ::occtl_graph_for_each_ref(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), ref_kind_mask, _occtl_ref_visitor_bridge, &_ctx);
    return static_cast<int>(_status);
}

int OcctlTopo::graph_for_each_rep(const Ref<OcctlGraphHandle>& graph, int64_t rep_kind_mask, const Callable& callable) { // NOLINT
    _CallbackContext _ctx;
    _ctx.callable = callable;
    occtl_status_t _status = ::occtl_graph_for_each_rep(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), rep_kind_mask, _occtl_rep_visitor_bridge, &_ctx);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_for_each_related(const Ref<OcctlGraphHandle>& graph, int64_t node, const Callable& callable) { // NOLINT
    _CallbackContext _ctx;
    _ctx.callable = callable;
    occtl_status_t _status = ::occtl_topo_for_each_related(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node)}, _occtl_node_visitor_bridge, &_ctx);
    return static_cast<int>(_status);
}

int OcctlTopo::graph_color_set(const Ref<OcctlGraphHandle>& graph, int64_t target, const Ref<OcctlColorRgba>& color) { // NOLINT
    occtl_status_t _status = ::occtl_graph_color_set(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(target)}, color->to_c());
    return static_cast<int>(_status);
}

int OcctlTopo::graph_color_get(const Ref<OcctlGraphHandle>& graph, int64_t target, const Ref<OcctlColorRgba>& out_color) { // NOLINT
    occtl_color_rgba_t _out_color_val = {};
    occtl_status_t _status = ::occtl_graph_color_get(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(target)}, &_out_color_val);
    if (out_color.is_valid()) out_color->copy_from_c(_out_color_val);
    return static_cast<int>(_status);
}

Dictionary OcctlTopo::graph_color_entries(const Ref<OcctlGraphHandle>& graph) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_graph_color_entries(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), nullptr, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return Dictionary(); }
    std::vector<occtl_node_id_t> _out_nodes_buf(_out_count_cnt);
    std::vector<occtl_color_rgba_t> _out_colors_buf(static_cast<size_t>(_out_count_cnt));
    _err = ::occtl_graph_color_entries(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _out_nodes_buf.data(), _out_colors_buf.data(), _out_count_cnt, &_out_count_cnt);
    Dictionary _result;
    PackedInt64Array _nodes;
    _nodes.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _nodes[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_nodes_buf[_i].bits);
    _result["nodes"] = _nodes;
    Array _colors;
    _colors.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) {
        Ref<OcctlColorRgba> _item;
        _item.instantiate();
        _item->copy_from_c(_out_colors_buf[_i]);
        _colors[static_cast<int64_t>(_i)] = _item;
    }
    _result["colors"] = _colors;
    return _result;
}

int OcctlTopo::graph_color_unset(const Ref<OcctlGraphHandle>& graph, int64_t target) { // NOLINT
    occtl_status_t _status = ::occtl_graph_color_unset(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(target)});
    return static_cast<int>(_status);
}

int OcctlTopo::graph_name_set(const Ref<OcctlGraphHandle>& graph, int64_t target, const String& name) { // NOLINT
    occtl_status_t _status = ::occtl_graph_name_set(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(target)}, name.utf8().get_data(), static_cast<size_t>(name.utf8().length()));
    return static_cast<int>(_status);
}

String OcctlTopo::graph_name_get(const Ref<OcctlGraphHandle>& graph, int64_t target) { // NOLINT
    size_t _out_required_cnt = 0;
    occtl_status_t _err = ::occtl_graph_name_get(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(target)}, nullptr, 0, &_out_required_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return String(); }
    std::vector<char> _buf_buf(_out_required_cnt + 1);
    _err = ::occtl_graph_name_get(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(target)}, _buf_buf.data(), _out_required_cnt, &_out_required_cnt);
    return godot::String(_buf_buf.data());
}

PackedInt64Array OcctlTopo::graph_name_nodes(const Ref<OcctlGraphHandle>& graph) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_graph_name_nodes(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt64Array(); }
    std::vector<occtl_node_id_t> _out_nodes_buf(_out_count_cnt);
    _err = ::occtl_graph_name_nodes(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _out_nodes_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_nodes_buf[_i].bits);
    return _result;
}

int OcctlTopo::graph_material_set(const Ref<OcctlGraphHandle>& graph, int64_t target, const Ref<OcctlMaterialInfo>& info) { // NOLINT
    occtl_material_info_t _info_c = {};
    const occtl_material_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_status_t _status = ::occtl_graph_material_set(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(target)}, _info_ptr);
    return static_cast<int>(_status);
}

String OcctlTopo::graph_material_get(const Ref<OcctlGraphHandle>& graph, int64_t target, const Ref<OcctlMaterialInfo>& out_info) { // NOLINT
    size_t _out_name_required_cnt = 0;
    occtl_material_info_t _out_info_val = {};
    occtl_status_t _err = ::occtl_graph_material_get(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(target)}, &_out_info_val, nullptr, 0, &_out_name_required_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return String(); }
    std::vector<char> _name_buf_buf(_out_name_required_cnt + 1);
    _err = ::occtl_graph_material_get(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(target)}, &_out_info_val, _name_buf_buf.data(), _out_name_required_cnt, &_out_name_required_cnt);
    if (out_info.is_valid()) out_info->copy_from_c(_out_info_val);
    return godot::String(_name_buf_buf.data());
}

PackedInt64Array OcctlTopo::graph_material_nodes(const Ref<OcctlGraphHandle>& graph) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_graph_material_nodes(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt64Array(); }
    std::vector<occtl_node_id_t> _out_nodes_buf(_out_count_cnt);
    _err = ::occtl_graph_material_nodes(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _out_nodes_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_nodes_buf[_i].bits);
    return _result;
}

int OcctlTopo::graph_material_unset(const Ref<OcctlGraphHandle>& graph, int64_t target) { // NOLINT
    occtl_status_t _status = ::occtl_graph_material_unset(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(target)});
    return static_cast<int>(_status);
}

int OcctlTopo::graph_units_set(const Ref<OcctlGraphHandle>& graph, double length_unit_to_meter, const String& name) { // NOLINT
    occtl_status_t _status = ::occtl_graph_units_set(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), length_unit_to_meter, name.utf8().get_data(), static_cast<size_t>(name.utf8().length()));
    return static_cast<int>(_status);
}

String OcctlTopo::graph_units_get(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlDouble>& out_length_unit_to_meter) { // NOLINT
    size_t _out_name_required_cnt = 0;
    double _out_length_unit_to_meter_val = {};
    occtl_status_t _err = ::occtl_graph_units_get(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_length_unit_to_meter_val, nullptr, 0, &_out_name_required_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return String(); }
    std::vector<char> _name_buf_buf(_out_name_required_cnt + 1);
    _err = ::occtl_graph_units_get(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), &_out_length_unit_to_meter_val, _name_buf_buf.data(), _out_name_required_cnt, &_out_name_required_cnt);
    if (out_length_unit_to_meter.is_valid()) out_length_unit_to_meter->copy_from_c(_out_length_unit_to_meter_val);
    return godot::String(_name_buf_buf.data());
}

int OcctlTopo::graph_node_metadata_set(const Ref<OcctlGraphHandle>& graph, int64_t target, const String& key, const String& value) { // NOLINT
    occtl_status_t _status = ::occtl_graph_node_metadata_set(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(target)}, key.utf8().get_data(), static_cast<size_t>(key.utf8().length()), value.utf8().get_data(), static_cast<size_t>(value.utf8().length()));
    return static_cast<int>(_status);
}

String OcctlTopo::graph_node_metadata_get(const Ref<OcctlGraphHandle>& graph, int64_t target, const String& key) { // NOLINT
    size_t _out_required_cnt = 0;
    godot::CharString _key_cs = key.utf8();
    occtl_status_t _err = ::occtl_graph_node_metadata_get(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(target)}, _key_cs.get_data(), static_cast<size_t>(key.utf8().length()), nullptr, 0, &_out_required_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return String(); }
    std::vector<char> _buf_buf(_out_required_cnt + 1);
    _err = ::occtl_graph_node_metadata_get(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(target)}, _key_cs.get_data(), static_cast<size_t>(key.utf8().length()), _buf_buf.data(), _out_required_cnt, &_out_required_cnt);
    return godot::String(_buf_buf.data());
}

Array OcctlTopo::graph_node_metadata_keys(const Ref<OcctlGraphHandle>& graph, int64_t target) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_graph_node_metadata_keys(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(target)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return Array(); }
    std::vector<occtl_metadata_key_view_t> _out_keys_buf(static_cast<size_t>(_out_count_cnt));
    _err = ::occtl_graph_node_metadata_keys(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(target)}, _out_keys_buf.data(), _out_count_cnt, &_out_count_cnt);
    Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) {
        Ref<OcctlMetadataKeyView> _item;
        _item.instantiate();
        _item->copy_from_c(_out_keys_buf[_i]);
        _result[static_cast<int64_t>(_i)] = _item;
    }
    return _result;
}

PackedInt64Array OcctlTopo::graph_node_metadata_nodes(const Ref<OcctlGraphHandle>& graph) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_graph_node_metadata_nodes(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt64Array(); }
    std::vector<occtl_node_id_t> _out_nodes_buf(_out_count_cnt);
    _err = ::occtl_graph_node_metadata_nodes(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _out_nodes_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_nodes_buf[_i].bits);
    return _result;
}

int OcctlTopo::graph_metadata_set(const Ref<OcctlGraphHandle>& graph, const String& key, const String& value) { // NOLINT
    occtl_status_t _status = ::occtl_graph_metadata_set(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), key.utf8().get_data(), static_cast<size_t>(key.utf8().length()), value.utf8().get_data(), static_cast<size_t>(value.utf8().length()));
    return static_cast<int>(_status);
}

String OcctlTopo::graph_metadata_get(const Ref<OcctlGraphHandle>& graph, const String& key) { // NOLINT
    size_t _out_required_cnt = 0;
    godot::CharString _key_cs = key.utf8();
    occtl_status_t _err = ::occtl_graph_metadata_get(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _key_cs.get_data(), static_cast<size_t>(key.utf8().length()), nullptr, 0, &_out_required_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return String(); }
    std::vector<char> _buf_buf(_out_required_cnt + 1);
    _err = ::occtl_graph_metadata_get(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _key_cs.get_data(), static_cast<size_t>(key.utf8().length()), _buf_buf.data(), _out_required_cnt, &_out_required_cnt);
    return godot::String(_buf_buf.data());
}

Array OcctlTopo::graph_metadata_keys(const Ref<OcctlGraphHandle>& graph) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_graph_metadata_keys(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return Array(); }
    std::vector<occtl_metadata_key_view_t> _out_keys_buf(static_cast<size_t>(_out_count_cnt));
    _err = ::occtl_graph_metadata_keys(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _out_keys_buf.data(), _out_count_cnt, &_out_count_cnt);
    Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) {
        Ref<OcctlMetadataKeyView> _item;
        _item.instantiate();
        _item->copy_from_c(_out_keys_buf[_i]);
        _result[static_cast<int64_t>(_i)] = _item;
    }
    return _result;
}

int OcctlTopo::graph_metadata_unset(const Ref<OcctlGraphHandle>& graph, const String& key) { // NOLINT
    occtl_status_t _status = ::occtl_graph_metadata_unset(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), key.utf8().get_data(), static_cast<size_t>(key.utf8().length()));
    return static_cast<int>(_status);
}

int OcctlTopo::graph_node_metadata_unset(const Ref<OcctlGraphHandle>& graph, int64_t target, const String& key) { // NOLINT
    occtl_status_t _status = ::occtl_graph_node_metadata_unset(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(target)}, key.utf8().get_data(), static_cast<size_t>(key.utf8().length()));
    return static_cast<int>(_status);
}

int OcctlTopo::graph_tag_add(const Ref<OcctlGraphHandle>& graph, int64_t target, const String& tag) { // NOLINT
    occtl_status_t _status = ::occtl_graph_tag_add(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(target)}, tag.utf8().get_data(), static_cast<size_t>(tag.utf8().length()));
    return static_cast<int>(_status);
}

int OcctlTopo::graph_tag_remove(const Ref<OcctlGraphHandle>& graph, int64_t target, const String& tag) { // NOLINT
    occtl_status_t _status = ::occtl_graph_tag_remove(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(target)}, tag.utf8().get_data(), static_cast<size_t>(tag.utf8().length()));
    return static_cast<int>(_status);
}

int OcctlTopo::graph_tag_has(const Ref<OcctlGraphHandle>& graph, int64_t target, const String& tag, const Ref<OcctlInt32>& out_has_tag) { // NOLINT
    int32_t _out_has_tag_val = {};
    occtl_status_t _status = ::occtl_graph_tag_has(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(target)}, tag.utf8().get_data(), static_cast<size_t>(tag.utf8().length()), &_out_has_tag_val);
    if (out_has_tag.is_valid()) out_has_tag->copy_from_c(_out_has_tag_val);
    return static_cast<int>(_status);
}

Array OcctlTopo::graph_tag_list(const Ref<OcctlGraphHandle>& graph, int64_t target) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_graph_tag_list(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(target)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return Array(); }
    std::vector<occtl_tag_view_t> _out_tags_buf(static_cast<size_t>(_out_count_cnt));
    _err = ::occtl_graph_tag_list(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(target)}, _out_tags_buf.data(), _out_count_cnt, &_out_count_cnt);
    Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) {
        Ref<OcctlTagView> _item;
        _item.instantiate();
        _item->copy_from_c(_out_tags_buf[_i]);
        _result[static_cast<int64_t>(_i)] = _item;
    }
    return _result;
}

PackedInt64Array OcctlTopo::graph_tag_nodes(const Ref<OcctlGraphHandle>& graph, const String& tag) { // NOLINT
    size_t _out_count_cnt = 0;
    godot::CharString _tag_cs = tag.utf8();
    occtl_status_t _err = ::occtl_graph_tag_nodes(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _tag_cs.get_data(), static_cast<size_t>(tag.utf8().length()), nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt64Array(); }
    std::vector<occtl_node_id_t> _out_nodes_buf(_out_count_cnt);
    _err = ::occtl_graph_tag_nodes(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _tag_cs.get_data(), static_cast<size_t>(tag.utf8().length()), _out_nodes_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_nodes_buf[_i].bits);
    return _result;
}

void OcctlTopo::joint_info_init(const Ref<OcctlJointInfo>& info) { // NOLINT
    occtl_joint_info_t _info_val = {};
    ::occtl_joint_info_init(&_info_val);
    ::occtl_joint_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlTopo::joint_create(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlJointInfo>& info, const Ref<OcctlJointId>& out_joint) { // NOLINT
    occtl_joint_info_t _info_c = {};
    const occtl_joint_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_joint_id_t _out_joint_val = {};
    occtl_status_t _status = ::occtl_joint_create(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_joint_val);
    if (out_joint.is_valid()) out_joint->copy_from_c(_out_joint_val);
    return static_cast<int>(_status);
}

int OcctlTopo::joint_get(const Ref<OcctlGraphHandle>& graph, int64_t joint, const Ref<OcctlJointInfo>& out_info) { // NOLINT
    occtl_joint_info_t _out_info_val = {};
    ::occtl_joint_info_init(&_out_info_val);
    occtl_status_t _status = ::occtl_joint_get(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_joint_id_t{static_cast<uint64_t>(joint)}, &_out_info_val);
    if (out_info.is_valid()) out_info->copy_from_c(_out_info_val);
    return static_cast<int>(_status);
}

int OcctlTopo::joint_remove(const Ref<OcctlGraphHandle>& graph, int64_t joint) { // NOLINT
    occtl_status_t _status = ::occtl_joint_remove(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_joint_id_t{static_cast<uint64_t>(joint)});
    return static_cast<int>(_status);
}

PackedInt64Array OcctlTopo::joint_list(const Ref<OcctlGraphHandle>& graph, int64_t node) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_joint_list(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt64Array(); }
    std::vector<occtl_joint_id_t> _out_joints_buf(_out_count_cnt);
    _err = ::occtl_joint_list(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node)}, _out_joints_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_joints_buf[_i].bits);
    return _result;
}

void OcctlTopo::topo_make_product_info_init(const Ref<OcctlTopoMakeProductInfo>& info) { // NOLINT
    occtl_topo_make_product_info_t _info_val = {};
    ::occtl_topo_make_product_info_init(&_info_val);
    ::occtl_topo_make_product_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlTopo::topo_make_product(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTopoMakeProductInfo>& info, const Ref<OcctlNodeId>& out_product) { // NOLINT
    occtl_topo_make_product_info_t _info_c = {};
    const occtl_topo_make_product_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_product_val = {};
    occtl_status_t _status = ::occtl_topo_make_product(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_product_val);
    if (out_product.is_valid()) out_product->copy_from_c(_out_product_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_link_product(const Ref<OcctlGraphHandle>& graph, int64_t product, int64_t root, const Ref<OcctlTransform>& placement) { // NOLINT
    occtl_status_t _status = ::occtl_topo_link_product(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(product)}, occtl_node_id_t{static_cast<uint64_t>(root)}, placement->to_c());
    return static_cast<int>(_status);
}

int OcctlTopo::topo_link_product_occurrence(const Ref<OcctlGraphHandle>& graph, int64_t product, int64_t root, const Ref<OcctlTransform>& placement, const Ref<OcctlNodeId>& out_occurrence) { // NOLINT
    occtl_node_id_t _out_occurrence_val = {};
    occtl_status_t _status = ::occtl_topo_link_product_occurrence(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(product)}, occtl_node_id_t{static_cast<uint64_t>(root)}, placement->to_c(), &_out_occurrence_val);
    if (out_occurrence.is_valid()) out_occurrence->copy_from_c(_out_occurrence_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_link_products(const Ref<OcctlGraphHandle>& graph, int64_t parentProduct, int64_t childProduct, const Ref<OcctlTransform>& placement, int64_t parentOccurrence) { // NOLINT
    occtl_status_t _status = ::occtl_topo_link_products(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(parentProduct)}, occtl_node_id_t{static_cast<uint64_t>(childProduct)}, placement->to_c(), occtl_node_id_t{static_cast<uint64_t>(parentOccurrence)});
    return static_cast<int>(_status);
}

int OcctlTopo::topo_link_products_occurrence(const Ref<OcctlGraphHandle>& graph, int64_t parentProduct, int64_t childProduct, const Ref<OcctlTransform>& placement, int64_t parentOccurrence, const Ref<OcctlNodeId>& out_occurrence) { // NOLINT
    occtl_node_id_t _out_occurrence_val = {};
    occtl_status_t _status = ::occtl_topo_link_products_occurrence(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(parentProduct)}, occtl_node_id_t{static_cast<uint64_t>(childProduct)}, placement->to_c(), occtl_node_id_t{static_cast<uint64_t>(parentOccurrence)}, &_out_occurrence_val);
    if (out_occurrence.is_valid()) out_occurrence->copy_from_c(_out_occurrence_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_remove_occurrence(const Ref<OcctlGraphHandle>& graph, int64_t occurrence_ref) { // NOLINT
    occtl_status_t _status = ::occtl_topo_remove_occurrence(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_ref_id_t{static_cast<uint64_t>(occurrence_ref)});
    return static_cast<int>(_status);
}

int OcctlTopo::topo_occurrence_set_transform(const Ref<OcctlGraphHandle>& graph, int64_t occurrence, const Ref<OcctlTransform>& transform) { // NOLINT
    occtl_status_t _status = ::occtl_topo_occurrence_set_transform(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(occurrence)}, transform->to_c());
    return static_cast<int>(_status);
}

int OcctlTopo::topo_occurrence_transform(const Ref<OcctlGraphHandle>& graph, int64_t occurrence, const Ref<OcctlTransform>& out_transform) { // NOLINT
    occtl_transform_t _out_transform_val = {};
    occtl_status_t _status = ::occtl_topo_occurrence_transform(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(occurrence)}, &_out_transform_val);
    if (out_transform.is_valid()) out_transform->copy_from_c(_out_transform_val);
    return static_cast<int>(_status);
}

int OcctlTopo::topo_occurrence_world_transform(const Ref<OcctlGraphHandle>& graph, int64_t root, int64_t occurrence, const Ref<OcctlTransform>& out_transform) { // NOLINT
    occtl_transform_t _out_transform_val = {};
    occtl_status_t _status = ::occtl_topo_occurrence_world_transform(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(root)}, occtl_node_id_t{static_cast<uint64_t>(occurrence)}, &_out_transform_val);
    if (out_transform.is_valid()) out_transform->copy_from_c(_out_transform_val);
    return static_cast<int>(_status);
}

void OcctlTopo::edge_view_init(const Ref<OcctlEdgeView>& view) { // NOLINT
    occtl_edge_view_t _view_val = {};
    ::occtl_edge_view_init(&_view_val);
    ::occtl_edge_view_init(&_view_val);
    if (view.is_valid()) view->copy_from_c(_view_val);
}

int OcctlTopo::topo_edge_view(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlEdgeView>& view) { // NOLINT
    occtl_edge_view_t _view_val = {};
    ::occtl_edge_view_init(&_view_val);
    occtl_status_t _status = ::occtl_topo_edge_view(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, &_view_val);
    if (view.is_valid()) view->copy_from_c(_view_val);
    return static_cast<int>(_status);
}

void OcctlTopo::coedge_view_init(const Ref<OcctlCoedgeView>& view) { // NOLINT
    occtl_coedge_view_t _view_val = {};
    ::occtl_coedge_view_init(&_view_val);
    ::occtl_coedge_view_init(&_view_val);
    if (view.is_valid()) view->copy_from_c(_view_val);
}

int OcctlTopo::topo_coedge_view(const Ref<OcctlGraphHandle>& graph, int64_t coedge, const Ref<OcctlCoedgeView>& view) { // NOLINT
    occtl_coedge_view_t _view_val = {};
    ::occtl_coedge_view_init(&_view_val);
    occtl_status_t _status = ::occtl_topo_coedge_view(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(coedge)}, &_view_val);
    if (view.is_valid()) view->copy_from_c(_view_val);
    return static_cast<int>(_status);
}

void OcctlTopo::face_view_init(const Ref<OcctlFaceView>& view) { // NOLINT
    occtl_face_view_t _view_val = {};
    ::occtl_face_view_init(&_view_val);
    ::occtl_face_view_init(&_view_val);
    if (view.is_valid()) view->copy_from_c(_view_val);
}

int OcctlTopo::topo_face_view(const Ref<OcctlGraphHandle>& graph, int64_t face, const Ref<OcctlFaceView>& view) { // NOLINT
    occtl_face_view_t _view_val = {};
    ::occtl_face_view_init(&_view_val);
    occtl_status_t _status = ::occtl_topo_face_view(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, &_view_val);
    if (view.is_valid()) view->copy_from_c(_view_val);
    return static_cast<int>(_status);
}

void OcctlTopo::vertex_view_init(const Ref<OcctlVertexView>& view) { // NOLINT
    occtl_vertex_view_t _view_val = {};
    ::occtl_vertex_view_init(&_view_val);
    ::occtl_vertex_view_init(&_view_val);
    if (view.is_valid()) view->copy_from_c(_view_val);
}

int OcctlTopo::topo_vertex_view(const Ref<OcctlGraphHandle>& graph, int64_t vertex, const Ref<OcctlVertexView>& view) { // NOLINT
    occtl_vertex_view_t _view_val = {};
    ::occtl_vertex_view_init(&_view_val);
    occtl_status_t _status = ::occtl_topo_vertex_view(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(vertex)}, &_view_val);
    if (view.is_valid()) view->copy_from_c(_view_val);
    return static_cast<int>(_status);
}

void OcctlTopo::wire_view_init(const Ref<OcctlWireView>& view) { // NOLINT
    occtl_wire_view_t _view_val = {};
    ::occtl_wire_view_init(&_view_val);
    ::occtl_wire_view_init(&_view_val);
    if (view.is_valid()) view->copy_from_c(_view_val);
}

int OcctlTopo::topo_wire_view(const Ref<OcctlGraphHandle>& graph, int64_t wire, const Ref<OcctlWireView>& view) { // NOLINT
    occtl_wire_view_t _view_val = {};
    ::occtl_wire_view_init(&_view_val);
    occtl_status_t _status = ::occtl_topo_wire_view(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(wire)}, &_view_val);
    if (view.is_valid()) view->copy_from_c(_view_val);
    return static_cast<int>(_status);
}

void OcctlTopo::shell_view_init(const Ref<OcctlShellView>& view) { // NOLINT
    occtl_shell_view_t _view_val = {};
    ::occtl_shell_view_init(&_view_val);
    ::occtl_shell_view_init(&_view_val);
    if (view.is_valid()) view->copy_from_c(_view_val);
}

int OcctlTopo::topo_shell_view(const Ref<OcctlGraphHandle>& graph, int64_t shell, const Ref<OcctlShellView>& view) { // NOLINT
    occtl_shell_view_t _view_val = {};
    ::occtl_shell_view_init(&_view_val);
    occtl_status_t _status = ::occtl_topo_shell_view(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(shell)}, &_view_val);
    if (view.is_valid()) view->copy_from_c(_view_val);
    return static_cast<int>(_status);
}

void OcctlTopo::solid_view_init(const Ref<OcctlSolidView>& view) { // NOLINT
    occtl_solid_view_t _view_val = {};
    ::occtl_solid_view_init(&_view_val);
    ::occtl_solid_view_init(&_view_val);
    if (view.is_valid()) view->copy_from_c(_view_val);
}

int OcctlTopo::topo_solid_view(const Ref<OcctlGraphHandle>& graph, int64_t solid, const Ref<OcctlSolidView>& view) { // NOLINT
    occtl_solid_view_t _view_val = {};
    ::occtl_solid_view_init(&_view_val);
    occtl_status_t _status = ::occtl_topo_solid_view(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(solid)}, &_view_val);
    if (view.is_valid()) view->copy_from_c(_view_val);
    return static_cast<int>(_status);
}

void OcctlTopo::compound_view_init(const Ref<OcctlCompoundView>& view) { // NOLINT
    occtl_compound_view_t _view_val = {};
    ::occtl_compound_view_init(&_view_val);
    ::occtl_compound_view_init(&_view_val);
    if (view.is_valid()) view->copy_from_c(_view_val);
}

int OcctlTopo::topo_compound_view(const Ref<OcctlGraphHandle>& graph, int64_t compound, const Ref<OcctlCompoundView>& view) { // NOLINT
    occtl_compound_view_t _view_val = {};
    ::occtl_compound_view_init(&_view_val);
    occtl_status_t _status = ::occtl_topo_compound_view(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(compound)}, &_view_val);
    if (view.is_valid()) view->copy_from_c(_view_val);
    return static_cast<int>(_status);
}
