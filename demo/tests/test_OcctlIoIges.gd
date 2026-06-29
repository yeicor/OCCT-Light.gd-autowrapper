class_name TestOcctlIoIges

var _w: OcctlIoIges

func _init() -> void:
    self._w = OcctlIoIges.new()

static func test_OCCTL_IO_IGES_READ_OPTIONS_VERSION_1() -> String:
    var v = OcctlIoIges.OCCTL_IO_IGES_READ_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_IO_IGES_WRITE_OPTIONS_VERSION_1() -> String:
    var v = OcctlIoIges.OCCTL_IO_IGES_WRITE_OPTIONS_VERSION_1
    return ""
