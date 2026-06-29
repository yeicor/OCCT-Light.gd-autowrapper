#include "OcctlTopoExtrudeFacesOptions.h"

#include "OcctlDirection3.h"

int OcctlTopoExtrudeFacesOptions::get_struct_version() const { return struct_version; }
void OcctlTopoExtrudeFacesOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoExtrudeFacesOptions::get_p_next() const { return p_next; }
void OcctlTopoExtrudeFacesOptions::set_p_next(int64_t val) { p_next = val; }

PackedInt64Array OcctlTopoExtrudeFacesOptions::get_faces() const { return faces; }
void OcctlTopoExtrudeFacesOptions::set_faces(PackedInt64Array val) { faces = val; }

int OcctlTopoExtrudeFacesOptions::get_face_count() const { return face_count; }
void OcctlTopoExtrudeFacesOptions::set_face_count(int val) { face_count = val; }

double OcctlTopoExtrudeFacesOptions::get_thickness() const { return thickness; }
void OcctlTopoExtrudeFacesOptions::set_thickness(double val) { thickness = val; }

int OcctlTopoExtrudeFacesOptions::get_both_sides() const { return both_sides; }
void OcctlTopoExtrudeFacesOptions::set_both_sides(int val) { both_sides = val; }

int OcctlTopoExtrudeFacesOptions::get_use_normal() const { return use_normal; }
void OcctlTopoExtrudeFacesOptions::set_use_normal(int val) { use_normal = val; }

Ref<OcctlDirection3> OcctlTopoExtrudeFacesOptions::get_normal() const { return normal; }
void OcctlTopoExtrudeFacesOptions::set_normal(Ref<OcctlDirection3> val) { normal = val; }

int OcctlTopoExtrudeFacesOptions::get_copy() const { return copy; }
void OcctlTopoExtrudeFacesOptions::set_copy(int val) { copy = val; }

int OcctlTopoExtrudeFacesOptions::get_canonize() const { return canonize; }
void OcctlTopoExtrudeFacesOptions::set_canonize(int val) { canonize = val; }

void OcctlTopoExtrudeFacesOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoExtrudeFacesOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoExtrudeFacesOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoExtrudeFacesOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoExtrudeFacesOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_faces"), &OcctlTopoExtrudeFacesOptions::get_faces);
    godot::ClassDB::bind_method(godot::D_METHOD("set_faces", "val"), &OcctlTopoExtrudeFacesOptions::set_faces);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "faces"), "set_faces", "get_faces");
    godot::ClassDB::bind_method(godot::D_METHOD("get_face_count"), &OcctlTopoExtrudeFacesOptions::get_face_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_face_count", "val"), &OcctlTopoExtrudeFacesOptions::set_face_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "face_count"), "set_face_count", "get_face_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_thickness"), &OcctlTopoExtrudeFacesOptions::get_thickness);
    godot::ClassDB::bind_method(godot::D_METHOD("set_thickness", "val"), &OcctlTopoExtrudeFacesOptions::set_thickness);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "thickness"), "set_thickness", "get_thickness");
    godot::ClassDB::bind_method(godot::D_METHOD("get_both_sides"), &OcctlTopoExtrudeFacesOptions::get_both_sides);
    godot::ClassDB::bind_method(godot::D_METHOD("set_both_sides", "val"), &OcctlTopoExtrudeFacesOptions::set_both_sides);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "both_sides"), "set_both_sides", "get_both_sides");
    godot::ClassDB::bind_method(godot::D_METHOD("get_use_normal"), &OcctlTopoExtrudeFacesOptions::get_use_normal);
    godot::ClassDB::bind_method(godot::D_METHOD("set_use_normal", "val"), &OcctlTopoExtrudeFacesOptions::set_use_normal);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "use_normal"), "set_use_normal", "get_use_normal");
    godot::ClassDB::bind_method(godot::D_METHOD("get_normal"), &OcctlTopoExtrudeFacesOptions::get_normal);
    godot::ClassDB::bind_method(godot::D_METHOD("set_normal", "val"), &OcctlTopoExtrudeFacesOptions::set_normal);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "normal"), "set_normal", "get_normal");
    godot::ClassDB::bind_method(godot::D_METHOD("get_copy"), &OcctlTopoExtrudeFacesOptions::get_copy);
    godot::ClassDB::bind_method(godot::D_METHOD("set_copy", "val"), &OcctlTopoExtrudeFacesOptions::set_copy);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "copy"), "set_copy", "get_copy");
    godot::ClassDB::bind_method(godot::D_METHOD("get_canonize"), &OcctlTopoExtrudeFacesOptions::get_canonize);
    godot::ClassDB::bind_method(godot::D_METHOD("set_canonize", "val"), &OcctlTopoExtrudeFacesOptions::set_canonize);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "canonize"), "set_canonize", "get_canonize");
}

occtl_topo_extrude_faces_options_t OcctlTopoExtrudeFacesOptions::to_c() const {
    occtl_topo_extrude_faces_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.faces = reinterpret_cast<const occtl_node_id_t*>(faces.ptr());
    result.face_count = face_count;
    result.thickness = thickness;
    result.both_sides = both_sides;
    result.use_normal = use_normal;
    result.normal = normal->to_c();
    result.copy = copy;
    result.canonize = canonize;
    return result;
}

Ref<OcctlTopoExtrudeFacesOptions> OcctlTopoExtrudeFacesOptions::from_c(const occtl_topo_extrude_faces_options_t& val) {
    Ref<OcctlTopoExtrudeFacesOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field faces is not populated from C
    r->face_count = val.face_count;
    r->thickness = val.thickness;
    r->both_sides = val.both_sides;
    r->use_normal = val.use_normal;
    r->normal = OcctlDirection3::from_c(val.normal);
    r->copy = val.copy;
    r->canonize = val.canonize;
    return r;
}

void OcctlTopoExtrudeFacesOptions::copy_from_c(const occtl_topo_extrude_faces_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field faces is not populated from C
    face_count = val.face_count;
    thickness = val.thickness;
    both_sides = val.both_sides;
    use_normal = val.use_normal;
    normal = OcctlDirection3::from_c(val.normal);
    copy = val.copy;
    canonize = val.canonize;
}
