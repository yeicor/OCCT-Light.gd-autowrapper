#include "OcctlTopoCheckIssue.h"

#include "OcctlNodeId.h"

int64_t OcctlTopoCheckIssue::get_node_id() const { return node_id; }
void OcctlTopoCheckIssue::set_node_id(int64_t val) { node_id = val; }

int64_t OcctlTopoCheckIssue::get_context_node_id() const { return context_node_id; }
void OcctlTopoCheckIssue::set_context_node_id(int64_t val) { context_node_id = val; }

int OcctlTopoCheckIssue::get_status_bit() const { return status_bit; }
void OcctlTopoCheckIssue::set_status_bit(int val) { status_bit = val; }

int OcctlTopoCheckIssue::get_severity() const { return severity; }
void OcctlTopoCheckIssue::set_severity(int val) { severity = val; }

void OcctlTopoCheckIssue::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_node_id"), &OcctlTopoCheckIssue::get_node_id);
    godot::ClassDB::bind_method(godot::D_METHOD("set_node_id", "val"), &OcctlTopoCheckIssue::set_node_id);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "node_id"), "set_node_id", "get_node_id");
    godot::ClassDB::bind_method(godot::D_METHOD("get_context_node_id"), &OcctlTopoCheckIssue::get_context_node_id);
    godot::ClassDB::bind_method(godot::D_METHOD("set_context_node_id", "val"), &OcctlTopoCheckIssue::set_context_node_id);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "context_node_id"), "set_context_node_id", "get_context_node_id");
    godot::ClassDB::bind_method(godot::D_METHOD("get_status_bit"), &OcctlTopoCheckIssue::get_status_bit);
    godot::ClassDB::bind_method(godot::D_METHOD("set_status_bit", "val"), &OcctlTopoCheckIssue::set_status_bit);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "status_bit"), "set_status_bit", "get_status_bit");
    godot::ClassDB::bind_method(godot::D_METHOD("get_severity"), &OcctlTopoCheckIssue::get_severity);
    godot::ClassDB::bind_method(godot::D_METHOD("set_severity", "val"), &OcctlTopoCheckIssue::set_severity);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "severity"), "set_severity", "get_severity");
}

occtl_topo_check_issue_t OcctlTopoCheckIssue::to_c() const {
    occtl_topo_check_issue_t result = {};
    result.node_id.bits = static_cast<uint64_t>(node_id);
    result.context_node_id.bits = static_cast<uint64_t>(context_node_id);
    result.status_bit = status_bit;
    result.severity = static_cast<occtl_topo_check_severity_t>(severity);
    return result;
}

Ref<OcctlTopoCheckIssue> OcctlTopoCheckIssue::from_c(const occtl_topo_check_issue_t& val) {
    Ref<OcctlTopoCheckIssue> r;
    r.instantiate();
    r->node_id = static_cast<int64_t>(val.node_id.bits);
    r->context_node_id = static_cast<int64_t>(val.context_node_id.bits);
    r->status_bit = val.status_bit;
    r->severity = static_cast<int>(val.severity);
    return r;
}

void OcctlTopoCheckIssue::copy_from_c(const occtl_topo_check_issue_t& val) {
    node_id = static_cast<int64_t>(val.node_id.bits);
    context_node_id = static_cast<int64_t>(val.context_node_id.bits);
    status_bit = val.status_bit;
    severity = static_cast<int>(val.severity);
}
