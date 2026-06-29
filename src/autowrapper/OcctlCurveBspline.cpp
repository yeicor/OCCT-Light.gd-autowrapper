#include "OcctlCurveBspline.h"


int OcctlCurveBspline::get_struct_version() const { return struct_version; }
void OcctlCurveBspline::set_struct_version(int val) { struct_version = val; }

int64_t OcctlCurveBspline::get_p_next() const { return p_next; }
void OcctlCurveBspline::set_p_next(int64_t val) { p_next = val; }

int OcctlCurveBspline::get_degree() const { return degree; }
void OcctlCurveBspline::set_degree(int val) { degree = val; }

int OcctlCurveBspline::get_is_rational() const { return is_rational; }
void OcctlCurveBspline::set_is_rational(int val) { is_rational = val; }

int OcctlCurveBspline::get_is_periodic() const { return is_periodic; }
void OcctlCurveBspline::set_is_periodic(int val) { is_periodic = val; }

int OcctlCurveBspline::get_is_closed() const { return is_closed; }
void OcctlCurveBspline::set_is_closed(int val) { is_closed = val; }

int OcctlCurveBspline::get_continuity() const { return continuity; }
void OcctlCurveBspline::set_continuity(int val) { continuity = val; }

int OcctlCurveBspline::get_pole_count() const { return pole_count; }
void OcctlCurveBspline::set_pole_count(int val) { pole_count = val; }

int OcctlCurveBspline::get_knot_count() const { return knot_count; }
void OcctlCurveBspline::set_knot_count(int val) { knot_count = val; }

int OcctlCurveBspline::get_flat_knot_count() const { return flat_knot_count; }
void OcctlCurveBspline::set_flat_knot_count(int val) { flat_knot_count = val; }

Array OcctlCurveBspline::get_poles() const { return poles; }
void OcctlCurveBspline::set_poles(Array val) { poles = val; }

PackedFloat64Array OcctlCurveBspline::get_weights() const { return weights; }
void OcctlCurveBspline::set_weights(PackedFloat64Array val) { weights = val; }

PackedFloat64Array OcctlCurveBspline::get_knots() const { return knots; }
void OcctlCurveBspline::set_knots(PackedFloat64Array val) { knots = val; }

PackedInt32Array OcctlCurveBspline::get_multiplicities() const { return multiplicities; }
void OcctlCurveBspline::set_multiplicities(PackedInt32Array val) { multiplicities = val; }

PackedFloat64Array OcctlCurveBspline::get_flat_knots() const { return flat_knots; }
void OcctlCurveBspline::set_flat_knots(PackedFloat64Array val) { flat_knots = val; }

void OcctlCurveBspline::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlCurveBspline::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlCurveBspline::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlCurveBspline::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlCurveBspline::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_degree"), &OcctlCurveBspline::get_degree);
    godot::ClassDB::bind_method(godot::D_METHOD("set_degree", "val"), &OcctlCurveBspline::set_degree);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "degree"), "set_degree", "get_degree");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_rational"), &OcctlCurveBspline::get_is_rational);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_rational", "val"), &OcctlCurveBspline::set_is_rational);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_rational"), "set_is_rational", "get_is_rational");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_periodic"), &OcctlCurveBspline::get_is_periodic);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_periodic", "val"), &OcctlCurveBspline::set_is_periodic);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_periodic"), "set_is_periodic", "get_is_periodic");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_closed"), &OcctlCurveBspline::get_is_closed);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_closed", "val"), &OcctlCurveBspline::set_is_closed);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_closed"), "set_is_closed", "get_is_closed");
    godot::ClassDB::bind_method(godot::D_METHOD("get_continuity"), &OcctlCurveBspline::get_continuity);
    godot::ClassDB::bind_method(godot::D_METHOD("set_continuity", "val"), &OcctlCurveBspline::set_continuity);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "continuity"), "set_continuity", "get_continuity");
    godot::ClassDB::bind_method(godot::D_METHOD("get_pole_count"), &OcctlCurveBspline::get_pole_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_pole_count", "val"), &OcctlCurveBspline::set_pole_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "pole_count"), "set_pole_count", "get_pole_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_knot_count"), &OcctlCurveBspline::get_knot_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_knot_count", "val"), &OcctlCurveBspline::set_knot_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "knot_count"), "set_knot_count", "get_knot_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_flat_knot_count"), &OcctlCurveBspline::get_flat_knot_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_flat_knot_count", "val"), &OcctlCurveBspline::set_flat_knot_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "flat_knot_count"), "set_flat_knot_count", "get_flat_knot_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_poles"), &OcctlCurveBspline::get_poles);
    godot::ClassDB::bind_method(godot::D_METHOD("set_poles", "val"), &OcctlCurveBspline::set_poles);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "poles"), "set_poles", "get_poles");
    godot::ClassDB::bind_method(godot::D_METHOD("get_weights"), &OcctlCurveBspline::get_weights);
    godot::ClassDB::bind_method(godot::D_METHOD("set_weights", "val"), &OcctlCurveBspline::set_weights);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "weights"), "set_weights", "get_weights");
    godot::ClassDB::bind_method(godot::D_METHOD("get_knots"), &OcctlCurveBspline::get_knots);
    godot::ClassDB::bind_method(godot::D_METHOD("set_knots", "val"), &OcctlCurveBspline::set_knots);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "knots"), "set_knots", "get_knots");
    godot::ClassDB::bind_method(godot::D_METHOD("get_multiplicities"), &OcctlCurveBspline::get_multiplicities);
    godot::ClassDB::bind_method(godot::D_METHOD("set_multiplicities", "val"), &OcctlCurveBspline::set_multiplicities);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "multiplicities"), "set_multiplicities", "get_multiplicities");
    godot::ClassDB::bind_method(godot::D_METHOD("get_flat_knots"), &OcctlCurveBspline::get_flat_knots);
    godot::ClassDB::bind_method(godot::D_METHOD("set_flat_knots", "val"), &OcctlCurveBspline::set_flat_knots);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "flat_knots"), "set_flat_knots", "get_flat_knots");
}

occtl_curve_bspline_t OcctlCurveBspline::to_c() const {
    occtl_curve_bspline_t result = {};
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
        Ref<OcctlPoint3> _item = poles[_i];
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

Ref<OcctlCurveBspline> OcctlCurveBspline::from_c(const occtl_curve_bspline_t& val) {
    Ref<OcctlCurveBspline> r;
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

void OcctlCurveBspline::copy_from_c(const occtl_curve_bspline_t& val) {
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
