#ifndef OCCTLCORE_H
#define OCCTLCORE_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/packed_byte_array.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/vector3.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/transform3d.hpp>
#include <godot_cpp/variant/aabb.hpp>
#include <godot_cpp/variant/color.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <cstdint>
#include "occtl/occtl_core.h"

#include "OcctlByteArray.h"
#include "OcctlError.h"
#include "OcctlRuntimeInitInfo.h"
#include "OcctlUid.h"
#include "OcctlUint32.h"

using namespace godot;

class OcctlCore : public godot::RefCounted {
    GDCLASS(OcctlCore, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    double const_OCCTL_PI(); // NOLINT
    double const_OCCTL_ANGLE_1_DEG_RAD(); // NOLINT
    double const_OCCTL_ANGLE_90_DEG_RAD(); // NOLINT
    String status_to_string(int status); // NOLINT
    Ref<OcctlError> error_last(void); // NOLINT
    void error_clear(void); // NOLINT
    int runtime_init(const Ref<OcctlRuntimeInitInfo>& info); // NOLINT
    int runtime_init_info_init(const Ref<OcctlRuntimeInitInfo>& info); // NOLINT
    void runtime_shutdown(void); // NOLINT
    void runtime_version(const Ref<OcctlUint32>& out_major, const Ref<OcctlUint32>& out_minor, const Ref<OcctlUint32>& out_patch); // NOLINT
    int runtime_abi_version(void); // NOLINT
    String runtime_occt_version(void); // NOLINT
    int uid_to_bytes(int64_t uid, const Ref<OcctlByteArray>& out_bytes); // NOLINT
    int uid_from_bytes(const PackedByteArray& in_bytes, const Ref<OcctlUid>& out_uid); // NOLINT
    int uid_equal(int64_t a, int64_t b); // NOLINT
};

#endif // OCCTLCORE_H
