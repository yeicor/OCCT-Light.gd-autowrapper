#include "OcctlTopoTouchIterHandle.h"

void OcctlTopoTouchIterHandle::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &OcctlTopoTouchIterHandle::set_handle);
    godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &OcctlTopoTouchIterHandle::get_handle);
    godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &OcctlTopoTouchIterHandle::is_valid);
    godot::ClassDB::bind_method(godot::D_METHOD("release"), &OcctlTopoTouchIterHandle::release);
    godot::ClassDB::bind_method(godot::D_METHOD("free"), static_cast<void(OcctlTopoTouchIterHandle::*)()>(&OcctlTopoTouchIterHandle::free));
}

void OcctlTopoTouchIterHandle::set_handle(int64_t h) {
    _handle = reinterpret_cast<occtl_topo_touch_iter_t*>(static_cast<uintptr_t>(h));
    _owns = true;
}

int64_t OcctlTopoTouchIterHandle::get_handle() const {
    return static_cast<int64_t>(reinterpret_cast<uintptr_t>(_handle));
}

bool OcctlTopoTouchIterHandle::is_valid() const {
    return _handle != nullptr;
}

int64_t OcctlTopoTouchIterHandle::release() {
    _owns = false;
    return get_handle();
}

void OcctlTopoTouchIterHandle::free() {
    if (_handle) {
        ::occtl_topo_touch_iter_free(_handle);
        _handle = nullptr;
    }
}
