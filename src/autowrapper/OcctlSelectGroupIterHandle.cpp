#include "OcctlSelectGroupIterHandle.h"

void OcctlSelectGroupIterHandle::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &OcctlSelectGroupIterHandle::set_handle);
    godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &OcctlSelectGroupIterHandle::get_handle);
    godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &OcctlSelectGroupIterHandle::is_valid);
    godot::ClassDB::bind_method(godot::D_METHOD("release"), &OcctlSelectGroupIterHandle::release);
    godot::ClassDB::bind_method(godot::D_METHOD("free"), static_cast<void(OcctlSelectGroupIterHandle::*)()>(&OcctlSelectGroupIterHandle::free));
}

void OcctlSelectGroupIterHandle::set_handle(int64_t h) {
    _handle = reinterpret_cast<occtl_select_group_iter_t*>(static_cast<uintptr_t>(h));
    _owns = true;
}

int64_t OcctlSelectGroupIterHandle::get_handle() const {
    return static_cast<int64_t>(reinterpret_cast<uintptr_t>(_handle));
}

bool OcctlSelectGroupIterHandle::is_valid() const {
    return _handle != nullptr;
}

int64_t OcctlSelectGroupIterHandle::release() {
    _owns = false;
    return get_handle();
}

void OcctlSelectGroupIterHandle::free() {
    if (_handle) {
        ::occtl_select_group_iter_free(_handle);
        _handle = nullptr;
    }
}
