#include "OcctlCore.h"

#include "occtl/occtl_core.h"

void OcctlCore::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("const_OCCTL_PI"), &OcctlCore::const_OCCTL_PI);
    godot::ClassDB::bind_method(godot::D_METHOD("const_OCCTL_ANGLE_1_DEG_RAD"), &OcctlCore::const_OCCTL_ANGLE_1_DEG_RAD);
    godot::ClassDB::bind_method(godot::D_METHOD("const_OCCTL_ANGLE_90_DEG_RAD"), &OcctlCore::const_OCCTL_ANGLE_90_DEG_RAD);
    BIND_CONSTANT(OCCTL_VERSION_MAJOR);
    BIND_CONSTANT(OCCTL_VERSION_MINOR);
    BIND_CONSTANT(OCCTL_VERSION_PATCH);
    BIND_CONSTANT(OCCTL_ABI_VERSION);
    BIND_CONSTANT(OCCTL_RUNTIME_INIT_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_UID_WIRE_SIZE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_status_t", "OCCTL_OK", OCCTL_OK);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_status_t", "OCCTL_ERROR", OCCTL_ERROR);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_status_t", "OCCTL_INVALID_ARGUMENT", OCCTL_INVALID_ARGUMENT);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_status_t", "OCCTL_INVALID_HANDLE", OCCTL_INVALID_HANDLE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_status_t", "OCCTL_NOT_FOUND", OCCTL_NOT_FOUND);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_status_t", "OCCTL_OUT_OF_MEMORY", OCCTL_OUT_OF_MEMORY);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_status_t", "OCCTL_OUT_OF_RANGE", OCCTL_OUT_OF_RANGE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_status_t", "OCCTL_NOT_DONE", OCCTL_NOT_DONE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_status_t", "OCCTL_GEOMETRY_INVALID", OCCTL_GEOMETRY_INVALID);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_status_t", "OCCTL_TOPOLOGY_INVALID", OCCTL_TOPOLOGY_INVALID);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_status_t", "OCCTL_IO_ERROR", OCCTL_IO_ERROR);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_status_t", "OCCTL_FORMAT_ERROR", OCCTL_FORMAT_ERROR);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_status_t", "OCCTL_UNSUPPORTED", OCCTL_UNSUPPORTED);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_status_t", "OCCTL_CANCELLED", OCCTL_CANCELLED);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_status_t", "OCCTL_BUFFER_TOO_SMALL", OCCTL_BUFFER_TOO_SMALL);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_status_t", "OCCTL_VERSION_MISMATCH", OCCTL_VERSION_MISMATCH);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_status_t", "OCCTL_INTERNAL", OCCTL_INTERNAL);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_status_t", "OCCTL_WRONG_KIND", OCCTL_WRONG_KIND);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_status_t", "OCCTL_STATUS_RESERVED_FUTURE", OCCTL_STATUS_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_node_kind_t", "OCCTL_KIND_INVALID", OCCTL_KIND_INVALID);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_node_kind_t", "OCCTL_KIND_SOLID", OCCTL_KIND_SOLID);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_node_kind_t", "OCCTL_KIND_SHELL", OCCTL_KIND_SHELL);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_node_kind_t", "OCCTL_KIND_FACE", OCCTL_KIND_FACE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_node_kind_t", "OCCTL_KIND_WIRE", OCCTL_KIND_WIRE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_node_kind_t", "OCCTL_KIND_EDGE", OCCTL_KIND_EDGE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_node_kind_t", "OCCTL_KIND_VERTEX", OCCTL_KIND_VERTEX);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_node_kind_t", "OCCTL_KIND_COMPOUND", OCCTL_KIND_COMPOUND);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_node_kind_t", "OCCTL_KIND_COMPSOLID", OCCTL_KIND_COMPSOLID);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_node_kind_t", "OCCTL_KIND_COEDGE", OCCTL_KIND_COEDGE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_node_kind_t", "OCCTL_KIND_PRODUCT", OCCTL_KIND_PRODUCT);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_node_kind_t", "OCCTL_KIND_OCCURRENCE", OCCTL_KIND_OCCURRENCE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_node_kind_t", "OCCTL_NODE_KIND_RESERVED_FUTURE", OCCTL_NODE_KIND_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_ref_kind_t", "OCCTL_REF_KIND_INVALID", OCCTL_REF_KIND_INVALID);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_ref_kind_t", "OCCTL_REF_KIND_SHELL", OCCTL_REF_KIND_SHELL);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_ref_kind_t", "OCCTL_REF_KIND_FACE", OCCTL_REF_KIND_FACE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_ref_kind_t", "OCCTL_REF_KIND_WIRE", OCCTL_REF_KIND_WIRE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_ref_kind_t", "OCCTL_REF_KIND_COEDGE", OCCTL_REF_KIND_COEDGE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_ref_kind_t", "OCCTL_REF_KIND_VERTEX", OCCTL_REF_KIND_VERTEX);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_ref_kind_t", "OCCTL_REF_KIND_SOLID", OCCTL_REF_KIND_SOLID);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_ref_kind_t", "OCCTL_REF_KIND_CHILD", OCCTL_REF_KIND_CHILD);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_ref_kind_t", "OCCTL_REF_KIND_OCCURRENCE", OCCTL_REF_KIND_OCCURRENCE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_ref_kind_t", "OCCTL_REF_KIND_RESERVED_FUTURE", OCCTL_REF_KIND_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_rep_kind_t", "OCCTL_REP_KIND_INVALID", OCCTL_REP_KIND_INVALID);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_rep_kind_t", "OCCTL_REP_KIND_SURFACE", OCCTL_REP_KIND_SURFACE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_rep_kind_t", "OCCTL_REP_KIND_CURVE3D", OCCTL_REP_KIND_CURVE3D);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_rep_kind_t", "OCCTL_REP_KIND_CURVE2D", OCCTL_REP_KIND_CURVE2D);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_rep_kind_t", "OCCTL_REP_KIND_TRIANGULATION", OCCTL_REP_KIND_TRIANGULATION);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_rep_kind_t", "OCCTL_REP_KIND_POLYGON3D", OCCTL_REP_KIND_POLYGON3D);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_rep_kind_t", "OCCTL_REP_KIND_POLYGON2D", OCCTL_REP_KIND_POLYGON2D);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_rep_kind_t", "OCCTL_REP_KIND_POLYGON_ON_TRI", OCCTL_REP_KIND_POLYGON_ON_TRI);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_rep_kind_t", "OCCTL_REP_KIND_RESERVED_FUTURE", OCCTL_REP_KIND_RESERVED_FUTURE);
    godot::ClassDB::bind_method(godot::D_METHOD("status_to_string", "status"), &OcctlCore::status_to_string);
    godot::ClassDB::bind_method(godot::D_METHOD("error_last"), &OcctlCore::error_last);
    godot::ClassDB::bind_method(godot::D_METHOD("error_clear"), &OcctlCore::error_clear);
    godot::ClassDB::bind_method(godot::D_METHOD("runtime_init", "info"), &OcctlCore::runtime_init, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("runtime_init_info_init", "info"), &OcctlCore::runtime_init_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("runtime_shutdown"), &OcctlCore::runtime_shutdown);
    godot::ClassDB::bind_method(godot::D_METHOD("runtime_version", "out_major", "out_minor", "out_patch"), &OcctlCore::runtime_version);
    godot::ClassDB::bind_method(godot::D_METHOD("runtime_abi_version"), &OcctlCore::runtime_abi_version);
    godot::ClassDB::bind_method(godot::D_METHOD("runtime_occt_version"), &OcctlCore::runtime_occt_version);
    godot::ClassDB::bind_method(godot::D_METHOD("uid_to_bytes", "uid", "out_bytes"), &OcctlCore::uid_to_bytes);
    godot::ClassDB::bind_method(godot::D_METHOD("uid_from_bytes", "in_bytes", "out_uid"), &OcctlCore::uid_from_bytes);
    godot::ClassDB::bind_method(godot::D_METHOD("uid_equal", "a", "b"), &OcctlCore::uid_equal);
}

double OcctlCore::const_OCCTL_PI() { // NOLINT
    return 3.141592653589793;
}

double OcctlCore::const_OCCTL_ANGLE_1_DEG_RAD() { // NOLINT
    return 0.017453292519943295;
}

double OcctlCore::const_OCCTL_ANGLE_90_DEG_RAD() { // NOLINT
    return OCCTL_PI_OVER_TWO;
}

String OcctlCore::status_to_string(int status) { // NOLINT
    auto _result = ::occtl_status_to_string(static_cast<occtl_status_t>(status));
    return String(_result);
}

Ref<OcctlError> OcctlCore::error_last(void) { // NOLINT
    const occtl_error_t* _err = ::occtl_error_last();
    if (!_err) return Ref<OcctlError>();
    return OcctlError::from_c(*_err);
}

void OcctlCore::error_clear(void) { // NOLINT
    ::occtl_error_clear();
}

int OcctlCore::runtime_init(const Ref<OcctlRuntimeInitInfo>& info) { // NOLINT
    occtl_runtime_init_info_t _info_c = {};
    const occtl_runtime_init_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_status_t _status = ::occtl_runtime_init(_info_ptr);
    return static_cast<int>(_status);
}

int OcctlCore::runtime_init_info_init(const Ref<OcctlRuntimeInitInfo>& info) { // NOLINT
    occtl_runtime_init_info_t _info_val = {};
    ::occtl_runtime_init_info_init(&_info_val);
    occtl_status_t _status = ::occtl_runtime_init_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
    return static_cast<int>(_status);
}

void OcctlCore::runtime_shutdown(void) { // NOLINT
    ::occtl_runtime_shutdown();
}

void OcctlCore::runtime_version(const Ref<OcctlUint32>& out_major, const Ref<OcctlUint32>& out_minor, const Ref<OcctlUint32>& out_patch) { // NOLINT
    uint32_t _out_major_val = {};
    uint32_t _out_minor_val = {};
    uint32_t _out_patch_val = {};
    ::occtl_runtime_version(&_out_major_val, &_out_minor_val, &_out_patch_val);
    if (out_major.is_valid()) out_major->copy_from_c(_out_major_val);
    if (out_minor.is_valid()) out_minor->copy_from_c(_out_minor_val);
    if (out_patch.is_valid()) out_patch->copy_from_c(_out_patch_val);
}

int OcctlCore::runtime_abi_version(void) { // NOLINT
    auto _result = ::occtl_runtime_abi_version();
    return static_cast<int>(_result);
}

String OcctlCore::runtime_occt_version(void) { // NOLINT
    auto _result = ::occtl_runtime_occt_version();
    return String(_result);
}

int OcctlCore::uid_to_bytes(int64_t uid, const Ref<OcctlByteArray>& out_bytes) { // NOLINT
    uint8_t _out_bytes_buf[16] = {};
    occtl_status_t _status = ::occtl_uid_to_bytes(occtl_uid_t{static_cast<uint64_t>(uid)}, _out_bytes_buf);
    if (out_bytes.is_valid()) {
        PackedByteArray _ba;
        _ba.resize(16);
        for (int _i = 0; _i < 16; ++_i) _ba[_i] = _out_bytes_buf[_i];
        out_bytes->copy_from_c(_ba);
    }
    return static_cast<int>(_status);
}

int OcctlCore::uid_from_bytes(const PackedByteArray& in_bytes, const Ref<OcctlUid>& out_uid) { // NOLINT
    const uint8_t* _in_bytes_c = in_bytes.ptr();
    occtl_uid_t _out_uid_val = {};
    occtl_status_t _status = ::occtl_uid_from_bytes(_in_bytes_c, &_out_uid_val);
    if (out_uid.is_valid()) out_uid->copy_from_c(_out_uid_val);
    return static_cast<int>(_status);
}

int OcctlCore::uid_equal(int64_t a, int64_t b) { // NOLINT
    auto _result = ::occtl_uid_equal(occtl_uid_t{static_cast<uint64_t>(a)}, occtl_uid_t{static_cast<uint64_t>(b)});
    return static_cast<int>(_result);
}
