#ifndef OCCTLTOPODEFEATUREOPTIONS_H
#define OCCTLTOPODEFEATUREOPTIONS_H

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

class OcctlTopoDefeatureOptions : public godot::RefCounted {
    GDCLASS(OcctlTopoDefeatureOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t root;
    PackedInt64Array selections;
    int selection_count;
    int parallel;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_root() const;
    void set_root(int64_t val);
    PackedInt64Array get_selections() const;
    void set_selections(PackedInt64Array val);
    int get_selection_count() const;
    void set_selection_count(int val);
    int get_parallel() const;
    void set_parallel(int val);

    occtl_topo_defeature_options_t to_c() const;
    static Ref<OcctlTopoDefeatureOptions> from_c(const occtl_topo_defeature_options_t& val);
    void copy_from_c(const occtl_topo_defeature_options_t& val);
};

#endif // OCCTLTOPODEFEATUREOPTIONS_H
