#ifndef OCCTLTOPODRAFTFACESOPTIONS_H
#define OCCTLTOPODRAFTFACESOPTIONS_H

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
#include "OcctlPoint3.h"

using namespace godot;

class OcctlTopoDraftFacesOptions : public godot::RefCounted {
    GDCLASS(OcctlTopoDraftFacesOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t root;
    PackedInt64Array faces;
    int face_count;
    Ref<OcctlDirection3> pull_direction;
    Ref<OcctlPoint3> neutral_point;
    Ref<OcctlDirection3> neutral_normal;
    double angle;
    int keep_inside;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_root() const;
    void set_root(int64_t val);
    PackedInt64Array get_faces() const;
    void set_faces(PackedInt64Array val);
    int get_face_count() const;
    void set_face_count(int val);
    Ref<OcctlDirection3> get_pull_direction() const;
    void set_pull_direction(Ref<OcctlDirection3> val);
    Ref<OcctlPoint3> get_neutral_point() const;
    void set_neutral_point(Ref<OcctlPoint3> val);
    Ref<OcctlDirection3> get_neutral_normal() const;
    void set_neutral_normal(Ref<OcctlDirection3> val);
    double get_angle() const;
    void set_angle(double val);
    int get_keep_inside() const;
    void set_keep_inside(int val);

    occtl_topo_draft_faces_options_t to_c() const;
    static Ref<OcctlTopoDraftFacesOptions> from_c(const occtl_topo_draft_faces_options_t& val);
    void copy_from_c(const occtl_topo_draft_faces_options_t& val);
};

#endif // OCCTLTOPODRAFTFACESOPTIONS_H
