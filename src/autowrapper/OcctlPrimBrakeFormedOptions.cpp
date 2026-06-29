#include "OcctlPrimBrakeFormedOptions.h"

#include "OcctlNodeId.h"

int OcctlPrimBrakeFormedOptions::get_struct_version() const { return struct_version; }
void OcctlPrimBrakeFormedOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimBrakeFormedOptions::get_p_next() const { return p_next; }
void OcctlPrimBrakeFormedOptions::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlPrimBrakeFormedOptions::get_line() const { return line; }
void OcctlPrimBrakeFormedOptions::set_line(int64_t val) { line = val; }

double OcctlPrimBrakeFormedOptions::get_thickness() const { return thickness; }
void OcctlPrimBrakeFormedOptions::set_thickness(double val) { thickness = val; }

PackedFloat64Array OcctlPrimBrakeFormedOptions::get_station_widths() const { return station_widths; }
void OcctlPrimBrakeFormedOptions::set_station_widths(PackedFloat64Array val) { station_widths = val; }

int OcctlPrimBrakeFormedOptions::get_station_width_count() const { return station_width_count; }
void OcctlPrimBrakeFormedOptions::set_station_width_count(int val) { station_width_count = val; }

int OcctlPrimBrakeFormedOptions::get_side() const { return side; }
void OcctlPrimBrakeFormedOptions::set_side(int val) { side = val; }

int OcctlPrimBrakeFormedOptions::get_join() const { return join; }
void OcctlPrimBrakeFormedOptions::set_join(int val) { join = val; }

int OcctlPrimBrakeFormedOptions::get_approximate() const { return approximate; }
void OcctlPrimBrakeFormedOptions::set_approximate(int val) { approximate = val; }

double OcctlPrimBrakeFormedOptions::get_tolerance() const { return tolerance; }
void OcctlPrimBrakeFormedOptions::set_tolerance(double val) { tolerance = val; }

void OcctlPrimBrakeFormedOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimBrakeFormedOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimBrakeFormedOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimBrakeFormedOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimBrakeFormedOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_line"), &OcctlPrimBrakeFormedOptions::get_line);
    godot::ClassDB::bind_method(godot::D_METHOD("set_line", "val"), &OcctlPrimBrakeFormedOptions::set_line);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "line"), "set_line", "get_line");
    godot::ClassDB::bind_method(godot::D_METHOD("get_thickness"), &OcctlPrimBrakeFormedOptions::get_thickness);
    godot::ClassDB::bind_method(godot::D_METHOD("set_thickness", "val"), &OcctlPrimBrakeFormedOptions::set_thickness);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "thickness"), "set_thickness", "get_thickness");
    godot::ClassDB::bind_method(godot::D_METHOD("get_station_widths"), &OcctlPrimBrakeFormedOptions::get_station_widths);
    godot::ClassDB::bind_method(godot::D_METHOD("set_station_widths", "val"), &OcctlPrimBrakeFormedOptions::set_station_widths);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "station_widths"), "set_station_widths", "get_station_widths");
    godot::ClassDB::bind_method(godot::D_METHOD("get_station_width_count"), &OcctlPrimBrakeFormedOptions::get_station_width_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_station_width_count", "val"), &OcctlPrimBrakeFormedOptions::set_station_width_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "station_width_count"), "set_station_width_count", "get_station_width_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_side"), &OcctlPrimBrakeFormedOptions::get_side);
    godot::ClassDB::bind_method(godot::D_METHOD("set_side", "val"), &OcctlPrimBrakeFormedOptions::set_side);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "side"), "set_side", "get_side");
    godot::ClassDB::bind_method(godot::D_METHOD("get_join"), &OcctlPrimBrakeFormedOptions::get_join);
    godot::ClassDB::bind_method(godot::D_METHOD("set_join", "val"), &OcctlPrimBrakeFormedOptions::set_join);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "join"), "set_join", "get_join");
    godot::ClassDB::bind_method(godot::D_METHOD("get_approximate"), &OcctlPrimBrakeFormedOptions::get_approximate);
    godot::ClassDB::bind_method(godot::D_METHOD("set_approximate", "val"), &OcctlPrimBrakeFormedOptions::set_approximate);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "approximate"), "set_approximate", "get_approximate");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlPrimBrakeFormedOptions::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlPrimBrakeFormedOptions::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
}

occtl_prim_brake_formed_options_t OcctlPrimBrakeFormedOptions::to_c() const {
    occtl_prim_brake_formed_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.line.bits = static_cast<uint64_t>(line);
    result.thickness = thickness;
    result.station_widths = station_widths.ptr();
    result.station_width_count = station_width_count;
    result.side = static_cast<occtl_prim_brake_side_t>(side);
    result.join = static_cast<occtl_topo_wire_offset_2d_join_t>(join);
    result.approximate = approximate;
    result.tolerance = tolerance;
    return result;
}

Ref<OcctlPrimBrakeFormedOptions> OcctlPrimBrakeFormedOptions::from_c(const occtl_prim_brake_formed_options_t& val) {
    Ref<OcctlPrimBrakeFormedOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->line = static_cast<int64_t>(val.line.bits);
    r->thickness = val.thickness;
    // array field station_widths is not populated from C
    r->station_width_count = val.station_width_count;
    r->side = static_cast<int>(val.side);
    r->join = static_cast<int>(val.join);
    r->approximate = val.approximate;
    r->tolerance = val.tolerance;
    return r;
}

void OcctlPrimBrakeFormedOptions::copy_from_c(const occtl_prim_brake_formed_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    line = static_cast<int64_t>(val.line.bits);
    thickness = val.thickness;
    // array field station_widths is not populated from C
    station_width_count = val.station_width_count;
    side = static_cast<int>(val.side);
    join = static_cast<int>(val.join);
    approximate = val.approximate;
    tolerance = val.tolerance;
}
