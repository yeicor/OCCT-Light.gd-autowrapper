#include "module_parts.h"

#include "OcctlTopoSewOptions.h"
#include "OcctlTopoSewResult.h"
#include "OcctlTopoSameParameterOptions.h"
#include "OcctlTopoCheckIssue.h"
#include "OcctlTopoFilletOptions.h"
#include "OcctlTopoEdgeBlendOptions.h"
#include "OcctlTopoMaxFilletRadiusOptions.h"
#include "OcctlTopoProjectOnFaceOptions.h"
#include "OcctlTopoWrapOnFaceOptions.h"
#include "OcctlTopoProjectFaceDirectionOptions.h"
#include "OcctlTopoFaceToArcsOptions.h"
#include "OcctlTopoHlrOptions.h"
#include "OcctlTopoHlrResult.h"
#include "OcctlTopoDraftFacesOptions.h"
#include "OcctlTopoDefeatureOptions.h"
#include "OcctlTopoOffsetFeaturesOptions.h"
#include "OcctlTopoFillingOptions.h"
#include "OcctlTopoFillingPatchEdge.h"
#include "OcctlTopoFillingPatchOptions.h"
#include "OcctlTopoSplitByPlaneOptions.h"
#include "OcctlTopoSectionPlane.h"
#include "OcctlTopoSectionByPlanesOptions.h"
#include "OcctlTopoExtrudeFacesOptions.h"
#include "OcctlTopoLinearPatternOptions.h"
#include "OcctlTopoCircularPatternOptions.h"
#include "OcctlTopoMakeVertexInfo.h"
#include "OcctlTopoMakeEdgeInfo.h"
#include "OcctlTopoMakeWireInfo.h"
#include "OcctlTopoEdgesToWiresOptions.h"
#include "OcctlTopoWireOffset2dOptions.h"
#include "OcctlTopoWireFixDegenerateEdgesOptions.h"
#include "OcctlTopoFaceChamfer2dOptions.h"
#include "OcctlTopoWireChamfer2dOptions.h"
#include "OcctlTopoMakeFaceInfo.h"
#include "OcctlTopoMakeFaceFromWiresAutoOptions.h"
#include "OcctlTopoMakeShellInfo.h"
#include "OcctlTopoMakeSolidInfo.h"
#include "OcctlTopoMakeCompoundInfo.h"
#include "OcctlTopoMakeCompsolidInfo.h"
#include "OcctlColorRgba.h"

void gdext_initialize_module_part_5(ModuleInitializationLevel p_level) {
    (void)p_level;
    GDREGISTER_CLASS(OcctlTopoSewOptions);
    GDREGISTER_CLASS(OcctlTopoSewResult);
    GDREGISTER_CLASS(OcctlTopoSameParameterOptions);
    GDREGISTER_CLASS(OcctlTopoCheckIssue);
    GDREGISTER_CLASS(OcctlTopoFilletOptions);
    GDREGISTER_CLASS(OcctlTopoEdgeBlendOptions);
    GDREGISTER_CLASS(OcctlTopoMaxFilletRadiusOptions);
    GDREGISTER_CLASS(OcctlTopoProjectOnFaceOptions);
    GDREGISTER_CLASS(OcctlTopoWrapOnFaceOptions);
    GDREGISTER_CLASS(OcctlTopoProjectFaceDirectionOptions);
    GDREGISTER_CLASS(OcctlTopoFaceToArcsOptions);
    GDREGISTER_CLASS(OcctlTopoHlrOptions);
    GDREGISTER_CLASS(OcctlTopoHlrResult);
    GDREGISTER_CLASS(OcctlTopoDraftFacesOptions);
    GDREGISTER_CLASS(OcctlTopoDefeatureOptions);
    GDREGISTER_CLASS(OcctlTopoOffsetFeaturesOptions);
    GDREGISTER_CLASS(OcctlTopoFillingOptions);
    GDREGISTER_CLASS(OcctlTopoFillingPatchEdge);
    GDREGISTER_CLASS(OcctlTopoFillingPatchOptions);
    GDREGISTER_CLASS(OcctlTopoSplitByPlaneOptions);
    GDREGISTER_CLASS(OcctlTopoSectionPlane);
    GDREGISTER_CLASS(OcctlTopoSectionByPlanesOptions);
    GDREGISTER_CLASS(OcctlTopoExtrudeFacesOptions);
    GDREGISTER_CLASS(OcctlTopoLinearPatternOptions);
    GDREGISTER_CLASS(OcctlTopoCircularPatternOptions);
    GDREGISTER_CLASS(OcctlTopoMakeVertexInfo);
    GDREGISTER_CLASS(OcctlTopoMakeEdgeInfo);
    GDREGISTER_CLASS(OcctlTopoMakeWireInfo);
    GDREGISTER_CLASS(OcctlTopoEdgesToWiresOptions);
    GDREGISTER_CLASS(OcctlTopoWireOffset2dOptions);
    GDREGISTER_CLASS(OcctlTopoWireFixDegenerateEdgesOptions);
    GDREGISTER_CLASS(OcctlTopoFaceChamfer2dOptions);
    GDREGISTER_CLASS(OcctlTopoWireChamfer2dOptions);
    GDREGISTER_CLASS(OcctlTopoMakeFaceInfo);
    GDREGISTER_CLASS(OcctlTopoMakeFaceFromWiresAutoOptions);
    GDREGISTER_CLASS(OcctlTopoMakeShellInfo);
    GDREGISTER_CLASS(OcctlTopoMakeSolidInfo);
    GDREGISTER_CLASS(OcctlTopoMakeCompoundInfo);
    GDREGISTER_CLASS(OcctlTopoMakeCompsolidInfo);
    GDREGISTER_CLASS(OcctlColorRgba);
}

void gdext_uninitialize_module_part_5(ModuleInitializationLevel p_level) {
    (void)p_level;
}
