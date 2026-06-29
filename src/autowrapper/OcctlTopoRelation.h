#ifndef OCCTLTOPORELATION_H
#define OCCTLTOPORELATION_H

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
#include "occtl/occtl_topo_relation.h"

#include "OcctlAxis1Placement.h"
#include "OcctlDouble.h"
#include "OcctlGraphHandle.h"
#include "OcctlInt32.h"
#include "OcctlNodeId.h"
#include "OcctlOrientedNode.h"
#include "OcctlPoint3.h"
#include "OcctlSize.h"
#include "OcctlTopoAxisHit.h"
#include "OcctlTopoAxisHitIterHandle.h"
#include "OcctlTopoChildExplorerConfig.h"
#include "OcctlTopoDistancePair.h"
#include "OcctlTopoExplorerIterHandle.h"
#include "OcctlTopoIntersectionIterHandle.h"
#include "OcctlTopoParentExplorerConfig.h"
#include "OcctlTopoRelatedIterHandle.h"
#include "OcctlTopoRelationOptions.h"
#include "OcctlTopoTouchHit.h"
#include "OcctlTopoTouchIterHandle.h"
#include "OcctlTransform.h"

using namespace godot;

class OcctlTopoRelation : public godot::RefCounted {
    GDCLASS(OcctlTopoRelation, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    Array wire_order_edges(const Ref<OcctlGraphHandle>& graph, int64_t wire); // NOLINT
    void child_explorer_config_init(const Ref<OcctlTopoChildExplorerConfig>& config); // NOLINT
    Ref<OcctlTopoExplorerIterHandle> child_explorer_create(const Ref<OcctlGraphHandle>& graph, int64_t root, const Ref<OcctlTopoChildExplorerConfig>& config); // NOLINT
    void parent_explorer_config_init(const Ref<OcctlTopoParentExplorerConfig>& config); // NOLINT
    Ref<OcctlTopoExplorerIterHandle> parent_explorer_create(const Ref<OcctlGraphHandle>& graph, int64_t node, const Ref<OcctlTopoParentExplorerConfig>& config); // NOLINT
    int explorer_iter_next(const Ref<OcctlTopoExplorerIterHandle>& iter, const Ref<OcctlNodeId>& out_node, const Ref<OcctlTransform>& out_transform, const Ref<OcctlInt32>& out_orientation); // NOLINT
    void explorer_iter_free(const Ref<OcctlTopoExplorerIterHandle>& iter); // NOLINT
    void relation_options_init(const Ref<OcctlTopoRelationOptions>& options); // NOLINT
    Ref<OcctlTopoRelatedIterHandle> related_iter_create(const Ref<OcctlGraphHandle>& graph, int64_t node); // NOLINT
    int distance_pair(const Ref<OcctlGraphHandle>& graph, int64_t node_a, int64_t node_b, const Ref<OcctlTopoDistancePair>& out_pair); // NOLINT
    int closest_point_to_point(const Ref<OcctlGraphHandle>& graph, int64_t node, const Ref<OcctlPoint3>& point, const Ref<OcctlPoint3>& out_closest, const Ref<OcctlDouble>& out_distance); // NOLINT
    Ref<OcctlTopoAxisHitIterHandle> axis_intersect_faces(const Ref<OcctlGraphHandle>& graph, int64_t root, const Ref<OcctlAxis1Placement>& axis, double min_parameter, double max_parameter, double tolerance); // NOLINT
    Ref<OcctlTopoTouchIterHandle> touch_iter_create(const Ref<OcctlGraphHandle>& graph, int64_t node_a, int64_t node_b, const Ref<OcctlTopoRelationOptions>& options); // NOLINT
    Ref<OcctlTopoIntersectionIterHandle> intersection_iter_create(const Ref<OcctlGraphHandle>& graph, int64_t node_a, int64_t node_b, const Ref<OcctlTopoRelationOptions>& options); // NOLINT
    int is_same_geometry(const Ref<OcctlGraphHandle>& graph, int64_t node_a, int64_t node_b, double tolerance, const Ref<OcctlInt32>& out_is_same_geometry); // NOLINT
    PackedInt64Array common_vertices(const Ref<OcctlGraphHandle>& graph, int64_t node_a, int64_t node_b); // NOLINT
    PackedInt64Array adjacent_edges(const Ref<OcctlGraphHandle>& graph, int64_t edge); // NOLINT
    PackedInt64Array adjacent_faces(const Ref<OcctlGraphHandle>& graph, int64_t face); // NOLINT
    PackedInt64Array connected_edges(const Ref<OcctlGraphHandle>& graph, int64_t seed_edge); // NOLINT
    PackedInt64Array connected_faces(const Ref<OcctlGraphHandle>& graph, int64_t seed_face); // NOLINT
    int graph_distance(const Ref<OcctlGraphHandle>& graph, int64_t root, const PackedInt64Array& sources, int64_t target, const Ref<OcctlInt32>& out_distance); // NOLINT
    int classify_point(const Ref<OcctlGraphHandle>& graph, int64_t solid, const Ref<OcctlPoint3>& point, double tolerance, const Ref<OcctlInt32>& out_class); // NOLINT
    int is_inside(const Ref<OcctlGraphHandle>& graph, int64_t solid, const Ref<OcctlPoint3>& point, double tolerance, int include_boundary, const Ref<OcctlInt32>& out_is_inside); // NOLINT
    int axis_hit_iter_next(const Ref<OcctlTopoAxisHitIterHandle>& iter, const Ref<OcctlTopoAxisHit>& out_hit); // NOLINT
    void axis_hit_iter_free(const Ref<OcctlTopoAxisHitIterHandle>& iter); // NOLINT
    int touch_iter_next(const Ref<OcctlTopoTouchIterHandle>& iter, const Ref<OcctlTopoTouchHit>& out_hit); // NOLINT
    void touch_iter_free(const Ref<OcctlTopoTouchIterHandle>& iter); // NOLINT
    int intersection_iter_next(const Ref<OcctlTopoIntersectionIterHandle>& iter, const Ref<OcctlNodeId>& out_node); // NOLINT
    void intersection_iter_free(const Ref<OcctlTopoIntersectionIterHandle>& iter); // NOLINT
    int related_iter_next(const Ref<OcctlTopoRelatedIterHandle>& iter, const Ref<OcctlNodeId>& out_node, const Ref<OcctlInt32>& out_kind); // NOLINT
    void related_iter_free(const Ref<OcctlTopoRelatedIterHandle>& iter); // NOLINT
};

#endif // OCCTLTOPORELATION_H
