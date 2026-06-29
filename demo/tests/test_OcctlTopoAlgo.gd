class_name TestOcctlTopoAlgo

var _w: OcctlTopoAlgo

func _init() -> void:
    self._w = OcctlTopoAlgo.new()

static func test_OCCTL_TOPO_SEW_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_SEW_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TOPO_SEW_RESULT_VERSION_1() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_SEW_RESULT_VERSION_1
    return ""

static func test_OCCTL_TOPO_SAME_PARAMETER_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_SAME_PARAMETER_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TOPO_FILLET_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_FILLET_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TOPO_EDGE_BLEND_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_EDGE_BLEND_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TOPO_MAX_FILLET_RADIUS_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_MAX_FILLET_RADIUS_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TOPO_PROJECT_ON_FACE_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_PROJECT_ON_FACE_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TOPO_WRAP_ON_FACE_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_WRAP_ON_FACE_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TOPO_PROJECT_FACE_DIRECTION_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_PROJECT_FACE_DIRECTION_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TOPO_FACE_TO_ARCS_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_FACE_TO_ARCS_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TOPO_HLR_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_HLR_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TOPO_HLR_RESULT_VERSION_1() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_HLR_RESULT_VERSION_1
    return ""

static func test_OCCTL_TOPO_DRAFT_FACES_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_DRAFT_FACES_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TOPO_DEFEATURE_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_DEFEATURE_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TOPO_OFFSET_FEATURES_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_OFFSET_FEATURES_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TOPO_FILLING_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_FILLING_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TOPO_FILLING_PATCH_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_FILLING_PATCH_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TOPO_SPLIT_BY_PLANE_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_SPLIT_BY_PLANE_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TOPO_SECTION_BY_PLANES_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_SECTION_BY_PLANES_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TOPO_EXTRUDE_FACES_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_EXTRUDE_FACES_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TOPO_LINEAR_PATTERN_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_LINEAR_PATTERN_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TOPO_CIRCULAR_PATTERN_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_CIRCULAR_PATTERN_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TOPO_CHECK_WARNING() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_CHECK_WARNING
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TOPO_CHECK_ERROR() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_CHECK_ERROR
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TOPO_CHECK_FATAL() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_CHECK_FATAL
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TOPO_CHECK_SEVERITY_RESERVED_FUTURE() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_CHECK_SEVERITY_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TOPO_HLR_BREP() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_HLR_BREP
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TOPO_HLR_POLY() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_HLR_POLY
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TOPO_HLR_MODE_RESERVED_FUTURE() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_HLR_MODE_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TOPO_FILLING_C0() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_FILLING_C0
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TOPO_FILLING_G1() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_FILLING_G1
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TOPO_FILLING_G2() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_FILLING_G2
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TOPO_FILLING_CONTINUITY_RESERVED_FUTURE() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_FILLING_CONTINUITY_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TOPO_SPLIT_KEEP_ALL() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_SPLIT_KEEP_ALL
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TOPO_SPLIT_KEEP_POSITIVE() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_SPLIT_KEEP_POSITIVE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TOPO_SPLIT_KEEP_NEGATIVE() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_SPLIT_KEEP_NEGATIVE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TOPO_SPLIT_KEEP_RESERVED_FUTURE() -> String:
    var v = OcctlTopoAlgo.OCCTL_TOPO_SPLIT_KEEP_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""
