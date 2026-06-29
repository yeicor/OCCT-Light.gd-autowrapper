#ifndef OCCTLTAGVIEW_H
#define OCCTLTAGVIEW_H

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


using namespace godot;

class OcctlTagView : public godot::RefCounted {
    GDCLASS(OcctlTagView, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    String tag;
    int tag_len;

    String get_tag() const;
    void set_tag(String val);
    int get_tag_len() const;
    void set_tag_len(int val);

    occtl_tag_view_t to_c() const;
    static Ref<OcctlTagView> from_c(const occtl_tag_view_t& val);
    void copy_from_c(const occtl_tag_view_t& val);
};

#endif // OCCTLTAGVIEW_H
