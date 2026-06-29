#ifndef OCCTLTOPOPROJECTONFACEOPTIONS_H
#define OCCTLTOPOPROJECTONFACEOPTIONS_H

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

using namespace godot;

class OcctlTopoProjectOnFaceOptions : public godot::RefCounted {
    GDCLASS(OcctlTopoProjectOnFaceOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t source;
    int64_t face;
    double tolerance_3d;
    double tolerance_2d;
    int max_degree;
    int max_segments;
    double max_distance;
    int limit_to_face;
    int compute_3d;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_source() const;
    void set_source(int64_t val);
    int64_t get_face() const;
    void set_face(int64_t val);
    double get_tolerance_3d() const;
    void set_tolerance_3d(double val);
    double get_tolerance_2d() const;
    void set_tolerance_2d(double val);
    int get_max_degree() const;
    void set_max_degree(int val);
    int get_max_segments() const;
    void set_max_segments(int val);
    double get_max_distance() const;
    void set_max_distance(double val);
    int get_limit_to_face() const;
    void set_limit_to_face(int val);
    int get_compute_3d() const;
    void set_compute_3d(int val);

    occtl_topo_project_on_face_options_t to_c() const;
    static Ref<OcctlTopoProjectOnFaceOptions> from_c(const occtl_topo_project_on_face_options_t& val);
    void copy_from_c(const occtl_topo_project_on_face_options_t& val);
};

#endif // OCCTLTOPOPROJECTONFACEOPTIONS_H
