class_name TestOcctlSurfaces

var _w: OcctlSurfaces

func _init() -> void:
    self._w = OcctlSurfaces.new()

static func test_OCCTL_SURFACE_REVOLUTION_CREATE_INFO_VERSION_1() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_REVOLUTION_CREATE_INFO_VERSION_1
    return ""

static func test_OCCTL_SURFACE_EXTRUSION_CREATE_INFO_VERSION_1() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_EXTRUSION_CREATE_INFO_VERSION_1
    return ""

static func test_OCCTL_SURFACE_RECTANGULAR_TRIMMED_CREATE_INFO_VERSION_1() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_RECTANGULAR_TRIMMED_CREATE_INFO_VERSION_1
    return ""

static func test_OCCTL_SURFACE_OFFSET_CREATE_INFO_VERSION_1() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_OFFSET_CREATE_INFO_VERSION_1
    return ""

static func test_OCCTL_SURFACE_BSPLINE_CREATE_INFO_VERSION_1() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_BSPLINE_CREATE_INFO_VERSION_1
    return ""

static func test_OCCTL_SURFACE_BEZIER_CREATE_INFO_VERSION_1() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_BEZIER_CREATE_INFO_VERSION_1
    return ""

static func test_OCCTL_SURFACE_BSPLINE_VERSION_1() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_BSPLINE_VERSION_1
    return ""

static func test_OCCTL_SURFACE_INTERPOLATED_INFO_VERSION_1() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_INTERPOLATED_INFO_VERSION_1
    return ""

static func test_OCCTL_SURFACE_APPROXIMATED_INFO_VERSION_1() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_APPROXIMATED_INFO_VERSION_1
    return ""

static func test_OCCTL_SURFACE_POINT_GRID_CREATE_INFO_VERSION_1() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_POINT_GRID_CREATE_INFO_VERSION_1
    return ""

static func test_OCCTL_SURFACE_BOUNDARY_CURVES_CREATE_INFO_VERSION_1() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_BOUNDARY_CURVES_CREATE_INFO_VERSION_1
    return ""

static func test_OCCTL_SURFACE_GORDON_CREATE_INFO_VERSION_1() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_GORDON_CREATE_INFO_VERSION_1
    return ""

static func test_OCCTL_SURFACE_CURVE_GRID_CREATE_INFO_VERSION_1() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_CURVE_GRID_CREATE_INFO_VERSION_1
    return ""

static func test_OCCTL_SURFACE_KIND_PLANE() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_KIND_PLANE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SURFACE_KIND_CYLINDRICAL() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_KIND_CYLINDRICAL
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SURFACE_KIND_CONICAL() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_KIND_CONICAL
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SURFACE_KIND_SPHERICAL() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_KIND_SPHERICAL
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SURFACE_KIND_TOROIDAL() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_KIND_TOROIDAL
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SURFACE_KIND_BSPLINE() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_KIND_BSPLINE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SURFACE_KIND_BEZIER() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_KIND_BEZIER
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SURFACE_KIND_REVOLUTION() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_KIND_REVOLUTION
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SURFACE_KIND_EXTRUSION() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_KIND_EXTRUSION
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SURFACE_KIND_RECTANGULAR_TRIMMED() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_KIND_RECTANGULAR_TRIMMED
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SURFACE_KIND_OFFSET() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_KIND_OFFSET
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SURFACE_KIND_UNDEFINED() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_KIND_UNDEFINED
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SURFACE_KIND_RESERVED_FUTURE() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_KIND_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SURFACE_POINT_GRID_MODE_APPROXIMATE() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_POINT_GRID_MODE_APPROXIMATE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SURFACE_POINT_GRID_MODE_INTERPOLATE() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_POINT_GRID_MODE_INTERPOLATE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SURFACE_POINT_GRID_MODE_RESERVED_FUTURE() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_POINT_GRID_MODE_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SURFACE_FILLING_STRETCH() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_FILLING_STRETCH
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SURFACE_FILLING_COONS() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_FILLING_COONS
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SURFACE_FILLING_CURVED() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_FILLING_CURVED
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SURFACE_FILLING_RESERVED_FUTURE() -> String:
    var v = OcctlSurfaces.OCCTL_SURFACE_FILLING_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""
