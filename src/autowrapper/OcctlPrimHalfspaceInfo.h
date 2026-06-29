#ifndef OCCTLPRIMHALFSPACEINFO_H
#define OCCTLPRIMHALFSPACEINFO_H

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
#include "occtl/occtl_prim_solid.h"

#include "OcctlNodeId.h"
#include "OcctlPoint3.h"

using namespace godot;

class OcctlPrimHalfspaceInfo : public godot::RefCounted {
    GDCLASS(OcctlPrimHalfspaceInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t face;
    Ref<OcctlPoint3> reference_point;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_face() const;
    void set_face(int64_t val);
    Ref<OcctlPoint3> get_reference_point() const;
    void set_reference_point(Ref<OcctlPoint3> val);

    occtl_prim_halfspace_info_t to_c() const;
    static Ref<OcctlPrimHalfspaceInfo> from_c(const occtl_prim_halfspace_info_t& val);
    void copy_from_c(const occtl_prim_halfspace_info_t& val);
};

#endif // OCCTLPRIMHALFSPACEINFO_H
