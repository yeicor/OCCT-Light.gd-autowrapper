#ifndef OCCTLTEXTMETRICS_H
#define OCCTLTEXTMETRICS_H

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

class OcctlTextMetrics : public godot::RefCounted {
    GDCLASS(OcctlTextMetrics, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    double width;
    double height;
    double left;
    double right;
    double bottom;
    double top;
    double ascender;
    double descender;
    double line_spacing;
    double max_symbol_width;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    double get_width() const;
    void set_width(double val);
    double get_height() const;
    void set_height(double val);
    double get_left() const;
    void set_left(double val);
    double get_right() const;
    void set_right(double val);
    double get_bottom() const;
    void set_bottom(double val);
    double get_top() const;
    void set_top(double val);
    double get_ascender() const;
    void set_ascender(double val);
    double get_descender() const;
    void set_descender(double val);
    double get_line_spacing() const;
    void set_line_spacing(double val);
    double get_max_symbol_width() const;
    void set_max_symbol_width(double val);

    occtl_text_metrics_t to_c() const;
    static Ref<OcctlTextMetrics> from_c(const occtl_text_metrics_t& val);
    void copy_from_c(const occtl_text_metrics_t& val);
};

#endif // OCCTLTEXTMETRICS_H
