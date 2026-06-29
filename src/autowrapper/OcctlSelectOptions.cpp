#include "OcctlSelectOptions.h"

#include "OcctlNodeId.h"
#include "OcctlColorRgba.h"
#include "OcctlSelectBbox.h"
#include "OcctlDirection3.h"
#include "OcctlPoint3.h"

int OcctlSelectOptions::get_struct_version() const { return struct_version; }
void OcctlSelectOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlSelectOptions::get_p_next() const { return p_next; }
void OcctlSelectOptions::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlSelectOptions::get_root() const { return root; }
void OcctlSelectOptions::set_root(int64_t val) { root = val; }

int64_t OcctlSelectOptions::get_kind_mask() const { return kind_mask; }
void OcctlSelectOptions::set_kind_mask(int64_t val) { kind_mask = val; }

int OcctlSelectOptions::get_include_root() const { return include_root; }
void OcctlSelectOptions::set_include_root(int val) { include_root = val; }

String OcctlSelectOptions::get_name() const { return name; }
void OcctlSelectOptions::set_name(String val) { name = val; }

int OcctlSelectOptions::get_name_len() const { return name_len; }
void OcctlSelectOptions::set_name_len(int val) { name_len = val; }

int OcctlSelectOptions::get_use_color() const { return use_color; }
void OcctlSelectOptions::set_use_color(int val) { use_color = val; }

Ref<OcctlColorRgba> OcctlSelectOptions::get_color() const { return color; }
void OcctlSelectOptions::set_color(Ref<OcctlColorRgba> val) { color = val; }

float OcctlSelectOptions::get_color_tolerance() const { return color_tolerance; }
void OcctlSelectOptions::set_color_tolerance(float val) { color_tolerance = val; }

int OcctlSelectOptions::get_use_bbox() const { return use_bbox; }
void OcctlSelectOptions::set_use_bbox(int val) { use_bbox = val; }

Ref<OcctlSelectBbox> OcctlSelectOptions::get_bbox() const { return bbox; }
void OcctlSelectOptions::set_bbox(Ref<OcctlSelectBbox> val) { bbox = val; }

int OcctlSelectOptions::get_bbox_mode() const { return bbox_mode; }
void OcctlSelectOptions::set_bbox_mode(int val) { bbox_mode = val; }

int OcctlSelectOptions::get_use_curve_kind() const { return use_curve_kind; }
void OcctlSelectOptions::set_use_curve_kind(int val) { use_curve_kind = val; }

int OcctlSelectOptions::get_curve_kind() const { return curve_kind; }
void OcctlSelectOptions::set_curve_kind(int val) { curve_kind = val; }

int OcctlSelectOptions::get_use_surface_kind() const { return use_surface_kind; }
void OcctlSelectOptions::set_use_surface_kind(int val) { use_surface_kind = val; }

int OcctlSelectOptions::get_surface_kind() const { return surface_kind; }
void OcctlSelectOptions::set_surface_kind(int val) { surface_kind = val; }

int OcctlSelectOptions::get_use_axis_position() const { return use_axis_position; }
void OcctlSelectOptions::set_use_axis_position(int val) { use_axis_position = val; }

int OcctlSelectOptions::get_axis() const { return axis; }
void OcctlSelectOptions::set_axis(int val) { axis = val; }

int OcctlSelectOptions::get_axis_position() const { return axis_position; }
void OcctlSelectOptions::set_axis_position(int val) { axis_position = val; }

double OcctlSelectOptions::get_axis_tolerance() const { return axis_tolerance; }
void OcctlSelectOptions::set_axis_tolerance(double val) { axis_tolerance = val; }

int OcctlSelectOptions::get_use_normal() const { return use_normal; }
void OcctlSelectOptions::set_use_normal(int val) { use_normal = val; }

Ref<OcctlDirection3> OcctlSelectOptions::get_normal() const { return normal; }
void OcctlSelectOptions::set_normal(Ref<OcctlDirection3> val) { normal = val; }

int OcctlSelectOptions::get_normal_mode() const { return normal_mode; }
void OcctlSelectOptions::set_normal_mode(int val) { normal_mode = val; }

double OcctlSelectOptions::get_normal_angle_tolerance() const { return normal_angle_tolerance; }
void OcctlSelectOptions::set_normal_angle_tolerance(double val) { normal_angle_tolerance = val; }

int OcctlSelectOptions::get_use_measure() const { return use_measure; }
void OcctlSelectOptions::set_use_measure(int val) { use_measure = val; }

int OcctlSelectOptions::get_measure_kind() const { return measure_kind; }
void OcctlSelectOptions::set_measure_kind(int val) { measure_kind = val; }

double OcctlSelectOptions::get_measure_min() const { return measure_min; }
void OcctlSelectOptions::set_measure_min(double val) { measure_min = val; }

double OcctlSelectOptions::get_measure_max() const { return measure_max; }
void OcctlSelectOptions::set_measure_max(double val) { measure_max = val; }

int OcctlSelectOptions::get_sort_key() const { return sort_key; }
void OcctlSelectOptions::set_sort_key(int val) { sort_key = val; }

int OcctlSelectOptions::get_sort_direction() const { return sort_direction; }
void OcctlSelectOptions::set_sort_direction(int val) { sort_direction = val; }

int OcctlSelectOptions::get_sort_axis() const { return sort_axis; }
void OcctlSelectOptions::set_sort_axis(int val) { sort_axis = val; }

int OcctlSelectOptions::get_sort_measure_kind() const { return sort_measure_kind; }
void OcctlSelectOptions::set_sort_measure_kind(int val) { sort_measure_kind = val; }

Ref<OcctlPoint3> OcctlSelectOptions::get_sort_point() const { return sort_point; }
void OcctlSelectOptions::set_sort_point(Ref<OcctlPoint3> val) { sort_point = val; }

void OcctlSelectOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlSelectOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlSelectOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlSelectOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlSelectOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_root"), &OcctlSelectOptions::get_root);
    godot::ClassDB::bind_method(godot::D_METHOD("set_root", "val"), &OcctlSelectOptions::set_root);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "root"), "set_root", "get_root");
    godot::ClassDB::bind_method(godot::D_METHOD("get_kind_mask"), &OcctlSelectOptions::get_kind_mask);
    godot::ClassDB::bind_method(godot::D_METHOD("set_kind_mask", "val"), &OcctlSelectOptions::set_kind_mask);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "kind_mask"), "set_kind_mask", "get_kind_mask");
    godot::ClassDB::bind_method(godot::D_METHOD("get_include_root"), &OcctlSelectOptions::get_include_root);
    godot::ClassDB::bind_method(godot::D_METHOD("set_include_root", "val"), &OcctlSelectOptions::set_include_root);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "include_root"), "set_include_root", "get_include_root");
    godot::ClassDB::bind_method(godot::D_METHOD("get_name"), &OcctlSelectOptions::get_name);
    godot::ClassDB::bind_method(godot::D_METHOD("set_name", "val"), &OcctlSelectOptions::set_name);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "name"), "set_name", "get_name");
    godot::ClassDB::bind_method(godot::D_METHOD("get_name_len"), &OcctlSelectOptions::get_name_len);
    godot::ClassDB::bind_method(godot::D_METHOD("set_name_len", "val"), &OcctlSelectOptions::set_name_len);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "name_len"), "set_name_len", "get_name_len");
    godot::ClassDB::bind_method(godot::D_METHOD("get_use_color"), &OcctlSelectOptions::get_use_color);
    godot::ClassDB::bind_method(godot::D_METHOD("set_use_color", "val"), &OcctlSelectOptions::set_use_color);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "use_color"), "set_use_color", "get_use_color");
    godot::ClassDB::bind_method(godot::D_METHOD("get_color"), &OcctlSelectOptions::get_color);
    godot::ClassDB::bind_method(godot::D_METHOD("set_color", "val"), &OcctlSelectOptions::set_color);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "color"), "set_color", "get_color");
    godot::ClassDB::bind_method(godot::D_METHOD("get_color_tolerance"), &OcctlSelectOptions::get_color_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_color_tolerance", "val"), &OcctlSelectOptions::set_color_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "color_tolerance"), "set_color_tolerance", "get_color_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_use_bbox"), &OcctlSelectOptions::get_use_bbox);
    godot::ClassDB::bind_method(godot::D_METHOD("set_use_bbox", "val"), &OcctlSelectOptions::set_use_bbox);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "use_bbox"), "set_use_bbox", "get_use_bbox");
    godot::ClassDB::bind_method(godot::D_METHOD("get_bbox"), &OcctlSelectOptions::get_bbox);
    godot::ClassDB::bind_method(godot::D_METHOD("set_bbox", "val"), &OcctlSelectOptions::set_bbox);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "bbox"), "set_bbox", "get_bbox");
    godot::ClassDB::bind_method(godot::D_METHOD("get_bbox_mode"), &OcctlSelectOptions::get_bbox_mode);
    godot::ClassDB::bind_method(godot::D_METHOD("set_bbox_mode", "val"), &OcctlSelectOptions::set_bbox_mode);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "bbox_mode"), "set_bbox_mode", "get_bbox_mode");
    godot::ClassDB::bind_method(godot::D_METHOD("get_use_curve_kind"), &OcctlSelectOptions::get_use_curve_kind);
    godot::ClassDB::bind_method(godot::D_METHOD("set_use_curve_kind", "val"), &OcctlSelectOptions::set_use_curve_kind);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "use_curve_kind"), "set_use_curve_kind", "get_use_curve_kind");
    godot::ClassDB::bind_method(godot::D_METHOD("get_curve_kind"), &OcctlSelectOptions::get_curve_kind);
    godot::ClassDB::bind_method(godot::D_METHOD("set_curve_kind", "val"), &OcctlSelectOptions::set_curve_kind);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "curve_kind"), "set_curve_kind", "get_curve_kind");
    godot::ClassDB::bind_method(godot::D_METHOD("get_use_surface_kind"), &OcctlSelectOptions::get_use_surface_kind);
    godot::ClassDB::bind_method(godot::D_METHOD("set_use_surface_kind", "val"), &OcctlSelectOptions::set_use_surface_kind);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "use_surface_kind"), "set_use_surface_kind", "get_use_surface_kind");
    godot::ClassDB::bind_method(godot::D_METHOD("get_surface_kind"), &OcctlSelectOptions::get_surface_kind);
    godot::ClassDB::bind_method(godot::D_METHOD("set_surface_kind", "val"), &OcctlSelectOptions::set_surface_kind);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "surface_kind"), "set_surface_kind", "get_surface_kind");
    godot::ClassDB::bind_method(godot::D_METHOD("get_use_axis_position"), &OcctlSelectOptions::get_use_axis_position);
    godot::ClassDB::bind_method(godot::D_METHOD("set_use_axis_position", "val"), &OcctlSelectOptions::set_use_axis_position);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "use_axis_position"), "set_use_axis_position", "get_use_axis_position");
    godot::ClassDB::bind_method(godot::D_METHOD("get_axis"), &OcctlSelectOptions::get_axis);
    godot::ClassDB::bind_method(godot::D_METHOD("set_axis", "val"), &OcctlSelectOptions::set_axis);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "axis"), "set_axis", "get_axis");
    godot::ClassDB::bind_method(godot::D_METHOD("get_axis_position"), &OcctlSelectOptions::get_axis_position);
    godot::ClassDB::bind_method(godot::D_METHOD("set_axis_position", "val"), &OcctlSelectOptions::set_axis_position);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "axis_position"), "set_axis_position", "get_axis_position");
    godot::ClassDB::bind_method(godot::D_METHOD("get_axis_tolerance"), &OcctlSelectOptions::get_axis_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_axis_tolerance", "val"), &OcctlSelectOptions::set_axis_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "axis_tolerance"), "set_axis_tolerance", "get_axis_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_use_normal"), &OcctlSelectOptions::get_use_normal);
    godot::ClassDB::bind_method(godot::D_METHOD("set_use_normal", "val"), &OcctlSelectOptions::set_use_normal);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "use_normal"), "set_use_normal", "get_use_normal");
    godot::ClassDB::bind_method(godot::D_METHOD("get_normal"), &OcctlSelectOptions::get_normal);
    godot::ClassDB::bind_method(godot::D_METHOD("set_normal", "val"), &OcctlSelectOptions::set_normal);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "normal"), "set_normal", "get_normal");
    godot::ClassDB::bind_method(godot::D_METHOD("get_normal_mode"), &OcctlSelectOptions::get_normal_mode);
    godot::ClassDB::bind_method(godot::D_METHOD("set_normal_mode", "val"), &OcctlSelectOptions::set_normal_mode);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "normal_mode"), "set_normal_mode", "get_normal_mode");
    godot::ClassDB::bind_method(godot::D_METHOD("get_normal_angle_tolerance"), &OcctlSelectOptions::get_normal_angle_tolerance);
    godot::ClassDB::bind_method(godot::D_METHOD("set_normal_angle_tolerance", "val"), &OcctlSelectOptions::set_normal_angle_tolerance);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "normal_angle_tolerance"), "set_normal_angle_tolerance", "get_normal_angle_tolerance");
    godot::ClassDB::bind_method(godot::D_METHOD("get_use_measure"), &OcctlSelectOptions::get_use_measure);
    godot::ClassDB::bind_method(godot::D_METHOD("set_use_measure", "val"), &OcctlSelectOptions::set_use_measure);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "use_measure"), "set_use_measure", "get_use_measure");
    godot::ClassDB::bind_method(godot::D_METHOD("get_measure_kind"), &OcctlSelectOptions::get_measure_kind);
    godot::ClassDB::bind_method(godot::D_METHOD("set_measure_kind", "val"), &OcctlSelectOptions::set_measure_kind);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "measure_kind"), "set_measure_kind", "get_measure_kind");
    godot::ClassDB::bind_method(godot::D_METHOD("get_measure_min"), &OcctlSelectOptions::get_measure_min);
    godot::ClassDB::bind_method(godot::D_METHOD("set_measure_min", "val"), &OcctlSelectOptions::set_measure_min);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "measure_min"), "set_measure_min", "get_measure_min");
    godot::ClassDB::bind_method(godot::D_METHOD("get_measure_max"), &OcctlSelectOptions::get_measure_max);
    godot::ClassDB::bind_method(godot::D_METHOD("set_measure_max", "val"), &OcctlSelectOptions::set_measure_max);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "measure_max"), "set_measure_max", "get_measure_max");
    godot::ClassDB::bind_method(godot::D_METHOD("get_sort_key"), &OcctlSelectOptions::get_sort_key);
    godot::ClassDB::bind_method(godot::D_METHOD("set_sort_key", "val"), &OcctlSelectOptions::set_sort_key);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "sort_key"), "set_sort_key", "get_sort_key");
    godot::ClassDB::bind_method(godot::D_METHOD("get_sort_direction"), &OcctlSelectOptions::get_sort_direction);
    godot::ClassDB::bind_method(godot::D_METHOD("set_sort_direction", "val"), &OcctlSelectOptions::set_sort_direction);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "sort_direction"), "set_sort_direction", "get_sort_direction");
    godot::ClassDB::bind_method(godot::D_METHOD("get_sort_axis"), &OcctlSelectOptions::get_sort_axis);
    godot::ClassDB::bind_method(godot::D_METHOD("set_sort_axis", "val"), &OcctlSelectOptions::set_sort_axis);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "sort_axis"), "set_sort_axis", "get_sort_axis");
    godot::ClassDB::bind_method(godot::D_METHOD("get_sort_measure_kind"), &OcctlSelectOptions::get_sort_measure_kind);
    godot::ClassDB::bind_method(godot::D_METHOD("set_sort_measure_kind", "val"), &OcctlSelectOptions::set_sort_measure_kind);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "sort_measure_kind"), "set_sort_measure_kind", "get_sort_measure_kind");
    godot::ClassDB::bind_method(godot::D_METHOD("get_sort_point"), &OcctlSelectOptions::get_sort_point);
    godot::ClassDB::bind_method(godot::D_METHOD("set_sort_point", "val"), &OcctlSelectOptions::set_sort_point);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "sort_point"), "set_sort_point", "get_sort_point");
}

occtl_select_options_t OcctlSelectOptions::to_c() const {
    occtl_select_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.root.bits = static_cast<uint64_t>(root);
    result.kind_mask = kind_mask;
    result.include_root = include_root;
    // const pointer field name: not convertible (type String)
    result.name_len = name_len;
    result.use_color = use_color;
    result.color = color->to_c();
    result.color_tolerance = color_tolerance;
    result.use_bbox = use_bbox;
    result.bbox = bbox->to_c();
    result.bbox_mode = static_cast<occtl_select_bbox_mode_t>(bbox_mode);
    result.use_curve_kind = use_curve_kind;
    result.curve_kind = static_cast<occtl_curve_kind_t>(curve_kind);
    result.use_surface_kind = use_surface_kind;
    result.surface_kind = static_cast<occtl_surface_kind_t>(surface_kind);
    result.use_axis_position = use_axis_position;
    result.axis = static_cast<occtl_select_axis_t>(axis);
    result.axis_position = static_cast<occtl_select_axis_position_t>(axis_position);
    result.axis_tolerance = axis_tolerance;
    result.use_normal = use_normal;
    result.normal = normal->to_c();
    result.normal_mode = static_cast<occtl_select_normal_mode_t>(normal_mode);
    result.normal_angle_tolerance = normal_angle_tolerance;
    result.use_measure = use_measure;
    result.measure_kind = static_cast<occtl_select_measure_kind_t>(measure_kind);
    result.measure_min = measure_min;
    result.measure_max = measure_max;
    result.sort_key = static_cast<occtl_select_sort_key_t>(sort_key);
    result.sort_direction = static_cast<occtl_select_sort_direction_t>(sort_direction);
    result.sort_axis = static_cast<occtl_select_axis_t>(sort_axis);
    result.sort_measure_kind = static_cast<occtl_select_measure_kind_t>(sort_measure_kind);
    result.sort_point = sort_point->to_c();
    return result;
}

Ref<OcctlSelectOptions> OcctlSelectOptions::from_c(const occtl_select_options_t& val) {
    Ref<OcctlSelectOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->root = static_cast<int64_t>(val.root.bits);
    r->kind_mask = val.kind_mask;
    r->include_root = val.include_root;
    if (val.name) r->name = String(val.name);
    r->name_len = val.name_len;
    r->use_color = val.use_color;
    r->color = OcctlColorRgba::from_c(val.color);
    r->color_tolerance = val.color_tolerance;
    r->use_bbox = val.use_bbox;
    r->bbox = OcctlSelectBbox::from_c(val.bbox);
    r->bbox_mode = static_cast<int>(val.bbox_mode);
    r->use_curve_kind = val.use_curve_kind;
    r->curve_kind = static_cast<int>(val.curve_kind);
    r->use_surface_kind = val.use_surface_kind;
    r->surface_kind = static_cast<int>(val.surface_kind);
    r->use_axis_position = val.use_axis_position;
    r->axis = static_cast<int>(val.axis);
    r->axis_position = static_cast<int>(val.axis_position);
    r->axis_tolerance = val.axis_tolerance;
    r->use_normal = val.use_normal;
    r->normal = OcctlDirection3::from_c(val.normal);
    r->normal_mode = static_cast<int>(val.normal_mode);
    r->normal_angle_tolerance = val.normal_angle_tolerance;
    r->use_measure = val.use_measure;
    r->measure_kind = static_cast<int>(val.measure_kind);
    r->measure_min = val.measure_min;
    r->measure_max = val.measure_max;
    r->sort_key = static_cast<int>(val.sort_key);
    r->sort_direction = static_cast<int>(val.sort_direction);
    r->sort_axis = static_cast<int>(val.sort_axis);
    r->sort_measure_kind = static_cast<int>(val.sort_measure_kind);
    r->sort_point = OcctlPoint3::from_c(val.sort_point);
    return r;
}

void OcctlSelectOptions::copy_from_c(const occtl_select_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    root = static_cast<int64_t>(val.root.bits);
    kind_mask = val.kind_mask;
    include_root = val.include_root;
    if (val.name) name = String(val.name);
    name_len = val.name_len;
    use_color = val.use_color;
    color = OcctlColorRgba::from_c(val.color);
    color_tolerance = val.color_tolerance;
    use_bbox = val.use_bbox;
    bbox = OcctlSelectBbox::from_c(val.bbox);
    bbox_mode = static_cast<int>(val.bbox_mode);
    use_curve_kind = val.use_curve_kind;
    curve_kind = static_cast<int>(val.curve_kind);
    use_surface_kind = val.use_surface_kind;
    surface_kind = static_cast<int>(val.surface_kind);
    use_axis_position = val.use_axis_position;
    axis = static_cast<int>(val.axis);
    axis_position = static_cast<int>(val.axis_position);
    axis_tolerance = val.axis_tolerance;
    use_normal = val.use_normal;
    normal = OcctlDirection3::from_c(val.normal);
    normal_mode = static_cast<int>(val.normal_mode);
    normal_angle_tolerance = val.normal_angle_tolerance;
    use_measure = val.use_measure;
    measure_kind = static_cast<int>(val.measure_kind);
    measure_min = val.measure_min;
    measure_max = val.measure_max;
    sort_key = static_cast<int>(val.sort_key);
    sort_direction = static_cast<int>(val.sort_direction);
    sort_axis = static_cast<int>(val.sort_axis);
    sort_measure_kind = static_cast<int>(val.sort_measure_kind);
    sort_point = OcctlPoint3::from_c(val.sort_point);
}
