#ifndef OCCTLDOUBLE_H
#define OCCTLDOUBLE_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <cstdint>

using namespace godot;

class OcctlDouble : public godot::RefCounted {
    GDCLASS(OcctlDouble, godot::RefCounted)
    float _value{};
protected:
    static void _bind_methods();
public:
    double get_value() const;
    void set_value(double v);
    void copy_from_c(const float& v);
};

#endif // OCCTLDOUBLE_H
