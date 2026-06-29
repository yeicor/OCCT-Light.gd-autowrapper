#ifndef OCCTLSELECTITERHANDLE_H
#define OCCTLSELECTITERHANDLE_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <cstdint>
#include "occtl/occtl_topo_build.h"
#include "occtl/occtl_topo_build.h"

using namespace godot;

class OcctlSelectIterHandle : public godot::RefCounted {
    GDCLASS(OcctlSelectIterHandle, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    occtl_select_iter_t* _handle = nullptr;
    bool _owns = true;

    ~OcctlSelectIterHandle() {
        if (_owns && _handle) {
            ::occtl_select_iter_free(_handle);
            _handle = nullptr;
        }
    }

    void set_handle(int64_t h);
    int64_t get_handle() const;
    bool is_valid() const;
    int64_t release();
    void free();
};

#endif // OCCTLSELECTITERHANDLE_H
