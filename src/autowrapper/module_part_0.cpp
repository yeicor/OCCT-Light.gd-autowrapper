#include "module_parts.h"

#include "OcctlBool.h"
#include "OcctlCore.h"
#include "OcctlCurves.h"
#include "OcctlCurves2d.h"
#include "OcctlCurvesCommon.h"
#include "OcctlDe.h"
#include "OcctlGeom.h"
#include "OcctlHeal.h"
#include "OcctlIoBrep.h"
#include "OcctlIoGltf.h"
#include "OcctlIoIges.h"
#include "OcctlIoObj.h"
#include "OcctlIoPly.h"
#include "OcctlIoStep.h"
#include "OcctlIoStl.h"
#include "OcctlIoVrml.h"
#include "OcctlMesh.h"
#include "OcctlPrim.h"
#include "OcctlPrimFeature.h"
#include "OcctlPrimSketch.h"
#include "OcctlPrimSolid.h"
#include "OcctlPrimSweep.h"
#include "OcctlSurfaces.h"
#include "OcctlText.h"
#include "OcctlTopo.h"
#include "OcctlTopoAlgo.h"
#include "OcctlTopoBuild.h"
#include "OcctlTopoRelation.h"
#include "OcctlTopoTypes.h"
#include "OcctlBoolOptions.h"
#include "OcctlRepId.h"
#include "OcctlUid.h"
#include "OcctlError.h"
#include "OcctlRuntimeInitInfo.h"
#include "OcctlCurveBsplineCreateInfo.h"
#include "OcctlCurveBezierCreateInfo.h"
#include "OcctlCurveOffsetCreateInfo.h"
#include "OcctlCurveBspline.h"
#include "OcctlCurveAirfoilNaca4Info.h"
#include "OcctlCurveInterpolatedInfo.h"

void gdext_initialize_module_part_0(ModuleInitializationLevel p_level) {
    (void)p_level;
    GDREGISTER_CLASS(OcctlBool);
    GDREGISTER_CLASS(OcctlCore);
    GDREGISTER_CLASS(OcctlCurves);
    GDREGISTER_CLASS(OcctlCurves2d);
    GDREGISTER_CLASS(OcctlCurvesCommon);
    GDREGISTER_CLASS(OcctlDe);
    GDREGISTER_CLASS(OcctlGeom);
    GDREGISTER_CLASS(OcctlHeal);
    GDREGISTER_CLASS(OcctlIoBrep);
    GDREGISTER_CLASS(OcctlIoGltf);
    GDREGISTER_CLASS(OcctlIoIges);
    GDREGISTER_CLASS(OcctlIoObj);
    GDREGISTER_CLASS(OcctlIoPly);
    GDREGISTER_CLASS(OcctlIoStep);
    GDREGISTER_CLASS(OcctlIoStl);
    GDREGISTER_CLASS(OcctlIoVrml);
    GDREGISTER_CLASS(OcctlMesh);
    GDREGISTER_CLASS(OcctlPrim);
    GDREGISTER_CLASS(OcctlPrimFeature);
    GDREGISTER_CLASS(OcctlPrimSketch);
    GDREGISTER_CLASS(OcctlPrimSolid);
    GDREGISTER_CLASS(OcctlPrimSweep);
    GDREGISTER_CLASS(OcctlSurfaces);
    GDREGISTER_CLASS(OcctlText);
    GDREGISTER_CLASS(OcctlTopo);
    GDREGISTER_CLASS(OcctlTopoAlgo);
    GDREGISTER_CLASS(OcctlTopoBuild);
    GDREGISTER_CLASS(OcctlTopoRelation);
    GDREGISTER_CLASS(OcctlTopoTypes);
    GDREGISTER_CLASS(OcctlBoolOptions);
    GDREGISTER_CLASS(OcctlRepId);
    GDREGISTER_CLASS(OcctlUid);
    GDREGISTER_CLASS(OcctlError);
    GDREGISTER_CLASS(OcctlRuntimeInitInfo);
    GDREGISTER_CLASS(OcctlCurveBsplineCreateInfo);
    GDREGISTER_CLASS(OcctlCurveBezierCreateInfo);
    GDREGISTER_CLASS(OcctlCurveOffsetCreateInfo);
    GDREGISTER_CLASS(OcctlCurveBspline);
    GDREGISTER_CLASS(OcctlCurveAirfoilNaca4Info);
    GDREGISTER_CLASS(OcctlCurveInterpolatedInfo);
}

void gdext_uninitialize_module_part_0(ModuleInitializationLevel p_level) {
    (void)p_level;
}
