#include "OcctlTopoCircularPatternOptions.h"

#include "OcctlAxis1Placement.h"

int OcctlTopoCircularPatternOptions::get_struct_version() const { return struct_version; }
void OcctlTopoCircularPatternOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoCircularPatternOptions::get_p_next() const { return p_next; }
void OcctlTopoCircularPatternOptions::set_p_next(int64_t val) { p_next = val; }

Ref<OcctlAxis1Placement> OcctlTopoCircularPatternOptions::get_axis() const { return axis; }
void OcctlTopoCircularPatternOptions::set_axis(Ref<OcctlAxis1Placement> val) { axis = val; }

int OcctlTopoCircularPatternOptions::get_count() const { return count; }
void OcctlTopoCircularPatternOptions::set_count(int val) { count = val; }

double OcctlTopoCircularPatternOptions::get_angle() const { return angle; }
void OcctlTopoCircularPatternOptions::set_angle(double val) { angle = val; }

void OcctlTopoCircularPatternOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoCircularPatternOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoCircularPatternOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoCircularPatternOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoCircularPatternOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_axis"), &OcctlTopoCircularPatternOptions::get_axis);
    godot::ClassDB::bind_method(godot::D_METHOD("set_axis", "val"), &OcctlTopoCircularPatternOptions::set_axis);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "axis"), "set_axis", "get_axis");
    godot::ClassDB::bind_method(godot::D_METHOD("get_count"), &OcctlTopoCircularPatternOptions::get_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_count", "val"), &OcctlTopoCircularPatternOptions::set_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "count"), "set_count", "get_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_angle"), &OcctlTopoCircularPatternOptions::get_angle);
    godot::ClassDB::bind_method(godot::D_METHOD("set_angle", "val"), &OcctlTopoCircularPatternOptions::set_angle);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "angle"), "set_angle", "get_angle");
}

occtl_topo_circular_pattern_options_t OcctlTopoCircularPatternOptions::to_c() const {
    occtl_topo_circular_pattern_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.axis = axis->to_c();
    result.count = count;
    result.angle = angle;
    return result;
}

Ref<OcctlTopoCircularPatternOptions> OcctlTopoCircularPatternOptions::from_c(const occtl_topo_circular_pattern_options_t& val) {
    Ref<OcctlTopoCircularPatternOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->axis = OcctlAxis1Placement::from_c(val.axis);
    r->count = val.count;
    r->angle = val.angle;
    return r;
}

void OcctlTopoCircularPatternOptions::copy_from_c(const occtl_topo_circular_pattern_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    axis = OcctlAxis1Placement::from_c(val.axis);
    count = val.count;
    angle = val.angle;
}
