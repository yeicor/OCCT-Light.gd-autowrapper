class_name TestOcctlIoPly

var _w: OcctlIoPly

func _init() -> void:
    self._w = OcctlIoPly.new()

static func test_OCCTL_IO_PLY_WRITE_OPTIONS_VERSION_1() -> String:
    var v = OcctlIoPly.OCCTL_IO_PLY_WRITE_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_IO_PLY_COORDINATE_SYSTEM_Y_UP() -> String:
    var v = OcctlIoPly.OCCTL_IO_PLY_COORDINATE_SYSTEM_Y_UP
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_IO_PLY_COORDINATE_SYSTEM_Z_UP() -> String:
    var v = OcctlIoPly.OCCTL_IO_PLY_COORDINATE_SYSTEM_Z_UP
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_IO_PLY_COORDINATE_SYSTEM_GLTF() -> String:
    var v = OcctlIoPly.OCCTL_IO_PLY_COORDINATE_SYSTEM_GLTF
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_IO_PLY_COORDINATE_SYSTEM_RESERVED_FUTURE() -> String:
    var v = OcctlIoPly.OCCTL_IO_PLY_COORDINATE_SYSTEM_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""
