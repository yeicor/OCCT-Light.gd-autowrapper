#include "OcctlSurfaceBsplineCreateInfo.h"


int OcctlSurfaceBsplineCreateInfo::get_struct_version() const { return struct_version; }
void OcctlSurfaceBsplineCreateInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlSurfaceBsplineCreateInfo::get_p_next() const { return p_next; }
void OcctlSurfaceBsplineCreateInfo::set_p_next(int64_t val) { p_next = val; }

Array OcctlSurfaceBsplineCreateInfo::get_poles() const { return poles; }
void OcctlSurfaceBsplineCreateInfo::set_poles(Array val) { poles = val; }

int OcctlSurfaceBsplineCreateInfo::get_u_pole_count() const { return u_pole_count; }
void OcctlSurfaceBsplineCreateInfo::set_u_pole_count(int val) { u_pole_count = val; }

int OcctlSurfaceBsplineCreateInfo::get_v_pole_count() const { return v_pole_count; }
void OcctlSurfaceBsplineCreateInfo::set_v_pole_count(int val) { v_pole_count = val; }

PackedFloat64Array OcctlSurfaceBsplineCreateInfo::get_weights() const { return weights; }
void OcctlSurfaceBsplineCreateInfo::set_weights(PackedFloat64Array val) { weights = val; }

PackedFloat64Array OcctlSurfaceBsplineCreateInfo::get_u_knots() const { return u_knots; }
void OcctlSurfaceBsplineCreateInfo::set_u_knots(PackedFloat64Array val) { u_knots = val; }

PackedInt32Array OcctlSurfaceBsplineCreateInfo::get_u_multiplicities() const { return u_multiplicities; }
void OcctlSurfaceBsplineCreateInfo::set_u_multiplicities(PackedInt32Array val) { u_multiplicities = val; }

int OcctlSurfaceBsplineCreateInfo::get_u_knot_count() const { return u_knot_count; }
void OcctlSurfaceBsplineCreateInfo::set_u_knot_count(int val) { u_knot_count = val; }

PackedFloat64Array OcctlSurfaceBsplineCreateInfo::get_v_knots() const { return v_knots; }
void OcctlSurfaceBsplineCreateInfo::set_v_knots(PackedFloat64Array val) { v_knots = val; }

PackedInt32Array OcctlSurfaceBsplineCreateInfo::get_v_multiplicities() const { return v_multiplicities; }
void OcctlSurfaceBsplineCreateInfo::set_v_multiplicities(PackedInt32Array val) { v_multiplicities = val; }

int OcctlSurfaceBsplineCreateInfo::get_v_knot_count() const { return v_knot_count; }
void OcctlSurfaceBsplineCreateInfo::set_v_knot_count(int val) { v_knot_count = val; }

int OcctlSurfaceBsplineCreateInfo::get_u_degree() const { return u_degree; }
void OcctlSurfaceBsplineCreateInfo::set_u_degree(int val) { u_degree = val; }

int OcctlSurfaceBsplineCreateInfo::get_v_degree() const { return v_degree; }
void OcctlSurfaceBsplineCreateInfo::set_v_degree(int val) { v_degree = val; }

int OcctlSurfaceBsplineCreateInfo::get_is_u_periodic() const { return is_u_periodic; }
void OcctlSurfaceBsplineCreateInfo::set_is_u_periodic(int val) { is_u_periodic = val; }

int OcctlSurfaceBsplineCreateInfo::get_is_v_periodic() const { return is_v_periodic; }
void OcctlSurfaceBsplineCreateInfo::set_is_v_periodic(int val) { is_v_periodic = val; }

void OcctlSurfaceBsplineCreateInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlSurfaceBsplineCreateInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlSurfaceBsplineCreateInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlSurfaceBsplineCreateInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlSurfaceBsplineCreateInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_poles"), &OcctlSurfaceBsplineCreateInfo::get_poles);
    godot::ClassDB::bind_method(godot::D_METHOD("set_poles", "val"), &OcctlSurfaceBsplineCreateInfo::set_poles);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "poles"), "set_poles", "get_poles");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_pole_count"), &OcctlSurfaceBsplineCreateInfo::get_u_pole_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_pole_count", "val"), &OcctlSurfaceBsplineCreateInfo::set_u_pole_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "u_pole_count"), "set_u_pole_count", "get_u_pole_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_v_pole_count"), &OcctlSurfaceBsplineCreateInfo::get_v_pole_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_v_pole_count", "val"), &OcctlSurfaceBsplineCreateInfo::set_v_pole_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "v_pole_count"), "set_v_pole_count", "get_v_pole_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_weights"), &OcctlSurfaceBsplineCreateInfo::get_weights);
    godot::ClassDB::bind_method(godot::D_METHOD("set_weights", "val"), &OcctlSurfaceBsplineCreateInfo::set_weights);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "weights"), "set_weights", "get_weights");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_knots"), &OcctlSurfaceBsplineCreateInfo::get_u_knots);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_knots", "val"), &OcctlSurfaceBsplineCreateInfo::set_u_knots);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "u_knots"), "set_u_knots", "get_u_knots");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_multiplicities"), &OcctlSurfaceBsplineCreateInfo::get_u_multiplicities);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_multiplicities", "val"), &OcctlSurfaceBsplineCreateInfo::set_u_multiplicities);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "u_multiplicities"), "set_u_multiplicities", "get_u_multiplicities");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_knot_count"), &OcctlSurfaceBsplineCreateInfo::get_u_knot_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_knot_count", "val"), &OcctlSurfaceBsplineCreateInfo::set_u_knot_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "u_knot_count"), "set_u_knot_count", "get_u_knot_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_v_knots"), &OcctlSurfaceBsplineCreateInfo::get_v_knots);
    godot::ClassDB::bind_method(godot::D_METHOD("set_v_knots", "val"), &OcctlSurfaceBsplineCreateInfo::set_v_knots);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "v_knots"), "set_v_knots", "get_v_knots");
    godot::ClassDB::bind_method(godot::D_METHOD("get_v_multiplicities"), &OcctlSurfaceBsplineCreateInfo::get_v_multiplicities);
    godot::ClassDB::bind_method(godot::D_METHOD("set_v_multiplicities", "val"), &OcctlSurfaceBsplineCreateInfo::set_v_multiplicities);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "v_multiplicities"), "set_v_multiplicities", "get_v_multiplicities");
    godot::ClassDB::bind_method(godot::D_METHOD("get_v_knot_count"), &OcctlSurfaceBsplineCreateInfo::get_v_knot_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_v_knot_count", "val"), &OcctlSurfaceBsplineCreateInfo::set_v_knot_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "v_knot_count"), "set_v_knot_count", "get_v_knot_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_degree"), &OcctlSurfaceBsplineCreateInfo::get_u_degree);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_degree", "val"), &OcctlSurfaceBsplineCreateInfo::set_u_degree);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "u_degree"), "set_u_degree", "get_u_degree");
    godot::ClassDB::bind_method(godot::D_METHOD("get_v_degree"), &OcctlSurfaceBsplineCreateInfo::get_v_degree);
    godot::ClassDB::bind_method(godot::D_METHOD("set_v_degree", "val"), &OcctlSurfaceBsplineCreateInfo::set_v_degree);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "v_degree"), "set_v_degree", "get_v_degree");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_u_periodic"), &OcctlSurfaceBsplineCreateInfo::get_is_u_periodic);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_u_periodic", "val"), &OcctlSurfaceBsplineCreateInfo::set_is_u_periodic);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_u_periodic"), "set_is_u_periodic", "get_is_u_periodic");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_v_periodic"), &OcctlSurfaceBsplineCreateInfo::get_is_v_periodic);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_v_periodic", "val"), &OcctlSurfaceBsplineCreateInfo::set_is_v_periodic);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_v_periodic"), "set_is_v_periodic", "get_is_v_periodic");
}

occtl_surface_bspline_create_info_t OcctlSurfaceBsplineCreateInfo::to_c() const {
    occtl_surface_bspline_create_info_t result = {};
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
    result.u_knots = u_knots.ptr();
    result.u_multiplicities = u_multiplicities.ptr();
    result.u_knot_count = u_knot_count;
    result.v_knots = v_knots.ptr();
    result.v_multiplicities = v_multiplicities.ptr();
    result.v_knot_count = v_knot_count;
    result.u_degree = u_degree;
    result.v_degree = v_degree;
    result.is_u_periodic = is_u_periodic;
    result.is_v_periodic = is_v_periodic;
    return result;
}

Ref<OcctlSurfaceBsplineCreateInfo> OcctlSurfaceBsplineCreateInfo::from_c(const occtl_surface_bspline_create_info_t& val) {
    Ref<OcctlSurfaceBsplineCreateInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field poles is not populated from C
    r->u_pole_count = val.u_pole_count;
    r->v_pole_count = val.v_pole_count;
    // array field weights is not populated from C
    // array field u_knots is not populated from C
    // array field u_multiplicities is not populated from C
    r->u_knot_count = val.u_knot_count;
    // array field v_knots is not populated from C
    // array field v_multiplicities is not populated from C
    r->v_knot_count = val.v_knot_count;
    r->u_degree = val.u_degree;
    r->v_degree = val.v_degree;
    r->is_u_periodic = val.is_u_periodic;
    r->is_v_periodic = val.is_v_periodic;
    return r;
}

void OcctlSurfaceBsplineCreateInfo::copy_from_c(const occtl_surface_bspline_create_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field poles is not populated from C
    u_pole_count = val.u_pole_count;
    v_pole_count = val.v_pole_count;
    // array field weights is not populated from C
    // array field u_knots is not populated from C
    // array field u_multiplicities is not populated from C
    u_knot_count = val.u_knot_count;
    // array field v_knots is not populated from C
    // array field v_multiplicities is not populated from C
    v_knot_count = val.v_knot_count;
    u_degree = val.u_degree;
    v_degree = val.v_degree;
    is_u_periodic = val.is_u_periodic;
    is_v_periodic = val.is_v_periodic;
}
