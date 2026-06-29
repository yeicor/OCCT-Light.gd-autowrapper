#include "OcctlSelectGroupView.h"

#include "OcctlColorRgba.h"

int OcctlSelectGroupView::get_struct_version() const { return struct_version; }
void OcctlSelectGroupView::set_struct_version(int val) { struct_version = val; }

int64_t OcctlSelectGroupView::get_p_next() const { return p_next; }
void OcctlSelectGroupView::set_p_next(int64_t val) { p_next = val; }

int OcctlSelectGroupView::get_key() const { return key; }
void OcctlSelectGroupView::set_key(int val) { key = val; }

int OcctlSelectGroupView::get_node_kind() const { return node_kind; }
void OcctlSelectGroupView::set_node_kind(int val) { node_kind = val; }

int OcctlSelectGroupView::get_curve_kind() const { return curve_kind; }
void OcctlSelectGroupView::set_curve_kind(int val) { curve_kind = val; }

int OcctlSelectGroupView::get_surface_kind() const { return surface_kind; }
void OcctlSelectGroupView::set_surface_kind(int val) { surface_kind = val; }

double OcctlSelectGroupView::get_numeric_key() const { return numeric_key; }
void OcctlSelectGroupView::set_numeric_key(double val) { numeric_key = val; }

String OcctlSelectGroupView::get_name() const { return name; }
void OcctlSelectGroupView::set_name(String val) { name = val; }

int OcctlSelectGroupView::get_name_len() const { return name_len; }
void OcctlSelectGroupView::set_name_len(int val) { name_len = val; }

int OcctlSelectGroupView::get_has_color() const { return has_color; }
void OcctlSelectGroupView::set_has_color(int val) { has_color = val; }

Ref<OcctlColorRgba> OcctlSelectGroupView::get_color() const { return color; }
void OcctlSelectGroupView::set_color(Ref<OcctlColorRgba> val) { color = val; }

PackedInt64Array OcctlSelectGroupView::get_nodes() const { return nodes; }
void OcctlSelectGroupView::set_nodes(PackedInt64Array val) { nodes = val; }

int OcctlSelectGroupView::get_node_count() const { return node_count; }
void OcctlSelectGroupView::set_node_count(int val) { node_count = val; }

void OcctlSelectGroupView::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlSelectGroupView::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlSelectGroupView::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlSelectGroupView::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlSelectGroupView::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_key"), &OcctlSelectGroupView::get_key);
    godot::ClassDB::bind_method(godot::D_METHOD("set_key", "val"), &OcctlSelectGroupView::set_key);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "key"), "set_key", "get_key");
    godot::ClassDB::bind_method(godot::D_METHOD("get_node_kind"), &OcctlSelectGroupView::get_node_kind);
    godot::ClassDB::bind_method(godot::D_METHOD("set_node_kind", "val"), &OcctlSelectGroupView::set_node_kind);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "node_kind"), "set_node_kind", "get_node_kind");
    godot::ClassDB::bind_method(godot::D_METHOD("get_curve_kind"), &OcctlSelectGroupView::get_curve_kind);
    godot::ClassDB::bind_method(godot::D_METHOD("set_curve_kind", "val"), &OcctlSelectGroupView::set_curve_kind);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "curve_kind"), "set_curve_kind", "get_curve_kind");
    godot::ClassDB::bind_method(godot::D_METHOD("get_surface_kind"), &OcctlSelectGroupView::get_surface_kind);
    godot::ClassDB::bind_method(godot::D_METHOD("set_surface_kind", "val"), &OcctlSelectGroupView::set_surface_kind);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "surface_kind"), "set_surface_kind", "get_surface_kind");
    godot::ClassDB::bind_method(godot::D_METHOD("get_numeric_key"), &OcctlSelectGroupView::get_numeric_key);
    godot::ClassDB::bind_method(godot::D_METHOD("set_numeric_key", "val"), &OcctlSelectGroupView::set_numeric_key);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "numeric_key"), "set_numeric_key", "get_numeric_key");
    godot::ClassDB::bind_method(godot::D_METHOD("get_name"), &OcctlSelectGroupView::get_name);
    godot::ClassDB::bind_method(godot::D_METHOD("set_name", "val"), &OcctlSelectGroupView::set_name);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "name"), "set_name", "get_name");
    godot::ClassDB::bind_method(godot::D_METHOD("get_name_len"), &OcctlSelectGroupView::get_name_len);
    godot::ClassDB::bind_method(godot::D_METHOD("set_name_len", "val"), &OcctlSelectGroupView::set_name_len);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "name_len"), "set_name_len", "get_name_len");
    godot::ClassDB::bind_method(godot::D_METHOD("get_has_color"), &OcctlSelectGroupView::get_has_color);
    godot::ClassDB::bind_method(godot::D_METHOD("set_has_color", "val"), &OcctlSelectGroupView::set_has_color);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "has_color"), "set_has_color", "get_has_color");
    godot::ClassDB::bind_method(godot::D_METHOD("get_color"), &OcctlSelectGroupView::get_color);
    godot::ClassDB::bind_method(godot::D_METHOD("set_color", "val"), &OcctlSelectGroupView::set_color);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "color"), "set_color", "get_color");
    godot::ClassDB::bind_method(godot::D_METHOD("get_nodes"), &OcctlSelectGroupView::get_nodes);
    godot::ClassDB::bind_method(godot::D_METHOD("set_nodes", "val"), &OcctlSelectGroupView::set_nodes);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "nodes"), "set_nodes", "get_nodes");
    godot::ClassDB::bind_method(godot::D_METHOD("get_node_count"), &OcctlSelectGroupView::get_node_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_node_count", "val"), &OcctlSelectGroupView::set_node_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "node_count"), "set_node_count", "get_node_count");
}

occtl_select_group_view_t OcctlSelectGroupView::to_c() const {
    occtl_select_group_view_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.key = static_cast<occtl_select_group_key_t>(key);
    result.node_kind = static_cast<occtl_node_kind_t>(node_kind);
    result.curve_kind = static_cast<occtl_curve_kind_t>(curve_kind);
    result.surface_kind = static_cast<occtl_surface_kind_t>(surface_kind);
    result.numeric_key = numeric_key;
    // const pointer field name: not convertible (type String)
    result.name_len = name_len;
    result.has_color = has_color;
    result.color = color->to_c();
    result.nodes = reinterpret_cast<const occtl_node_id_t*>(nodes.ptr());
    result.node_count = node_count;
    return result;
}

Ref<OcctlSelectGroupView> OcctlSelectGroupView::from_c(const occtl_select_group_view_t& val) {
    Ref<OcctlSelectGroupView> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->key = static_cast<int>(val.key);
    r->node_kind = static_cast<int>(val.node_kind);
    r->curve_kind = static_cast<int>(val.curve_kind);
    r->surface_kind = static_cast<int>(val.surface_kind);
    r->numeric_key = val.numeric_key;
    if (val.name) r->name = String(val.name);
    r->name_len = val.name_len;
    r->has_color = val.has_color;
    r->color = OcctlColorRgba::from_c(val.color);
    // array field nodes is not populated from C
    r->node_count = val.node_count;
    return r;
}

void OcctlSelectGroupView::copy_from_c(const occtl_select_group_view_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    key = static_cast<int>(val.key);
    node_kind = static_cast<int>(val.node_kind);
    curve_kind = static_cast<int>(val.curve_kind);
    surface_kind = static_cast<int>(val.surface_kind);
    numeric_key = val.numeric_key;
    if (val.name) name = String(val.name);
    name_len = val.name_len;
    has_color = val.has_color;
    color = OcctlColorRgba::from_c(val.color);
    // array field nodes is not populated from C
    node_count = val.node_count;
}
