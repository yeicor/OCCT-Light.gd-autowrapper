#ifndef OCCTLTEXTINFO_H
#define OCCTLTEXTINFO_H

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

#include "OcctlAxis2Placement.h"

using namespace godot;

class OcctlTextInfo : public godot::RefCounted {
    GDCLASS(OcctlTextInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    Ref<OcctlAxis2Placement> placement;
    String utf8_text;
    String font_family;
    String font_path;
    int font_aspect;
    double height;
    int horizontal_align;
    int vertical_align;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    Ref<OcctlAxis2Placement> get_placement() const;
    void set_placement(Ref<OcctlAxis2Placement> val);
    String get_utf8_text() const;
    void set_utf8_text(String val);
    String get_font_family() const;
    void set_font_family(String val);
    String get_font_path() const;
    void set_font_path(String val);
    int get_font_aspect() const;
    void set_font_aspect(int val);
    double get_height() const;
    void set_height(double val);
    int get_horizontal_align() const;
    void set_horizontal_align(int val);
    int get_vertical_align() const;
    void set_vertical_align(int val);

    occtl_text_info_t to_c() const;
    static Ref<OcctlTextInfo> from_c(const occtl_text_info_t& val);
    void copy_from_c(const occtl_text_info_t& val);
};

#endif // OCCTLTEXTINFO_H
