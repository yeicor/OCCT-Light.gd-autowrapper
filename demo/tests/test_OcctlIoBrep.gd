class_name TestOcctlIoBrep

var _w: OcctlIoBrep

func _init() -> void:
    self._w = OcctlIoBrep.new()

static func test_OCCTL_IO_BREP_WRITE_OPTIONS_VERSION_1() -> String:
    var v = OcctlIoBrep.OCCTL_IO_BREP_WRITE_OPTIONS_VERSION_1
    return ""
