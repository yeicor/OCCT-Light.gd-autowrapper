#include "OcctlPrimConstrainedEdgeInfo.h"

#include "OcctlRepId.h"
#include "OcctlAxis2Placement.h"

int OcctlPrimConstrainedEdgeInfo::get_struct_version() const { return struct_version; }
void OcctlPrimConstrainedEdgeInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimConstrainedEdgeInfo::get_p_next() const { return p_next; }
void OcctlPrimConstrainedEdgeInfo::set_p_next(int64_t val) { p_next = val; }

int64_t OcctlPrimConstrainedEdgeInfo::get_curve() const { return curve; }
void OcctlPrimConstrainedEdgeInfo::set_curve(int64_t val) { curve = val; }

Ref<OcctlAxis2Placement> OcctlPrimConstrainedEdgeInfo::get_placement() const { return placement; }
void OcctlPrimConstrainedEdgeInfo::set_placement(Ref<OcctlAxis2Placement> val) { placement = val; }

int OcctlPrimConstrainedEdgeInfo::get_use_parameter_range() const { return use_parameter_range; }
void OcctlPrimConstrainedEdgeInfo::set_use_parameter_range(int val) { use_parameter_range = val; }

double OcctlPrimConstrainedEdgeInfo::get_first_parameter() const { return first_parameter; }
void OcctlPrimConstrainedEdgeInfo::set_first_parameter(double val) { first_parameter = val; }

double OcctlPrimConstrainedEdgeInfo::get_last_parameter() const { return last_parameter; }
void OcctlPrimConstrainedEdgeInfo::set_last_parameter(double val) { last_parameter = val; }

void OcctlPrimConstrainedEdgeInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimConstrainedEdgeInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimConstrainedEdgeInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimConstrainedEdgeInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimConstrainedEdgeInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_curve"), &OcctlPrimConstrainedEdgeInfo::get_curve);
    godot::ClassDB::bind_method(godot::D_METHOD("set_curve", "val"), &OcctlPrimConstrainedEdgeInfo::set_curve);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "curve"), "set_curve", "get_curve");
    godot::ClassDB::bind_method(godot::D_METHOD("get_placement"), &OcctlPrimConstrainedEdgeInfo::get_placement);
    godot::ClassDB::bind_method(godot::D_METHOD("set_placement", "val"), &OcctlPrimConstrainedEdgeInfo::set_placement);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "placement"), "set_placement", "get_placement");
    godot::ClassDB::bind_method(godot::D_METHOD("get_use_parameter_range"), &OcctlPrimConstrainedEdgeInfo::get_use_parameter_range);
    godot::ClassDB::bind_method(godot::D_METHOD("set_use_parameter_range", "val"), &OcctlPrimConstrainedEdgeInfo::set_use_parameter_range);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "use_parameter_range"), "set_use_parameter_range", "get_use_parameter_range");
    godot::ClassDB::bind_method(godot::D_METHOD("get_first_parameter"), &OcctlPrimConstrainedEdgeInfo::get_first_parameter);
    godot::ClassDB::bind_method(godot::D_METHOD("set_first_parameter", "val"), &OcctlPrimConstrainedEdgeInfo::set_first_parameter);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "first_parameter"), "set_first_parameter", "get_first_parameter");
    godot::ClassDB::bind_method(godot::D_METHOD("get_last_parameter"), &OcctlPrimConstrainedEdgeInfo::get_last_parameter);
    godot::ClassDB::bind_method(godot::D_METHOD("set_last_parameter", "val"), &OcctlPrimConstrainedEdgeInfo::set_last_parameter);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "last_parameter"), "set_last_parameter", "get_last_parameter");
}

occtl_prim_constrained_edge_info_t OcctlPrimConstrainedEdgeInfo::to_c() const {
    occtl_prim_constrained_edge_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.curve.bits = static_cast<uint64_t>(curve);
    result.placement = placement->to_c();
    result.use_parameter_range = use_parameter_range;
    result.first_parameter = first_parameter;
    result.last_parameter = last_parameter;
    return result;
}

Ref<OcctlPrimConstrainedEdgeInfo> OcctlPrimConstrainedEdgeInfo::from_c(const occtl_prim_constrained_edge_info_t& val) {
    Ref<OcctlPrimConstrainedEdgeInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->curve = static_cast<int64_t>(val.curve.bits);
    r->placement = OcctlAxis2Placement::from_c(val.placement);
    r->use_parameter_range = val.use_parameter_range;
    r->first_parameter = val.first_parameter;
    r->last_parameter = val.last_parameter;
    return r;
}

void OcctlPrimConstrainedEdgeInfo::copy_from_c(const occtl_prim_constrained_edge_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    curve = static_cast<int64_t>(val.curve.bits);
    placement = OcctlAxis2Placement::from_c(val.placement);
    use_parameter_range = val.use_parameter_range;
    first_parameter = val.first_parameter;
    last_parameter = val.last_parameter;
}
