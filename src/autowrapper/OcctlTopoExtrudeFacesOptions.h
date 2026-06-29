#ifndef OCCTLTOPOEXTRUDEFACESOPTIONS_H
#define OCCTLTOPOEXTRUDEFACESOPTIONS_H

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

class OcctlTopoExtrudeFacesOptions : public godot::RefCounted {
    GDCLASS(OcctlTopoExtrudeFacesOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    PackedInt64Array faces;
    int face_count;
    double thickness;
    int both_sides;
    int use_normal;
    Ref<OcctlDirection3> normal;
    int copy;
    int canonize;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    PackedInt64Array get_faces() const;
    void set_faces(PackedInt64Array val);
    int get_face_count() const;
    void set_face_count(int val);
    double get_thickness() const;
    void set_thickness(double val);
    int get_both_sides() const;
    void set_both_sides(int val);
    int get_use_normal() const;
    void set_use_normal(int val);
    Ref<OcctlDirection3> get_normal() const;
    void set_normal(Ref<OcctlDirection3> val);
    int get_copy() const;
    void set_copy(int val);
    int get_canonize() const;
    void set_canonize(int val);

    occtl_topo_extrude_faces_options_t to_c() const;
    static Ref<OcctlTopoExtrudeFacesOptions> from_c(const occtl_topo_extrude_faces_options_t& val);
    void copy_from_c(const occtl_topo_extrude_faces_options_t& val);
};

#endif // OCCTLTOPOEXTRUDEFACESOPTIONS_H
