#ifndef OCCTLJOINTINFO_H
#define OCCTLJOINTINFO_H

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

#include "OcctlJointId.h"
#include "OcctlNodeId.h"
#include "OcctlTransform.h"
#include "OcctlUid.h"

using namespace godot;

class OcctlJointInfo : public godot::RefCounted {
    GDCLASS(OcctlJointInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t id;
    int kind;
    int64_t node_a;
    int64_t node_b;
    Ref<OcctlTransform> frame_a;
    Ref<OcctlTransform> frame_b;
    int has_limit_min;
    double limit_min;
    int has_limit_max;
    double limit_max;
    int64_t metadata_uid;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_id() const;
    void set_id(int64_t val);
    int get_kind() const;
    void set_kind(int val);
    int64_t get_node_a() const;
    void set_node_a(int64_t val);
    int64_t get_node_b() const;
    void set_node_b(int64_t val);
    Ref<OcctlTransform> get_frame_a() const;
    void set_frame_a(Ref<OcctlTransform> val);
    Ref<OcctlTransform> get_frame_b() const;
    void set_frame_b(Ref<OcctlTransform> val);
    int get_has_limit_min() const;
    void set_has_limit_min(int val);
    double get_limit_min() const;
    void set_limit_min(double val);
    int get_has_limit_max() const;
    void set_has_limit_max(int val);
    double get_limit_max() const;
    void set_limit_max(double val);
    int64_t get_metadata_uid() const;
    void set_metadata_uid(int64_t val);

    occtl_joint_info_t to_c() const;
    static Ref<OcctlJointInfo> from_c(const occtl_joint_info_t& val);
    void copy_from_c(const occtl_joint_info_t& val);
};

#endif // OCCTLJOINTINFO_H
