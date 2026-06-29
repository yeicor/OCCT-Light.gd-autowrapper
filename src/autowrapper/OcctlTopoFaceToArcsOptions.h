#ifndef OCCTLTOPOFACETOARCSOPTIONS_H
#define OCCTLTOPOFACETOARCSOPTIONS_H

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

class OcctlTopoFaceToArcsOptions : public godot::RefCounted {
    GDCLASS(OcctlTopoFaceToArcsOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t source;
    double angular_tolerance;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_source() const;
    void set_source(int64_t val);
    double get_angular_tolerance() const;
    void set_angular_tolerance(double val);

    occtl_topo_face_to_arcs_options_t to_c() const;
    static Ref<OcctlTopoFaceToArcsOptions> from_c(const occtl_topo_face_to_arcs_options_t& val);
    void copy_from_c(const occtl_topo_face_to_arcs_options_t& val);
};

#endif // OCCTLTOPOFACETOARCSOPTIONS_H
