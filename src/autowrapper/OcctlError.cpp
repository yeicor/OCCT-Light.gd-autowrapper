#include "OcctlError.h"

#include "OcctlUid.h"

int OcctlError::get_status() const { return status; }
void OcctlError::set_status(int val) { status = val; }

String OcctlError::get_message() const { return message; }
void OcctlError::set_message(String val) { message = val; }

int64_t OcctlError::get_source() const { return source; }
void OcctlError::set_source(int64_t val) { source = val; }

int OcctlError::get_extended() const { return extended; }
void OcctlError::set_extended(int val) { extended = val; }

void OcctlError::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("get_status"), &OcctlError::get_status);
    godot::ClassDB::bind_method(godot::D_METHOD("set_status", "val"), &OcctlError::set_status);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "status"), "set_status", "get_status");
    godot::ClassDB::bind_method(godot::D_METHOD("get_message"), &OcctlError::get_message);
    godot::ClassDB::bind_method(godot::D_METHOD("set_message", "val"), &OcctlError::set_message);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "message"), "set_message", "get_message");
    godot::ClassDB::bind_method(godot::D_METHOD("get_source"), &OcctlError::get_source);
    godot::ClassDB::bind_method(godot::D_METHOD("set_source", "val"), &OcctlError::set_source);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "source"), "set_source", "get_source");
    godot::ClassDB::bind_method(godot::D_METHOD("get_extended"), &OcctlError::get_extended);
    godot::ClassDB::bind_method(godot::D_METHOD("set_extended", "val"), &OcctlError::set_extended);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "extended"), "set_extended", "get_extended");
    godot::ClassDB::bind_static_method("OcctlError", godot::D_METHOD("from_values", "status", "message"), &OcctlError::from_values);
}

occtl_error_t OcctlError::to_c() const {
    occtl_error_t result = {};
    result.status = static_cast<occtl_status_t>(status);
    // const pointer field message: not convertible (type String)
    result.source.bits = static_cast<uint64_t>(source);
    result.extended = extended;
    return result;
}

Ref<OcctlError> OcctlError::from_c(const occtl_error_t& val) {
    Ref<OcctlError> r;
    r.instantiate();
    r->status = static_cast<int>(val.status);
    if (val.message) r->message = String(val.message);
    r->source = static_cast<int64_t>(val.source.bits);
    r->extended = val.extended;
    return r;
}

void OcctlError::copy_from_c(const occtl_error_t& val) {
    status = static_cast<int>(val.status);
    if (val.message) message = String(val.message);
    source = static_cast<int64_t>(val.source.bits);
    extended = val.extended;
}

Ref<OcctlError> OcctlError::from_values(int status, String message) {
    Ref<OcctlError> instance;
    instance.instantiate();
    instance->status = status;
    instance->message = message;
    return instance;
}
