#include "OcctlTopoMakeSolidInfo.h"


int OcctlTopoMakeSolidInfo::get_struct_version() const { return struct_version; }
void OcctlTopoMakeSolidInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoMakeSolidInfo::get_p_next() const { return p_next; }
void OcctlTopoMakeSolidInfo::set_p_next(int64_t val) { p_next = val; }

Array OcctlTopoMakeSolidInfo::get_shells() const { return shells; }
void OcctlTopoMakeSolidInfo::set_shells(Array val) { shells = val; }

int OcctlTopoMakeSolidInfo::get_shell_count() const { return shell_count; }
void OcctlTopoMakeSolidInfo::set_shell_count(int val) { shell_count = val; }

void OcctlTopoMakeSolidInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoMakeSolidInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoMakeSolidInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoMakeSolidInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoMakeSolidInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_shells"), &OcctlTopoMakeSolidInfo::get_shells);
    godot::ClassDB::bind_method(godot::D_METHOD("set_shells", "val"), &OcctlTopoMakeSolidInfo::set_shells);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "shells"), "set_shells", "get_shells");
    godot::ClassDB::bind_method(godot::D_METHOD("get_shell_count"), &OcctlTopoMakeSolidInfo::get_shell_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_shell_count", "val"), &OcctlTopoMakeSolidInfo::set_shell_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "shell_count"), "set_shell_count", "get_shell_count");
}

occtl_topo_make_solid_info_t OcctlTopoMakeSolidInfo::to_c() const {
    occtl_topo_make_solid_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    _cache_shells.resize(shells.size());
    for (int _i = 0; _i < shells.size(); _i++) {
        Ref<OcctlOrientedNode> _item = shells[_i];
        if (_item.is_valid()) _cache_shells[_i] = _item->to_c();
        else _cache_shells[_i] = {};
    }
    result.shells = _cache_shells.data();
    result.shell_count = shell_count;
    return result;
}

Ref<OcctlTopoMakeSolidInfo> OcctlTopoMakeSolidInfo::from_c(const occtl_topo_make_solid_info_t& val) {
    Ref<OcctlTopoMakeSolidInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field shells is not populated from C
    r->shell_count = val.shell_count;
    return r;
}

void OcctlTopoMakeSolidInfo::copy_from_c(const occtl_topo_make_solid_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field shells is not populated from C
    shell_count = val.shell_count;
}
