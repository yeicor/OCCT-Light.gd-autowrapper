#include "OcctlSelectIterHandle.h"

void OcctlSelectIterHandle::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &OcctlSelectIterHandle::set_handle);
    godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &OcctlSelectIterHandle::get_handle);
    godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &OcctlSelectIterHandle::is_valid);
    godot::ClassDB::bind_method(godot::D_METHOD("release"), &OcctlSelectIterHandle::release);
    godot::ClassDB::bind_method(godot::D_METHOD("free"), static_cast<void(OcctlSelectIterHandle::*)()>(&OcctlSelectIterHandle::free));
}

void OcctlSelectIterHandle::set_handle(int64_t h) {
    _handle = reinterpret_cast<occtl_select_iter_t*>(static_cast<uintptr_t>(h));
    _owns = true;
}

int64_t OcctlSelectIterHandle::get_handle() const {
    return static_cast<int64_t>(reinterpret_cast<uintptr_t>(_handle));
}

bool OcctlSelectIterHandle::is_valid() const {
    return _handle != nullptr;
}

int64_t OcctlSelectIterHandle::release() {
    _owns = false;
    return get_handle();
}

void OcctlSelectIterHandle::free() {
    if (_handle) {
        ::occtl_select_iter_free(_handle);
        _handle = nullptr;
    }
}
