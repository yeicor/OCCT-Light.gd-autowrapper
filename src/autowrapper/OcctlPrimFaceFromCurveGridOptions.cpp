#include "OcctlPrimFaceFromCurveGridOptions.h"

#include "OcctlSurfaceCurveGridCreateInfo.h"

int OcctlPrimFaceFromCurveGridOptions::get_struct_version() const { return struct_version; }
void OcctlPrimFaceFromCurveGridOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimFaceFromCurveGridOptions::get_p_next() const { return p_next; }
void OcctlPrimFaceFromCurveGridOptions::set_p_next(int64_t val) { p_next = val; }

Ref<OcctlSurfaceCurveGridCreateInfo> OcctlPrimFaceFromCurveGridOptions::get_surface() const { return surface; }
void OcctlPrimFaceFromCurveGridOptions::set_surface(Ref<OcctlSurfaceCurveGridCreateInfo> val) { surface = val; }

double OcctlPrimFaceFromCurveGridOptions::get_tolerance() const { return tolerance; }
void OcctlPrimFaceFromCurveGridOptions::set_tolerance(double val) { tolerance = val; }

void OcctlPrimFaceFromCurveGridOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimFaceFromCurveGridOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimFaceFromCurveGridOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimFaceFromCurveGridOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimFaceFromCurveGridOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_surface"), &OcctlPrimFaceFromCurveGridOptions::get_surface);
    godot::ClassDB::bind_method(godot::D_METHOD("set_surface", "val"), &OcctlPrimFaceFromCurveGridOptions::set_surface);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "surface"), "set_surface", "get_surface");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlPrimFaceFromCurveGridOptions::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlPrimFaceFromCurveGridOptions::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
}

occtl_prim_face_from_curve_grid_options_t OcctlPrimFaceFromCurveGridOptions::to_c() const {
    occtl_prim_face_from_curve_grid_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.surface = surface->to_c();
    result.tolerance = tolerance;
    return result;
}

Ref<OcctlPrimFaceFromCurveGridOptions> OcctlPrimFaceFromCurveGridOptions::from_c(const occtl_prim_face_from_curve_grid_options_t& val) {
    Ref<OcctlPrimFaceFromCurveGridOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->surface = OcctlSurfaceCurveGridCreateInfo::from_c(val.surface);
    r->tolerance = val.tolerance;
    return r;
}

void OcctlPrimFaceFromCurveGridOptions::copy_from_c(const occtl_prim_face_from_curve_grid_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    surface = OcctlSurfaceCurveGridCreateInfo::from_c(val.surface);
    tolerance = val.tolerance;
}
