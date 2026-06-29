#ifndef OCCTLPRIMTRACEINFO_H
#define OCCTLPRIMTRACEINFO_H

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
#include "occtl/occtl_prim_sketch.h"

#include "OcctlNodeId.h"
#include "OcctlDirection3.h"

using namespace godot;

class OcctlPrimTraceInfo : public godot::RefCounted {
    GDCLASS(OcctlPrimTraceInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t path;
    double width;
    Ref<OcctlDirection3> normal;
    int join;
    int approximate;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_path() const;
    void set_path(int64_t val);
    double get_width() const;
    void set_width(double val);
    Ref<OcctlDirection3> get_normal() const;
    void set_normal(Ref<OcctlDirection3> val);
    int get_join() const;
    void set_join(int val);
    int get_approximate() const;
    void set_approximate(int val);

    occtl_prim_trace_info_t to_c() const;
    static Ref<OcctlPrimTraceInfo> from_c(const occtl_prim_trace_info_t& val);
    void copy_from_c(const occtl_prim_trace_info_t& val);
};

#endif // OCCTLPRIMTRACEINFO_H
