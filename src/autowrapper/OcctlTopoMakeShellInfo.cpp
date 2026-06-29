#include "OcctlTopoMakeShellInfo.h"


int OcctlTopoMakeShellInfo::get_struct_version() const { return struct_version; }
void OcctlTopoMakeShellInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoMakeShellInfo::get_p_next() const { return p_next; }
void OcctlTopoMakeShellInfo::set_p_next(int64_t val) { p_next = val; }

Array OcctlTopoMakeShellInfo::get_faces() const { return faces; }
void OcctlTopoMakeShellInfo::set_faces(Array val) { faces = val; }

int OcctlTopoMakeShellInfo::get_face_count() const { return face_count; }
void OcctlTopoMakeShellInfo::set_face_count(int val) { face_count = val; }

int OcctlTopoMakeShellInfo::get_is_closed() const { return is_closed; }
void OcctlTopoMakeShellInfo::set_is_closed(int val) { is_closed = val; }

void OcctlTopoMakeShellInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoMakeShellInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoMakeShellInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoMakeShellInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoMakeShellInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_faces"), &OcctlTopoMakeShellInfo::get_faces);
    godot::ClassDB::bind_method(godot::D_METHOD("set_faces", "val"), &OcctlTopoMakeShellInfo::set_faces);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "faces"), "set_faces", "get_faces");
    godot::ClassDB::bind_method(godot::D_METHOD("get_face_count"), &OcctlTopoMakeShellInfo::get_face_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_face_count", "val"), &OcctlTopoMakeShellInfo::set_face_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "face_count"), "set_face_count", "get_face_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_closed"), &OcctlTopoMakeShellInfo::get_is_closed);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_closed", "val"), &OcctlTopoMakeShellInfo::set_is_closed);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_closed"), "set_is_closed", "get_is_closed");
}

occtl_topo_make_shell_info_t OcctlTopoMakeShellInfo::to_c() const {
    occtl_topo_make_shell_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    _cache_faces.resize(faces.size());
    for (int _i = 0; _i < faces.size(); _i++) {
        Ref<OcctlOrientedNode> _item = faces[_i];
        if (_item.is_valid()) _cache_faces[_i] = _item->to_c();
        else _cache_faces[_i] = {};
    }
    result.faces = _cache_faces.data();
    result.face_count = face_count;
    result.is_closed = is_closed;
    return result;
}

Ref<OcctlTopoMakeShellInfo> OcctlTopoMakeShellInfo::from_c(const occtl_topo_make_shell_info_t& val) {
    Ref<OcctlTopoMakeShellInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field faces is not populated from C
    r->face_count = val.face_count;
    r->is_closed = val.is_closed;
    return r;
}

void OcctlTopoMakeShellInfo::copy_from_c(const occtl_topo_make_shell_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field faces is not populated from C
    face_count = val.face_count;
    is_closed = val.is_closed;
}
