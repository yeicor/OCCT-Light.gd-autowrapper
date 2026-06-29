class_name TestOcctlMesh

var _w: OcctlMesh

func _init() -> void:
    self._w = OcctlMesh.new()

static func test_OCCTL_MESH_OPTIONS_VERSION_1() -> String:
    var v = OcctlMesh.OCCTL_MESH_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_MESH_FROM_BUFFERS_OPTIONS_VERSION_1() -> String:
    var v = OcctlMesh.OCCTL_MESH_FROM_BUFFERS_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_MESH_TRIANGLE_ADJACENCY_BOUNDARY() -> String:
    var v = OcctlMesh.new().const_OCCTL_MESH_TRIANGLE_ADJACENCY_BOUNDARY()
    if v == null: return "Failed: {c.name} returned null"
    return ""

static func test_OCCTL_MESH_TRIANGLE_COMPONENTS_OPTIONS_VERSION_1() -> String:
    var v = OcctlMesh.OCCTL_MESH_TRIANGLE_COMPONENTS_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_MESH_TRIANGLE_PLANE_COMPONENTS_OPTIONS_VERSION_1() -> String:
    var v = OcctlMesh.OCCTL_MESH_TRIANGLE_PLANE_COMPONENTS_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_MESH_TRIANGLE_SPHERE_COMPONENTS_OPTIONS_VERSION_1() -> String:
    var v = OcctlMesh.OCCTL_MESH_TRIANGLE_SPHERE_COMPONENTS_OPTIONS_VERSION_1
    return ""

static func test_OCCTL_MESH_TRIANGLE_CYLINDER_COMPONENTS_OPTIONS_VERSION_1() -> String:
    var v = OcctlMesh.OCCTL_MESH_TRIANGLE_CYLINDER_COMPONENTS_OPTIONS_VERSION_1
    return ""

static func test_model_metadata_set_string_pair() -> String:
    var _w = OcctlMesh.new()
    _w.model_metadata_set(null, "test", "test")
    return ""

static func test_model_metadata_get_string_pair() -> String:
    var _w = OcctlMesh.new()
    _w.model_metadata_get(null, "test")
    return ""

static func test_model_metadata_unset_string_pair() -> String:
    var _w = OcctlMesh.new()
    _w.model_metadata_unset(null, "test")
    return ""
