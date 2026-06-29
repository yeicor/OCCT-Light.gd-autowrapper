#ifndef OCCTLDEFORMATINFO_H
#define OCCTLDEFORMATINFO_H

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
#include "occtl/occtl_de.h"


using namespace godot;

class OcctlDeFormatInfo : public godot::RefCounted {
    GDCLASS(OcctlDeFormatInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    String id;
    String label;
    int extension_count;
    int can_read_file;
    int can_write_file;
    int can_read_memory;
    int can_write_memory;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    String get_id() const;
    void set_id(String val);
    String get_label() const;
    void set_label(String val);
    int get_extension_count() const;
    void set_extension_count(int val);
    int get_can_read_file() const;
    void set_can_read_file(int val);
    int get_can_write_file() const;
    void set_can_write_file(int val);
    int get_can_read_memory() const;
    void set_can_read_memory(int val);
    int get_can_write_memory() const;
    void set_can_write_memory(int val);

    occtl_de_format_info_t to_c() const;
    static Ref<OcctlDeFormatInfo> from_c(const occtl_de_format_info_t& val);
    void copy_from_c(const occtl_de_format_info_t& val);
};

#endif // OCCTLDEFORMATINFO_H
