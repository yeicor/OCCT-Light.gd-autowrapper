#include "OcctlCurveBsplineCreateInfo.h"


int OcctlCurveBsplineCreateInfo::get_struct_version() const { return struct_version; }
void OcctlCurveBsplineCreateInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlCurveBsplineCreateInfo::get_p_next() const { return p_next; }
void OcctlCurveBsplineCreateInfo::set_p_next(int64_t val) { p_next = val; }

Array OcctlCurveBsplineCreateInfo::get_poles() const { return poles; }
void OcctlCurveBsplineCreateInfo::set_poles(Array val) { poles = val; }

int OcctlCurveBsplineCreateInfo::get_pole_count() const { return pole_count; }
void OcctlCurveBsplineCreateInfo::set_pole_count(int val) { pole_count = val; }

PackedFloat64Array OcctlCurveBsplineCreateInfo::get_weights() const { return weights; }
void OcctlCurveBsplineCreateInfo::set_weights(PackedFloat64Array val) { weights = val; }

PackedFloat64Array OcctlCurveBsplineCreateInfo::get_knots() const { return knots; }
void OcctlCurveBsplineCreateInfo::set_knots(PackedFloat64Array val) { knots = val; }

PackedInt32Array OcctlCurveBsplineCreateInfo::get_multiplicities() const { return multiplicities; }
void OcctlCurveBsplineCreateInfo::set_multiplicities(PackedInt32Array val) { multiplicities = val; }

int OcctlCurveBsplineCreateInfo::get_knot_count() const { return knot_count; }
void OcctlCurveBsplineCreateInfo::set_knot_count(int val) { knot_count = val; }

int OcctlCurveBsplineCreateInfo::get_degree() const { return degree; }
void OcctlCurveBsplineCreateInfo::set_degree(int val) { degree = val; }

int OcctlCurveBsplineCreateInfo::get_is_periodic() const { return is_periodic; }
void OcctlCurveBsplineCreateInfo::set_is_periodic(int val) { is_periodic = val; }

void OcctlCurveBsplineCreateInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlCurveBsplineCreateInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlCurveBsplineCreateInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlCurveBsplineCreateInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlCurveBsplineCreateInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_poles"), &OcctlCurveBsplineCreateInfo::get_poles);
    godot::ClassDB::bind_method(godot::D_METHOD("set_poles", "val"), &OcctlCurveBsplineCreateInfo::set_poles);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "poles"), "set_poles", "get_poles");
    godot::ClassDB::bind_method(godot::D_METHOD("get_pole_count"), &OcctlCurveBsplineCreateInfo::get_pole_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_pole_count", "val"), &OcctlCurveBsplineCreateInfo::set_pole_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "pole_count"), "set_pole_count", "get_pole_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_weights"), &OcctlCurveBsplineCreateInfo::get_weights);
    godot::ClassDB::bind_method(godot::D_METHOD("set_weights", "val"), &OcctlCurveBsplineCreateInfo::set_weights);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "weights"), "set_weights", "get_weights");
    godot::ClassDB::bind_method(godot::D_METHOD("get_knots"), &OcctlCurveBsplineCreateInfo::get_knots);
    godot::ClassDB::bind_method(godot::D_METHOD("set_knots", "val"), &OcctlCurveBsplineCreateInfo::set_knots);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "knots"), "set_knots", "get_knots");
    godot::ClassDB::bind_method(godot::D_METHOD("get_multiplicities"), &OcctlCurveBsplineCreateInfo::get_multiplicities);
    godot::ClassDB::bind_method(godot::D_METHOD("set_multiplicities", "val"), &OcctlCurveBsplineCreateInfo::set_multiplicities);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "multiplicities"), "set_multiplicities", "get_multiplicities");
    godot::ClassDB::bind_method(godot::D_METHOD("get_knot_count"), &OcctlCurveBsplineCreateInfo::get_knot_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_knot_count", "val"), &OcctlCurveBsplineCreateInfo::set_knot_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "knot_count"), "set_knot_count", "get_knot_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_degree"), &OcctlCurveBsplineCreateInfo::get_degree);
    godot::ClassDB::bind_method(godot::D_METHOD("set_degree", "val"), &OcctlCurveBsplineCreateInfo::set_degree);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "degree"), "set_degree", "get_degree");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_periodic"), &OcctlCurveBsplineCreateInfo::get_is_periodic);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_periodic", "val"), &OcctlCurveBsplineCreateInfo::set_is_periodic);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_periodic"), "set_is_periodic", "get_is_periodic");
}

occtl_curve_bspline_create_info_t OcctlCurveBsplineCreateInfo::to_c() const {
    occtl_curve_bspline_create_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    _cache_poles.resize(poles.size());
    for (int _i = 0; _i < poles.size(); _i++) {
        Ref<OcctlPoint3> _item = poles[_i];
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

Ref<OcctlCurveBsplineCreateInfo> OcctlCurveBsplineCreateInfo::from_c(const occtl_curve_bspline_create_info_t& val) {
    Ref<OcctlCurveBsplineCreateInfo> r;
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

void OcctlCurveBsplineCreateInfo::copy_from_c(const occtl_curve_bspline_create_info_t& val) {
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
