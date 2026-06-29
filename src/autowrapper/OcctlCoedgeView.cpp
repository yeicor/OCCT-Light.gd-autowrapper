#include "OcctlCoedgeView.h"

#include "OcctlNodeId.h"
#include "OcctlPoint2.h"

int OcctlCoedgeView::get_struct_version() const { return struct_version; }
void OcctlCoedgeView::set_struct_version(int val) { struct_version = val; }

int64_t OcctlCoedgeView::get_p_next() const { return p_next; }
void OcctlCoedgeView::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlCoedgeView::get_edge_of() const { return edge_of; }
void OcctlCoedgeView::set_edge_of(int64_t val) { edge_of = val; }

int64_t OcctlCoedgeView::get_face_of() const { return face_of; }
void OcctlCoedgeView::set_face_of(int64_t val) { face_of = val; }

int OcctlCoedgeView::get_orientation() const { return orientation; }
void OcctlCoedgeView::set_orientation(int val) { orientation = val; }

double OcctlCoedgeView::get_t_min() const { return t_min; }
void OcctlCoedgeView::set_t_min(double val) { t_min = val; }

double OcctlCoedgeView::get_t_max() const { return t_max; }
void OcctlCoedgeView::set_t_max(double val) { t_max = val; }

Ref<OcctlPoint2> OcctlCoedgeView::get_uv_start() const { return uv_start; }
void OcctlCoedgeView::set_uv_start(Ref<OcctlPoint2> val) { uv_start = val; }

Ref<OcctlPoint2> OcctlCoedgeView::get_uv_end() const { return uv_end; }
void OcctlCoedgeView::set_uv_end(Ref<OcctlPoint2> val) { uv_end = val; }

int OcctlCoedgeView::get_is_seam() const { return is_seam; }
void OcctlCoedgeView::set_is_seam(int val) { is_seam = val; }

int OcctlCoedgeView::get_is_reversed() const { return is_reversed; }
void OcctlCoedgeView::set_is_reversed(int val) { is_reversed = val; }

int OcctlCoedgeView::get_has_pcurve() const { return has_pcurve; }
void OcctlCoedgeView::set_has_pcurve(int val) { has_pcurve = val; }

void OcctlCoedgeView::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlCoedgeView::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlCoedgeView::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlCoedgeView::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlCoedgeView::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_edge_of"), &OcctlCoedgeView::get_edge_of);
    godot::ClassDB::bind_method(godot::D_METHOD("set_edge_of", "val"), &OcctlCoedgeView::set_edge_of);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "edge_of"), "set_edge_of", "get_edge_of");
    godot::ClassDB::bind_method(godot::D_METHOD("get_face_of"), &OcctlCoedgeView::get_face_of);
    godot::ClassDB::bind_method(godot::D_METHOD("set_face_of", "val"), &OcctlCoedgeView::set_face_of);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "face_of"), "set_face_of", "get_face_of");
    godot::ClassDB::bind_method(godot::D_METHOD("get_orientation"), &OcctlCoedgeView::get_orientation);
    godot::ClassDB::bind_method(godot::D_METHOD("set_orientation", "val"), &OcctlCoedgeView::set_orientation);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "orientation"), "set_orientation", "get_orientation");
    godot::ClassDB::bind_method(godot::D_METHOD("get_t_min"), &OcctlCoedgeView::get_t_min);
    godot::ClassDB::bind_method(godot::D_METHOD("set_t_min", "val"), &OcctlCoedgeView::set_t_min);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "t_min"), "set_t_min", "get_t_min");
    godot::ClassDB::bind_method(godot::D_METHOD("get_t_max"), &OcctlCoedgeView::get_t_max);
    godot::ClassDB::bind_method(godot::D_METHOD("set_t_max", "val"), &OcctlCoedgeView::set_t_max);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "t_max"), "set_t_max", "get_t_max");
    godot::ClassDB::bind_method(godot::D_METHOD("get_uv_start"), &OcctlCoedgeView::get_uv_start);
    godot::ClassDB::bind_method(godot::D_METHOD("set_uv_start", "val"), &OcctlCoedgeView::set_uv_start);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "uv_start"), "set_uv_start", "get_uv_start");
    godot::ClassDB::bind_method(godot::D_METHOD("get_uv_end"), &OcctlCoedgeView::get_uv_end);
    godot::ClassDB::bind_method(godot::D_METHOD("set_uv_end", "val"), &OcctlCoedgeView::set_uv_end);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "uv_end"), "set_uv_end", "get_uv_end");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_seam"), &OcctlCoedgeView::get_is_seam);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_seam", "val"), &OcctlCoedgeView::set_is_seam);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_seam"), "set_is_seam", "get_is_seam");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_reversed"), &OcctlCoedgeView::get_is_reversed);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_reversed", "val"), &OcctlCoedgeView::set_is_reversed);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_reversed"), "set_is_reversed", "get_is_reversed");
    godot::ClassDB::bind_method(godot::D_METHOD("get_has_pcurve"), &OcctlCoedgeView::get_has_pcurve);
    godot::ClassDB::bind_method(godot::D_METHOD("set_has_pcurve", "val"), &OcctlCoedgeView::set_has_pcurve);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "has_pcurve"), "set_has_pcurve", "get_has_pcurve");
}

occtl_coedge_view_t OcctlCoedgeView::to_c() const {
    occtl_coedge_view_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.edge_of.bits = static_cast<uint64_t>(edge_of);
    result.face_of.bits = static_cast<uint64_t>(face_of);
    result.orientation = static_cast<occtl_orientation_t>(orientation);
    result.t_min = t_min;
    result.t_max = t_max;
    result.uv_start = uv_start->to_c();
    result.uv_end = uv_end->to_c();
    result.is_seam = is_seam;
    result.is_reversed = is_reversed;
    result.has_pcurve = has_pcurve;
    return result;
}

Ref<OcctlCoedgeView> OcctlCoedgeView::from_c(const occtl_coedge_view_t& val) {
    Ref<OcctlCoedgeView> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->edge_of = static_cast<int64_t>(val.edge_of.bits);
    r->face_of = static_cast<int64_t>(val.face_of.bits);
    r->orientation = static_cast<int>(val.orientation);
    r->t_min = val.t_min;
    r->t_max = val.t_max;
    r->uv_start = OcctlPoint2::from_c(val.uv_start);
    r->uv_end = OcctlPoint2::from_c(val.uv_end);
    r->is_seam = val.is_seam;
    r->is_reversed = val.is_reversed;
    r->has_pcurve = val.has_pcurve;
    return r;
}

void OcctlCoedgeView::copy_from_c(const occtl_coedge_view_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    edge_of = static_cast<int64_t>(val.edge_of.bits);
    face_of = static_cast<int64_t>(val.face_of.bits);
    orientation = static_cast<int>(val.orientation);
    t_min = val.t_min;
    t_max = val.t_max;
    uv_start = OcctlPoint2::from_c(val.uv_start);
    uv_end = OcctlPoint2::from_c(val.uv_end);
    is_seam = val.is_seam;
    is_reversed = val.is_reversed;
    has_pcurve = val.has_pcurve;
}
