#ifndef OCCTLINT32_H
#define OCCTLINT32_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <cstdint>

using namespace godot;

class OcctlInt32 : public godot::RefCounted {
    GDCLASS(OcctlInt32, godot::RefCounted)
    int _value{};
protected:
    static void _bind_methods();
public:
    int64_t get_value() const;
    void set_value(int64_t v);
    void copy_from_c(const int& v);
};

#endif // OCCTLINT32_H
