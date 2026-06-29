#include "OcctlTopoProjectOnFaceOptions.h"

#include "OcctlNodeId.h"

int OcctlTopoProjectOnFaceOptions::get_struct_version() const { return struct_version; }
void OcctlTopoProjectOnFaceOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoProjectOnFaceOptions::get_p_next() const { return p_next; }
void OcctlTopoProjectOnFaceOptions::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlTopoProjectOnFaceOptions::get_source() const { return source; }
void OcctlTopoProjectOnFaceOptions::set_source(int64_t val) { source = val; }

int64_t OcctlTopoProjectOnFaceOptions::get_face() const { return face; }
void OcctlTopoProjectOnFaceOptions::set_face(int64_t val) { face = val; }

double OcctlTopoProjectOnFaceOptions::get_tolerance_3d() const { return tolerance_3d; }
void OcctlTopoProjectOnFaceOptions::set_tolerance_3d(double val) { tolerance_3d = val; }

double OcctlTopoProjectOnFaceOptions::get_tolerance_2d() const { return tolerance_2d; }
void OcctlTopoProjectOnFaceOptions::set_tolerance_2d(double val) { tolerance_2d = val; }

int OcctlTopoProjectOnFaceOptions::get_max_degree() const { return max_degree; }
void OcctlTopoProjectOnFaceOptions::set_max_degree(int val) { max_degree = val; }

int OcctlTopoProjectOnFaceOptions::get_max_segments() const { return max_segments; }
void OcctlTopoProjectOnFaceOptions::set_max_segments(int val) { max_segments = val; }

double OcctlTopoProjectOnFaceOptions::get_max_distance() const { return max_distance; }
void OcctlTopoProjectOnFaceOptions::set_max_distance(double val) { max_distance = val; }

int OcctlTopoProjectOnFaceOptions::get_limit_to_face() const { return limit_to_face; }
void OcctlTopoProjectOnFaceOptions::set_limit_to_face(int val) { limit_to_face = val; }

int OcctlTopoProjectOnFaceOptions::get_compute_3d() const { return compute_3d; }
void OcctlTopoProjectOnFaceOptions::set_compute_3d(int val) { compute_3d = val; }

void OcctlTopoProjectOnFaceOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoProjectOnFaceOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoProjectOnFaceOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoProjectOnFaceOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoProjectOnFaceOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_source"), &OcctlTopoProjectOnFaceOptions::get_source);
    godot::ClassDB::bind_method(godot::D_METHOD("set_source", "val"), &OcctlTopoProjectOnFaceOptions::set_source);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "source"), "set_source", "get_source");
    godot::ClassDB::bind_method(godot::D_METHOD("get_face"), &OcctlTopoProjectOnFaceOptions::get_face);
    godot::ClassDB::bind_method(godot::D_METHOD("set_face", "val"), &OcctlTopoProjectOnFaceOptions::set_face);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "face"), "set_face", "get_face");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance_3d"), &OcctlTopoProjectOnFaceOptions::get_tolerance_3d);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance_3d", "val"), &OcctlTopoProjectOnFaceOptions::set_tolerance_3d);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance_3d"), "set_tolerance_3d", "get_tolerance_3d");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance_2d"), &OcctlTopoProjectOnFaceOptions::get_tolerance_2d);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance_2d", "val"), &OcctlTopoProjectOnFaceOptions::set_tolerance_2d);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance_2d"), "set_tolerance_2d", "get_tolerance_2d");
    godot::ClassDB::bind_method(godot::D_METHOD("get_max_degree"), &OcctlTopoProjectOnFaceOptions::get_max_degree);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max_degree", "val"), &OcctlTopoProjectOnFaceOptions::set_max_degree);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "max_degree"), "set_max_degree", "get_max_degree");
    godot::ClassDB::bind_method(godot::D_METHOD("get_max_segments"), &OcctlTopoProjectOnFaceOptions::get_max_segments);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max_segments", "val"), &OcctlTopoProjectOnFaceOptions::set_max_segments);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "max_segments"), "set_max_segments", "get_max_segments");
    godot::ClassDB::bind_method(godot::D_METHOD("get_max_distance"), &OcctlTopoProjectOnFaceOptions::get_max_distance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max_distance", "val"), &OcctlTopoProjectOnFaceOptions::set_max_distance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max_distance"), "set_max_distance", "get_max_distance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_limit_to_face"), &OcctlTopoProjectOnFaceOptions::get_limit_to_face);
    godot::ClassDB::bind_method(godot::D_METHOD("set_limit_to_face", "val"), &OcctlTopoProjectOnFaceOptions::set_limit_to_face);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "limit_to_face"), "set_limit_to_face", "get_limit_to_face");
    godot::ClassDB::bind_method(godot::D_METHOD("get_compute_3d"), &OcctlTopoProjectOnFaceOptions::get_compute_3d);
    godot::ClassDB::bind_method(godot::D_METHOD("set_compute_3d", "val"), &OcctlTopoProjectOnFaceOptions::set_compute_3d);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "compute_3d"), "set_compute_3d", "get_compute_3d");
}

occtl_topo_project_on_face_options_t OcctlTopoProjectOnFaceOptions::to_c() const {
    occtl_topo_project_on_face_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.source.bits = static_cast<uint64_t>(source);
    result.face.bits = static_cast<uint64_t>(face);
    result.tolerance_3d = tolerance_3d;
    result.tolerance_2d = tolerance_2d;
    result.max_degree = max_degree;
    result.max_segments = max_segments;
    result.max_distance = max_distance;
    result.limit_to_face = limit_to_face;
    result.compute_3d = compute_3d;
    return result;
}

Ref<OcctlTopoProjectOnFaceOptions> OcctlTopoProjectOnFaceOptions::from_c(const occtl_topo_project_on_face_options_t& val) {
    Ref<OcctlTopoProjectOnFaceOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->source = static_cast<int64_t>(val.source.bits);
    r->face = static_cast<int64_t>(val.face.bits);
    r->tolerance_3d = val.tolerance_3d;
    r->tolerance_2d = val.tolerance_2d;
    r->max_degree = val.max_degree;
    r->max_segments = val.max_segments;
    r->max_distance = val.max_distance;
    r->limit_to_face = val.limit_to_face;
    r->compute_3d = val.compute_3d;
    return r;
}

void OcctlTopoProjectOnFaceOptions::copy_from_c(const occtl_topo_project_on_face_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    source = static_cast<int64_t>(val.source.bits);
    face = static_cast<int64_t>(val.face.bits);
    tolerance_3d = val.tolerance_3d;
    tolerance_2d = val.tolerance_2d;
    max_degree = val.max_degree;
    max_segments = val.max_segments;
    max_distance = val.max_distance;
    limit_to_face = val.limit_to_face;
    compute_3d = val.compute_3d;
}
