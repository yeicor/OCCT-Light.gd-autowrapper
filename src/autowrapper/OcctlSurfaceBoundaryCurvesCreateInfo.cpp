#include "OcctlSurfaceBoundaryCurvesCreateInfo.h"


int OcctlSurfaceBoundaryCurvesCreateInfo::get_struct_version() const { return struct_version; }
void OcctlSurfaceBoundaryCurvesCreateInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlSurfaceBoundaryCurvesCreateInfo::get_p_next() const { return p_next; }
void OcctlSurfaceBoundaryCurvesCreateInfo::set_p_next(int64_t val) { p_next = val; }

PackedInt64Array OcctlSurfaceBoundaryCurvesCreateInfo::get_curves() const { return curves; }
void OcctlSurfaceBoundaryCurvesCreateInfo::set_curves(PackedInt64Array val) { curves = val; }

int OcctlSurfaceBoundaryCurvesCreateInfo::get_curve_count() const { return curve_count; }
void OcctlSurfaceBoundaryCurvesCreateInfo::set_curve_count(int val) { curve_count = val; }

int OcctlSurfaceBoundaryCurvesCreateInfo::get_style() const { return style; }
void OcctlSurfaceBoundaryCurvesCreateInfo::set_style(int val) { style = val; }

void OcctlSurfaceBoundaryCurvesCreateInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlSurfaceBoundaryCurvesCreateInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlSurfaceBoundaryCurvesCreateInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlSurfaceBoundaryCurvesCreateInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlSurfaceBoundaryCurvesCreateInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_curves"), &OcctlSurfaceBoundaryCurvesCreateInfo::get_curves);
    godot::ClassDB::bind_method(godot::D_METHOD("set_curves", "val"), &OcctlSurfaceBoundaryCurvesCreateInfo::set_curves);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "curves"), "set_curves", "get_curves");
    godot::ClassDB::bind_method(godot::D_METHOD("get_curve_count"), &OcctlSurfaceBoundaryCurvesCreateInfo::get_curve_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_curve_count", "val"), &OcctlSurfaceBoundaryCurvesCreateInfo::set_curve_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "curve_count"), "set_curve_count", "get_curve_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_style"), &OcctlSurfaceBoundaryCurvesCreateInfo::get_style);
    godot::ClassDB::bind_method(godot::D_METHOD("set_style", "val"), &OcctlSurfaceBoundaryCurvesCreateInfo::set_style);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "style"), "set_style", "get_style");
}

occtl_surface_boundary_curves_create_info_t OcctlSurfaceBoundaryCurvesCreateInfo::to_c() const {
    occtl_surface_boundary_curves_create_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.curves = reinterpret_cast<const occtl_rep_id_t*>(curves.ptr());
    result.curve_count = curve_count;
    result.style = static_cast<occtl_surface_filling_style_t>(style);
    return result;
}

Ref<OcctlSurfaceBoundaryCurvesCreateInfo> OcctlSurfaceBoundaryCurvesCreateInfo::from_c(const occtl_surface_boundary_curves_create_info_t& val) {
    Ref<OcctlSurfaceBoundaryCurvesCreateInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field curves is not populated from C
    r->curve_count = val.curve_count;
    r->style = static_cast<int>(val.style);
    return r;
}

void OcctlSurfaceBoundaryCurvesCreateInfo::copy_from_c(const occtl_surface_boundary_curves_create_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field curves is not populated from C
    curve_count = val.curve_count;
    style = static_cast<int>(val.style);
}
