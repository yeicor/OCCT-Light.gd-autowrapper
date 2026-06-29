#include "OcctlIoGltfReadOptions.h"


int OcctlIoGltfReadOptions::get_struct_version() const { return struct_version; }
void OcctlIoGltfReadOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlIoGltfReadOptions::get_p_next() const { return p_next; }
void OcctlIoGltfReadOptions::set_p_next(int64_t val) { p_next = val; }

int OcctlIoGltfReadOptions::get_load_all_scenes() const { return load_all_scenes; }
void OcctlIoGltfReadOptions::set_load_all_scenes(int val) { load_all_scenes = val; }

int OcctlIoGltfReadOptions::get_skip_empty_nodes() const { return skip_empty_nodes; }
void OcctlIoGltfReadOptions::set_skip_empty_nodes(int val) { skip_empty_nodes = val; }

int OcctlIoGltfReadOptions::get_use_mesh_name_as_fallback() const { return use_mesh_name_as_fallback; }
void OcctlIoGltfReadOptions::set_use_mesh_name_as_fallback(int val) { use_mesh_name_as_fallback = val; }

int OcctlIoGltfReadOptions::get_apply_scale() const { return apply_scale; }
void OcctlIoGltfReadOptions::set_apply_scale(int val) { apply_scale = val; }

int OcctlIoGltfReadOptions::get_parallel() const { return parallel; }
void OcctlIoGltfReadOptions::set_parallel(int val) { parallel = val; }

int OcctlIoGltfReadOptions::get_single_precision() const { return single_precision; }
void OcctlIoGltfReadOptions::set_single_precision(int val) { single_precision = val; }

int OcctlIoGltfReadOptions::get_fill_incomplete() const { return fill_incomplete; }
void OcctlIoGltfReadOptions::set_fill_incomplete(int val) { fill_incomplete = val; }

int OcctlIoGltfReadOptions::get_memory_limit_mib() const { return memory_limit_mib; }
void OcctlIoGltfReadOptions::set_memory_limit_mib(int val) { memory_limit_mib = val; }

void OcctlIoGltfReadOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlIoGltfReadOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlIoGltfReadOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlIoGltfReadOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlIoGltfReadOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_load_all_scenes"), &OcctlIoGltfReadOptions::get_load_all_scenes);
    godot::ClassDB::bind_method(godot::D_METHOD("set_load_all_scenes", "val"), &OcctlIoGltfReadOptions::set_load_all_scenes);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "load_all_scenes"), "set_load_all_scenes", "get_load_all_scenes");
    godot::ClassDB::bind_method(godot::D_METHOD("get_skip_empty_nodes"), &OcctlIoGltfReadOptions::get_skip_empty_nodes);
    godot::ClassDB::bind_method(godot::D_METHOD("set_skip_empty_nodes", "val"), &OcctlIoGltfReadOptions::set_skip_empty_nodes);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "skip_empty_nodes"), "set_skip_empty_nodes", "get_skip_empty_nodes");
    godot::ClassDB::bind_method(godot::D_METHOD("get_use_mesh_name_as_fallback"), &OcctlIoGltfReadOptions::get_use_mesh_name_as_fallback);
    godot::ClassDB::bind_method(godot::D_METHOD("set_use_mesh_name_as_fallback", "val"), &OcctlIoGltfReadOptions::set_use_mesh_name_as_fallback);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "use_mesh_name_as_fallback"), "set_use_mesh_name_as_fallback", "get_use_mesh_name_as_fallback");
    godot::ClassDB::bind_method(godot::D_METHOD("get_apply_scale"), &OcctlIoGltfReadOptions::get_apply_scale);
    godot::ClassDB::bind_method(godot::D_METHOD("set_apply_scale", "val"), &OcctlIoGltfReadOptions::set_apply_scale);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "apply_scale"), "set_apply_scale", "get_apply_scale");
    godot::ClassDB::bind_method(godot::D_METHOD("get_parallel"), &OcctlIoGltfReadOptions::get_parallel);
    godot::ClassDB::bind_method(godot::D_METHOD("set_parallel", "val"), &OcctlIoGltfReadOptions::set_parallel);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "parallel"), "set_parallel", "get_parallel");
    godot::ClassDB::bind_method(godot::D_METHOD("get_single_precision"), &OcctlIoGltfReadOptions::get_single_precision);
    godot::ClassDB::bind_method(godot::D_METHOD("set_single_precision", "val"), &OcctlIoGltfReadOptions::set_single_precision);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "single_precision"), "set_single_precision", "get_single_precision");
    godot::ClassDB::bind_method(godot::D_METHOD("get_fill_incomplete"), &OcctlIoGltfReadOptions::get_fill_incomplete);
    godot::ClassDB::bind_method(godot::D_METHOD("set_fill_incomplete", "val"), &OcctlIoGltfReadOptions::set_fill_incomplete);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "fill_incomplete"), "set_fill_incomplete", "get_fill_incomplete");
    godot::ClassDB::bind_method(godot::D_METHOD("get_memory_limit_mib"), &OcctlIoGltfReadOptions::get_memory_limit_mib);
    godot::ClassDB::bind_method(godot::D_METHOD("set_memory_limit_mib", "val"), &OcctlIoGltfReadOptions::set_memory_limit_mib);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "memory_limit_mib"), "set_memory_limit_mib", "get_memory_limit_mib");
}

occtl_io_gltf_read_options_t OcctlIoGltfReadOptions::to_c() const {
    occtl_io_gltf_read_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.load_all_scenes = load_all_scenes;
    result.skip_empty_nodes = skip_empty_nodes;
    result.use_mesh_name_as_fallback = use_mesh_name_as_fallback;
    result.apply_scale = apply_scale;
    result.parallel = parallel;
    result.single_precision = single_precision;
    result.fill_incomplete = fill_incomplete;
    result.memory_limit_mib = memory_limit_mib;
    return result;
}

Ref<OcctlIoGltfReadOptions> OcctlIoGltfReadOptions::from_c(const occtl_io_gltf_read_options_t& val) {
    Ref<OcctlIoGltfReadOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->load_all_scenes = val.load_all_scenes;
    r->skip_empty_nodes = val.skip_empty_nodes;
    r->use_mesh_name_as_fallback = val.use_mesh_name_as_fallback;
    r->apply_scale = val.apply_scale;
    r->parallel = val.parallel;
    r->single_precision = val.single_precision;
    r->fill_incomplete = val.fill_incomplete;
    r->memory_limit_mib = val.memory_limit_mib;
    return r;
}

void OcctlIoGltfReadOptions::copy_from_c(const occtl_io_gltf_read_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    load_all_scenes = val.load_all_scenes;
    skip_empty_nodes = val.skip_empty_nodes;
    use_mesh_name_as_fallback = val.use_mesh_name_as_fallback;
    apply_scale = val.apply_scale;
    parallel = val.parallel;
    single_precision = val.single_precision;
    fill_incomplete = val.fill_incomplete;
    memory_limit_mib = val.memory_limit_mib;
}
