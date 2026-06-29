#include "OcctlAabb3.h"

#include "OcctlPoint3.h"

Ref<OcctlPoint3> OcctlAabb3::get_min() const { return min; }
void OcctlAabb3::set_min(Ref<OcctlPoint3> val) { min = val; }

Ref<OcctlPoint3> OcctlAabb3::get_max() const { return max; }
void OcctlAabb3::set_max(Ref<OcctlPoint3> val) { max = val; }

void OcctlAabb3::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_min"), &OcctlAabb3::get_min);
    godot::ClassDB::bind_method(godot::D_METHOD("set_min", "val"), &OcctlAabb3::set_min);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "min"), "set_min", "get_min");
    godot::ClassDB::bind_method(godot::D_METHOD("get_max"), &OcctlAabb3::get_max);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max", "val"), &OcctlAabb3::set_max);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "max"), "set_max", "get_max");
    godot::ClassDB::bind_static_method("OcctlAabb3", godot::D_METHOD("from_aabb", "a"), &OcctlAabb3::from_aabb);
}

occtl_aabb3_t OcctlAabb3::to_c() const {
    occtl_aabb3_t result = {};
    result.min = min->to_c();
    result.max = max->to_c();
    return result;
}

Ref<OcctlAabb3> OcctlAabb3::from_c(const occtl_aabb3_t& val) {
    Ref<OcctlAabb3> r;
    r.instantiate();
    r->min = OcctlPoint3::from_c(val.min);
    r->max = OcctlPoint3::from_c(val.max);
    return r;
}

void OcctlAabb3::copy_from_c(const occtl_aabb3_t& val) {
    min = OcctlPoint3::from_c(val.min);
    max = OcctlPoint3::from_c(val.max);
}

Ref<OcctlAabb3> OcctlAabb3::from_aabb(AABB a) {
    Ref<OcctlAabb3> instance;
    instance.instantiate();
    { auto _c = occtl_point3_t{}; _c.x = a.position.x; _c.y = a.position.y; _c.z = a.position.z; instance->min = OcctlPoint3::from_c(_c); }
    { auto _c = occtl_point3_t{}; _c.x = a.position.x + a.size.x; _c.y = a.position.y + a.size.y; _c.z = a.position.z + a.size.z; instance->max = OcctlPoint3::from_c(_c); }
    return instance;
}
