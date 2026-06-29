#ifndef OCCTLCURVE2DOFFSETCREATEINFO_H
#define OCCTLCURVE2DOFFSETCREATEINFO_H

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
#include "occtl/occtl_curves2d.h"

#include "OcctlRepId.h"

using namespace godot;

class OcctlCurve2dOffsetCreateInfo : public godot::RefCounted {
    GDCLASS(OcctlCurve2dOffsetCreateInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t basis;
    double offset;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_basis() const;
    void set_basis(int64_t val);
    double get_offset() const;
    void set_offset(double val);

    occtl_curve2d_offset_create_info_t to_c() const;
    static Ref<OcctlCurve2dOffsetCreateInfo> from_c(const occtl_curve2d_offset_create_info_t& val);
    void copy_from_c(const occtl_curve2d_offset_create_info_t& val);
};

#endif // OCCTLCURVE2DOFFSETCREATEINFO_H
