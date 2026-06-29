#ifndef OCCTLIOBREPWRITEOPTIONS_H
#define OCCTLIOBREPWRITEOPTIONS_H

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
#include "occtl/occtl_io_brep.h"


using namespace godot;

class OcctlIoBrepWriteOptions : public godot::RefCounted {
    GDCLASS(OcctlIoBrepWriteOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int write_triangulation;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int get_write_triangulation() const;
    void set_write_triangulation(int val);

    occtl_io_brep_write_options_t to_c() const;
    static Ref<OcctlIoBrepWriteOptions> from_c(const occtl_io_brep_write_options_t& val);
    void copy_from_c(const occtl_io_brep_write_options_t& val);
};

#endif // OCCTLIOBREPWRITEOPTIONS_H
