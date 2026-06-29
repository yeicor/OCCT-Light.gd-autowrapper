#ifndef OCCTLSTRINGARRAY_H
#define OCCTLSTRINGARRAY_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/packed_string_array.hpp>

using namespace godot;

class OcctlStringArray : public godot::RefCounted {
    GDCLASS(OcctlStringArray, godot::RefCounted)
    PackedStringArray _value{};
protected:
    static void _bind_methods();
public:
    PackedStringArray get_strings() const;
    void set_strings(const PackedStringArray& v);
    int64_t get_count() const;
    void copy_from_c(const PackedStringArray& v);
};

#endif // OCCTLSTRINGARRAY_H
