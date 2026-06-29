class_name TestOcctlPrimFeature

var _w: OcctlPrimFeature

func _init() -> void:
    self._w = OcctlPrimFeature.new()

static func test_OCCTL_PRIM_FACE_FROM_SURFACE_OPTIONS_VERSION_1() -> String:
    var v = OcctlPrimFeature.OCCTL_PRIM_FACE_FROM_SURFACE_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_PRIM_FACE_FROM_POINT_GRID_OPTIONS_VERSION_1() -> String:
    var v = OcctlPrimFeature.OCCTL_PRIM_FACE_FROM_POINT_GRID_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_PRIM_FACE_FROM_BOUNDARY_CURVES_OPTIONS_VERSION_1() -> String:
    var v = OcctlPrimFeature.OCCTL_PRIM_FACE_FROM_BOUNDARY_CURVES_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_PRIM_FACE_FROM_CURVE_GRID_OPTIONS_VERSION_1() -> String:
    var v = OcctlPrimFeature.OCCTL_PRIM_FACE_FROM_CURVE_GRID_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_PRIM_BRAKE_FORMED_OPTIONS_VERSION_1() -> String:
    var v = OcctlPrimFeature.OCCTL_PRIM_BRAKE_FORMED_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_PRIM_DRAFT_PRISM_INFO_VERSION_1() -> String:
    var v = OcctlPrimFeature.OCCTL_PRIM_DRAFT_PRISM_INFO_VERSION_1
    return ""

static func test_OCCTL_PRIM_EXTRUDE_TAPERED_INFO_VERSION_1() -> String:
    var v = OcctlPrimFeature.OCCTL_PRIM_EXTRUDE_TAPERED_INFO_VERSION_1
    return ""

static func test_OCCTL_PRIM_RULED_SURFACE_INFO_VERSION_1() -> String:
    var v = OcctlPrimFeature.OCCTL_PRIM_RULED_SURFACE_INFO_VERSION_1
    return ""

static func test_OCCTL_PRIM_FEAT_PRISM_INFO_VERSION_1() -> String:
    var v = OcctlPrimFeature.OCCTL_PRIM_FEAT_PRISM_INFO_VERSION_1
    return ""

static func test_OCCTL_PRIM_EXTRUDE_UNTIL_INFO_VERSION_1() -> String:
    var v = OcctlPrimFeature.OCCTL_PRIM_EXTRUDE_UNTIL_INFO_VERSION_1
    return ""

static func test_OCCTL_PRIM_FEAT_DRAFT_PRISM_INFO_VERSION_1() -> String:
    var v = OcctlPrimFeature.OCCTL_PRIM_FEAT_DRAFT_PRISM_INFO_VERSION_1
    return ""

static func test_OCCTL_PRIM_CYLINDRICAL_HOLE_INFO_VERSION_1() -> String:
    var v = OcctlPrimFeature.OCCTL_PRIM_CYLINDRICAL_HOLE_INFO_VERSION_1
    return ""

static func test_OCCTL_PRIM_BRAKE_SIDE_LEFT() -> String:
    var v = OcctlPrimFeature.OCCTL_PRIM_BRAKE_SIDE_LEFT
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_PRIM_BRAKE_SIDE_RIGHT() -> String:
    var v = OcctlPrimFeature.OCCTL_PRIM_BRAKE_SIDE_RIGHT
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_PRIM_BRAKE_SIDE_RESERVED_FUTURE() -> String:
    var v = OcctlPrimFeature.OCCTL_PRIM_BRAKE_SIDE_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_UNTIL_LENGTH() -> String:
    var v = OcctlPrimFeature.OCCTL_UNTIL_LENGTH
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_UNTIL_SHAPE() -> String:
    var v = OcctlPrimFeature.OCCTL_UNTIL_SHAPE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_UNTIL_THRU_ALL() -> String:
    var v = OcctlPrimFeature.OCCTL_UNTIL_THRU_ALL
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_UNTIL_HEIGHT() -> String:
    var v = OcctlPrimFeature.OCCTL_UNTIL_HEIGHT
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_UNTIL_RESERVED_FUTURE() -> String:
    var v = OcctlPrimFeature.OCCTL_UNTIL_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_FEAT_SEPARATE() -> String:
    var v = OcctlPrimFeature.OCCTL_FEAT_SEPARATE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_FEAT_CUT() -> String:
    var v = OcctlPrimFeature.OCCTL_FEAT_CUT
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_FEAT_FUSE() -> String:
    var v = OcctlPrimFeature.OCCTL_FEAT_FUSE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_FEAT_COMBINE_RESERVED_FUTURE() -> String:
    var v = OcctlPrimFeature.OCCTL_FEAT_COMBINE_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_EXTRUDE_UNTIL_NEXT() -> String:
    var v = OcctlPrimFeature.OCCTL_EXTRUDE_UNTIL_NEXT
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_EXTRUDE_UNTIL_LAST() -> String:
    var v = OcctlPrimFeature.OCCTL_EXTRUDE_UNTIL_LAST
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_EXTRUDE_UNTIL_PREVIOUS() -> String:
    var v = OcctlPrimFeature.OCCTL_EXTRUDE_UNTIL_PREVIOUS
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_EXTRUDE_UNTIL_FIRST() -> String:
    var v = OcctlPrimFeature.OCCTL_EXTRUDE_UNTIL_FIRST
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_EXTRUDE_UNTIL_RESERVED_FUTURE() -> String:
    var v = OcctlPrimFeature.OCCTL_EXTRUDE_UNTIL_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_CYLINDRICAL_HOLE_THROUGH_ALL() -> String:
    var v = OcctlPrimFeature.OCCTL_CYLINDRICAL_HOLE_THROUGH_ALL
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_CYLINDRICAL_HOLE_BETWEEN_PARAMS() -> String:
    var v = OcctlPrimFeature.OCCTL_CYLINDRICAL_HOLE_BETWEEN_PARAMS
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_CYLINDRICAL_HOLE_THRU_NEXT() -> String:
    var v = OcctlPrimFeature.OCCTL_CYLINDRICAL_HOLE_THRU_NEXT
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_CYLINDRICAL_HOLE_UNTIL_END() -> String:
    var v = OcctlPrimFeature.OCCTL_CYLINDRICAL_HOLE_UNTIL_END
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_CYLINDRICAL_HOLE_BLIND() -> String:
    var v = OcctlPrimFeature.OCCTL_CYLINDRICAL_HOLE_BLIND
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_CYLINDRICAL_HOLE_RESERVED_FUTURE() -> String:
    var v = OcctlPrimFeature.OCCTL_CYLINDRICAL_HOLE_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""
