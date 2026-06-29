#include "OcctlSurfaceBspline.h"


int OcctlSurfaceBspline::get_struct_version() const { return struct_version; }
void OcctlSurfaceBspline::set_struct_version(int val) { struct_version = val; }

int64_t OcctlSurfaceBspline::get_p_next() const { return p_next; }
void OcctlSurfaceBspline::set_p_next(int64_t val) { p_next = val; }

int OcctlSurfaceBspline::get_u_degree() const { return u_degree; }
void OcctlSurfaceBspline::set_u_degree(int val) { u_degree = val; }

int OcctlSurfaceBspline::get_v_degree() const { return v_degree; }
void OcctlSurfaceBspline::set_v_degree(int val) { v_degree = val; }

int OcctlSurfaceBspline::get_is_rational() const { return is_rational; }
void OcctlSurfaceBspline::set_is_rational(int val) { is_rational = val; }

int OcctlSurfaceBspline::get_is_u_periodic() const { return is_u_periodic; }
void OcctlSurfaceBspline::set_is_u_periodic(int val) { is_u_periodic = val; }

int OcctlSurfaceBspline::get_is_v_periodic() const { return is_v_periodic; }
void OcctlSurfaceBspline::set_is_v_periodic(int val) { is_v_periodic = val; }

int OcctlSurfaceBspline::get_u_pole_count() const { return u_pole_count; }
void OcctlSurfaceBspline::set_u_pole_count(int val) { u_pole_count = val; }

int OcctlSurfaceBspline::get_v_pole_count() const { return v_pole_count; }
void OcctlSurfaceBspline::set_v_pole_count(int val) { v_pole_count = val; }

int OcctlSurfaceBspline::get_u_knot_count() const { return u_knot_count; }
void OcctlSurfaceBspline::set_u_knot_count(int val) { u_knot_count = val; }

int OcctlSurfaceBspline::get_v_knot_count() const { return v_knot_count; }
void OcctlSurfaceBspline::set_v_knot_count(int val) { v_knot_count = val; }

int OcctlSurfaceBspline::get_u_flat_knot_count() const { return u_flat_knot_count; }
void OcctlSurfaceBspline::set_u_flat_knot_count(int val) { u_flat_knot_count = val; }

int OcctlSurfaceBspline::get_v_flat_knot_count() const { return v_flat_knot_count; }
void OcctlSurfaceBspline::set_v_flat_knot_count(int val) { v_flat_knot_count = val; }

Array OcctlSurfaceBspline::get_poles() const { return poles; }
void OcctlSurfaceBspline::set_poles(Array val) { poles = val; }

PackedFloat64Array OcctlSurfaceBspline::get_weights() const { return weights; }
void OcctlSurfaceBspline::set_weights(PackedFloat64Array val) { weights = val; }

PackedFloat64Array OcctlSurfaceBspline::get_u_knots() const { return u_knots; }
void OcctlSurfaceBspline::set_u_knots(PackedFloat64Array val) { u_knots = val; }

PackedFloat64Array OcctlSurfaceBspline::get_v_knots() const { return v_knots; }
void OcctlSurfaceBspline::set_v_knots(PackedFloat64Array val) { v_knots = val; }

PackedInt32Array OcctlSurfaceBspline::get_u_multiplicities() const { return u_multiplicities; }
void OcctlSurfaceBspline::set_u_multiplicities(PackedInt32Array val) { u_multiplicities = val; }

PackedInt32Array OcctlSurfaceBspline::get_v_multiplicities() const { return v_multiplicities; }
void OcctlSurfaceBspline::set_v_multiplicities(PackedInt32Array val) { v_multiplicities = val; }

PackedFloat64Array OcctlSurfaceBspline::get_u_flat_knots() const { return u_flat_knots; }
void OcctlSurfaceBspline::set_u_flat_knots(PackedFloat64Array val) { u_flat_knots = val; }

PackedFloat64Array OcctlSurfaceBspline::get_v_flat_knots() const { return v_flat_knots; }
void OcctlSurfaceBspline::set_v_flat_knots(PackedFloat64Array val) { v_flat_knots = val; }

void OcctlSurfaceBspline::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlSurfaceBspline::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlSurfaceBspline::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlSurfaceBspline::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlSurfaceBspline::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_degree"), &OcctlSurfaceBspline::get_u_degree);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_degree", "val"), &OcctlSurfaceBspline::set_u_degree);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "u_degree"), "set_u_degree", "get_u_degree");
    godot::ClassDB::bind_method(godot::D_METHOD("get_v_degree"), &OcctlSurfaceBspline::get_v_degree);
    godot::ClassDB::bind_method(godot::D_METHOD("set_v_degree", "val"), &OcctlSurfaceBspline::set_v_degree);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "v_degree"), "set_v_degree", "get_v_degree");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_rational"), &OcctlSurfaceBspline::get_is_rational);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_rational", "val"), &OcctlSurfaceBspline::set_is_rational);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_rational"), "set_is_rational", "get_is_rational");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_u_periodic"), &OcctlSurfaceBspline::get_is_u_periodic);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_u_periodic", "val"), &OcctlSurfaceBspline::set_is_u_periodic);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_u_periodic"), "set_is_u_periodic", "get_is_u_periodic");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_v_periodic"), &OcctlSurfaceBspline::get_is_v_periodic);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_v_periodic", "val"), &OcctlSurfaceBspline::set_is_v_periodic);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_v_periodic"), "set_is_v_periodic", "get_is_v_periodic");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_pole_count"), &OcctlSurfaceBspline::get_u_pole_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_pole_count", "val"), &OcctlSurfaceBspline::set_u_pole_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "u_pole_count"), "set_u_pole_count", "get_u_pole_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_v_pole_count"), &OcctlSurfaceBspline::get_v_pole_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_v_pole_count", "val"), &OcctlSurfaceBspline::set_v_pole_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "v_pole_count"), "set_v_pole_count", "get_v_pole_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_knot_count"), &OcctlSurfaceBspline::get_u_knot_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_knot_count", "val"), &OcctlSurfaceBspline::set_u_knot_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "u_knot_count"), "set_u_knot_count", "get_u_knot_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_v_knot_count"), &OcctlSurfaceBspline::get_v_knot_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_v_knot_count", "val"), &OcctlSurfaceBspline::set_v_knot_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "v_knot_count"), "set_v_knot_count", "get_v_knot_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_flat_knot_count"), &OcctlSurfaceBspline::get_u_flat_knot_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_flat_knot_count", "val"), &OcctlSurfaceBspline::set_u_flat_knot_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "u_flat_knot_count"), "set_u_flat_knot_count", "get_u_flat_knot_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_v_flat_knot_count"), &OcctlSurfaceBspline::get_v_flat_knot_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_v_flat_knot_count", "val"), &OcctlSurfaceBspline::set_v_flat_knot_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "v_flat_knot_count"), "set_v_flat_knot_count", "get_v_flat_knot_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_poles"), &OcctlSurfaceBspline::get_poles);
    godot::ClassDB::bind_method(godot::D_METHOD("set_poles", "val"), &OcctlSurfaceBspline::set_poles);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "poles"), "set_poles", "get_poles");
    godot::ClassDB::bind_method(godot::D_METHOD("get_weights"), &OcctlSurfaceBspline::get_weights);
    godot::ClassDB::bind_method(godot::D_METHOD("set_weights", "val"), &OcctlSurfaceBspline::set_weights);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "weights"), "set_weights", "get_weights");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_knots"), &OcctlSurfaceBspline::get_u_knots);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_knots", "val"), &OcctlSurfaceBspline::set_u_knots);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "u_knots"), "set_u_knots", "get_u_knots");
    godot::ClassDB::bind_method(godot::D_METHOD("get_v_knots"), &OcctlSurfaceBspline::get_v_knots);
    godot::ClassDB::bind_method(godot::D_METHOD("set_v_knots", "val"), &OcctlSurfaceBspline::set_v_knots);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "v_knots"), "set_v_knots", "get_v_knots");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_multiplicities"), &OcctlSurfaceBspline::get_u_multiplicities);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_multiplicities", "val"), &OcctlSurfaceBspline::set_u_multiplicities);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "u_multiplicities"), "set_u_multiplicities", "get_u_multiplicities");
    godot::ClassDB::bind_method(godot::D_METHOD("get_v_multiplicities"), &OcctlSurfaceBspline::get_v_multiplicities);
    godot::ClassDB::bind_method(godot::D_METHOD("set_v_multiplicities", "val"), &OcctlSurfaceBspline::set_v_multiplicities);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "v_multiplicities"), "set_v_multiplicities", "get_v_multiplicities");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_flat_knots"), &OcctlSurfaceBspline::get_u_flat_knots);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_flat_knots", "val"), &OcctlSurfaceBspline::set_u_flat_knots);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "u_flat_knots"), "set_u_flat_knots", "get_u_flat_knots");
    godot::ClassDB::bind_method(godot::D_METHOD("get_v_flat_knots"), &OcctlSurfaceBspline::get_v_flat_knots);
    godot::ClassDB::bind_method(godot::D_METHOD("set_v_flat_knots", "val"), &OcctlSurfaceBspline::set_v_flat_knots);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "v_flat_knots"), "set_v_flat_knots", "get_v_flat_knots");
}

occtl_surface_bspline_t OcctlSurfaceBspline::to_c() const {
    occtl_surface_bspline_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.u_degree = u_degree;
    result.v_degree = v_degree;
    result.is_rational = is_rational;
    result.is_u_periodic = is_u_periodic;
    result.is_v_periodic = is_v_periodic;
    result.u_pole_count = u_pole_count;
    result.v_pole_count = v_pole_count;
    result.u_knot_count = u_knot_count;
    result.v_knot_count = v_knot_count;
    result.u_flat_knot_count = u_flat_knot_count;
    result.v_flat_knot_count = v_flat_knot_count;
    _cache_poles.resize(poles.size());
    for (int _i = 0; _i < poles.size(); _i++) {
        Ref<OcctlPoint3> _item = poles[_i];
        if (_item.is_valid()) _cache_poles[_i] = _item->to_c();
        else _cache_poles[_i] = {};
    }
    result.poles = _cache_poles.data();
    result.weights = weights.ptr();
    result.u_knots = u_knots.ptr();
    result.v_knots = v_knots.ptr();
    result.u_multiplicities = u_multiplicities.ptr();
    result.v_multiplicities = v_multiplicities.ptr();
    result.u_flat_knots = u_flat_knots.ptr();
    result.v_flat_knots = v_flat_knots.ptr();
    return result;
}

Ref<OcctlSurfaceBspline> OcctlSurfaceBspline::from_c(const occtl_surface_bspline_t& val) {
    Ref<OcctlSurfaceBspline> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->u_degree = val.u_degree;
    r->v_degree = val.v_degree;
    r->is_rational = val.is_rational;
    r->is_u_periodic = val.is_u_periodic;
    r->is_v_periodic = val.is_v_periodic;
    r->u_pole_count = val.u_pole_count;
    r->v_pole_count = val.v_pole_count;
    r->u_knot_count = val.u_knot_count;
    r->v_knot_count = val.v_knot_count;
    r->u_flat_knot_count = val.u_flat_knot_count;
    r->v_flat_knot_count = val.v_flat_knot_count;
    // array field poles is not populated from C
    // array field weights is not populated from C
    // array field u_knots is not populated from C
    // array field v_knots is not populated from C
    // array field u_multiplicities is not populated from C
    // array field v_multiplicities is not populated from C
    // array field u_flat_knots is not populated from C
    // array field v_flat_knots is not populated from C
    return r;
}

void OcctlSurfaceBspline::copy_from_c(const occtl_surface_bspline_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    u_degree = val.u_degree;
    v_degree = val.v_degree;
    is_rational = val.is_rational;
    is_u_periodic = val.is_u_periodic;
    is_v_periodic = val.is_v_periodic;
    u_pole_count = val.u_pole_count;
    v_pole_count = val.v_pole_count;
    u_knot_count = val.u_knot_count;
    v_knot_count = val.v_knot_count;
    u_flat_knot_count = val.u_flat_knot_count;
    v_flat_knot_count = val.v_flat_knot_count;
    // array field poles is not populated from C
    // array field weights is not populated from C
    // array field u_knots is not populated from C
    // array field v_knots is not populated from C
    // array field u_multiplicities is not populated from C
    // array field v_multiplicities is not populated from C
    // array field u_flat_knots is not populated from C
    // array field v_flat_knots is not populated from C
}
