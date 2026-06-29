#include "OcctlCurve2dBspline.h"


int OcctlCurve2dBspline::get_struct_version() const { return struct_version; }
void OcctlCurve2dBspline::set_struct_version(int val) { struct_version = val; }

int64_t OcctlCurve2dBspline::get_p_next() const { return p_next; }
void OcctlCurve2dBspline::set_p_next(int64_t val) { p_next = val; }

int OcctlCurve2dBspline::get_degree() const { return degree; }
void OcctlCurve2dBspline::set_degree(int val) { degree = val; }

int OcctlCurve2dBspline::get_is_rational() const { return is_rational; }
void OcctlCurve2dBspline::set_is_rational(int val) { is_rational = val; }

int OcctlCurve2dBspline::get_is_periodic() const { return is_periodic; }
void OcctlCurve2dBspline::set_is_periodic(int val) { is_periodic = val; }

int OcctlCurve2dBspline::get_is_closed() const { return is_closed; }
void OcctlCurve2dBspline::set_is_closed(int val) { is_closed = val; }

int OcctlCurve2dBspline::get_continuity() const { return continuity; }
void OcctlCurve2dBspline::set_continuity(int val) { continuity = val; }

int OcctlCurve2dBspline::get_pole_count() const { return pole_count; }
void OcctlCurve2dBspline::set_pole_count(int val) { pole_count = val; }

int OcctlCurve2dBspline::get_knot_count() const { return knot_count; }
void OcctlCurve2dBspline::set_knot_count(int val) { knot_count = val; }

int OcctlCurve2dBspline::get_flat_knot_count() const { return flat_knot_count; }
void OcctlCurve2dBspline::set_flat_knot_count(int val) { flat_knot_count = val; }

Array OcctlCurve2dBspline::get_poles() const { return poles; }
void OcctlCurve2dBspline::set_poles(Array val) { poles = val; }

PackedFloat64Array OcctlCurve2dBspline::get_weights() const { return weights; }
void OcctlCurve2dBspline::set_weights(PackedFloat64Array val) { weights = val; }

PackedFloat64Array OcctlCurve2dBspline::get_knots() const { return knots; }
void OcctlCurve2dBspline::set_knots(PackedFloat64Array val) { knots = val; }

PackedInt32Array OcctlCurve2dBspline::get_multiplicities() const { return multiplicities; }
void OcctlCurve2dBspline::set_multiplicities(PackedInt32Array val) { multiplicities = val; }

PackedFloat64Array OcctlCurve2dBspline::get_flat_knots() const { return flat_knots; }
void OcctlCurve2dBspline::set_flat_knots(PackedFloat64Array val) { flat_knots = val; }

void OcctlCurve2dBspline::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlCurve2dBspline::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlCurve2dBspline::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlCurve2dBspline::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlCurve2dBspline::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_degree"), &OcctlCurve2dBspline::get_degree);
    godot::ClassDB::bind_method(godot::D_METHOD("set_degree", "val"), &OcctlCurve2dBspline::set_degree);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "degree"), "set_degree", "get_degree");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_rational"), &OcctlCurve2dBspline::get_is_rational);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_rational", "val"), &OcctlCurve2dBspline::set_is_rational);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_rational"), "set_is_rational", "get_is_rational");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_periodic"), &OcctlCurve2dBspline::get_is_periodic);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_periodic", "val"), &OcctlCurve2dBspline::set_is_periodic);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_periodic"), "set_is_periodic", "get_is_periodic");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_closed"), &OcctlCurve2dBspline::get_is_closed);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_closed", "val"), &OcctlCurve2dBspline::set_is_closed);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_closed"), "set_is_closed", "get_is_closed");
    godot::ClassDB::bind_method(godot::D_METHOD("get_continuity"), &OcctlCurve2dBspline::get_continuity);
    godot::ClassDB::bind_method(godot::D_METHOD("set_continuity", "val"), &OcctlCurve2dBspline::set_continuity);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "continuity"), "set_continuity", "get_continuity");
    godot::ClassDB::bind_method(godot::D_METHOD("get_pole_count"), &OcctlCurve2dBspline::get_pole_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_pole_count", "val"), &OcctlCurve2dBspline::set_pole_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "pole_count"), "set_pole_count", "get_pole_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_knot_count"), &OcctlCurve2dBspline::get_knot_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_knot_count", "val"), &OcctlCurve2dBspline::set_knot_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "knot_count"), "set_knot_count", "get_knot_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_flat_knot_count"), &OcctlCurve2dBspline::get_flat_knot_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_flat_knot_count", "val"), &OcctlCurve2dBspline::set_flat_knot_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "flat_knot_count"), "set_flat_knot_count", "get_flat_knot_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_poles"), &OcctlCurve2dBspline::get_poles);
    godot::ClassDB::bind_method(godot::D_METHOD("set_poles", "val"), &OcctlCurve2dBspline::set_poles);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "poles"), "set_poles", "get_poles");
    godot::ClassDB::bind_method(godot::D_METHOD("get_weights"), &OcctlCurve2dBspline::get_weights);
    godot::ClassDB::bind_method(godot::D_METHOD("set_weights", "val"), &OcctlCurve2dBspline::set_weights);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "weights"), "set_weights", "get_weights");
    godot::ClassDB::bind_method(godot::D_METHOD("get_knots"), &OcctlCurve2dBspline::get_knots);
    godot::ClassDB::bind_method(godot::D_METHOD("set_knots", "val"), &OcctlCurve2dBspline::set_knots);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "knots"), "set_knots", "get_knots");
    godot::ClassDB::bind_method(godot::D_METHOD("get_multiplicities"), &OcctlCurve2dBspline::get_multiplicities);
    godot::ClassDB::bind_method(godot::D_METHOD("set_multiplicities", "val"), &OcctlCurve2dBspline::set_multiplicities);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "multiplicities"), "set_multiplicities", "get_multiplicities");
    godot::ClassDB::bind_method(godot::D_METHOD("get_flat_knots"), &OcctlCurve2dBspline::get_flat_knots);
    godot::ClassDB::bind_method(godot::D_METHOD("set_flat_knots", "val"), &OcctlCurve2dBspline::set_flat_knots);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "flat_knots"), "set_flat_knots", "get_flat_knots");
}

occtl_curve2d_bspline_t OcctlCurve2dBspline::to_c() const {
    occtl_curve2d_bspline_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.degree = degree;
    result.is_rational = is_rational;
    result.is_periodic = is_periodic;
    result.is_closed = is_closed;
    result.continuity = continuity;
    result.pole_count = pole_count;
    result.knot_count = knot_count;
    result.flat_knot_count = flat_knot_count;
    _cache_poles.resize(poles.size());
    for (int _i = 0; _i < poles.size(); _i++) {
        Ref<OcctlPoint2> _item = poles[_i];
        if (_item.is_valid()) _cache_poles[_i] = _item->to_c();
        else _cache_poles[_i] = {};
    }
    result.poles = _cache_poles.data();
    result.weights = weights.ptr();
    result.knots = knots.ptr();
    result.multiplicities = multiplicities.ptr();
    result.flat_knots = flat_knots.ptr();
    return result;
}

Ref<OcctlCurve2dBspline> OcctlCurve2dBspline::from_c(const occtl_curve2d_bspline_t& val) {
    Ref<OcctlCurve2dBspline> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->degree = val.degree;
    r->is_rational = val.is_rational;
    r->is_periodic = val.is_periodic;
    r->is_closed = val.is_closed;
    r->continuity = val.continuity;
    r->pole_count = val.pole_count;
    r->knot_count = val.knot_count;
    r->flat_knot_count = val.flat_knot_count;
    // array field poles is not populated from C
    // array field weights is not populated from C
    // array field knots is not populated from C
    // array field multiplicities is not populated from C
    // array field flat_knots is not populated from C
    return r;
}

void OcctlCurve2dBspline::copy_from_c(const occtl_curve2d_bspline_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    degree = val.degree;
    is_rational = val.is_rational;
    is_periodic = val.is_periodic;
    is_closed = val.is_closed;
    continuity = val.continuity;
    pole_count = val.pole_count;
    knot_count = val.knot_count;
    flat_knot_count = val.flat_knot_count;
    // array field poles is not populated from C
    // array field weights is not populated from C
    // array field knots is not populated from C
    // array field multiplicities is not populated from C
    // array field flat_knots is not populated from C
}
