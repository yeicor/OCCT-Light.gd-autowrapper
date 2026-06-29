#ifndef OCCTLPRIMFEATPRISMINFO_H
#define OCCTLPRIMFEATPRISMINFO_H

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
#include "occtl/occtl_prim_feature.h"

#include "OcctlNodeId.h"
#include "OcctlDirection3.h"

using namespace godot;

class OcctlPrimFeatPrismInfo : public godot::RefCounted {
    GDCLASS(OcctlPrimFeatPrismInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t base_shape;
    int64_t profile;
    int64_t sketch_face;
    Ref<OcctlDirection3> direction;
    int combine;
    int modify;
    int until_kind;
    int64_t until_shape;
    double length;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_base_shape() const;
    void set_base_shape(int64_t val);
    int64_t get_profile() const;
    void set_profile(int64_t val);
    int64_t get_sketch_face() const;
    void set_sketch_face(int64_t val);
    Ref<OcctlDirection3> get_direction() const;
    void set_direction(Ref<OcctlDirection3> val);
    int get_combine() const;
    void set_combine(int val);
    int get_modify() const;
    void set_modify(int val);
    int get_until_kind() const;
    void set_until_kind(int val);
    int64_t get_until_shape() const;
    void set_until_shape(int64_t val);
    double get_length() const;
    void set_length(double val);

    occtl_prim_feat_prism_info_t to_c() const;
    static Ref<OcctlPrimFeatPrismInfo> from_c(const occtl_prim_feat_prism_info_t& val);
    void copy_from_c(const occtl_prim_feat_prism_info_t& val);
};

#endif // OCCTLPRIMFEATPRISMINFO_H
