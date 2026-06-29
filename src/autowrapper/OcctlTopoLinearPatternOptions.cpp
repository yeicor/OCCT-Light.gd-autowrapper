#include "OcctlTopoLinearPatternOptions.h"

#include "OcctlVector3.h"

int OcctlTopoLinearPatternOptions::get_struct_version() const { return struct_version; }
void OcctlTopoLinearPatternOptions::set_struct_version(int val) { struct_version = val; }

int64_t OcctlTopoLinearPatternOptions::get_p_next() const { return p_next; }
void OcctlTopoLinearPatternOptions::set_p_next(int64_t val) { p_next = val; }

Ref<OcctlVector3> OcctlTopoLinearPatternOptions::get_direction() const { return direction; }
void OcctlTopoLinearPatternOptions::set_direction(Ref<OcctlVector3> val) { direction = val; }

int OcctlTopoLinearPatternOptions::get_count() const { return count; }
void OcctlTopoLinearPatternOptions::set_count(int val) { count = val; }

double OcctlTopoLinearPatternOptions::get_step() const { return step; }
void OcctlTopoLinearPatternOptions::set_step(double val) { step = val; }

void OcctlTopoLinearPatternOptions::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_struct_version"), &OcctlTopoLinearPatternOptions::get_struct_version);
    godot::ClassDB::bind_method(godot::D_METHOD("set_struct_version", "val"), &OcctlTopoLinearPatternOptions::set_struct_version);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "struct_version"), "set_struct_version", "get_struct_version");
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_next"), &OcctlTopoLinearPatternOptions::get_p_next);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_next", "val"), &OcctlTopoLinearPatternOptions::set_p_next);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "p_next"), "set_p_next", "get_p_next");
    godot::ClassDB::bind_method(godot::D_METHOD("get_direction"), &OcctlTopoLinearPatternOptions::get_direction);
    godot::ClassDB::bind_method(godot::D_METHOD("set_direction", "val"), &OcctlTopoLinearPatternOptions::set_direction);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "direction"), "set_direction", "get_direction");
    godot::ClassDB::bind_method(godot::D_METHOD("get_count"), &OcctlTopoLinearPatternOptions::get_count);
    godot::ClassDB::bind_method(godot::D_METHOD("set_count", "val"), &OcctlTopoLinearPatternOptions::set_count);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "count"), "set_count", "get_count");
    godot::ClassDB::bind_method(godot::D_METHOD("get_step"), &OcctlTopoLinearPatternOptions::get_step);
    godot::ClassDB::bind_method(godot::D_METHOD("set_step", "val"), &OcctlTopoLinearPatternOptions::set_step);
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "step"), "set_step", "get_step");
}

occtl_topo_linear_pattern_options_t OcctlTopoLinearPatternOptions::to_c() const {
    occtl_topo_linear_pattern_options_t result = {};
    result.struct_version = struct_version;
    result.p_next = nullptr;
    result.direction = direction->to_c();
    result.count = count;
    result.step = step;
    return result;
}

Ref<OcctlTopoLinearPatternOptions> OcctlTopoLinearPatternOptions::from_c(const occtl_topo_linear_pattern_options_t& val) {
    Ref<OcctlTopoLinearPatternOptions> r;
    r.instantiate();
    r->struct_version = val.struct_version;
    r->p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    r->direction = OcctlVector3::from_c(val.direction);
    r->count = val.count;
    r->step = val.step;
    return r;
}

void OcctlTopoLinearPatternOptions::copy_from_c(const occtl_topo_linear_pattern_options_t& val) {
    struct_version = val.struct_version;
    p_next = static_cast<int64_t>(reinterpret_cast<uintptr_t>(val.p_next));
    direction = OcctlVector3::from_c(val.direction);
    count = val.count;
    step = val.step;
}
