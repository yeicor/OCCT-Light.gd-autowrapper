#ifndef OCCTLUINT64_H
#define OCCTLUINT64_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <cstdint>

using namespace godot;

class OcctlUint64 : public godot::RefCounted {
    GDCLASS(OcctlUint64, godot::RefCounted)
    uint64_t _value{};
protected:
    static void _bind_methods();
public:
    int64_t get_value() const;
    void set_value(int64_t v);
    void copy_from_c(const uint64_t& v);
};

#endif // OCCTLUINT64_H
