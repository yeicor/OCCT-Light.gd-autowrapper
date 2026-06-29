class_name TestOcctlTopo

var _w: OcctlTopo

func _init() -> void:
    self._w = OcctlTopo.new()

static func test_OCCTL_TOPO_MAKE_PRODUCT_INFO_VERSION_1() -> String:
    var v = OcctlTopo.OCCTL_TOPO_MAKE_PRODUCT_INFO_VERSION_1
    return ""

static func test_OCCTL_EDGE_VIEW_VERSION_1() -> String:
    var v = OcctlTopo.OCCTL_EDGE_VIEW_VERSION_1
    return ""

static func test_OCCTL_COEDGE_VIEW_VERSION_1() -> String:
    var v = OcctlTopo.OCCTL_COEDGE_VIEW_VERSION_1
    return ""

static func test_OCCTL_FACE_VIEW_VERSION_1() -> String:
    var v = OcctlTopo.OCCTL_FACE_VIEW_VERSION_1
    return ""

static func test_OCCTL_VERTEX_VIEW_VERSION_1() -> String:
    var v = OcctlTopo.OCCTL_VERTEX_VIEW_VERSION_1
    return ""

static func test_OCCTL_WIRE_VIEW_VERSION_1() -> String:
    var v = OcctlTopo.OCCTL_WIRE_VIEW_VERSION_1
    return ""

static func test_OCCTL_SHELL_VIEW_VERSION_1() -> String:
    var v = OcctlTopo.OCCTL_SHELL_VIEW_VERSION_1
    return ""

static func test_OCCTL_SOLID_VIEW_VERSION_1() -> String:
    var v = OcctlTopo.OCCTL_SOLID_VIEW_VERSION_1
    return ""

static func test_OCCTL_COMPOUND_VIEW_VERSION_1() -> String:
    var v = OcctlTopo.OCCTL_COMPOUND_VIEW_VERSION_1
    return ""

static func test_graph_name_set_string_pair() -> String:
    var _w = OcctlTopo.new()
    _w.graph_name_set(null, 0, "test")
    return ""

static func test_graph_units_set_string_pair() -> String:
    var _w = OcctlTopo.new()
    _w.graph_units_set(null, 0.0, "test")
    return ""

static func test_graph_node_metadata_set_string_pair() -> String:
    var _w = OcctlTopo.new()
    _w.graph_node_metadata_set(null, 0, "test", "test")
    return ""

static func test_graph_node_metadata_get_string_pair() -> String:
    var _w = OcctlTopo.new()
    _w.graph_node_metadata_get(null, 0, "test")
    return ""

static func test_graph_metadata_set_string_pair() -> String:
    var _w = OcctlTopo.new()
    _w.graph_metadata_set(null, "test", "test")
    return ""

static func test_graph_metadata_get_string_pair() -> String:
    var _w = OcctlTopo.new()
    _w.graph_metadata_get(null, "test")
    return ""

static func test_graph_metadata_unset_string_pair() -> String:
    var _w = OcctlTopo.new()
    _w.graph_metadata_unset(null, "test")
    return ""

static func test_graph_node_metadata_unset_string_pair() -> String:
    var _w = OcctlTopo.new()
    _w.graph_node_metadata_unset(null, 0, "test")
    return ""

static func test_graph_tag_add_string_pair() -> String:
    var _w = OcctlTopo.new()
    _w.graph_tag_add(null, 0, "test")
    return ""

static func test_graph_tag_remove_string_pair() -> String:
    var _w = OcctlTopo.new()
    _w.graph_tag_remove(null, 0, "test")
    return ""

static func test_graph_tag_has_string_pair() -> String:
    var _w = OcctlTopo.new()
    _w.graph_tag_has(null, 0, "test", null)
    return ""

static func test_graph_tag_nodes_string_pair() -> String:
    var _w = OcctlTopo.new()
    _w.graph_tag_nodes(null, "test")
    return ""
