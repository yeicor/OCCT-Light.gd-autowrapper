#include "module_parts.h"

#include "OcctlDouble.h"
#include "OcctlString.h"
#include "OcctlStringArray.h"
#include "OcctlByteArray.h"

void gdext_initialize_module_part_7(ModuleInitializationLevel p_level) {
    (void)p_level;
    GDREGISTER_CLASS(OcctlDouble);
    GDREGISTER_CLASS(OcctlString);
    GDREGISTER_CLASS(OcctlStringArray);
    GDREGISTER_CLASS(OcctlByteArray);
}

void gdext_uninitialize_module_part_7(ModuleInitializationLevel p_level) {
    (void)p_level;
}
