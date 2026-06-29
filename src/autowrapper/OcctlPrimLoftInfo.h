#ifndef OCCTLPRIMLOFTINFO_H
#define OCCTLPRIMLOFTINFO_H

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

class OcctlPrimLoftInfo : public godot::RefCounted {
    GDCLASS(OcctlPrimLoftInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    PackedInt64Array sections;
    int section_count;
    int is_solid;
    int ruled;
    double pres3d;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    PackedInt64Array get_sections() const;
    void set_sections(PackedInt64Array val);
    int get_section_count() const;
    void set_section_count(int val);
    int get_is_solid() const;
    void set_is_solid(int val);
    int get_ruled() const;
    void set_ruled(int val);
    double get_pres3d() const;
    void set_pres3d(double val);

    occtl_prim_loft_info_t to_c() const;
    static Ref<OcctlPrimLoftInfo> from_c(const occtl_prim_loft_info_t& val);
    void copy_from_c(const occtl_prim_loft_info_t& val);
};

#endif // OCCTLPRIMLOFTINFO_H
