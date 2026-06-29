#include "OcctlTopoFillingPatchEdge.h"

#include "OcctlNodeId.h"

int64_t OcctlTopoFillingPatchEdge::get_edge() const { return edge; }
void OcctlTopoFillingPatchEdge::set_edge(int64_t val) { edge = val; }

int64_t OcctlTopoFillingPatchEdge::get_support_face() const { return support_face; }
void OcctlTopoFillingPatchEdge::set_support_face(int64_t val) { support_face = val; }

int OcctlTopoFillingPatchEdge::get_continuity() const { return continuity; }
void OcctlTopoFillingPatchEdge::set_continuity(int val) { continuity = val; }

int OcctlTopoFillingPatchEdge::get_is_boundary() const { return is_boundary; }
void OcctlTopoFillingPatchEdge::set_is_boundary(int val) { is_boundary = val; }

void OcctlTopoFillingPatchEdge::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_edge"), &OcctlTopoFillingPatchEdge::get_edge);
    godot::ClassDB::bind_method(godot::D_METHOD("set_edge", "val"), &OcctlTopoFillingPatchEdge::set_edge);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "edge"), "set_edge", "get_edge");
    godot::ClassDB::bind_method(godot::D_METHOD("get_support_face"), &OcctlTopoFillingPatchEdge::get_support_face);
    godot::ClassDB::bind_method(godot::D_METHOD("set_support_face", "val"), &OcctlTopoFillingPatchEdge::set_support_face);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "support_face"), "set_support_face", "get_support_face");
    godot::ClassDB::bind_method(godot::D_METHOD("get_continuity"), &OcctlTopoFillingPatchEdge::get_continuity);
    godot::ClassDB::bind_method(godot::D_METHOD("set_continuity", "val"), &OcctlTopoFillingPatchEdge::set_continuity);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "continuity"), "set_continuity", "get_continuity");
    godot::ClassDB::bind_method(godot::D_METHOD("get_is_boundary"), &OcctlTopoFillingPatchEdge::get_is_boundary);
    godot::ClassDB::bind_method(godot::D_METHOD("set_is_boundary", "val"), &OcctlTopoFillingPatchEdge::set_is_boundary);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "is_boundary"), "set_is_boundary", "get_is_boundary");
}

occtl_topo_filling_patch_edge_t OcctlTopoFillingPatchEdge::to_c() const {
    occtl_topo_filling_patch_edge_t result = {};
    result.edge.bits = static_cast<uint64_t>(edge);
    result.support_face.bits = static_cast<uint64_t>(support_face);
    result.continuity = static_cast<occtl_topo_filling_continuity_t>(continuity);
    result.is_boundary = is_boundary;
    return result;
}

Ref<OcctlTopoFillingPatchEdge> OcctlTopoFillingPatchEdge::from_c(const occtl_topo_filling_patch_edge_t& val) {
    Ref<OcctlTopoFillingPatchEdge> r;
    r.instantiate();
    r->edge = static_cast<int64_t>(val.edge.bits);
    r->support_face = static_cast<int64_t>(val.support_face.bits);
    r->continuity = static_cast<int>(val.continuity);
    r->is_boundary = val.is_boundary;
    return r;
}

void OcctlTopoFillingPatchEdge::copy_from_c(const occtl_topo_filling_patch_edge_t& val) {
    edge = static_cast<int64_t>(val.edge.bits);
    support_face = static_cast<int64_t>(val.support_face.bits);
    continuity = static_cast<int>(val.continuity);
    is_boundary = val.is_boundary;
}
