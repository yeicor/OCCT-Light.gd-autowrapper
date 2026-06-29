#ifndef OCCTLIOVRMLWRITEOPTIONS_H
#define OCCTLIOVRMLWRITEOPTIONS_H

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
#include "occtl/occtl_io_vrml.h"


using namespace godot;

class OcctlIoVrmlWriteOptions : public godot::RefCounted {
    GDCLASS(OcctlIoVrmlWriteOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int writer_version;
    int representation;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int get_writer_version() const;
    void set_writer_version(int val);
    int get_representation() const;
    void set_representation(int val);

    occtl_io_vrml_write_options_t to_c() const;
    static Ref<OcctlIoVrmlWriteOptions> from_c(const occtl_io_vrml_write_options_t& val);
    void copy_from_c(const occtl_io_vrml_write_options_t& val);
};

#endif // OCCTLIOVRMLWRITEOPTIONS_H
