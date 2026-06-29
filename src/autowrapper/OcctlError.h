#ifndef OCCTLERROR_H
#define OCCTLERROR_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/vector3.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/transform3d.hpp>
#include <godot_cpp/variant/aabb.hpp>
#include <godot_cpp/variant/color.hpp>
#include <cstdint>
#include <vector>
#include "occtl/occtl_core.h"

#include "OcctlUid.h"

using namespace godot;

class OcctlError : public godot::RefCounted {
    GDCLASS(OcctlError, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int status;
    String message;
    int64_t source;
    int extended;

    int get_status() const;
    void set_status(int val);
    String get_message() const;
    void set_message(String val);
    int64_t get_source() const;
    void set_source(int64_t val);
    int get_extended() const;
    void set_extended(int val);

    occtl_error_t to_c() const;
    static Ref<OcctlError> from_c(const occtl_error_t& val);
    void copy_from_c(const occtl_error_t& val);

    static Ref<OcctlError> from_values(int status, String message); // NOLINT
};

#endif // OCCTLERROR_H
