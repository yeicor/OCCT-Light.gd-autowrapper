#include "OcctlPrimSweep.h"

#include "occtl/occtl_prim_sweep.h"

void OcctlPrimSweep::_bind_methods() {
    BIND_CONSTANT(OCCTL_PRIM_PRISM_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_TWIST_EXTRUSION_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_EXTRUDE_TWIST_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_REVOL_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_PIPE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_LOFT_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_PIPE_SHELL_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_PIPE_SHELL_LINEAR_LAW_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_PIPE_SHELL_INTERPOLATED_LAW_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_OFFSET_SHAPE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_PRIM_THICK_SOLID_INFO_VERSION_1);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_pipe_mode_t", "OCCTL_PIPE_MODE_CORRECTED_FRENET", OCCTL_PIPE_MODE_CORRECTED_FRENET);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_pipe_mode_t", "OCCTL_PIPE_MODE_FRENET", OCCTL_PIPE_MODE_FRENET);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_pipe_mode_t", "OCCTL_PIPE_MODE_DISCRETE", OCCTL_PIPE_MODE_DISCRETE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_pipe_mode_t", "OCCTL_PIPE_MODE_CONSTANT_AXIS", OCCTL_PIPE_MODE_CONSTANT_AXIS);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_pipe_mode_t", "OCCTL_PIPE_MODE_CONSTANT_BINORMAL", OCCTL_PIPE_MODE_CONSTANT_BINORMAL);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_pipe_mode_t", "OCCTL_PIPE_MODE_RESERVED_FUTURE", OCCTL_PIPE_MODE_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_pipe_transition_t", "OCCTL_PIPE_TRANSITION_MODIFIED", OCCTL_PIPE_TRANSITION_MODIFIED);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_pipe_transition_t", "OCCTL_PIPE_TRANSITION_RIGHT_CORNER", OCCTL_PIPE_TRANSITION_RIGHT_CORNER);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_pipe_transition_t", "OCCTL_PIPE_TRANSITION_ROUND_CORNER", OCCTL_PIPE_TRANSITION_ROUND_CORNER);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_pipe_transition_t", "OCCTL_PIPE_TRANSITION_RESERVED_FUTURE", OCCTL_PIPE_TRANSITION_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_offset_mode_t", "OCCTL_OFFSET_MODE_SKIN", OCCTL_OFFSET_MODE_SKIN);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_offset_mode_t", "OCCTL_OFFSET_MODE_PIPE", OCCTL_OFFSET_MODE_PIPE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_offset_mode_t", "OCCTL_OFFSET_MODE_RECTO_VERSO", OCCTL_OFFSET_MODE_RECTO_VERSO);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_prim_offset_mode_t", "OCCTL_OFFSET_MODE_RESERVED_FUTURE", OCCTL_OFFSET_MODE_RESERVED_FUTURE);
    godot::ClassDB::bind_method(godot::D_METHOD("prism_info_init", "info"), &OcctlPrimSweep::prism_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_prism", "graph", "info", "out_shape"), &OcctlPrimSweep::make_prism, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("twist_extrusion_info_init", "info"), &OcctlPrimSweep::twist_extrusion_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_twist_extrusion", "graph", "info", "out_shape"), &OcctlPrimSweep::make_twist_extrusion, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("extrude_twist_info_init", "info"), &OcctlPrimSweep::extrude_twist_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_extrude_twist", "graph", "info", "out_shape"), &OcctlPrimSweep::make_extrude_twist, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("revol_info_init", "info"), &OcctlPrimSweep::revol_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_revol", "graph", "info", "out_shape"), &OcctlPrimSweep::make_revol, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("pipe_info_init", "info"), &OcctlPrimSweep::pipe_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_pipe", "graph", "info", "out_shape"), &OcctlPrimSweep::make_pipe, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("loft_info_init", "info"), &OcctlPrimSweep::loft_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_loft", "graph", "info", "out_shape"), &OcctlPrimSweep::make_loft, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("pipe_shell_info_init", "info"), &OcctlPrimSweep::pipe_shell_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_pipe_shell", "graph", "info", "out_shape"), &OcctlPrimSweep::make_pipe_shell, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("pipe_shell_linear_law_info_init", "info"), &OcctlPrimSweep::pipe_shell_linear_law_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_pipe_shell_linear_law", "graph", "info", "out_shape"), &OcctlPrimSweep::make_pipe_shell_linear_law, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("pipe_shell_interpolated_law_info_init", "info"), &OcctlPrimSweep::pipe_shell_interpolated_law_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_pipe_shell_interpolated_law", "graph", "info", "out_shape"), &OcctlPrimSweep::make_pipe_shell_interpolated_law, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("offset_shape_info_init", "info"), &OcctlPrimSweep::offset_shape_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_offset_shape", "graph", "info", "out_shape"), &OcctlPrimSweep::make_offset_shape, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("thick_solid_info_init", "info"), &OcctlPrimSweep::thick_solid_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("make_thick_solid", "graph", "info", "out_solid"), &OcctlPrimSweep::make_thick_solid, DEFVAL(Variant()));
}

void OcctlPrimSweep::prism_info_init(const Ref<OcctlPrimPrismInfo>& info) { // NOLINT
    occtl_prim_prism_info_t _info_val = {};
    ::occtl_prim_prism_info_init(&_info_val);
    ::occtl_prim_prism_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSweep::make_prism(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimPrismInfo>& info, const Ref<OcctlNodeId>& out_shape) { // NOLINT
    occtl_prim_prism_info_t _info_c = {};
    const occtl_prim_prism_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_shape_val = {};
    occtl_status_t _status = ::occtl_prim_make_prism(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_shape_val);
    if (out_shape.is_valid()) out_shape->copy_from_c(_out_shape_val);
    return static_cast<int>(_status);
}

void OcctlPrimSweep::twist_extrusion_info_init(const Ref<OcctlPrimTwistExtrusionInfo>& info) { // NOLINT
    occtl_prim_twist_extrusion_info_t _info_val = {};
    ::occtl_prim_twist_extrusion_info_init(&_info_val);
    ::occtl_prim_twist_extrusion_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSweep::make_twist_extrusion(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimTwistExtrusionInfo>& info, const Ref<OcctlNodeId>& out_shape) { // NOLINT
    occtl_prim_twist_extrusion_info_t _info_c = {};
    const occtl_prim_twist_extrusion_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_shape_val = {};
    occtl_status_t _status = ::occtl_prim_make_twist_extrusion(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_shape_val);
    if (out_shape.is_valid()) out_shape->copy_from_c(_out_shape_val);
    return static_cast<int>(_status);
}

void OcctlPrimSweep::extrude_twist_info_init(const Ref<OcctlPrimExtrudeTwistInfo>& info) { // NOLINT
    occtl_prim_extrude_twist_info_t _info_val = {};
    ::occtl_prim_extrude_twist_info_init(&_info_val);
    ::occtl_prim_extrude_twist_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSweep::make_extrude_twist(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimExtrudeTwistInfo>& info, const Ref<OcctlNodeId>& out_shape) { // NOLINT
    occtl_prim_extrude_twist_info_t _info_c = {};
    const occtl_prim_extrude_twist_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_shape_val = {};
    occtl_status_t _status = ::occtl_prim_make_extrude_twist(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_shape_val);
    if (out_shape.is_valid()) out_shape->copy_from_c(_out_shape_val);
    return static_cast<int>(_status);
}

void OcctlPrimSweep::revol_info_init(const Ref<OcctlPrimRevolInfo>& info) { // NOLINT
    occtl_prim_revol_info_t _info_val = {};
    ::occtl_prim_revol_info_init(&_info_val);
    ::occtl_prim_revol_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSweep::make_revol(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimRevolInfo>& info, const Ref<OcctlNodeId>& out_shape) { // NOLINT
    occtl_prim_revol_info_t _info_c = {};
    const occtl_prim_revol_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_shape_val = {};
    occtl_status_t _status = ::occtl_prim_make_revol(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_shape_val);
    if (out_shape.is_valid()) out_shape->copy_from_c(_out_shape_val);
    return static_cast<int>(_status);
}

void OcctlPrimSweep::pipe_info_init(const Ref<OcctlPrimPipeInfo>& info) { // NOLINT
    occtl_prim_pipe_info_t _info_val = {};
    ::occtl_prim_pipe_info_init(&_info_val);
    ::occtl_prim_pipe_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSweep::make_pipe(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimPipeInfo>& info, const Ref<OcctlNodeId>& out_shape) { // NOLINT
    occtl_prim_pipe_info_t _info_c = {};
    const occtl_prim_pipe_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_shape_val = {};
    occtl_status_t _status = ::occtl_prim_make_pipe(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_shape_val);
    if (out_shape.is_valid()) out_shape->copy_from_c(_out_shape_val);
    return static_cast<int>(_status);
}

void OcctlPrimSweep::loft_info_init(const Ref<OcctlPrimLoftInfo>& info) { // NOLINT
    occtl_prim_loft_info_t _info_val = {};
    ::occtl_prim_loft_info_init(&_info_val);
    ::occtl_prim_loft_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSweep::make_loft(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimLoftInfo>& info, const Ref<OcctlNodeId>& out_shape) { // NOLINT
    occtl_prim_loft_info_t _info_c = {};
    const occtl_prim_loft_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_shape_val = {};
    occtl_status_t _status = ::occtl_prim_make_loft(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_shape_val);
    if (out_shape.is_valid()) out_shape->copy_from_c(_out_shape_val);
    return static_cast<int>(_status);
}

void OcctlPrimSweep::pipe_shell_info_init(const Ref<OcctlPrimPipeShellInfo>& info) { // NOLINT
    occtl_prim_pipe_shell_info_t _info_val = {};
    ::occtl_prim_pipe_shell_info_init(&_info_val);
    ::occtl_prim_pipe_shell_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSweep::make_pipe_shell(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimPipeShellInfo>& info, const Ref<OcctlNodeId>& out_shape) { // NOLINT
    occtl_prim_pipe_shell_info_t _info_c = {};
    const occtl_prim_pipe_shell_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_shape_val = {};
    occtl_status_t _status = ::occtl_prim_make_pipe_shell(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_shape_val);
    if (out_shape.is_valid()) out_shape->copy_from_c(_out_shape_val);
    return static_cast<int>(_status);
}

void OcctlPrimSweep::pipe_shell_linear_law_info_init(const Ref<OcctlPrimPipeShellLinearLawInfo>& info) { // NOLINT
    occtl_prim_pipe_shell_linear_law_info_t _info_val = {};
    ::occtl_prim_pipe_shell_linear_law_info_init(&_info_val);
    ::occtl_prim_pipe_shell_linear_law_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSweep::make_pipe_shell_linear_law(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimPipeShellLinearLawInfo>& info, const Ref<OcctlNodeId>& out_shape) { // NOLINT
    occtl_prim_pipe_shell_linear_law_info_t _info_c = {};
    const occtl_prim_pipe_shell_linear_law_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_shape_val = {};
    occtl_status_t _status = ::occtl_prim_make_pipe_shell_linear_law(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_shape_val);
    if (out_shape.is_valid()) out_shape->copy_from_c(_out_shape_val);
    return static_cast<int>(_status);
}

void OcctlPrimSweep::pipe_shell_interpolated_law_info_init(const Ref<OcctlPrimPipeShellInterpolatedLawInfo>& info) { // NOLINT
    occtl_prim_pipe_shell_interpolated_law_info_t _info_val = {};
    ::occtl_prim_pipe_shell_interpolated_law_info_init(&_info_val);
    ::occtl_prim_pipe_shell_interpolated_law_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSweep::make_pipe_shell_interpolated_law(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimPipeShellInterpolatedLawInfo>& info, const Ref<OcctlNodeId>& out_shape) { // NOLINT
    occtl_prim_pipe_shell_interpolated_law_info_t _info_c = {};
    const occtl_prim_pipe_shell_interpolated_law_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_shape_val = {};
    occtl_status_t _status = ::occtl_prim_make_pipe_shell_interpolated_law(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_shape_val);
    if (out_shape.is_valid()) out_shape->copy_from_c(_out_shape_val);
    return static_cast<int>(_status);
}

void OcctlPrimSweep::offset_shape_info_init(const Ref<OcctlPrimOffsetShapeInfo>& info) { // NOLINT
    occtl_prim_offset_shape_info_t _info_val = {};
    ::occtl_prim_offset_shape_info_init(&_info_val);
    ::occtl_prim_offset_shape_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSweep::make_offset_shape(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimOffsetShapeInfo>& info, const Ref<OcctlNodeId>& out_shape) { // NOLINT
    occtl_prim_offset_shape_info_t _info_c = {};
    const occtl_prim_offset_shape_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_shape_val = {};
    occtl_status_t _status = ::occtl_prim_make_offset_shape(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_shape_val);
    if (out_shape.is_valid()) out_shape->copy_from_c(_out_shape_val);
    return static_cast<int>(_status);
}

void OcctlPrimSweep::thick_solid_info_init(const Ref<OcctlPrimThickSolidInfo>& info) { // NOLINT
    occtl_prim_thick_solid_info_t _info_val = {};
    ::occtl_prim_thick_solid_info_init(&_info_val);
    ::occtl_prim_thick_solid_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

int OcctlPrimSweep::make_thick_solid(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlPrimThickSolidInfo>& info, const Ref<OcctlNodeId>& out_solid) { // NOLINT
    occtl_prim_thick_solid_info_t _info_c = {};
    const occtl_prim_thick_solid_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_solid_val = {};
    occtl_status_t _status = ::occtl_prim_make_thick_solid(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_solid_val);
    if (out_solid.is_valid()) out_solid->copy_from_c(_out_solid_val);
    return static_cast<int>(_status);
}
