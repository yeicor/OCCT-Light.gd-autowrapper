#include "OcctlText.h"

#include "occtl/occtl_text.h"

void OcctlText::_bind_methods() {
    BIND_CONSTANT(OCCTL_TEXT_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_TEXT_LAYOUT_OPTIONS_VERSION_1);
    BIND_CONSTANT(OCCTL_TEXT_METRICS_VERSION_1);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_text_font_aspect_t", "OCCTL_TEXT_FONT_ASPECT_REGULAR", OCCTL_TEXT_FONT_ASPECT_REGULAR);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_text_font_aspect_t", "OCCTL_TEXT_FONT_ASPECT_BOLD", OCCTL_TEXT_FONT_ASPECT_BOLD);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_text_font_aspect_t", "OCCTL_TEXT_FONT_ASPECT_ITALIC", OCCTL_TEXT_FONT_ASPECT_ITALIC);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_text_font_aspect_t", "OCCTL_TEXT_FONT_ASPECT_BOLD_ITALIC", OCCTL_TEXT_FONT_ASPECT_BOLD_ITALIC);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_text_font_aspect_t", "OCCTL_TEXT_FONT_ASPECT_RESERVED_FUTURE", OCCTL_TEXT_FONT_ASPECT_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_text_halign_t", "OCCTL_TEXT_HALIGN_LEFT", OCCTL_TEXT_HALIGN_LEFT);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_text_halign_t", "OCCTL_TEXT_HALIGN_CENTER", OCCTL_TEXT_HALIGN_CENTER);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_text_halign_t", "OCCTL_TEXT_HALIGN_RIGHT", OCCTL_TEXT_HALIGN_RIGHT);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_text_halign_t", "OCCTL_TEXT_HALIGN_RESERVED_FUTURE", OCCTL_TEXT_HALIGN_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_text_valign_t", "OCCTL_TEXT_VALIGN_BOTTOM", OCCTL_TEXT_VALIGN_BOTTOM);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_text_valign_t", "OCCTL_TEXT_VALIGN_BASELINE", OCCTL_TEXT_VALIGN_BASELINE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_text_valign_t", "OCCTL_TEXT_VALIGN_CENTER", OCCTL_TEXT_VALIGN_CENTER);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_text_valign_t", "OCCTL_TEXT_VALIGN_TOP", OCCTL_TEXT_VALIGN_TOP);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_text_valign_t", "OCCTL_TEXT_VALIGN_RESERVED_FUTURE", OCCTL_TEXT_VALIGN_RESERVED_FUTURE);
    godot::ClassDB::bind_method(godot::D_METHOD("info_init", "info"), &OcctlText::info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("layout_options_init", "options"), &OcctlText::layout_options_init);
    godot::ClassDB::bind_method(godot::D_METHOD("metrics_init", "metrics"), &OcctlText::metrics_init);
    godot::ClassDB::bind_method(godot::D_METHOD("measure", "info", "out_metrics"), &OcctlText::measure, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("make_faces", "graph", "info", "out_compound"), &OcctlText::make_faces, DEFVAL(Variant()));
    godot::ClassDB::bind_method(godot::D_METHOD("make_wires", "graph", "info", "out_compound"), &OcctlText::make_wires, DEFVAL(Variant()));
}

void OcctlText::info_init(const Ref<OcctlTextInfo>& info) { // NOLINT
    occtl_text_info_t _info_val = {};
    ::occtl_text_info_init(&_info_val);
    ::occtl_text_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

void OcctlText::layout_options_init(const Ref<OcctlTextLayoutOptions>& options) { // NOLINT
    occtl_text_layout_options_t _options_val = {};
    ::occtl_text_layout_options_init(&_options_val);
    ::occtl_text_layout_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}

void OcctlText::metrics_init(const Ref<OcctlTextMetrics>& metrics) { // NOLINT
    occtl_text_metrics_t _metrics_val = {};
    ::occtl_text_metrics_init(&_metrics_val);
    ::occtl_text_metrics_init(&_metrics_val);
    if (metrics.is_valid()) metrics->copy_from_c(_metrics_val);
}

int OcctlText::measure(const Ref<OcctlTextInfo>& info, const Ref<OcctlTextMetrics>& out_metrics) { // NOLINT
    occtl_text_info_t _info_c = {};
    const occtl_text_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_text_metrics_t _out_metrics_val = {};
    ::occtl_text_metrics_init(&_out_metrics_val);
    occtl_status_t _status = ::occtl_text_measure(_info_ptr, &_out_metrics_val);
    if (out_metrics.is_valid()) out_metrics->copy_from_c(_out_metrics_val);
    return static_cast<int>(_status);
}

int OcctlText::make_faces(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTextInfo>& info, const Ref<OcctlNodeId>& out_compound) { // NOLINT
    occtl_text_info_t _info_c = {};
    const occtl_text_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_compound_val = {};
    occtl_status_t _status = ::occtl_text_make_faces(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_compound_val);
    if (out_compound.is_valid()) out_compound->copy_from_c(_out_compound_val);
    return static_cast<int>(_status);
}

int OcctlText::make_wires(const Ref<OcctlGraphHandle>& graph, const Ref<OcctlTextInfo>& info, const Ref<OcctlNodeId>& out_compound) { // NOLINT
    occtl_text_info_t _info_c = {};
    const occtl_text_info_t* _info_ptr = nullptr;
    if (info.is_valid()) { _info_c = info->to_c(); _info_ptr = &_info_c; }
    occtl_node_id_t _out_compound_val = {};
    occtl_status_t _status = ::occtl_text_make_wires(reinterpret_cast<occtl_graph_t*>(static_cast<uintptr_t>(graph.is_valid() ? graph->get_handle() : 0)), _info_ptr, &_out_compound_val);
    if (out_compound.is_valid()) out_compound->copy_from_c(_out_compound_val);
    return static_cast<int>(_status);
}
