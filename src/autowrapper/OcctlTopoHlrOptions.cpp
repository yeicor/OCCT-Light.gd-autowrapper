#include "OcctlTopoHlrOptions.h"

#include "OcctlNodeId.h"
#include "OcctlAxis3Placement.h"

int OcctlTopoHlrOptions::get_struct_version() const { return struct_version; }
void OcctlTopoHlrOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoHlrOptions::get_p_next() const { return p_next; }
void OcctlTopoHlrOptions::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlTopoHlrOptions::get_root() const { return root; }
void OcctlTopoHlrOptions::set_root(int64_t val) { root = val; }

Ref<OcctlAxis3Placement> OcctlTopoHlrOptions::get_projection_frame() const { return projection_frame; }
void OcctlTopoHlrOptions::set_projection_frame(Ref<OcctlAxis3Placement> val) { projection_frame = val; }

double OcctlTopoHlrOptions::get_focus() const { return focus; }
void OcctlTopoHlrOptions::set_focus(double val) { focus = val; }

int OcctlTopoHlrOptions::get_include_hidden() const { return include_hidden; }
void OcctlTopoHlrOptions::set_include_hidden(int val) { include_hidden = val; }

int OcctlTopoHlrOptions::get_include_smooth() const { return include_smooth; }
void OcctlTopoHlrOptions::set_include_smooth(int val) { include_smooth = val; }

int OcctlTopoHlrOptions::get_include_outline() const { return include_outline; }
void OcctlTopoHlrOptions::set_include_outline(int val) { include_outline = val; }

int OcctlTopoHlrOptions::get_mode() const { return mode; }
void OcctlTopoHlrOptions::set_mode(int val) { mode = val; }

void OcctlTopoHlrOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoHlrOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoHlrOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoHlrOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoHlrOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_root"), &OcctlTopoHlrOptions::get_root);
    godot::ClassDB::bind_method(godot::D_METHOD("set_root", "val"), &OcctlTopoHlrOptions::set_root);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "root"), "set_root", "get_root");
    godot::ClassDB::bind_method(godot::D_METHOD("get_projection_frame"), &OcctlTopoHlrOptions::get_projection_frame);
    godot::ClassDB::bind_method(godot::D_METHOD("set_projection_frame", "val"), &OcctlTopoHlrOptions::set_projection_frame);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "projection_frame"), "set_projection_frame", "get_projection_frame");
    godot::ClassDB::bind_method(godot::D_METHOD("get_focus"), &OcctlTopoHlrOptions::get_focus);
    godot::ClassDB::bind_method(godot::D_METHOD("set_focus", "val"), &OcctlTopoHlrOptions::set_focus);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "focus"), "set_focus", "get_focus");
    godot::ClassDB::bind_method(godot::D_METHOD("get_include_hidden"), &OcctlTopoHlrOptions::get_include_hidden);
    godot::ClassDB::bind_method(godot::D_METHOD("set_include_hidden", "val"), &OcctlTopoHlrOptions::set_include_hidden);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "include_hidden"), "set_include_hidden", "get_include_hidden");
    godot::ClassDB::bind_method(godot::D_METHOD("get_include_smooth"), &OcctlTopoHlrOptions::get_include_smooth);
    godot::ClassDB::bind_method(godot::D_METHOD("set_include_smooth", "val"), &OcctlTopoHlrOptions::set_include_smooth);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "include_smooth"), "set_include_smooth", "get_include_smooth");
    godot::ClassDB::bind_method(godot::D_METHOD("get_include_outline"), &OcctlTopoHlrOptions::get_include_outline);
    godot::ClassDB::bind_method(godot::D_METHOD("set_include_outline", "val"), &OcctlTopoHlrOptions::set_include_outline);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "include_outline"), "set_include_outline", "get_include_outline");
    godot::ClassDB::bind_method(godot::D_METHOD("get_mode"), &OcctlTopoHlrOptions::get_mode);
    godot::ClassDB::bind_method(godot::D_METHOD("set_mode", "val"), &OcctlTopoHlrOptions::set_mode);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "mode"), "set_mode", "get_mode");
}

occtl_topo_hlr_options_t OcctlTopoHlrOptions::to_c() const {
    occtl_topo_hlr_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.root.bits = static_cast<uint64_t>(root);
    result.projection_frame = projection_frame->to_c();
    result.focus = focus;
    result.include_hidden = include_hidden;
    result.include_smooth = include_smooth;
    result.include_outline = include_outline;
    result.mode = static_cast<occtl_topo_hlr_mode_t>(mode);
    return result;
}

Ref<OcctlTopoHlrOptions> OcctlTopoHlrOptions::from_c(const occtl_topo_hlr_options_t& val) {
    Ref<OcctlTopoHlrOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->root = static_cast<int64_t>(val.root.bits);
    r->projection_frame = OcctlAxis3Placement::from_c(val.projection_frame);
    r->focus = val.focus;
    r->include_hidden = val.include_hidden;
    r->include_smooth = val.include_smooth;
    r->include_outline = val.include_outline;
    r->mode = static_cast<int>(val.mode);
    return r;
}

void OcctlTopoHlrOptions::copy_from_c(const occtl_topo_hlr_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    root = static_cast<int64_t>(val.root.bits);
    projection_frame = OcctlAxis3Placement::from_c(val.projection_frame);
    focus = val.focus;
    include_hidden = val.include_hidden;
    include_smooth = val.include_smooth;
    include_outline = val.include_outline;
    mode = static_cast<int>(val.mode);
}
