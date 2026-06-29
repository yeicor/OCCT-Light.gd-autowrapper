#ifndef OCCTLGRAPHHANDLE_H
#define OCCTLGRAPHHANDLE_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <cstdint>
#include "occtl/occtl_curves.h"
#include "occtl/occtl_topo.h"

using namespace godot;

class OcctlGraphHandle : public godot::RefCounted {
    GDCLASS(OcctlGraphHandle, godot::RefCounted)
protected:
    static void _bind_methods();
public:
    occtl_graph_t* _handle = nullptr;
    bool _owns = true;

    ~OcctlGraphHandle() {
        if (_owns && _handle) {
            ::occtl_graph_free(_handle);
            _handle = nullptr;
        }
    }

    void set_handle(int64_t h);
    int64_t get_handle() const;
    bool is_valid() const;
    int64_t release();
    void free();
};

#endif // OCCTLGRAPHHANDLE_H
