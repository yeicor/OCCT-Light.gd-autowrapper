#include "OcctlShellView.h"


int OcctlShellView::get_struct_version() const { return struct_version; }
void OcctlShellView::set_struct_version(int val) { struct_version = val; }

int64_t OcctlShellView::get_p_next() const { return p_next; }
void OcctlShellView::set_p_next(int64_t val) { p_next = val; }

int OcctlShellView::get_is_closed() const { return is_closed; }
void OcctlShellView::set_is_closed(int val) { is_closed = val; }

int OcctlShellView::get_face_count() const { return face_count; }
void OcctlShellView::set_face_count(int val) { face_count = val; }

void OcctlShellView::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlShellView::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlShellView::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlShellView::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlShellView::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_closed"), &OcctlShellView::get_is_closed);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_closed", "val"), &OcctlShellView::set_is_closed);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_closed"), "set_is_closed", "get_is_closed");
    godot::ClassDB::bind_method(godot::D_METHOD("get_face_count"), &OcctlShellView::get_face_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_face_count", "val"), &OcctlShellView::set_face_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "face_count"), "set_face_count", "get_face_count");
}

occtl_shell_view_t OcctlShellView::to_c() const {
    occtl_shell_view_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.is_closed = is_closed;
    result.face_count = face_count;
    return result;
}

Ref<OcctlShellView> OcctlShellView::from_c(const occtl_shell_view_t& val) {
    Ref<OcctlShellView> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->is_closed = val.is_closed;
    r->face_count = val.face_count;
    return r;
}

void OcctlShellView::copy_from_c(const occtl_shell_view_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    is_closed = val.is_closed;
    face_count = val.face_count;
}
