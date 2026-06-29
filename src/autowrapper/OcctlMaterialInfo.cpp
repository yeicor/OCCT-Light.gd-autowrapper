#include "OcctlMaterialInfo.h"

#include "OcctlColorRgba.h"
#include "OcctlUid.h"

int OcctlMaterialInfo::get_struct_version() const { return struct_version; }
void OcctlMaterialInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlMaterialInfo::get_p_next() const { return p_next; }
void OcctlMaterialInfo::set_p_next(int64_t val) { p_next = val; }

String OcctlMaterialInfo::get_name() const { return name; }
void OcctlMaterialInfo::set_name(String val) { name = val; }

int OcctlMaterialInfo::get_name_len() const { return name_len; }
void OcctlMaterialInfo::set_name_len(int val) { name_len = val; }

int OcctlMaterialInfo::get_has_density() const { return has_density; }
void OcctlMaterialInfo::set_has_density(int val) { has_density = val; }

double OcctlMaterialInfo::get_density() const { return density; }
void OcctlMaterialInfo::set_density(double val) { density = val; }

int OcctlMaterialInfo::get_has_diffuse_color() const { return has_diffuse_color; }
void OcctlMaterialInfo::set_has_diffuse_color(int val) { has_diffuse_color = val; }

Ref<OcctlColorRgba> OcctlMaterialInfo::get_diffuse_color() const { return diffuse_color; }
void OcctlMaterialInfo::set_diffuse_color(Ref<OcctlColorRgba> val) { diffuse_color = val; }

int64_t OcctlMaterialInfo::get_metadata_uid() const { return metadata_uid; }
void OcctlMaterialInfo::set_metadata_uid(int64_t val) { metadata_uid = val; }

void OcctlMaterialInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlMaterialInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlMaterialInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlMaterialInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlMaterialInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_name"), &OcctlMaterialInfo::get_name);
    godot::ClassDB::bind_method(godot::D_METHOD("set_name", "val"), &OcctlMaterialInfo::set_name);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "name"), "set_name", "get_name");
    godot::ClassDB::bind_method(godot::D_METHOD("get_name_len"), &OcctlMaterialInfo::get_name_len);
    godot::ClassDB::bind_method(godot::D_METHOD("set_name_len", "val"), &OcctlMaterialInfo::set_name_len);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "name_len"), "set_name_len", "get_name_len");
    godot::ClassDB::bind_method(godot::D_METHOD("get_has_density"), &OcctlMaterialInfo::get_has_density);
    godot::ClassDB::bind_method(godot::D_METHOD("set_has_density", "val"), &OcctlMaterialInfo::set_has_density);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "has_density"), "set_has_density", "get_has_density");
    godot::ClassDB::bind_method(godot::D_METHOD("get_density"), &OcctlMaterialInfo::get_density);
    godot::ClassDB::bind_method(godot::D_METHOD("set_density", "val"), &OcctlMaterialInfo::set_density);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "density"), "set_density", "get_density");
    godot::ClassDB::bind_method(godot::D_METHOD("get_has_diffuse_color"), &OcctlMaterialInfo::get_has_diffuse_color);
    godot::ClassDB::bind_method(godot::D_METHOD("set_has_diffuse_color", "val"), &OcctlMaterialInfo::set_has_diffuse_color);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "has_diffuse_color"), "set_has_diffuse_color", "get_has_diffuse_color");
    godot::ClassDB::bind_method(godot::D_METHOD("get_diffuse_color"), &OcctlMaterialInfo::get_diffuse_color);
    godot::ClassDB::bind_method(godot::D_METHOD("set_diffuse_color", "val"), &OcctlMaterialInfo::set_diffuse_color);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "diffuse_color"), "set_diffuse_color", "get_diffuse_color");
    godot::ClassDB::bind_method(godot::D_METHOD("get_metadata_uid"), &OcctlMaterialInfo::get_metadata_uid);
    godot::ClassDB::bind_method(godot::D_METHOD("set_metadata_uid", "val"), &OcctlMaterialInfo::set_metadata_uid);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "metadata_uid"), "set_metadata_uid", "get_metadata_uid");
}

occtl_material_info_t OcctlMaterialInfo::to_c() const {
    occtl_material_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    // const pointer field name: not convertible (type String)
    result.name_len = name_len;
    result.has_density = has_density;
    result.density = density;
    result.has_diffuse_color = has_diffuse_color;
    result.diffuse_color = diffuse_color->to_c();
    result.metadata_uid.bits = static_cast<uint64_t>(metadata_uid);
    return result;
}

Ref<OcctlMaterialInfo> OcctlMaterialInfo::from_c(const occtl_material_info_t& val) {
    Ref<OcctlMaterialInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    if (val.name) r->name = String(val.name);
    r->name_len = val.name_len;
    r->has_density = val.has_density;
    r->density = val.density;
    r->has_diffuse_color = val.has_diffuse_color;
    r->diffuse_color = OcctlColorRgba::from_c(val.diffuse_color);
    r->metadata_uid = static_cast<int64_t>(val.metadata_uid.bits);
    return r;
}

void OcctlMaterialInfo::copy_from_c(const occtl_material_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    if (val.name) name = String(val.name);
    name_len = val.name_len;
    has_density = val.has_density;
    density = val.density;
    has_diffuse_color = val.has_diffuse_color;
    diffuse_color = OcctlColorRgba::from_c(val.diffuse_color);
    metadata_uid = static_cast<int64_t>(val.metadata_uid.bits);
}
