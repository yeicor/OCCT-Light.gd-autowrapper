#ifndef OCCTLCOEDGEVIEW_H
#define OCCTLCOEDGEVIEW_H

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
#include "occtl/occtl_topo.h"

#include "OcctlNodeId.h"
#include "OcctlPoint2.h"

using namespace godot;

class OcctlCoedgeView : public godot::RefCounted {
    GDCLASS(OcctlCoedgeView, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t edge_of;
    int64_t face_of;
    int orientation;
    double t_min;
    double t_max;
    Ref<OcctlPoint2> uv_start;
    Ref<OcctlPoint2> uv_end;
    int is_seam;
    int is_reversed;
    int has_pcurve;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_edge_of() const;
    void set_edge_of(int64_t val);
    int64_t get_face_of() const;
    void set_face_of(int64_t val);
    int get_orientation() const;
    void set_orientation(int val);
    double get_t_min() const;
    void set_t_min(double val);
    double get_t_max() const;
    void set_t_max(double val);
    Ref<OcctlPoint2> get_uv_start() const;
    void set_uv_start(Ref<OcctlPoint2> val);
    Ref<OcctlPoint2> get_uv_end() const;
    void set_uv_end(Ref<OcctlPoint2> val);
    int get_is_seam() const;
    void set_is_seam(int val);
    int get_is_reversed() const;
    void set_is_reversed(int val);
    int get_has_pcurve() const;
    void set_has_pcurve(int val);

    occtl_coedge_view_t to_c() const;
    static Ref<OcctlCoedgeView> from_c(const occtl_coedge_view_t& val);
    void copy_from_c(const occtl_coedge_view_t& val);
};

#endif // OCCTLCOEDGEVIEW_H
