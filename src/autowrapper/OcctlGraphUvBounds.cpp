#include "OcctlGraphUvBounds.h"


double OcctlGraphUvBounds::get_u_min() const { return u_min; }
void OcctlGraphUvBounds::set_u_min(double val) { u_min = val; }

double OcctlGraphUvBounds::get_u_max() const { return u_max; }
void OcctlGraphUvBounds::set_u_max(double val) { u_max = val; }

double OcctlGraphUvBounds::get_v_min() const { return v_min; }
void OcctlGraphUvBounds::set_v_min(double val) { v_min = val; }

double OcctlGraphUvBounds::get_v_max() const { return v_max; }
void OcctlGraphUvBounds::set_v_max(double val) { v_max = val; }

int OcctlGraphUvBounds::get_is_natural_restriction() const { return is_natural_restriction; }
void OcctlGraphUvBounds::set_is_natural_restriction(int val) { is_natural_restriction = val; }

void OcctlGraphUvBounds::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_min"), &OcctlGraphUvBounds::get_u_min);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_min", "val"), &OcctlGraphUvBounds::set_u_min);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "u_min"), "set_u_min", "get_u_min");
    godot::ClassDB::bind_method(godot::D_METHOD("get_u_max"), &OcctlGraphUvBounds::get_u_max);
    godot::ClassDB::bind_method(godot::D_METHOD("set_u_max", "val"), &OcctlGraphUvBounds::set_u_max);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "u_max"), "set_u_max", "get_u_max");
    godot::ClassDB::bind_method(godot::D_METHOD("get_v_min"), &OcctlGraphUvBounds::get_v_min);
    godot::ClassDB::bind_method(godot::D_METHOD("set_v_min", "val"), &OcctlGraphUvBounds::set_v_min);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "v_min"), "set_v_min", "get_v_min");
    godot::ClassDB::bind_method(godot::D_METHOD("get_v_max"), &OcctlGraphUvBounds::get_v_max);
    godot::ClassDB::bind_method(godot::D_METHOD("set_v_max", "val"), &OcctlGraphUvBounds::set_v_max);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "v_max"), "set_v_max", "get_v_max");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_natural_restriction"), &OcctlGraphUvBounds::get_is_natural_restriction);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_natural_restriction", "val"), &OcctlGraphUvBounds::set_is_natural_restriction);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_natural_restriction"), "set_is_natural_restriction", "get_is_natural_restriction");
}

occtl_graph_uv_bounds_t OcctlGraphUvBounds::to_c() const {
    occtl_graph_uv_bounds_t result = {};
    result.u_min = u_min;
    result.u_max = u_max;
    result.v_min = v_min;
    result.v_max = v_max;
    result.is_natural_restriction = is_natural_restriction;
    return result;
}

Ref<OcctlGraphUvBounds> OcctlGraphUvBounds::from_c(const occtl_graph_uv_bounds_t& val) {
    Ref<OcctlGraphUvBounds> r;
    r.instantiate();
    r->u_min = val.u_min;
    r->u_max = val.u_max;
    r->v_min = val.v_min;
    r->v_max = val.v_max;
    r->is_natural_restriction = val.is_natural_restriction;
    return r;
}

void OcctlGraphUvBounds::copy_from_c(const occtl_graph_uv_bounds_t& val) {
    u_min = val.u_min;
    u_max = val.u_max;
    v_min = val.v_min;
    v_max = val.v_max;
    is_natural_restriction = val.is_natural_restriction;
}
