#ifndef OCCTLTOPOAXISHIT_H
#define OCCTLTOPOAXISHIT_H

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
#include "occtl/occtl_topo_relation.h"

#include "OcctlNodeId.h"
#include "OcctlPoint3.h"
#include "OcctlPoint2.h"
#include "OcctlDirection3.h"

using namespace godot;

class OcctlTopoAxisHit : public godot::RefCounted {
    GDCLASS(OcctlTopoAxisHit, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int64_t face;
    Ref<OcctlPoint3> point;
    Ref<OcctlPoint2> uv;
    double parameter;
    Ref<OcctlDirection3> normal;
    int has_normal;
    int location;

    int64_t get_face() const;
    void set_face(int64_t val);
    Ref<OcctlPoint3> get_point() const;
    void set_point(Ref<OcctlPoint3> val);
    Ref<OcctlPoint2> get_uv() const;
    void set_uv(Ref<OcctlPoint2> val);
    double get_parameter() const;
    void set_parameter(double val);
    Ref<OcctlDirection3> get_normal() const;
    void set_normal(Ref<OcctlDirection3> val);
    int get_has_normal() const;
    void set_has_normal(int val);
    int get_location() const;
    void set_location(int val);

    occtl_topo_axis_hit_t to_c() const;
    static Ref<OcctlTopoAxisHit> from_c(const occtl_topo_axis_hit_t& val);
    void copy_from_c(const occtl_topo_axis_hit_t& val);
};

#endif // OCCTLTOPOAXISHIT_H
