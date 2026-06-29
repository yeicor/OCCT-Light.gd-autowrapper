#include "OcctlSurfaceCurveGridCreateInfo.h"


int OcctlSurfaceCurveGridCreateInfo::get_struct_version() const { return struct_version; }
void OcctlSurfaceCurveGridCreateInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlSurfaceCurveGridCreateInfo::get_p_next() const { return p_next; }
void OcctlSurfaceCurveGridCreateInfo::set_p_next(int64_t val) { p_next = val; }

PackedInt64Array OcctlSurfaceCurveGridCreateInfo::get_u_curves() const { return u_curves; }
void OcctlSurfaceCurveGridCreateInfo::set_u_curves(PackedInt64Array val) { u_curves = val; }

int OcctlSurfaceCurveGridCreateInfo::get_u_curve_count() const { return u_curve_count; }
void OcctlSurfaceCurveGridCreateInfo::set_u_curve_count(int val) { u_curve_count = val; }

PackedInt64Array OcctlSurfaceCurveGridCreateInfo::get_v_curves() const { return v_curves; }
void OcctlSurfaceCurveGridCreateInfo::set_v_curves(PackedInt64Array val) { v_curves = val; }

int OcctlSurfaceCurveGridCreateInfo::get_v_curve_count() const { return v_curve_count; }
void OcctlSurfaceCurveGridCreateInfo::set_v_curve_count(int val) { v_curve_count = val; }

double OcctlSurfaceCurveGridCreateInfo::get_tolerance() const { return tolerance; }
void OcctlSurfaceCurveGridCreateInfo::set_tolerance(double val) { tolerance = val; }

int OcctlSurfaceCurveGridCreateInfo::get_parallel() const { return parallel; }
void OcctlSurfaceCurveGridCreateInfo::set_parallel(int val) { parallel = val; }

void OcctlSurfaceCurveGridCreateInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlSurfaceCurveGridCreateInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlSurfaceCurveGridCreateInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlSurfaceCurveGridCreateInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlSurfaceCurveGridCreateInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_curves"), &OcctlSurfaceCurveGridCreateInfo::get_u_curves);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_curves", "val"), &OcctlSurfaceCurveGridCreateInfo::set_u_curves);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "u_curves"), "set_u_curves", "get_u_curves");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_curve_count"), &OcctlSurfaceCurveGridCreateInfo::get_u_curve_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_curve_count", "val"), &OcctlSurfaceCurveGridCreateInfo::set_u_curve_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "u_curve_count"), "set_u_curve_count", "get_u_curve_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_v_curves"), &OcctlSurfaceCurveGridCreateInfo::get_v_curves);
    godot::ClassDB::bind_method(godot::D_METHOD("set_v_curves", "val"), &OcctlSurfaceCurveGridCreateInfo::set_v_curves);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "v_curves"), "set_v_curves", "get_v_curves");
    godot::ClassDB::bind_method(godot::D_METHOD("get_v_curve_count"), &OcctlSurfaceCurveGridCreateInfo::get_v_curve_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_v_curve_count", "val"), &OcctlSurfaceCurveGridCreateInfo::set_v_curve_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "v_curve_count"), "set_v_curve_count", "get_v_curve_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlSurfaceCurveGridCreateInfo::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlSurfaceCurveGridCreateInfo::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_parallel"), &OcctlSurfaceCurveGridCreateInfo::get_parallel);
    godot::ClassDB::bind_method(godot::D_METHOD("set_parallel", "val"), &OcctlSurfaceCurveGridCreateInfo::set_parallel);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "parallel"), "set_parallel", "get_parallel");
}

occtl_surface_curve_grid_create_info_t OcctlSurfaceCurveGridCreateInfo::to_c() const {
    occtl_surface_curve_grid_create_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.u_curves = reinterpret_cast<const occtl_rep_id_t*>(u_curves.ptr());
    result.u_curve_count = u_curve_count;
    result.v_curves = reinterpret_cast<const occtl_rep_id_t*>(v_curves.ptr());
    result.v_curve_count = v_curve_count;
    result.tolerance = tolerance;
    result.parallel = parallel;
    return result;
}

Ref<OcctlSurfaceCurveGridCreateInfo> OcctlSurfaceCurveGridCreateInfo::from_c(const occtl_surface_curve_grid_create_info_t& val) {
    Ref<OcctlSurfaceCurveGridCreateInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field u_curves is not populated from C
    r->u_curve_count = val.u_curve_count;
    // array field v_curves is not populated from C
    r->v_curve_count = val.v_curve_count;
    r->tolerance = val.tolerance;
    r->parallel = val.parallel;
    return r;
}

void OcctlSurfaceCurveGridCreateInfo::copy_from_c(const occtl_surface_curve_grid_create_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field u_curves is not populated from C
    u_curve_count = val.u_curve_count;
    // array field v_curves is not populated from C
    v_curve_count = val.v_curve_count;
    tolerance = val.tolerance;
    parallel = val.parallel;
}
