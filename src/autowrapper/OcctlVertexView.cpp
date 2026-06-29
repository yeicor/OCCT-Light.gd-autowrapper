#include "OcctlVertexView.h"

#include "OcctlPoint3.h"

int OcctlVertexView::get_struct_version() const { return struct_version; }
void OcctlVertexView::set_struct_version(int val) { struct_version = val; }

int64_t OcctlVertexView::get_p_next() const { return p_next; }
void OcctlVertexView::set_p_next(int64_t val) { p_next = val; }

Ref<OcctlPoint3> OcctlVertexView::get_point() const { return point; }
void OcctlVertexView::set_point(Ref<OcctlPoint3> val) { point = val; }

double OcctlVertexView::get_tolerance() const { return tolerance; }
void OcctlVertexView::set_tolerance(double val) { tolerance = val; }

void OcctlVertexView::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlVertexView::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlVertexView::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlVertexView::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlVertexView::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_point"), &OcctlVertexView::get_point);
    godot::ClassDB::bind_method(godot::D_METHOD("set_point", "val"), &OcctlVertexView::set_point);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "point"), "set_point", "get_point");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlVertexView::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlVertexView::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
}

occtl_vertex_view_t OcctlVertexView::to_c() const {
    occtl_vertex_view_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.point = point->to_c();
    result.tolerance = tolerance;
    return result;
}

Ref<OcctlVertexView> OcctlVertexView::from_c(const occtl_vertex_view_t& val) {
    Ref<OcctlVertexView> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->point = OcctlPoint3::from_c(val.point);
    r->tolerance = val.tolerance;
    return r;
}

void OcctlVertexView::copy_from_c(const occtl_vertex_view_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    point = OcctlPoint3::from_c(val.point);
    tolerance = val.tolerance;
}
