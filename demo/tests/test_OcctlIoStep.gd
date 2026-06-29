class_name TestOcctlIoStep

var _w: OcctlIoStep

func _init() -> void:
    self._w = OcctlIoStep.new()

static func test_OCCTL_IO_STEP_READ_OPTIONS_VERSION_1() -> String:
    var v = OcctlIoStep.OCCTL_IO_STEP_READ_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_IO_STEP_WRITE_OPTIONS_VERSION_1() -> String:
    var v = OcctlIoStep.OCCTL_IO_STEP_WRITE_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_IO_STEP_UNIT_MM() -> String:
    var v = OcctlIoStep.OCCTL_IO_STEP_UNIT_MM
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_IO_STEP_UNIT_M() -> String:
    var v = OcctlIoStep.OCCTL_IO_STEP_UNIT_M
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_IO_STEP_UNIT_INCH() -> String:
    var v = OcctlIoStep.OCCTL_IO_STEP_UNIT_INCH
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_IO_STEP_UNIT_RESERVED_FUTURE() -> String:
    var v = OcctlIoStep.OCCTL_IO_STEP_UNIT_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_IO_STEP_SCHEMA_AP203() -> String:
    var v = OcctlIoStep.OCCTL_IO_STEP_SCHEMA_AP203
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_IO_STEP_SCHEMA_AP214() -> String:
    var v = OcctlIoStep.OCCTL_IO_STEP_SCHEMA_AP214
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_IO_STEP_SCHEMA_AP242() -> String:
    var v = OcctlIoStep.OCCTL_IO_STEP_SCHEMA_AP242
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_IO_STEP_SCHEMA_RESERVED_FUTURE() -> String:
    var v = OcctlIoStep.OCCTL_IO_STEP_SCHEMA_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""
