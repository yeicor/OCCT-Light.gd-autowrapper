#ifndef OCCTLTOPOAXISHITITERHANDLE_H
#define OCCTLTOPOAXISHITITERHANDLE_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <cstdint>
#include "occtl/occtl_topo_relation.h"
#include "occtl/occtl_topo_relation.h"

using namespace godot;

class OcctlTopoAxisHitIterHandle : public godot::RefCounted {
    GDCLASS(OcctlTopoAxisHitIterHandle, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    occtl_topo_axis_hit_iter_t* _handle = nullptr;
    bool _owns = true;

    ~OcctlTopoAxisHitIterHandle() {
        if (_owns && _handle) {
            ::occtl_topo_axis_hit_iter_free(_handle);
            _handle = nullptr;
        }
    }

    void set_handle(int64_t h);
    int64_t get_handle() const;
    bool is_valid() const;
    int64_t release();
    void free();
};

#endif // OCCTLTOPOAXISHITITERHANDLE_H
