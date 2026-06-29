#include "OcctlCurve2dBsplineCreateInfo.h"


int OcctlCurve2dBsplineCreateInfo::get_struct_version() const { return struct_version; }
void OcctlCurve2dBsplineCreateInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlCurve2dBsplineCreateInfo::get_p_next() const { return p_next; }
void OcctlCurve2dBsplineCreateInfo::set_p_next(int64_t val) { p_next = val; }

Array OcctlCurve2dBsplineCreateInfo::get_poles() const { return poles; }
void OcctlCurve2dBsplineCreateInfo::set_poles(Array val) { poles = val; }

int OcctlCurve2dBsplineCreateInfo::get_pole_count() const { return pole_count; }
void OcctlCurve2dBsplineCreateInfo::set_pole_count(int val) { pole_count = val; }

PackedFloat64Array OcctlCurve2dBsplineCreateInfo::get_weights() const { return weights; }
void OcctlCurve2dBsplineCreateInfo::set_weights(PackedFloat64Array val) { weights = val; }

PackedFloat64Array OcctlCurve2dBsplineCreateInfo::get_knots() const { return knots; }
void OcctlCurve2dBsplineCreateInfo::set_knots(PackedFloat64Array val) { knots = val; }

PackedInt32Array OcctlCurve2dBsplineCreateInfo::get_multiplicities() const { return multiplicities; }
void OcctlCurve2dBsplineCreateInfo::set_multiplicities(PackedInt32Array val) { multiplicities = val; }

int OcctlCurve2dBsplineCreateInfo::get_knot_count() const { return knot_count; }
void OcctlCurve2dBsplineCreateInfo::set_knot_count(int val) { knot_count = val; }

int OcctlCurve2dBsplineCreateInfo::get_degree() const { return degree; }
void OcctlCurve2dBsplineCreateInfo::set_degree(int val) { degree = val; }

int OcctlCurve2dBsplineCreateInfo::get_is_periodic() const { return is_periodic; }
void OcctlCurve2dBsplineCreateInfo::set_is_periodic(int val) { is_periodic = val; }

void OcctlCurve2dBsplineCreateInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlCurve2dBsplineCreateInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlCurve2dBsplineCreateInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlCurve2dBsplineCreateInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlCurve2dBsplineCreateInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_poles"), &OcctlCurve2dBsplineCreateInfo::get_poles);
    godot::ClassDB::bind_method(godot::D_METHOD("set_poles", "val"), &OcctlCurve2dBsplineCreateInfo::set_poles);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "poles"), "set_poles", "get_poles");
    godot::ClassDB::bind_method(godot::D_METHOD("get_pole_count"), &OcctlCurve2dBsplineCreateInfo::get_pole_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_pole_count", "val"), &OcctlCurve2dBsplineCreateInfo::set_pole_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "pole_count"), "set_pole_count", "get_pole_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_weights"), &OcctlCurve2dBsplineCreateInfo::get_weights);
    godot::ClassDB::bind_method(godot::D_METHOD("set_weights", "val"), &OcctlCurve2dBsplineCreateInfo::set_weights);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "weights"), "set_weights", "get_weights");
    godot::ClassDB::bind_method(godot::D_METHOD("get_knots"), &OcctlCurve2dBsplineCreateInfo::get_knots);
    godot::ClassDB::bind_method(godot::D_METHOD("set_knots", "val"), &OcctlCurve2dBsplineCreateInfo::set_knots);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "knots"), "set_knots", "get_knots");
    godot::ClassDB::bind_method(godot::D_METHOD("get_multiplicities"), &OcctlCurve2dBsplineCreateInfo::get_multiplicities);
    godot::ClassDB::bind_method(godot::D_METHOD("set_multiplicities", "val"), &OcctlCurve2dBsplineCreateInfo::set_multiplicities);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "multiplicities"), "set_multiplicities", "get_multiplicities");
    godot::ClassDB::bind_method(godot::D_METHOD("get_knot_count"), &OcctlCurve2dBsplineCreateInfo::get_knot_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_knot_count", "val"), &OcctlCurve2dBsplineCreateInfo::set_knot_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "knot_count"), "set_knot_count", "get_knot_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_degree"), &OcctlCurve2dBsplineCreateInfo::get_degree);
    godot::ClassDB::bind_method(godot::D_METHOD("set_degree", "val"), &OcctlCurve2dBsplineCreateInfo::set_degree);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "degree"), "set_degree", "get_degree");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_periodic"), &OcctlCurve2dBsplineCreateInfo::get_is_periodic);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_periodic", "val"), &OcctlCurve2dBsplineCreateInfo::set_is_periodic);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_periodic"), "set_is_periodic", "get_is_periodic");
}

occtl_curve2d_bspline_create_info_t OcctlCurve2dBsplineCreateInfo::to_c() const {
    occtl_curve2d_bspline_create_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    _cache_poles.resize(poles.size());
    for (int _i = 0; _i < poles.size(); _i++) {
        Ref<OcctlPoint2> _item = poles[_i];
        if (_item.is_valid()) _cache_poles[_i] = _item->to_c();
        else _cache_poles[_i] = {};
    }
    result.poles = _cache_poles.data();
    result.pole_count = pole_count;
    result.weights = weights.ptr();
    result.knots = knots.ptr();
    result.multiplicities = multiplicities.ptr();
    result.knot_count = knot_count;
    result.degree = degree;
    result.is_periodic = is_periodic;
    return result;
}

Ref<OcctlCurve2dBsplineCreateInfo> OcctlCurve2dBsplineCreateInfo::from_c(const occtl_curve2d_bspline_create_info_t& val) {
    Ref<OcctlCurve2dBsplineCreateInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field poles is not populated from C
    r->pole_count = val.pole_count;
    // array field weights is not populated from C
    // array field knots is not populated from C
    // array field multiplicities is not populated from C
    r->knot_count = val.knot_count;
    r->degree = val.degree;
    r->is_periodic = val.is_periodic;
    return r;
}

void OcctlCurve2dBsplineCreateInfo::copy_from_c(const occtl_curve2d_bspline_create_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field poles is not populated from C
    pole_count = val.pole_count;
    // array field weights is not populated from C
    // array field knots is not populated from C
    // array field multiplicities is not populated from C
    knot_count = val.knot_count;
    degree = val.degree;
    is_periodic = val.is_periodic;
}
