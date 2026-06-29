#ifndef OCCTLSELECTMETADATAFILTER_H
#define OCCTLSELECTMETADATAFILTER_H

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


using namespace godot;

class OcctlSelectMetadataFilter : public godot::RefCounted {
    GDCLASS(OcctlSelectMetadataFilter, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    int struct_version;
    int64_t p_next;
    String key;
    int key_len;
    String value;
    int value_len;
    int match_value;

    int get_struct_version() const;
    void set_struct_version(int val);
    int64_t get_p_next() const;
    void set_p_next(int64_t val);
    String get_key() const;
    void set_key(String val);
    int get_key_len() const;
    void set_key_len(int val);
    String get_value() const;
    void set_value(String val);
    int get_value_len() const;
    void set_value_len(int val);
    int get_match_value() const;
    void set_match_value(int val);

    occtl_select_metadata_filter_t to_c() const;
    static Ref<OcctlSelectMetadataFilter> from_c(const occtl_select_metadata_filter_t& val);
    void copy_from_c(const occtl_select_metadata_filter_t& val);
};

#endif // OCCTLSELECTMETADATAFILTER_H
