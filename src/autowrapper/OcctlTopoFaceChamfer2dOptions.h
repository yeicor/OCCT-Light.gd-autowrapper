#ifndef OCCTLTOPOFACECHAMFER2DOPTIONS_H
#define OCCTLTOPOFACECHAMFER2DOPTIONS_H

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

using namespace godot;

class OcctlTopoFaceChamfer2dOptions : public godot::RefCounted {
    GDCLASS(OcctlTopoFaceChamfer2dOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t face;
    PackedInt64Array vertices;
    int vertex_count;
    double distance1;
    double distance2;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_face() const;
    void set_face(int64_t val);
    PackedInt64Array get_vertices() const;
    void set_vertices(PackedInt64Array val);
    int get_vertex_count() const;
    void set_vertex_count(int val);
    double get_distance1() const;
    void set_distance1(double val);
    double get_distance2() const;
    void set_distance2(double val);

    occtl_topo_face_chamfer_2d_options_t to_c() const;
    static Ref<OcctlTopoFaceChamfer2dOptions> from_c(const occtl_topo_face_chamfer_2d_options_t& val);
    void copy_from_c(const occtl_topo_face_chamfer_2d_options_t& val);
};

#endif // OCCTLTOPOFACECHAMFER2DOPTIONS_H
