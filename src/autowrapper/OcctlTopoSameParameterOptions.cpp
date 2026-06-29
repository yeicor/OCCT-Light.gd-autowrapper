#include "OcctlTopoSameParameterOptions.h"


int OcctlTopoSameParameterOptions::get_struct_version() const { return struct_version; }
void OcctlTopoSameParameterOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoSameParameterOptions::get_p_next() const { return p_next; }
void OcctlTopoSameParameterOptions::set_p_next(int64_t val) { p_next = val; }

double OcctlTopoSameParameterOptions::get_tolerance() const { return tolerance; }
void OcctlTopoSameParameterOptions::set_tolerance(double val) { tolerance = val; }

int OcctlTopoSameParameterOptions::get_history_mode() const { return history_mode; }
void OcctlTopoSameParameterOptions::set_history_mode(int val) { history_mode = val; }

void OcctlTopoSameParameterOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoSameParameterOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoSameParameterOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoSameParameterOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoSameParameterOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlTopoSameParameterOptions::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlTopoSameParameterOptions::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_history_mode"), &OcctlTopoSameParameterOptions::get_history_mode);
    godot::ClassDB::bind_method(godot::D_METHOD("set_history_mode", "val"), &OcctlTopoSameParameterOptions::set_history_mode);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "history_mode"), "set_history_mode", "get_history_mode");
}

occtl_topo_same_parameter_options_t OcctlTopoSameParameterOptions::to_c() const {
    occtl_topo_same_parameter_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.tolerance = tolerance;
    result.history_mode = history_mode;
    return result;
}

Ref<OcctlTopoSameParameterOptions> OcctlTopoSameParameterOptions::from_c(const occtl_topo_same_parameter_options_t& val) {
    Ref<OcctlTopoSameParameterOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->tolerance = val.tolerance;
    r->history_mode = val.history_mode;
    return r;
}

void OcctlTopoSameParameterOptions::copy_from_c(const occtl_topo_same_parameter_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    tolerance = val.tolerance;
    history_mode = val.history_mode;
}
