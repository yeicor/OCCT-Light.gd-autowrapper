#ifndef OCCTLIOGLTFWRITEOPTIONS_H
#define OCCTLIOGLTFWRITEOPTIONS_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/vector3.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/transform3d.hpp>
#include <godot_cpp/variant/aabb.hpp>
#include <godot_cpp/variant/color.hpp>
#include <cstdint>
#include <vector>
#include "occtl/occtl_io_gltf.h"


using namespace godot;

class OcctlIoGltfWriteOptions : public godot::RefCounted {
    GDCLASS(OcctlIoGltfWriteOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int transform_format;
    int force_uv_export;
    int embed_textures_in_glb;
    int merge_faces;
    int split_indices_16;
    int parallel;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int get_transform_format() const;
    void set_transform_format(int val);
    int get_force_uv_export() const;
    void set_force_uv_export(int val);
    int get_embed_textures_in_glb() const;
    void set_embed_textures_in_glb(int val);
    int get_merge_faces() const;
    void set_merge_faces(int val);
    int get_split_indices_16() const;
    void set_split_indices_16(int val);
    int get_parallel() const;
    void set_parallel(int val);

    occtl_io_gltf_write_options_t to_c() const;
    static Ref<OcctlIoGltfWriteOptions> from_c(const occtl_io_gltf_write_options_t& val);
    void copy_from_c(const occtl_io_gltf_write_options_t& val);
};

#endif // OCCTLIOGLTFWRITEOPTIONS_H
