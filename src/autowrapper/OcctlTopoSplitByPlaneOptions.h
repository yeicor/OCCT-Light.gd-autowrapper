#ifndef OCCTLTOPOSPLITBYPLANEOPTIONS_H
#define OCCTLTOPOSPLITBYPLANEOPTIONS_H

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
#include "OcctlPoint3.h"
#include "OcctlDirection3.h"

using namespace godot;

class OcctlTopoSplitByPlaneOptions : public godot::RefCounted {
    GDCLASS(OcctlTopoSplitByPlaneOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t root;
    Ref<OcctlPoint3> point;
    Ref<OcctlDirection3> normal;
    int keep;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_root() const;
    void set_root(int64_t val);
    Ref<OcctlPoint3> get_point() const;
    void set_point(Ref<OcctlPoint3> val);
    Ref<OcctlDirection3> get_normal() const;
    void set_normal(Ref<OcctlDirection3> val);
    int get_keep() const;
    void set_keep(int val);

    occtl_topo_split_by_plane_options_t to_c() const;
    static Ref<OcctlTopoSplitByPlaneOptions> from_c(const occtl_topo_split_by_plane_options_t& val);
    void copy_from_c(const occtl_topo_split_by_plane_options_t& val);
};

#endif // OCCTLTOPOSPLITBYPLANEOPTIONS_H
