class_name TestOcctlCurvesCommon

var _w: OcctlCurvesCommon

func _init() -> void:
    self._w = OcctlCurvesCommon.new()

static func test_OCCTL_CURVE_TRIMMED_CREATE_INFO_VERSION_1() -> String:
    var v = OcctlCurvesCommon.OCCTL_CURVE_TRIMMED_CREATE_INFO_VERSION_1
    return ""

static func test_OCCTL_CURVE_BEZIER_SEGMENTS_OPTIONS_VERSION_1() -> String:
    var v = OcctlCurvesCommon.OCCTL_CURVE_BEZIER_SEGMENTS_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_CURVE_KIND_LINE() -> String:
    var v = OcctlCurvesCommon.OCCTL_CURVE_KIND_LINE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_CURVE_KIND_CIRCLE() -> String:
    var v = OcctlCurvesCommon.OCCTL_CURVE_KIND_CIRCLE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_CURVE_KIND_ELLIPSE() -> String:
    var v = OcctlCurvesCommon.OCCTL_CURVE_KIND_ELLIPSE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_CURVE_KIND_HYPERBOLA() -> String:
    var v = OcctlCurvesCommon.OCCTL_CURVE_KIND_HYPERBOLA
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_CURVE_KIND_PARABOLA() -> String:
    var v = OcctlCurvesCommon.OCCTL_CURVE_KIND_PARABOLA
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_CURVE_KIND_BSPLINE() -> String:
    var v = OcctlCurvesCommon.OCCTL_CURVE_KIND_BSPLINE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_CURVE_KIND_BEZIER() -> String:
    var v = OcctlCurvesCommon.OCCTL_CURVE_KIND_BEZIER
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_CURVE_KIND_TRIMMED() -> String:
    var v = OcctlCurvesCommon.OCCTL_CURVE_KIND_TRIMMED
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_CURVE_KIND_OFFSET() -> String:
    var v = OcctlCurvesCommon.OCCTL_CURVE_KIND_OFFSET
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_CURVE_KIND_UNDEFINED() -> String:
    var v = OcctlCurvesCommon.OCCTL_CURVE_KIND_UNDEFINED
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_CURVE_KIND_RESERVED_FUTURE() -> String:
    var v = OcctlCurvesCommon.OCCTL_CURVE_KIND_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_GEOM_TANGENCY_UNQUALIFIED() -> String:
    var v = OcctlCurvesCommon.OCCTL_GEOM_TANGENCY_UNQUALIFIED
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_GEOM_TANGENCY_ENCLOSING() -> String:
    var v = OcctlCurvesCommon.OCCTL_GEOM_TANGENCY_ENCLOSING
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_GEOM_TANGENCY_ENCLOSED() -> String:
    var v = OcctlCurvesCommon.OCCTL_GEOM_TANGENCY_ENCLOSED
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_GEOM_TANGENCY_OUTSIDE() -> String:
    var v = OcctlCurvesCommon.OCCTL_GEOM_TANGENCY_OUTSIDE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_GEOM_TANGENCY_NO_QUALIFIER() -> String:
    var v = OcctlCurvesCommon.OCCTL_GEOM_TANGENCY_NO_QUALIFIER
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_GEOM_TANGENCY_RESERVED_FUTURE() -> String:
    var v = OcctlCurvesCommon.OCCTL_GEOM_TANGENCY_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""
