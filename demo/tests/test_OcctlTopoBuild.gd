class_name TestOcctlTopoBuild

var _w: OcctlTopoBuild

func _init() -> void:
    self._w = OcctlTopoBuild.new()

static func test_OCCTL_TOPO_MAKE_VERTEX_INFO_VERSION_1() -> String:
    var v = OcctlTopoBuild.OCCTL_TOPO_MAKE_VERTEX_INFO_VERSION_1
    return ""

static func test_OCCTL_TOPO_MAKE_EDGE_INFO_VERSION_1() -> String:
    var v = OcctlTopoBuild.OCCTL_TOPO_MAKE_EDGE_INFO_VERSION_1
    return ""

static func test_OCCTL_TOPO_MAKE_WIRE_INFO_VERSION_1() -> String:
    var v = OcctlTopoBuild.OCCTL_TOPO_MAKE_WIRE_INFO_VERSION_1
    return ""

static func test_OCCTL_TOPO_EDGES_TO_WIRES_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoBuild.OCCTL_TOPO_EDGES_TO_WIRES_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TOPO_WIRE_OFFSET_2D_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoBuild.OCCTL_TOPO_WIRE_OFFSET_2D_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TOPO_WIRE_FIX_DEGENERATE_EDGES_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoBuild.OCCTL_TOPO_WIRE_FIX_DEGENERATE_EDGES_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TOPO_FACE_CHAMFER_2D_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoBuild.OCCTL_TOPO_FACE_CHAMFER_2D_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TOPO_WIRE_CHAMFER_2D_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoBuild.OCCTL_TOPO_WIRE_CHAMFER_2D_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TOPO_MAKE_FACE_INFO_VERSION_1() -> String:
    var v = OcctlTopoBuild.OCCTL_TOPO_MAKE_FACE_INFO_VERSION_1
    return ""

static func test_OCCTL_TOPO_MAKE_FACE_FROM_WIRES_AUTO_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoBuild.OCCTL_TOPO_MAKE_FACE_FROM_WIRES_AUTO_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_TOPO_MAKE_SHELL_INFO_VERSION_1() -> String:
    var v = OcctlTopoBuild.OCCTL_TOPO_MAKE_SHELL_INFO_VERSION_1
    return ""

static func test_OCCTL_TOPO_MAKE_SOLID_INFO_VERSION_1() -> String:
    var v = OcctlTopoBuild.OCCTL_TOPO_MAKE_SOLID_INFO_VERSION_1
    return ""

static func test_OCCTL_TOPO_MAKE_COMPOUND_INFO_VERSION_1() -> String:
    var v = OcctlTopoBuild.OCCTL_TOPO_MAKE_COMPOUND_INFO_VERSION_1
    return ""

static func test_OCCTL_TOPO_MAKE_COMPSOLID_INFO_VERSION_1() -> String:
    var v = OcctlTopoBuild.OCCTL_TOPO_MAKE_COMPSOLID_INFO_VERSION_1
    return ""

static func test_OCCTL_MATERIAL_INFO_VERSION_1() -> String:
    var v = OcctlTopoBuild.OCCTL_MATERIAL_INFO_VERSION_1
    return ""

static func test_OCCTL_JOINT_INFO_VERSION_1() -> String:
    var v = OcctlTopoBuild.OCCTL_JOINT_INFO_VERSION_1
    return ""

static func test_OCCTL_SELECT_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_SELECT_METADATA_FILTER_VERSION_1() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_METADATA_FILTER_VERSION_1
    return ""

static func test_OCCTL_SELECT_DISTANCE_TO_NODE_SORT_VERSION_1() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_DISTANCE_TO_NODE_SORT_VERSION_1
    return ""

static func test_OCCTL_SELECT_GROUP_OPTIONS_VERSION_1() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_GROUP_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_SELECT_GROUP_VIEW_VERSION_1() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_GROUP_VIEW_VERSION_1
    return ""

static func test_OCCTL_TOPO_WIRE_OFFSET_2D_JOIN_ARC() -> String:
    var v = OcctlTopoBuild.OCCTL_TOPO_WIRE_OFFSET_2D_JOIN_ARC
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TOPO_WIRE_OFFSET_2D_JOIN_TANGENT() -> String:
    var v = OcctlTopoBuild.OCCTL_TOPO_WIRE_OFFSET_2D_JOIN_TANGENT
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TOPO_WIRE_OFFSET_2D_JOIN_INTERSECTION() -> String:
    var v = OcctlTopoBuild.OCCTL_TOPO_WIRE_OFFSET_2D_JOIN_INTERSECTION
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_TOPO_WIRE_OFFSET_2D_JOIN_RESERVED_FUTURE() -> String:
    var v = OcctlTopoBuild.OCCTL_TOPO_WIRE_OFFSET_2D_JOIN_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_OFFSET_JOIN_ARC() -> String:
    var v = OcctlTopoBuild.OCCTL_OFFSET_JOIN_ARC
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_OFFSET_JOIN_TANGENT() -> String:
    var v = OcctlTopoBuild.OCCTL_OFFSET_JOIN_TANGENT
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_OFFSET_JOIN_INTERSECTION() -> String:
    var v = OcctlTopoBuild.OCCTL_OFFSET_JOIN_INTERSECTION
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_OFFSET_JOIN_RESERVED_FUTURE() -> String:
    var v = OcctlTopoBuild.OCCTL_OFFSET_JOIN_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_JOINT_RIGID() -> String:
    var v = OcctlTopoBuild.OCCTL_JOINT_RIGID
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_JOINT_REVOLUTE() -> String:
    var v = OcctlTopoBuild.OCCTL_JOINT_REVOLUTE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_JOINT_LINEAR() -> String:
    var v = OcctlTopoBuild.OCCTL_JOINT_LINEAR
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_JOINT_CYLINDRICAL() -> String:
    var v = OcctlTopoBuild.OCCTL_JOINT_CYLINDRICAL
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_JOINT_BALL() -> String:
    var v = OcctlTopoBuild.OCCTL_JOINT_BALL
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_JOINT_RESERVED_FUTURE() -> String:
    var v = OcctlTopoBuild.OCCTL_JOINT_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_BBOX_INTERSECTS() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_BBOX_INTERSECTS
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_BBOX_INSIDE() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_BBOX_INSIDE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_BBOX_CONTAINS_CENTER() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_BBOX_CONTAINS_CENTER
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_BBOX_MODE_RESERVED_FUTURE() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_BBOX_MODE_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_AXIS_X() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_AXIS_X
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_AXIS_Y() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_AXIS_Y
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_AXIS_Z() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_AXIS_Z
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_AXIS_RESERVED_FUTURE() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_AXIS_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_AXIS_POSITION_MIN() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_AXIS_POSITION_MIN
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_AXIS_POSITION_MAX() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_AXIS_POSITION_MAX
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_AXIS_POSITION_CENTER() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_AXIS_POSITION_CENTER
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_AXIS_POSITION_RESERVED_FUTURE() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_AXIS_POSITION_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_NORMAL_PARALLEL() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_NORMAL_PARALLEL
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_NORMAL_ANTIPARALLEL() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_NORMAL_ANTIPARALLEL
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_NORMAL_EITHER() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_NORMAL_EITHER
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_NORMAL_MODE_RESERVED_FUTURE() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_NORMAL_MODE_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_MEASURE_EDGE_LENGTH() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_MEASURE_EDGE_LENGTH
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_MEASURE_WIRE_LENGTH() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_MEASURE_WIRE_LENGTH
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_MEASURE_FACE_AREA() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_MEASURE_FACE_AREA
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_MEASURE_SURFACE_AREA() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_MEASURE_SURFACE_AREA
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_MEASURE_VOLUME() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_MEASURE_VOLUME
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_MEASURE_KIND_RESERVED_FUTURE() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_MEASURE_KIND_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_SORT_NONE() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_SORT_NONE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_SORT_AXIS_COORDINATE() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_SORT_AXIS_COORDINATE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_SORT_MEASURE() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_SORT_MEASURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_SORT_DISTANCE_TO_POINT() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_SORT_DISTANCE_TO_POINT
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_SORT_NAME() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_SORT_NAME
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_SORT_UID() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_SORT_UID
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_SORT_DISTANCE_TO_NODE() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_SORT_DISTANCE_TO_NODE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_SORT_KEY_RESERVED_FUTURE() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_SORT_KEY_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_SORT_ASCENDING() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_SORT_ASCENDING
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_SORT_DESCENDING() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_SORT_DESCENDING
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_SORT_DIRECTION_RESERVED_FUTURE() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_SORT_DIRECTION_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_GROUP_KIND() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_GROUP_KIND
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_GROUP_AXIS_COORDINATE() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_GROUP_AXIS_COORDINATE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_GROUP_CURVE_KIND() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_GROUP_CURVE_KIND
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_GROUP_SURFACE_KIND() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_GROUP_SURFACE_KIND
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_GROUP_NAME() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_GROUP_NAME
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_GROUP_COLOR() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_GROUP_COLOR
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_OCCTL_SELECT_GROUP_KEY_RESERVED_FUTURE() -> String:
    var v = OcctlTopoBuild.OCCTL_SELECT_GROUP_KEY_RESERVED_FUTURE
    if v < 0: return "Failed: enum value negative"
    return ""

static func test_select_tagged_iter_create_string_pair() -> String:
    var _w = OcctlTopoBuild.new()
    _w.select_tagged_iter_create(null, null, "test")
    return ""
