#include "OcctlSelectBbox.h"

#include "OcctlPoint3.h"

Ref<OcctlPoint3> OcctlSelectBbox::get_min() const { return min; }
void OcctlSelectBbox::set_min(Ref<OcctlPoint3> val) { min = val; }

Ref<OcctlPoint3> OcctlSelectBbox::get_max() const { return max; }
void OcctlSelectBbox::set_max(Ref<OcctlPoint3> val) { max = val; }

void OcctlSelectBbox::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_min"), &OcctlSelectBbox::get_min);
    godot::ClassDB::bind_method(godot::D_METHOD("set_min", "val"), &OcctlSelectBbox::set_min);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "min"), "set_min", "get_min");
    godot::ClassDB::bind_method(godot::D_METHOD("get_max"), &OcctlSelectBbox::get_max);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max", "val"), &OcctlSelectBbox::set_max);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "max"), "set_max", "get_max");
}

occtl_select_bbox_t OcctlSelectBbox::to_c() const {
    occtl_select_bbox_t result = {};
    result.min = min->to_c();
    result.max = max->to_c();
    return result;
}

Ref<OcctlSelectBbox> OcctlSelectBbox::from_c(const occtl_select_bbox_t& val) {
    Ref<OcctlSelectBbox> r;
    r.instantiate();
    r->min = OcctlPoint3::from_c(val.min);
    r->max = OcctlPoint3::from_c(val.max);
    return r;
}

void OcctlSelectBbox::copy_from_c(const occtl_select_bbox_t& val) {
    min = OcctlPoint3::from_c(val.min);
    max = OcctlPoint3::from_c(val.max);
}
