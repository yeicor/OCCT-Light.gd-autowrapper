#include "OcctlTopoSectionByPlanesOptions.h"

#include "OcctlNodeId.h"

int OcctlTopoSectionByPlanesOptions::get_struct_version() const { return struct_version; }
void OcctlTopoSectionByPlanesOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoSectionByPlanesOptions::get_p_next() const { return p_next; }
void OcctlTopoSectionByPlanesOptions::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlTopoSectionByPlanesOptions::get_root() const { return root; }
void OcctlTopoSectionByPlanesOptions::set_root(int64_t val) { root = val; }

Array OcctlTopoSectionByPlanesOptions::get_planes() const { return planes; }
void OcctlTopoSectionByPlanesOptions::set_planes(Array val) { planes = val; }

int OcctlTopoSectionByPlanesOptions::get_plane_count() const { return plane_count; }
void OcctlTopoSectionByPlanesOptions::set_plane_count(int val) { plane_count = val; }

int OcctlTopoSectionByPlanesOptions::get_approximate() const { return approximate; }
void OcctlTopoSectionByPlanesOptions::set_approximate(int val) { approximate = val; }

int OcctlTopoSectionByPlanesOptions::get_compute_pcurves_on_root() const { return compute_pcurves_on_root; }
void OcctlTopoSectionByPlanesOptions::set_compute_pcurves_on_root(int val) { compute_pcurves_on_root = val; }

int OcctlTopoSectionByPlanesOptions::get_compute_pcurves_on_plane() const { return compute_pcurves_on_plane; }
void OcctlTopoSectionByPlanesOptions::set_compute_pcurves_on_plane(int val) { compute_pcurves_on_plane = val; }

void OcctlTopoSectionByPlanesOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoSectionByPlanesOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoSectionByPlanesOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoSectionByPlanesOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoSectionByPlanesOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_root"), &OcctlTopoSectionByPlanesOptions::get_root);
    godot::ClassDB::bind_method(godot::D_METHOD("set_root", "val"), &OcctlTopoSectionByPlanesOptions::set_root);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "root"), "set_root", "get_root");
    godot::ClassDB::bind_method(godot::D_METHOD("get_planes"), &OcctlTopoSectionByPlanesOptions::get_planes);
    godot::ClassDB::bind_method(godot::D_METHOD("set_planes", "val"), &OcctlTopoSectionByPlanesOptions::set_planes);
    ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "planes"), "set_planes", "get_planes");
    godot::ClassDB::bind_method(godot::D_METHOD("get_plane_count"), &OcctlTopoSectionByPlanesOptions::get_plane_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_plane_count", "val"), &OcctlTopoSectionByPlanesOptions::set_plane_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "plane_count"), "set_plane_count", "get_plane_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_approximate"), &OcctlTopoSectionByPlanesOptions::get_approximate);
    godot::ClassDB::bind_method(godot::D_METHOD("set_approximate", "val"), &OcctlTopoSectionByPlanesOptions::set_approximate);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "approximate"), "set_approximate", "get_approximate");
    godot::ClassDB::bind_method(godot::D_METHOD("get_compute_pcurves_on_root"), &OcctlTopoSectionByPlanesOptions::get_compute_pcurves_on_root);
    godot::ClassDB::bind_method(godot::D_METHOD("set_compute_pcurves_on_root", "val"), &OcctlTopoSectionByPlanesOptions::set_compute_pcurves_on_root);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "compute_pcurves_on_root"), "set_compute_pcurves_on_root", "get_compute_pcurves_on_root");
    godot::ClassDB::bind_method(godot::D_METHOD("get_compute_pcurves_on_plane"), &OcctlTopoSectionByPlanesOptions::get_compute_pcurves_on_plane);
    godot::ClassDB::bind_method(godot::D_METHOD("set_compute_pcurves_on_plane", "val"), &OcctlTopoSectionByPlanesOptions::set_compute_pcurves_on_plane);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "compute_pcurves_on_plane"), "set_compute_pcurves_on_plane", "get_compute_pcurves_on_plane");
}

occtl_topo_section_by_planes_options_t OcctlTopoSectionByPlanesOptions::to_c() const {
    occtl_topo_section_by_planes_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.root.bits = static_cast<uint64_t>(root);
    _cache_planes.resize(planes.size());
    for (int _i = 0; _i < planes.size(); _i++) {
        Ref<OcctlTopoSectionPlane> _item = planes[_i];
        if (_item.is_valid()) _cache_planes[_i] = _item->to_c();
        else _cache_planes[_i] = {};
    }
    result.planes = _cache_planes.data();
    result.plane_count = plane_count;
    result.approximate = approximate;
    result.compute_pcurves_on_root = compute_pcurves_on_root;
    result.compute_pcurves_on_plane = compute_pcurves_on_plane;
    return result;
}

Ref<OcctlTopoSectionByPlanesOptions> OcctlTopoSectionByPlanesOptions::from_c(const occtl_topo_section_by_planes_options_t& val) {
    Ref<OcctlTopoSectionByPlanesOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->root = static_cast<int64_t>(val.root.bits);
    // array field planes is not populated from C
    r->plane_count = val.plane_count;
    r->approximate = val.approximate;
    r->compute_pcurves_on_root = val.compute_pcurves_on_root;
    r->compute_pcurves_on_plane = val.compute_pcurves_on_plane;
    return r;
}

void OcctlTopoSectionByPlanesOptions::copy_from_c(const occtl_topo_section_by_planes_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    root = static_cast<int64_t>(val.root.bits);
    // array field planes is not populated from C
    plane_count = val.plane_count;
    approximate = val.approximate;
    compute_pcurves_on_root = val.compute_pcurves_on_root;
    compute_pcurves_on_plane = val.compute_pcurves_on_plane;
}
