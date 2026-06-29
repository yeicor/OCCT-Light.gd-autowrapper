#include "OcctlSolidView.h"


int OcctlSolidView::get_struct_version() const { return struct_version; }
void OcctlSolidView::set_struct_version(int val) { struct_version = val; }

int64_t OcctlSolidView::get_p_next() const { return p_next; }
void OcctlSolidView::set_p_next(int64_t val) { p_next = val; }

int OcctlSolidView::get_shell_count() const { return shell_count; }
void OcctlSolidView::set_shell_count(int val) { shell_count = val; }

void OcctlSolidView::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlSolidView::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlSolidView::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlSolidView::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlSolidView::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_shell_count"), &OcctlSolidView::get_shell_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_shell_count", "val"), &OcctlSolidView::set_shell_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "shell_count"), "set_shell_count", "get_shell_count");
}

occtl_solid_view_t OcctlSolidView::to_c() const {
    occtl_solid_view_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.shell_count = shell_count;
    return result;
}

Ref<OcctlSolidView> OcctlSolidView::from_c(const occtl_solid_view_t& val) {
    Ref<OcctlSolidView> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->shell_count = val.shell_count;
    return r;
}

void OcctlSolidView::copy_from_c(const occtl_solid_view_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    shell_count = val.shell_count;
}
