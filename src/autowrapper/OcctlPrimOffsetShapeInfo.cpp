#include "OcctlPrimOffsetShapeInfo.h"

#include "OcctlNodeId.h"

int OcctlPrimOffsetShapeInfo::get_struct_version() const { return struct_version; }
void OcctlPrimOffsetShapeInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimOffsetShapeInfo::get_p_next() const { return p_next; }
void OcctlPrimOffsetShapeInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlPrimOffsetShapeInfo::get_shape() const { return shape; }
void OcctlPrimOffsetShapeInfo::set_shape(int64_t val) { shape = val; }

double OcctlPrimOffsetShapeInfo::get_offset() const { return offset; }
void OcctlPrimOffsetShapeInfo::set_offset(double val) { offset = val; }

double OcctlPrimOffsetShapeInfo::get_tolerance() const { return tolerance; }
void OcctlPrimOffsetShapeInfo::set_tolerance(double val) { tolerance = val; }

int OcctlPrimOffsetShapeInfo::get_mode() const { return mode; }
void OcctlPrimOffsetShapeInfo::set_mode(int val) { mode = val; }

int OcctlPrimOffsetShapeInfo::get_join() const { return join; }
void OcctlPrimOffsetShapeInfo::set_join(int val) { join = val; }

int OcctlPrimOffsetShapeInfo::get_intersection() const { return intersection; }
void OcctlPrimOffsetShapeInfo::set_intersection(int val) { intersection = val; }

int OcctlPrimOffsetShapeInfo::get_self_intersection() const { return self_intersection; }
void OcctlPrimOffsetShapeInfo::set_self_intersection(int val) { self_intersection = val; }

int OcctlPrimOffsetShapeInfo::get_remove_internal_edges() const { return remove_internal_edges; }
void OcctlPrimOffsetShapeInfo::set_remove_internal_edges(int val) { remove_internal_edges = val; }

void OcctlPrimOffsetShapeInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimOffsetShapeInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimOffsetShapeInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimOffsetShapeInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimOffsetShapeInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_shape"), &OcctlPrimOffsetShapeInfo::get_shape);
    godot::ClassDB::bind_method(godot::D_METHOD("set_shape", "val"), &OcctlPrimOffsetShapeInfo::set_shape);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "shape"), "set_shape", "get_shape");
    godot::ClassDB::bind_method(godot::D_METHOD("get_offset"), &OcctlPrimOffsetShapeInfo::get_offset);
    godot::ClassDB::bind_method(godot::D_METHOD("set_offset", "val"), &OcctlPrimOffsetShapeInfo::set_offset);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "offset"), "set_offset", "get_offset");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlPrimOffsetShapeInfo::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlPrimOffsetShapeInfo::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_mode"), &OcctlPrimOffsetShapeInfo::get_mode);
    godot::ClassDB::bind_method(godot::D_METHOD("set_mode", "val"), &OcctlPrimOffsetShapeInfo::set_mode);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "mode"), "set_mode", "get_mode");
    godot::ClassDB::bind_method(godot::D_METHOD("get_join"), &OcctlPrimOffsetShapeInfo::get_join);
    godot::ClassDB::bind_method(godot::D_METHOD("set_join", "val"), &OcctlPrimOffsetShapeInfo::set_join);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "join"), "set_join", "get_join");
    godot::ClassDB::bind_method(godot::D_METHOD("get_intersection"), &OcctlPrimOffsetShapeInfo::get_intersection);
    godot::ClassDB::bind_method(godot::D_METHOD("set_intersection", "val"), &OcctlPrimOffsetShapeInfo::set_intersection);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "intersection"), "set_intersection", "get_intersection");
    godot::ClassDB::bind_method(godot::D_METHOD("get_self_intersection"), &OcctlPrimOffsetShapeInfo::get_self_intersection);
    godot::ClassDB::bind_method(godot::D_METHOD("set_self_intersection", "val"), &OcctlPrimOffsetShapeInfo::set_self_intersection);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "self_intersection"), "set_self_intersection", "get_self_intersection");
    godot::ClassDB::bind_method(godot::D_METHOD("get_remove_internal_edges"), &OcctlPrimOffsetShapeInfo::get_remove_internal_edges);
    godot::ClassDB::bind_method(godot::D_METHOD("set_remove_internal_edges", "val"), &OcctlPrimOffsetShapeInfo::set_remove_internal_edges);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "remove_internal_edges"), "set_remove_internal_edges", "get_remove_internal_edges");
}

occtl_prim_offset_shape_info_t OcctlPrimOffsetShapeInfo::to_c() const {
    occtl_prim_offset_shape_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.shape.bits = static_cast<uint64_t>(shape);
    result.offset = offset;
    result.tolerance = tolerance;
    result.mode = static_cast<occtl_prim_offset_mode_t>(mode);
    result.join = static_cast<occtl_offset_join_type_t>(join);
    result.intersection = intersection;
    result.self_intersection = self_intersection;
    result.remove_internal_edges = remove_internal_edges;
    return result;
}

Ref<OcctlPrimOffsetShapeInfo> OcctlPrimOffsetShapeInfo::from_c(const occtl_prim_offset_shape_info_t& val) {
    Ref<OcctlPrimOffsetShapeInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->shape = static_cast<int64_t>(val.shape.bits);
    r->offset = val.offset;
    r->tolerance = val.tolerance;
    r->mode = static_cast<int>(val.mode);
    r->join = static_cast<int>(val.join);
    r->intersection = val.intersection;
    r->self_intersection = val.self_intersection;
    r->remove_internal_edges = val.remove_internal_edges;
    return r;
}

void OcctlPrimOffsetShapeInfo::copy_from_c(const occtl_prim_offset_shape_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    shape = static_cast<int64_t>(val.shape.bits);
    offset = val.offset;
    tolerance = val.tolerance;
    mode = static_cast<int>(val.mode);
    join = static_cast<int>(val.join);
    intersection = val.intersection;
    self_intersection = val.self_intersection;
    remove_internal_edges = val.remove_internal_edges;
}
