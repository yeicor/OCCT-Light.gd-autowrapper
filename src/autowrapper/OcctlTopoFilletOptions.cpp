#include "OcctlTopoFilletOptions.h"


int OcctlTopoFilletOptions::get_struct_version() const { return struct_version; }
void OcctlTopoFilletOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoFilletOptions::get_p_next() const { return p_next; }
void OcctlTopoFilletOptions::set_p_next(int64_t val) { p_next = val; }

double OcctlTopoFilletOptions::get_radius() const { return radius; }
void OcctlTopoFilletOptions::set_radius(double val) { radius = val; }

int OcctlTopoFilletOptions::get_chamfer_mode() const { return chamfer_mode; }
void OcctlTopoFilletOptions::set_chamfer_mode(int val) { chamfer_mode = val; }

double OcctlTopoFilletOptions::get_chamfer_dist1() const { return chamfer_dist1; }
void OcctlTopoFilletOptions::set_chamfer_dist1(double val) { chamfer_dist1 = val; }

double OcctlTopoFilletOptions::get_chamfer_dist2() const { return chamfer_dist2; }
void OcctlTopoFilletOptions::set_chamfer_dist2(double val) { chamfer_dist2 = val; }

void OcctlTopoFilletOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoFilletOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoFilletOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoFilletOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoFilletOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_radius"), &OcctlTopoFilletOptions::get_radius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_radius", "val"), &OcctlTopoFilletOptions::set_radius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "radius"), "set_radius", "get_radius");
    godot::ClassDB::bind_method(godot::D_METHOD("get_chamfer_mode"), &OcctlTopoFilletOptions::get_chamfer_mode);
    godot::ClassDB::bind_method(godot::D_METHOD("set_chamfer_mode", "val"), &OcctlTopoFilletOptions::set_chamfer_mode);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "chamfer_mode"), "set_chamfer_mode", "get_chamfer_mode");
    godot::ClassDB::bind_method(godot::D_METHOD("get_chamfer_dist1"), &OcctlTopoFilletOptions::get_chamfer_dist1);
    godot::ClassDB::bind_method(godot::D_METHOD("set_chamfer_dist1", "val"), &OcctlTopoFilletOptions::set_chamfer_dist1);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "chamfer_dist1"), "set_chamfer_dist1", "get_chamfer_dist1");
    godot::ClassDB::bind_method(godot::D_METHOD("get_chamfer_dist2"), &OcctlTopoFilletOptions::get_chamfer_dist2);
    godot::ClassDB::bind_method(godot::D_METHOD("set_chamfer_dist2", "val"), &OcctlTopoFilletOptions::set_chamfer_dist2);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "chamfer_dist2"), "set_chamfer_dist2", "get_chamfer_dist2");
}

occtl_topo_fillet_options_t OcctlTopoFilletOptions::to_c() const {
    occtl_topo_fillet_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.radius = radius;
    result.chamfer_mode = chamfer_mode;
    result.chamfer_dist1 = chamfer_dist1;
    result.chamfer_dist2 = chamfer_dist2;
    return result;
}

Ref<OcctlTopoFilletOptions> OcctlTopoFilletOptions::from_c(const occtl_topo_fillet_options_t& val) {
    Ref<OcctlTopoFilletOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->radius = val.radius;
    r->chamfer_mode = val.chamfer_mode;
    r->chamfer_dist1 = val.chamfer_dist1;
    r->chamfer_dist2 = val.chamfer_dist2;
    return r;
}

void OcctlTopoFilletOptions::copy_from_c(const occtl_topo_fillet_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    radius = val.radius;
    chamfer_mode = val.chamfer_mode;
    chamfer_dist1 = val.chamfer_dist1;
    chamfer_dist2 = val.chamfer_dist2;
}
