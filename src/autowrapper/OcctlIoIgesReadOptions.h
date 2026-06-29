#ifndef OCCTLIOIGESREADOPTIONS_H
#define OCCTLIOIGESREADOPTIONS_H

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
#include "occtl/occtl_io_iges.h"


using namespace godot;

class OcctlIoIgesReadOptions : public godot::RefCounted {
    GDCLASS(OcctlIoIgesReadOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int read_color;
    int read_name;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int get_read_color() const;
    void set_read_color(int val);
    int get_read_name() const;
    void set_read_name(int val);

    occtl_io_iges_read_options_t to_c() const;
    static Ref<OcctlIoIgesReadOptions> from_c(const occtl_io_iges_read_options_t& val);
    void copy_from_c(const occtl_io_iges_read_options_t& val);
};

#endif // OCCTLIOIGESREADOPTIONS_H
