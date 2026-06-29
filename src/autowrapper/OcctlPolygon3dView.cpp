#include "OcctlPolygon3dView.h"

#include "OcctlUid.h"

PackedFloat64Array OcctlPolygon3dView::get_nodes() const { return nodes; }
void OcctlPolygon3dView::set_nodes(PackedFloat64Array val) { nodes = val; }

int OcctlPolygon3dView::get_node_count() const { return node_count; }
void OcctlPolygon3dView::set_node_count(int val) { node_count = val; }

PackedFloat64Array OcctlPolygon3dView::get_parameters() const { return parameters; }
void OcctlPolygon3dView::set_parameters(PackedFloat64Array val) { parameters = val; }

double OcctlPolygon3dView::get_deflection() const { return deflection; }
void OcctlPolygon3dView::set_deflection(double val) { deflection = val; }

int64_t OcctlPolygon3dView::get_source_uid() const { return source_uid; }
void OcctlPolygon3dView::set_source_uid(int64_t val) { source_uid = val; }

void OcctlPolygon3dView::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_nodes"), &OcctlPolygon3dView::get_nodes);
    godot::ClassDB::bind_method(godot::D_METHOD("set_nodes", "val"), &OcctlPolygon3dView::set_nodes);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "nodes"), "set_nodes", "get_nodes");
    godot::ClassDB::bind_method(godot::D_METHOD("get_node_count"), &OcctlPolygon3dView::get_node_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_node_count", "val"), &OcctlPolygon3dView::set_node_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "node_count"), "set_node_count", "get_node_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_parameters"), &OcctlPolygon3dView::get_parameters);
    godot::ClassDB::bind_method(godot::D_METHOD("set_parameters", "val"), &OcctlPolygon3dView::set_parameters);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "parameters"), "set_parameters", "get_parameters");
    godot::ClassDB::bind_method(godot::D_METHOD("get_deflection"), &OcctlPolygon3dView::get_deflection);
    godot::ClassDB::bind_method(godot::D_METHOD("set_deflection", "val"), &OcctlPolygon3dView::set_deflection);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "deflection"), "set_deflection", "get_deflection");
    godot::ClassDB::bind_method(godot::D_METHOD("get_source_uid"), &OcctlPolygon3dView::get_source_uid);
    godot::ClassDB::bind_method(godot::D_METHOD("set_source_uid", "val"), &OcctlPolygon3dView::set_source_uid);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "source_uid"), "set_source_uid", "get_source_uid");
}

occtl_polygon3d_view_t OcctlPolygon3dView::to_c() const {
    occtl_polygon3d_view_t result = {};
    result.nodes = nodes.ptr();
    result.node_count = node_count;
    result.parameters = parameters.ptr();
    result.deflection = deflection;
    result.source_uid.bits = static_cast<uint64_t>(source_uid);
    return result;
}

Ref<OcctlPolygon3dView> OcctlPolygon3dView::from_c(const occtl_polygon3d_view_t& val) {
    Ref<OcctlPolygon3dView> r;
    r.instantiate();
    // array field nodes is not populated from C
    r->node_count = val.node_count;
    // array field parameters is not populated from C
    r->deflection = val.deflection;
    r->source_uid = static_cast<int64_t>(val.source_uid.bits);
    return r;
}

void OcctlPolygon3dView::copy_from_c(const occtl_polygon3d_view_t& val) {
    // array field nodes is not populated from C
    node_count = val.node_count;
    // array field parameters is not populated from C
    deflection = val.deflection;
    source_uid = static_cast<int64_t>(val.source_uid.bits);
}
