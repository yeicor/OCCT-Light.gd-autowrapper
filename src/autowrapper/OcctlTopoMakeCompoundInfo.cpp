#include "OcctlTopoMakeCompoundInfo.h"


int OcctlTopoMakeCompoundInfo::get_struct_version() const { return struct_version; }
void OcctlTopoMakeCompoundInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoMakeCompoundInfo::get_p_next() const { return p_next; }
void OcctlTopoMakeCompoundInfo::set_p_next(int64_t val) { p_next = val; }

Array OcctlTopoMakeCompoundInfo::get_children() const { return children; }
void OcctlTopoMakeCompoundInfo::set_children(Array val) { children = val; }

int OcctlTopoMakeCompoundInfo::get_child_count() const { return child_count; }
void OcctlTopoMakeCompoundInfo::set_child_count(int val) { child_count = val; }

void OcctlTopoMakeCompoundInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoMakeCompoundInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoMakeCompoundInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoMakeCompoundInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoMakeCompoundInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_children"), &OcctlTopoMakeCompoundInfo::get_children);
    godot::ClassDB::bind_method(godot::D_METHOD("set_children", "val"), &OcctlTopoMakeCompoundInfo::set_children);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "children"), "set_children", "get_children");
    godot::ClassDB::bind_method(godot::D_METHOD("get_child_count"), &OcctlTopoMakeCompoundInfo::get_child_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_child_count", "val"), &OcctlTopoMakeCompoundInfo::set_child_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "child_count"), "set_child_count", "get_child_count");
}

occtl_topo_make_compound_info_t OcctlTopoMakeCompoundInfo::to_c() const {
    occtl_topo_make_compound_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    _cache_children.resize(children.size());
    for (int _i = 0; _i < children.size(); _i++) {
        Ref<OcctlOrientedNode> _item = children[_i];
        if (_item.is_valid()) _cache_children[_i] = _item->to_c();
        else _cache_children[_i] = {};
    }
    result.children = _cache_children.data();
    result.child_count = child_count;
    return result;
}

Ref<OcctlTopoMakeCompoundInfo> OcctlTopoMakeCompoundInfo::from_c(const occtl_topo_make_compound_info_t& val) {
    Ref<OcctlTopoMakeCompoundInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field children is not populated from C
    r->child_count = val.child_count;
    return r;
}

void OcctlTopoMakeCompoundInfo::copy_from_c(const occtl_topo_make_compound_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field children is not populated from C
    child_count = val.child_count;
}
