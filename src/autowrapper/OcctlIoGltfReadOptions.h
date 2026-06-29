#ifndef OCCTLIOGLTFREADOPTIONS_H
#define OCCTLIOGLTFREADOPTIONS_H

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

class OcctlIoGltfReadOptions : public godot::RefCounted {
    GDCLASS(OcctlIoGltfReadOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int load_all_scenes;
    int skip_empty_nodes;
    int use_mesh_name_as_fallback;
    int apply_scale;
    int parallel;
    int single_precision;
    int fill_incomplete;
    int memory_limit_mib;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int get_load_all_scenes() const;
    void set_load_all_scenes(int val);
    int get_skip_empty_nodes() const;
    void set_skip_empty_nodes(int val);
    int get_use_mesh_name_as_fallback() const;
    void set_use_mesh_name_as_fallback(int val);
    int get_apply_scale() const;
    void set_apply_scale(int val);
    int get_parallel() const;
    void set_parallel(int val);
    int get_single_precision() const;
    void set_single_precision(int val);
    int get_fill_incomplete() const;
    void set_fill_incomplete(int val);
    int get_memory_limit_mib() const;
    void set_memory_limit_mib(int val);

    occtl_io_gltf_read_options_t to_c() const;
    static Ref<OcctlIoGltfReadOptions> from_c(const occtl_io_gltf_read_options_t& val);
    void copy_from_c(const occtl_io_gltf_read_options_t& val);
};

#endif // OCCTLIOGLTFREADOPTIONS_H
