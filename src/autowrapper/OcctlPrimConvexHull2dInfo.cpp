#include "OcctlPrimConvexHull2dInfo.h"

#include "OcctlAxis2Placement.h"

int OcctlPrimConvexHull2dInfo::get_struct_version() const { return struct_version; }
void OcctlPrimConvexHull2dInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimConvexHull2dInfo::get_p_next() const { return p_next; }
void OcctlPrimConvexHull2dInfo::set_p_next(int64_t val) { p_next = val; }

Ref<OcctlAxis2Placement> OcctlPrimConvexHull2dInfo::get_placement() const { return placement; }
void OcctlPrimConvexHull2dInfo::set_placement(Ref<OcctlAxis2Placement> val) { placement = val; }

Array OcctlPrimConvexHull2dInfo::get_points() const { return points; }
void OcctlPrimConvexHull2dInfo::set_points(Array val) { points = val; }

int OcctlPrimConvexHull2dInfo::get_point_count() const { return point_count; }
void OcctlPrimConvexHull2dInfo::set_point_count(int val) { point_count = val; }

PackedInt64Array OcctlPrimConvexHull2dInfo::get_vertices() const { return vertices; }
void OcctlPrimConvexHull2dInfo::set_vertices(PackedInt64Array val) { vertices = val; }

int OcctlPrimConvexHull2dInfo::get_vertex_count() const { return vertex_count; }
void OcctlPrimConvexHull2dInfo::set_vertex_count(int val) { vertex_count = val; }

double OcctlPrimConvexHull2dInfo::get_tolerance() const { return tolerance; }
void OcctlPrimConvexHull2dInfo::set_tolerance(double val) { tolerance = val; }

int OcctlPrimConvexHull2dInfo::get_make_face() const { return make_face; }
void OcctlPrimConvexHull2dInfo::set_make_face(int val) { make_face = val; }

void OcctlPrimConvexHull2dInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimConvexHull2dInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimConvexHull2dInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimConvexHull2dInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimConvexHull2dInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_placement"), &OcctlPrimConvexHull2dInfo::get_placement);
    godot::ClassDB::bind_method(godot::D_METHOD("set_placement", "val"), &OcctlPrimConvexHull2dInfo::set_placement);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "placement"), "set_placement", "get_placement");
    godot::ClassDB::bind_method(godot::D_METHOD("get_points"), &OcctlPrimConvexHull2dInfo::get_points);
    godot::ClassDB::bind_method(godot::D_METHOD("set_points", "val"), &OcctlPrimConvexHull2dInfo::set_points);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "points"), "set_points", "get_points");
    godot::ClassDB::bind_method(godot::D_METHOD("get_point_count"), &OcctlPrimConvexHull2dInfo::get_point_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_point_count", "val"), &OcctlPrimConvexHull2dInfo::set_point_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "point_count"), "set_point_count", "get_point_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_vertices"), &OcctlPrimConvexHull2dInfo::get_vertices);
    godot::ClassDB::bind_method(godot::D_METHOD("set_vertices", "val"), &OcctlPrimConvexHull2dInfo::set_vertices);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "vertices"), "set_vertices", "get_vertices");
    godot::ClassDB::bind_method(godot::D_METHOD("get_vertex_count"), &OcctlPrimConvexHull2dInfo::get_vertex_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_vertex_count", "val"), &OcctlPrimConvexHull2dInfo::set_vertex_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "vertex_count"), "set_vertex_count", "get_vertex_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlPrimConvexHull2dInfo::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlPrimConvexHull2dInfo::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_make_face"), &OcctlPrimConvexHull2dInfo::get_make_face);
    godot::ClassDB::bind_method(godot::D_METHOD("set_make_face", "val"), &OcctlPrimConvexHull2dInfo::set_make_face);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "make_face"), "set_make_face", "get_make_face");
}

occtl_prim_convex_hull_2d_info_t OcctlPrimConvexHull2dInfo::to_c() const {
    occtl_prim_convex_hull_2d_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.placement = placement->to_c();
    _cache_points.resize(points.size());
    for (int _i = 0; _i < points.size(); _i++) {
        Ref<OcctlPoint3> _item = points[_i];
        if (_item.is_valid()) _cache_points[_i] = _item->to_c();
        else _cache_points[_i] = {};
    }
    result.points = _cache_points.data();
    result.point_count = point_count;
    result.vertices = reinterpret_cast<const occtl_node_id_t*>(vertices.ptr());
    result.vertex_count = vertex_count;
    result.tolerance = tolerance;
    result.make_face = make_face;
    return result;
}

Ref<OcctlPrimConvexHull2dInfo> OcctlPrimConvexHull2dInfo::from_c(const occtl_prim_convex_hull_2d_info_t& val) {
    Ref<OcctlPrimConvexHull2dInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->placement = OcctlAxis2Placement::from_c(val.placement);
    // array field points is not populated from C
    r->point_count = val.point_count;
    // array field vertices is not populated from C
    r->vertex_count = val.vertex_count;
    r->tolerance = val.tolerance;
    r->make_face = val.make_face;
    return r;
}

void OcctlPrimConvexHull2dInfo::copy_from_c(const occtl_prim_convex_hull_2d_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    placement = OcctlAxis2Placement::from_c(val.placement);
    // array field points is not populated from C
    point_count = val.point_count;
    // array field vertices is not populated from C
    vertex_count = val.vertex_count;
    tolerance = val.tolerance;
    make_face = val.make_face;
}
