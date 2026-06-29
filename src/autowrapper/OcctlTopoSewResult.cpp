#include "OcctlTopoSewResult.h"


int OcctlTopoSewResult::get_struct_version() const { return struct_version; }
void OcctlTopoSewResult::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoSewResult::get_p_next() const { return p_next; }
void OcctlTopoSewResult::set_p_next(int64_t val) { p_next = val; }

int OcctlTopoSewResult::get_is_done() const { return is_done; }
void OcctlTopoSewResult::set_is_done(int val) { is_done = val; }

int OcctlTopoSewResult::get_free_edge_count_before() const { return free_edge_count_before; }
void OcctlTopoSewResult::set_free_edge_count_before(int val) { free_edge_count_before = val; }

int OcctlTopoSewResult::get_free_edge_count_after() const { return free_edge_count_after; }
void OcctlTopoSewResult::set_free_edge_count_after(int val) { free_edge_count_after = val; }

int OcctlTopoSewResult::get_sewn_edge_count() const { return sewn_edge_count; }
void OcctlTopoSewResult::set_sewn_edge_count(int val) { sewn_edge_count = val; }

int OcctlTopoSewResult::get_multiple_edge_count() const { return multiple_edge_count; }
void OcctlTopoSewResult::set_multiple_edge_count(int val) { multiple_edge_count = val; }

int OcctlTopoSewResult::get_degenerated_edge_count() const { return degenerated_edge_count; }
void OcctlTopoSewResult::set_degenerated_edge_count(int val) { degenerated_edge_count = val; }

int OcctlTopoSewResult::get_deleted_face_count() const { return deleted_face_count; }
void OcctlTopoSewResult::set_deleted_face_count(int val) { deleted_face_count = val; }

int OcctlTopoSewResult::get_rejected_by_tolerance_count() const { return rejected_by_tolerance_count; }
void OcctlTopoSewResult::set_rejected_by_tolerance_count(int val) { rejected_by_tolerance_count = val; }

void OcctlTopoSewResult::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoSewResult::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoSewResult::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoSewResult::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoSewResult::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_done"), &OcctlTopoSewResult::get_is_done);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_done", "val"), &OcctlTopoSewResult::set_is_done);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_done"), "set_is_done", "get_is_done");
    godot::ClassDB::bind_method(godot::D_METHOD("get_free_edge_count_before"), &OcctlTopoSewResult::get_free_edge_count_before);
    godot::ClassDB::bind_method(godot::D_METHOD("set_free_edge_count_before", "val"), &OcctlTopoSewResult::set_free_edge_count_before);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "free_edge_count_before"), "set_free_edge_count_before", "get_free_edge_count_before");
    godot::ClassDB::bind_method(godot::D_METHOD("get_free_edge_count_after"), &OcctlTopoSewResult::get_free_edge_count_after);
    godot::ClassDB::bind_method(godot::D_METHOD("set_free_edge_count_after", "val"), &OcctlTopoSewResult::set_free_edge_count_after);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "free_edge_count_after"), "set_free_edge_count_after", "get_free_edge_count_after");
    godot::ClassDB::bind_method(godot::D_METHOD("get_sewn_edge_count"), &OcctlTopoSewResult::get_sewn_edge_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_sewn_edge_count", "val"), &OcctlTopoSewResult::set_sewn_edge_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "sewn_edge_count"), "set_sewn_edge_count", "get_sewn_edge_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_multiple_edge_count"), &OcctlTopoSewResult::get_multiple_edge_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_multiple_edge_count", "val"), &OcctlTopoSewResult::set_multiple_edge_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "multiple_edge_count"), "set_multiple_edge_count", "get_multiple_edge_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_degenerated_edge_count"), &OcctlTopoSewResult::get_degenerated_edge_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_degenerated_edge_count", "val"), &OcctlTopoSewResult::set_degenerated_edge_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "degenerated_edge_count"), "set_degenerated_edge_count", "get_degenerated_edge_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_deleted_face_count"), &OcctlTopoSewResult::get_deleted_face_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_deleted_face_count", "val"), &OcctlTopoSewResult::set_deleted_face_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "deleted_face_count"), "set_deleted_face_count", "get_deleted_face_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_rejected_by_tolerance_count"), &OcctlTopoSewResult::get_rejected_by_tolerance_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_rejected_by_tolerance_count", "val"), &OcctlTopoSewResult::set_rejected_by_tolerance_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "rejected_by_tolerance_count"), "set_rejected_by_tolerance_count", "get_rejected_by_tolerance_count");
}

occtl_topo_sew_result_t OcctlTopoSewResult::to_c() const {
    occtl_topo_sew_result_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.is_done = is_done;
    result.free_edge_count_before = free_edge_count_before;
    result.free_edge_count_after = free_edge_count_after;
    result.sewn_edge_count = sewn_edge_count;
    result.multiple_edge_count = multiple_edge_count;
    result.degenerated_edge_count = degenerated_edge_count;
    result.deleted_face_count = deleted_face_count;
    result.rejected_by_tolerance_count = rejected_by_tolerance_count;
    return result;
}

Ref<OcctlTopoSewResult> OcctlTopoSewResult::from_c(const occtl_topo_sew_result_t& val) {
    Ref<OcctlTopoSewResult> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->is_done = val.is_done;
    r->free_edge_count_before = val.free_edge_count_before;
    r->free_edge_count_after = val.free_edge_count_after;
    r->sewn_edge_count = val.sewn_edge_count;
    r->multiple_edge_count = val.multiple_edge_count;
    r->degenerated_edge_count = val.degenerated_edge_count;
    r->deleted_face_count = val.deleted_face_count;
    r->rejected_by_tolerance_count = val.rejected_by_tolerance_count;
    return r;
}

void OcctlTopoSewResult::copy_from_c(const occtl_topo_sew_result_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    is_done = val.is_done;
    free_edge_count_before = val.free_edge_count_before;
    free_edge_count_after = val.free_edge_count_after;
    sewn_edge_count = val.sewn_edge_count;
    multiple_edge_count = val.multiple_edge_count;
    degenerated_edge_count = val.degenerated_edge_count;
    deleted_face_count = val.deleted_face_count;
    rejected_by_tolerance_count = val.rejected_by_tolerance_count;
}
