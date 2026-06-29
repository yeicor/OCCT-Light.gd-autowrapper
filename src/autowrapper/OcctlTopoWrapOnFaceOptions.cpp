#include "OcctlTopoWrapOnFaceOptions.h"

#include "OcctlNodeId.h"
#include "OcctlAxis3Placement.h"

int OcctlTopoWrapOnFaceOptions::get_struct_version() const { return struct_version; }
void OcctlTopoWrapOnFaceOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoWrapOnFaceOptions::get_p_next() const { return p_next; }
void OcctlTopoWrapOnFaceOptions::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlTopoWrapOnFaceOptions::get_source() const { return source; }
void OcctlTopoWrapOnFaceOptions::set_source(int64_t val) { source = val; }

int64_t OcctlTopoWrapOnFaceOptions::get_target_face() const { return target_face; }
void OcctlTopoWrapOnFaceOptions::set_target_face(int64_t val) { target_face = val; }

Ref<OcctlAxis3Placement> OcctlTopoWrapOnFaceOptions::get_surface_location() const { return surface_location; }
void OcctlTopoWrapOnFaceOptions::set_surface_location(Ref<OcctlAxis3Placement> val) { surface_location = val; }

double OcctlTopoWrapOnFaceOptions::get_tolerance() const { return tolerance; }
void OcctlTopoWrapOnFaceOptions::set_tolerance(double val) { tolerance = val; }

int OcctlTopoWrapOnFaceOptions::get_initial_subdivisions() const { return initial_subdivisions; }
void OcctlTopoWrapOnFaceOptions::set_initial_subdivisions(int val) { initial_subdivisions = val; }

int OcctlTopoWrapOnFaceOptions::get_max_refinements() const { return max_refinements; }
void OcctlTopoWrapOnFaceOptions::set_max_refinements(int val) { max_refinements = val; }

double OcctlTopoWrapOnFaceOptions::get_intersection_extent() const { return intersection_extent; }
void OcctlTopoWrapOnFaceOptions::set_intersection_extent(double val) { intersection_extent = val; }

double OcctlTopoWrapOnFaceOptions::get_wire_fix_tolerance() const { return wire_fix_tolerance; }
void OcctlTopoWrapOnFaceOptions::set_wire_fix_tolerance(double val) { wire_fix_tolerance = val; }

void OcctlTopoWrapOnFaceOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoWrapOnFaceOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoWrapOnFaceOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoWrapOnFaceOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoWrapOnFaceOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_source"), &OcctlTopoWrapOnFaceOptions::get_source);
    godot::ClassDB::bind_method(godot::D_METHOD("set_source", "val"), &OcctlTopoWrapOnFaceOptions::set_source);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "source"), "set_source", "get_source");
    godot::ClassDB::bind_method(godot::D_METHOD("get_target_face"), &OcctlTopoWrapOnFaceOptions::get_target_face);
    godot::ClassDB::bind_method(godot::D_METHOD("set_target_face", "val"), &OcctlTopoWrapOnFaceOptions::set_target_face);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "target_face"), "set_target_face", "get_target_face");
    godot::ClassDB::bind_method(godot::D_METHOD("get_surface_location"), &OcctlTopoWrapOnFaceOptions::get_surface_location);
    godot::ClassDB::bind_method(godot::D_METHOD("set_surface_location", "val"), &OcctlTopoWrapOnFaceOptions::set_surface_location);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "surface_location"), "set_surface_location", "get_surface_location");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlTopoWrapOnFaceOptions::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlTopoWrapOnFaceOptions::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_initial_subdivisions"), &OcctlTopoWrapOnFaceOptions::get_initial_subdivisions);
    godot::ClassDB::bind_method(godot::D_METHOD("set_initial_subdivisions", "val"), &OcctlTopoWrapOnFaceOptions::set_initial_subdivisions);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "initial_subdivisions"), "set_initial_subdivisions", "get_initial_subdivisions");
    godot::ClassDB::bind_method(godot::D_METHOD("get_max_refinements"), &OcctlTopoWrapOnFaceOptions::get_max_refinements);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max_refinements", "val"), &OcctlTopoWrapOnFaceOptions::set_max_refinements);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "max_refinements"), "set_max_refinements", "get_max_refinements");
    godot::ClassDB::bind_method(godot::D_METHOD("get_intersection_extent"), &OcctlTopoWrapOnFaceOptions::get_intersection_extent);
    godot::ClassDB::bind_method(godot::D_METHOD("set_intersection_extent", "val"), &OcctlTopoWrapOnFaceOptions::set_intersection_extent);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "intersection_extent"), "set_intersection_extent", "get_intersection_extent");
    godot::ClassDB::bind_method(godot::D_METHOD("get_wire_fix_tolerance"), &OcctlTopoWrapOnFaceOptions::get_wire_fix_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_wire_fix_tolerance", "val"), &OcctlTopoWrapOnFaceOptions::set_wire_fix_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "wire_fix_tolerance"), "set_wire_fix_tolerance", "get_wire_fix_tolerance");
}

occtl_topo_wrap_on_face_options_t OcctlTopoWrapOnFaceOptions::to_c() const {
    occtl_topo_wrap_on_face_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.source.bits = static_cast<uint64_t>(source);
    result.target_face.bits = static_cast<uint64_t>(target_face);
    result.surface_location = surface_location->to_c();
    result.tolerance = tolerance;
    result.initial_subdivisions = initial_subdivisions;
    result.max_refinements = max_refinements;
    result.intersection_extent = intersection_extent;
    result.wire_fix_tolerance = wire_fix_tolerance;
    return result;
}

Ref<OcctlTopoWrapOnFaceOptions> OcctlTopoWrapOnFaceOptions::from_c(const occtl_topo_wrap_on_face_options_t& val) {
    Ref<OcctlTopoWrapOnFaceOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->source = static_cast<int64_t>(val.source.bits);
    r->target_face = static_cast<int64_t>(val.target_face.bits);
    r->surface_location = OcctlAxis3Placement::from_c(val.surface_location);
    r->tolerance = val.tolerance;
    r->initial_subdivisions = val.initial_subdivisions;
    r->max_refinements = val.max_refinements;
    r->intersection_extent = val.intersection_extent;
    r->wire_fix_tolerance = val.wire_fix_tolerance;
    return r;
}

void OcctlTopoWrapOnFaceOptions::copy_from_c(const occtl_topo_wrap_on_face_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    source = static_cast<int64_t>(val.source.bits);
    target_face = static_cast<int64_t>(val.target_face.bits);
    surface_location = OcctlAxis3Placement::from_c(val.surface_location);
    tolerance = val.tolerance;
    initial_subdivisions = val.initial_subdivisions;
    max_refinements = val.max_refinements;
    intersection_extent = val.intersection_extent;
    wire_fix_tolerance = val.wire_fix_tolerance;
}
