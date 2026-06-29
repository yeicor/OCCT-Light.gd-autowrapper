class_name TestOcctlIoGltf

var _w: OcctlIoGltf

func _init() -> void:
    self._w = OcctlIoGltf.new()

static func test_OCCTL_IO_GLTF_READ_OPTIONS_VERSION_1() -> String:
    var v = OcctlIoGltf.OCCTL_IO_GLTF_READ_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_IO_GLTF_WRITE_OPTIONS_VERSION_1() -> String:
    var v = OcctlIoGltf.OCCTL_IO_GLTF_WRITE_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_IO_GLTF_TRANSFORM_COMPACT() -> String:
    var v = OcctlIoGltf.OCCTL_IO_GLTF_TRANSFORM_COMPACT
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_IO_GLTF_TRANSFORM_MAT4() -> String:
    var v = OcctlIoGltf.OCCTL_IO_GLTF_TRANSFORM_MAT4
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_IO_GLTF_TRANSFORM_TRS() -> String:
    var v = OcctlIoGltf.OCCTL_IO_GLTF_TRANSFORM_TRS
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_IO_GLTF_TRANSFORM_RESERVED_FUTURE() -> String:
    var v = OcctlIoGltf.OCCTL_IO_GLTF_TRANSFORM_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""
