#ifndef OCCTLMATERIALINFO_H
#define OCCTLMATERIALINFO_H

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
#include "occtl/occtl_topo_build.h"

#include "OcctlColorRgba.h"
#include "OcctlUid.h"

using namespace godot;

class OcctlMaterialInfo : public godot::RefCounted {
    GDCLASS(OcctlMaterialInfo, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    String name;
    int name_len;
    int has_density;
    double density;
    int has_diffuse_color;
    Ref<OcctlColorRgba> diffuse_color;
    int64_t metadata_uid;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    String get_name() const;
    void set_name(String val);
    int get_name_len() const;
    void set_name_len(int val);
    int get_has_density() const;
    void set_has_density(int val);
    double get_density() const;
    void set_density(double val);
    int get_has_diffuse_color() const;
    void set_has_diffuse_color(int val);
    Ref<OcctlColorRgba> get_diffuse_color() const;
    void set_diffuse_color(Ref<OcctlColorRgba> val);
    int64_t get_metadata_uid() const;
    void set_metadata_uid(int64_t val);

    occtl_material_info_t to_c() const;
    static Ref<OcctlMaterialInfo> from_c(const occtl_material_info_t& val);
    void copy_from_c(const occtl_material_info_t& val);
};

#endif // OCCTLMATERIALINFO_H
