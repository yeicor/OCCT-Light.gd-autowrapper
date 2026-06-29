#include "OcctlPrimSolid.h"

#include "occtl/occtl_prim_solid.h"

void OcctlPrimSolid::_bind_methods() {
    BIND_CONSTANT(OCCTL_PRIM_BOX_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_SPHERE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_CYLINDER_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_CONE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_TORUS_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_WEDGE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_HALFSPACE_INFO_VERSION_1);
    godot::ClassDB::bind_method(godot::D_METHOD("box_info_init", "info"), &OcctlPrimSolid::box_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_box", "graph", "info", "out_solid"), &OcctlPrimSolid::make_box, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("sphere_info_init", "info"), &OcctlPrimSolid::sphere_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_sphere", "graph", "info", "out_solid"), &OcctlPrimSolid::make_sphere, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("cylinder_info_init", "info"), &OcctlPrimSolid::cylinder_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_cylinder", "graph", "info", "out_solid"), &OcctlPrimSolid::make_cylinder, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("cone_info_init", "info"), &OcctlPrimSolid::cone_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_cone", "graph", "info", "out_solid"), &OcctlPrimSolid::make_cone, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("torus_info_init", "info"), &OcctlPrimSolid::torus_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_torus", "graph", "info", "out_solid"), &OcctlPrimSolid::make_torus, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("wedge_info_init", "info"), &OcctlPrimSolid::wedge_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_wedge", "graph", "info", "out_solid"), &OcctlPrimSolid::make_wedge, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("halfspace_info_init", "info"), &OcctlPrimSolid::halfspace_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_halfspace", "graph", "info", "out_solid"), &OcctlPrimSolid::make_halfspace, DEFVAL(Variant()));
}

void OcctlPrimSolid::box_info_init(const Ref<OcctlPrimBoxInfo>& info) { // NOLINT
    occtl_prim_box_info_t _info_val = {};
    ::occtl_prim_box_info_init(&_info_val);
    ::occtl_prim_box_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSolid::make_box(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimBoxInfo>& info, const Ref<OcctlNodeId>& out_solid) { // NOLINT
    occtl_prim_box_info_t _info_c = {};
    const occtl_prim_box_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_solid_val = {};
    occtl_status_t _status = ::occtl_prim_make_box(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_solid_val);
    if (out_solid.is_valid()) out_solid->copy_from_c(_out_solid_val);
    return static_cast<int>(_status);
}

void OcctlPrimSolid::sphere_info_init(const Ref<OcctlPrimSphereInfo>& info) { // NOLINT
    occtl_prim_sphere_info_t _info_val = {};
    ::occtl_prim_sphere_info_init(&_info_val);
    ::occtl_prim_sphere_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSolid::make_sphere(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimSphereInfo>& info, const Ref<OcctlNodeId>& out_solid) { // NOLINT
    occtl_prim_sphere_info_t _info_c = {};
    const occtl_prim_sphere_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_solid_val = {};
    occtl_status_t _status = ::occtl_prim_make_sphere(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_solid_val);
    if (out_solid.is_valid()) out_solid->copy_from_c(_out_solid_val);
    return static_cast<int>(_status);
}

void OcctlPrimSolid::cylinder_info_init(const Ref<OcctlPrimCylinderInfo>& info) { // NOLINT
    occtl_prim_cylinder_info_t _info_val = {};
    ::occtl_prim_cylinder_info_init(&_info_val);
    ::occtl_prim_cylinder_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSolid::make_cylinder(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimCylinderInfo>& info, const Ref<OcctlNodeId>& out_solid) { // NOLINT
    occtl_prim_cylinder_info_t _info_c = {};
    const occtl_prim_cylinder_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_solid_val = {};
    occtl_status_t _status = ::occtl_prim_make_cylinder(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_solid_val);
    if (out_solid.is_valid()) out_solid->copy_from_c(_out_solid_val);
    return static_cast<int>(_status);
}

void OcctlPrimSolid::cone_info_init(const Ref<OcctlPrimConeInfo>& info) { // NOLINT
    occtl_prim_cone_info_t _info_val = {};
    ::occtl_prim_cone_info_init(&_info_val);
    ::occtl_prim_cone_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSolid::make_cone(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimConeInfo>& info, const Ref<OcctlNodeId>& out_solid) { // NOLINT
    occtl_prim_cone_info_t _info_c = {};
    const occtl_prim_cone_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_solid_val = {};
    occtl_status_t _status = ::occtl_prim_make_cone(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_solid_val);
    if (out_solid.is_valid()) out_solid->copy_from_c(_out_solid_val);
    return static_cast<int>(_status);
}

void OcctlPrimSolid::torus_info_init(const Ref<OcctlPrimTorusInfo>& info) { // NOLINT
    occtl_prim_torus_info_t _info_val = {};
    ::occtl_prim_torus_info_init(&_info_val);
    ::occtl_prim_torus_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSolid::make_torus(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimTorusInfo>& info, const Ref<OcctlNodeId>& out_solid) { // NOLINT
    occtl_prim_torus_info_t _info_c = {};
    const occtl_prim_torus_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_solid_val = {};
    occtl_status_t _status = ::occtl_prim_make_torus(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_solid_val);
    if (out_solid.is_valid()) out_solid->copy_from_c(_out_solid_val);
    return static_cast<int>(_status);
}

void OcctlPrimSolid::wedge_info_init(const Ref<OcctlPrimWedgeInfo>& info) { // NOLINT
    occtl_prim_wedge_info_t _info_val = {};
    ::occtl_prim_wedge_info_init(&_info_val);
    ::occtl_prim_wedge_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSolid::make_wedge(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimWedgeInfo>& info, const Ref<OcctlNodeId>& out_solid) { // NOLINT
    occtl_prim_wedge_info_t _info_c = {};
    const occtl_prim_wedge_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_solid_val = {};
    occtl_status_t _status = ::occtl_prim_make_wedge(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_solid_val);
    if (out_solid.is_valid()) out_solid->copy_from_c(_out_solid_val);
    return static_cast<int>(_status);
}

void OcctlPrimSolid::halfspace_info_init(const Ref<OcctlPrimHalfspaceInfo>& info) { // NOLINT
    occtl_prim_halfspace_info_t _info_val = {};
    ::occtl_prim_halfspace_info_init(&_info_val);
    ::occtl_prim_halfspace_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSolid::make_halfspace(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimHalfspaceInfo>& info, const Ref<OcctlNodeId>& out_solid) { // NOLINT
    occtl_prim_halfspace_info_t _info_c = {};
    const occtl_prim_halfspace_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_solid_val = {};
    occtl_status_t _status = ::occtl_prim_make_halfspace(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_solid_val);
    if (out_solid.is_valid()) out_solid->copy_from_c(_out_solid_val);
    return static_cast<int>(_status);
}
