#ifndef OCCTLPRIMSOLID_H
#define OCCTLPRIMSOLID_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/packed_byte_array.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/vector3.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/transform3d.hpp>
#include <godot_cpp/variant/aabb.hpp>
#include <godot_cpp/variant/color.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <cstdint>
#include "occtl/occtl_prim_solid.h"

#include "OcctlGraphHandle.h"
#include "OcctlNodeId.h"
#include "OcctlPrimBoxInfo.h"
#include "OcctlPrimConeInfo.h"
#include "OcctlPrimCylinderInfo.h"
#include "OcctlPrimHalfspaceInfo.h"
#include "OcctlPrimSphereInfo.h"
#include "OcctlPrimTorusInfo.h"
#include "OcctlPrimWedgeInfo.h"

using namespace godot;

class OcctlPrimSolid : public godot::RefCounted {
    GDCLASS(OcctlPrimSolid, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    void box_info_init(const Ref<OcctlPrimBoxInfo>& info); // NOLINT
    int make_box(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimBoxInfo>& info, const Ref<OcctlNodeId>& out_solid); // NOLINT
    void sphere_info_init(const Ref<OcctlPrimSphereInfo>& info); // NOLINT
    int make_sphere(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimSphereInfo>& info, const Ref<OcctlNodeId>& out_solid); // NOLINT
    void cylinder_info_init(const Ref<OcctlPrimCylinderInfo>& info); // NOLINT
    int make_cylinder(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimCylinderInfo>& info, const Ref<OcctlNodeId>& out_solid); // NOLINT
    void cone_info_init(const Ref<OcctlPrimConeInfo>& info); // NOLINT
    int make_cone(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimConeInfo>& info, const Ref<OcctlNodeId>& out_solid); // NOLINT
    void torus_info_init(const Ref<OcctlPrimTorusInfo>& info); // NOLINT
    int make_torus(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimTorusInfo>& info, const Ref<OcctlNodeId>& out_solid); // NOLINT
    void wedge_info_init(const Ref<OcctlPrimWedgeInfo>& info); // NOLINT
    int make_wedge(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimWedgeInfo>& info, const Ref<OcctlNodeId>& out_solid); // NOLINT
    void halfspace_info_init(const Ref<OcctlPrimHalfspaceInfo>& info); // NOLINT
    int make_halfspace(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimHalfspaceInfo>& info, const Ref<OcctlNodeId>& out_solid); // NOLINT
};

#endif // OCCTLPRIMSOLID_H
