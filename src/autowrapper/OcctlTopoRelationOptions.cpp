#include "OcctlTopoRelationOptions.h"


int OcctlTopoRelationOptions::get_struct_version() const { return struct_version; }
void OcctlTopoRelationOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoRelationOptions::get_p_next() const { return p_next; }
void OcctlTopoRelationOptions::set_p_next(int64_t val) { p_next = val; }

double OcctlTopoRelationOptions::get_tolerance() const { return tolerance; }
void OcctlTopoRelationOptions::set_tolerance(double val) { tolerance = val; }

int OcctlTopoRelationOptions::get_include_tangent_contacts() const { return include_tangent_contacts; }
void OcctlTopoRelationOptions::set_include_tangent_contacts(int val) { include_tangent_contacts = val; }

int OcctlTopoRelationOptions::get_include_overlaps() const { return include_overlaps; }
void OcctlTopoRelationOptions::set_include_overlaps(int val) { include_overlaps = val; }

int OcctlTopoRelationOptions::get_include_lower_dimension_results() const { return include_lower_dimension_results; }
void OcctlTopoRelationOptions::set_include_lower_dimension_results(int val) { include_lower_dimension_results = val; }

void OcctlTopoRelationOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoRelationOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoRelationOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoRelationOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoRelationOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlTopoRelationOptions::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlTopoRelationOptions::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_include_tangent_contacts"), &OcctlTopoRelationOptions::get_include_tangent_contacts);
    godot::ClassDB::bind_method(godot::D_METHOD("set_include_tangent_contacts", "val"), &OcctlTopoRelationOptions::set_include_tangent_contacts);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "include_tangent_contacts"), "set_include_tangent_contacts", "get_include_tangent_contacts");
    godot::ClassDB::bind_method(godot::D_METHOD("get_include_overlaps"), &OcctlTopoRelationOptions::get_include_overlaps);
    godot::ClassDB::bind_method(godot::D_METHOD("set_include_overlaps", "val"), &OcctlTopoRelationOptions::set_include_overlaps);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "include_overlaps"), "set_include_overlaps", "get_include_overlaps");
    godot::ClassDB::bind_method(godot::D_METHOD("get_include_lower_dimension_results"), &OcctlTopoRelationOptions::get_include_lower_dimension_results);
    godot::ClassDB::bind_method(godot::D_METHOD("set_include_lower_dimension_results", "val"), &OcctlTopoRelationOptions::set_include_lower_dimension_results);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "include_lower_dimension_results"), "set_include_lower_dimension_results", "get_include_lower_dimension_results");
}

occtl_topo_relation_options_t OcctlTopoRelationOptions::to_c() const {
    occtl_topo_relation_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.tolerance = tolerance;
    result.include_tangent_contacts = include_tangent_contacts;
    result.include_overlaps = include_overlaps;
    result.include_lower_dimension_results = include_lower_dimension_results;
    return result;
}

Ref<OcctlTopoRelationOptions> OcctlTopoRelationOptions::from_c(const occtl_topo_relation_options_t& val) {
    Ref<OcctlTopoRelationOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->tolerance = val.tolerance;
    r->include_tangent_contacts = val.include_tangent_contacts;
    r->include_overlaps = val.include_overlaps;
    r->include_lower_dimension_results = val.include_lower_dimension_results;
    return r;
}

void OcctlTopoRelationOptions::copy_from_c(const occtl_topo_relation_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    tolerance = val.tolerance;
    include_tangent_contacts = val.include_tangent_contacts;
    include_overlaps = val.include_overlaps;
    include_lower_dimension_results = val.include_lower_dimension_results;
}
