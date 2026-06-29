#ifndef OCCTLTOPOPROJECTFACEDIRECTIONOPTIONS_H
#define OCCTLTOPOPROJECTFACEDIRECTIONOPTIONS_H

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
#include "OcctlDirection3.h"

using namespace godot;

class OcctlTopoProjectFaceDirectionOptions : public godot::RefCounted {
    GDCLASS(OcctlTopoProjectFaceDirectionOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t source_face;
    int64_t target;
    Ref<OcctlDirection3> direction;
    double max_distance;
    int copy_source;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_source_face() const;
    void set_source_face(int64_t val);
    int64_t get_target() const;
    void set_target(int64_t val);
    Ref<OcctlDirection3> get_direction() const;
    void set_direction(Ref<OcctlDirection3> val);
    double get_max_distance() const;
    void set_max_distance(double val);
    int get_copy_source() const;
    void set_copy_source(int val);

    occtl_topo_project_face_direction_options_t to_c() const;
    static Ref<OcctlTopoProjectFaceDirectionOptions> from_c(const occtl_topo_project_face_direction_options_t& val);
    void copy_from_c(const occtl_topo_project_face_direction_options_t& val);
};

#endif // OCCTLTOPOPROJECTFACEDIRECTIONOPTIONS_H
