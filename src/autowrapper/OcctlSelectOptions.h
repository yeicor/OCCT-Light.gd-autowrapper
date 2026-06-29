#ifndef OCCTLSELECTOPTIONS_H
#define OCCTLSELECTOPTIONS_H

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
#include "occtl/occtl_topo_build.h"

#include "OcctlNodeId.h"
#include "OcctlColorRgba.h"
#include "OcctlSelectBbox.h"
#include "OcctlDirection3.h"
#include "OcctlPoint3.h"

using namespace godot;

class OcctlSelectOptions : public godot::RefCounted {
    GDCLASS(OcctlSelectOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t root;
    int64_t kind_mask;
    int include_root;
    String name;
    int name_len;
    int use_color;
    Ref<OcctlColorRgba> color;
    float color_tolerance;
    int use_bbox;
    Ref<OcctlSelectBbox> bbox;
    int bbox_mode;
    int use_curve_kind;
    int curve_kind;
    int use_surface_kind;
    int surface_kind;
    int use_axis_position;
    int axis;
    int axis_position;
    double axis_tolerance;
    int use_normal;
    Ref<OcctlDirection3> normal;
    int normal_mode;
    double normal_angle_tolerance;
    int use_measure;
    int measure_kind;
    double measure_min;
    double measure_max;
    int sort_key;
    int sort_direction;
    int sort_axis;
    int sort_measure_kind;
    Ref<OcctlPoint3> sort_point;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_root() const;
    void set_root(int64_t val);
    int64_t get_kind_mask() const;
    void set_kind_mask(int64_t val);
    int get_include_root() const;
    void set_include_root(int val);
    String get_name() const;
    void set_name(String val);
    int get_name_len() const;
    void set_name_len(int val);
    int get_use_color() const;
    void set_use_color(int val);
    Ref<OcctlColorRgba> get_color() const;
    void set_color(Ref<OcctlColorRgba> val);
    float get_color_tolerance() const;
    void set_color_tolerance(float val);
    int get_use_bbox() const;
    void set_use_bbox(int val);
    Ref<OcctlSelectBbox> get_bbox() const;
    void set_bbox(Ref<OcctlSelectBbox> val);
    int get_bbox_mode() const;
    void set_bbox_mode(int val);
    int get_use_curve_kind() const;
    void set_use_curve_kind(int val);
    int get_curve_kind() const;
    void set_curve_kind(int val);
    int get_use_surface_kind() const;
    void set_use_surface_kind(int val);
    int get_surface_kind() const;
    void set_surface_kind(int val);
    int get_use_axis_position() const;
    void set_use_axis_position(int val);
    int get_axis() const;
    void set_axis(int val);
    int get_axis_position() const;
    void set_axis_position(int val);
    double get_axis_tolerance() const;
    void set_axis_tolerance(double val);
    int get_use_normal() const;
    void set_use_normal(int val);
    Ref<OcctlDirection3> get_normal() const;
    void set_normal(Ref<OcctlDirection3> val);
    int get_normal_mode() const;
    void set_normal_mode(int val);
    double get_normal_angle_tolerance() const;
    void set_normal_angle_tolerance(double val);
    int get_use_measure() const;
    void set_use_measure(int val);
    int get_measure_kind() const;
    void set_measure_kind(int val);
    double get_measure_min() const;
    void set_measure_min(double val);
    double get_measure_max() const;
    void set_measure_max(double val);
    int get_sort_key() const;
    void set_sort_key(int val);
    int get_sort_direction() const;
    void set_sort_direction(int val);
    int get_sort_axis() const;
    void set_sort_axis(int val);
    int get_sort_measure_kind() const;
    void set_sort_measure_kind(int val);
    Ref<OcctlPoint3> get_sort_point() const;
    void set_sort_point(Ref<OcctlPoint3> val);

    occtl_select_options_t to_c() const;
    static Ref<OcctlSelectOptions> from_c(const occtl_select_options_t& val);
    void copy_from_c(const occtl_select_options_t& val);
};

#endif // OCCTLSELECTOPTIONS_H
