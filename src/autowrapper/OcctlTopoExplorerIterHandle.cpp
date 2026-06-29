#include "OcctlTopoExplorerIterHandle.h"

void OcctlTopoExplorerIterHandle::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &OcctlTopoExplorerIterHandle::set_handle);
    godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &OcctlTopoExplorerIterHandle::get_handle);
    godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &OcctlTopoExplorerIterHandle::is_valid);
    godot::ClassDB::bind_method(godot::D_METHOD("release"), &OcctlTopoExplorerIterHandle::release);
    godot::ClassDB::bind_method(godot::D_METHOD("free"), static_cast<void(OcctlTopoExplorerIterHandle::*)()>(&OcctlTopoExplorerIterHandle::free));
}

void OcctlTopoExplorerIterHandle::set_handle(int64_t h) {
    _handle = reinterpret_cast<occtl_topo_explorer_iter_t*>(static_cast<uintptr_t>(h));
    _owns = true;
}

int64_t OcctlTopoExplorerIterHandle::get_handle() const {
    return static_cast<int64_t>(reinterpret_cast<uintptr_t>(_handle));
}

bool OcctlTopoExplorerIterHandle::is_valid() const {
    return _handle != nullptr;
}

int64_t OcctlTopoExplorerIterHandle::release() {
    _owns = false;
    return get_handle();
}

void OcctlTopoExplorerIterHandle::free() {
    if (_handle) {
        ::occtl_topo_explorer_iter_free(_handle);
        _handle = nullptr;
    }
}
