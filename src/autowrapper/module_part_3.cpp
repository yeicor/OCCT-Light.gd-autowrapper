#include "module_parts.h"

#include "OcctlMeshTriangleSphereComponentsOptions.h"
#include "OcctlMeshTriangleSphereComponent.h"
#include "OcctlMeshTriangleSphereComponentsView.h"
#include "OcctlMeshTriangleCylinderComponentsOptions.h"
#include "OcctlMeshTriangleCylinderComponent.h"
#include "OcctlMeshTriangleCylinderComponentsView.h"
#include "OcctlPrimFaceFromSurfaceOptions.h"
#include "OcctlPrimFaceFromPointGridOptions.h"
#include "OcctlPrimFaceFromBoundaryCurvesOptions.h"
#include "OcctlPrimFaceFromCurveGridOptions.h"
#include "OcctlPrimBrakeFormedOptions.h"
#include "OcctlPrimDraftPrismInfo.h"
#include "OcctlPrimExtrudeTaperedInfo.h"
#include "OcctlPrimRuledSurfaceInfo.h"
#include "OcctlPrimFeatPrismInfo.h"
#include "OcctlPrimExtrudeUntilInfo.h"
#include "OcctlPrimFeatDraftPrismInfo.h"
#include "OcctlPrimCylindricalHoleInfo.h"
#include "OcctlPrimPolylineInfo.h"
#include "OcctlPrimRegularPolygonInfo.h"
#include "OcctlPrimRectangleInfo.h"
#include "OcctlPrimCircleInfo.h"
#include "OcctlPrimEllipseInfo.h"
#include "OcctlPrimPlanarFaceInfo.h"
#include "OcctlPrimConvexHull2dInfo.h"
#include "OcctlPrimTraceInfo.h"
#include "OcctlPrimConstrainedEdgeInfo.h"
#include "OcctlPrimArc3ptInfo.h"
#include "OcctlPrimArcCenterInfo.h"
#include "OcctlPrimSplineInfo.h"
#include "OcctlPrimPlaneInfo.h"
#include "OcctlPrimDiskInfo.h"
#include "OcctlPrimSlotInfo.h"
#include "OcctlPrimTubeInfo.h"
#include "OcctlPrimHelixInfo.h"
#include "OcctlPrimFillet2dInfo.h"
#include "OcctlPrimFullRound2dInfo.h"
#include "OcctlPrimBoxInfo.h"
#include "OcctlPrimSphereInfo.h"
#include "OcctlPrimCylinderInfo.h"

void gdext_initialize_module_part_3(ModuleInitializationLevel p_level) {
    (void)p_level;
    GDREGISTER_CLASS(OcctlMeshTriangleSphereComponentsOptions);
    GDREGISTER_CLASS(OcctlMeshTriangleSphereComponent);
    GDREGISTER_CLASS(OcctlMeshTriangleSphereComponentsView);
    GDREGISTER_CLASS(OcctlMeshTriangleCylinderComponentsOptions);
    GDREGISTER_CLASS(OcctlMeshTriangleCylinderComponent);
    GDREGISTER_CLASS(OcctlMeshTriangleCylinderComponentsView);
    GDREGISTER_CLASS(OcctlPrimFaceFromSurfaceOptions);
    GDREGISTER_CLASS(OcctlPrimFaceFromPointGridOptions);
    GDREGISTER_CLASS(OcctlPrimFaceFromBoundaryCurvesOptions);
    GDREGISTER_CLASS(OcctlPrimFaceFromCurveGridOptions);
    GDREGISTER_CLASS(OcctlPrimBrakeFormedOptions);
    GDREGISTER_CLASS(OcctlPrimDraftPrismInfo);
    GDREGISTER_CLASS(OcctlPrimExtrudeTaperedInfo);
    GDREGISTER_CLASS(OcctlPrimRuledSurfaceInfo);
    GDREGISTER_CLASS(OcctlPrimFeatPrismInfo);
    GDREGISTER_CLASS(OcctlPrimExtrudeUntilInfo);
    GDREGISTER_CLASS(OcctlPrimFeatDraftPrismInfo);
    GDREGISTER_CLASS(OcctlPrimCylindricalHoleInfo);
    GDREGISTER_CLASS(OcctlPrimPolylineInfo);
    GDREGISTER_CLASS(OcctlPrimRegularPolygonInfo);
    GDREGISTER_CLASS(OcctlPrimRectangleInfo);
    GDREGISTER_CLASS(OcctlPrimCircleInfo);
    GDREGISTER_CLASS(OcctlPrimEllipseInfo);
    GDREGISTER_CLASS(OcctlPrimPlanarFaceInfo);
    GDREGISTER_CLASS(OcctlPrimConvexHull2dInfo);
    GDREGISTER_CLASS(OcctlPrimTraceInfo);
    GDREGISTER_CLASS(OcctlPrimConstrainedEdgeInfo);
    GDREGISTER_CLASS(OcctlPrimArc3ptInfo);
    GDREGISTER_CLASS(OcctlPrimArcCenterInfo);
    GDREGISTER_CLASS(OcctlPrimSplineInfo);
    GDREGISTER_CLASS(OcctlPrimPlaneInfo);
    GDREGISTER_CLASS(OcctlPrimDiskInfo);
    GDREGISTER_CLASS(OcctlPrimSlotInfo);
    GDREGISTER_CLASS(OcctlPrimTubeInfo);
    GDREGISTER_CLASS(OcctlPrimHelixInfo);
    GDREGISTER_CLASS(OcctlPrimFillet2dInfo);
    GDREGISTER_CLASS(OcctlPrimFullRound2dInfo);
    GDREGISTER_CLASS(OcctlPrimBoxInfo);
    GDREGISTER_CLASS(OcctlPrimSphereInfo);
    GDREGISTER_CLASS(OcctlPrimCylinderInfo);
}

void gdext_uninitialize_module_part_3(ModuleInitializationLevel p_level) {
    (void)p_level;
}
