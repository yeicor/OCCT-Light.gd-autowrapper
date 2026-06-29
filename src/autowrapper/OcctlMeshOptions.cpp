#include "OcctlMeshOptions.h"

#include "OcctlAabb3.h"

int OcctlMeshOptions::get_struct_version() const { return struct_version; }
void OcctlMeshOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlMeshOptions::get_p_next() const { return p_next; }
void OcctlMeshOptions::set_p_next(int64_t val) { p_next = val; }

double OcctlMeshOptions::get_deflection() const { return deflection; }
void OcctlMeshOptions::set_deflection(double val) { deflection = val; }

double OcctlMeshOptions::get_angle() const { return angle; }
void OcctlMeshOptions::set_angle(double val) { angle = val; }

double OcctlMeshOptions::get_deflection_interior() const { return deflection_interior; }
void OcctlMeshOptions::set_deflection_interior(double val) { deflection_interior = val; }

double OcctlMeshOptions::get_angle_interior() const { return angle_interior; }
void OcctlMeshOptions::set_angle_interior(double val) { angle_interior = val; }

double OcctlMeshOptions::get_min_size() const { return min_size; }
void OcctlMeshOptions::set_min_size(double val) { min_size = val; }

int OcctlMeshOptions::get_in_parallel() const { return in_parallel; }
void OcctlMeshOptions::set_in_parallel(int val) { in_parallel = val; }

int OcctlMeshOptions::get_relative() const { return relative; }
void OcctlMeshOptions::set_relative(int val) { relative = val; }

int OcctlMeshOptions::get_internal_vertices_mode() const { return internal_vertices_mode; }
void OcctlMeshOptions::set_internal_vertices_mode(int val) { internal_vertices_mode = val; }

int OcctlMeshOptions::get_control_surface_deflection() const { return control_surface_deflection; }
void OcctlMeshOptions::set_control_surface_deflection(int val) { control_surface_deflection = val; }

int OcctlMeshOptions::get_control_surface_deflection_all() const { return control_surface_deflection_all; }
void OcctlMeshOptions::set_control_surface_deflection_all(int val) { control_surface_deflection_all = val; }

int OcctlMeshOptions::get_clean_model() const { return clean_model; }
void OcctlMeshOptions::set_clean_model(int val) { clean_model = val; }

int OcctlMeshOptions::get_adjust_min_size() const { return adjust_min_size; }
void OcctlMeshOptions::set_adjust_min_size(int val) { adjust_min_size = val; }

int OcctlMeshOptions::get_force_face_deflection() const { return force_face_deflection; }
void OcctlMeshOptions::set_force_face_deflection(int val) { force_face_deflection = val; }

int OcctlMeshOptions::get_allow_quality_decrease() const { return allow_quality_decrease; }
void OcctlMeshOptions::set_allow_quality_decrease(int val) { allow_quality_decrease = val; }

int OcctlMeshOptions::get_use_bbox() const { return use_bbox; }
void OcctlMeshOptions::set_use_bbox(int val) { use_bbox = val; }

Ref<OcctlAabb3> OcctlMeshOptions::get_bbox() const { return bbox; }
void OcctlMeshOptions::set_bbox(Ref<OcctlAabb3> val) { bbox = val; }

double OcctlMeshOptions::get_deviation_coefficient() const { return deviation_coefficient; }
void OcctlMeshOptions::set_deviation_coefficient(double val) { deviation_coefficient = val; }

double OcctlMeshOptions::get_deviation_angle() const { return deviation_angle; }
void OcctlMeshOptions::set_deviation_angle(double val) { deviation_angle = val; }

void OcctlMeshOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlMeshOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlMeshOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlMeshOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlMeshOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_deflection"), &OcctlMeshOptions::get_deflection);
    godot::ClassDB::bind_method(godot::D_METHOD("set_deflection", "val"), &OcctlMeshOptions::set_deflection);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "deflection"), "set_deflection", "get_deflection");
    godot::ClassDB::bind_method(godot::D_METHOD("get_angle"), &OcctlMeshOptions::get_angle);
    godot::ClassDB::bind_method(godot::D_METHOD("set_angle", "val"), &OcctlMeshOptions::set_angle);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "angle"), "set_angle", "get_angle");
    godot::ClassDB::bind_method(godot::D_METHOD("get_deflection_interior"), &OcctlMeshOptions::get_deflection_interior);
    godot::ClassDB::bind_method(godot::D_METHOD("set_deflection_interior", "val"), &OcctlMeshOptions::set_deflection_interior);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "deflection_interior"), "set_deflection_interior", "get_deflection_interior");
    godot::ClassDB::bind_method(godot::D_METHOD("get_angle_interior"), &OcctlMeshOptions::get_angle_interior);
    godot::ClassDB::bind_method(godot::D_METHOD("set_angle_interior", "val"), &OcctlMeshOptions::set_angle_interior);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "angle_interior"), "set_angle_interior", "get_angle_interior");
    godot::ClassDB::bind_method(godot::D_METHOD("get_min_size"), &OcctlMeshOptions::get_min_size);
    godot::ClassDB::bind_method(godot::D_METHOD("set_min_size", "val"), &OcctlMeshOptions::set_min_size);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "min_size"), "set_min_size", "get_min_size");
    godot::ClassDB::bind_method(godot::D_METHOD("get_in_parallel"), &OcctlMeshOptions::get_in_parallel);
    godot::ClassDB::bind_method(godot::D_METHOD("set_in_parallel", "val"), &OcctlMeshOptions::set_in_parallel);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "in_parallel"), "set_in_parallel", "get_in_parallel");
    godot::ClassDB::bind_method(godot::D_METHOD("get_relative"), &OcctlMeshOptions::get_relative);
    godot::ClassDB::bind_method(godot::D_METHOD("set_relative", "val"), &OcctlMeshOptions::set_relative);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "relative"), "set_relative", "get_relative");
    godot::ClassDB::bind_method(godot::D_METHOD("get_internal_vertices_mode"), &OcctlMeshOptions::get_internal_vertices_mode);
    godot::ClassDB::bind_method(godot::D_METHOD("set_internal_vertices_mode", "val"), &OcctlMeshOptions::set_internal_vertices_mode);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "internal_vertices_mode"), "set_internal_vertices_mode", "get_internal_vertices_mode");
    godot::ClassDB::bind_method(godot::D_METHOD("get_control_surface_deflection"), &OcctlMeshOptions::get_control_surface_deflection);
    godot::ClassDB::bind_method(godot::D_METHOD("set_control_surface_deflection", "val"), &OcctlMeshOptions::set_control_surface_deflection);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "control_surface_deflection"), "set_control_surface_deflection", "get_control_surface_deflection");
    godot::ClassDB::bind_method(godot::D_METHOD("get_control_surface_deflection_all"), &OcctlMeshOptions::get_control_surface_deflection_all);
    godot::ClassDB::bind_method(godot::D_METHOD("set_control_surface_deflection_all", "val"), &OcctlMeshOptions::set_control_surface_deflection_all);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "control_surface_deflection_all"), "set_control_surface_deflection_all", "get_control_surface_deflection_all");
    godot::ClassDB::bind_method(godot::D_METHOD("get_clean_model"), &OcctlMeshOptions::get_clean_model);
    godot::ClassDB::bind_method(godot::D_METHOD("set_clean_model", "val"), &OcctlMeshOptions::set_clean_model);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "clean_model"), "set_clean_model", "get_clean_model");
    godot::ClassDB::bind_method(godot::D_METHOD("get_adjust_min_size"), &OcctlMeshOptions::get_adjust_min_size);
    godot::ClassDB::bind_method(godot::D_METHOD("set_adjust_min_size", "val"), &OcctlMeshOptions::set_adjust_min_size);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "adjust_min_size"), "set_adjust_min_size", "get_adjust_min_size");
    godot::ClassDB::bind_method(godot::D_METHOD("get_force_face_deflection"), &OcctlMeshOptions::get_force_face_deflection);
    godot::ClassDB::bind_method(godot::D_METHOD("set_force_face_deflection", "val"), &OcctlMeshOptions::set_force_face_deflection);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "force_face_deflection"), "set_force_face_deflection", "get_force_face_deflection");
    godot::ClassDB::bind_method(godot::D_METHOD("get_allow_quality_decrease"), &OcctlMeshOptions::get_allow_quality_decrease);
    godot::ClassDB::bind_method(godot::D_METHOD("set_allow_quality_decrease", "val"), &OcctlMeshOptions::set_allow_quality_decrease);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "allow_quality_decrease"), "set_allow_quality_decrease", "get_allow_quality_decrease");
    godot::ClassDB::bind_method(godot::D_METHOD("get_use_bbox"), &OcctlMeshOptions::get_use_bbox);
    godot::ClassDB::bind_method(godot::D_METHOD("set_use_bbox", "val"), &OcctlMeshOptions::set_use_bbox);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "use_bbox"), "set_use_bbox", "get_use_bbox");
    godot::ClassDB::bind_method(godot::D_METHOD("get_bbox"), &OcctlMeshOptions::get_bbox);
    godot::ClassDB::bind_method(godot::D_METHOD("set_bbox", "val"), &OcctlMeshOptions::set_bbox);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "bbox"), "set_bbox", "get_bbox");
    godot::ClassDB::bind_method(godot::D_METHOD("get_deviation_coefficient"), &OcctlMeshOptions::get_deviation_coefficient);
    godot::ClassDB::bind_method(godot::D_METHOD("set_deviation_coefficient", "val"), &OcctlMeshOptions::set_deviation_coefficient);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "deviation_coefficient"), "set_deviation_coefficient", "get_deviation_coefficient");
    godot::ClassDB::bind_method(godot::D_METHOD("get_deviation_angle"), &OcctlMeshOptions::get_deviation_angle);
    godot::ClassDB::bind_method(godot::D_METHOD("set_deviation_angle", "val"), &OcctlMeshOptions::set_deviation_angle);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "deviation_angle"), "set_deviation_angle", "get_deviation_angle");
}

occtl_mesh_options_t OcctlMeshOptions::to_c() const {
    occtl_mesh_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.deflection = deflection;
    result.angle = angle;
    result.deflection_interior = deflection_interior;
    result.angle_interior = angle_interior;
    result.min_size = min_size;
    result.in_parallel = in_parallel;
    result.relative = relative;
    result.internal_vertices_mode = internal_vertices_mode;
    result.control_surface_deflection = control_surface_deflection;
    result.control_surface_deflection_all = control_surface_deflection_all;
    result.clean_model = clean_model;
    result.adjust_min_size = adjust_min_size;
    result.force_face_deflection = force_face_deflection;
    result.allow_quality_decrease = allow_quality_decrease;
    result.use_bbox = use_bbox;
    result.bbox = bbox->to_c();
    result.deviation_coefficient = deviation_coefficient;
    result.deviation_angle = deviation_angle;
    return result;
}

Ref<OcctlMeshOptions> OcctlMeshOptions::from_c(const occtl_mesh_options_t& val) {
    Ref<OcctlMeshOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->deflection = val.deflection;
    r->angle = val.angle;
    r->deflection_interior = val.deflection_interior;
    r->angle_interior = val.angle_interior;
    r->min_size = val.min_size;
    r->in_parallel = val.in_parallel;
    r->relative = val.relative;
    r->internal_vertices_mode = val.internal_vertices_mode;
    r->control_surface_deflection = val.control_surface_deflection;
    r->control_surface_deflection_all = val.control_surface_deflection_all;
    r->clean_model = val.clean_model;
    r->adjust_min_size = val.adjust_min_size;
    r->force_face_deflection = val.force_face_deflection;
    r->allow_quality_decrease = val.allow_quality_decrease;
    r->use_bbox = val.use_bbox;
    r->bbox = OcctlAabb3::from_c(val.bbox);
    r->deviation_coefficient = val.deviation_coefficient;
    r->deviation_angle = val.deviation_angle;
    return r;
}

void OcctlMeshOptions::copy_from_c(const occtl_mesh_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    deflection = val.deflection;
    angle = val.angle;
    deflection_interior = val.deflection_interior;
    angle_interior = val.angle_interior;
    min_size = val.min_size;
    in_parallel = val.in_parallel;
    relative = val.relative;
    internal_vertices_mode = val.internal_vertices_mode;
    control_surface_deflection = val.control_surface_deflection;
    control_surface_deflection_all = val.control_surface_deflection_all;
    clean_model = val.clean_model;
    adjust_min_size = val.adjust_min_size;
    force_face_deflection = val.force_face_deflection;
    allow_quality_decrease = val.allow_quality_decrease;
    use_bbox = val.use_bbox;
    bbox = OcctlAabb3::from_c(val.bbox);
    deviation_coefficient = val.deviation_coefficient;
    deviation_angle = val.deviation_angle;
}
