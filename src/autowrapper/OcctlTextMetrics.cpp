#include "OcctlTextMetrics.h"


int OcctlTextMetrics::get_struct_version() const { return struct_version; }
void OcctlTextMetrics::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTextMetrics::get_p_next() const { return p_next; }
void OcctlTextMetrics::set_p_next(int64_t val) { p_next = val; }

double OcctlTextMetrics::get_width() const { return width; }
void OcctlTextMetrics::set_width(double val) { width = val; }

double OcctlTextMetrics::get_height() const { return height; }
void OcctlTextMetrics::set_height(double val) { height = val; }

double OcctlTextMetrics::get_left() const { return left; }
void OcctlTextMetrics::set_left(double val) { left = val; }

double OcctlTextMetrics::get_right() const { return right; }
void OcctlTextMetrics::set_right(double val) { right = val; }

double OcctlTextMetrics::get_bottom() const { return bottom; }
void OcctlTextMetrics::set_bottom(double val) { bottom = val; }

double OcctlTextMetrics::get_top() const { return top; }
void OcctlTextMetrics::set_top(double val) { top = val; }

double OcctlTextMetrics::get_ascender() const { return ascender; }
void OcctlTextMetrics::set_ascender(double val) { ascender = val; }

double OcctlTextMetrics::get_descender() const { return descender; }
void OcctlTextMetrics::set_descender(double val) { descender = val; }

double OcctlTextMetrics::get_line_spacing() const { return line_spacing; }
void OcctlTextMetrics::set_line_spacing(double val) { line_spacing = val; }

double OcctlTextMetrics::get_max_symbol_width() const { return max_symbol_width; }
void OcctlTextMetrics::set_max_symbol_width(double val) { max_symbol_width = val; }

void OcctlTextMetrics::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTextMetrics::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTextMetrics::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTextMetrics::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTextMetrics::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_width"), &OcctlTextMetrics::get_width);
    godot::ClassDB::bind_method(godot::D_METHOD("set_width", "val"), &OcctlTextMetrics::set_width);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "width"), "set_width", "get_width");
    godot::ClassDB::bind_method(godot::D_METHOD("get_height"), &OcctlTextMetrics::get_height);
    godot::ClassDB::bind_method(godot::D_METHOD("set_height", "val"), &OcctlTextMetrics::set_height);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "height"), "set_height", "get_height");
    godot::ClassDB::bind_method(godot::D_METHOD("get_left"), &OcctlTextMetrics::get_left);
    godot::ClassDB::bind_method(godot::D_METHOD("set_left", "val"), &OcctlTextMetrics::set_left);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "left"), "set_left", "get_left");
    godot::ClassDB::bind_method(godot::D_METHOD("get_right"), &OcctlTextMetrics::get_right);
    godot::ClassDB::bind_method(godot::D_METHOD("set_right", "val"), &OcctlTextMetrics::set_right);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "right"), "set_right", "get_right");
    godot::ClassDB::bind_method(godot::D_METHOD("get_bottom"), &OcctlTextMetrics::get_bottom);
    godot::ClassDB::bind_method(godot::D_METHOD("set_bottom", "val"), &OcctlTextMetrics::set_bottom);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "bottom"), "set_bottom", "get_bottom");
    godot::ClassDB::bind_method(godot::D_METHOD("get_top"), &OcctlTextMetrics::get_top);
    godot::ClassDB::bind_method(godot::D_METHOD("set_top", "val"), &OcctlTextMetrics::set_top);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "top"), "set_top", "get_top");
    godot::ClassDB::bind_method(godot::D_METHOD("get_ascender"), &OcctlTextMetrics::get_ascender);
    godot::ClassDB::bind_method(godot::D_METHOD("set_ascender", "val"), &OcctlTextMetrics::set_ascender);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "ascender"), "set_ascender", "get_ascender");
    godot::ClassDB::bind_method(godot::D_METHOD("get_descender"), &OcctlTextMetrics::get_descender);
    godot::ClassDB::bind_method(godot::D_METHOD("set_descender", "val"), &OcctlTextMetrics::set_descender);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "descender"), "set_descender", "get_descender");
    godot::ClassDB::bind_method(godot::D_METHOD("get_line_spacing"), &OcctlTextMetrics::get_line_spacing);
    godot::ClassDB::bind_method(godot::D_METHOD("set_line_spacing", "val"), &OcctlTextMetrics::set_line_spacing);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "line_spacing"), "set_line_spacing", "get_line_spacing");
    godot::ClassDB::bind_method(godot::D_METHOD("get_max_symbol_width"), &OcctlTextMetrics::get_max_symbol_width);
    godot::ClassDB::bind_method(godot::D_METHOD("set_max_symbol_width", "val"), &OcctlTextMetrics::set_max_symbol_width);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max_symbol_width"), "set_max_symbol_width", "get_max_symbol_width");
}

occtl_text_metrics_t OcctlTextMetrics::to_c() const {
    occtl_text_metrics_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.width = width;
    result.height = height;
    result.left = left;
    result.right = right;
    result.bottom = bottom;
    result.top = top;
    result.ascender = ascender;
    result.descender = descender;
    result.line_spacing = line_spacing;
    result.max_symbol_width = max_symbol_width;
    return result;
}

Ref<OcctlTextMetrics> OcctlTextMetrics::from_c(const occtl_text_metrics_t& val) {
    Ref<OcctlTextMetrics> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->width = val.width;
    r->height = val.height;
    r->left = val.left;
    r->right = val.right;
    r->bottom = val.bottom;
    r->top = val.top;
    r->ascender = val.ascender;
    r->descender = val.descender;
    r->line_spacing = val.line_spacing;
    r->max_symbol_width = val.max_symbol_width;
    return r;
}

void OcctlTextMetrics::copy_from_c(const occtl_text_metrics_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    width = val.width;
    height = val.height;
    left = val.left;
    right = val.right;
    bottom = val.bottom;
    top = val.top;
    ascender = val.ascender;
    descender = val.descender;
    line_spacing = val.line_spacing;
    max_symbol_width = val.max_symbol_width;
}
