#ifndef OCCTLTOPOFILLETOPTIONS_H
#define OCCTLTOPOFILLETOPTIONS_H

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


using namespace godot;

class OcctlTopoFilletOptions : public godot::RefCounted {
    GDCLASS(OcctlTopoFilletOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    double radius;
    int chamfer_mode;
    double chamfer_dist1;
    double chamfer_dist2;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    double get_radius() const;
    void set_radius(double val);
    int get_chamfer_mode() const;
    void set_chamfer_mode(int val);
    double get_chamfer_dist1() const;
    void set_chamfer_dist1(double val);
    double get_chamfer_dist2() const;
    void set_chamfer_dist2(double val);

    occtl_topo_fillet_options_t to_c() const;
    static Ref<OcctlTopoFilletOptions> from_c(const occtl_topo_fillet_options_t& val);
    void copy_from_c(const occtl_topo_fillet_options_t& val);
};

#endif // OCCTLTOPOFILLETOPTIONS_H
