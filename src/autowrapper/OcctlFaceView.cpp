#include "OcctlFaceView.h"

#include "OcctlNodeId.h"

int OcctlFaceView::get_struct_version() const { return struct_version; }
void OcctlFaceView::set_struct_version(int val) { struct_version = val; }

int64_t OcctlFaceView::get_p_next() const { return p_next; }
void OcctlFaceView::set_p_next(int64_t val) { p_next = val; }

double OcctlFaceView::get_u_min() const { return u_min; }
void OcctlFaceView::set_u_min(double val) { u_min = val; }

double OcctlFaceView::get_u_max() const { return u_max; }
void OcctlFaceView::set_u_max(double val) { u_max = val; }

double OcctlFaceView::get_v_min() const { return v_min; }
void OcctlFaceView::set_v_min(double val) { v_min = val; }

double OcctlFaceView::get_v_max() const { return v_max; }
void OcctlFaceView::set_v_max(double val) { v_max = val; }

double OcctlFaceView::get_tolerance() const { return tolerance; }
void OcctlFaceView::set_tolerance(double val) { tolerance = val; }

int64_t OcctlFaceView::get_outer_wire() const { return outer_wire; }
void OcctlFaceView::set_outer_wire(int64_t val) { outer_wire = val; }

int OcctlFaceView::get_wire_count() const { return wire_count; }
void OcctlFaceView::set_wire_count(int val) { wire_count = val; }

int OcctlFaceView::get_has_surface() const { return has_surface; }
void OcctlFaceView::set_has_surface(int val) { has_surface = val; }

int OcctlFaceView::get_has_triangulation() const { return has_triangulation; }
void OcctlFaceView::set_has_triangulation(int val) { has_triangulation = val; }

int OcctlFaceView::get_natural_restriction() const { return natural_restriction; }
void OcctlFaceView::set_natural_restriction(int val) { natural_restriction = val; }

void OcctlFaceView::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlFaceView::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlFaceView::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlFaceView::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlFaceView::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_min"), &OcctlFaceView::get_u_min);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_min", "val"), &OcctlFaceView::set_u_min);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "u_min"), "set_u_min", "get_u_min");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_max"), &OcctlFaceView::get_u_max);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_max", "val"), &OcctlFaceView::set_u_max);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "u_max"), "set_u_max", "get_u_max");
    godot::ClassDB::bind_method(godot::D_METHOD("get_v_min"), &OcctlFaceView::get_v_min);
    godot::ClassDB::bind_method(godot::D_METHOD("set_v_min", "val"), &OcctlFaceView::set_v_min);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "v_min"), "set_v_min", "get_v_min");
    godot::ClassDB::bind_method(godot::D_METHOD("get_v_max"), &OcctlFaceView::get_v_max);
    godot::ClassDB::bind_method(godot::D_METHOD("set_v_max", "val"), &OcctlFaceView::set_v_max);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "v_max"), "set_v_max", "get_v_max");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlFaceView::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlFaceView::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_outer_wire"), &OcctlFaceView::get_outer_wire);
    godot::ClassDB::bind_method(godot::D_METHOD("set_outer_wire", "val"), &OcctlFaceView::set_outer_wire);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "outer_wire"), "set_outer_wire", "get_outer_wire");
    godot::ClassDB::bind_method(godot::D_METHOD("get_wire_count"), &OcctlFaceView::get_wire_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_wire_count", "val"), &OcctlFaceView::set_wire_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "wire_count"), "set_wire_count", "get_wire_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_has_surface"), &OcctlFaceView::get_has_surface);
    godot::ClassDB::bind_method(godot::D_METHOD("set_has_surface", "val"), &OcctlFaceView::set_has_surface);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "has_surface"), "set_has_surface", "get_has_surface");
    godot::ClassDB::bind_method(godot::D_METHOD("get_has_triangulation"), &OcctlFaceView::get_has_triangulation);
    godot::ClassDB::bind_method(godot::D_METHOD("set_has_triangulation", "val"), &OcctlFaceView::set_has_triangulation);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "has_triangulation"), "set_has_triangulation", "get_has_triangulation");
    godot::ClassDB::bind_method(godot::D_METHOD("get_natural_restriction"), &OcctlFaceView::get_natural_restriction);
    godot::ClassDB::bind_method(godot::D_METHOD("set_natural_restriction", "val"), &OcctlFaceView::set_natural_restriction);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "natural_restriction"), "set_natural_restriction", "get_natural_restriction");
}

occtl_face_view_t OcctlFaceView::to_c() const {
    occtl_face_view_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.u_min = u_min;
    result.u_max = u_max;
    result.v_min = v_min;
    result.v_max = v_max;
    result.tolerance = tolerance;
    result.outer_wire.bits = static_cast<uint64_t>(outer_wire);
    result.wire_count = wire_count;
    result.has_surface = has_surface;
    result.has_triangulation = has_triangulation;
    result.natural_restriction = natural_restriction;
    return result;
}

Ref<OcctlFaceView> OcctlFaceView::from_c(const occtl_face_view_t& val) {
    Ref<OcctlFaceView> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->u_min = val.u_min;
    r->u_max = val.u_max;
    r->v_min = val.v_min;
    r->v_max = val.v_max;
    r->tolerance = val.tolerance;
    r->outer_wire = static_cast<int64_t>(val.outer_wire.bits);
    r->wire_count = val.wire_count;
    r->has_surface = val.has_surface;
    r->has_triangulation = val.has_triangulation;
    r->natural_restriction = val.natural_restriction;
    return r;
}

void OcctlFaceView::copy_from_c(const occtl_face_view_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    u_min = val.u_min;
    u_max = val.u_max;
    v_min = val.v_min;
    v_max = val.v_max;
    tolerance = val.tolerance;
    outer_wire = static_cast<int64_t>(val.outer_wire.bits);
    wire_count = val.wire_count;
    has_surface = val.has_surface;
    has_triangulation = val.has_triangulation;
    natural_restriction = val.natural_restriction;
}
