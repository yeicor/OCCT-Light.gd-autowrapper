#include "OcctlPrimHalfspaceInfo.h"

#include "OcctlNodeId.h"
#include "OcctlPoint3.h"

int OcctlPrimHalfspaceInfo::get_struct_version() const { return struct_version; }
void OcctlPrimHalfspaceInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimHalfspaceInfo::get_p_next() const { return p_next; }
void OcctlPrimHalfspaceInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlPrimHalfspaceInfo::get_face() const { return face; }
void OcctlPrimHalfspaceInfo::set_face(int64_t val) { face = val; }

Ref<OcctlPoint3> OcctlPrimHalfspaceInfo::get_reference_point() const { return reference_point; }
void OcctlPrimHalfspaceInfo::set_reference_point(Ref<OcctlPoint3> val) { reference_point = val; }

void OcctlPrimHalfspaceInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimHalfspaceInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimHalfspaceInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimHalfspaceInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimHalfspaceInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_face"), &OcctlPrimHalfspaceInfo::get_face);
    godot::ClassDB::bind_method(godot::D_METHOD("set_face", "val"), &OcctlPrimHalfspaceInfo::set_face);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "face"), "set_face", "get_face");
    godot::ClassDB::bind_method(godot::D_METHOD("get_reference_point"), &OcctlPrimHalfspaceInfo::get_reference_point);
    godot::ClassDB::bind_method(godot::D_METHOD("set_reference_point", "val"), &OcctlPrimHalfspaceInfo::set_reference_point);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "reference_point"), "set_reference_point", "get_reference_point");
}

occtl_prim_halfspace_info_t OcctlPrimHalfspaceInfo::to_c() const {
    occtl_prim_halfspace_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.face.bits = static_cast<uint64_t>(face);
    result.reference_point = reference_point->to_c();
    return result;
}

Ref<OcctlPrimHalfspaceInfo> OcctlPrimHalfspaceInfo::from_c(const occtl_prim_halfspace_info_t& val) {
    Ref<OcctlPrimHalfspaceInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->face = static_cast<int64_t>(val.face.bits);
    r->reference_point = OcctlPoint3::from_c(val.reference_point);
    return r;
}

void OcctlPrimHalfspaceInfo::copy_from_c(const occtl_prim_halfspace_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    face = static_cast<int64_t>(val.face.bits);
    reference_point = OcctlPoint3::from_c(val.reference_point);
}
