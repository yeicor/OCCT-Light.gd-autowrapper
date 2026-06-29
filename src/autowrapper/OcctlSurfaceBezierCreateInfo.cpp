#include "OcctlSurfaceBezierCreateInfo.h"


int OcctlSurfaceBezierCreateInfo::get_struct_version() const { return struct_version; }
void OcctlSurfaceBezierCreateInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlSurfaceBezierCreateInfo::get_p_next() const { return p_next; }
void OcctlSurfaceBezierCreateInfo::set_p_next(int64_t val) { p_next = val; }

Array OcctlSurfaceBezierCreateInfo::get_poles() const { return poles; }
void OcctlSurfaceBezierCreateInfo::set_poles(Array val) { poles = val; }

int OcctlSurfaceBezierCreateInfo::get_u_pole_count() const { return u_pole_count; }
void OcctlSurfaceBezierCreateInfo::set_u_pole_count(int val) { u_pole_count = val; }

int OcctlSurfaceBezierCreateInfo::get_v_pole_count() const { return v_pole_count; }
void OcctlSurfaceBezierCreateInfo::set_v_pole_count(int val) { v_pole_count = val; }

PackedFloat64Array OcctlSurfaceBezierCreateInfo::get_weights() const { return weights; }
void OcctlSurfaceBezierCreateInfo::set_weights(PackedFloat64Array val) { weights = val; }

void OcctlSurfaceBezierCreateInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlSurfaceBezierCreateInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlSurfaceBezierCreateInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlSurfaceBezierCreateInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlSurfaceBezierCreateInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_poles"), &OcctlSurfaceBezierCreateInfo::get_poles);
    godot::ClassDB::bind_method(godot::D_METHOD("set_poles", "val"), &OcctlSurfaceBezierCreateInfo::set_poles);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "poles"), "set_poles", "get_poles");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_pole_count"), &OcctlSurfaceBezierCreateInfo::get_u_pole_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_pole_count", "val"), &OcctlSurfaceBezierCreateInfo::set_u_pole_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "u_pole_count"), "set_u_pole_count", "get_u_pole_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_v_pole_count"), &OcctlSurfaceBezierCreateInfo::get_v_pole_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_v_pole_count", "val"), &OcctlSurfaceBezierCreateInfo::set_v_pole_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "v_pole_count"), "set_v_pole_count", "get_v_pole_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_weights"), &OcctlSurfaceBezierCreateInfo::get_weights);
    godot::ClassDB::bind_method(godot::D_METHOD("set_weights", "val"), &OcctlSurfaceBezierCreateInfo::set_weights);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "weights"), "set_weights", "get_weights");
}

occtl_surface_bezier_create_info_t OcctlSurfaceBezierCreateInfo::to_c() const {
    occtl_surface_bezier_create_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    _cache_poles.resize(poles.size());
    for (int _i = 0; _i < poles.size(); _i++) {
        Ref<OcctlPoint3> _item = poles[_i];
        if (_item.is_valid()) _cache_poles[_i] = _item->to_c();
        else _cache_poles[_i] = {};
    }
    result.poles = _cache_poles.data();
    result.u_pole_count = u_pole_count;
    result.v_pole_count = v_pole_count;
    result.weights = weights.ptr();
    return result;
}

Ref<OcctlSurfaceBezierCreateInfo> OcctlSurfaceBezierCreateInfo::from_c(const occtl_surface_bezier_create_info_t& val) {
    Ref<OcctlSurfaceBezierCreateInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field poles is not populated from C
    r->u_pole_count = val.u_pole_count;
    r->v_pole_count = val.v_pole_count;
    // array field weights is not populated from C
    return r;
}

void OcctlSurfaceBezierCreateInfo::copy_from_c(const occtl_surface_bezier_create_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field poles is not populated from C
    u_pole_count = val.u_pole_count;
    v_pole_count = val.v_pole_count;
    // array field weights is not populated from C
}
