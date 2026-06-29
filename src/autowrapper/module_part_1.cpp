#include "module_parts.h"

#include "OcctlCurveApproximatedInfo.h"
#include "OcctlCurveIntersectionPoint.h"
#include "OcctlCurve2dCircleTangentToTwoRadiusInfo.h"
#include "OcctlCurve2dBlendArcInfo.h"
#include "OcctlCurve2dLineTangentToTwoInfo.h"
#include "OcctlCurve2dLineTangentThroughPointInfo.h"
#include "OcctlCurve2dLineTangentWithAngleInfo.h"
#include "OcctlCurve2dCircleTangentToThreeInfo.h"
#include "OcctlCurve2dCircleTangentFixedCenterInfo.h"
#include "OcctlCurve2dCircleTangentCenterOnCurveInfo.h"
#include "OcctlCurve2dCircleTangentOnCurveRadiusInfo.h"
#include "OcctlCurve2dBsplineCreateInfo.h"
#include "OcctlCurve2dBezierCreateInfo.h"
#include "OcctlCurve2dOffsetCreateInfo.h"
#include "OcctlCurve2dBspline.h"
#include "OcctlCurveTrimmedCreateInfo.h"
#include "OcctlCurveBezierSegmentsOptions.h"
#include "OcctlDeFormatInfo.h"
#include "OcctlPoint2.h"
#include "OcctlVector2.h"
#include "OcctlDirection2.h"
#include "OcctlPoint3.h"
#include "OcctlVector3.h"
#include "OcctlDirection3.h"
#include "OcctlAxis1Placement.h"
#include "OcctlAxis2Placement.h"
#include "OcctlAxis3Placement.h"
#include "OcctlTransform.h"
#include "OcctlAxis2Placement2d.h"
#include "OcctlGeomCircle.h"
#include "OcctlGeomEllipse.h"
#include "OcctlGeomHyperbola.h"
#include "OcctlGeomParabola.h"
#include "OcctlGeom2dLine.h"
#include "OcctlGeom2dCircle.h"
#include "OcctlGeom2dEllipse.h"
#include "OcctlGeom2dHyperbola.h"
#include "OcctlGeom2dParabola.h"
#include "OcctlGeomPlane.h"
#include "OcctlGeomCylindricalSurface.h"

void gdext_initialize_module_part_1(ModuleInitializationLevel p_level) {
    (void)p_level;
    GDREGISTER_CLASS(OcctlCurveApproximatedInfo);
    GDREGISTER_CLASS(OcctlCurveIntersectionPoint);
    GDREGISTER_CLASS(OcctlCurve2dCircleTangentToTwoRadiusInfo);
    GDREGISTER_CLASS(OcctlCurve2dBlendArcInfo);
    GDREGISTER_CLASS(OcctlCurve2dLineTangentToTwoInfo);
    GDREGISTER_CLASS(OcctlCurve2dLineTangentThroughPointInfo);
    GDREGISTER_CLASS(OcctlCurve2dLineTangentWithAngleInfo);
    GDREGISTER_CLASS(OcctlCurve2dCircleTangentToThreeInfo);
    GDREGISTER_CLASS(OcctlCurve2dCircleTangentFixedCenterInfo);
    GDREGISTER_CLASS(OcctlCurve2dCircleTangentCenterOnCurveInfo);
    GDREGISTER_CLASS(OcctlCurve2dCircleTangentOnCurveRadiusInfo);
    GDREGISTER_CLASS(OcctlCurve2dBsplineCreateInfo);
    GDREGISTER_CLASS(OcctlCurve2dBezierCreateInfo);
    GDREGISTER_CLASS(OcctlCurve2dOffsetCreateInfo);
    GDREGISTER_CLASS(OcctlCurve2dBspline);
    GDREGISTER_CLASS(OcctlCurveTrimmedCreateInfo);
    GDREGISTER_CLASS(OcctlCurveBezierSegmentsOptions);
    GDREGISTER_CLASS(OcctlDeFormatInfo);
    GDREGISTER_CLASS(OcctlPoint2);
    GDREGISTER_CLASS(OcctlVector2);
    GDREGISTER_CLASS(OcctlDirection2);
    GDREGISTER_CLASS(OcctlPoint3);
    GDREGISTER_CLASS(OcctlVector3);
    GDREGISTER_CLASS(OcctlDirection3);
    GDREGISTER_CLASS(OcctlAxis1Placement);
    GDREGISTER_CLASS(OcctlAxis2Placement);
    GDREGISTER_CLASS(OcctlAxis3Placement);
    GDREGISTER_CLASS(OcctlTransform);
    GDREGISTER_CLASS(OcctlAxis2Placement2d);
    GDREGISTER_CLASS(OcctlGeomCircle);
    GDREGISTER_CLASS(OcctlGeomEllipse);
    GDREGISTER_CLASS(OcctlGeomHyperbola);
    GDREGISTER_CLASS(OcctlGeomParabola);
    GDREGISTER_CLASS(OcctlGeom2dLine);
    GDREGISTER_CLASS(OcctlGeom2dCircle);
    GDREGISTER_CLASS(OcctlGeom2dEllipse);
    GDREGISTER_CLASS(OcctlGeom2dHyperbola);
    GDREGISTER_CLASS(OcctlGeom2dParabola);
    GDREGISTER_CLASS(OcctlGeomPlane);
    GDREGISTER_CLASS(OcctlGeomCylindricalSurface);
}

void gdext_uninitialize_module_part_1(ModuleInitializationLevel p_level) {
    (void)p_level;
}
