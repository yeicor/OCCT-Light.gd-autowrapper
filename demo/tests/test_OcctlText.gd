class_name TestOcctlText

var _w: OcctlText

func _init() -> void:
    self._w = OcctlText.new()

static func test_OCCTL_TEXT_INFO_VERSION_1() -> String:
    var v = OcctlText.OCCTL_TEXT_INFO_VERSION_1
    return ""

static func test_OCCTL_TEXT_LAYOUT_OPTIONS_VERSION_1() -> String:
    var v = OcctlText.OCCTL_TEXT_LAYOUT_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TEXT_METRICS_VERSION_1() -> String:
    var v = OcctlText.OCCTL_TEXT_METRICS_VERSION_1
    return ""

static func test_OCCTL_TEXT_FONT_ASPECT_REGULAR() -> String:
    var v = OcctlText.OCCTL_TEXT_FONT_ASPECT_REGULAR
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TEXT_FONT_ASPECT_BOLD() -> String:
    var v = OcctlText.OCCTL_TEXT_FONT_ASPECT_BOLD
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TEXT_FONT_ASPECT_ITALIC() -> String:
    var v = OcctlText.OCCTL_TEXT_FONT_ASPECT_ITALIC
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TEXT_FONT_ASPECT_BOLD_ITALIC() -> String:
    var v = OcctlText.OCCTL_TEXT_FONT_ASPECT_BOLD_ITALIC
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TEXT_FONT_ASPECT_RESERVED_FUTURE() -> String:
    var v = OcctlText.OCCTL_TEXT_FONT_ASPECT_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TEXT_HALIGN_LEFT() -> String:
    var v = OcctlText.OCCTL_TEXT_HALIGN_LEFT
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TEXT_HALIGN_CENTER() -> String:
    var v = OcctlText.OCCTL_TEXT_HALIGN_CENTER
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TEXT_HALIGN_RIGHT() -> String:
    var v = OcctlText.OCCTL_TEXT_HALIGN_RIGHT
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TEXT_HALIGN_RESERVED_FUTURE() -> String:
    var v = OcctlText.OCCTL_TEXT_HALIGN_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TEXT_VALIGN_BOTTOM() -> String:
    var v = OcctlText.OCCTL_TEXT_VALIGN_BOTTOM
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TEXT_VALIGN_BASELINE() -> String:
    var v = OcctlText.OCCTL_TEXT_VALIGN_BASELINE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TEXT_VALIGN_CENTER() -> String:
    var v = OcctlText.OCCTL_TEXT_VALIGN_CENTER
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TEXT_VALIGN_TOP() -> String:
    var v = OcctlText.OCCTL_TEXT_VALIGN_TOP
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TEXT_VALIGN_RESERVED_FUTURE() -> String:
    var v = OcctlText.OCCTL_TEXT_VALIGN_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""
