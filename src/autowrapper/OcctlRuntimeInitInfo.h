#ifndef OCCTLRUNTIMEINITINFO_H
#define OCCTLRUNTIMEINITINFO_H

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


using namespace godot;

class OcctlRuntimeInitInfo : public godot::RefCounted {
    GDCLASS(OcctlRuntimeInitInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);

    occtl_runtime_init_info_t to_c() const;
    static Ref<OcctlRuntimeInitInfo> from_c(const occtl_runtime_init_info_t& val);
    void copy_from_c(const occtl_runtime_init_info_t& val);
};

#endif // OCCTLRUNTIMEINITINFO_H
