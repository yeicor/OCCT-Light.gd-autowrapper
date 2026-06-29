#ifndef OCCTLTOPOMAKEFACEINFO_H
#define OCCTLTOPOMAKEFACEINFO_H

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

#include "OcctlRepId.h"
#include "OcctlNodeId.h"

using namespace godot;

class OcctlTopoMakeFaceInfo : public godot::RefCounted {
    GDCLASS(OcctlTopoMakeFaceInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t surface;
    int64_t outer_wire;
    PackedInt64Array inner_wires;
    int inner_wire_count;
    double tolerance;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_surface() const;
    void set_surface(int64_t val);
    int64_t get_outer_wire() const;
    void set_outer_wire(int64_t val);
    PackedInt64Array get_inner_wires() const;
    void set_inner_wires(PackedInt64Array val);
    int get_inner_wire_count() const;
    void set_inner_wire_count(int val);
    double get_tolerance() const;
    void set_tolerance(double val);

    occtl_topo_make_face_info_t to_c() const;
    static Ref<OcctlTopoMakeFaceInfo> from_c(const occtl_topo_make_face_info_t& val);
    void copy_from_c(const occtl_topo_make_face_info_t& val);
};

#endif // OCCTLTOPOMAKEFACEINFO_H
