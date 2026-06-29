#ifndef OCCTLGRAPHMASSPROPERTIES_H
#define OCCTLGRAPHMASSPROPERTIES_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/vector3.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/transform3d.hpp>
#include <godot_cpp/variant/aabb.hpp>
#include <godot_cpp/variant/color.hpp>
#include <cstdint>
#include <vector>
#include "occtl/occtl_topo_build.h"

#include "OcctlPoint3.h"

using namespace godot;

class OcctlGraphMassProperties : public godot::RefCounted {
    GDCLASS(OcctlGraphMassProperties, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    double linear_length;
    double surface_area;
    double volume;
    double mass;
    Ref<OcctlPoint3> centre_of_mass;
    PackedFloat64Array inertia;

    double get_linear_length() const;
    void set_linear_length(double val);
    double get_surface_area() const;
    void set_surface_area(double val);
    double get_volume() const;
    void set_volume(double val);
    double get_mass() const;
    void set_mass(double val);
    Ref<OcctlPoint3> get_centre_of_mass() const;
    void set_centre_of_mass(Ref<OcctlPoint3> val);
    PackedFloat64Array get_inertia() const;
    void set_inertia(PackedFloat64Array val);

    occtl_graph_mass_properties_t to_c() const;
    static Ref<OcctlGraphMassProperties> from_c(const occtl_graph_mass_properties_t& val);
    void copy_from_c(const occtl_graph_mass_properties_t& val);
};

#endif // OCCTLGRAPHMASSPROPERTIES_H
