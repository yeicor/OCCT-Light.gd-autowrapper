#include "module_parts.h"

#include "OcctlGeomSphericalSurface.h"
#include "OcctlGeomConicalSurface.h"
#include "OcctlGeomToroidalSurface.h"
#include "OcctlHealOptions.h"
#include "OcctlHealUnifySameDomainOptions.h"
#include "OcctlIoBrepWriteOptions.h"
#include "OcctlIoGltfReadOptions.h"
#include "OcctlIoGltfWriteOptions.h"
#include "OcctlIoIgesReadOptions.h"
#include "OcctlIoIgesWriteOptions.h"
#include "OcctlIoObjReadOptions.h"
#include "OcctlIoObjWriteOptions.h"
#include "OcctlIoPlyWriteOptions.h"
#include "OcctlIoStepReadOptions.h"
#include "OcctlIoStepWriteOptions.h"
#include "OcctlIoStlWriteOptions.h"
#include "OcctlIoVrmlReadOptions.h"
#include "OcctlIoVrmlWriteOptions.h"
#include "OcctlAabb3.h"
#include "OcctlMeshOptions.h"
#include "OcctlMeshFromBuffersOptions.h"
#include "OcctlTriangulationView.h"
#include "OcctlPolygon3dView.h"
#include "OcctlPolygonOnTriView.h"
#include "OcctlMeshTriangleBuffersView.h"
#include "OcctlMeshTriangleAnalysisView.h"
#include "OcctlMeshTriangleComponentsOptions.h"
#include "OcctlMeshTriangleComponentsView.h"
#include "OcctlMeshTriangleComponentTrianglesView.h"
#include "OcctlMeshTriangleComponentBoundaryEdge.h"
#include "OcctlMeshTriangleComponentBoundaryChain.h"
#include "OcctlMeshComponentBoundaryPolyline.h"
#include "OcctlMeshTriangleComponentBoundaryView.h"
#include "OcctlMeshTriangleComponentBoundaryChainsView.h"
#include "OcctlMeshComponentBoundaryPolylinesView.h"
#include "OcctlMeshTriangleComponentSummary.h"
#include "OcctlMeshTriangleComponentSummariesView.h"
#include "OcctlMeshTrianglePlaneComponentsOptions.h"
#include "OcctlMeshTrianglePlaneComponent.h"
#include "OcctlMeshTrianglePlaneComponentsView.h"

void gdext_initialize_module_part_2(ModuleInitializationLevel p_level) {
    (void)p_level;
    GDREGISTER_CLASS(OcctlGeomSphericalSurface);
    GDREGISTER_CLASS(OcctlGeomConicalSurface);
    GDREGISTER_CLASS(OcctlGeomToroidalSurface);
    GDREGISTER_CLASS(OcctlHealOptions);
    GDREGISTER_CLASS(OcctlHealUnifySameDomainOptions);
    GDREGISTER_CLASS(OcctlIoBrepWriteOptions);
    GDREGISTER_CLASS(OcctlIoGltfReadOptions);
    GDREGISTER_CLASS(OcctlIoGltfWriteOptions);
    GDREGISTER_CLASS(OcctlIoIgesReadOptions);
    GDREGISTER_CLASS(OcctlIoIgesWriteOptions);
    GDREGISTER_CLASS(OcctlIoObjReadOptions);
    GDREGISTER_CLASS(OcctlIoObjWriteOptions);
    GDREGISTER_CLASS(OcctlIoPlyWriteOptions);
    GDREGISTER_CLASS(OcctlIoStepReadOptions);
    GDREGISTER_CLASS(OcctlIoStepWriteOptions);
    GDREGISTER_CLASS(OcctlIoStlWriteOptions);
    GDREGISTER_CLASS(OcctlIoVrmlReadOptions);
    GDREGISTER_CLASS(OcctlIoVrmlWriteOptions);
    GDREGISTER_CLASS(OcctlAabb3);
    GDREGISTER_CLASS(OcctlMeshOptions);
    GDREGISTER_CLASS(OcctlMeshFromBuffersOptions);
    GDREGISTER_CLASS(OcctlTriangulationView);
    GDREGISTER_CLASS(OcctlPolygon3dView);
    GDREGISTER_CLASS(OcctlPolygonOnTriView);
    GDREGISTER_CLASS(OcctlMeshTriangleBuffersView);
    GDREGISTER_CLASS(OcctlMeshTriangleAnalysisView);
    GDREGISTER_CLASS(OcctlMeshTriangleComponentsOptions);
    GDREGISTER_CLASS(OcctlMeshTriangleComponentsView);
    GDREGISTER_CLASS(OcctlMeshTriangleComponentTrianglesView);
    GDREGISTER_CLASS(OcctlMeshTriangleComponentBoundaryEdge);
    GDREGISTER_CLASS(OcctlMeshTriangleComponentBoundaryChain);
    GDREGISTER_CLASS(OcctlMeshComponentBoundaryPolyline);
    GDREGISTER_CLASS(OcctlMeshTriangleComponentBoundaryView);
    GDREGISTER_CLASS(OcctlMeshTriangleComponentBoundaryChainsView);
    GDREGISTER_CLASS(OcctlMeshComponentBoundaryPolylinesView);
    GDREGISTER_CLASS(OcctlMeshTriangleComponentSummary);
    GDREGISTER_CLASS(OcctlMeshTriangleComponentSummariesView);
    GDREGISTER_CLASS(OcctlMeshTrianglePlaneComponentsOptions);
    GDREGISTER_CLASS(OcctlMeshTrianglePlaneComponent);
    GDREGISTER_CLASS(OcctlMeshTrianglePlaneComponentsView);
}

void gdext_uninitialize_module_part_2(ModuleInitializationLevel p_level) {
    (void)p_level;
}
