#ifndef OCCTLTOPOMAKECOMPSOLIDINFO_H
#define OCCTLTOPOMAKECOMPSOLIDINFO_H

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
#include "occtl/occtl_topo_build.h"

#include "OcctlOrientedNode.h"

using namespace godot;

class OcctlTopoMakeCompsolidInfo : public godot::RefCounted {
    GDCLASS(OcctlTopoMakeCompsolidInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    Array solids;
    mutable std::vector<occtl_oriented_node_t> _cache_solids;
    int solid_count;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    Array get_solids() const;
    void set_solids(Array val);
    int get_solid_count() const;
    void set_solid_count(int val);

    occtl_topo_make_compsolid_info_t to_c() const;
    static Ref<OcctlTopoMakeCompsolidInfo> from_c(const occtl_topo_make_compsolid_info_t& val);
    void copy_from_c(const occtl_topo_make_compsolid_info_t& val);
};

#endif // OCCTLTOPOMAKECOMPSOLIDINFO_H
