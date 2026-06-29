#ifndef OCCTLMETADATAKEYVIEW_H
#define OCCTLMETADATAKEYVIEW_H

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

class OcctlMetadataKeyView : public godot::RefCounted {
    GDCLASS(OcctlMetadataKeyView, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    String key;
    int key_len;

    String get_key() const;
    void set_key(String val);
    int get_key_len() const;
    void set_key_len(int val);

    occtl_metadata_key_view_t to_c() const;
    static Ref<OcctlMetadataKeyView> from_c(const occtl_metadata_key_view_t& val);
    void copy_from_c(const occtl_metadata_key_view_t& val);
};

#endif // OCCTLMETADATAKEYVIEW_H
