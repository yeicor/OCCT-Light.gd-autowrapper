#ifndef OCCTLTOPOSECTIONBYPLANESOPTIONS_H
#define OCCTLTOPOSECTIONBYPLANESOPTIONS_H

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
#include "OcctlTopoSectionPlane.h"

using namespace godot;

class OcctlTopoSectionByPlanesOptions : public godot::RefCounted {
    GDCLASS(OcctlTopoSectionByPlanesOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int64_t root;
    Array planes;
    mutable std::vector<occtl_topo_section_plane_t> _cache_planes;
    int plane_count;
    int approximate;
    int compute_pcurves_on_root;
    int compute_pcurves_on_plane;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int64_t get_root() const;
    void set_root(int64_t val);
    Array get_planes() const;
    void set_planes(Array val);
    int get_plane_count() const;
    void set_plane_count(int val);
    int get_approximate() const;
    void set_approximate(int val);
    int get_compute_pcurves_on_root() const;
    void set_compute_pcurves_on_root(int val);
    int get_compute_pcurves_on_plane() const;
    void set_compute_pcurves_on_plane(int val);

    occtl_topo_section_by_planes_options_t to_c() const;
    static Ref<OcctlTopoSectionByPlanesOptions> from_c(const occtl_topo_section_by_planes_options_t& val);
    void copy_from_c(const occtl_topo_section_by_planes_options_t& val);
};

#endif // OCCTLTOPOSECTIONBYPLANESOPTIONS_H
