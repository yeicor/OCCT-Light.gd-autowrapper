#include "OcctlMesh.h"

#include "occtl/occtl_mesh.h"

#include <vector>

void OcctlMesh::_bind_methods() {
    BIND_CONSTANT(OCCTL_MESH_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_MESH_FROM_BUFFERS_OPTIONS_VERSION_1);
    godot::ClassDB::bind_method(godot::D_METHOD("const_OCCTL_MESH_TRIANGLE_ADJACENCY_BOUNDARY"), &OcctlMesh::const_OCCTL_MESH_TRIANGLE_ADJACENCY_BOUNDARY);
    BIND_CONSTANT(OCCTL_MESH_TRIANGLE_COMPONENTS_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_MESH_TRIANGLE_PLANE_COMPONENTS_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_MESH_TRIANGLE_SPHERE_COMPONENTS_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_MESH_TRIANGLE_CYLINDER_COMPONENTS_OPTIONS_VERSION_1);
    godot::ClassDB::bind_method(godot::D_METHOD("options_init", "options"), &OcctlMesh::options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("model_metadata_set", "graph", "key", "value"), &OcctlMesh::model_metadata_set);
    godot::ClassDB::bind_method(godot::D_METHOD("model_metadata_get", "graph", "key"), &OcctlMesh::model_metadata_get);
    godot::ClassDB::bind_method(godot::D_METHOD("model_metadata_keys", "graph"), &OcctlMesh::model_metadata_keys);
    godot::ClassDB::bind_method(godot::D_METHOD("model_metadata_unset", "graph", "key"), &OcctlMesh::model_metadata_unset);
    godot::ClassDB::bind_method(godot::D_METHOD("from_buffers_options_init", "options"), &OcctlMesh::from_buffers_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("from_buffers", "options", "out_root"), &OcctlMesh::from_buffers, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("generate", "graph", "nodes", "options"), &OcctlMesh::generate, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("face_triangulation", "graph", "face", "out_view"), &OcctlMesh::face_triangulation);
    godot::ClassDB::bind_method(godot::D_METHOD("face_triangulation_count", "graph", "face", "out_count"), &OcctlMesh::face_triangulation_count);
    godot::ClassDB::bind_method(godot::D_METHOD("face_triangulation_indexed", "graph", "face", "index", "out_view"), &OcctlMesh::face_triangulation_indexed);
    godot::ClassDB::bind_method(godot::D_METHOD("edge_polygon3d", "graph", "edge", "out_view"), &OcctlMesh::edge_polygon3d);
    godot::ClassDB::bind_method(godot::D_METHOD("coedge_polygon_on_tri", "graph", "coedge", "out_view"), &OcctlMesh::coedge_polygon_on_tri);
    godot::ClassDB::bind_method(godot::D_METHOD("triangle_buffers", "graph", "root", "out_view"), &OcctlMesh::triangle_buffers);
    godot::ClassDB::bind_method(godot::D_METHOD("triangle_analysis", "graph", "root", "out_view"), &OcctlMesh::triangle_analysis);
    godot::ClassDB::bind_method(godot::D_METHOD("triangle_components_options_init", "options"), &OcctlMesh::triangle_components_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("triangle_components", "graph", "options", "out_view"), &OcctlMesh::triangle_components, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("triangle_component_triangles", "graph", "options", "component_id", "out_view"), &OcctlMesh::triangle_component_triangles, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("triangle_component_boundary", "graph", "options", "component_id", "out_view"), &OcctlMesh::triangle_component_boundary, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("triangle_component_boundary_chains", "graph", "options", "component_id", "out_view"), &OcctlMesh::triangle_component_boundary_chains, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("component_boundary_polylines", "graph", "options", "component_id", "out_view"), &OcctlMesh::component_boundary_polylines, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("triangle_component_summaries", "graph", "options", "out_view"), &OcctlMesh::triangle_component_summaries, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("triangle_plane_components_options_init", "options"), &OcctlMesh::triangle_plane_components_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("triangle_plane_components", "graph", "options", "out_view"), &OcctlMesh::triangle_plane_components, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("triangle_sphere_components_options_init", "options"), &OcctlMesh::triangle_sphere_components_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("triangle_sphere_components", "graph", "options", "out_view"), &OcctlMesh::triangle_sphere_components, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("triangle_cylinder_components_options_init", "options"), &OcctlMesh::triangle_cylinder_components_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("triangle_cylinder_components", "graph", "options", "out_view"), &OcctlMesh::triangle_cylinder_components, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("make_sphere_component_solid", "graph", "options", "component_id", "out_solid"), &OcctlMesh::make_sphere_component_solid, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("make_cylinder_component_solid", "graph", "options", "component_id", "out_solid"), &OcctlMesh::make_cylinder_component_solid, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("make_sphere_component_solids", "graph", "options"), &OcctlMesh::make_sphere_component_solids, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("make_cylinder_component_solids", "graph", "options"), &OcctlMesh::make_cylinder_component_solids, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("make_plane_component_face", "graph", "options", "component_id", "out_face"), &OcctlMesh::make_plane_component_face, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("make_plane_component_faces", "graph", "options"), &OcctlMesh::make_plane_component_faces, DEFVAL(Variant()));
}

int64_t OcctlMesh::const_OCCTL_MESH_TRIANGLE_ADJACENCY_BOUNDARY() { // NOLINT
    return UINT32_MAX;
}

void OcctlMesh::options_init(const Ref<OcctlMeshOptions>& options) { // NOLINT
    occtl_mesh_options_t _options_val = {};
    ::occtl_mesh_options_init(&_options_val);
    ::occtl_mesh_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

int OcctlMesh::model_metadata_set(const Ref<OcctlGraphHandle>& graph, const String& key, const String& value) { // NOLINT
    occtl_status_t _status = ::occtl_mesh_model_metadata_set(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), key.utf8().get_data(), static_cast<size_t>(key.utf8().length()), value.utf8().get_data(), static_cast<size_t>(value.utf8().length()));
    return static_cast<int>(_status);
}

String OcctlMesh::model_metadata_get(const Ref<OcctlGraphHandle>& graph, const String& key) { // NOLINT
    size_t _out_required_cnt = 0;
    godot::CharString _key_cs = key.utf8();
    occtl_status_t _err = ::occtl_mesh_model_metadata_get(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _key_cs.get_data(), static_cast<size_t>(key.utf8().length()), nullptr, 0, &_out_required_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return String(); }
    std::vector<char> _buf_buf(_out_required_cnt + 1);
    _err = ::occtl_mesh_model_metadata_get(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _key_cs.get_data(), static_cast<size_t>(key.utf8().length()), _buf_buf.data(), _out_required_cnt, &_out_required_cnt);
    return godot::String(_buf_buf.data());
}

Array OcctlMesh::model_metadata_keys(const Ref<OcctlGraphHandle>& graph) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_status_t _err = ::occtl_mesh_model_metadata_keys(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return Array(); }
    std::vector<occtl_metadata_key_view_t> _out_keys_buf(static_cast<size_t>(_out_count_cnt));
    _err = ::occtl_mesh_model_metadata_keys(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _out_keys_buf.data(), _out_count_cnt, &_out_count_cnt);
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

int OcctlMesh::model_metadata_unset(const Ref<OcctlGraphHandle>& graph, const String& key) { // NOLINT
    occtl_status_t _status = ::occtl_mesh_model_metadata_unset(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), key.utf8().get_data(), static_cast<size_t>(key.utf8().length()));
    return static_cast<int>(_status);
}

void OcctlMesh::from_buffers_options_init(const Ref<OcctlMeshFromBuffersOptions>& options) { // NOLINT
    occtl_mesh_from_buffers_options_t _options_val = {};
    ::occtl_mesh_from_buffers_options_init(&_options_val);
    ::occtl_mesh_from_buffers_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

Ref<OcctlGraphHandle> OcctlMesh::from_buffers(const Ref<OcctlMeshFromBuffersOptions>& options, const Ref<OcctlNodeId>& out_root) { // NOLINT
    occtl_mesh_from_buffers_options_t _options_c = {};
    const occtl_mesh_from_buffers_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_graph_t* _out_graph_val = nullptr;
    occtl_node_id_t _out_root_val = {};
    occtl_status_t _status = ::occtl_mesh_from_buffers(_options_ptr, &_out_graph_val, &_out_root_val);
    if (out_root.is_valid()) out_root->copy_from_c(_out_root_val);
    if (_status != OCCTL_OK) { return Ref<OcctlGraphHandle>(); }
    if (!_out_graph_val) { return Ref<OcctlGraphHandle>(); }
    Ref<OcctlGraphHandle> _h;
    _h.instantiate();
    _h->set_handle(static_cast<int64_t>(reinterpret_cast<uintptr_t>(_out_graph_val)));
    return _h;
}

int OcctlMesh::generate(const Ref<OcctlGraphHandle>& graph, const PackedInt64Array& nodes, const Ref<OcctlMeshOptions>& options) { // NOLINT
    occtl_mesh_options_t _options_c = {};
    const occtl_mesh_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_status_t _status = ::occtl_mesh_generate(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), reinterpret_cast<const occtl_node_id_t*>(static_cast<const void*>(nodes.ptr())), static_cast<size_t>(nodes.size()), _options_ptr);
    return static_cast<int>(_status);
}

int OcctlMesh::face_triangulation(const Ref<OcctlGraphHandle>& graph, int64_t face, const Ref<OcctlTriangulationView>& out_view) { // NOLINT
    occtl_triangulation_view_t _out_view_val = {};
    occtl_status_t _status = ::occtl_mesh_face_triangulation(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, &_out_view_val);
    if (out_view.is_valid()) out_view->copy_from_c(_out_view_val);
    return static_cast<int>(_status);
}

int OcctlMesh::face_triangulation_count(const Ref<OcctlGraphHandle>& graph, int64_t face, const Ref<OcctlUint32>& out_count) { // NOLINT
    uint32_t _out_count_val = {};
    occtl_status_t _status = ::occtl_mesh_face_triangulation_count(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, &_out_count_val);
    if (out_count.is_valid()) out_count->copy_from_c(_out_count_val);
    return static_cast<int>(_status);
}

int OcctlMesh::face_triangulation_indexed(const Ref<OcctlGraphHandle>& graph, int64_t face, int index, const Ref<OcctlTriangulationView>& out_view) { // NOLINT
    occtl_triangulation_view_t _out_view_val = {};
    occtl_status_t _status = ::occtl_mesh_face_triangulation_indexed(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(face)}, index, &_out_view_val);
    if (out_view.is_valid()) out_view->copy_from_c(_out_view_val);
    return static_cast<int>(_status);
}

int OcctlMesh::edge_polygon3d(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlPolygon3dView>& out_view) { // NOLINT
    occtl_polygon3d_view_t _out_view_val = {};
    occtl_status_t _status = ::occtl_mesh_edge_polygon3d(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(edge)}, &_out_view_val);
    if (out_view.is_valid()) out_view->copy_from_c(_out_view_val);
    return static_cast<int>(_status);
}

int OcctlMesh::coedge_polygon_on_tri(const Ref<OcctlGraphHandle>& graph, int64_t coedge, const Ref<OcctlPolygonOnTriView>& out_view) { // NOLINT
    occtl_polygon_on_tri_view_t _out_view_val = {};
    occtl_status_t _status = ::occtl_mesh_coedge_polygon_on_tri(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(coedge)}, &_out_view_val);
    if (out_view.is_valid()) out_view->copy_from_c(_out_view_val);
    return static_cast<int>(_status);
}

int OcctlMesh::triangle_buffers(const Ref<OcctlGraphHandle>& graph, int64_t root, const Ref<OcctlMeshTriangleBuffersView>& out_view) { // NOLINT
    occtl_mesh_triangle_buffers_view_t _out_view_val = {};
    occtl_status_t _status = ::occtl_mesh_triangle_buffers(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(root)}, &_out_view_val);
    if (out_view.is_valid()) out_view->copy_from_c(_out_view_val);
    return static_cast<int>(_status);
}

int OcctlMesh::triangle_analysis(const Ref<OcctlGraphHandle>& graph, int64_t root, const Ref<OcctlMeshTriangleAnalysisView>& out_view) { // NOLINT
    occtl_mesh_triangle_analysis_view_t _out_view_val = {};
    occtl_status_t _status = ::occtl_mesh_triangle_analysis(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), occtl_node_id_t{static_cast<uint64_t>(root)}, &_out_view_val);
    if (out_view.is_valid()) out_view->copy_from_c(_out_view_val);
    return static_cast<int>(_status);
}

void OcctlMesh::triangle_components_options_init(const Ref<OcctlMeshTriangleComponentsOptions>& options) { // NOLINT
    occtl_mesh_triangle_components_options_t _options_val = {};
    ::occtl_mesh_triangle_components_options_init(&_options_val);
    ::occtl_mesh_triangle_components_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

int OcctlMesh::triangle_components(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTriangleComponentsOptions>& options, const Ref<OcctlMeshTriangleComponentsView>& out_view) { // NOLINT
    occtl_mesh_triangle_components_options_t _options_c = {};
    const occtl_mesh_triangle_components_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_mesh_triangle_components_view_t _out_view_val = {};
    occtl_status_t _status = ::occtl_mesh_triangle_components(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_view_val);
    if (out_view.is_valid()) out_view->copy_from_c(_out_view_val);
    return static_cast<int>(_status);
}

int OcctlMesh::triangle_component_triangles(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTriangleComponentsOptions>& options, int component_id, const Ref<OcctlMeshTriangleComponentTrianglesView>& out_view) { // NOLINT
    occtl_mesh_triangle_components_options_t _options_c = {};
    const occtl_mesh_triangle_components_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_mesh_triangle_component_triangles_view_t _out_view_val = {};
    occtl_status_t _status = ::occtl_mesh_triangle_component_triangles(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, component_id, &_out_view_val);
    if (out_view.is_valid()) out_view->copy_from_c(_out_view_val);
    return static_cast<int>(_status);
}

int OcctlMesh::triangle_component_boundary(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTriangleComponentsOptions>& options, int component_id, const Ref<OcctlMeshTriangleComponentBoundaryView>& out_view) { // NOLINT
    occtl_mesh_triangle_components_options_t _options_c = {};
    const occtl_mesh_triangle_components_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_mesh_triangle_component_boundary_view_t _out_view_val = {};
    occtl_status_t _status = ::occtl_mesh_triangle_component_boundary(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, component_id, &_out_view_val);
    if (out_view.is_valid()) out_view->copy_from_c(_out_view_val);
    return static_cast<int>(_status);
}

int OcctlMesh::triangle_component_boundary_chains(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTriangleComponentsOptions>& options, int component_id, const Ref<OcctlMeshTriangleComponentBoundaryChainsView>& out_view) { // NOLINT
    occtl_mesh_triangle_components_options_t _options_c = {};
    const occtl_mesh_triangle_components_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_mesh_triangle_component_boundary_chains_view_t _out_view_val = {};
    occtl_status_t _status = ::occtl_mesh_triangle_component_boundary_chains(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, component_id, &_out_view_val);
    if (out_view.is_valid()) out_view->copy_from_c(_out_view_val);
    return static_cast<int>(_status);
}

int OcctlMesh::component_boundary_polylines(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTriangleComponentsOptions>& options, int component_id, const Ref<OcctlMeshComponentBoundaryPolylinesView>& out_view) { // NOLINT
    occtl_mesh_triangle_components_options_t _options_c = {};
    const occtl_mesh_triangle_components_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_mesh_component_boundary_polylines_view_t _out_view_val = {};
    occtl_status_t _status = ::occtl_mesh_component_boundary_polylines(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, component_id, &_out_view_val);
    if (out_view.is_valid()) out_view->copy_from_c(_out_view_val);
    return static_cast<int>(_status);
}

int OcctlMesh::triangle_component_summaries(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTriangleComponentsOptions>& options, const Ref<OcctlMeshTriangleComponentSummariesView>& out_view) { // NOLINT
    occtl_mesh_triangle_components_options_t _options_c = {};
    const occtl_mesh_triangle_components_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_mesh_triangle_component_summaries_view_t _out_view_val = {};
    occtl_status_t _status = ::occtl_mesh_triangle_component_summaries(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_view_val);
    if (out_view.is_valid()) out_view->copy_from_c(_out_view_val);
    return static_cast<int>(_status);
}

void OcctlMesh::triangle_plane_components_options_init(const Ref<OcctlMeshTrianglePlaneComponentsOptions>& options) { // NOLINT
    occtl_mesh_triangle_plane_components_options_t _options_val = {};
    ::occtl_mesh_triangle_plane_components_options_init(&_options_val);
    ::occtl_mesh_triangle_plane_components_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

int OcctlMesh::triangle_plane_components(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTrianglePlaneComponentsOptions>& options, const Ref<OcctlMeshTrianglePlaneComponentsView>& out_view) { // NOLINT
    occtl_mesh_triangle_plane_components_options_t _options_c = {};
    const occtl_mesh_triangle_plane_components_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_mesh_triangle_plane_components_view_t _out_view_val = {};
    occtl_status_t _status = ::occtl_mesh_triangle_plane_components(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_view_val);
    if (out_view.is_valid()) out_view->copy_from_c(_out_view_val);
    return static_cast<int>(_status);
}

void OcctlMesh::triangle_sphere_components_options_init(const Ref<OcctlMeshTriangleSphereComponentsOptions>& options) { // NOLINT
    occtl_mesh_triangle_sphere_components_options_t _options_val = {};
    ::occtl_mesh_triangle_sphere_components_options_init(&_options_val);
    ::occtl_mesh_triangle_sphere_components_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

int OcctlMesh::triangle_sphere_components(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTriangleSphereComponentsOptions>& options, const Ref<OcctlMeshTriangleSphereComponentsView>& out_view) { // NOLINT
    occtl_mesh_triangle_sphere_components_options_t _options_c = {};
    const occtl_mesh_triangle_sphere_components_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_mesh_triangle_sphere_components_view_t _out_view_val = {};
    occtl_status_t _status = ::occtl_mesh_triangle_sphere_components(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_view_val);
    if (out_view.is_valid()) out_view->copy_from_c(_out_view_val);
    return static_cast<int>(_status);
}

void OcctlMesh::triangle_cylinder_components_options_init(const Ref<OcctlMeshTriangleCylinderComponentsOptions>& options) { // NOLINT
    occtl_mesh_triangle_cylinder_components_options_t _options_val = {};
    ::occtl_mesh_triangle_cylinder_components_options_init(&_options_val);
    ::occtl_mesh_triangle_cylinder_components_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

int OcctlMesh::triangle_cylinder_components(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTriangleCylinderComponentsOptions>& options, const Ref<OcctlMeshTriangleCylinderComponentsView>& out_view) { // NOLINT
    occtl_mesh_triangle_cylinder_components_options_t _options_c = {};
    const occtl_mesh_triangle_cylinder_components_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_mesh_triangle_cylinder_components_view_t _out_view_val = {};
    occtl_status_t _status = ::occtl_mesh_triangle_cylinder_components(reinterpret_cast<const occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, &_out_view_val);
    if (out_view.is_valid()) out_view->copy_from_c(_out_view_val);
    return static_cast<int>(_status);
}

int OcctlMesh::make_sphere_component_solid(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTriangleSphereComponentsOptions>& options, int component_id, const Ref<OcctlNodeId>& out_solid) { // NOLINT
    occtl_mesh_triangle_sphere_components_options_t _options_c = {};
    const occtl_mesh_triangle_sphere_components_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_node_id_t _out_solid_val = {};
    occtl_status_t _status = ::occtl_mesh_make_sphere_component_solid(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, component_id, &_out_solid_val);
    if (out_solid.is_valid()) out_solid->copy_from_c(_out_solid_val);
    return static_cast<int>(_status);
}

int OcctlMesh::make_cylinder_component_solid(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTriangleCylinderComponentsOptions>& options, int component_id, const Ref<OcctlNodeId>& out_solid) { // NOLINT
    occtl_mesh_triangle_cylinder_components_options_t _options_c = {};
    const occtl_mesh_triangle_cylinder_components_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_node_id_t _out_solid_val = {};
    occtl_status_t _status = ::occtl_mesh_make_cylinder_component_solid(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, component_id, &_out_solid_val);
    if (out_solid.is_valid()) out_solid->copy_from_c(_out_solid_val);
    return static_cast<int>(_status);
}

PackedInt64Array OcctlMesh::make_sphere_component_solids(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTriangleSphereComponentsOptions>& options) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_mesh_triangle_sphere_components_options_t _options_c = {};
    const occtl_mesh_triangle_sphere_components_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_status_t _err = ::occtl_mesh_make_sphere_component_solids(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt64Array(); }
    std::vector<occtl_node_id_t> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_mesh_make_sphere_component_solids(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_buf_buf[_i].bits);
    return _result;
}

PackedInt64Array OcctlMesh::make_cylinder_component_solids(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTriangleCylinderComponentsOptions>& options) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_mesh_triangle_cylinder_components_options_t _options_c = {};
    const occtl_mesh_triangle_cylinder_components_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_status_t _err = ::occtl_mesh_make_cylinder_component_solids(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt64Array(); }
    std::vector<occtl_node_id_t> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_mesh_make_cylinder_component_solids(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_buf_buf[_i].bits);
    return _result;
}

int OcctlMesh::make_plane_component_face(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTrianglePlaneComponentsOptions>& options, int component_id, const Ref<OcctlNodeId>& out_face) { // NOLINT
    occtl_mesh_triangle_plane_components_options_t _options_c = {};
    const occtl_mesh_triangle_plane_components_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_node_id_t _out_face_val = {};
    occtl_status_t _status = ::occtl_mesh_make_plane_component_face(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, component_id, &_out_face_val);
    if (out_face.is_valid()) out_face->copy_from_c(_out_face_val);
    return static_cast<int>(_status);
}

PackedInt64Array OcctlMesh::make_plane_component_faces(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTrianglePlaneComponentsOptions>& options) { // NOLINT
    size_t _out_count_cnt = 0;
    occtl_mesh_triangle_plane_components_options_t _options_c = {};
    const occtl_mesh_triangle_plane_components_options_t* _options_ptr = nullptr;
    if (options.is_valid()) { _options_c = options->to_c(); _options_ptr = &_options_c; }
    occtl_status_t _err = ::occtl_mesh_make_plane_component_faces(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, nullptr, 0, &_out_count_cnt);
    if (_err != 0 && _err != OCCTL_BUFFER_TOO_SMALL) { return PackedInt64Array(); }
    std::vector<occtl_node_id_t> _out_buf_buf(_out_count_cnt);
    _err = ::occtl_mesh_make_plane_component_faces(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _options_ptr, _out_buf_buf.data(), _out_count_cnt, &_out_count_cnt);
    PackedInt64Array _result;
    _result.resize(static_cast<int64_t>(_out_count_cnt));
    for (size_t _i = 0; _i < _out_count_cnt; _i++) _result[static_cast<int64_t>(_i)] = static_cast<int64_t>(_out_buf_buf[_i].bits);
    return _result;
}
