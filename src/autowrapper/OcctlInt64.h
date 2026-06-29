#ifndef OCCTLINT64_H
#define OCCTLINT64_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <cstdint>

using namespace godot;

class OcctlInt64 : public godot::RefCounted {
    GDCLASS(OcctlInt64, godot::RefCounted)
    int64_t _value{};
protected:
    static void _bind_methods();
public:
    int64_t get_value() const;
    void set_value(int64_t v);
    void copy_from_c(const int64_t& v);
};

#endif // OCCTLINT64_H
