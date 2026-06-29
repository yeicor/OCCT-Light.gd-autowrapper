#ifndef OCCTLIOSTEPWRITEOPTIONS_H
#define OCCTLIOSTEPWRITEOPTIONS_H

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
#include "occtl/occtl_io_step.h"


using namespace godot;

class OcctlIoStepWriteOptions : public godot::RefCounted {
    GDCLASS(OcctlIoStepWriteOptions, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    int unit;
    int schema;
    int write_surface_curves;
    int write_tessellated;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    int get_unit() const;
    void set_unit(int val);
    int get_schema() const;
    void set_schema(int val);
    int get_write_surface_curves() const;
    void set_write_surface_curves(int val);
    int get_write_tessellated() const;
    void set_write_tessellated(int val);

    occtl_io_step_write_options_t to_c() const;
    static Ref<OcctlIoStepWriteOptions> from_c(const occtl_io_step_write_options_t& val);
    void copy_from_c(const occtl_io_step_write_options_t& val);
};

#endif // OCCTLIOSTEPWRITEOPTIONS_H
