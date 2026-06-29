#ifndef OCCTLPRIMSKETCH_H
#define OCCTLPRIMSKETCH_H

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
#include "occtl/occtl_prim_sketch.h"

#include "OcctlGraphHandle.h"
#include "OcctlNodeId.h"
#include "OcctlPrimArc3ptInfo.h"
#include "OcctlPrimArcCenterInfo.h"
#include "OcctlPrimCircleInfo.h"
#include "OcctlPrimConstrainedEdgeInfo.h"
#include "OcctlPrimConvexHull2dInfo.h"
#include "OcctlPrimDiskInfo.h"
#include "OcctlPrimEllipseInfo.h"
#include "OcctlPrimFillet2dInfo.h"
#include "OcctlPrimFullRound2dInfo.h"
#include "OcctlPrimHelixInfo.h"
#include "OcctlPrimPlanarFaceInfo.h"
#include "OcctlPrimPlaneInfo.h"
#include "OcctlPrimPolylineInfo.h"
#include "OcctlPrimRectangleInfo.h"
#include "OcctlPrimRegularPolygonInfo.h"
#include "OcctlPrimSlotInfo.h"
#include "OcctlPrimSplineInfo.h"
#include "OcctlPrimTraceInfo.h"
#include "OcctlPrimTubeInfo.h"

using namespace godot;

class OcctlPrimSketch : public godot::RefCounted {
    GDCLASS(OcctlPrimSketch, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    void polyline_info_init(const Ref<OcctlPrimPolylineInfo>& info); // NOLINT
    int make_polyline(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimPolylineInfo>& info, const Ref<OcctlNodeId>& out_wire); // NOLINT
    void regular_polygon_info_init(const Ref<OcctlPrimRegularPolygonInfo>& info); // NOLINT
    int make_regular_polygon(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimRegularPolygonInfo>& info, const Ref<OcctlNodeId>& out_wire); // NOLINT
    void rectangle_info_init(const Ref<OcctlPrimRectangleInfo>& info); // NOLINT
    int make_rectangle(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimRectangleInfo>& info, const Ref<OcctlNodeId>& out_wire); // NOLINT
    void circle_info_init(const Ref<OcctlPrimCircleInfo>& info); // NOLINT
    int make_circle(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimCircleInfo>& info, const Ref<OcctlNodeId>& out_wire); // NOLINT
    void ellipse_info_init(const Ref<OcctlPrimEllipseInfo>& info); // NOLINT
    int make_ellipse(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimEllipseInfo>& info, const Ref<OcctlNodeId>& out_wire); // NOLINT
    void planar_face_info_init(const Ref<OcctlPrimPlanarFaceInfo>& info); // NOLINT
    int make_planar_face(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimPlanarFaceInfo>& info, const Ref<OcctlNodeId>& out_face); // NOLINT
    void convex_hull_2d_info_init(const Ref<OcctlPrimConvexHull2dInfo>& info); // NOLINT
    int make_convex_hull_2d(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimConvexHull2dInfo>& info, const Ref<OcctlNodeId>& out_node); // NOLINT
    void trace_info_init(const Ref<OcctlPrimTraceInfo>& info); // NOLINT
    int make_trace(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimTraceInfo>& info, const Ref<OcctlNodeId>& out_face); // NOLINT
    void constrained_edge_info_init(const Ref<OcctlPrimConstrainedEdgeInfo>& info); // NOLINT
    int make_constrained_edge(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimConstrainedEdgeInfo>& info, const Ref<OcctlNodeId>& out_edge); // NOLINT
    void arc_3pt_info_init(const Ref<OcctlPrimArc3ptInfo>& info); // NOLINT
    int make_arc_3pt(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimArc3ptInfo>& info, const Ref<OcctlNodeId>& out_wire); // NOLINT
    void arc_center_info_init(const Ref<OcctlPrimArcCenterInfo>& info); // NOLINT
    int make_arc_center(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimArcCenterInfo>& info, const Ref<OcctlNodeId>& out_wire); // NOLINT
    void spline_info_init(const Ref<OcctlPrimSplineInfo>& info); // NOLINT
    int make_spline(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimSplineInfo>& info, const Ref<OcctlNodeId>& out_wire); // NOLINT
    void plane_info_init(const Ref<OcctlPrimPlaneInfo>& info); // NOLINT
    int make_plane(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimPlaneInfo>& info, const Ref<OcctlNodeId>& out_face); // NOLINT
    void disk_info_init(const Ref<OcctlPrimDiskInfo>& info); // NOLINT
    int make_disk(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimDiskInfo>& info, const Ref<OcctlNodeId>& out_face); // NOLINT
    void slot_info_init(const Ref<OcctlPrimSlotInfo>& info); // NOLINT
    int make_slot(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimSlotInfo>& info, const Ref<OcctlNodeId>& out_wire); // NOLINT
    void tube_info_init(const Ref<OcctlPrimTubeInfo>& info); // NOLINT
    int make_tube(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimTubeInfo>& info, const Ref<OcctlNodeId>& out_solid); // NOLINT
    void helix_info_init(const Ref<OcctlPrimHelixInfo>& info); // NOLINT
    int make_helix(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimHelixInfo>& info, const Ref<OcctlNodeId>& out_wire); // NOLINT
    void fillet_2d_info_init(const Ref<OcctlPrimFillet2dInfo>& info); // NOLINT
    int make_fillet_2d(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimFillet2dInfo>& info, const Ref<OcctlNodeId>& out_face); // NOLINT
    void full_round_2d_info_init(const Ref<OcctlPrimFullRound2dInfo>& info); // NOLINT
    int make_full_round_2d(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimFullRound2dInfo>& info, const Ref<OcctlNodeId>& out_face); // NOLINT
};

#endif // OCCTLPRIMSKETCH_H
