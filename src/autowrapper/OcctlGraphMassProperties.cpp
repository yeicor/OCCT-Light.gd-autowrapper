#include "OcctlGraphMassProperties.h"

#include "OcctlPoint3.h"

double OcctlGraphMassProperties::get_linear_length() const { return linear_length; }
void OcctlGraphMassProperties::set_linear_length(double val) { linear_length = val; }

double OcctlGraphMassProperties::get_surface_area() const { return surface_area; }
void OcctlGraphMassProperties::set_surface_area(double val) { surface_area = val; }

double OcctlGraphMassProperties::get_volume() const { return volume; }
void OcctlGraphMassProperties::set_volume(double val) { volume = val; }

double OcctlGraphMassProperties::get_mass() const { return mass; }
void OcctlGraphMassProperties::set_mass(double val) { mass = val; }

Ref<OcctlPoint3> OcctlGraphMassProperties::get_centre_of_mass() const { return centre_of_mass; }
void OcctlGraphMassProperties::set_centre_of_mass(Ref<OcctlPoint3> val) { centre_of_mass = val; }

PackedFloat64Array OcctlGraphMassProperties::get_inertia() const { return inertia; }
void OcctlGraphMassProperties::set_inertia(PackedFloat64Array val) { inertia = val; }

void OcctlGraphMassProperties::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_linear_length"), &OcctlGraphMassProperties::get_linear_length);
    godot::ClassDB::bind_method(godot::D_METHOD("set_linear_length", "val"), &OcctlGraphMassProperties::set_linear_length);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "linear_length"), "set_linear_length", "get_linear_length");
    godot::ClassDB::bind_method(godot::D_METHOD("get_surface_area"), &OcctlGraphMassProperties::get_surface_area);
    godot::ClassDB::bind_method(godot::D_METHOD("set_surface_area", "val"), &OcctlGraphMassProperties::set_surface_area);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "surface_area"), "set_surface_area", "get_surface_area");
    godot::ClassDB::bind_method(godot::D_METHOD("get_volume"), &OcctlGraphMassProperties::get_volume);
    godot::ClassDB::bind_method(godot::D_METHOD("set_volume", "val"), &OcctlGraphMassProperties::set_volume);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "volume"), "set_volume", "get_volume");
    godot::ClassDB::bind_method(godot::D_METHOD("get_mass"), &OcctlGraphMassProperties::get_mass);
    godot::ClassDB::bind_method(godot::D_METHOD("set_mass", "val"), &OcctlGraphMassProperties::set_mass);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "mass"), "set_mass", "get_mass");
    godot::ClassDB::bind_method(godot::D_METHOD("get_centre_of_mass"), &OcctlGraphMassProperties::get_centre_of_mass);
    godot::ClassDB::bind_method(godot::D_METHOD("set_centre_of_mass", "val"), &OcctlGraphMassProperties::set_centre_of_mass);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "centre_of_mass"), "set_centre_of_mass", "get_centre_of_mass");
    godot::ClassDB::bind_method(godot::D_METHOD("get_inertia"), &OcctlGraphMassProperties::get_inertia);
    godot::ClassDB::bind_method(godot::D_METHOD("set_inertia", "val"), &OcctlGraphMassProperties::set_inertia);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "inertia"), "set_inertia", "get_inertia");
}

occtl_graph_mass_properties_t OcctlGraphMassProperties::to_c() const {
    occtl_graph_mass_properties_t result = {};
    result.linear_length = linear_length;
    result.surface_area = surface_area;
    result.volume = volume;
    result.mass = mass;
    result.centre_of_mass = centre_of_mass->to_c();
    for (int _i = 0; _i < 9; _i++) result.inertia[_i] = inertia[_i];
    return result;
}

Ref<OcctlGraphMassProperties> OcctlGraphMassProperties::from_c(const occtl_graph_mass_properties_t& val) {
    Ref<OcctlGraphMassProperties> r;
    r.instantiate();
    r->linear_length = val.linear_length;
    r->surface_area = val.surface_area;
    r->volume = val.volume;
    r->mass = val.mass;
    r->centre_of_mass = OcctlPoint3::from_c(val.centre_of_mass);
    r->inertia.resize(9);
    for (int _i = 0; _i < 9; _i++) r->inertia[_i] = val.inertia[_i];
    return r;
}

void OcctlGraphMassProperties::copy_from_c(const occtl_graph_mass_properties_t& val) {
    linear_length = val.linear_length;
    surface_area = val.surface_area;
    volume = val.volume;
    mass = val.mass;
    centre_of_mass = OcctlPoint3::from_c(val.centre_of_mass);
    inertia.resize(9);
    for (int _i = 0; _i < 9; _i++) inertia[_i] = val.inertia[_i];
}
