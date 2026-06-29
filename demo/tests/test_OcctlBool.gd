class_name TestOcctlBool

var _w: OcctlBool

func _init() -> void:
    self._w = OcctlBool.new()

static func test_OCCTL_BOOL_OPTIONS_VERSION_1() -> String:
    var v = OcctlBool.OCCTL_BOOL_OPTIONS_VERSION_1
    return ""
