#ifndef OCCTLTOPOWRAPONFACEOPTIONS_H
#define OCCTLTOPOWRAPONFACEOPTIONS_H

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

#include "OcctlNodeId.h"
#include "OcctlAxis3Placement.h"

using namespace godot;

class OcctlTopoWrapOnFaceOptions : public godot::RefCounted {
    GDCLASS(OcctlTopoWrapOnFaceOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t source;
    int64_t target_face;
    Ref<OcctlAxis3Placement> surface_location;
    double tolerance;
    int initial_subdivisions;
    int max_refinements;
    double intersection_extent;
    double wire_fix_tolerance;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_source() const;
    void set_source(int64_t val);
    int64_t get_target_face() const;
    void set_target_face(int64_t val);
    Ref<OcctlAxis3Placement> get_surface_location() const;
    void set_surface_location(Ref<OcctlAxis3Placement> val);
    double get_tolerance() const;
    void set_tolerance(double val);
    int get_initial_subdivisions() const;
    void set_initial_subdivisions(int val);
    int get_max_refinements() const;
    void set_max_refinements(int val);
    double get_intersection_extent() const;
    void set_intersection_extent(double val);
    double get_wire_fix_tolerance() const;
    void set_wire_fix_tolerance(double val);

    occtl_topo_wrap_on_face_options_t to_c() const;
    static Ref<OcctlTopoWrapOnFaceOptions> from_c(const occtl_topo_wrap_on_face_options_t& val);
    void copy_from_c(const occtl_topo_wrap_on_face_options_t& val);
};

#endif // OCCTLTOPOWRAPONFACEOPTIONS_H
