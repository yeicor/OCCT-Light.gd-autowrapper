#ifndef OCCTLTEXTLAYOUTOPTIONS_H
#define OCCTLTEXTLAYOUTOPTIONS_H

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
#include "occtl/occtl_text.h"


using namespace godot;

class OcctlTextLayoutOptions : public godot::RefCounted {
    GDCLASS(OcctlTextLayoutOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    double wrapping_width;
    int word_wrapping;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    double get_wrapping_width() const;
    void set_wrapping_width(double val);
    int get_word_wrapping() const;
    void set_word_wrapping(int val);

    occtl_text_layout_options_t to_c() const;
    static Ref<OcctlTextLayoutOptions> from_c(const occtl_text_layout_options_t& val);
    void copy_from_c(const occtl_text_layout_options_t& val);
};

#endif // OCCTLTEXTLAYOUTOPTIONS_H
