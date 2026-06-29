#include "OcctlCurvesCommon.h"

#include "occtl/occtl_curves_common.h"

void OcctlCurvesCommon::_bind_methods() {
    BIND_CONSTANT(OCCTL_CURVE_TRIMMED_CREATE_INFO_VERSION_1);
    BIND_CONSTANT(OCCTL_CURVE_BEZIER_SEGMENTS_OPTIONS_VERSION_1);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_curve_kind_t", "OCCTL_CURVE_KIND_LINE", OCCTL_CURVE_KIND_LINE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_curve_kind_t", "OCCTL_CURVE_KIND_CIRCLE", OCCTL_CURVE_KIND_CIRCLE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_curve_kind_t", "OCCTL_CURVE_KIND_ELLIPSE", OCCTL_CURVE_KIND_ELLIPSE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_curve_kind_t", "OCCTL_CURVE_KIND_HYPERBOLA", OCCTL_CURVE_KIND_HYPERBOLA);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_curve_kind_t", "OCCTL_CURVE_KIND_PARABOLA", OCCTL_CURVE_KIND_PARABOLA);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_curve_kind_t", "OCCTL_CURVE_KIND_BSPLINE", OCCTL_CURVE_KIND_BSPLINE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_curve_kind_t", "OCCTL_CURVE_KIND_BEZIER", OCCTL_CURVE_KIND_BEZIER);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_curve_kind_t", "OCCTL_CURVE_KIND_TRIMMED", OCCTL_CURVE_KIND_TRIMMED);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_curve_kind_t", "OCCTL_CURVE_KIND_OFFSET", OCCTL_CURVE_KIND_OFFSET);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_curve_kind_t", "OCCTL_CURVE_KIND_UNDEFINED", OCCTL_CURVE_KIND_UNDEFINED);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_curve_kind_t", "OCCTL_CURVE_KIND_RESERVED_FUTURE", OCCTL_CURVE_KIND_RESERVED_FUTURE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_curve2d_tangency_qualifier_t", "OCCTL_GEOM_TANGENCY_UNQUALIFIED", OCCTL_GEOM_TANGENCY_UNQUALIFIED);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_curve2d_tangency_qualifier_t", "OCCTL_GEOM_TANGENCY_ENCLOSING", OCCTL_GEOM_TANGENCY_ENCLOSING);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_curve2d_tangency_qualifier_t", "OCCTL_GEOM_TANGENCY_ENCLOSED", OCCTL_GEOM_TANGENCY_ENCLOSED);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_curve2d_tangency_qualifier_t", "OCCTL_GEOM_TANGENCY_OUTSIDE", OCCTL_GEOM_TANGENCY_OUTSIDE);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_curve2d_tangency_qualifier_t", "OCCTL_GEOM_TANGENCY_NO_QUALIFIER", OCCTL_GEOM_TANGENCY_NO_QUALIFIER);
    godot::ClassDB::bind_integer_constant(get_class_static(), "occtl_curve2d_tangency_qualifier_t", "OCCTL_GEOM_TANGENCY_RESERVED_FUTURE", OCCTL_GEOM_TANGENCY_RESERVED_FUTURE);
    godot::ClassDB::bind_method(godot::D_METHOD("trimmed_create_info_init", "info"), &OcctlCurvesCommon::trimmed_create_info_init);
    godot::ClassDB::bind_method(godot::D_METHOD("bezier_segments_options_init", "options"), &OcctlCurvesCommon::bezier_segments_options_init);
}

void OcctlCurvesCommon::trimmed_create_info_init(const Ref<OcctlCurveTrimmedCreateInfo>& info) { // NOLINT
    occtl_curve_trimmed_create_info_t _info_val = {};
    ::occtl_curve_trimmed_create_info_init(&_info_val);
    ::occtl_curve_trimmed_create_info_init(&_info_val);
    if (info.is_valid()) info->copy_from_c(_info_val);
}

void OcctlCurvesCommon::bezier_segments_options_init(const Ref<OcctlCurveBezierSegmentsOptions>& options) { // NOLINT
    occtl_curve_bezier_segments_options_t _options_val = {};
    ::occtl_curve_bezier_segments_options_init(&_options_val);
    ::occtl_curve_bezier_segments_options_init(&_options_val);
    if (options.is_valid()) options->copy_from_c(_options_val);
}
