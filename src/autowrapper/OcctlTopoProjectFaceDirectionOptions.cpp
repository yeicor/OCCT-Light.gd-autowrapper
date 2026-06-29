#include "OcctlTopoProjectFaceDirectionOptions.h"

#include "OcctlNodeId.h"
#include "OcctlDirection3.h"

int OcctlTopoProjectFaceDirectionOptions::get_struct_version() const { return struct_version; }
void OcctlTopoProjectFaceDirectionOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoProjectFaceDirectionOptions::get_p_next() const { return p_next; }
void OcctlTopoProjectFaceDirectionOptions::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlTopoProjectFaceDirectionOptions::get_source_face() const { return source_face; }
void OcctlTopoProjectFaceDirectionOptions::set_source_face(int64_t val) { source_face = val; }

int64_t OcctlTopoProjectFaceDirectionOptions::get_target() const { return target; }
void OcctlTopoProjectFaceDirectionOptions::set_target(int64_t val) { target = val; }

Ref<OcctlDirection3> OcctlTopoProjectFaceDirectionOptions::get_direction() const { return direction; }
void OcctlTopoProjectFaceDirectionOptions::set_direction(Ref<OcctlDirection3> val) { direction = val; }

double OcctlTopoProjectFaceDirectionOptions::get_max_distance() const { return max_distance; }
void OcctlTopoProjectFaceDirectionOptions::set_max_distance(double val) { max_distance = val; }

int OcctlTopoProjectFaceDirectionOptions::get_copy_source() const { return copy_source; }
void OcctlTopoProjectFaceDirectionOptions::set_copy_source(int val) { copy_source = val; }

void OcctlTopoProjectFaceDirectionOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoProjectFaceDirectionOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoProjectFaceDirectionOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoProjectFaceDirectionOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoProjectFaceDirectionOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_source_face"), &OcctlTopoProjectFaceDirectionOptions::get_source_face);
    godot::ClassDB::bind_method(godot::D_METHOD("set_source_face", "val"), &OcctlTopoProjectFaceDirectionOptions::set_source_face);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "source_face"), "set_source_face", "get_source_face");
    godot::ClassDB::bind_method(godot::D_METHOD("get_target"), &OcctlTopoProjectFaceDirectionOptions::get_target);
    godot::ClassDB::bind_method(godot::D_METHOD("set_target", "val"), &OcctlTopoProjectFaceDirectionOptions::set_target);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "target"), "set_target", "get_target");
    godot::ClassDB::bind_method(godot::D_METHOD("get_direction"), &OcctlTopoProjectFaceDirectionOptions::get_direction);
    godot::ClassDB::bind_method(godot::D_METHOD("set_direction", "val"), &OcctlTopoProjectFaceDirectionOptions::set_direction);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "direction"), "set_direction", "get_direction");
    godot::ClassDB::bind_method(godot::D_METHOD("get_max_distance"), &OcctlTopoProjectFaceDirectionOptions::get_max_distance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max_distance", "val"), &OcctlTopoProjectFaceDirectionOptions::set_max_distance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max_distance"), "set_max_distance", "get_max_distance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_copy_source"), &OcctlTopoProjectFaceDirectionOptions::get_copy_source);
    godot::ClassDB::bind_method(godot::D_METHOD("set_copy_source", "val"), &OcctlTopoProjectFaceDirectionOptions::set_copy_source);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "copy_source"), "set_copy_source", "get_copy_source");
}

occtl_topo_project_face_direction_options_t OcctlTopoProjectFaceDirectionOptions::to_c() const {
    occtl_topo_project_face_direction_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.source_face.bits = static_cast<uint64_t>(source_face);
    result.target.bits = static_cast<uint64_t>(target);
    result.direction = direction->to_c();
    result.max_distance = max_distance;
    result.copy_source = copy_source;
    return result;
}

Ref<OcctlTopoProjectFaceDirectionOptions> OcctlTopoProjectFaceDirectionOptions::from_c(const occtl_topo_project_face_direction_options_t& val) {
    Ref<OcctlTopoProjectFaceDirectionOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->source_face = static_cast<int64_t>(val.source_face.bits);
    r->target = static_cast<int64_t>(val.target.bits);
    r->direction = OcctlDirection3::from_c(val.direction);
    r->max_distance = val.max_distance;
    r->copy_source = val.copy_source;
    return r;
}

void OcctlTopoProjectFaceDirectionOptions::copy_from_c(const occtl_topo_project_face_direction_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    source_face = static_cast<int64_t>(val.source_face.bits);
    target = static_cast<int64_t>(val.target.bits);
    direction = OcctlDirection3::from_c(val.direction);
    max_distance = val.max_distance;
    copy_source = val.copy_source;
}
