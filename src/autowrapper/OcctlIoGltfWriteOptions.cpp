#include "OcctlIoGltfWriteOptions.h"


int OcctlIoGltfWriteOptions::get_struct_version() const { return struct_version; }
void OcctlIoGltfWriteOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlIoGltfWriteOptions::get_p_next() const { return p_next; }
void OcctlIoGltfWriteOptions::set_p_next(int64_t val) { p_next = val; }

int OcctlIoGltfWriteOptions::get_transform_format() const { return transform_format; }
void OcctlIoGltfWriteOptions::set_transform_format(int val) { transform_format = val; }

int OcctlIoGltfWriteOptions::get_force_uv_export() const { return force_uv_export; }
void OcctlIoGltfWriteOptions::set_force_uv_export(int val) { force_uv_export = val; }

int OcctlIoGltfWriteOptions::get_embed_textures_in_glb() const { return embed_textures_in_glb; }
void OcctlIoGltfWriteOptions::set_embed_textures_in_glb(int val) { embed_textures_in_glb = val; }

int OcctlIoGltfWriteOptions::get_merge_faces() const { return merge_faces; }
void OcctlIoGltfWriteOptions::set_merge_faces(int val) { merge_faces = val; }

int OcctlIoGltfWriteOptions::get_split_indices_16() const { return split_indices_16; }
void OcctlIoGltfWriteOptions::set_split_indices_16(int val) { split_indices_16 = val; }

int OcctlIoGltfWriteOptions::get_parallel() const { return parallel; }
void OcctlIoGltfWriteOptions::set_parallel(int val) { parallel = val; }

void OcctlIoGltfWriteOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlIoGltfWriteOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlIoGltfWriteOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlIoGltfWriteOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlIoGltfWriteOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_transform_format"), &OcctlIoGltfWriteOptions::get_transform_format);
    godot::ClassDB::bind_method(godot::D_METHOD("set_transform_format", "val"), &OcctlIoGltfWriteOptions::set_transform_format);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "transform_format"), "set_transform_format", "get_transform_format");
    godot::ClassDB::bind_method(godot::D_METHOD("get_force_uv_export"), &OcctlIoGltfWriteOptions::get_force_uv_export);
    godot::ClassDB::bind_method(godot::D_METHOD("set_force_uv_export", "val"), &OcctlIoGltfWriteOptions::set_force_uv_export);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "force_uv_export"), "set_force_uv_export", "get_force_uv_export");
    godot::ClassDB::bind_method(godot::D_METHOD("get_embed_textures_in_glb"), &OcctlIoGltfWriteOptions::get_embed_textures_in_glb);
    godot::ClassDB::bind_method(godot::D_METHOD("set_embed_textures_in_glb", "val"), &OcctlIoGltfWriteOptions::set_embed_textures_in_glb);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "embed_textures_in_glb"), "set_embed_textures_in_glb", "get_embed_textures_in_glb");
    godot::ClassDB::bind_method(godot::D_METHOD("get_merge_faces"), &OcctlIoGltfWriteOptions::get_merge_faces);
    godot::ClassDB::bind_method(godot::D_METHOD("set_merge_faces", "val"), &OcctlIoGltfWriteOptions::set_merge_faces);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "merge_faces"), "set_merge_faces", "get_merge_faces");
    godot::ClassDB::bind_method(godot::D_METHOD("get_split_indices_16"), &OcctlIoGltfWriteOptions::get_split_indices_16);
    godot::ClassDB::bind_method(godot::D_METHOD("set_split_indices_16", "val"), &OcctlIoGltfWriteOptions::set_split_indices_16);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "split_indices_16"), "set_split_indices_16", "get_split_indices_16");
    godot::ClassDB::bind_method(godot::D_METHOD("get_parallel"), &OcctlIoGltfWriteOptions::get_parallel);
    godot::ClassDB::bind_method(godot::D_METHOD("set_parallel", "val"), &OcctlIoGltfWriteOptions::set_parallel);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "parallel"), "set_parallel", "get_parallel");
}

occtl_io_gltf_write_options_t OcctlIoGltfWriteOptions::to_c() const {
    occtl_io_gltf_write_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.transform_format = static_cast<occtl_io_gltf_transform_format_t>(transform_format);
    result.force_uv_export = force_uv_export;
    result.embed_textures_in_glb = embed_textures_in_glb;
    result.merge_faces = merge_faces;
    result.split_indices_16 = split_indices_16;
    result.parallel = parallel;
    return result;
}

Ref<OcctlIoGltfWriteOptions> OcctlIoGltfWriteOptions::from_c(const occtl_io_gltf_write_options_t& val) {
    Ref<OcctlIoGltfWriteOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->transform_format = static_cast<int>(val.transform_format);
    r->force_uv_export = val.force_uv_export;
    r->embed_textures_in_glb = val.embed_textures_in_glb;
    r->merge_faces = val.merge_faces;
    r->split_indices_16 = val.split_indices_16;
    r->parallel = val.parallel;
    return r;
}

void OcctlIoGltfWriteOptions::copy_from_c(const occtl_io_gltf_write_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    transform_format = static_cast<int>(val.transform_format);
    force_uv_export = val.force_uv_export;
    embed_textures_in_glb = val.embed_textures_in_glb;
    merge_faces = val.merge_faces;
    split_indices_16 = val.split_indices_16;
    parallel = val.parallel;
}
