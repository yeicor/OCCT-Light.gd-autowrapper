#ifndef OCCTLSTRING_H
#define OCCTLSTRING_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/string.hpp>

using namespace godot;

class OcctlString : public godot::RefCounted {
    GDCLASS(OcctlString, godot::RefCounted)
    String _value{};
protected:
    static void _bind_methods();
public:
    String get_value() const;
    void set_value(const String& v);
    void copy_from_c(const char* v);
};

#endif // OCCTLSTRING_H
