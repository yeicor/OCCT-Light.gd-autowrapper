#include "OcctlSurfaceGordonCreateInfo.h"


int OcctlSurfaceGordonCreateInfo::get_struct_version() const { return struct_version; }
void OcctlSurfaceGordonCreateInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlSurfaceGordonCreateInfo::get_p_next() const { return p_next; }
void OcctlSurfaceGordonCreateInfo::set_p_next(int64_t val) { p_next = val; }

PackedInt64Array OcctlSurfaceGordonCreateInfo::get_profiles() const { return profiles; }
void OcctlSurfaceGordonCreateInfo::set_profiles(PackedInt64Array val) { profiles = val; }

int OcctlSurfaceGordonCreateInfo::get_profile_count() const { return profile_count; }
void OcctlSurfaceGordonCreateInfo::set_profile_count(int val) { profile_count = val; }

PackedInt64Array OcctlSurfaceGordonCreateInfo::get_guides() const { return guides; }
void OcctlSurfaceGordonCreateInfo::set_guides(PackedInt64Array val) { guides = val; }

int OcctlSurfaceGordonCreateInfo::get_guide_count() const { return guide_count; }
void OcctlSurfaceGordonCreateInfo::set_guide_count(int val) { guide_count = val; }

double OcctlSurfaceGordonCreateInfo::get_tolerance() const { return tolerance; }
void OcctlSurfaceGordonCreateInfo::set_tolerance(double val) { tolerance = val; }

int OcctlSurfaceGordonCreateInfo::get_parallel() const { return parallel; }
void OcctlSurfaceGordonCreateInfo::set_parallel(int val) { parallel = val; }

void OcctlSurfaceGordonCreateInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlSurfaceGordonCreateInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlSurfaceGordonCreateInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlSurfaceGordonCreateInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlSurfaceGordonCreateInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_profiles"), &OcctlSurfaceGordonCreateInfo::get_profiles);
    godot::ClassDB::bind_method(godot::D_METHOD("set_profiles", "val"), &OcctlSurfaceGordonCreateInfo::set_profiles);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "profiles"), "set_profiles", "get_profiles");
    godot::ClassDB::bind_method(godot::D_METHOD("get_profile_count"), &OcctlSurfaceGordonCreateInfo::get_profile_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_profile_count", "val"), &OcctlSurfaceGordonCreateInfo::set_profile_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "profile_count"), "set_profile_count", "get_profile_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_guides"), &OcctlSurfaceGordonCreateInfo::get_guides);
    godot::ClassDB::bind_method(godot::D_METHOD("set_guides", "val"), &OcctlSurfaceGordonCreateInfo::set_guides);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "guides"), "set_guides", "get_guides");
    godot::ClassDB::bind_method(godot::D_METHOD("get_guide_count"), &OcctlSurfaceGordonCreateInfo::get_guide_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_guide_count", "val"), &OcctlSurfaceGordonCreateInfo::set_guide_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "guide_count"), "set_guide_count", "get_guide_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_tolerance"), &OcctlSurfaceGordonCreateInfo::get_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_tolerance", "val"), &OcctlSurfaceGordonCreateInfo::set_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "tolerance"), "set_tolerance", "get_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_parallel"), &OcctlSurfaceGordonCreateInfo::get_parallel);
    godot::ClassDB::bind_method(godot::D_METHOD("set_parallel", "val"), &OcctlSurfaceGordonCreateInfo::set_parallel);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "parallel"), "set_parallel", "get_parallel");
}

occtl_surface_gordon_create_info_t OcctlSurfaceGordonCreateInfo::to_c() const {
    occtl_surface_gordon_create_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.profiles = reinterpret_cast<const occtl_rep_id_t*>(profiles.ptr());
    result.profile_count = profile_count;
    result.guides = reinterpret_cast<const occtl_rep_id_t*>(guides.ptr());
    result.guide_count = guide_count;
    result.tolerance = tolerance;
    result.parallel = parallel;
    return result;
}

Ref<OcctlSurfaceGordonCreateInfo> OcctlSurfaceGordonCreateInfo::from_c(const occtl_surface_gordon_create_info_t& val) {
    Ref<OcctlSurfaceGordonCreateInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field profiles is not populated from C
    r->profile_count = val.profile_count;
    // array field guides is not populated from C
    r->guide_count = val.guide_count;
    r->tolerance = val.tolerance;
    r->parallel = val.parallel;
    return r;
}

void OcctlSurfaceGordonCreateInfo::copy_from_c(const occtl_surface_gordon_create_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    // array field profiles is not populated from C
    profile_count = val.profile_count;
    // array field guides is not populated from C
    guide_count = val.guide_count;
    tolerance = val.tolerance;
    parallel = val.parallel;
}
