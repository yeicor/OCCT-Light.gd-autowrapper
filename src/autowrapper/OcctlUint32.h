#ifndef OCCTLUINT32_H
#define OCCTLUINT32_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <cstdint>

using namespace godot;

class OcctlUint32 : public godot::RefCounted {
    GDCLASS(OcctlUint32, godot::RefCounted)
    uint32_t _value{};
protected:
    static void _bind_methods();
public:
    int64_t get_value() const;
    void set_value(int64_t v);
    void copy_from_c(const uint32_t& v);
};

#endif // OCCTLUINT32_H
