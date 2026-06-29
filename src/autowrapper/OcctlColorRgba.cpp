#include "OcctlColorRgba.h"


float OcctlColorRgba::get_r() const { return r; }
void OcctlColorRgba::set_r(float val) { r = val; }

float OcctlColorRgba::get_g() const { return g; }
void OcctlColorRgba::set_g(float val) { g = val; }

float OcctlColorRgba::get_b() const { return b; }
void OcctlColorRgba::set_b(float val) { b = val; }

float OcctlColorRgba::get_a() const { return a; }
void OcctlColorRgba::set_a(float val) { a = val; }

void OcctlColorRgba::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_r"), &OcctlColorRgba::get_r);
    godot::ClassDB::bind_method(godot::D_METHOD("set_r", "val"), &OcctlColorRgba::set_r);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "r"), "set_r", "get_r");
    godot::ClassDB::bind_method(godot::D_METHOD("get_g"), &OcctlColorRgba::get_g);
    godot::ClassDB::bind_method(godot::D_METHOD("set_g", "val"), &OcctlColorRgba::set_g);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "g"), "set_g", "get_g");
    godot::ClassDB::bind_method(godot::D_METHOD("get_b"), &OcctlColorRgba::get_b);
    godot::ClassDB::bind_method(godot::D_METHOD("set_b", "val"), &OcctlColorRgba::set_b);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "b"), "set_b", "get_b");
    godot::ClassDB::bind_method(godot::D_METHOD("get_a"), &OcctlColorRgba::get_a);
    godot::ClassDB::bind_method(godot::D_METHOD("set_a", "val"), &OcctlColorRgba::set_a);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "a"), "set_a", "get_a");
    godot::ClassDB::bind_static_method("OcctlColorRgba", godot::D_METHOD("from_color", "c"), &OcctlColorRgba::from_color);
}

occtl_color_rgba_t OcctlColorRgba::to_c() const {
    occtl_color_rgba_t result = {};
    result.r = r;
    result.g = g;
    result.b = b;
    result.a = a;
    return result;
}

Ref<OcctlColorRgba> OcctlColorRgba::from_c(const occtl_color_rgba_t& val) {
    Ref<OcctlColorRgba> r;
    r.instantiate();
    r->r = val.r;
    r->g = val.g;
    r->b = val.b;
    r->a = val.a;
    return r;
}

void OcctlColorRgba::copy_from_c(const occtl_color_rgba_t& val) {
    r = val.r;
    g = val.g;
    b = val.b;
    a = val.a;
}

Ref<OcctlColorRgba> OcctlColorRgba::from_color(Color c) {
    Ref<OcctlColorRgba> instance;
    instance.instantiate();
    instance->r = c.r;
    instance->g = c.g;
    instance->b = c.b;
    instance->a = c.a;
    return instance;
}
