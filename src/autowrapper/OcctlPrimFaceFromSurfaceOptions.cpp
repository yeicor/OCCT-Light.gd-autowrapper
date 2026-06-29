#include "OcctlPrimFaceFromSurfaceOptions.h"

#include "OcctlRepId.h"
#include "OcctlNodeId.h"

int OcctlPrimFaceFromSurfaceOptions::get_struct_version() const { return struct_version; }
void OcctlPrimFaceFromSurfaceOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimFaceFromSurfaceOptions::get_p_next() const { return p_next; }
void OcctlPrimFaceFromSurfaceOptions::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlPrimFaceFromSurfaceOptions::get_surface_id() const { return surface_id; }
void OcctlPrimFaceFromSurfaceOptions::set_surface_id(int64_t val) { surface_id = val; }

int64_t OcctlPrimFaceFromSurfaceOptions::get_outer_wire() const { return outer_wire; }
void OcctlPrimFaceFromSurfaceOptions::set_outer_wire(int64_t val) { outer_wire = val; }

PackedInt64Array OcctlPrimFaceFromSurfaceOptions::get_inner_wires() const { return inner_wires; }
void OcctlPrimFaceFromSurfaceOptions::set_inner_wires(PackedInt64Array val) { inner_wires = val; }

int OcctlPrimFaceFromSurfaceOptions::get_inner_wire_count() const { return inner_wire_count; }
void OcctlPrimFaceFromSurfaceOptions::set_inner_wire_count(int val) { inner_wire_count = val; }

double OcctlPrimFaceFromSurfaceOptions::get_tolerance() const { return tolerance; }
void OcctlPrimFaceFromSurfaceOptions::set_tolerance(double val) { tolerance = val; }

void OcctlPrimFaceFromSurfaceOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimFaceFromSurfaceOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimFaceFromSurfaceOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimFaceFromSurfaceOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimFaceFromSurfaceOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_surface_id"), &OcctlPrimFaceFromSurfaceOptions::get_surface_id);
    godot::ClassDB::bind_method(godot::D_METHOD("set_surface_id", "val"), &OcctlPrimFaceFromSurfaceOptions::set_surface_id);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "surface_id"), "set_surface_id", "get_surface_id");
    godot::ClassDB::bind_method(godot::D_METHOD("get_outer_wire"), &OcctlPrimFaceFromSurfaceOptions::get_outer_wire);
    godot::ClassDB::bind_method(godot::D_METHOD("set_outer_wire", "val"), &OcctlPrimFaceFromSurfaceOptions::set_outer_wire);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "outer_wire"), "set_outer_wire", "get_outer_wire");
    godot::ClassDB::bind_method(godot::D_METHOD("get_inner_wires"), &OcctlPrimFaceFromSurfaceOptions::get_inner_wires);
    godot::ClassDB::bind_method(godot::D_METHOD("set_inner_wires", "val"), &OcctlPrimFaceFromSurfaceOptions::set_inner_wires);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "inner_wires"), "set_inner_wires", "get_inner_wires");
    godot::ClassDB::bind_method(godot::D_METHOD("get_inner_wire_count"), &OcctlPrimFaceFromSurfaceOptions::get_inner_wire_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_inner_wire_count", "val"), &OcctlPrimFaceFromSurfaceOptions::set_inner_wire_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "inner_wire_count"), "set_inner_wire_count", "get_inner_wire_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlPrimFaceFromSurfaceOptions::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlPrimFaceFromSurfaceOptions::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
}

occtl_prim_face_from_surface_options_t OcctlPrimFaceFromSurfaceOptions::to_c() const {
    occtl_prim_face_from_surface_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.surface_id.bits = static_cast<uint64_t>(surface_id);
    result.outer_wire.bits = static_cast<uint64_t>(outer_wire);
    result.inner_wires = reinterpret_cast<const occtl_node_id_t*>(inner_wires.ptr());
    result.inner_wire_count = inner_wire_count;
    result.tolerance = tolerance;
    return result;
}

Ref<OcctlPrimFaceFromSurfaceOptions> OcctlPrimFaceFromSurfaceOptions::from_c(const occtl_prim_face_from_surface_options_t& val) {
    Ref<OcctlPrimFaceFromSurfaceOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->surface_id = static_cast<int64_t>(val.surface_id.bits);
    r->outer_wire = static_cast<int64_t>(val.outer_wire.bits);
    // array field inner_wires is not populated from C
    r->inner_wire_count = val.inner_wire_count;
    r->tolerance = val.tolerance;
    return r;
}

void OcctlPrimFaceFromSurfaceOptions::copy_from_c(const occtl_prim_face_from_surface_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    surface_id = static_cast<int64_t>(val.surface_id.bits);
    outer_wire = static_cast<int64_t>(val.outer_wire.bits);
    // array field inner_wires is not populated from C
    inner_wire_count = val.inner_wire_count;
    tolerance = val.tolerance;
}
