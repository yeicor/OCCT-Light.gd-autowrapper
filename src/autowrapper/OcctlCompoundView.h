#ifndef OCCTLCOMPOUNDVIEW_H
#define OCCTLCOMPOUNDVIEW_H

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
#include "occtl/occtl_topo.h"


using namespace godot;

class OcctlCompoundView : public godot::RefCounted {
    GDCLASS(OcctlCompoundView, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int child_count;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int get_child_count() const;
    void set_child_count(int val);

    occtl_compound_view_t to_c() const;
    static Ref<OcctlCompoundView> from_c(const occtl_compound_view_t& val);
    void copy_from_c(const occtl_compound_view_t& val);
};

#endif // OCCTLCOMPOUNDVIEW_H
