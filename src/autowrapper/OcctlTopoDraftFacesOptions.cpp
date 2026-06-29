#include "OcctlTopoDraftFacesOptions.h"

#include "OcctlNodeId.h"
#include "OcctlDirection3.h"
#include "OcctlPoint3.h"

int OcctlTopoDraftFacesOptions::get_struct_version() const { return struct_version; }
void OcctlTopoDraftFacesOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoDraftFacesOptions::get_p_next() const { return p_next; }
void OcctlTopoDraftFacesOptions::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlTopoDraftFacesOptions::get_root() const { return root; }
void OcctlTopoDraftFacesOptions::set_root(int64_t val) { root = val; }

PackedInt64Array OcctlTopoDraftFacesOptions::get_faces() const { return faces; }
void OcctlTopoDraftFacesOptions::set_faces(PackedInt64Array val) { faces = val; }

int OcctlTopoDraftFacesOptions::get_face_count() const { return face_count; }
void OcctlTopoDraftFacesOptions::set_face_count(int val) { face_count = val; }

Ref<OcctlDirection3> OcctlTopoDraftFacesOptions::get_pull_direction() const { return pull_direction; }
void OcctlTopoDraftFacesOptions::set_pull_direction(Ref<OcctlDirection3> val) { pull_direction = val; }

Ref<OcctlPoint3> OcctlTopoDraftFacesOptions::get_neutral_point() const { return neutral_point; }
void OcctlTopoDraftFacesOptions::set_neutral_point(Ref<OcctlPoint3> val) { neutral_point = val; }

Ref<OcctlDirection3> OcctlTopoDraftFacesOptions::get_neutral_normal() const { return neutral_normal; }
void OcctlTopoDraftFacesOptions::set_neutral_normal(Ref<OcctlDirection3> val) { neutral_normal = val; }

double OcctlTopoDraftFacesOptions::get_angle() const { return angle; }
void OcctlTopoDraftFacesOptions::set_angle(double val) { angle = val; }

int OcctlTopoDraftFacesOptions::get_keep_inside() const { return keep_inside; }
void OcctlTopoDraftFacesOptions::set_keep_inside(int val) { keep_inside = val; }

void OcctlTopoDraftFacesOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoDraftFacesOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoDraftFacesOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoDraftFacesOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoDraftFacesOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_root"), &OcctlTopoDraftFacesOptions::get_root);
    godot::ClassDB::bind_method(godot::D_METHOD("set_root", "val"), &OcctlTopoDraftFacesOptions::set_root);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "root"), "set_root", "get_root");
    godot::ClassDB::bind_method(godot::D_METHOD("get_faces"), &OcctlTopoDraftFacesOptions::get_faces);
    godot::ClassDB::bind_method(godot::D_METHOD("set_faces", "val"), &OcctlTopoDraftFacesOptions::set_faces);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "faces"), "set_faces", "get_faces");
    godot::ClassDB::bind_method(godot::D_METHOD("get_face_count"), &OcctlTopoDraftFacesOptions::get_face_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_face_count", "val"), &OcctlTopoDraftFacesOptions::set_face_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "face_count"), "set_face_count", "get_face_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_pull_direction"), &OcctlTopoDraftFacesOptions::get_pull_direction);
    godot::ClassDB::bind_method(godot::D_METHOD("set_pull_direction", "val"), &OcctlTopoDraftFacesOptions::set_pull_direction);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "pull_direction"), "set_pull_direction", "get_pull_direction");
    godot::ClassDB::bind_method(godot::D_METHOD("get_neutral_point"), &OcctlTopoDraftFacesOptions::get_neutral_point);
    godot::ClassDB::bind_method(godot::D_METHOD("set_neutral_point", "val"), &OcctlTopoDraftFacesOptions::set_neutral_point);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "neutral_point"), "set_neutral_point", "get_neutral_point");
    godot::ClassDB::bind_method(godot::D_METHOD("get_neutral_normal"), &OcctlTopoDraftFacesOptions::get_neutral_normal);
    godot::ClassDB::bind_method(godot::D_METHOD("set_neutral_normal", "val"), &OcctlTopoDraftFacesOptions::set_neutral_normal);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "neutral_normal"), "set_neutral_normal", "get_neutral_normal");
    godot::ClassDB::bind_method(godot::D_METHOD("get_angle"), &OcctlTopoDraftFacesOptions::get_angle);
    godot::ClassDB::bind_method(godot::D_METHOD("set_angle", "val"), &OcctlTopoDraftFacesOptions::set_angle);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "angle"), "set_angle", "get_angle");
    godot::ClassDB::bind_method(godot::D_METHOD("get_keep_inside"), &OcctlTopoDraftFacesOptions::get_keep_inside);
    godot::ClassDB::bind_method(godot::D_METHOD("set_keep_inside", "val"), &OcctlTopoDraftFacesOptions::set_keep_inside);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "keep_inside"), "set_keep_inside", "get_keep_inside");
}

occtl_topo_draft_faces_options_t OcctlTopoDraftFacesOptions::to_c() const {
    occtl_topo_draft_faces_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.root.bits = static_cast<uint64_t>(root);
    result.faces = reinterpret_cast<const occtl_node_id_t*>(faces.ptr());
    result.face_count = face_count;
    result.pull_direction = pull_direction->to_c();
    result.neutral_point = neutral_point->to_c();
    result.neutral_normal = neutral_normal->to_c();
    result.angle = angle;
    result.keep_inside = keep_inside;
    return result;
}

Ref<OcctlTopoDraftFacesOptions> OcctlTopoDraftFacesOptions::from_c(const occtl_topo_draft_faces_options_t& val) {
    Ref<OcctlTopoDraftFacesOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->root = static_cast<int64_t>(val.root.bits);
    // array field faces is not populated from C
    r->face_count = val.face_count;
    r->pull_direction = OcctlDirection3::from_c(val.pull_direction);
    r->neutral_point = OcctlPoint3::from_c(val.neutral_point);
    r->neutral_normal = OcctlDirection3::from_c(val.neutral_normal);
    r->angle = val.angle;
    r->keep_inside = val.keep_inside;
    return r;
}

void OcctlTopoDraftFacesOptions::copy_from_c(const occtl_topo_draft_faces_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    root = static_cast<int64_t>(val.root.bits);
    // array field faces is not populated from C
    face_count = val.face_count;
    pull_direction = OcctlDirection3::from_c(val.pull_direction);
    neutral_point = OcctlPoint3::from_c(val.neutral_point);
    neutral_normal = OcctlDirection3::from_c(val.neutral_normal);
    angle = val.angle;
    keep_inside = val.keep_inside;
}
