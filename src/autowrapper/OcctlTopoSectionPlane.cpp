#include "OcctlTopoSectionPlane.h"

#include "OcctlPoint3.h"
#include "OcctlDirection3.h"

Ref<OcctlPoint3> OcctlTopoSectionPlane::get_point() const { return point; }
void OcctlTopoSectionPlane::set_point(Ref<OcctlPoint3> val) { point = val; }

Ref<OcctlDirection3> OcctlTopoSectionPlane::get_normal() const { return normal; }
void OcctlTopoSectionPlane::set_normal(Ref<OcctlDirection3> val) { normal = val; }

void OcctlTopoSectionPlane::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_point"), &OcctlTopoSectionPlane::get_point);
    godot::ClassDB::bind_method(godot::D_METHOD("set_point", "val"), &OcctlTopoSectionPlane::set_point);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "point"), "set_point", "get_point");
    godot::ClassDB::bind_method(godot::D_METHOD("get_normal"), &OcctlTopoSectionPlane::get_normal);
    godot::ClassDB::bind_method(godot::D_METHOD("set_normal", "val"), &OcctlTopoSectionPlane::set_normal);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "normal"), "set_normal", "get_normal");
}

occtl_topo_section_plane_t OcctlTopoSectionPlane::to_c() const {
    occtl_topo_section_plane_t result = {};
    result.point = point->to_c();
    result.normal = normal->to_c();
    return result;
}

Ref<OcctlTopoSectionPlane> OcctlTopoSectionPlane::from_c(const occtl_topo_section_plane_t& val) {
    Ref<OcctlTopoSectionPlane> r;
    r.instantiate();
    r->point = OcctlPoint3::from_c(val.point);
    r->normal = OcctlDirection3::from_c(val.normal);
    return r;
}

void OcctlTopoSectionPlane::copy_from_c(const occtl_topo_section_plane_t& val) {
    point = OcctlPoint3::from_c(val.point);
    normal = OcctlDirection3::from_c(val.normal);
}
