#ifndef OCCTLIOVRMLREADOPTIONS_H
#define OCCTLIOVRMLREADOPTIONS_H

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

class OcctlIoVrmlReadOptions : public godot::RefCounted {
    GDCLASS(OcctlIoVrmlReadOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    double file_length_unit_m;
    int system_coordinate_system;
    int file_coordinate_system;
    int fill_incomplete;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    double get_file_length_unit_m() const;
    void set_file_length_unit_m(double val);
    int get_system_coordinate_system() const;
    void set_system_coordinate_system(int val);
    int get_file_coordinate_system() const;
    void set_file_coordinate_system(int val);
    int get_fill_incomplete() const;
    void set_fill_incomplete(int val);

    occtl_io_vrml_read_options_t to_c() const;
    static Ref<OcctlIoVrmlReadOptions> from_c(const occtl_io_vrml_read_options_t& val);
    void copy_from_c(const occtl_io_vrml_read_options_t& val);
};

#endif // OCCTLIOVRMLREADOPTIONS_H
