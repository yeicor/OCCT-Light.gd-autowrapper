#include "OcctlPrimEllipseInfo.h"

#include "OcctlAxis2Placement.h"

int OcctlPrimEllipseInfo::get_struct_version() const { return struct_version; }
void OcctlPrimEllipseInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimEllipseInfo::get_p_next() const { return p_next; }
void OcctlPrimEllipseInfo::set_p_next(int64_t val) { p_next = val; }

Ref<OcctlAxis2Placement> OcctlPrimEllipseInfo::get_placement() const { return placement; }
void OcctlPrimEllipseInfo::set_placement(Ref<OcctlAxis2Placement> val) { placement = val; }

double OcctlPrimEllipseInfo::get_major() const { return major; }
void OcctlPrimEllipseInfo::set_major(double val) { major = val; }

double OcctlPrimEllipseInfo::get_minor() const { return minor; }
void OcctlPrimEllipseInfo::set_minor(double val) { minor = val; }

void OcctlPrimEllipseInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimEllipseInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimEllipseInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimEllipseInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimEllipseInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_placement"), &OcctlPrimEllipseInfo::get_placement);
    godot::ClassDB::bind_method(godot::D_METHOD("set_placement", "val"), &OcctlPrimEllipseInfo::set_placement);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "placement"), "set_placement", "get_placement");
    godot::ClassDB::bind_method(godot::D_METHOD("get_major"), &OcctlPrimEllipseInfo::get_major);
    godot::ClassDB::bind_method(godot::D_METHOD("set_major", "val"), &OcctlPrimEllipseInfo::set_major);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "major"), "set_major", "get_major");
    godot::ClassDB::bind_method(godot::D_METHOD("get_minor"), &OcctlPrimEllipseInfo::get_minor);
    godot::ClassDB::bind_method(godot::D_METHOD("set_minor", "val"), &OcctlPrimEllipseInfo::set_minor);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "minor"), "set_minor", "get_minor");
}

occtl_prim_ellipse_info_t OcctlPrimEllipseInfo::to_c() const {
    occtl_prim_ellipse_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.placement = placement->to_c();
    result.major = major;
    result.minor = minor;
    return result;
}

Ref<OcctlPrimEllipseInfo> OcctlPrimEllipseInfo::from_c(const occtl_prim_ellipse_info_t& val) {
    Ref<OcctlPrimEllipseInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->placement = OcctlAxis2Placement::from_c(val.placement);
    r->major = val.major;
    r->minor = val.minor;
    return r;
}

void OcctlPrimEllipseInfo::copy_from_c(const occtl_prim_ellipse_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    placement = OcctlAxis2Placement::from_c(val.placement);
    major = val.major;
    minor = val.minor;
}
