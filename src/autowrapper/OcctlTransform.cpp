#include "OcctlTransform.h"


PackedFloat64Array OcctlTransform::get_m() const { return m; }
void OcctlTransform::set_m(PackedFloat64Array val) { m = val; }

void OcctlTransform::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_m"), &OcctlTransform::get_m);
    godot::ClassDB::bind_method(godot::D_METHOD("set_m", "val"), &OcctlTransform::set_m);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "m"), "set_m", "get_m");
    godot::ClassDB::bind_static_method("OcctlTransform", godot::D_METHOD("from_transform3d", "t"), &OcctlTransform::from_transform3d);
}

occtl_transform_t OcctlTransform::to_c() const {
    occtl_transform_t result = {};
    for (int _i = 0; _i < 12; _i++) result.m[_i] = m[_i];
    return result;
}

Ref<OcctlTransform> OcctlTransform::from_c(const occtl_transform_t& val) {
    Ref<OcctlTransform> r;
    r.instantiate();
    r->m.resize(12);
    for (int _i = 0; _i < 12; _i++) r->m[_i] = val.m[_i];
    return r;
}

void OcctlTransform::copy_from_c(const occtl_transform_t& val) {
    m.resize(12);
    for (int _i = 0; _i < 12; _i++) m[_i] = val.m[_i];
}

Ref<OcctlTransform> OcctlTransform::from_transform3d(Transform3D t) {
    Ref<OcctlTransform> instance;
    instance.instantiate();
    instance->m.resize(12);
    instance->m[0] = t.basis[0].x;
    instance->m[1] = t.basis[0].y;
    instance->m[2] = t.basis[0].z;
    instance->m[3] = t.origin.x;
    instance->m[4] = t.basis[1].x;
    instance->m[5] = t.basis[1].y;
    instance->m[6] = t.basis[1].z;
    instance->m[7] = t.origin.y;
    instance->m[8] = t.basis[2].x;
    instance->m[9] = t.basis[2].y;
    instance->m[10] = t.basis[2].z;
    instance->m[11] = t.origin.z;
    return instance;
}
