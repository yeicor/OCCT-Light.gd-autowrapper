#include "OcctlTopoAxisHitIterHandle.h"

void OcctlTopoAxisHitIterHandle::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &OcctlTopoAxisHitIterHandle::set_handle);
    godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &OcctlTopoAxisHitIterHandle::get_handle);
    godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &OcctlTopoAxisHitIterHandle::is_valid);
    godot::ClassDB::bind_method(godot::D_METHOD("release"), &OcctlTopoAxisHitIterHandle::release);
    godot::ClassDB::bind_method(godot::D_METHOD("free"), static_cast<void(OcctlTopoAxisHitIterHandle::*)()>(&OcctlTopoAxisHitIterHandle::free));
}

void OcctlTopoAxisHitIterHandle::set_handle(int64_t h) {
    _handle = reinterpret_cast<occtl_topo_axis_hit_iter_t*>(static_cast<uintptr_t>(h));
    _owns = true;
}

int64_t OcctlTopoAxisHitIterHandle::get_handle() const {
    return static_cast<int64_t>(reinterpret_cast<uintptr_t>(_handle));
}

bool OcctlTopoAxisHitIterHandle::is_valid() const {
    return _handle != nullptr;
}

int64_t OcctlTopoAxisHitIterHandle::release() {
    _owns = false;
    return get_handle();
}

void OcctlTopoAxisHitIterHandle::free() {
    if (_handle) {
        ::occtl_topo_axis_hit_iter_free(_handle);
        _handle = nullptr;
    }
}
