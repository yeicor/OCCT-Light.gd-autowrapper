class_name TestOcctlCore

var _w: OcctlCore

func _init() -> void:
    self._w = OcctlCore.new()

static func test_OCCTL_PI() -> String:
    var v = OcctlCore.new().const_OCCTL_PI()
    if v == null: return "Failed: {c.name} returned null"
    return ""

static func test_OCCTL_ANGLE_1_DEG_RAD() -> String:
    var v = OcctlCore.new().const_OCCTL_ANGLE_1_DEG_RAD()
    if v == null: return "Failed: {c.name} returned null"
    return ""

static func test_OCCTL_ANGLE_90_DEG_RAD() -> String:
    var v = OcctlCore.new().const_OCCTL_ANGLE_90_DEG_RAD()
    if v == null: return "Failed: {c.name} returned null"
    return ""

static func test_OCCTL_VERSION_MAJOR() -> String:
    var v = OcctlCore.OCCTL_VERSION_MAJOR
    return ""

static func test_OCCTL_VERSION_MINOR() -> String:
    var v = OcctlCore.OCCTL_VERSION_MINOR
    return ""

static func test_OCCTL_VERSION_PATCH() -> String:
    var v = OcctlCore.OCCTL_VERSION_PATCH
    return ""

static func test_OCCTL_ABI_VERSION() -> String:
    var v = OcctlCore.OCCTL_ABI_VERSION
    return ""

static func test_OCCTL_RUNTIME_INIT_INFO_VERSION_1() -> String:
    var v = OcctlCore.OCCTL_RUNTIME_INIT_INFO_VERSION_1
    return ""

static func test_OCCTL_UID_WIRE_SIZE() -> String:
    var v = OcctlCore.OCCTL_UID_WIRE_SIZE
    return ""

static func test_OCCTL_OK() -> String:
    var v = OcctlCore.OCCTL_OK
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_ERROR() -> String:
    var v = OcctlCore.OCCTL_ERROR
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_INVALID_ARGUMENT() -> String:
    var v = OcctlCore.OCCTL_INVALID_ARGUMENT
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_INVALID_HANDLE() -> String:
    var v = OcctlCore.OCCTL_INVALID_HANDLE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_NOT_FOUND() -> String:
    var v = OcctlCore.OCCTL_NOT_FOUND
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_OUT_OF_MEMORY() -> String:
    var v = OcctlCore.OCCTL_OUT_OF_MEMORY
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_OUT_OF_RANGE() -> String:
    var v = OcctlCore.OCCTL_OUT_OF_RANGE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_NOT_DONE() -> String:
    var v = OcctlCore.OCCTL_NOT_DONE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_GEOMETRY_INVALID() -> String:
    var v = OcctlCore.OCCTL_GEOMETRY_INVALID
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TOPOLOGY_INVALID() -> String:
    var v = OcctlCore.OCCTL_TOPOLOGY_INVALID
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_IO_ERROR() -> String:
    var v = OcctlCore.OCCTL_IO_ERROR
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_FORMAT_ERROR() -> String:
    var v = OcctlCore.OCCTL_FORMAT_ERROR
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_UNSUPPORTED() -> String:
    var v = OcctlCore.OCCTL_UNSUPPORTED
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_CANCELLED() -> String:
    var v = OcctlCore.OCCTL_CANCELLED
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_BUFFER_TOO_SMALL() -> String:
    var v = OcctlCore.OCCTL_BUFFER_TOO_SMALL
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_VERSION_MISMATCH() -> String:
    var v = OcctlCore.OCCTL_VERSION_MISMATCH
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_INTERNAL() -> String:
    var v = OcctlCore.OCCTL_INTERNAL
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_WRONG_KIND() -> String:
    var v = OcctlCore.OCCTL_WRONG_KIND
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_STATUS_RESERVED_FUTURE() -> String:
    var v = OcctlCore.OCCTL_STATUS_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_KIND_INVALID() -> String:
    var v = OcctlCore.OCCTL_KIND_INVALID
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_KIND_SOLID() -> String:
    var v = OcctlCore.OCCTL_KIND_SOLID
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_KIND_SHELL() -> String:
    var v = OcctlCore.OCCTL_KIND_SHELL
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_KIND_FACE() -> String:
    var v = OcctlCore.OCCTL_KIND_FACE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_KIND_WIRE() -> String:
    var v = OcctlCore.OCCTL_KIND_WIRE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_KIND_EDGE() -> String:
    var v = OcctlCore.OCCTL_KIND_EDGE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_KIND_VERTEX() -> String:
    var v = OcctlCore.OCCTL_KIND_VERTEX
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_KIND_COMPOUND() -> String:
    var v = OcctlCore.OCCTL_KIND_COMPOUND
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_KIND_COMPSOLID() -> String:
    var v = OcctlCore.OCCTL_KIND_COMPSOLID
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_KIND_COEDGE() -> String:
    var v = OcctlCore.OCCTL_KIND_COEDGE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_KIND_PRODUCT() -> String:
    var v = OcctlCore.OCCTL_KIND_PRODUCT
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_KIND_OCCURRENCE() -> String:
    var v = OcctlCore.OCCTL_KIND_OCCURRENCE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_NODE_KIND_RESERVED_FUTURE() -> String:
    var v = OcctlCore.OCCTL_NODE_KIND_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_REF_KIND_INVALID() -> String:
    var v = OcctlCore.OCCTL_REF_KIND_INVALID
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_REF_KIND_SHELL() -> String:
    var v = OcctlCore.OCCTL_REF_KIND_SHELL
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_REF_KIND_FACE() -> String:
    var v = OcctlCore.OCCTL_REF_KIND_FACE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_REF_KIND_WIRE() -> String:
    var v = OcctlCore.OCCTL_REF_KIND_WIRE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_REF_KIND_COEDGE() -> String:
    var v = OcctlCore.OCCTL_REF_KIND_COEDGE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_REF_KIND_VERTEX() -> String:
    var v = OcctlCore.OCCTL_REF_KIND_VERTEX
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_REF_KIND_SOLID() -> String:
    var v = OcctlCore.OCCTL_REF_KIND_SOLID
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_REF_KIND_CHILD() -> String:
    var v = OcctlCore.OCCTL_REF_KIND_CHILD
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_REF_KIND_OCCURRENCE() -> String:
    var v = OcctlCore.OCCTL_REF_KIND_OCCURRENCE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_REF_KIND_RESERVED_FUTURE() -> String:
    var v = OcctlCore.OCCTL_REF_KIND_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_REP_KIND_INVALID() -> String:
    var v = OcctlCore.OCCTL_REP_KIND_INVALID
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_REP_KIND_SURFACE() -> String:
    var v = OcctlCore.OCCTL_REP_KIND_SURFACE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_REP_KIND_CURVE3D() -> String:
    var v = OcctlCore.OCCTL_REP_KIND_CURVE3D
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_REP_KIND_CURVE2D() -> String:
    var v = OcctlCore.OCCTL_REP_KIND_CURVE2D
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_REP_KIND_TRIANGULATION() -> String:
    var v = OcctlCore.OCCTL_REP_KIND_TRIANGULATION
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_REP_KIND_POLYGON3D() -> String:
    var v = OcctlCore.OCCTL_REP_KIND_POLYGON3D
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_REP_KIND_POLYGON2D() -> String:
    var v = OcctlCore.OCCTL_REP_KIND_POLYGON2D
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_REP_KIND_POLYGON_ON_TRI() -> String:
    var v = OcctlCore.OCCTL_REP_KIND_POLYGON_ON_TRI
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_REP_KIND_RESERVED_FUTURE() -> String:
    var v = OcctlCore.OCCTL_REP_KIND_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""
