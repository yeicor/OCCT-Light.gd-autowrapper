#ifndef OCCTLPRIMARC3PTINFO_H
#define OCCTLPRIMARC3PTINFO_H

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
#include "occtl/occtl_prim_sketch.h"

#include "OcctlPoint3.h"

using namespace godot;

class OcctlPrimArc3ptInfo : public godot::RefCounted {
    GDCLASS(OcctlPrimArc3ptInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    Ref<OcctlPoint3> start;
    Ref<OcctlPoint3> via;
    Ref<OcctlPoint3> end;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    Ref<OcctlPoint3> get_start() const;
    void set_start(Ref<OcctlPoint3> val);
    Ref<OcctlPoint3> get_via() const;
    void set_via(Ref<OcctlPoint3> val);
    Ref<OcctlPoint3> get_end() const;
    void set_end(Ref<OcctlPoint3> val);

    occtl_prim_arc_3pt_info_t to_c() const;
    static Ref<OcctlPrimArc3ptInfo> from_c(const occtl_prim_arc_3pt_info_t& val);
    void copy_from_c(const occtl_prim_arc_3pt_info_t& val);
};

#endif // OCCTLPRIMARC3PTINFO_H
