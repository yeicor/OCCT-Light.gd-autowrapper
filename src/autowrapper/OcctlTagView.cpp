#include "OcctlTagView.h"


String OcctlTagView::get_tag() const { return tag; }
void OcctlTagView::set_tag(String val) { tag = val; }

int OcctlTagView::get_tag_len() const { return tag_len; }
void OcctlTagView::set_tag_len(int val) { tag_len = val; }

void OcctlTagView::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_tag"), &OcctlTagView::get_tag);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tag", "val"), &OcctlTagView::set_tag);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "tag"), "set_tag", "get_tag");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tag_len"), &OcctlTagView::get_tag_len);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tag_len", "val"), &OcctlTagView::set_tag_len);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "tag_len"), "set_tag_len", "get_tag_len");
}

occtl_tag_view_t OcctlTagView::to_c() const {
    occtl_tag_view_t result = {};
    // const pointer field tag: not convertible (type String)
    result.tag_len = tag_len;
    return result;
}

Ref<OcctlTagView> OcctlTagView::from_c(const occtl_tag_view_t& val) {
    Ref<OcctlTagView> r;
    r.instantiate();
    if (val.tag) r->tag = String(val.tag);
    r->tag_len = val.tag_len;
    return r;
}

void OcctlTagView::copy_from_c(const occtl_tag_view_t& val) {
    if (val.tag) tag = String(val.tag);
    tag_len = val.tag_len;
}
