#include "OcctlCurveBezierCreateInfo.h"


int OcctlCurveBezierCreateInfo::get_struct_version() const { return struct_version; }
void OcctlCurveBezierCreateInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlCurveBezierCreateInfo::get_p_next() const { return p_next; }
void OcctlCurveBezierCreateInfo::set_p_next(int64_t val) { p_next = val; }

Array OcctlCurveBezierCreateInfo::get_poles() const { return poles; }
void OcctlCurveBezierCreateInfo::set_poles(Array val) { poles = val; }

int OcctlCurveBezierCreateInfo::get_pole_count() const { return pole_count; }
void OcctlCurveBezierCreateInfo::set_pole_count(int val) { pole_count = val; }

PackedFloat64Array OcctlCurveBezierCreateInfo::get_weights() const { return weights; }
void OcctlCurveBezierCreateInfo::set_weights(PackedFloat64Array val) { weights = val; }

void OcctlCurveBezierCreateInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlCurveBezierCreateInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlCurveBezierCreateInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlCurveBezierCreateInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlCurveBezierCreateInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_poles"), &OcctlCurveBezierCreateInfo::get_poles);
    godot::ClassDB::bind_method(godot::D_METHOD("set_poles", "val"), &OcctlCurveBezierCreateInfo::set_poles);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "poles"), "set_poles", "get_poles");
    godot::ClassDB::bind_method(godot::D_METHOD("get_pole_count"), &OcctlCurveBezierCreateInfo::get_pole_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_pole_count", "val"), &OcctlCurveBezierCreateInfo::set_pole_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "pole_count"), "set_pole_count", "get_pole_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_weights"), &OcctlCurveBezierCreateInfo::get_weights);
    godot::ClassDB::bind_method(godot::D_METHOD("set_weights", "val"), &OcctlCurveBezierCreateInfo::set_weights);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "weights"), "set_weights", "get_weights");
}

occtl_curve_bezier_create_info_t OcctlCurveBezierCreateInfo::to_c() const {
    occtl_curve_bezier_create_info_t result = {};
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
    return result;
}

Ref<OcctlCurveBezierCreateInfo> OcctlCurveBezierCreateInfo::from_c(const occtl_curve_bezier_create_info_t& val) {
    Ref<OcctlCurveBezierCreateInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field poles is not populated from C
    r->pole_count = val.pole_count;
    // array field weights is not populated from C
    return r;
}

void OcctlCurveBezierCreateInfo::copy_from_c(const occtl_curve_bezier_create_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field poles is not populated from C
    pole_count = val.pole_count;
    // array field weights is not populated from C
}
