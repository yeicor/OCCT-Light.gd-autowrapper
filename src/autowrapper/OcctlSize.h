#ifndef OCCTLSIZE_H
#define OCCTLSIZE_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <cstdint>

using namespace godot;

class OcctlSize : public godot::RefCounted {
    GDCLASS(OcctlSize, godot::RefCounted)
    size_t _value{};
protected:
    static void _bind_methods();
public:
    int64_t get_value() const;
    void set_value(int64_t v);
    void copy_from_c(const size_t& v);
};

#endif // OCCTLSIZE_H
