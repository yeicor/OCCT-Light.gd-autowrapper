#include "OcctlCompoundView.h"


int OcctlCompoundView::get_struct_version() const { return struct_version; }
void OcctlCompoundView::set_struct_version(int val) { struct_version = val; }

int64_t OcctlCompoundView::get_p_next() const { return p_next; }
void OcctlCompoundView::set_p_next(int64_t val) { p_next = val; }

int OcctlCompoundView::get_child_count() const { return child_count; }
void OcctlCompoundView::set_child_count(int val) { child_count = val; }

void OcctlCompoundView::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlCompoundView::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlCompoundView::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlCompoundView::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlCompoundView::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_child_count"), &OcctlCompoundView::get_child_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_child_count", "val"), &OcctlCompoundView::set_child_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "child_count"), "set_child_count", "get_child_count");
}

occtl_compound_view_t OcctlCompoundView::to_c() const {
    occtl_compound_view_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.child_count = child_count;
    return result;
}

Ref<OcctlCompoundView> OcctlCompoundView::from_c(const occtl_compound_view_t& val) {
    Ref<OcctlCompoundView> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->child_count = val.child_count;
    return r;
}

void OcctlCompoundView::copy_from_c(const occtl_compound_view_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    child_count = val.child_count;
}
