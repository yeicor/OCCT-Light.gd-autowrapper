#include "OcctlTopoMakeFaceFromWiresAutoOptions.h"

#include "OcctlRepId.h"

int OcctlTopoMakeFaceFromWiresAutoOptions::get_struct_version() const { return struct_version; }
void OcctlTopoMakeFaceFromWiresAutoOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoMakeFaceFromWiresAutoOptions::get_p_next() const { return p_next; }
void OcctlTopoMakeFaceFromWiresAutoOptions::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlTopoMakeFaceFromWiresAutoOptions::get_surface() const { return surface; }
void OcctlTopoMakeFaceFromWiresAutoOptions::set_surface(int64_t val) { surface = val; }

PackedInt64Array OcctlTopoMakeFaceFromWiresAutoOptions::get_wires() const { return wires; }
void OcctlTopoMakeFaceFromWiresAutoOptions::set_wires(PackedInt64Array val) { wires = val; }

int OcctlTopoMakeFaceFromWiresAutoOptions::get_wire_count() const { return wire_count; }
void OcctlTopoMakeFaceFromWiresAutoOptions::set_wire_count(int val) { wire_count = val; }

double OcctlTopoMakeFaceFromWiresAutoOptions::get_tolerance() const { return tolerance; }
void OcctlTopoMakeFaceFromWiresAutoOptions::set_tolerance(double val) { tolerance = val; }

double OcctlTopoMakeFaceFromWiresAutoOptions::get_area_tolerance() const { return area_tolerance; }
void OcctlTopoMakeFaceFromWiresAutoOptions::set_area_tolerance(double val) { area_tolerance = val; }

void OcctlTopoMakeFaceFromWiresAutoOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoMakeFaceFromWiresAutoOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoMakeFaceFromWiresAutoOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoMakeFaceFromWiresAutoOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoMakeFaceFromWiresAutoOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_surface"), &OcctlTopoMakeFaceFromWiresAutoOptions::get_surface);
    godot::ClassDB::bind_method(godot::D_METHOD("set_surface", "val"), &OcctlTopoMakeFaceFromWiresAutoOptions::set_surface);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "surface"), "set_surface", "get_surface");
    godot::ClassDB::bind_method(godot::D_METHOD("get_wires"), &OcctlTopoMakeFaceFromWiresAutoOptions::get_wires);
    godot::ClassDB::bind_method(godot::D_METHOD("set_wires", "val"), &OcctlTopoMakeFaceFromWiresAutoOptions::set_wires);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "wires"), "set_wires", "get_wires");
    godot::ClassDB::bind_method(godot::D_METHOD("get_wire_count"), &OcctlTopoMakeFaceFromWiresAutoOptions::get_wire_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_wire_count", "val"), &OcctlTopoMakeFaceFromWiresAutoOptions::set_wire_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "wire_count"), "set_wire_count", "get_wire_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlTopoMakeFaceFromWiresAutoOptions::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlTopoMakeFaceFromWiresAutoOptions::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_area_tolerance"), &OcctlTopoMakeFaceFromWiresAutoOptions::get_area_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_area_tolerance", "val"), &OcctlTopoMakeFaceFromWiresAutoOptions::set_area_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "area_tolerance"), "set_area_tolerance", "get_area_tolerance");
}

occtl_topo_make_face_from_wires_auto_options_t OcctlTopoMakeFaceFromWiresAutoOptions::to_c() const {
    occtl_topo_make_face_from_wires_auto_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.surface.bits = static_cast<uint64_t>(surface);
    result.wires = reinterpret_cast<const occtl_node_id_t*>(wires.ptr());
    result.wire_count = wire_count;
    result.tolerance = tolerance;
    result.area_tolerance = area_tolerance;
    return result;
}

Ref<OcctlTopoMakeFaceFromWiresAutoOptions> OcctlTopoMakeFaceFromWiresAutoOptions::from_c(const occtl_topo_make_face_from_wires_auto_options_t& val) {
    Ref<OcctlTopoMakeFaceFromWiresAutoOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->surface = static_cast<int64_t>(val.surface.bits);
    // array field wires is not populated from C
    r->wire_count = val.wire_count;
    r->tolerance = val.tolerance;
    r->area_tolerance = val.area_tolerance;
    return r;
}

void OcctlTopoMakeFaceFromWiresAutoOptions::copy_from_c(const occtl_topo_make_face_from_wires_auto_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    surface = static_cast<int64_t>(val.surface.bits);
    // array field wires is not populated from C
    wire_count = val.wire_count;
    tolerance = val.tolerance;
    area_tolerance = val.area_tolerance;
}
