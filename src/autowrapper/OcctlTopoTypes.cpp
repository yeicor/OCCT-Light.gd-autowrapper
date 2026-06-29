#include "OcctlTopoTypes.h"

#include "occtl/occtl_topo_types.h"

void OcctlTopoTypes::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("const_OCCTL_REF_UID_WIRE_SIZE"), &OcctlTopoTypes::const_OCCTL_REF_UID_WIRE_SIZE);
    godot::ClassDB::bind_method(godot::D_METHOD("const_OCCTL_REP_UID_WIRE_SIZE"), &OcctlTopoTypes::const_OCCTL_REP_UID_WIRE_SIZE);
}

int64_t OcctlTopoTypes::const_OCCTL_REF_UID_WIRE_SIZE() { // NOLINT
    return OCCTL_UID_WIRE_SIZE;
}

int64_t OcctlTopoTypes::const_OCCTL_REP_UID_WIRE_SIZE() { // NOLINT
    return OCCTL_UID_WIRE_SIZE;
}
