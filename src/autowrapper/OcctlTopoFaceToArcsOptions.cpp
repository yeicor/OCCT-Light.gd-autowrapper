#include "OcctlTopoFaceToArcsOptions.h"

#include "OcctlNodeId.h"

int OcctlTopoFaceToArcsOptions::get_struct_version() const { return struct_version; }
void OcctlTopoFaceToArcsOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoFaceToArcsOptions::get_p_next() const { return p_next; }
void OcctlTopoFaceToArcsOptions::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlTopoFaceToArcsOptions::get_source() const { return source; }
void OcctlTopoFaceToArcsOptions::set_source(int64_t val) { source = val; }

double OcctlTopoFaceToArcsOptions::get_angular_tolerance() const { return angular_tolerance; }
void OcctlTopoFaceToArcsOptions::set_angular_tolerance(double val) { angular_tolerance = val; }

void OcctlTopoFaceToArcsOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoFaceToArcsOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoFaceToArcsOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoFaceToArcsOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoFaceToArcsOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_source"), &OcctlTopoFaceToArcsOptions::get_source);
    godot::ClassDB::bind_method(godot::D_METHOD("set_source", "val"), &OcctlTopoFaceToArcsOptions::set_source);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "source"), "set_source", "get_source");
    godot::ClassDB::bind_method(godot::D_METHOD("get_angular_tolerance"), &OcctlTopoFaceToArcsOptions::get_angular_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_angular_tolerance", "val"), &OcctlTopoFaceToArcsOptions::set_angular_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "angular_tolerance"), "set_angular_tolerance", "get_angular_tolerance");
}

occtl_topo_face_to_arcs_options_t OcctlTopoFaceToArcsOptions::to_c() const {
    occtl_topo_face_to_arcs_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.source.bits = static_cast<uint64_t>(source);
    result.angular_tolerance = angular_tolerance;
    return result;
}

Ref<OcctlTopoFaceToArcsOptions> OcctlTopoFaceToArcsOptions::from_c(const occtl_topo_face_to_arcs_options_t& val) {
    Ref<OcctlTopoFaceToArcsOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->source = static_cast<int64_t>(val.source.bits);
    r->angular_tolerance = val.angular_tolerance;
    return r;
}

void OcctlTopoFaceToArcsOptions::copy_from_c(const occtl_topo_face_to_arcs_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    source = static_cast<int64_t>(val.source.bits);
    angular_tolerance = val.angular_tolerance;
}
