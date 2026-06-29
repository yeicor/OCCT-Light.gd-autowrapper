#ifndef OCCTLTOPOMAKEEDGEINFO_H
#define OCCTLTOPOMAKEEDGEINFO_H

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

#include "OcctlNodeId.h"
#include "OcctlRepId.h"

using namespace godot;

class OcctlTopoMakeEdgeInfo : public godot::RefCounted {
    GDCLASS(OcctlTopoMakeEdgeInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t start_vertex;
    int64_t end_vertex;
    int64_t curve;
    double first;
    double last;
    double tolerance;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_start_vertex() const;
    void set_start_vertex(int64_t val);
    int64_t get_end_vertex() const;
    void set_end_vertex(int64_t val);
    int64_t get_curve() const;
    void set_curve(int64_t val);
    double get_first() const;
    void set_first(double val);
    double get_last() const;
    void set_last(double val);
    double get_tolerance() const;
    void set_tolerance(double val);

    occtl_topo_make_edge_info_t to_c() const;
    static Ref<OcctlTopoMakeEdgeInfo> from_c(const occtl_topo_make_edge_info_t& val);
    void copy_from_c(const occtl_topo_make_edge_info_t& val);
};

#endif // OCCTLTOPOMAKEEDGEINFO_H
