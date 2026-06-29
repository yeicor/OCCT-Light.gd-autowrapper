#ifndef OCCTLTOPOSECTIONPLANE_H
#define OCCTLTOPOSECTIONPLANE_H

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
#include "occtl/occtl_topo_algo.h"

#include "OcctlPoint3.h"
#include "OcctlDirection3.h"

using namespace godot;

class OcctlTopoSectionPlane : public godot::RefCounted {
    GDCLASS(OcctlTopoSectionPlane, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    Ref<OcctlPoint3> point;
    Ref<OcctlDirection3> normal;

    Ref<OcctlPoint3> get_point() const;
    void set_point(Ref<OcctlPoint3> val);
    Ref<OcctlDirection3> get_normal() const;
    void set_normal(Ref<OcctlDirection3> val);

    occtl_topo_section_plane_t to_c() const;
    static Ref<OcctlTopoSectionPlane> from_c(const occtl_topo_section_plane_t& val);
    void copy_from_c(const occtl_topo_section_plane_t& val);
};

#endif // OCCTLTOPOSECTIONPLANE_H
