class_name TestOcctlPrimSweep

var _w: OcctlPrimSweep

func _init() -> void:
    self._w = OcctlPrimSweep.new()

static func test_OCCTL_PRIM_PRISM_INFO_VERSION_1() -> String:
    var v = OcctlPrimSweep.OCCTL_PRIM_PRISM_INFO_VERSION_1
    return ""

static func test_OCCTL_PRIM_TWIST_EXTRUSION_INFO_VERSION_1() -> String:
    var v = OcctlPrimSweep.OCCTL_PRIM_TWIST_EXTRUSION_INFO_VERSION_1
    return ""

static func test_OCCTL_PRIM_EXTRUDE_TWIST_INFO_VERSION_1() -> String:
    var v = OcctlPrimSweep.OCCTL_PRIM_EXTRUDE_TWIST_INFO_VERSION_1
    return ""

static func test_OCCTL_PRIM_REVOL_INFO_VERSION_1() -> String:
    var v = OcctlPrimSweep.OCCTL_PRIM_REVOL_INFO_VERSION_1
    return ""

static func test_OCCTL_PRIM_PIPE_INFO_VERSION_1() -> String:
    var v = OcctlPrimSweep.OCCTL_PRIM_PIPE_INFO_VERSION_1
    return ""

static func test_OCCTL_PRIM_LOFT_INFO_VERSION_1() -> String:
    var v = OcctlPrimSweep.OCCTL_PRIM_LOFT_INFO_VERSION_1
    return ""

static func test_OCCTL_PRIM_PIPE_SHELL_INFO_VERSION_1() -> String:
    var v = OcctlPrimSweep.OCCTL_PRIM_PIPE_SHELL_INFO_VERSION_1
    return ""

static func test_OCCTL_PRIM_PIPE_SHELL_LINEAR_LAW_INFO_VERSION_1() -> String:
    var v = OcctlPrimSweep.OCCTL_PRIM_PIPE_SHELL_LINEAR_LAW_INFO_VERSION_1
    return ""

static func test_OCCTL_PRIM_PIPE_SHELL_INTERPOLATED_LAW_INFO_VERSION_1() -> String:
    var v = OcctlPrimSweep.OCCTL_PRIM_PIPE_SHELL_INTERPOLATED_LAW_INFO_VERSION_1
    return ""

static func test_OCCTL_PRIM_OFFSET_SHAPE_INFO_VERSION_1() -> String:
    var v = OcctlPrimSweep.OCCTL_PRIM_OFFSET_SHAPE_INFO_VERSION_1
    return ""

static func test_OCCTL_PRIM_THICK_SOLID_INFO_VERSION_1() -> String:
    var v = OcctlPrimSweep.OCCTL_PRIM_THICK_SOLID_INFO_VERSION_1
    return ""

static func test_OCCTL_PIPE_MODE_CORRECTED_FRENET() -> String:
    var v = OcctlPrimSweep.OCCTL_PIPE_MODE_CORRECTED_FRENET
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_PIPE_MODE_FRENET() -> String:
    var v = OcctlPrimSweep.OCCTL_PIPE_MODE_FRENET
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_PIPE_MODE_DISCRETE() -> String:
    var v = OcctlPrimSweep.OCCTL_PIPE_MODE_DISCRETE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_PIPE_MODE_CONSTANT_AXIS() -> String:
    var v = OcctlPrimSweep.OCCTL_PIPE_MODE_CONSTANT_AXIS
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_PIPE_MODE_CONSTANT_BINORMAL() -> String:
    var v = OcctlPrimSweep.OCCTL_PIPE_MODE_CONSTANT_BINORMAL
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_PIPE_MODE_RESERVED_FUTURE() -> String:
    var v = OcctlPrimSweep.OCCTL_PIPE_MODE_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_PIPE_TRANSITION_MODIFIED() -> String:
    var v = OcctlPrimSweep.OCCTL_PIPE_TRANSITION_MODIFIED
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_PIPE_TRANSITION_RIGHT_CORNER() -> String:
    var v = OcctlPrimSweep.OCCTL_PIPE_TRANSITION_RIGHT_CORNER
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_PIPE_TRANSITION_ROUND_CORNER() -> String:
    var v = OcctlPrimSweep.OCCTL_PIPE_TRANSITION_ROUND_CORNER
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_PIPE_TRANSITION_RESERVED_FUTURE() -> String:
    var v = OcctlPrimSweep.OCCTL_PIPE_TRANSITION_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_OFFSET_MODE_SKIN() -> String:
    var v = OcctlPrimSweep.OCCTL_OFFSET_MODE_SKIN
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_OFFSET_MODE_PIPE() -> String:
    var v = OcctlPrimSweep.OCCTL_OFFSET_MODE_PIPE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_OFFSET_MODE_RECTO_VERSO() -> String:
    var v = OcctlPrimSweep.OCCTL_OFFSET_MODE_RECTO_VERSO
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_OFFSET_MODE_RESERVED_FUTURE() -> String:
    var v = OcctlPrimSweep.OCCTL_OFFSET_MODE_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""
