class_name TestOcctlCurves

var _w: OcctlCurves

func _init() -> void:
    self._w = OcctlCurves.new()

static func test_OCCTL_CURVE_BSPLINE_CREATE_INFO_VERSION_1() -> String:
    var v = OcctlCurves.OCCTL_CURVE_BSPLINE_CREATE_INFO_VERSION_1
    return ""

static func test_OCCTL_CURVE_BEZIER_CREATE_INFO_VERSION_1() -> String:
    var v = OcctlCurves.OCCTL_CURVE_BEZIER_CREATE_INFO_VERSION_1
    return ""

static func test_OCCTL_CURVE_OFFSET_CREATE_INFO_VERSION_1() -> String:
    var v = OcctlCurves.OCCTL_CURVE_OFFSET_CREATE_INFO_VERSION_1
    return ""

static func test_OCCTL_CURVE_BSPLINE_VERSION_1() -> String:
    var v = OcctlCurves.OCCTL_CURVE_BSPLINE_VERSION_1
    return ""

static func test_OCCTL_CURVE_AIRFOIL_NACA4_INFO_VERSION_1() -> String:
    var v = OcctlCurves.OCCTL_CURVE_AIRFOIL_NACA4_INFO_VERSION_1
    return ""

static func test_OCCTL_CURVE_INTERPOLATED_INFO_VERSION_1() -> String:
    var v = OcctlCurves.OCCTL_CURVE_INTERPOLATED_INFO_VERSION_1
    return ""

static func test_OCCTL_CURVE_APPROXIMATED_INFO_VERSION_1() -> String:
    var v = OcctlCurves.OCCTL_CURVE_APPROXIMATED_INFO_VERSION_1
    return ""
