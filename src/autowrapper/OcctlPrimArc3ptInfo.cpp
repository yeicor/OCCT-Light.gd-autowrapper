#include "OcctlPrimArc3ptInfo.h"

#include "OcctlPoint3.h"

int OcctlPrimArc3ptInfo::get_struct_version() const { return struct_version; }
void OcctlPrimArc3ptInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimArc3ptInfo::get_p_next() const { return p_next; }
void OcctlPrimArc3ptInfo::set_p_next(int64_t val) { p_next = val; }

Ref<OcctlPoint3> OcctlPrimArc3ptInfo::get_start() const { return start; }
void OcctlPrimArc3ptInfo::set_start(Ref<OcctlPoint3> val) { start = val; }

Ref<OcctlPoint3> OcctlPrimArc3ptInfo::get_via() const { return via; }
void OcctlPrimArc3ptInfo::set_via(Ref<OcctlPoint3> val) { via = val; }

Ref<OcctlPoint3> OcctlPrimArc3ptInfo::get_end() const { return end; }
void OcctlPrimArc3ptInfo::set_end(Ref<OcctlPoint3> val) { end = val; }

void OcctlPrimArc3ptInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimArc3ptInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimArc3ptInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimArc3ptInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimArc3ptInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_start"), &OcctlPrimArc3ptInfo::get_start);
    godot::ClassDB::bind_method(godot::D_METHOD("set_start", "val"), &OcctlPrimArc3ptInfo::set_start);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "start"), "set_start", "get_start");
    godot::ClassDB::bind_method(godot::D_METHOD("get_via"), &OcctlPrimArc3ptInfo::get_via);
    godot::ClassDB::bind_method(godot::D_METHOD("set_via", "val"), &OcctlPrimArc3ptInfo::set_via);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "via"), "set_via", "get_via");
    godot::ClassDB::bind_method(godot::D_METHOD("get_end"), &OcctlPrimArc3ptInfo::get_end);
    godot::ClassDB::bind_method(godot::D_METHOD("set_end", "val"), &OcctlPrimArc3ptInfo::set_end);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "end"), "set_end", "get_end");
}

occtl_prim_arc_3pt_info_t OcctlPrimArc3ptInfo::to_c() const {
    occtl_prim_arc_3pt_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.start = start->to_c();
    result.via = via->to_c();
    result.end = end->to_c();
    return result;
}

Ref<OcctlPrimArc3ptInfo> OcctlPrimArc3ptInfo::from_c(const occtl_prim_arc_3pt_info_t& val) {
    Ref<OcctlPrimArc3ptInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->start = OcctlPoint3::from_c(val.start);
    r->via = OcctlPoint3::from_c(val.via);
    r->end = OcctlPoint3::from_c(val.end);
    return r;
}

void OcctlPrimArc3ptInfo::copy_from_c(const occtl_prim_arc_3pt_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    start = OcctlPoint3::from_c(val.start);
    via = OcctlPoint3::from_c(val.via);
    end = OcctlPoint3::from_c(val.end);
}
