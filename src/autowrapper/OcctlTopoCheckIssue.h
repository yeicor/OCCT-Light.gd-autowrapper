#ifndef OCCTLTOPOCHECKISSUE_H
#define OCCTLTOPOCHECKISSUE_H

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

using namespace godot;

class OcctlTopoCheckIssue : public godot::RefCounted {
    GDCLASS(OcctlTopoCheckIssue, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int64_t node_id;
    int64_t context_node_id;
    int status_bit;
    int severity;

    int64_t get_node_id() const;
    void set_node_id(int64_t val);
    int64_t get_context_node_id() const;
    void set_context_node_id(int64_t val);
    int get_status_bit() const;
    void set_status_bit(int val);
    int get_severity() const;
    void set_severity(int val);

    occtl_topo_check_issue_t to_c() const;
    static Ref<OcctlTopoCheckIssue> from_c(const occtl_topo_check_issue_t& val);
    void copy_from_c(const occtl_topo_check_issue_t& val);
};

#endif // OCCTLTOPOCHECKISSUE_H
