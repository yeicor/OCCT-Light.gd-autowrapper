#include "OcctlHealUnifySameDomainOptions.h"


int OcctlHealUnifySameDomainOptions::get_struct_version() const { return struct_version; }
void OcctlHealUnifySameDomainOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlHealUnifySameDomainOptions::get_p_next() const { return p_next; }
void OcctlHealUnifySameDomainOptions::set_p_next(int64_t val) { p_next = val; }

int OcctlHealUnifySameDomainOptions::get_unify_edges() const { return unify_edges; }
void OcctlHealUnifySameDomainOptions::set_unify_edges(int val) { unify_edges = val; }

int OcctlHealUnifySameDomainOptions::get_unify_faces() const { return unify_faces; }
void OcctlHealUnifySameDomainOptions::set_unify_faces(int val) { unify_faces = val; }

int OcctlHealUnifySameDomainOptions::get_concat_bspline() const { return concat_bspline; }
void OcctlHealUnifySameDomainOptions::set_concat_bspline(int val) { concat_bspline = val; }

int OcctlHealUnifySameDomainOptions::get_allow_internal_edges() const { return allow_internal_edges; }
void OcctlHealUnifySameDomainOptions::set_allow_internal_edges(int val) { allow_internal_edges = val; }

int OcctlHealUnifySameDomainOptions::get_safe_input() const { return safe_input; }
void OcctlHealUnifySameDomainOptions::set_safe_input(int val) { safe_input = val; }

double OcctlHealUnifySameDomainOptions::get_linear_tolerance() const { return linear_tolerance; }
void OcctlHealUnifySameDomainOptions::set_linear_tolerance(double val) { linear_tolerance = val; }

double OcctlHealUnifySameDomainOptions::get_angular_tolerance() const { return angular_tolerance; }
void OcctlHealUnifySameDomainOptions::set_angular_tolerance(double val) { angular_tolerance = val; }

void OcctlHealUnifySameDomainOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlHealUnifySameDomainOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlHealUnifySameDomainOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlHealUnifySameDomainOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlHealUnifySameDomainOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_unify_edges"), &OcctlHealUnifySameDomainOptions::get_unify_edges);
    godot::ClassDB::bind_method(godot::D_METHOD("set_unify_edges", "val"), &OcctlHealUnifySameDomainOptions::set_unify_edges);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "unify_edges"), "set_unify_edges", "get_unify_edges");
    godot::ClassDB::bind_method(godot::D_METHOD("get_unify_faces"), &OcctlHealUnifySameDomainOptions::get_unify_faces);
    godot::ClassDB::bind_method(godot::D_METHOD("set_unify_faces", "val"), &OcctlHealUnifySameDomainOptions::set_unify_faces);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "unify_faces"), "set_unify_faces", "get_unify_faces");
    godot::ClassDB::bind_method(godot::D_METHOD("get_concat_bspline"), &OcctlHealUnifySameDomainOptions::get_concat_bspline);
    godot::ClassDB::bind_method(godot::D_METHOD("set_concat_bspline", "val"), &OcctlHealUnifySameDomainOptions::set_concat_bspline);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "concat_bspline"), "set_concat_bspline", "get_concat_bspline");
    godot::ClassDB::bind_method(godot::D_METHOD("get_allow_internal_edges"), &OcctlHealUnifySameDomainOptions::get_allow_internal_edges);
    godot::ClassDB::bind_method(godot::D_METHOD("set_allow_internal_edges", "val"), &OcctlHealUnifySameDomainOptions::set_allow_internal_edges);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "allow_internal_edges"), "set_allow_internal_edges", "get_allow_internal_edges");
    godot::ClassDB::bind_method(godot::D_METHOD("get_safe_input"), &OcctlHealUnifySameDomainOptions::get_safe_input);
    godot::ClassDB::bind_method(godot::D_METHOD("set_safe_input", "val"), &OcctlHealUnifySameDomainOptions::set_safe_input);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "safe_input"), "set_safe_input", "get_safe_input");
    godot::ClassDB::bind_method(godot::D_METHOD("get_linear_tolerance"), &OcctlHealUnifySameDomainOptions::get_linear_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_linear_tolerance", "val"), &OcctlHealUnifySameDomainOptions::set_linear_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "linear_tolerance"), "set_linear_tolerance", "get_linear_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_angular_tolerance"), &OcctlHealUnifySameDomainOptions::get_angular_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_angular_tolerance", "val"), &OcctlHealUnifySameDomainOptions::set_angular_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "angular_tolerance"), "set_angular_tolerance", "get_angular_tolerance");
}

occtl_heal_unify_same_domain_options_t OcctlHealUnifySameDomainOptions::to_c() const {
    occtl_heal_unify_same_domain_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.unify_edges = unify_edges;
    result.unify_faces = unify_faces;
    result.concat_bspline = concat_bspline;
    result.allow_internal_edges = allow_internal_edges;
    result.safe_input = safe_input;
    result.linear_tolerance = linear_tolerance;
    result.angular_tolerance = angular_tolerance;
    return result;
}

Ref<OcctlHealUnifySameDomainOptions> OcctlHealUnifySameDomainOptions::from_c(const occtl_heal_unify_same_domain_options_t& val) {
    Ref<OcctlHealUnifySameDomainOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->unify_edges = val.unify_edges;
    r->unify_faces = val.unify_faces;
    r->concat_bspline = val.concat_bspline;
    r->allow_internal_edges = val.allow_internal_edges;
    r->safe_input = val.safe_input;
    r->linear_tolerance = val.linear_tolerance;
    r->angular_tolerance = val.angular_tolerance;
    return r;
}

void OcctlHealUnifySameDomainOptions::copy_from_c(const occtl_heal_unify_same_domain_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    unify_edges = val.unify_edges;
    unify_faces = val.unify_faces;
    concat_bspline = val.concat_bspline;
    allow_internal_edges = val.allow_internal_edges;
    safe_input = val.safe_input;
    linear_tolerance = val.linear_tolerance;
    angular_tolerance = val.angular_tolerance;
}
