#include "OcctlTopoIntersectionIterHandle.h"

void OcctlTopoIntersectionIterHandle::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &OcctlTopoIntersectionIterHandle::set_handle);
    godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &OcctlTopoIntersectionIterHandle::get_handle);
    godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &OcctlTopoIntersectionIterHandle::is_valid);
    godot::ClassDB::bind_method(godot::D_METHOD("release"), &OcctlTopoIntersectionIterHandle::release);
    godot::ClassDB::bind_method(godot::D_METHOD("free"), static_cast<void(OcctlTopoIntersectionIterHandle::*)()>(&OcctlTopoIntersectionIterHandle::free));
}

void OcctlTopoIntersectionIterHandle::set_handle(int64_t h) {
    _handle = reinterpret_cast<occtl_topo_intersection_iter_t*>(static_cast<uintptr_t>(h));
    _owns = true;
}

int64_t OcctlTopoIntersectionIterHandle::get_handle() const {
    return static_cast<int64_t>(reinterpret_cast<uintptr_t>(_handle));
}

bool OcctlTopoIntersectionIterHandle::is_valid() const {
    return _handle != nullptr;
}

int64_t OcctlTopoIntersectionIterHandle::release() {
    _owns = false;
    return get_handle();
}

void OcctlTopoIntersectionIterHandle::free() {
    if (_handle) {
        ::occtl_topo_intersection_iter_free(_handle);
        _handle = nullptr;
    }
}
