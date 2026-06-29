#include "module_parts.h"

#include "OcctlMaterialInfo.h"
#include "OcctlJointInfo.h"
#include "OcctlMetadataKeyView.h"
#include "OcctlTagView.h"
#include "OcctlSelectBbox.h"
#include "OcctlGraphObb.h"
#include "OcctlGraphUvBounds.h"
#include "OcctlGraphMassProperties.h"
#include "OcctlSelectOptions.h"
#include "OcctlSelectMetadataFilter.h"
#include "OcctlSelectDistanceToNodeSort.h"
#include "OcctlSelectGroupOptions.h"
#include "OcctlSelectGroupView.h"
#include "OcctlOrientedNode.h"
#include "OcctlTopoChildExplorerConfig.h"
#include "OcctlTopoParentExplorerConfig.h"
#include "OcctlTopoRelationOptions.h"
#include "OcctlTopoDistancePair.h"
#include "OcctlTopoAxisHit.h"
#include "OcctlTopoTouchHit.h"
#include "OcctlNodeId.h"
#include "OcctlRefId.h"
#include "OcctlRefUid.h"
#include "OcctlRepUid.h"
#include "OcctlJointId.h"
#include "OcctlGraphHandle.h"
#include "OcctlNodeIterHandle.h"
#include "OcctlSelectIterHandle.h"
#include "OcctlSelectGroupIterHandle.h"
#include "OcctlTopoExplorerIterHandle.h"
#include "OcctlTopoRelatedIterHandle.h"
#include "OcctlTopoAxisHitIterHandle.h"
#include "OcctlTopoTouchIterHandle.h"
#include "OcctlTopoIntersectionIterHandle.h"
#include "OcctlUint32.h"
#include "OcctlInt32.h"
#include "OcctlUint8.h"
#include "OcctlSize.h"
#include "OcctlInt64.h"
#include "OcctlUint64.h"

void gdext_initialize_module_part_6(ModuleInitializationLevel p_level) {
    (void)p_level;
    GDREGISTER_CLASS(OcctlMaterialInfo);
    GDREGISTER_CLASS(OcctlJointInfo);
    GDREGISTER_CLASS(OcctlMetadataKeyView);
    GDREGISTER_CLASS(OcctlTagView);
    GDREGISTER_CLASS(OcctlSelectBbox);
    GDREGISTER_CLASS(OcctlGraphObb);
    GDREGISTER_CLASS(OcctlGraphUvBounds);
    GDREGISTER_CLASS(OcctlGraphMassProperties);
    GDREGISTER_CLASS(OcctlSelectOptions);
    GDREGISTER_CLASS(OcctlSelectMetadataFilter);
    GDREGISTER_CLASS(OcctlSelectDistanceToNodeSort);
    GDREGISTER_CLASS(OcctlSelectGroupOptions);
    GDREGISTER_CLASS(OcctlSelectGroupView);
    GDREGISTER_CLASS(OcctlOrientedNode);
    GDREGISTER_CLASS(OcctlTopoChildExplorerConfig);
    GDREGISTER_CLASS(OcctlTopoParentExplorerConfig);
    GDREGISTER_CLASS(OcctlTopoRelationOptions);
    GDREGISTER_CLASS(OcctlTopoDistancePair);
    GDREGISTER_CLASS(OcctlTopoAxisHit);
    GDREGISTER_CLASS(OcctlTopoTouchHit);
    GDREGISTER_CLASS(OcctlNodeId);
    GDREGISTER_CLASS(OcctlRefId);
    GDREGISTER_CLASS(OcctlRefUid);
    GDREGISTER_CLASS(OcctlRepUid);
    GDREGISTER_CLASS(OcctlJointId);
    GDREGISTER_CLASS(OcctlGraphHandle);
    GDREGISTER_CLASS(OcctlNodeIterHandle);
    GDREGISTER_CLASS(OcctlSelectIterHandle);
    GDREGISTER_CLASS(OcctlSelectGroupIterHandle);
    GDREGISTER_CLASS(OcctlTopoExplorerIterHandle);
    GDREGISTER_CLASS(OcctlTopoRelatedIterHandle);
    GDREGISTER_CLASS(OcctlTopoAxisHitIterHandle);
    GDREGISTER_CLASS(OcctlTopoTouchIterHandle);
    GDREGISTER_CLASS(OcctlTopoIntersectionIterHandle);
    GDREGISTER_CLASS(OcctlUint32);
    GDREGISTER_CLASS(OcctlInt32);
    GDREGISTER_CLASS(OcctlUint8);
    GDREGISTER_CLASS(OcctlSize);
    GDREGISTER_CLASS(OcctlInt64);
    GDREGISTER_CLASS(OcctlUint64);
}

void gdext_uninitialize_module_part_6(ModuleInitializationLevel p_level) {
    (void)p_level;
}
