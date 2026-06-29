#ifndef OCCTLSELECTGROUPVIEW_H
#define OCCTLSELECTGROUPVIEW_H

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

#include "OcctlColorRgba.h"
#include "OcctlNodeId.h"

using namespace godot;

class OcctlSelectGroupView : public godot::RefCounted {
    GDCLASS(OcctlSelectGroupView, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int key;
    int node_kind;
    int curve_kind;
    int surface_kind;
    double numeric_key;
    String name;
    int name_len;
    int has_color;
    Ref<OcctlColorRgba> color;
    PackedInt64Array nodes;
    int node_count;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int get_key() const;
    void set_key(int val);
    int get_node_kind() const;
    void set_node_kind(int val);
    int get_curve_kind() const;
    void set_curve_kind(int val);
    int get_surface_kind() const;
    void set_surface_kind(int val);
    double get_numeric_key() const;
    void set_numeric_key(double val);
    String get_name() const;
    void set_name(String val);
    int get_name_len() const;
    void set_name_len(int val);
    int get_has_color() const;
    void set_has_color(int val);
    Ref<OcctlColorRgba> get_color() const;
    void set_color(Ref<OcctlColorRgba> val);
    PackedInt64Array get_nodes() const;
    void set_nodes(PackedInt64Array val);
    int get_node_count() const;
    void set_node_count(int val);

    occtl_select_group_view_t to_c() const;
    static Ref<OcctlSelectGroupView> from_c(const occtl_select_group_view_t& val);
    void copy_from_c(const occtl_select_group_view_t& val);
};

#endif // OCCTLSELECTGROUPVIEW_H
