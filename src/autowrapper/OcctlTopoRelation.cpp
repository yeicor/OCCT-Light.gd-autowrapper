#include "OcctlTopoRelation.h"

#include "occtl/occtl_topo_relation.h"

#include <vector>

void OcctlTopoRelation::_bind_methods() {
    BIND_CONSTANT(OCCTL_TOPO_CHILD_EXPLORER_CONFIG_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_PARENT_EXPLORER_CONFIG_VERSION_1);
    BIND_CONSTANT(OCCTL_TOPO_RELATION_OPTIONS_VERSION_1);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_shape_continuity_t", "OCCTL_CONTINUITY_C0", OCCTL_CONTINUITY_C0);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_shape_continuity_t", "OCCTL_CONTINUITY_C1", OCCTL_CONTINUITY_C1);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_shape_continuity_t", "OCCTL_CONTINUITY_C2", OCCTL_CONTINUITY_C2);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_shape_continuity_t", "OCCTL_CONTINUITY_C3", OCCTL_CONTINUITY_C3);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_shape_continuity_t", "OCCTL_CONTINUITY_CN", OCCTL_CONTINUITY_CN);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_shape_continuity_t", "OCCTL_CONTINUITY_G1", OCCTL_CONTINUITY_G1);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_shape_continuity_t", "OCCTL_CONTINUITY_G2", OCCTL_CONTINUITY_G2);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_shape_continuity_t", "OCCTL_CONTINUITY_RESERVED_FUTURE", OCCTL_CONTINUITY_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_orientation_t", "OCCTL_ORIENTATION_FORWARD", OCCTL_ORIENTATION_FORWARD);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_orientation_t", "OCCTL_ORIENTATION_REVERSED", OCCTL_ORIENTATION_REVERSED);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_orientation_t", "OCCTL_ORIENTATION_INTERNAL", OCCTL_ORIENTATION_INTERNAL);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_orientation_t", "OCCTL_ORIENTATION_EXTERNAL", OCCTL_ORIENTATION_EXTERNAL);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_orientation_t", "OCCTL_ORIENTATION_RESERVED_FUTURE", OCCTL_ORIENTATION_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_explorer_traversal_t", "OCCTL_TOPO_EXPLORER_RECURSIVE", OCCTL_TOPO_EXPLORER_RECURSIVE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_explorer_traversal_t", "OCCTL_TOPO_EXPLORER_DIRECT_CHILDREN", OCCTL_TOPO_EXPLORER_DIRECT_CHILDREN);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_explorer_traversal_t", "OCCTL_TOPO_EXPLORER_TRAVERSAL_RESERVED_FUTURE", OCCTL_TOPO_EXPLORER_TRAVERSAL_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_relation_kind_t", "OCCTL_RELATION_BOUNDARY_EDGE", OCCTL_RELATION_BOUNDARY_EDGE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_relation_kind_t", "OCCTL_RELATION_ADJACENT_FACE", OCCTL_RELATION_ADJACENT_FACE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_relation_kind_t", "OCCTL_RELATION_OUTER_WIRE", OCCTL_RELATION_OUTER_WIRE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_relation_kind_t", "OCCTL_RELATION_REFERENCED_BY", OCCTL_RELATION_REFERENCED_BY);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_relation_kind_t", "OCCTL_RELATION_INCIDENT_VERTEX", OCCTL_RELATION_INCIDENT_VERTEX);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_relation_kind_t", "OCCTL_RELATION_WIRE_COEDGE", OCCTL_RELATION_WIRE_COEDGE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_relation_kind_t", "OCCTL_RELATION_OWNING_FACE", OCCTL_RELATION_OWNING_FACE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_relation_kind_t", "OCCTL_RELATION_INCIDENT_EDGE", OCCTL_RELATION_INCIDENT_EDGE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_relation_kind_t", "OCCTL_RELATION_PARENT_EDGE", OCCTL_RELATION_PARENT_EDGE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_relation_kind_t", "OCCTL_RELATION_SEAM_PAIR", OCCTL_RELATION_SEAM_PAIR);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_relation_kind_t", "OCCTL_RELATION_KIND_RESERVED_FUTURE", OCCTL_RELATION_KIND_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_point_class_t", "OCCTL_TOPO_POINT_CLASS_IN", OCCTL_TOPO_POINT_CLASS_IN);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_point_class_t", "OCCTL_TOPO_POINT_CLASS_OUT", OCCTL_TOPO_POINT_CLASS_OUT);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_point_class_t", "OCCTL_TOPO_POINT_CLASS_ON", OCCTL_TOPO_POINT_CLASS_ON);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_point_class_t", "OCCTL_TOPO_POINT_CLASS_UNKNOWN", OCCTL_TOPO_POINT_CLASS_UNKNOWN);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_topo_point_class_t", "OCCTL_TOPO_POINT_CLASS_RESERVED_FUTURE", OCCTL_TOPO_POINT_CLASS_RESERVED_FUTURE);
    godot::ClassDB::bind_method(godot::D_METHOD("wire_order_edges", "graph", "wire"), &OcctlTopoRelation::wire_order_edges);
    godot::ClassDB::bind_method(godot::D_METHOD("child_explorer_config_init", "config"), &OcctlTopoRelation::child_explorer_config_init);
    godot::ClassDB::bind_method(godot::D_METHOD("child_explorer_create", "graph", "root", "config"), &OcctlTopoRelation::child_explorer_create, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("parent_explorer_config_init", "config"), &OcctlTopoRelation::parent_explorer_config_init);
    godot::ClassDB::bind_method(godot::D_METHOD("parent_explorer_create", "graph", "node", "config"), &OcctlTopoRelation::parent_explorer_create, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("explorer_iter_next", "iter", "out_node", "out_transform", "out_orientation"), &OcctlTopoRelation::explorer_iter_next);
    godot::ClassDB::bind_method(godot::D_METHOD("explorer_iter_free", "iter"), &OcctlTopoRelation::explorer_iter_free);
    godot::ClassDB::bind_method(godot::D_METHOD("relation_options_init", "options"), &OcctlTopoRelation::relation_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("related_iter_create", "graph", "node"), &OcctlTopoRelation::related_iter_create);
    godot::ClassDB::bind_method(godot::D_METHOD("distance_pair", "graph", "node_a", "node_b", "out_pair"), &OcctlTopoRelation::distance_pair);
    godot::ClassDB::bind_method(godot::D_METHOD("closest_point_to_point", "graph", "node", "point", "out_closest", "out_distance"), &OcctlTopoRelation::closest_point_to_point);
    godot::ClassDB::bind_method(godot::D_METHOD("axis_intersect_faces", "graph", "root", "axis", "min_parameter", "max_parameter", "tolerance"), &OcctlTopoRelation::axis_intersect_faces);
    godot::ClassDB::bind_method(godot::D_METHOD("touch_iter_create", "graph", "node_a", "node_b", "options"), &OcctlTopoRelation::touch_iter_create, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("intersection_iter_create", "graph", "node_a", "node_b", "options"), &OcctlTopoRelation::intersection_iter_create, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("is_same_geometry", "graph", "node_a", "node_b", "tolerance", "out_is_same_geometry"), &OcctlTopoRelation::is_same_geometry);
    godot::ClassDB::bind_method(godot::D_METHOD("common_vertices", "graph", "node_a", "node_b"), &OcctlTopoRelation::common_vertices);
    godot::ClassDB::bind_method(godot::D_METHOD("adjacent_edges", "graph", "edge"), &OcctlTopoRelation::adjacent_edges);
    godot::ClassDB::bind_method(godot::D_METHOD("adjacent_faces", "graph", "face"), &OcctlTopoRelation::adjacent_faces);
    godot::ClassDB::bind_method(godot::D_METHOD("connected_edges", "graph", "seed_edge"), &OcctlTopoRelation::connected_edges);
    godot::ClassDB::bind_method(godot::D_METHOD("connected_faces", "graph", "seed_face"), &OcctlTopoRelation::connected_faces);
    godot::ClassDB::bind_method(godot::D_METHOD("graph_distance", "graph", "root", "sources", "target", "out_distance"), &OcctlTopoRelation::graph_distance);
    godot::ClassDB::bind_method(godot::D_METHOD("classify_point", "graph", "solid", "point", "tolerance", "out_class"), &OcctlTopoRelation::classify_point);
    godot::ClassDB::bind_method(godot::D_METHOD("is_inside", "graph", "solid", "point", "tolerance", "include_boundary", "out_is_inside"), &OcctlTopoRelation::is_inside);
    godot::ClassDB::bind_method(godot::D_METHOD("axis_hit_iter_next", "iter", "out_hit"), &OcctlTopoRelation::axis_hit_iter_next);
    godot::ClassDB::bind_method(godot::D_METHOD("axis_hit_iter_free", "iter"), &OcctlTopoRelation::axis_hit_iter_free);
    godot::ClassDB::bind_method(godot::D_METHOD("touch_iter_next", "iter", "out_hit"), &OcctlTopoRelation::touch_iter_next);
    godot::ClassDB::bind_method(godot::D_METHOD("touch_iter_free", "iter"), &OcctlTopoRelation::touch_iter_free);
    godot::ClassDB::bind_method(godot::D_METHOD("intersection_iter_next", "iter", "out_node"), &OcctlTopoRelation::intersection_iter_next);
    godot::ClassDB::bind_method(godot::D_METHOD("intersection_iter_free", "iter"), &OcctlTopoRelation::intersection_iter_free);
    godot::ClassDB::bind_method(godot::D_METHOD("related_iter_next", "iter", "out_node", "out_kind"), &OcctlTopoRelation::related_iter_next);
    godot::ClassDB::bind_method(godot::D_METHOD("related_iter_free", "iter"), &OcctlTopoRelation::related_iter_free);
}

Array OcctlTopoRelation::wire_order_edges(const Ref<OcctlGraphHandle>& graph, int64_t wire) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_topo_wire_order_edges(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(wire)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return Array(); }
    std::vector<occtl_oriented_node_t> _out_buf_buf(static_cast<size_t>(_out_count_cnt));
    _err = ::occtl_topo_wire_order_edges(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(wire)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) {
        Ref<OcctlOrientedNode> _item;
        _item.instantiate();
        _item->copy_from_c(_out_buf_buf[_i]);
        _result[static_cast<int64_t>(_i)] = _item;
    }
    return _result;
}

void OcctlTopoRelation::child_explorer_config_init(const Ref<OcctlTopoChildExplorerConfig>& config) { // NOLINT
    occtl_topo_child_explorer_config_t _config_val = {};
    ::occtl_topo_child_explorer_config_init(&_config_val);
    ::occtl_topo_child_explorer_config_init(&_config_val);
    if (config.is_valid()) config->copy_from_c(_config_val);
}

Ref<OcctlTopoExplorerIterHandle> OcctlTopoRelation::child_explorer_create(const Ref<OcctlGraphHandle>& graph, int64_t root, const Ref<OcctlTopoChildExplorerConfig>& config) { // NOLINT
    occtl_topo_child_explorer_config_t _config_c = {};
    const occtl_topo_child_explorer_config_t* _config_ptr = nullptr;
    if (config.is_valid()) { _config_c = config->to_c(); _config_ptr = &_config_c; }
    occtl_topo_explorer_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_topo_child_explorer_create(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(root)}, _config_ptr, &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlTopoExplorerIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlTopoExplorerIterHandle>(); }
    Ref<OcctlTopoExplorerIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

void OcctlTopoRelation::parent_explorer_config_init(const Ref<OcctlTopoParentExplorerConfig>& config) { // NOLINT
    occtl_topo_parent_explorer_config_t _config_val = {};
    ::occtl_topo_parent_explorer_config_init(&_config_val);
    ::occtl_topo_parent_explorer_config_init(&_config_val);
    if (config.is_valid()) config->copy_from_c(_config_val);
}

Ref<OcctlTopoExplorerIterHandle> OcctlTopoRelation::parent_explorer_create(const Ref<OcctlGraphHandle>& graph, int64_t node, const Ref<OcctlTopoParentExplorerConfig>& config) { // NOLINT
    occtl_topo_parent_explorer_config_t _config_c = {};
    const occtl_topo_parent_explorer_config_t* _config_ptr = nullptr;
    if (config.is_valid()) { _config_c = config->to_c(); _config_ptr = &_config_c; }
    occtl_topo_explorer_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_topo_parent_explorer_create(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node)}, _config_ptr, &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlTopoExplorerIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlTopoExplorerIterHandle>(); }
    Ref<OcctlTopoExplorerIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

int OcctlTopoRelation::explorer_iter_next(const Ref<OcctlTopoExplorerIterHandle>& iter, const Ref<OcctlNodeId>& out_node, const Ref<OcctlTransform>& out_transform, const Ref<OcctlInt32>& out_orientation) { // NOLINT
    occtl_node_id_t _out_node_val = {};
    occtl_transform_t _out_transform_val = {};
    occtl_orientation_t _out_orientation_val = {};
    occtl_status_t _status = ::occtl_topo_explorer_iter_next(reinterpret_cast<occtl_topo_explorer_iter_t*>(static_cast<uintptr_t>(iter.is_valid() ? iter->get_handle() : 0)), &_out_node_val, &_out_transform_val, &_out_orientation_val);
    if (out_node.is_valid()) out_node->copy_from_c(_out_node_val);
    if (out_transform.is_valid()) out_transform->copy_from_c(_out_transform_val);
    if (out_orientation.is_valid()) out_orientation->copy_from_c(_out_orientation_val);
    return static_cast<int>(_status);
}

void OcctlTopoRelation::explorer_iter_free(const Ref<OcctlTopoExplorerIterHandle>& iter) { // NOLINT
    ::occtl_topo_explorer_iter_free(reinterpret_cast<occtl_topo_explorer_iter_t*>(static_cast<uintptr_t>(iter.is_valid() ? iter->release() : 0)));
}

void OcctlTopoRelation::relation_options_init(const Ref<OcctlTopoRelationOptions>& options) { // NOLINT
    occtl_topo_relation_options_t _options_val = {};
    ::occtl_topo_relation_options_init(&_options_val);
    ::occtl_topo_relation_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

Ref<OcctlTopoRelatedIterHandle> OcctlTopoRelation::related_iter_create(const Ref<OcctlGraphHandle>& graph, int64_t node) { // NOLINT
    occtl_topo_related_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_topo_related_iter_create(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node)}, &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlTopoRelatedIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlTopoRelatedIterHandle>(); }
    Ref<OcctlTopoRelatedIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

int OcctlTopoRelation::distance_pair(const Ref<OcctlGraphHandle>& graph, int64_t node_a, int64_t node_b, const Ref<OcctlTopoDistancePair>& out_pair) { // NOLINT
    occtl_topo_distance_pair_t _out_pair_val = {};
    occtl_status_t _status = ::occtl_topo_distance_pair(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node_a)}, occtl_node_id_t{static_cast<uint64_t>(node_b)}, &_out_pair_val);
    if (out_pair.is_valid()) out_pair->copy_from_c(_out_pair_val);
    return static_cast<int>(_status);
}

int OcctlTopoRelation::closest_point_to_point(const Ref<OcctlGraphHandle>& graph, int64_t node, const Ref<OcctlPoint3>& point, const Ref<OcctlPoint3>& out_closest, const Ref<OcctlDouble>& out_distance) { // NOLINT
    occtl_point3_t _out_closest_val = {};
    double _out_distance_val = {};
    occtl_status_t _status = ::occtl_topo_closest_point_to_point(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node)}, point->to_c(), &_out_closest_val, &_out_distance_val);
    if (out_closest.is_valid()) out_closest->copy_from_c(_out_closest_val);
    if (out_distance.is_valid()) out_distance->copy_from_c(_out_distance_val);
    return static_cast<int>(_status);
}

Ref<OcctlTopoAxisHitIterHandle> OcctlTopoRelation::axis_intersect_faces(const Ref<OcctlGraphHandle>& graph, int64_t root, const Ref<OcctlAxis1Placement>& axis, double min_parameter, double max_parameter, double tolerance) { // NOLINT
    occtl_topo_axis_hit_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_topo_axis_intersect_faces(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(root)}, axis->to_c(), min_parameter, max_parameter, tolerance, &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlTopoAxisHitIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlTopoAxisHitIterHandle>(); }
    Ref<OcctlTopoAxisHitIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

Ref<OcctlTopoTouchIterHandle> OcctlTopoRelation::touch_iter_create(const Ref<OcctlGraphHandle>& graph, int64_t node_a, int64_t node_b, const Ref<OcctlTopoRelationOptions>& options) { // NOLINT
    occtl_topo_relation_options_t _options_c = {};
    const occtl_topo_relation_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_topo_touch_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_topo_touch_iter_create(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node_a)}, occtl_node_id_t{static_cast<uint64_t>(node_b)}, _options_ptr, &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlTopoTouchIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlTopoTouchIterHandle>(); }
    Ref<OcctlTopoTouchIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

Ref<OcctlTopoIntersectionIterHandle> OcctlTopoRelation::intersection_iter_create(const Ref<OcctlGraphHandle>& graph, int64_t node_a, int64_t node_b, const Ref<OcctlTopoRelationOptions>& options) { // NOLINT
    occtl_topo_relation_options_t _options_c = {};
    const occtl_topo_relation_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_topo_intersection_iter_t* _out_iter_val = nullptr;
    occtl_status_t _status = ::occtl_topo_intersection_iter_create(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node_a)}, occtl_node_id_t{static_cast<uint64_t>(node_b)}, _options_ptr, &_out_iter_val);
    if (_status != OCCTL_OK) { return Ref<OcctlTopoIntersectionIterHandle>(); }
    if (!_out_iter_val) { return Ref<OcctlTopoIntersectionIterHandle>(); }
    Ref<OcctlTopoIntersectionIterHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_iter_val)));
    return _h;
}

int OcctlTopoRelation::is_same_geometry(const Ref<OcctlGraphHandle>& graph, int64_t node_a, int64_t node_b, double tolerance, const Ref<OcctlInt32>& out_is_same_geometry) { // NOLINT
    int32_t _out_is_same_geometry_val = {};
    occtl_status_t _status = ::occtl_topo_is_same_geometry(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node_a)}, occtl_node_id_t{static_cast<uint64_t>(node_b)}, tolerance, &_out_is_same_geometry_val);
    if (out_is_same_geometry.is_valid()) out_is_same_geometry->copy_from_c(_out_is_same_geometry_val);
    return static_cast<int>(_status);
}

PackedInt64Array OcctlTopoRelation::common_vertices(const Ref<OcctlGraphHandle>& graph, int64_t node_a, int64_t node_b) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_topo_common_vertices(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node_a)}, occtl_node_id_t{static_cast<uint64_t>(node_b)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt64Array(); }
    std::vector<occtl_node_id_t> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_topo_common_vertices(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(node_a)}, occtl_node_id_t{static_cast<uint64_t>(node_b)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_buf_buf[_i].bits);
    return _result;
}

PackedInt64Array OcctlTopoRelation::adjacent_edges(const Ref<OcctlGraphHandle>& graph, int64_t edge) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_topo_adjacent_edges(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt64Array(); }
    std::vector<occtl_node_id_t> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_topo_adjacent_edges(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_buf_buf[_i].bits);
    return _result;
}

PackedInt64Array OcctlTopoRelation::adjacent_faces(const Ref<OcctlGraphHandle>& graph, int64_t face) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_topo_adjacent_faces(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt64Array(); }
    std::vector<occtl_node_id_t> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_topo_adjacent_faces(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_buf_buf[_i].bits);
    return _result;
}

PackedInt64Array OcctlTopoRelation::connected_edges(const Ref<OcctlGraphHandle>& graph, int64_t seed_edge) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_topo_connected_edges(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(seed_edge)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt64Array(); }
    std::vector<occtl_node_id_t> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_topo_connected_edges(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(seed_edge)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_buf_buf[_i].bits);
    return _result;
}

PackedInt64Array OcctlTopoRelation::connected_faces(const Ref<OcctlGraphHandle>& graph, int64_t seed_face) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_topo_connected_faces(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(seed_face)}, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt64Array(); }
    std::vector<occtl_node_id_t> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_topo_connected_faces(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(seed_face)}, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_buf_buf[_i].bits);
    return _result;
}

int OcctlTopoRelation::graph_distance(const Ref<OcctlGraphHandle>& graph, int64_t root, const PackedInt64Array& sources, int64_t target, const Ref<OcctlInt32>& out_distance) { // NOLINT
    int32_t _out_distance_val = {};
    occtl_status_t _status = ::occtl_topo_graph_distance(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(root)}, reinterpret_cast<const occtl_node_id_t*>(static_cast<const void*>(sources.ptr())), static_cast<size_t>(sources.size()), occtl_node_id_t{static_cast<uint64_t>(target)}, &_out_distance_val);
    if (out_distance.is_valid()) out_distance->copy_from_c(_out_distance_val);
    return static_cast<int>(_status);
}

int OcctlTopoRelation::classify_point(const Ref<OcctlGraphHandle>& graph, int64_t solid, const Ref<OcctlPoint3>& point, double tolerance, const Ref<OcctlInt32>& out_class) { // NOLINT
    occtl_topo_point_class_t _out_class_val = {};
    occtl_status_t _status = ::occtl_topo_classify_point(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(solid)}, point->to_c(), tolerance, &_out_class_val);
    if (out_class.is_valid()) out_class->copy_from_c(_out_class_val);
    return static_cast<int>(_status);
}

int OcctlTopoRelation::is_inside(const Ref<OcctlGraphHandle>& graph, int64_t solid, const Ref<OcctlPoint3>& point, double tolerance, int include_boundary, const Ref<OcctlInt32>& out_is_inside) { // NOLINT
    int32_t _out_is_inside_val = {};
    occtl_status_t _status = ::occtl_topo_is_inside(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(solid)}, point->to_c(), tolerance, include_boundary, &_out_is_inside_val);
    if (out_is_inside.is_valid()) out_is_inside->copy_from_c(_out_is_inside_val);
    return static_cast<int>(_status);
}

int OcctlTopoRelation::axis_hit_iter_next(const Ref<OcctlTopoAxisHitIterHandle>& iter, const Ref<OcctlTopoAxisHit>& out_hit) { // NOLINT
    occtl_topo_axis_hit_t _out_hit_val = {};
    occtl_status_t _status = ::occtl_topo_axis_hit_iter_next(reinterpret_cast<occtl_topo_axis_hit_iter_t*>(static_cast<uintptr_t>(iter.is_valid() ? iter->get_handle() : 0)), &_out_hit_val);
    if (out_hit.is_valid()) out_hit->copy_from_c(_out_hit_val);
    return static_cast<int>(_status);
}

void OcctlTopoRelation::axis_hit_iter_free(const Ref<OcctlTopoAxisHitIterHandle>& iter) { // NOLINT
    ::occtl_topo_axis_hit_iter_free(reinterpret_cast<occtl_topo_axis_hit_iter_t*>(static_cast<uintptr_t>(iter.is_valid() ? iter->release() : 0)));
}

int OcctlTopoRelation::touch_iter_next(const Ref<OcctlTopoTouchIterHandle>& iter, const Ref<OcctlTopoTouchHit>& out_hit) { // NOLINT
    occtl_topo_touch_hit_t _out_hit_val = {};
    occtl_status_t _status = ::occtl_topo_touch_iter_next(reinterpret_cast<occtl_topo_touch_iter_t*>(static_cast<uintptr_t>(iter.is_valid() ? iter->get_handle() : 0)), &_out_hit_val);
    if (out_hit.is_valid()) out_hit->copy_from_c(_out_hit_val);
    return static_cast<int>(_status);
}

void OcctlTopoRelation::touch_iter_free(const Ref<OcctlTopoTouchIterHandle>& iter) { // NOLINT
    ::occtl_topo_touch_iter_free(reinterpret_cast<occtl_topo_touch_iter_t*>(static_cast<uintptr_t>(iter.is_valid() ? iter->release() : 0)));
}

int OcctlTopoRelation::intersection_iter_next(const Ref<OcctlTopoIntersectionIterHandle>& iter, const Ref<OcctlNodeId>& out_node) { // NOLINT
    occtl_node_id_t _out_node_val = {};
    occtl_status_t _status = ::occtl_topo_intersection_iter_next(reinterpret_cast<occtl_topo_intersection_iter_t*>(static_cast<uintptr_t>(iter.is_valid() ? iter->get_handle() : 0)), &_out_node_val);
    if (out_node.is_valid()) out_node->copy_from_c(_out_node_val);
    return static_cast<int>(_status);
}

void OcctlTopoRelation::intersection_iter_free(const Ref<OcctlTopoIntersectionIterHandle>& iter) { // NOLINT
    ::occtl_topo_intersection_iter_free(reinterpret_cast<occtl_topo_intersection_iter_t*>(static_cast<uintptr_t>(iter.is_valid() ? iter->release() : 0)));
}

int OcctlTopoRelation::related_iter_next(const Ref<OcctlTopoRelatedIterHandle>& iter, const Ref<OcctlNodeId>& out_node, const Ref<OcctlInt32>& out_kind) { // NOLINT
    occtl_node_id_t _out_node_val = {};
    occtl_relation_kind_t _out_kind_val = {};
    occtl_status_t _status = ::occtl_topo_related_iter_next(reinterpret_cast<occtl_topo_related_iter_t*>(static_cast<uintptr_t>(iter.is_valid() ? iter->get_handle() : 0)), &_out_node_val, &_out_kind_val);
    if (out_node.is_valid()) out_node->copy_from_c(_out_node_val);
    if (out_kind.is_valid()) out_kind->copy_from_c(_out_kind_val);
    return static_cast<int>(_status);
}

void OcctlTopoRelation::related_iter_free(const Ref<OcctlTopoRelatedIterHandle>& iter) { // NOLINT
    ::occtl_topo_related_iter_free(reinterpret_cast<occtl_topo_related_iter_t*>(static_cast<uintptr_t>(iter.is_valid() ? iter->release() : 0)));
}
