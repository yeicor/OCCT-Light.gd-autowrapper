class_name TestOcctlIoVrml

var _w: OcctlIoVrml

func _init() -> void:
    self._w = OcctlIoVrml.new()

static func test_OCCTL_IO_VRML_READ_OPTIONS_VERSION_1() -> String:
    var v = OcctlIoVrml.OCCTL_IO_VRML_READ_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_IO_VRML_WRITE_OPTIONS_VERSION_1() -> String:
    var v = OcctlIoVrml.OCCTL_IO_VRML_WRITE_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_IO_VRML_COORDINATE_SYSTEM_Y_UP() -> String:
    var v = OcctlIoVrml.OCCTL_IO_VRML_COORDINATE_SYSTEM_Y_UP
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_IO_VRML_COORDINATE_SYSTEM_Z_UP() -> String:
    var v = OcctlIoVrml.OCCTL_IO_VRML_COORDINATE_SYSTEM_Z_UP
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_IO_VRML_COORDINATE_SYSTEM_GLTF() -> String:
    var v = OcctlIoVrml.OCCTL_IO_VRML_COORDINATE_SYSTEM_GLTF
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_IO_VRML_COORDINATE_SYSTEM_RESERVED_FUTURE() -> String:
    var v = OcctlIoVrml.OCCTL_IO_VRML_COORDINATE_SYSTEM_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_IO_VRML_WRITER_VERSION_1() -> String:
    var v = OcctlIoVrml.OCCTL_IO_VRML_WRITER_VERSION_1
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_IO_VRML_WRITER_VERSION_2() -> String:
    var v = OcctlIoVrml.OCCTL_IO_VRML_WRITER_VERSION_2
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_IO_VRML_WRITER_VERSION_RESERVED_FUTURE() -> String:
    var v = OcctlIoVrml.OCCTL_IO_VRML_WRITER_VERSION_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_IO_VRML_REPRESENTATION_SHADED() -> String:
    var v = OcctlIoVrml.OCCTL_IO_VRML_REPRESENTATION_SHADED
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_IO_VRML_REPRESENTATION_WIREFRAME() -> String:
    var v = OcctlIoVrml.OCCTL_IO_VRML_REPRESENTATION_WIREFRAME
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_IO_VRML_REPRESENTATION_BOTH() -> String:
    var v = OcctlIoVrml.OCCTL_IO_VRML_REPRESENTATION_BOTH
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_IO_VRML_REPRESENTATION_RESERVED_FUTURE() -> String:
    var v = OcctlIoVrml.OCCTL_IO_VRML_REPRESENTATION_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""
