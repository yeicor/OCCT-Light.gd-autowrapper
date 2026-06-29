#ifndef OCCTLTOPOHLRRESULT_H
#define OCCTLTOPOHLRRESULT_H

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

class OcctlTopoHlrResult : public godot::RefCounted {
    GDCLASS(OcctlTopoHlrResult, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t graph;
    int64_t visible_sharp;
    int64_t visible_smooth;
    int64_t visible_seam;
    int64_t visible_outline;
    int64_t hidden_sharp;
    int64_t hidden_smooth;
    int64_t hidden_seam;
    int64_t hidden_outline;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_graph() const;
    void set_graph(int64_t val);
    int64_t get_visible_sharp() const;
    void set_visible_sharp(int64_t val);
    int64_t get_visible_smooth() const;
    void set_visible_smooth(int64_t val);
    int64_t get_visible_seam() const;
    void set_visible_seam(int64_t val);
    int64_t get_visible_outline() const;
    void set_visible_outline(int64_t val);
    int64_t get_hidden_sharp() const;
    void set_hidden_sharp(int64_t val);
    int64_t get_hidden_smooth() const;
    void set_hidden_smooth(int64_t val);
    int64_t get_hidden_seam() const;
    void set_hidden_seam(int64_t val);
    int64_t get_hidden_outline() const;
    void set_hidden_outline(int64_t val);

    occtl_topo_hlr_result_t to_c() const;
    static Ref<OcctlTopoHlrResult> from_c(const occtl_topo_hlr_result_t& val);
    void copy_from_c(const occtl_topo_hlr_result_t& val);
};

#endif // OCCTLTOPOHLRRESULT_H
