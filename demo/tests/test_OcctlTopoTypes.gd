class_name TestOcctlTopoTypes

var _w: OcctlTopoTypes

func _init() -> void:
    self._w = OcctlTopoTypes.new()

static func test_OCCTL_REF_UID_WIRE_SIZE() -> String:
    var v = OcctlTopoTypes.new().const_OCCTL_REF_UID_WIRE_SIZE()
    if v == null: return "Failed: {c.name} returned null"
    return ""

static func test_OCCTL_REP_UID_WIRE_SIZE() -> String:
    var v = OcctlTopoTypes.new().const_OCCTL_REP_UID_WIRE_SIZE()
    if v == null: return "Failed: {c.name} returned null"
    return ""
