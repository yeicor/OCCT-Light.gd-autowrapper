#include "OcctlPrimFaceFromPointGridOptions.h"

#include "OcctlSurfacePointGridCreateInfo.h"

int OcctlPrimFaceFromPointGridOptions::get_struct_version() const { return struct_version; }
void OcctlPrimFaceFromPointGridOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimFaceFromPointGridOptions::get_p_next() const { return p_next; }
void OcctlPrimFaceFromPointGridOptions::set_p_next(int64_t val) { p_next = val; }

Ref<OcctlSurfacePointGridCreateInfo> OcctlPrimFaceFromPointGridOptions::get_surface() const { return surface; }
void OcctlPrimFaceFromPointGridOptions::set_surface(Ref<OcctlSurfacePointGridCreateInfo> val) { surface = val; }

double OcctlPrimFaceFromPointGridOptions::get_tolerance() const { return tolerance; }
void OcctlPrimFaceFromPointGridOptions::set_tolerance(double val) { tolerance = val; }

void OcctlPrimFaceFromPointGridOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimFaceFromPointGridOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimFaceFromPointGridOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimFaceFromPointGridOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimFaceFromPointGridOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_surface"), &OcctlPrimFaceFromPointGridOptions::get_surface);
    godot::ClassDB::bind_method(godot::D_METHOD("set_surface", "val"), &OcctlPrimFaceFromPointGridOptions::set_surface);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "surface"), "set_surface", "get_surface");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlPrimFaceFromPointGridOptions::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlPrimFaceFromPointGridOptions::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
}

occtl_prim_face_from_point_grid_options_t OcctlPrimFaceFromPointGridOptions::to_c() const {
    occtl_prim_face_from_point_grid_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.surface = surface->to_c();
    result.tolerance = tolerance;
    return result;
}

Ref<OcctlPrimFaceFromPointGridOptions> OcctlPrimFaceFromPointGridOptions::from_c(const occtl_prim_face_from_point_grid_options_t& val) {
    Ref<OcctlPrimFaceFromPointGridOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->surface = OcctlSurfacePointGridCreateInfo::from_c(val.surface);
    r->tolerance = val.tolerance;
    return r;
}

void OcctlPrimFaceFromPointGridOptions::copy_from_c(const occtl_prim_face_from_point_grid_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    surface = OcctlSurfacePointGridCreateInfo::from_c(val.surface);
    tolerance = val.tolerance;
}
