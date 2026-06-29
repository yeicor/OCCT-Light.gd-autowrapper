class_name TestOcctlHeal

var _w: OcctlHeal

func _init() -> void:
    self._w = OcctlHeal.new()

static func test_OCCTL_HEAL_OPTIONS_VERSION_1() -> String:
    var v = OcctlHeal.OCCTL_HEAL_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_HEAL_UNIFY_SAME_DOMAIN_OPTIONS_VERSION_1() -> String:
    var v = OcctlHeal.OCCTL_HEAL_UNIFY_SAME_DOMAIN_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_HEAL_MODE_BASIC() -> String:
    var v = OcctlHeal.OCCTL_HEAL_MODE_BASIC
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_HEAL_MODE_STANDARD() -> String:
    var v = OcctlHeal.OCCTL_HEAL_MODE_STANDARD
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_HEAL_MODE_FULL() -> String:
    var v = OcctlHeal.OCCTL_HEAL_MODE_FULL
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_HEAL_MODE_RESERVED_FUTURE() -> String:
    var v = OcctlHeal.OCCTL_HEAL_MODE_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""
