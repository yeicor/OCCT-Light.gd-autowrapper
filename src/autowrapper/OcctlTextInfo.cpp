#include "OcctlTextInfo.h"

#include "OcctlAxis2Placement.h"

int OcctlTextInfo::get_struct_version() const { return struct_version; }
void OcctlTextInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTextInfo::get_p_next() const { return p_next; }
void OcctlTextInfo::set_p_next(int64_t val) { p_next = val; }

Ref<OcctlAxis2Placement> OcctlTextInfo::get_placement() const { return placement; }
void OcctlTextInfo::set_placement(Ref<OcctlAxis2Placement> val) { placement = val; }

String OcctlTextInfo::get_utf8_text() const { return utf8_text; }
void OcctlTextInfo::set_utf8_text(String val) { utf8_text = val; }

String OcctlTextInfo::get_font_family() const { return font_family; }
void OcctlTextInfo::set_font_family(String val) { font_family = val; }

String OcctlTextInfo::get_font_path() const { return font_path; }
void OcctlTextInfo::set_font_path(String val) { font_path = val; }

int OcctlTextInfo::get_font_aspect() const { return font_aspect; }
void OcctlTextInfo::set_font_aspect(int val) { font_aspect = val; }

double OcctlTextInfo::get_height() const { return height; }
void OcctlTextInfo::set_height(double val) { height = val; }

int OcctlTextInfo::get_horizontal_align() const { return horizontal_align; }
void OcctlTextInfo::set_horizontal_align(int val) { horizontal_align = val; }

int OcctlTextInfo::get_vertical_align() const { return vertical_align; }
void OcctlTextInfo::set_vertical_align(int val) { vertical_align = val; }

void OcctlTextInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTextInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTextInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTextInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTextInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_placement"), &OcctlTextInfo::get_placement);
    godot::ClassDB::bind_method(godot::D_METHOD("set_placement", "val"), &OcctlTextInfo::set_placement);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "placement"), "set_placement", "get_placement");
    godot::ClassDB::bind_method(godot::D_METHOD("get_utf8_text"), &OcctlTextInfo::get_utf8_text);
    godot::ClassDB::bind_method(godot::D_METHOD("set_utf8_text", "val"), &OcctlTextInfo::set_utf8_text);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "utf8_text"), "set_utf8_text", "get_utf8_text");
    godot::ClassDB::bind_method(godot::D_METHOD("get_font_family"), &OcctlTextInfo::get_font_family);
    godot::ClassDB::bind_method(godot::D_METHOD("set_font_family", "val"), &OcctlTextInfo::set_font_family);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "font_family"), "set_font_family", "get_font_family");
    godot::ClassDB::bind_method(godot::D_METHOD("get_font_path"), &OcctlTextInfo::get_font_path);
    godot::ClassDB::bind_method(godot::D_METHOD("set_font_path", "val"), &OcctlTextInfo::set_font_path);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "font_path"), "set_font_path", "get_font_path");
    godot::ClassDB::bind_method(godot::D_METHOD("get_font_aspect"), &OcctlTextInfo::get_font_aspect);
    godot::ClassDB::bind_method(godot::D_METHOD("set_font_aspect", "val"), &OcctlTextInfo::set_font_aspect);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "font_aspect"), "set_font_aspect", "get_font_aspect");
    godot::ClassDB::bind_method(godot::D_METHOD("get_height"), &OcctlTextInfo::get_height);
    godot::ClassDB::bind_method(godot::D_METHOD("set_height", "val"), &OcctlTextInfo::set_height);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "height"), "set_height", "get_height");
    godot::ClassDB::bind_method(godot::D_METHOD("get_horizontal_align"), &OcctlTextInfo::get_horizontal_align);
    godot::ClassDB::bind_method(godot::D_METHOD("set_horizontal_align", "val"), &OcctlTextInfo::set_horizontal_align);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "horizontal_align"), "set_horizontal_align", "get_horizontal_align");
    godot::ClassDB::bind_method(godot::D_METHOD("get_vertical_align"), &OcctlTextInfo::get_vertical_align);
    godot::ClassDB::bind_method(godot::D_METHOD("set_vertical_align", "val"), &OcctlTextInfo::set_vertical_align);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "vertical_align"), "set_vertical_align", "get_vertical_align");
}

occtl_text_info_t OcctlTextInfo::to_c() const {
    occtl_text_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.placement = placement->to_c();
    // const pointer field utf8_text: not convertible (type String)
    // const pointer field font_family: not convertible (type String)
    // const pointer field font_path: not convertible (type String)
    result.font_aspect = static_cast<occtl_text_font_aspect_t>(font_aspect);
    result.height = height;
    result.horizontal_align = static_cast<occtl_text_halign_t>(horizontal_align);
    result.vertical_align = static_cast<occtl_text_valign_t>(vertical_align);
    return result;
}

Ref<OcctlTextInfo> OcctlTextInfo::from_c(const occtl_text_info_t& val) {
    Ref<OcctlTextInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->placement = OcctlAxis2Placement::from_c(val.placement);
    if (val.utf8_text) r->utf8_text = String(val.utf8_text);
    if (val.font_family) r->font_family = String(val.font_family);
    if (val.font_path) r->font_path = String(val.font_path);
    r->font_aspect = static_cast<int>(val.font_aspect);
    r->height = val.height;
    r->horizontal_align = static_cast<int>(val.horizontal_align);
    r->vertical_align = static_cast<int>(val.vertical_align);
    return r;
}

void OcctlTextInfo::copy_from_c(const occtl_text_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    placement = OcctlAxis2Placement::from_c(val.placement);
    if (val.utf8_text) utf8_text = String(val.utf8_text);
    if (val.font_family) font_family = String(val.font_family);
    if (val.font_path) font_path = String(val.font_path);
    font_aspect = static_cast<int>(val.font_aspect);
    height = val.height;
    horizontal_align = static_cast<int>(val.horizontal_align);
    vertical_align = static_cast<int>(val.vertical_align);
}
