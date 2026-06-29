class_name TestOcctlGeom

var _w: OcctlGeom

func _init() -> void:
    self._w = OcctlGeom.new()

static func test_OCCTL_GEOM_CONTINUITY_C0() -> String:
    var v = OcctlGeom.OCCTL_GEOM_CONTINUITY_C0
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_GEOM_CONTINUITY_G1() -> String:
    var v = OcctlGeom.OCCTL_GEOM_CONTINUITY_G1
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_GEOM_CONTINUITY_C1() -> String:
    var v = OcctlGeom.OCCTL_GEOM_CONTINUITY_C1
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_GEOM_CONTINUITY_G2() -> String:
    var v = OcctlGeom.OCCTL_GEOM_CONTINUITY_G2
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_GEOM_CONTINUITY_C2() -> String:
    var v = OcctlGeom.OCCTL_GEOM_CONTINUITY_C2
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_GEOM_CONTINUITY_C3() -> String:
    var v = OcctlGeom.OCCTL_GEOM_CONTINUITY_C3
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_GEOM_CONTINUITY_CN() -> String:
    var v = OcctlGeom.OCCTL_GEOM_CONTINUITY_CN
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_GEOM_CONTINUITY_RESERVED_FUTURE() -> String:
    var v = OcctlGeom.OCCTL_GEOM_CONTINUITY_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""
