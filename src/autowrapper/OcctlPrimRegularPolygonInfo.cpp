#include "OcctlPrimRegularPolygonInfo.h"

#include "OcctlAxis2Placement.h"

int OcctlPrimRegularPolygonInfo::get_struct_version() const { return struct_version; }
void OcctlPrimRegularPolygonInfo::set_struct_version(int val) { struct_version = val; }

int64_t OcctlPrimRegularPolygonInfo::get_p_next() const { return p_next; }
void OcctlPrimRegularPolygonInfo::set_p_next(int64_t val) { p_next = val; }

Ref<OcctlAxis2Placement> OcctlPrimRegularPolygonInfo::get_placement() const { return placement; }
void OcctlPrimRegularPolygonInfo::set_placement(Ref<OcctlAxis2Placement> val) { placement = val; }

double OcctlPrimRegularPolygonInfo::get_circumradius() const { return circumradius; }
void OcctlPrimRegularPolygonInfo::set_circumradius(double val) { circumradius = val; }

int OcctlPrimRegularPolygonInfo::get_sides() const { return sides; }
void OcctlPrimRegularPolygonInfo::set_sides(int val) { sides = val; }

double OcctlPrimRegularPolygonInfo::get_rotation() const { return rotation; }
void OcctlPrimRegularPolygonInfo::set_rotation(double val) { rotation = val; }

void OcctlPrimRegularPolygonInfo::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlPrimRegularPolygonInfo::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlPrimRegularPolygonInfo::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlPrimRegularPolygonInfo::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlPrimRegularPolygonInfo::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_placement"), &OcctlPrimRegularPolygonInfo::get_placement);
    godot::ClassDB::bind_method(godot::D_METHOD("set_placement", "val"), &OcctlPrimRegularPolygonInfo::set_placement);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "placement"), "set_placement", "get_placement");
    godot::ClassDB::bind_method(godot::D_METHOD("get_circumradius"), &OcctlPrimRegularPolygonInfo::get_circumradius);
    godot::ClassDB::bind_method(godot::D_METHOD("set_circumradius", "val"), &OcctlPrimRegularPolygonInfo::set_circumradius);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "circumradius"), "set_circumradius", "get_circumradius");
    godot::ClassDB::bind_method(godot::D_METHOD("get_sides"), &OcctlPrimRegularPolygonInfo::get_sides);
    godot::ClassDB::bind_method(godot::D_METHOD("set_sides", "val"), &OcctlPrimRegularPolygonInfo::set_sides);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "sides"), "set_sides", "get_sides");
    godot::ClassDB::bind_method(godot::D_METHOD("get_rotation"), &OcctlPrimRegularPolygonInfo::get_rotation);
    godot::ClassDB::bind_method(godot::D_METHOD("set_rotation", "val"), &OcctlPrimRegularPolygonInfo::set_rotation);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "rotation"), "set_rotation", "get_rotation");
}

occtl_prim_regular_polygon_info_t OcctlPrimRegularPolygonInfo::to_c() const {
    occtl_prim_regular_polygon_info_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.placement = placement->to_c();
    result.circumradius = circumradius;
    result.sides = sides;
    result.rotation = rotation;
    return result;
}

Ref<OcctlPrimRegularPolygonInfo> OcctlPrimRegularPolygonInfo::from_c(const occtl_prim_regular_polygon_info_t& val) {
    Ref<OcctlPrimRegularPolygonInfo> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->placement = OcctlAxis2Placement::from_c(val.placement);
    r->circumradius = val.circumradius;
    r->sides = val.sides;
    r->rotation = val.rotation;
    return r;
}

void OcctlPrimRegularPolygonInfo::copy_from_c(const occtl_prim_regular_polygon_info_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    placement = OcctlAxis2Placement::from_c(val.placement);
    circumradius = val.circumradius;
    sides = val.sides;
    rotation = val.rotation;
}
