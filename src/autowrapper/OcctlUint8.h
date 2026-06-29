#ifndef OCCTLUINT8_H
#define OCCTLUINT8_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <cstdint>

using namespace godot;

class OcctlUint8 : public godot::RefCounted {
    GDCLASS(OcctlUint8, godot::RefCounted)
    uint8_t _value{};
protected:
    static void _bind_methods();
public:
    int64_t get_value() const;
    void set_value(int64_t v);
    void copy_from_c(const uint8_t& v);
};

#endif // OCCTLUINT8_H
