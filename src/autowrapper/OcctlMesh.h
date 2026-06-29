#ifndef OCCTLMESH_H
#define OCCTLMESH_H

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
#include "occtl/occtl_mesh.h"

#include "OcctlGraphHandle.h"
#include "OcctlMeshComponentBoundaryPolylinesView.h"
#include "OcctlMeshFromBuffersOptions.h"
#include "OcctlMeshOptions.h"
#include "OcctlMeshTriangleAnalysisView.h"
#include "OcctlMeshTriangleBuffersView.h"
#include "OcctlMeshTriangleComponentBoundaryChainsView.h"
#include "OcctlMeshTriangleComponentBoundaryView.h"
#include "OcctlMeshTriangleComponentSummariesView.h"
#include "OcctlMeshTriangleComponentTrianglesView.h"
#include "OcctlMeshTriangleComponentsOptions.h"
#include "OcctlMeshTriangleComponentsView.h"
#include "OcctlMeshTriangleCylinderComponentsOptions.h"
#include "OcctlMeshTriangleCylinderComponentsView.h"
#include "OcctlMeshTrianglePlaneComponentsOptions.h"
#include "OcctlMeshTrianglePlaneComponentsView.h"
#include "OcctlMeshTriangleSphereComponentsOptions.h"
#include "OcctlMeshTriangleSphereComponentsView.h"
#include "OcctlMetadataKeyView.h"
#include "OcctlNodeId.h"
#include "OcctlPolygon3dView.h"
#include "OcctlPolygonOnTriView.h"
#include "OcctlSize.h"
#include "OcctlTriangulationView.h"
#include "OcctlUint32.h"

using namespace godot;

class OcctlMesh : public godot::RefCounted {
    GDCLASS(OcctlMesh, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int64_t const_OCCTL_MESH_TRIANGLE_ADJACENCY_BOUNDARY(); // NOLINT
    void options_init(const Ref<OcctlMeshOptions>& options); // NOLINT
    int model_metadata_set(const Ref<OcctlGraphHandle>& graph, const String& key, const String& value); // NOLINT
    String model_metadata_get(const Ref<OcctlGraphHandle>& graph, const String& key); // NOLINT
    Array model_metadata_keys(const Ref<OcctlGraphHandle>& graph); // NOLINT
    int model_metadata_unset(const Ref<OcctlGraphHandle>& graph, const String& key); // NOLINT
    void from_buffers_options_init(const Ref<OcctlMeshFromBuffersOptions>& options); // NOLINT
    Ref<OcctlGraphHandle> from_buffers(const Ref<OcctlMeshFromBuffersOptions>& options, const Ref<OcctlNodeId>& out_root); // NOLINT
    int generate(const Ref<OcctlGraphHandle>& graph, const PackedInt64Array& nodes, const Ref<OcctlMeshOptions>& options); // NOLINT
    int face_triangulation(const Ref<OcctlGraphHandle>& graph, int64_t face, const Ref<OcctlTriangulationView>& out_view); // NOLINT
    int face_triangulation_count(const Ref<OcctlGraphHandle>& graph, int64_t face, const Ref<OcctlUint32>& out_count); // NOLINT
    int face_triangulation_indexed(const Ref<OcctlGraphHandle>& graph, int64_t face, int index, const Ref<OcctlTriangulationView>& out_view); // NOLINT
    int edge_polygon3d(const Ref<OcctlGraphHandle>& graph, int64_t edge, const Ref<OcctlPolygon3dView>& out_view); // NOLINT
    int coedge_polygon_on_tri(const Ref<OcctlGraphHandle>& graph, int64_t coedge, const Ref<OcctlPolygonOnTriView>& out_view); // NOLINT
    int triangle_buffers(const Ref<OcctlGraphHandle>& graph, int64_t root, const Ref<OcctlMeshTriangleBuffersView>& out_view); // NOLINT
    int triangle_analysis(const Ref<OcctlGraphHandle>& graph, int64_t root, const Ref<OcctlMeshTriangleAnalysisView>& out_view); // NOLINT
    void triangle_components_options_init(const Ref<OcctlMeshTriangleComponentsOptions>& options); // NOLINT
    int triangle_components(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTriangleComponentsOptions>& options, const Ref<OcctlMeshTriangleComponentsView>& out_view); // NOLINT
    int triangle_component_triangles(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTriangleComponentsOptions>& options, int component_id, const Ref<OcctlMeshTriangleComponentTrianglesView>& out_view); // NOLINT
    int triangle_component_boundary(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTriangleComponentsOptions>& options, int component_id, const Ref<OcctlMeshTriangleComponentBoundaryView>& out_view); // NOLINT
    int triangle_component_boundary_chains(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTriangleComponentsOptions>& options, int component_id, const Ref<OcctlMeshTriangleComponentBoundaryChainsView>& out_view); // NOLINT
    int component_boundary_polylines(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTriangleComponentsOptions>& options, int component_id, const Ref<OcctlMeshComponentBoundaryPolylinesView>& out_view); // NOLINT
    int triangle_component_summaries(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTriangleComponentsOptions>& options, const Ref<OcctlMeshTriangleComponentSummariesView>& out_view); // NOLINT
    void triangle_plane_components_options_init(const Ref<OcctlMeshTrianglePlaneComponentsOptions>& options); // NOLINT
    int triangle_plane_components(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTrianglePlaneComponentsOptions>& options, const Ref<OcctlMeshTrianglePlaneComponentsView>& out_view); // NOLINT
    void triangle_sphere_components_options_init(const Ref<OcctlMeshTriangleSphereComponentsOptions>& options); // NOLINT
    int triangle_sphere_components(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTriangleSphereComponentsOptions>& options, const Ref<OcctlMeshTriangleSphereComponentsView>& out_view); // NOLINT
    void triangle_cylinder_components_options_init(const Ref<OcctlMeshTriangleCylinderComponentsOptions>& options); // NOLINT
    int triangle_cylinder_components(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTriangleCylinderComponentsOptions>& options, const Ref<OcctlMeshTriangleCylinderComponentsView>& out_view); // NOLINT
    int make_sphere_component_solid(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTriangleSphereComponentsOptions>& options, int component_id, const Ref<OcctlNodeId>& out_solid); // NOLINT
    int make_cylinder_component_solid(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTriangleCylinderComponentsOptions>& options, int component_id, const Ref<OcctlNodeId>& out_solid); // NOLINT
    PackedInt64Array make_sphere_component_solids(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTriangleSphereComponentsOptions>& options); // NOLINT
    PackedInt64Array make_cylinder_component_solids(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTriangleCylinderComponentsOptions>& options); // NOLINT
    int make_plane_component_face(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTrianglePlaneComponentsOptions>& options, int component_id, const Ref<OcctlNodeId>& out_face); // NOLINT
    PackedInt64Array make_plane_component_faces(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlMeshTrianglePlaneComponentsOptions>& options); // NOLINT
};

#endif // OCCTLMESH_H
