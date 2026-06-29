#ifndef OCCTLBYTEARRAY_H
#define OCCTLBYTEARRAY_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/packed_byte_array.hpp>

using namespace godot;

class OcctlByteArray : public godot::RefCounted {
    GDCLASS(OcctlByteArray, godot::RefCounted)
    PackedByteArray _value{};
protected:
    static void _bind_methods();
public:
    PackedByteArray get_value() const;
    void set_value(const PackedByteArray& v);
    int64_t size() const;
    void copy_from_c(const PackedByteArray& v);
};

#endif // OCCTLBYTEARRAY_H
