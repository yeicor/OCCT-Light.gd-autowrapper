#ifndef OCCTLCOLORRGBA_H
#define OCCTLCOLORRGBA_H

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


using namespace godot;

class OcctlColorRgba : public godot::RefCounted {
    GDCLASS(OcctlColorRgba, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    float r;
    float g;
    float b;
    float a;

    float get_r() const;
    void set_r(float val);
    float get_g() const;
    void set_g(float val);
    float get_b() const;
    void set_b(float val);
    float get_a() const;
    void set_a(float val);

    occtl_color_rgba_t to_c() const;
    static Ref<OcctlColorRgba> from_c(const occtl_color_rgba_t& val);
    void copy_from_c(const occtl_color_rgba_t& val);

    static Ref<OcctlColorRgba> from_color(Color c); // NOLINT
};

#endif // OCCTLCOLORRGBA_H
