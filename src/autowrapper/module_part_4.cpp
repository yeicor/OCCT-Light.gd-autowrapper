#include "module_parts.h"

#include "OcctlPrimConeInfo.h"
#include "OcctlPrimTorusInfo.h"
#include "OcctlPrimWedgeInfo.h"
#include "OcctlPrimHalfspaceInfo.h"
#include "OcctlPrimPrismInfo.h"
#include "OcctlPrimTwistExtrusionInfo.h"
#include "OcctlPrimExtrudeTwistInfo.h"
#include "OcctlPrimRevolInfo.h"
#include "OcctlPrimPipeInfo.h"
#include "OcctlPrimLoftInfo.h"
#include "OcctlPrimPipeShellInfo.h"
#include "OcctlPrimPipeShellLinearLawInfo.h"
#include "OcctlPrimPipeShellInterpolatedLawInfo.h"
#include "OcctlPrimOffsetShapeInfo.h"
#include "OcctlPrimThickSolidInfo.h"
#include "OcctlSurfaceRevolutionCreateInfo.h"
#include "OcctlSurfaceExtrusionCreateInfo.h"
#include "OcctlSurfaceRectangularTrimmedCreateInfo.h"
#include "OcctlSurfaceOffsetCreateInfo.h"
#include "OcctlSurfaceBsplineCreateInfo.h"
#include "OcctlSurfaceBezierCreateInfo.h"
#include "OcctlSurfaceBspline.h"
#include "OcctlSurfaceInterpolatedInfo.h"
#include "OcctlSurfaceApproximatedInfo.h"
#include "OcctlSurfacePointGridCreateInfo.h"
#include "OcctlSurfaceBoundaryCurvesCreateInfo.h"
#include "OcctlSurfaceGordonCreateInfo.h"
#include "OcctlSurfaceCurveGridCreateInfo.h"
#include "OcctlTextInfo.h"
#include "OcctlTextLayoutOptions.h"
#include "OcctlTextMetrics.h"
#include "OcctlTopoMakeProductInfo.h"
#include "OcctlEdgeView.h"
#include "OcctlCoedgeView.h"
#include "OcctlFaceView.h"
#include "OcctlVertexView.h"
#include "OcctlWireView.h"
#include "OcctlShellView.h"
#include "OcctlSolidView.h"
#include "OcctlCompoundView.h"

void gdext_initialize_module_part_4(ModuleInitializationLevel p_level) {
    (void)p_level;
    GDREGISTER_CLASS(OcctlPrimConeInfo);
    GDREGISTER_CLASS(OcctlPrimTorusInfo);
    GDREGISTER_CLASS(OcctlPrimWedgeInfo);
    GDREGISTER_CLASS(OcctlPrimHalfspaceInfo);
    GDREGISTER_CLASS(OcctlPrimPrismInfo);
    GDREGISTER_CLASS(OcctlPrimTwistExtrusionInfo);
    GDREGISTER_CLASS(OcctlPrimExtrudeTwistInfo);
    GDREGISTER_CLASS(OcctlPrimRevolInfo);
    GDREGISTER_CLASS(OcctlPrimPipeInfo);
    GDREGISTER_CLASS(OcctlPrimLoftInfo);
    GDREGISTER_CLASS(OcctlPrimPipeShellInfo);
    GDREGISTER_CLASS(OcctlPrimPipeShellLinearLawInfo);
    GDREGISTER_CLASS(OcctlPrimPipeShellInterpolatedLawInfo);
    GDREGISTER_CLASS(OcctlPrimOffsetShapeInfo);
    GDREGISTER_CLASS(OcctlPrimThickSolidInfo);
    GDREGISTER_CLASS(OcctlSurfaceRevolutionCreateInfo);
    GDREGISTER_CLASS(OcctlSurfaceExtrusionCreateInfo);
    GDREGISTER_CLASS(OcctlSurfaceRectangularTrimmedCreateInfo);
    GDREGISTER_CLASS(OcctlSurfaceOffsetCreateInfo);
    GDREGISTER_CLASS(OcctlSurfaceBsplineCreateInfo);
    GDREGISTER_CLASS(OcctlSurfaceBezierCreateInfo);
    GDREGISTER_CLASS(OcctlSurfaceBspline);
    GDREGISTER_CLASS(OcctlSurfaceInterpolatedInfo);
    GDREGISTER_CLASS(OcctlSurfaceApproximatedInfo);
    GDREGISTER_CLASS(OcctlSurfacePointGridCreateInfo);
    GDREGISTER_CLASS(OcctlSurfaceBoundaryCurvesCreateInfo);
    GDREGISTER_CLASS(OcctlSurfaceGordonCreateInfo);
    GDREGISTER_CLASS(OcctlSurfaceCurveGridCreateInfo);
    GDREGISTER_CLASS(OcctlTextInfo);
    GDREGISTER_CLASS(OcctlTextLayoutOptions);
    GDREGISTER_CLASS(OcctlTextMetrics);
    GDREGISTER_CLASS(OcctlTopoMakeProductInfo);
    GDREGISTER_CLASS(OcctlEdgeView);
    GDREGISTER_CLASS(OcctlCoedgeView);
    GDREGISTER_CLASS(OcctlFaceView);
    GDREGISTER_CLASS(OcctlVertexView);
    GDREGISTER_CLASS(OcctlWireView);
    GDREGISTER_CLASS(OcctlShellView);
    GDREGISTER_CLASS(OcctlSolidView);
    GDREGISTER_CLASS(OcctlCompoundView);
}

void gdext_uninitialize_module_part_4(ModuleInitializationLevel p_level) {
    (void)p_level;
}
