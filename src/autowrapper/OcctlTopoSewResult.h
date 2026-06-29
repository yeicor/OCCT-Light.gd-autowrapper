#ifndef OCCTLTOPOSEWRESULT_H
#define OCCTLTOPOSEWRESULT_H

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

class OcctlTopoSewResult : public godot::RefCounted {
    GDCLASS(OcctlTopoSewResult, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int is_done;
    int free_edge_count_before;
    int free_edge_count_after;
    int sewn_edge_count;
    int multiple_edge_count;
    int degenerated_edge_count;
    int deleted_face_count;
    int rejected_by_tolerance_count;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int get_is_done() const;
    void set_is_done(int val);
    int get_free_edge_count_before() const;
    void set_free_edge_count_before(int val);
    int get_free_edge_count_after() const;
    void set_free_edge_count_after(int val);
    int get_sewn_edge_count() const;
    void set_sewn_edge_count(int val);
    int get_multiple_edge_count() const;
    void set_multiple_edge_count(int val);
    int get_degenerated_edge_count() const;
    void set_degenerated_edge_count(int val);
    int get_deleted_face_count() const;
    void set_deleted_face_count(int val);
    int get_rejected_by_tolerance_count() const;
    void set_rejected_by_tolerance_count(int val);

    occtl_topo_sew_result_t to_c() const;
    static Ref<OcctlTopoSewResult> from_c(const occtl_topo_sew_result_t& val);
    void copy_from_c(const occtl_topo_sew_result_t& val);
};

#endif // OCCTLTOPOSEWRESULT_H
