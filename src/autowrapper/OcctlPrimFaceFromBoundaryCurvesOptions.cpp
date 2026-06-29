#include "OcctlPrimFaceFromBoundaryCurvesOptions.h"

#include "OcctlSurfaceBoundaryCurvesCreateInfo.h"

int OcctlPrimFaceFromBoundaryCurvesOptions::get_struct_version() const { return struct_version; }
void OcctlPrimFaceFromBoundaryCurvesOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimFaceFromBoundaryCurvesOptions::get_p_next() const { return p_next; }
void OcctlPrimFaceFromBoundaryCurvesOptions::set_p_next(int64_t val) { p_next = val; }

Ref<OcctlSurfaceBoundaryCurvesCreateInfo> OcctlPrimFaceFromBoundaryCurvesOptions::get_surface() const { return surface; }
void OcctlPrimFaceFromBoundaryCurvesOptions::set_surface(Ref<OcctlSurfaceBoundaryCurvesCreateInfo> val) { surface = val; }

double OcctlPrimFaceFromBoundaryCurvesOptions::get_tolerance() const { return tolerance; }
void OcctlPrimFaceFromBoundaryCurvesOptions::set_tolerance(double val) { tolerance = val; }

void OcctlPrimFaceFromBoundaryCurvesOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimFaceFromBoundaryCurvesOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimFaceFromBoundaryCurvesOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimFaceFromBoundaryCurvesOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimFaceFromBoundaryCurvesOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_surface"), &OcctlPrimFaceFromBoundaryCurvesOptions::get_surface);
    godot::ClassDB::bind_method(godot::D_METHOD("set_surface", "val"), &OcctlPrimFaceFromBoundaryCurvesOptions::set_surface);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "surface"), "set_surface", "get_surface");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlPrimFaceFromBoundaryCurvesOptions::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlPrimFaceFromBoundaryCurvesOptions::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
}

occtl_prim_face_from_boundary_curves_options_t OcctlPrimFaceFromBoundaryCurvesOptions::to_c() const {
    occtl_prim_face_from_boundary_curves_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.surface = surface->to_c();
    result.tolerance = tolerance;
    return result;
}

Ref<OcctlPrimFaceFromBoundaryCurvesOptions> OcctlPrimFaceFromBoundaryCurvesOptions::from_c(const occtl_prim_face_from_boundary_curves_options_t& val) {
    Ref<OcctlPrimFaceFromBoundaryCurvesOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->surface = OcctlSurfaceBoundaryCurvesCreateInfo::from_c(val.surface);
    r->tolerance = val.tolerance;
    return r;
}

void OcctlPrimFaceFromBoundaryCurvesOptions::copy_from_c(const occtl_prim_face_from_boundary_curves_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    surface = OcctlSurfaceBoundaryCurvesCreateInfo::from_c(val.surface);
    tolerance = val.tolerance;
}
