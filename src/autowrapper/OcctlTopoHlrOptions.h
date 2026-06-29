#ifndef OCCTLTOPOHLROPTIONS_H
#define OCCTLTOPOHLROPTIONS_H

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
#include "OcctlAxis3Placement.h"

using namespace godot;

class OcctlTopoHlrOptions : public godot::RefCounted {
    GDCLASS(OcctlTopoHlrOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t root;
    Ref<OcctlAxis3Placement> projection_frame;
    double focus;
    int include_hidden;
    int include_smooth;
    int include_outline;
    int mode;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_root() const;
    void set_root(int64_t val);
    Ref<OcctlAxis3Placement> get_projection_frame() const;
    void set_projection_frame(Ref<OcctlAxis3Placement> val);
    double get_focus() const;
    void set_focus(double val);
    int get_include_hidden() const;
    void set_include_hidden(int val);
    int get_include_smooth() const;
    void set_include_smooth(int val);
    int get_include_outline() const;
    void set_include_outline(int val);
    int get_mode() const;
    void set_mode(int val);

    occtl_topo_hlr_options_t to_c() const;
    static Ref<OcctlTopoHlrOptions> from_c(const occtl_topo_hlr_options_t& val);
    void copy_from_c(const occtl_topo_hlr_options_t& val);
};

#endif // OCCTLTOPOHLROPTIONS_H
