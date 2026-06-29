#include "OcctlBoolOptions.h"


int OcctlBoolOptions::get_struct_version() const { return struct_version; }
void OcctlBoolOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlBoolOptions::get_p_next() const { return p_next; }
void OcctlBoolOptions::set_p_next(int64_t val) { p_next = val; }

double OcctlBoolOptions::get_fuzzy_value() const { return fuzzy_value; }
void OcctlBoolOptions::set_fuzzy_value(double val) { fuzzy_value = val; }

int OcctlBoolOptions::get_run_parallel() const { return run_parallel; }
void OcctlBoolOptions::set_run_parallel(int val) { run_parallel = val; }

int OcctlBoolOptions::get_simplify_result() const { return simplify_result; }
void OcctlBoolOptions::set_simplify_result(int val) { simplify_result = val; }

double OcctlBoolOptions::get_simplify_angular_tolerance() const { return simplify_angular_tolerance; }
void OcctlBoolOptions::set_simplify_angular_tolerance(double val) { simplify_angular_tolerance = val; }

int OcctlBoolOptions::get_build_history() const { return build_history; }
void OcctlBoolOptions::set_build_history(int val) { build_history = val; }

void OcctlBoolOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlBoolOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlBoolOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlBoolOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlBoolOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_fuzzy_value"), &OcctlBoolOptions::get_fuzzy_value);
    godot::ClassDB::bind_method(godot::D_METHOD("set_fuzzy_value", "val"), &OcctlBoolOptions::set_fuzzy_value);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "fuzzy_value"), "set_fuzzy_value", "get_fuzzy_value");
    godot::ClassDB::bind_method(godot::D_METHOD("get_run_parallel"), &OcctlBoolOptions::get_run_parallel);
    godot::ClassDB::bind_method(godot::D_METHOD("set_run_parallel", "val"), &OcctlBoolOptions::set_run_parallel);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "run_parallel"), "set_run_parallel", "get_run_parallel");
    godot::ClassDB::bind_method(godot::D_METHOD("get_simplify_result"), &OcctlBoolOptions::get_simplify_result);
    godot::ClassDB::bind_method(godot::D_METHOD("set_simplify_result", "val"), &OcctlBoolOptions::set_simplify_result);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "simplify_result"), "set_simplify_result", "get_simplify_result");
    godot::ClassDB::bind_method(godot::D_METHOD("get_simplify_angular_tolerance"), &OcctlBoolOptions::get_simplify_angular_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_simplify_angular_tolerance", "val"), &OcctlBoolOptions::set_simplify_angular_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "simplify_angular_tolerance"), "set_simplify_angular_tolerance", "get_simplify_angular_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_build_history"), &OcctlBoolOptions::get_build_history);
    godot::ClassDB::bind_method(godot::D_METHOD("set_build_history", "val"), &OcctlBoolOptions::set_build_history);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "build_history"), "set_build_history", "get_build_history");
}

occtl_bool_options_t OcctlBoolOptions::to_c() const {
    occtl_bool_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.fuzzy_value = fuzzy_value;
    result.run_parallel = run_parallel;
    result.simplify_result = simplify_result;
    result.simplify_angular_tolerance = simplify_angular_tolerance;
    result.build_history = build_history;
    return result;
}

Ref<OcctlBoolOptions> OcctlBoolOptions::from_c(const occtl_bool_options_t& val) {
    Ref<OcctlBoolOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->fuzzy_value = val.fuzzy_value;
    r->run_parallel = val.run_parallel;
    r->simplify_result = val.simplify_result;
    r->simplify_angular_tolerance = val.simplify_angular_tolerance;
    r->build_history = val.build_history;
    return r;
}

void OcctlBoolOptions::copy_from_c(const occtl_bool_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    fuzzy_value = val.fuzzy_value;
    run_parallel = val.run_parallel;
    simplify_result = val.simplify_result;
    simplify_angular_tolerance = val.simplify_angular_tolerance;
    build_history = val.build_history;
}
