#include "OcctlTopoSplitByPlaneOptions.h"

#include "OcctlNodeId.h"
#include "OcctlPoint3.h"
#include "OcctlDirection3.h"

int OcctlTopoSplitByPlaneOptions::get_struct_version() const { return struct_version; }
void OcctlTopoSplitByPlaneOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoSplitByPlaneOptions::get_p_next() const { return p_next; }
void OcctlTopoSplitByPlaneOptions::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlTopoSplitByPlaneOptions::get_root() const { return root; }
void OcctlTopoSplitByPlaneOptions::set_root(int64_t val) { root = val; }

Ref<OcctlPoint3> OcctlTopoSplitByPlaneOptions::get_point() const { return point; }
void OcctlTopoSplitByPlaneOptions::set_point(Ref<OcctlPoint3> val) { point = val; }

Ref<OcctlDirection3> OcctlTopoSplitByPlaneOptions::get_normal() const { return normal; }
void OcctlTopoSplitByPlaneOptions::set_normal(Ref<OcctlDirection3> val) { normal = val; }

int OcctlTopoSplitByPlaneOptions::get_keep() const { return keep; }
void OcctlTopoSplitByPlaneOptions::set_keep(int val) { keep = val; }

void OcctlTopoSplitByPlaneOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoSplitByPlaneOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoSplitByPlaneOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoSplitByPlaneOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoSplitByPlaneOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_root"), &OcctlTopoSplitByPlaneOptions::get_root);
    godot::ClassDB::bind_method(godot::D_METHOD("set_root", "val"), &OcctlTopoSplitByPlaneOptions::set_root);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "root"), "set_root", "get_root");
    godot::ClassDB::bind_method(godot::D_METHOD("get_point"), &OcctlTopoSplitByPlaneOptions::get_point);
    godot::ClassDB::bind_method(godot::D_METHOD("set_point", "val"), &OcctlTopoSplitByPlaneOptions::set_point);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "point"), "set_point", "get_point");
    godot::ClassDB::bind_method(godot::D_METHOD("get_normal"), &OcctlTopoSplitByPlaneOptions::get_normal);
    godot::ClassDB::bind_method(godot::D_METHOD("set_normal", "val"), &OcctlTopoSplitByPlaneOptions::set_normal);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "normal"), "set_normal", "get_normal");
    godot::ClassDB::bind_method(godot::D_METHOD("get_keep"), &OcctlTopoSplitByPlaneOptions::get_keep);
    godot::ClassDB::bind_method(godot::D_METHOD("set_keep", "val"), &OcctlTopoSplitByPlaneOptions::set_keep);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "keep"), "set_keep", "get_keep");
}

occtl_topo_split_by_plane_options_t OcctlTopoSplitByPlaneOptions::to_c() const {
    occtl_topo_split_by_plane_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.root.bits = static_cast<uint64_t>(root);
    result.point = point->to_c();
    result.normal = normal->to_c();
    result.keep = static_cast<occtl_topo_split_keep_t>(keep);
    return result;
}

Ref<OcctlTopoSplitByPlaneOptions> OcctlTopoSplitByPlaneOptions::from_c(const occtl_topo_split_by_plane_options_t& val) {
    Ref<OcctlTopoSplitByPlaneOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->root = static_cast<int64_t>(val.root.bits);
    r->point = OcctlPoint3::from_c(val.point);
    r->normal = OcctlDirection3::from_c(val.normal);
    r->keep = static_cast<int>(val.keep);
    return r;
}

void OcctlTopoSplitByPlaneOptions::copy_from_c(const occtl_topo_split_by_plane_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    root = static_cast<int64_t>(val.root.bits);
    point = OcctlPoint3::from_c(val.point);
    normal = OcctlDirection3::from_c(val.normal);
    keep = static_cast<int>(val.keep);
}
