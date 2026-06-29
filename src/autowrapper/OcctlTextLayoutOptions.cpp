#include "OcctlTextLayoutOptions.h"


int OcctlTextLayoutOptions::get_struct_version() const { return struct_version; }
void OcctlTextLayoutOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTextLayoutOptions::get_p_next() const { return p_next; }
void OcctlTextLayoutOptions::set_p_next(int64_t val) { p_next = val; }

double OcctlTextLayoutOptions::get_wrapping_width() const { return wrapping_width; }
void OcctlTextLayoutOptions::set_wrapping_width(double val) { wrapping_width = val; }

int OcctlTextLayoutOptions::get_word_wrapping() const { return word_wrapping; }
void OcctlTextLayoutOptions::set_word_wrapping(int val) { word_wrapping = val; }

void OcctlTextLayoutOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTextLayoutOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTextLayoutOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTextLayoutOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTextLayoutOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_wrapping_width"), &OcctlTextLayoutOptions::get_wrapping_width);
    godot::ClassDB::bind_method(godot::D_METHOD("set_wrapping_width", "val"), &OcctlTextLayoutOptions::set_wrapping_width);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "wrapping_width"), "set_wrapping_width", "get_wrapping_width");
    godot::ClassDB::bind_method(godot::D_METHOD("get_word_wrapping"), &OcctlTextLayoutOptions::get_word_wrapping);
    godot::ClassDB::bind_method(godot::D_METHOD("set_word_wrapping", "val"), &OcctlTextLayoutOptions::set_word_wrapping);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "word_wrapping"), "set_word_wrapping", "get_word_wrapping");
}

occtl_text_layout_options_t OcctlTextLayoutOptions::to_c() const {
    occtl_text_layout_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.wrapping_width = wrapping_width;
    result.word_wrapping = word_wrapping;
    return result;
}

Ref<OcctlTextLayoutOptions> OcctlTextLayoutOptions::from_c(const occtl_text_layout_options_t& val) {
    Ref<OcctlTextLayoutOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->wrapping_width = val.wrapping_width;
    r->word_wrapping = val.word_wrapping;
    return r;
}

void OcctlTextLayoutOptions::copy_from_c(const occtl_text_layout_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    wrapping_width = val.wrapping_width;
    word_wrapping = val.word_wrapping;
}
