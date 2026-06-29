#include "OcctlPrimTraceInfo.h"

#include "OcctlNodeId.h"
#include "OcctlDirection3.h"

int OcctlPrimTraceInfo::get_struct_version() const { return struct_version; }
void OcctlPrimTraceInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimTraceInfo::get_p_next() const { return p_next; }
void OcctlPrimTraceInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlPrimTraceInfo::get_path() const { return path; }
void OcctlPrimTraceInfo::set_path(int64_t val) { path = val; }

double OcctlPrimTraceInfo::get_width() const { return width; }
void OcctlPrimTraceInfo::set_width(double val) { width = val; }

Ref<OcctlDirection3> OcctlPrimTraceInfo::get_normal() const { return normal; }
void OcctlPrimTraceInfo::set_normal(Ref<OcctlDirection3> val) { normal = val; }

int OcctlPrimTraceInfo::get_join() const { return join; }
void OcctlPrimTraceInfo::set_join(int val) { join = val; }

int OcctlPrimTraceInfo::get_approximate() const { return approximate; }
void OcctlPrimTraceInfo::set_approximate(int val) { approximate = val; }

void OcctlPrimTraceInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimTraceInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimTraceInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimTraceInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimTraceInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_path"), &OcctlPrimTraceInfo::get_path);
    godot::ClassDB::bind_method(godot::D_METHOD("set_path", "val"), &OcctlPrimTraceInfo::set_path);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "path"), "set_path", "get_path");
    godot::ClassDB::bind_method(godot::D_METHOD("get_width"), &OcctlPrimTraceInfo::get_width);
    godot::ClassDB::bind_method(godot::D_METHOD("set_width", "val"), &OcctlPrimTraceInfo::set_width);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "width"), "set_width", "get_width");
    godot::ClassDB::bind_method(godot::D_METHOD("get_normal"), &OcctlPrimTraceInfo::get_normal);
    godot::ClassDB::bind_method(godot::D_METHOD("set_normal", "val"), &OcctlPrimTraceInfo::set_normal);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "normal"), "set_normal", "get_normal");
    godot::ClassDB::bind_method(godot::D_METHOD("get_join"), &OcctlPrimTraceInfo::get_join);
    godot::ClassDB::bind_method(godot::D_METHOD("set_join", "val"), &OcctlPrimTraceInfo::set_join);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "join"), "set_join", "get_join");
    godot::ClassDB::bind_method(godot::D_METHOD("get_approximate"), &OcctlPrimTraceInfo::get_approximate);
    godot::ClassDB::bind_method(godot::D_METHOD("set_approximate", "val"), &OcctlPrimTraceInfo::set_approximate);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "approximate"), "set_approximate", "get_approximate");
}

occtl_prim_trace_info_t OcctlPrimTraceInfo::to_c() const {
    occtl_prim_trace_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.path.bits = static_cast<uint64_t>(path);
    result.width = width;
    result.normal = normal->to_c();
    result.join = static_cast<occtl_topo_wire_offset_2d_join_t>(join);
    result.approximate = approximate;
    return result;
}

Ref<OcctlPrimTraceInfo> OcctlPrimTraceInfo::from_c(const occtl_prim_trace_info_t& val) {
    Ref<OcctlPrimTraceInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->path = static_cast<int64_t>(val.path.bits);
    r->width = val.width;
    r->normal = OcctlDirection3::from_c(val.normal);
    r->join = static_cast<int>(val.join);
    r->approximate = val.approximate;
    return r;
}

void OcctlPrimTraceInfo::copy_from_c(const occtl_prim_trace_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    path = static_cast<int64_t>(val.path.bits);
    width = val.width;
    normal = OcctlDirection3::from_c(val.normal);
    join = static_cast<int>(val.join);
    approximate = val.approximate;
}
