#include "OcctlRuntimeInitInfo.h"


int OcctlRuntimeInitInfo::get_struct_version() const { return struct_version; }
void OcctlRuntimeInitInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlRuntimeInitInfo::get_p_next() const { return p_next; }
void OcctlRuntimeInitInfo::set_p_next(int64_t val) { p_next = val; }

void OcctlRuntimeInitInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlRuntimeInitInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlRuntimeInitInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlRuntimeInitInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlRuntimeInitInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
}

occtl_runtime_init_info_t OcctlRuntimeInitInfo::to_c() const {
    occtl_runtime_init_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    return result;
}

Ref<OcctlRuntimeInitInfo> OcctlRuntimeInitInfo::from_c(const occtl_runtime_init_info_t& val) {
    Ref<OcctlRuntimeInitInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    return r;
}

void OcctlRuntimeInitInfo::copy_from_c(const occtl_runtime_init_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
}
