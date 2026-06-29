#include "OcctlGraphHandle.h"

void OcctlGraphHandle::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &OcctlGraphHandle::set_handle);
    godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &OcctlGraphHandle::get_handle);
    godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &OcctlGraphHandle::is_valid);
    godot::ClassDB::bind_method(godot::D_METHOD("release"), &OcctlGraphHandle::release);
    godot::ClassDB::bind_method(godot::D_METHOD("free"), static_cast<void(OcctlGraphHandle::*)()>(&OcctlGraphHandle::free));
}

void OcctlGraphHandle::set_handle(int64_t h) {
    _handle = reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(h));
    _owns = true;
}

int64_t OcctlGraphHandle::get_handle() const {
    return static_cast<int64_t>(reinterpret_cast<uintptr_t>(_handle));
}

bool OcctlGraphHandle::is_valid() const {
    return _handle != nullptr;
}

int64_t OcctlGraphHandle::release() {
    _owns = false;
    return get_handle();
}

void OcctlGraphHandle::free() {
    if (_handle) {
        ::occtl_graph_free(_handle);
        _handle = nullptr;
    }
}
