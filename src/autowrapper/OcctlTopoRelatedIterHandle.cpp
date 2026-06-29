#include "OcctlTopoRelatedIterHandle.h"

void OcctlTopoRelatedIterHandle::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &OcctlTopoRelatedIterHandle::set_handle);
    godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &OcctlTopoRelatedIterHandle::get_handle);
    godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &OcctlTopoRelatedIterHandle::is_valid);
    godot::ClassDB::bind_method(godot::D_METHOD("release"), &OcctlTopoRelatedIterHandle::release);
    godot::ClassDB::bind_method(godot::D_METHOD("free"), static_cast<void(OcctlTopoRelatedIterHandle::*)()>(&OcctlTopoRelatedIterHandle::free));
}

void OcctlTopoRelatedIterHandle::set_handle(int64_t h) {
    _handle = reinterpret_cast<occtl_topo_related_iter_t*>(static_cast<uintptr_t>(h));
    _owns = true;
}

int64_t OcctlTopoRelatedIterHandle::get_handle() const {
    return static_cast<int64_t>(reinterpret_cast<uintptr_t>(_handle));
}

bool OcctlTopoRelatedIterHandle::is_valid() const {
    return _handle != nullptr;
}

int64_t OcctlTopoRelatedIterHandle::release() {
    _owns = false;
    return get_handle();
}

void OcctlTopoRelatedIterHandle::free() {
    if (_handle) {
        ::occtl_topo_related_iter_free(_handle);
        _handle = nullptr;
    }
}
