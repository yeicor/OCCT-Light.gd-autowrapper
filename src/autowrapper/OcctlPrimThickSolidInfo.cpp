#include "OcctlPrimThickSolidInfo.h"

#include "OcctlNodeId.h"

int OcctlPrimThickSolidInfo::get_struct_version() const { return struct_version; }
void OcctlPrimThickSolidInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimThickSolidInfo::get_p_next() const { return p_next; }
void OcctlPrimThickSolidInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlPrimThickSolidInfo::get_solid() const { return solid; }
void OcctlPrimThickSolidInfo::set_solid(int64_t val) { solid = val; }

PackedInt64Array OcctlPrimThickSolidInfo::get_closing_faces() const { return closing_faces; }
void OcctlPrimThickSolidInfo::set_closing_faces(PackedInt64Array val) { closing_faces = val; }

int OcctlPrimThickSolidInfo::get_closing_face_count() const { return closing_face_count; }
void OcctlPrimThickSolidInfo::set_closing_face_count(int val) { closing_face_count = val; }

double OcctlPrimThickSolidInfo::get_offset() const { return offset; }
void OcctlPrimThickSolidInfo::set_offset(double val) { offset = val; }

double OcctlPrimThickSolidInfo::get_tolerance() const { return tolerance; }
void OcctlPrimThickSolidInfo::set_tolerance(double val) { tolerance = val; }

int OcctlPrimThickSolidInfo::get_mode() const { return mode; }
void OcctlPrimThickSolidInfo::set_mode(int val) { mode = val; }

int OcctlPrimThickSolidInfo::get_join() const { return join; }
void OcctlPrimThickSolidInfo::set_join(int val) { join = val; }

int OcctlPrimThickSolidInfo::get_intersection() const { return intersection; }
void OcctlPrimThickSolidInfo::set_intersection(int val) { intersection = val; }

int OcctlPrimThickSolidInfo::get_self_intersection() const { return self_intersection; }
void OcctlPrimThickSolidInfo::set_self_intersection(int val) { self_intersection = val; }

int OcctlPrimThickSolidInfo::get_remove_internal_edges() const { return remove_internal_edges; }
void OcctlPrimThickSolidInfo::set_remove_internal_edges(int val) { remove_internal_edges = val; }

void OcctlPrimThickSolidInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimThickSolidInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimThickSolidInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimThickSolidInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimThickSolidInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_solid"), &OcctlPrimThickSolidInfo::get_solid);
    godot::ClassDB::bind_method(godot::D_METHOD("set_solid", "val"), &OcctlPrimThickSolidInfo::set_solid);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "solid"), "set_solid", "get_solid");
    godot::ClassDB::bind_method(godot::D_METHOD("get_closing_faces"), &OcctlPrimThickSolidInfo::get_closing_faces);
    godot::ClassDB::bind_method(godot::D_METHOD("set_closing_faces", "val"), &OcctlPrimThickSolidInfo::set_closing_faces);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "closing_faces"), "set_closing_faces", "get_closing_faces");
    godot::ClassDB::bind_method(godot::D_METHOD("get_closing_face_count"), &OcctlPrimThickSolidInfo::get_closing_face_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_closing_face_count", "val"), &OcctlPrimThickSolidInfo::set_closing_face_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "closing_face_count"), "set_closing_face_count", "get_closing_face_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_offset"), &OcctlPrimThickSolidInfo::get_offset);
    godot::ClassDB::bind_method(godot::D_METHOD("set_offset", "val"), &OcctlPrimThickSolidInfo::set_offset);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "offset"), "set_offset", "get_offset");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlPrimThickSolidInfo::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlPrimThickSolidInfo::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_mode"), &OcctlPrimThickSolidInfo::get_mode);
    godot::ClassDB::bind_method(godot::D_METHOD("set_mode", "val"), &OcctlPrimThickSolidInfo::set_mode);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "mode"), "set_mode", "get_mode");
    godot::ClassDB::bind_method(godot::D_METHOD("get_join"), &OcctlPrimThickSolidInfo::get_join);
    godot::ClassDB::bind_method(godot::D_METHOD("set_join", "val"), &OcctlPrimThickSolidInfo::set_join);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "join"), "set_join", "get_join");
    godot::ClassDB::bind_method(godot::D_METHOD("get_intersection"), &OcctlPrimThickSolidInfo::get_intersection);
    godot::ClassDB::bind_method(godot::D_METHOD("set_intersection", "val"), &OcctlPrimThickSolidInfo::set_intersection);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "intersection"), "set_intersection", "get_intersection");
    godot::ClassDB::bind_method(godot::D_METHOD("get_self_intersection"), &OcctlPrimThickSolidInfo::get_self_intersection);
    godot::ClassDB::bind_method(godot::D_METHOD("set_self_intersection", "val"), &OcctlPrimThickSolidInfo::set_self_intersection);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "self_intersection"), "set_self_intersection", "get_self_intersection");
    godot::ClassDB::bind_method(godot::D_METHOD("get_remove_internal_edges"), &OcctlPrimThickSolidInfo::get_remove_internal_edges);
    godot::ClassDB::bind_method(godot::D_METHOD("set_remove_internal_edges", "val"), &OcctlPrimThickSolidInfo::set_remove_internal_edges);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "remove_internal_edges"), "set_remove_internal_edges", "get_remove_internal_edges");
}

occtl_prim_thick_solid_info_t OcctlPrimThickSolidInfo::to_c() const {
    occtl_prim_thick_solid_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.solid.bits = static_cast<uint64_t>(solid);
    result.closing_faces = reinterpret_cast<const occtl_node_id_t*>(closing_faces.ptr());
    result.closing_face_count = closing_face_count;
    result.offset = offset;
    result.tolerance = tolerance;
    result.mode = static_cast<occtl_prim_offset_mode_t>(mode);
    result.join = static_cast<occtl_offset_join_type_t>(join);
    result.intersection = intersection;
    result.self_intersection = self_intersection;
    result.remove_internal_edges = remove_internal_edges;
    return result;
}

Ref<OcctlPrimThickSolidInfo> OcctlPrimThickSolidInfo::from_c(const occtl_prim_thick_solid_info_t& val) {
    Ref<OcctlPrimThickSolidInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->solid = static_cast<int64_t>(val.solid.bits);
    // array field closing_faces is not populated from C
    r->closing_face_count = val.closing_face_count;
    r->offset = val.offset;
    r->tolerance = val.tolerance;
    r->mode = static_cast<int>(val.mode);
    r->join = static_cast<int>(val.join);
    r->intersection = val.intersection;
    r->self_intersection = val.self_intersection;
    r->remove_internal_edges = val.remove_internal_edges;
    return r;
}

void OcctlPrimThickSolidInfo::copy_from_c(const occtl_prim_thick_solid_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    solid = static_cast<int64_t>(val.solid.bits);
    // array field closing_faces is not populated from C
    closing_face_count = val.closing_face_count;
    offset = val.offset;
    tolerance = val.tolerance;
    mode = static_cast<int>(val.mode);
    join = static_cast<int>(val.join);
    intersection = val.intersection;
    self_intersection = val.self_intersection;
    remove_internal_edges = val.remove_internal_edges;
}
