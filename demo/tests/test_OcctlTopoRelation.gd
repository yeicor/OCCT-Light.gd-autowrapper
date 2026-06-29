class_name TestOcctlTopoRelation

var _w: OcctlTopoRelation

func _init() -> void:
    self._w = OcctlTopoRelation.new()

static func test_OCCTL_TOPO_CHILD_EXPLORER_CONFIG_VERSION_1() -> String:
    var v = OcctlTopoRelation.OCCTL_TOPO_CHILD_EXPLORER_CONFIG_VERSION_1
    return ""

static func test_OCCTL_TOPO_PARENT_EXPLORER_CONFIG_VERSION_1() -> String:
    var v = OcctlTopoRelation.OCCTL_TOPO_PARENT_EXPLORER_CONFIG_VERSION_1
    return ""

static func test_OCCTL_TOPO_RELATION_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoRelation.OCCTL_TOPO_RELATION_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_CONTINUITY_C0() -> String:
    var v = OcctlTopoRelation.OCCTL_CONTINUITY_C0
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_CONTINUITY_C1() -> String:
    var v = OcctlTopoRelation.OCCTL_CONTINUITY_C1
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_CONTINUITY_C2() -> String:
    var v = OcctlTopoRelation.OCCTL_CONTINUITY_C2
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_CONTINUITY_C3() -> String:
    var v = OcctlTopoRelation.OCCTL_CONTINUITY_C3
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_CONTINUITY_CN() -> String:
    var v = OcctlTopoRelation.OCCTL_CONTINUITY_CN
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_CONTINUITY_G1() -> String:
    var v = OcctlTopoRelation.OCCTL_CONTINUITY_G1
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_CONTINUITY_G2() -> String:
    var v = OcctlTopoRelation.OCCTL_CONTINUITY_G2
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_CONTINUITY_RESERVED_FUTURE() -> String:
    var v = OcctlTopoRelation.OCCTL_CONTINUITY_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_ORIENTATION_FORWARD() -> String:
    var v = OcctlTopoRelation.OCCTL_ORIENTATION_FORWARD
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_ORIENTATION_REVERSED() -> String:
    var v = OcctlTopoRelation.OCCTL_ORIENTATION_REVERSED
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_ORIENTATION_INTERNAL() -> String:
    var v = OcctlTopoRelation.OCCTL_ORIENTATION_INTERNAL
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_ORIENTATION_EXTERNAL() -> String:
    var v = OcctlTopoRelation.OCCTL_ORIENTATION_EXTERNAL
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_ORIENTATION_RESERVED_FUTURE() -> String:
    var v = OcctlTopoRelation.OCCTL_ORIENTATION_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TOPO_EXPLORER_RECURSIVE() -> String:
    var v = OcctlTopoRelation.OCCTL_TOPO_EXPLORER_RECURSIVE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TOPO_EXPLORER_DIRECT_CHILDREN() -> String:
    var v = OcctlTopoRelation.OCCTL_TOPO_EXPLORER_DIRECT_CHILDREN
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TOPO_EXPLORER_TRAVERSAL_RESERVED_FUTURE() -> String:
    var v = OcctlTopoRelation.OCCTL_TOPO_EXPLORER_TRAVERSAL_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_RELATION_BOUNDARY_EDGE() -> String:
    var v = OcctlTopoRelation.OCCTL_RELATION_BOUNDARY_EDGE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_RELATION_ADJACENT_FACE() -> String:
    var v = OcctlTopoRelation.OCCTL_RELATION_ADJACENT_FACE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_RELATION_OUTER_WIRE() -> String:
    var v = OcctlTopoRelation.OCCTL_RELATION_OUTER_WIRE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_RELATION_REFERENCED_BY() -> String:
    var v = OcctlTopoRelation.OCCTL_RELATION_REFERENCED_BY
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_RELATION_INCIDENT_VERTEX() -> String:
    var v = OcctlTopoRelation.OCCTL_RELATION_INCIDENT_VERTEX
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_RELATION_WIRE_COEDGE() -> String:
    var v = OcctlTopoRelation.OCCTL_RELATION_WIRE_COEDGE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_RELATION_OWNING_FACE() -> String:
    var v = OcctlTopoRelation.OCCTL_RELATION_OWNING_FACE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_RELATION_INCIDENT_EDGE() -> String:
    var v = OcctlTopoRelation.OCCTL_RELATION_INCIDENT_EDGE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_RELATION_PARENT_EDGE() -> String:
    var v = OcctlTopoRelation.OCCTL_RELATION_PARENT_EDGE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_RELATION_SEAM_PAIR() -> String:
    var v = OcctlTopoRelation.OCCTL_RELATION_SEAM_PAIR
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_RELATION_KIND_RESERVED_FUTURE() -> String:
    var v = OcctlTopoRelation.OCCTL_RELATION_KIND_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TOPO_POINT_CLASS_IN() -> String:
    var v = OcctlTopoRelation.OCCTL_TOPO_POINT_CLASS_IN
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TOPO_POINT_CLASS_OUT() -> String:
    var v = OcctlTopoRelation.OCCTL_TOPO_POINT_CLASS_OUT
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TOPO_POINT_CLASS_ON() -> String:
    var v = OcctlTopoRelation.OCCTL_TOPO_POINT_CLASS_ON
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TOPO_POINT_CLASS_UNKNOWN() -> String:
    var v = OcctlTopoRelation.OCCTL_TOPO_POINT_CLASS_UNKNOWN
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TOPO_POINT_CLASS_RESERVED_FUTURE() -> String:
    var v = OcctlTopoRelation.OCCTL_TOPO_POINT_CLASS_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""
