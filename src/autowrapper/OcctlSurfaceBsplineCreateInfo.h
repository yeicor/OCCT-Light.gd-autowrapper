#ifndef OCCTLSURFACEBSPLINECREATEINFO_H
#define OCCTLSURFACEBSPLINECREATEINFO_H

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
#include "occtl/occtl_surfaces.h"

#include "OcctlPoint3.h"

using namespace godot;

class OcctlSurfaceBsplineCreateInfo : public godot::RefCounted {
    GDCLASS(OcctlSurfaceBsplineCreateInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    Array poles;
    mutable std::vector<occtl_point3_t> _cache_poles;
    int u_pole_count;
    int v_pole_count;
    PackedFloat64Array weights;
    PackedFloat64Array u_knots;
    PackedInt32Array u_multiplicities;
    int u_knot_count;
    PackedFloat64Array v_knots;
    PackedInt32Array v_multiplicities;
    int v_knot_count;
    int u_degree;
    int v_degree;
    int is_u_periodic;
    int is_v_periodic;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    Array get_poles() const;
    void set_poles(Array val);
    int get_u_pole_count() const;
    void set_u_pole_count(int val);
    int get_v_pole_count() const;
    void set_v_pole_count(int val);
    PackedFloat64Array get_weights() const;
    void set_weights(PackedFloat64Array val);
    PackedFloat64Array get_u_knots() const;
    void set_u_knots(PackedFloat64Array val);
    PackedInt32Array get_u_multiplicities() const;
    void set_u_multiplicities(PackedInt32Array val);
    int get_u_knot_count() const;
    void set_u_knot_count(int val);
    PackedFloat64Array get_v_knots() const;
    void set_v_knots(PackedFloat64Array val);
    PackedInt32Array get_v_multiplicities() const;
    void set_v_multiplicities(PackedInt32Array val);
    int get_v_knot_count() const;
    void set_v_knot_count(int val);
    int get_u_degree() const;
    void set_u_degree(int val);
    int get_v_degree() const;
    void set_v_degree(int val);
    int get_is_u_periodic() const;
    void set_is_u_periodic(int val);
    int get_is_v_periodic() const;
    void set_is_v_periodic(int val);

    occtl_surface_bspline_create_info_t to_c() const;
    static Ref<OcctlSurfaceBsplineCreateInfo> from_c(const occtl_surface_bspline_create_info_t& val);
    void copy_from_c(const occtl_surface_bspline_create_info_t& val);
};

#endif // OCCTLSURFACEBSPLINECREATEINFO_H
