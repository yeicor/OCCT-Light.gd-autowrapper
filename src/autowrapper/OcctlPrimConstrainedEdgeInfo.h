#ifndef OCCTLPRIMCONSTRAINEDEDGEINFO_H
#define OCCTLPRIMCONSTRAINEDEDGEINFO_H

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

#include "OcctlRepId.h"
#include "OcctlAxis2Placement.h"

using namespace godot;

class OcctlPrimConstrainedEdgeInfo : public godot::RefCounted {
    GDCLASS(OcctlPrimConstrainedEdgeInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t curve;
    Ref<OcctlAxis2Placement> placement;
    int use_parameter_range;
    double first_parameter;
    double last_parameter;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_curve() const;
    void set_curve(int64_t val);
    Ref<OcctlAxis2Placement> get_placement() const;
    void set_placement(Ref<OcctlAxis2Placement> val);
    int get_use_parameter_range() const;
    void set_use_parameter_range(int val);
    double get_first_parameter() const;
    void set_first_parameter(double val);
    double get_last_parameter() const;
    void set_last_parameter(double val);

    occtl_prim_constrained_edge_info_t to_c() const;
    static Ref<OcctlPrimConstrainedEdgeInfo> from_c(const occtl_prim_constrained_edge_info_t& val);
    void copy_from_c(const occtl_prim_constrained_edge_info_t& val);
};

#endif // OCCTLPRIMCONSTRAINEDEDGEINFO_H
