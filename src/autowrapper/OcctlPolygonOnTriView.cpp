#include "OcctlPolygonOnTriView.h"

#include "OcctlUid.h"

PackedInt32Array OcctlPolygonOnTriView::get_node_indices() const { return node_indices; }
void OcctlPolygonOnTriView::set_node_indices(PackedInt32Array val) { node_indices = val; }

int OcctlPolygonOnTriView::get_node_count() const { return node_count; }
void OcctlPolygonOnTriView::set_node_count(int val) { node_count = val; }

PackedFloat64Array OcctlPolygonOnTriView::get_parameters() const { return parameters; }
void OcctlPolygonOnTriView::set_parameters(PackedFloat64Array val) { parameters = val; }

double OcctlPolygonOnTriView::get_deflection() const { return deflection; }
void OcctlPolygonOnTriView::set_deflection(double val) { deflection = val; }

int64_t OcctlPolygonOnTriView::get_source_uid() const { return source_uid; }
void OcctlPolygonOnTriView::set_source_uid(int64_t val) { source_uid = val; }

void OcctlPolygonOnTriView::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_node_indices"), &OcctlPolygonOnTriView::get_node_indices);
    godot::ClassDB::bind_method(godot::D_METHOD("set_node_indices", "val"), &OcctlPolygonOnTriView::set_node_indices);
    ADD_PROPERTY(PropertyInfo(Variant::NIL, "node_indices"), "set_node_indices", "get_node_indices");
    godot::ClassDB::bind_method(godot::D_METHOD("get_node_count"), &OcctlPolygonOnTriView::get_node_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_node_count", "val"), &OcctlPolygonOnTriView::set_node_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "node_count"), "set_node_count", "get_node_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_parameters"), &OcctlPolygonOnTriView::get_parameters);
    godot::ClassDB::bind_method(godot::D_METHOD("set_parameters", "val"), &OcctlPolygonOnTriView::set_parameters);
    ADD_PROPERTY(PropertyInfo(Variant::PACKED_FLOAT64_ARRAY, "parameters"), "set_parameters", "get_parameters");
    godot::ClassDB::bind_method(godot::D_METHOD("get_deflection"), &OcctlPolygonOnTriView::get_deflection);
    godot::ClassDB::bind_method(godot::D_METHOD("set_deflection", "val"), &OcctlPolygonOnTriView::set_deflection);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "deflection"), "set_deflection", "get_deflection");
    godot::ClassDB::bind_method(godot::D_METHOD("get_source_uid"), &OcctlPolygonOnTriView::get_source_uid);
    godot::ClassDB::bind_method(godot::D_METHOD("set_source_uid", "val"), &OcctlPolygonOnTriView::set_source_uid);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "source_uid"), "set_source_uid", "get_source_uid");
}

occtl_polygon_on_tri_view_t OcctlPolygonOnTriView::to_c() const {
    occtl_polygon_on_tri_view_t result = {};
    result.node_indices = reinterpret_cast<const uint32_t*>(node_indices.ptr());
    result.node_count = node_count;
    result.parameters = parameters.ptr();
    result.deflection = deflection;
    result.source_uid.bits = static_cast<uint64_t>(source_uid);
    return result;
}

Ref<OcctlPolygonOnTriView> OcctlPolygonOnTriView::from_c(const occtl_polygon_on_tri_view_t& val) {
    Ref<OcctlPolygonOnTriView> r;
    r.instantiate();
    // array field node_indices is not populated from C
    r->node_count = val.node_count;
    // array field parameters is not populated from C
    r->deflection = val.deflection;
    r->source_uid = static_cast<int64_t>(val.source_uid.bits);
    return r;
}

void OcctlPolygonOnTriView::copy_from_c(const occtl_polygon_on_tri_view_t& val) {
    // array field node_indices is not populated from C
    node_count = val.node_count;
    // array field parameters is not populated from C
    deflection = val.deflection;
    source_uid = static_cast<int64_t>(val.source_uid.bits);
}
