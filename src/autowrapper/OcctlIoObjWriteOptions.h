#ifndef OCCTLIOOBJWRITEOPTIONS_H
#define OCCTLIOOBJWRITEOPTIONS_H

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

class OcctlIoObjWriteOptions : public godot::RefCounted {
    GDCLASS(OcctlIoObjWriteOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int system_coordinate_system;
    int file_coordinate_system;
    String comment;
    String author;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int get_system_coordinate_system() const;
    void set_system_coordinate_system(int val);
    int get_file_coordinate_system() const;
    void set_file_coordinate_system(int val);
    String get_comment() const;
    void set_comment(String val);
    String get_author() const;
    void set_author(String val);

    occtl_io_obj_write_options_t to_c() const;
    static Ref<OcctlIoObjWriteOptions> from_c(const occtl_io_obj_write_options_t& val);
    void copy_from_c(const occtl_io_obj_write_options_t& val);
};

#endif // OCCTLIOOBJWRITEOPTIONS_H
