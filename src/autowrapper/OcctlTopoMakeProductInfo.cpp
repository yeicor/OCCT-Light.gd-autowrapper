#include "OcctlTopoMakeProductInfo.h"

#include "OcctlNodeId.h"
#include "OcctlTransform.h"

int OcctlTopoMakeProductInfo::get_struct_version() const { return struct_version; }
void OcctlTopoMakeProductInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoMakeProductInfo::get_p_next() const { return p_next; }
void OcctlTopoMakeProductInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlTopoMakeProductInfo::get_root() const { return root; }
void OcctlTopoMakeProductInfo::set_root(int64_t val) { root = val; }

Ref<OcctlTransform> OcctlTopoMakeProductInfo::get_placement() const { return placement; }
void OcctlTopoMakeProductInfo::set_placement(Ref<OcctlTransform> val) { placement = val; }

void OcctlTopoMakeProductInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoMakeProductInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoMakeProductInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoMakeProductInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoMakeProductInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_root"), &OcctlTopoMakeProductInfo::get_root);
    godot::ClassDB::bind_method(godot::D_METHOD("set_root", "val"), &OcctlTopoMakeProductInfo::set_root);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "root"), "set_root", "get_root");
    godot::ClassDB::bind_method(godot::D_METHOD("get_placement"), &OcctlTopoMakeProductInfo::get_placement);
    godot::ClassDB::bind_method(godot::D_METHOD("set_placement", "val"), &OcctlTopoMakeProductInfo::set_placement);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "placement"), "set_placement", "get_placement");
}

occtl_topo_make_product_info_t OcctlTopoMakeProductInfo::to_c() const {
    occtl_topo_make_product_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.root.bits = static_cast<uint64_t>(root);
    result.placement = placement->to_c();
    return result;
}

Ref<OcctlTopoMakeProductInfo> OcctlTopoMakeProductInfo::from_c(const occtl_topo_make_product_info_t& val) {
    Ref<OcctlTopoMakeProductInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->root = static_cast<int64_t>(val.root.bits);
    r->placement = OcctlTransform::from_c(val.placement);
    return r;
}

void OcctlTopoMakeProductInfo::copy_from_c(const occtl_topo_make_product_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    root = static_cast<int64_t>(val.root.bits);
    placement = OcctlTransform::from_c(val.placement);
}
