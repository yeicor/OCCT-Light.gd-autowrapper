#include "OcctlEdgeView.h"

#include "OcctlNodeId.h"

int OcctlEdgeView::get_struct_version() const { return struct_version; }
void OcctlEdgeView::set_struct_version(int val) { struct_version = val; }

int64_t OcctlEdgeView::get_p_next() const { return p_next; }
void OcctlEdgeView::set_p_next(int64_t val) { p_next = val; }

double OcctlEdgeView::get_t_min() const { return t_min; }
void OcctlEdgeView::set_t_min(double val) { t_min = val; }

double OcctlEdgeView::get_t_max() const { return t_max; }
void OcctlEdgeView::set_t_max(double val) { t_max = val; }

double OcctlEdgeView::get_tolerance() const { return tolerance; }
void OcctlEdgeView::set_tolerance(double val) { tolerance = val; }

int64_t OcctlEdgeView::get_start_vertex() const { return start_vertex; }
void OcctlEdgeView::set_start_vertex(int64_t val) { start_vertex = val; }

int64_t OcctlEdgeView::get_end_vertex() const { return end_vertex; }
void OcctlEdgeView::set_end_vertex(int64_t val) { end_vertex = val; }

int OcctlEdgeView::get_internal_vertex_count() const { return internal_vertex_count; }
void OcctlEdgeView::set_internal_vertex_count(int val) { internal_vertex_count = val; }

int OcctlEdgeView::get_face_count() const { return face_count; }
void OcctlEdgeView::set_face_count(int val) { face_count = val; }

int OcctlEdgeView::get_has_curve() const { return has_curve; }
void OcctlEdgeView::set_has_curve(int val) { has_curve = val; }

int OcctlEdgeView::get_is_degenerated() const { return is_degenerated; }
void OcctlEdgeView::set_is_degenerated(int val) { is_degenerated = val; }

int OcctlEdgeView::get_is_closed() const { return is_closed; }
void OcctlEdgeView::set_is_closed(int val) { is_closed = val; }

int OcctlEdgeView::get_same_parameter() const { return same_parameter; }
void OcctlEdgeView::set_same_parameter(int val) { same_parameter = val; }

int OcctlEdgeView::get_same_range() const { return same_range; }
void OcctlEdgeView::set_same_range(int val) { same_range = val; }

int OcctlEdgeView::get_is_manifold() const { return is_manifold; }
void OcctlEdgeView::set_is_manifold(int val) { is_manifold = val; }

int OcctlEdgeView::get_is_boundary() const { return is_boundary; }
void OcctlEdgeView::set_is_boundary(int val) { is_boundary = val; }

void OcctlEdgeView::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlEdgeView::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlEdgeView::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlEdgeView::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlEdgeView::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_t_min"), &OcctlEdgeView::get_t_min);
    godot::ClassDB::bind_method(godot::D_METHOD("set_t_min", "val"), &OcctlEdgeView::set_t_min);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "t_min"), "set_t_min", "get_t_min");
    godot::ClassDB::bind_method(godot::D_METHOD("get_t_max"), &OcctlEdgeView::get_t_max);
    godot::ClassDB::bind_method(godot::D_METHOD("set_t_max", "val"), &OcctlEdgeView::set_t_max);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "t_max"), "set_t_max", "get_t_max");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlEdgeView::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlEdgeView::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_start_vertex"), &OcctlEdgeView::get_start_vertex);
    godot::ClassDB::bind_method(godot::D_METHOD("set_start_vertex", "val"), &OcctlEdgeView::set_start_vertex);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "start_vertex"), "set_start_vertex", "get_start_vertex");
    godot::ClassDB::bind_method(godot::D_METHOD("get_end_vertex"), &OcctlEdgeView::get_end_vertex);
    godot::ClassDB::bind_method(godot::D_METHOD("set_end_vertex", "val"), &OcctlEdgeView::set_end_vertex);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "end_vertex"), "set_end_vertex", "get_end_vertex");
    godot::ClassDB::bind_method(godot::D_METHOD("get_internal_vertex_count"), &OcctlEdgeView::get_internal_vertex_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_internal_vertex_count", "val"), &OcctlEdgeView::set_internal_vertex_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "internal_vertex_count"), "set_internal_vertex_count", "get_internal_vertex_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_face_count"), &OcctlEdgeView::get_face_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_face_count", "val"), &OcctlEdgeView::set_face_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "face_count"), "set_face_count", "get_face_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_has_curve"), &OcctlEdgeView::get_has_curve);
    godot::ClassDB::bind_method(godot::D_METHOD("set_has_curve", "val"), &OcctlEdgeView::set_has_curve);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "has_curve"), "set_has_curve", "get_has_curve");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_degenerated"), &OcctlEdgeView::get_is_degenerated);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_degenerated", "val"), &OcctlEdgeView::set_is_degenerated);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_degenerated"), "set_is_degenerated", "get_is_degenerated");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_closed"), &OcctlEdgeView::get_is_closed);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_closed", "val"), &OcctlEdgeView::set_is_closed);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_closed"), "set_is_closed", "get_is_closed");
    godot::ClassDB::bind_method(godot::D_METHOD("get_same_parameter"), &OcctlEdgeView::get_same_parameter);
    godot::ClassDB::bind_method(godot::D_METHOD("set_same_parameter", "val"), &OcctlEdgeView::set_same_parameter);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "same_parameter"), "set_same_parameter", "get_same_parameter");
    godot::ClassDB::bind_method(godot::D_METHOD("get_same_range"), &OcctlEdgeView::get_same_range);
    godot::ClassDB::bind_method(godot::D_METHOD("set_same_range", "val"), &OcctlEdgeView::set_same_range);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "same_range"), "set_same_range", "get_same_range");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_manifold"), &OcctlEdgeView::get_is_manifold);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_manifold", "val"), &OcctlEdgeView::set_is_manifold);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_manifold"), "set_is_manifold", "get_is_manifold");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_boundary"), &OcctlEdgeView::get_is_boundary);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_boundary", "val"), &OcctlEdgeView::set_is_boundary);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_boundary"), "set_is_boundary", "get_is_boundary");
}

occtl_edge_view_t OcctlEdgeView::to_c() const {
    occtl_edge_view_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.t_min = t_min;
    result.t_max = t_max;
    result.tolerance = tolerance;
    result.start_vertex.bits = static_cast<uint64_t>(start_vertex);
    result.end_vertex.bits = static_cast<uint64_t>(end_vertex);
    result.internal_vertex_count = internal_vertex_count;
    result.face_count = face_count;
    result.has_curve = has_curve;
    result.is_degenerated = is_degenerated;
    result.is_closed = is_closed;
    result.same_parameter = same_parameter;
    result.same_range = same_range;
    result.is_manifold = is_manifold;
    result.is_boundary = is_boundary;
    return result;
}

Ref<OcctlEdgeView> OcctlEdgeView::from_c(const occtl_edge_view_t& val) {
    Ref<OcctlEdgeView> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->t_min = val.t_min;
    r->t_max = val.t_max;
    r->tolerance = val.tolerance;
    r->start_vertex = static_cast<int64_t>(val.start_vertex.bits);
    r->end_vertex = static_cast<int64_t>(val.end_vertex.bits);
    r->internal_vertex_count = val.internal_vertex_count;
    r->face_count = val.face_count;
    r->has_curve = val.has_curve;
    r->is_degenerated = val.is_degenerated;
    r->is_closed = val.is_closed;
    r->same_parameter = val.same_parameter;
    r->same_range = val.same_range;
    r->is_manifold = val.is_manifold;
    r->is_boundary = val.is_boundary;
    return r;
}

void OcctlEdgeView::copy_from_c(const occtl_edge_view_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    t_min = val.t_min;
    t_max = val.t_max;
    tolerance = val.tolerance;
    start_vertex = static_cast<int64_t>(val.start_vertex.bits);
    end_vertex = static_cast<int64_t>(val.end_vertex.bits);
    internal_vertex_count = val.internal_vertex_count;
    face_count = val.face_count;
    has_curve = val.has_curve;
    is_degenerated = val.is_degenerated;
    is_closed = val.is_closed;
    same_parameter = val.same_parameter;
    same_range = val.same_range;
    is_manifold = val.is_manifold;
    is_boundary = val.is_boundary;
}
