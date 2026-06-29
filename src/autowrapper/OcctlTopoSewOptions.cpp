#include "OcctlTopoSewOptions.h"


int OcctlTopoSewOptions::get_struct_version() const { return struct_version; }
void OcctlTopoSewOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoSewOptions::get_p_next() const { return p_next; }
void OcctlTopoSewOptions::set_p_next(int64_t val) { p_next = val; }

double OcctlTopoSewOptions::get_tolerance() const { return tolerance; }
void OcctlTopoSewOptions::set_tolerance(double val) { tolerance = val; }

double OcctlTopoSewOptions::get_min_tolerance() const { return min_tolerance; }
void OcctlTopoSewOptions::set_min_tolerance(double val) { min_tolerance = val; }

double OcctlTopoSewOptions::get_max_tolerance() const { return max_tolerance; }
void OcctlTopoSewOptions::set_max_tolerance(double val) { max_tolerance = val; }

int OcctlTopoSewOptions::get_cutting() const { return cutting; }
void OcctlTopoSewOptions::set_cutting(int val) { cutting = val; }

int OcctlTopoSewOptions::get_same_parameter_mode() const { return same_parameter_mode; }
void OcctlTopoSewOptions::set_same_parameter_mode(int val) { same_parameter_mode = val; }

int OcctlTopoSewOptions::get_non_manifold_mode() const { return non_manifold_mode; }
void OcctlTopoSewOptions::set_non_manifold_mode(int val) { non_manifold_mode = val; }

int OcctlTopoSewOptions::get_parallel() const { return parallel; }
void OcctlTopoSewOptions::set_parallel(int val) { parallel = val; }

int OcctlTopoSewOptions::get_history_mode() const { return history_mode; }
void OcctlTopoSewOptions::set_history_mode(int val) { history_mode = val; }

int OcctlTopoSewOptions::get_face_analysis() const { return face_analysis; }
void OcctlTopoSewOptions::set_face_analysis(int val) { face_analysis = val; }

int OcctlTopoSewOptions::get_floating_edges_mode() const { return floating_edges_mode; }
void OcctlTopoSewOptions::set_floating_edges_mode(int val) { floating_edges_mode = val; }

int OcctlTopoSewOptions::get_local_tolerances_mode() const { return local_tolerances_mode; }
void OcctlTopoSewOptions::set_local_tolerances_mode(int val) { local_tolerances_mode = val; }

void OcctlTopoSewOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoSewOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoSewOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoSewOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoSewOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlTopoSewOptions::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlTopoSewOptions::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_min_tolerance"), &OcctlTopoSewOptions::get_min_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_min_tolerance", "val"), &OcctlTopoSewOptions::set_min_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "min_tolerance"), "set_min_tolerance", "get_min_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_max_tolerance"), &OcctlTopoSewOptions::get_max_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max_tolerance", "val"), &OcctlTopoSewOptions::set_max_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max_tolerance"), "set_max_tolerance", "get_max_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_cutting"), &OcctlTopoSewOptions::get_cutting);
    godot::ClassDB::bind_method(godot::D_METHOD("set_cutting", "val"), &OcctlTopoSewOptions::set_cutting);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "cutting"), "set_cutting", "get_cutting");
    godot::ClassDB::bind_method(godot::D_METHOD("get_same_parameter_mode"), &OcctlTopoSewOptions::get_same_parameter_mode);
    godot::ClassDB::bind_method(godot::D_METHOD("set_same_parameter_mode", "val"), &OcctlTopoSewOptions::set_same_parameter_mode);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "same_parameter_mode"), "set_same_parameter_mode", "get_same_parameter_mode");
    godot::ClassDB::bind_method(godot::D_METHOD("get_non_manifold_mode"), &OcctlTopoSewOptions::get_non_manifold_mode);
    godot::ClassDB::bind_method(godot::D_METHOD("set_non_manifold_mode", "val"), &OcctlTopoSewOptions::set_non_manifold_mode);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "non_manifold_mode"), "set_non_manifold_mode", "get_non_manifold_mode");
    godot::ClassDB::bind_method(godot::D_METHOD("get_parallel"), &OcctlTopoSewOptions::get_parallel);
    godot::ClassDB::bind_method(godot::D_METHOD("set_parallel", "val"), &OcctlTopoSewOptions::set_parallel);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "parallel"), "set_parallel", "get_parallel");
    godot::ClassDB::bind_method(godot::D_METHOD("get_history_mode"), &OcctlTopoSewOptions::get_history_mode);
    godot::ClassDB::bind_method(godot::D_METHOD("set_history_mode", "val"), &OcctlTopoSewOptions::set_history_mode);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "history_mode"), "set_history_mode", "get_history_mode");
    godot::ClassDB::bind_method(godot::D_METHOD("get_face_analysis"), &OcctlTopoSewOptions::get_face_analysis);
    godot::ClassDB::bind_method(godot::D_METHOD("set_face_analysis", "val"), &OcctlTopoSewOptions::set_face_analysis);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "face_analysis"), "set_face_analysis", "get_face_analysis");
    godot::ClassDB::bind_method(godot::D_METHOD("get_floating_edges_mode"), &OcctlTopoSewOptions::get_floating_edges_mode);
    godot::ClassDB::bind_method(godot::D_METHOD("set_floating_edges_mode", "val"), &OcctlTopoSewOptions::set_floating_edges_mode);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "floating_edges_mode"), "set_floating_edges_mode", "get_floating_edges_mode");
    godot::ClassDB::bind_method(godot::D_METHOD("get_local_tolerances_mode"), &OcctlTopoSewOptions::get_local_tolerances_mode);
    godot::ClassDB::bind_method(godot::D_METHOD("set_local_tolerances_mode", "val"), &OcctlTopoSewOptions::set_local_tolerances_mode);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "local_tolerances_mode"), "set_local_tolerances_mode", "get_local_tolerances_mode");
}

occtl_topo_sew_options_t OcctlTopoSewOptions::to_c() const {
    occtl_topo_sew_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.tolerance = tolerance;
    result.min_tolerance = min_tolerance;
    result.max_tolerance = max_tolerance;
    result.cutting = cutting;
    result.same_parameter_mode = same_parameter_mode;
    result.non_manifold_mode = non_manifold_mode;
    result.parallel = parallel;
    result.history_mode = history_mode;
    result.face_analysis = face_analysis;
    result.floating_edges_mode = floating_edges_mode;
    result.local_tolerances_mode = local_tolerances_mode;
    return result;
}

Ref<OcctlTopoSewOptions> OcctlTopoSewOptions::from_c(const occtl_topo_sew_options_t& val) {
    Ref<OcctlTopoSewOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->tolerance = val.tolerance;
    r->min_tolerance = val.min_tolerance;
    r->max_tolerance = val.max_tolerance;
    r->cutting = val.cutting;
    r->same_parameter_mode = val.same_parameter_mode;
    r->non_manifold_mode = val.non_manifold_mode;
    r->parallel = val.parallel;
    r->history_mode = val.history_mode;
    r->face_analysis = val.face_analysis;
    r->floating_edges_mode = val.floating_edges_mode;
    r->local_tolerances_mode = val.local_tolerances_mode;
    return r;
}

void OcctlTopoSewOptions::copy_from_c(const occtl_topo_sew_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    tolerance = val.tolerance;
    min_tolerance = val.min_tolerance;
    max_tolerance = val.max_tolerance;
    cutting = val.cutting;
    same_parameter_mode = val.same_parameter_mode;
    non_manifold_mode = val.non_manifold_mode;
    parallel = val.parallel;
    history_mode = val.history_mode;
    face_analysis = val.face_analysis;
    floating_edges_mode = val.floating_edges_mode;
    local_tolerances_mode = val.local_tolerances_mode;
}
