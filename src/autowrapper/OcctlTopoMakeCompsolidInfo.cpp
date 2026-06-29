#include "OcctlTopoMakeCompsolidInfo.h"


int OcctlTopoMakeCompsolidInfo::get_struct_version() const { return struct_version; }
void OcctlTopoMakeCompsolidInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoMakeCompsolidInfo::get_p_next() const { return p_next; }
void OcctlTopoMakeCompsolidInfo::set_p_next(int64_t val) { p_next = val; }

Array OcctlTopoMakeCompsolidInfo::get_solids() const { return solids; }
void OcctlTopoMakeCompsolidInfo::set_solids(Array val) { solids = val; }

int OcctlTopoMakeCompsolidInfo::get_solid_count() const { return solid_count; }
void OcctlTopoMakeCompsolidInfo::set_solid_count(int val) { solid_count = val; }

void OcctlTopoMakeCompsolidInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoMakeCompsolidInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoMakeCompsolidInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoMakeCompsolidInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoMakeCompsolidInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_solids"), &OcctlTopoMakeCompsolidInfo::get_solids);
    godot::ClassDB::bind_method(godot::D_METHOD("set_solids", "val"), &OcctlTopoMakeCompsolidInfo::set_solids);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "solids"), "set_solids", "get_solids");
    godot::ClassDB::bind_method(godot::D_METHOD("get_solid_count"), &OcctlTopoMakeCompsolidInfo::get_solid_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_solid_count", "val"), &OcctlTopoMakeCompsolidInfo::set_solid_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "solid_count"), "set_solid_count", "get_solid_count");
}

occtl_topo_make_compsolid_info_t OcctlTopoMakeCompsolidInfo::to_c() const {
    occtl_topo_make_compsolid_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    _cache_solids.resize(solids.size());
    for (int _i = 0; _i < solids.size(); _i++) {
        Ref<OcctlOrientedNode> _item = solids[_i];
        if (_item.is_valid()) _cache_solids[_i] = _item->to_c();
        else _cache_solids[_i] = {};
    }
    result.solids = _cache_solids.data();
    result.solid_count = solid_count;
    return result;
}

Ref<OcctlTopoMakeCompsolidInfo> OcctlTopoMakeCompsolidInfo::from_c(const occtl_topo_make_compsolid_info_t& val) {
    Ref<OcctlTopoMakeCompsolidInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field solids is not populated from C
    r->solid_count = val.solid_count;
    return r;
}

void OcctlTopoMakeCompsolidInfo::copy_from_c(const occtl_topo_make_compsolid_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field solids is not populated from C
    solid_count = val.solid_count;
}
