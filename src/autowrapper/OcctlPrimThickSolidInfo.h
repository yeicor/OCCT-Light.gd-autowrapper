#ifndef OCCTLPRIMTHICKSOLIDINFO_H
#define OCCTLPRIMTHICKSOLIDINFO_H

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
#include "occtl/occtl_prim_sweep.h"

#include "OcctlNodeId.h"

using namespace godot;

class OcctlPrimThickSolidInfo : public godot::RefCounted {
    GDCLASS(OcctlPrimThickSolidInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t solid;
    PackedInt64Array closing_faces;
    int closing_face_count;
    double offset;
    double tolerance;
    int mode;
    int join;
    int intersection;
    int self_intersection;
    int remove_internal_edges;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_solid() const;
    void set_solid(int64_t val);
    PackedInt64Array get_closing_faces() const;
    void set_closing_faces(PackedInt64Array val);
    int get_closing_face_count() const;
    void set_closing_face_count(int val);
    double get_offset() const;
    void set_offset(double val);
    double get_tolerance() const;
    void set_tolerance(double val);
    int get_mode() const;
    void set_mode(int val);
    int get_join() const;
    void set_join(int val);
    int get_intersection() const;
    void set_intersection(int val);
    int get_self_intersection() const;
    void set_self_intersection(int val);
    int get_remove_internal_edges() const;
    void set_remove_internal_edges(int val);

    occtl_prim_thick_solid_info_t to_c() const;
    static Ref<OcctlPrimThickSolidInfo> from_c(const occtl_prim_thick_solid_info_t& val);
    void copy_from_c(const occtl_prim_thick_solid_info_t& val);
};

#endif // OCCTLPRIMTHICKSOLIDINFO_H
