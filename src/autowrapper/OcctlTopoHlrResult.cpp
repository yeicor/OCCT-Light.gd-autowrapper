#include "OcctlTopoHlrResult.h"

#include "OcctlNodeId.h"

int OcctlTopoHlrResult::get_struct_version() const { return struct_version; }
void OcctlTopoHlrResult::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoHlrResult::get_p_next() const { return p_next; }
void OcctlTopoHlrResult::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlTopoHlrResult::get_graph() const { return graph; }
void OcctlTopoHlrResult::set_graph(int64_t val) { graph = val; }

int64_t OcctlTopoHlrResult::get_visible_sharp() const { return visible_sharp; }
void OcctlTopoHlrResult::set_visible_sharp(int64_t val) { visible_sharp = val; }

int64_t OcctlTopoHlrResult::get_visible_smooth() const { return visible_smooth; }
void OcctlTopoHlrResult::set_visible_smooth(int64_t val) { visible_smooth = val; }

int64_t OcctlTopoHlrResult::get_visible_seam() const { return visible_seam; }
void OcctlTopoHlrResult::set_visible_seam(int64_t val) { visible_seam = val; }

int64_t OcctlTopoHlrResult::get_visible_outline() const { return visible_outline; }
void OcctlTopoHlrResult::set_visible_outline(int64_t val) { visible_outline = val; }

int64_t OcctlTopoHlrResult::get_hidden_sharp() const { return hidden_sharp; }
void OcctlTopoHlrResult::set_hidden_sharp(int64_t val) { hidden_sharp = val; }

int64_t OcctlTopoHlrResult::get_hidden_smooth() const { return hidden_smooth; }
void OcctlTopoHlrResult::set_hidden_smooth(int64_t val) { hidden_smooth = val; }

int64_t OcctlTopoHlrResult::get_hidden_seam() const { return hidden_seam; }
void OcctlTopoHlrResult::set_hidden_seam(int64_t val) { hidden_seam = val; }

int64_t OcctlTopoHlrResult::get_hidden_outline() const { return hidden_outline; }
void OcctlTopoHlrResult::set_hidden_outline(int64_t val) { hidden_outline = val; }

void OcctlTopoHlrResult::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoHlrResult::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoHlrResult::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoHlrResult::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoHlrResult::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_graph"), &OcctlTopoHlrResult::get_graph);
    godot::ClassDB::bind_method(godot::D_METHOD("set_graph", "val"), &OcctlTopoHlrResult::set_graph);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "graph"), "set_graph", "get_graph");
    godot::ClassDB::bind_method(godot::D_METHOD("get_visible_sharp"), &OcctlTopoHlrResult::get_visible_sharp);
    godot::ClassDB::bind_method(godot::D_METHOD("set_visible_sharp", "val"), &OcctlTopoHlrResult::set_visible_sharp);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "visible_sharp"), "set_visible_sharp", "get_visible_sharp");
    godot::ClassDB::bind_method(godot::D_METHOD("get_visible_smooth"), &OcctlTopoHlrResult::get_visible_smooth);
    godot::ClassDB::bind_method(godot::D_METHOD("set_visible_smooth", "val"), &OcctlTopoHlrResult::set_visible_smooth);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "visible_smooth"), "set_visible_smooth", "get_visible_smooth");
    godot::ClassDB::bind_method(godot::D_METHOD("get_visible_seam"), &OcctlTopoHlrResult::get_visible_seam);
    godot::ClassDB::bind_method(godot::D_METHOD("set_visible_seam", "val"), &OcctlTopoHlrResult::set_visible_seam);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "visible_seam"), "set_visible_seam", "get_visible_seam");
    godot::ClassDB::bind_method(godot::D_METHOD("get_visible_outline"), &OcctlTopoHlrResult::get_visible_outline);
    godot::ClassDB::bind_method(godot::D_METHOD("set_visible_outline", "val"), &OcctlTopoHlrResult::set_visible_outline);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "visible_outline"), "set_visible_outline", "get_visible_outline");
    godot::ClassDB::bind_method(godot::D_METHOD("get_hidden_sharp"), &OcctlTopoHlrResult::get_hidden_sharp);
    godot::ClassDB::bind_method(godot::D_METHOD("set_hidden_sharp", "val"), &OcctlTopoHlrResult::set_hidden_sharp);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "hidden_sharp"), "set_hidden_sharp", "get_hidden_sharp");
    godot::ClassDB::bind_method(godot::D_METHOD("get_hidden_smooth"), &OcctlTopoHlrResult::get_hidden_smooth);
    godot::ClassDB::bind_method(godot::D_METHOD("set_hidden_smooth", "val"), &OcctlTopoHlrResult::set_hidden_smooth);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "hidden_smooth"), "set_hidden_smooth", "get_hidden_smooth");
    godot::ClassDB::bind_method(godot::D_METHOD("get_hidden_seam"), &OcctlTopoHlrResult::get_hidden_seam);
    godot::ClassDB::bind_method(godot::D_METHOD("set_hidden_seam", "val"), &OcctlTopoHlrResult::set_hidden_seam);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "hidden_seam"), "set_hidden_seam", "get_hidden_seam");
    godot::ClassDB::bind_method(godot::D_METHOD("get_hidden_outline"), &OcctlTopoHlrResult::get_hidden_outline);
    godot::ClassDB::bind_method(godot::D_METHOD("set_hidden_outline", "val"), &OcctlTopoHlrResult::set_hidden_outline);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "hidden_outline"), "set_hidden_outline", "get_hidden_outline");
}

occtl_topo_hlr_result_t OcctlTopoHlrResult::to_c() const {
    occtl_topo_hlr_result_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.graph = reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph));
    result.visible_sharp.bits = static_cast<uint64_t>(visible_sharp);
    result.visible_smooth.bits = static_cast<uint64_t>(visible_smooth);
    result.visible_seam.bits = static_cast<uint64_t>(visible_seam);
    result.visible_outline.bits = static_cast<uint64_t>(visible_outline);
    result.hidden_sharp.bits = static_cast<uint64_t>(hidden_sharp);
    result.hidden_smooth.bits = static_cast<uint64_t>(hidden_smooth);
    result.hidden_seam.bits = static_cast<uint64_t>(hidden_seam);
    result.hidden_outline.bits = static_cast<uint64_t>(hidden_outline);
    return result;
}

Ref<OcctlTopoHlrResult> OcctlTopoHlrResult::from_c(const occtl_topo_hlr_result_t& val) {
    Ref<OcctlTopoHlrResult> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->graph = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.graph));
    r->visible_sharp = static_cast<int64_t>(val.visible_sharp.bits);
    r->visible_smooth = static_cast<int64_t>(val.visible_smooth.bits);
    r->visible_seam = static_cast<int64_t>(val.visible_seam.bits);
    r->visible_outline = static_cast<int64_t>(val.visible_outline.bits);
    r->hidden_sharp = static_cast<int64_t>(val.hidden_sharp.bits);
    r->hidden_smooth = static_cast<int64_t>(val.hidden_smooth.bits);
    r->hidden_seam = static_cast<int64_t>(val.hidden_seam.bits);
    r->hidden_outline = static_cast<int64_t>(val.hidden_outline.bits);
    return r;
}

void OcctlTopoHlrResult::copy_from_c(const occtl_topo_hlr_result_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    graph = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.graph));
    visible_sharp = static_cast<int64_t>(val.visible_sharp.bits);
    visible_smooth = static_cast<int64_t>(val.visible_smooth.bits);
    visible_seam = static_cast<int64_t>(val.visible_seam.bits);
    visible_outline = static_cast<int64_t>(val.visible_outline.bits);
    hidden_sharp = static_cast<int64_t>(val.hidden_sharp.bits);
    hidden_smooth = static_cast<int64_t>(val.hidden_smooth.bits);
    hidden_seam = static_cast<int64_t>(val.hidden_seam.bits);
    hidden_outline = static_cast<int64_t>(val.hidden_outline.bits);
}
