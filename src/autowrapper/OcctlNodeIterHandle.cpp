#include "OcctlNodeIterHandle.h"

void OcctlNodeIterHandle::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &OcctlNodeIterHandle::set_handle);
    godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &OcctlNodeIterHandle::get_handle);
    godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &OcctlNodeIterHandle::is_valid);
    godot::ClassDB::bind_method(godot::D_METHOD("release"), &OcctlNodeIterHandle::release);
    godot::ClassDB::bind_method(godot::D_METHOD("free"), static_cast<void(OcctlNodeIterHandle::*)()>(&OcctlNodeIterHandle::free));
}

void OcctlNodeIterHandle::set_handle(int64_t h) {
    _handle = reinterpret_cast<occtl_node_iter_t*>(static_cast<uintptr_t>(h));
    _owns = true;
}

int64_t OcctlNodeIterHandle::get_handle() const {
    return static_cast<int64_t>(reinterpret_cast<uintptr_t>(_handle));
}

bool OcctlNodeIterHandle::is_valid() const {
    return _handle != nullptr;
}

int64_t OcctlNodeIterHandle::release() {
    _owns = false;
    return get_handle();
}

void OcctlNodeIterHandle::free() {
    if (_handle) {
        ::occtl_node_iter_free(_handle);
        _handle = nullptr;
    }
}
