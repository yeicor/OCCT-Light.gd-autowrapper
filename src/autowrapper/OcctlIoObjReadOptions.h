#ifndef OCCTLIOOBJREADOPTIONS_H
#define OCCTLIOOBJREADOPTIONS_H

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
#include "occtl/occtl_io_obj.h"


using namespace godot;

class OcctlIoObjReadOptions : public godot::RefCounted {
    GDCLASS(OcctlIoObjReadOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    double file_length_unit_m;
    int system_coordinate_system;
    int file_coordinate_system;
    int single_precision;
    int create_shapes;
    int fill_incomplete;
    int memory_limit_mib;
    String root_prefix;

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
    int get_single_precision() const;
    void set_single_precision(int val);
    int get_create_shapes() const;
    void set_create_shapes(int val);
    int get_fill_incomplete() const;
    void set_fill_incomplete(int val);
    int get_memory_limit_mib() const;
    void set_memory_limit_mib(int val);
    String get_root_prefix() const;
    void set_root_prefix(String val);

    occtl_io_obj_read_options_t to_c() const;
    static Ref<OcctlIoObjReadOptions> from_c(const occtl_io_obj_read_options_t& val);
    void copy_from_c(const occtl_io_obj_read_options_t& val);
};

#endif // OCCTLIOOBJREADOPTIONS_H
