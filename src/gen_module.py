"""Generate module.h and module.cpp for autowrapper class registration.

These files provide the GDExtension entry point that registers all
generated wrapper, value-type, and handle classes with Godot.
"""

from pathlib import Path


def generate_module_h(
    wrapper_names: list[str],
    value_type_names: list[str],
    handle_class_names: list[str],
) -> str:
    """Generate module.h content."""
    all_headers: list[str] = []
    for n in wrapper_names:
        all_headers.append(f'#include "{n}.h"')
    for n in value_type_names:
        all_headers.append(f'#include "{n}.h"')
    for n in handle_class_names:
        all_headers.append(f'#include "{n}.h"')

    # Deduplicate and sort
    seen: set[str] = set()
    unique_headers: list[str] = []
    for h in all_headers:
        if h not in seen:
            seen.add(h)
            unique_headers.append(h)

    lines: list[str] = [
        "#ifndef GDEXT_MODULE_H",
        "#define GDEXT_MODULE_H",
        "",
        "#include <gdextension_interface.h>",
        "#include <godot_cpp/godot.hpp>",
        "#include <godot_cpp/core/class_db.hpp>",
        "",
    ]
    lines.extend(unique_headers)
    lines += [
        "",
        "using namespace godot;",
        "",
        "void gdext_initialize_module_auto(ModuleInitializationLevel p_level);",
        "void gdext_uninitialize_module_auto(ModuleInitializationLevel p_level);",
        "",
        "extern \"C\" {",
        "    GDExtensionBool GDE_EXPORT gdext_library_init_auto(",
        "        GDExtensionInterfaceGetProcAddress p_get_proc_address,",
        "        GDExtensionClassLibraryPtr p_library,",
        "        GDExtensionInitialization *r_initialization",
        "    );",
        "}",
        "",
        "#endif // GDEXT_MODULE_H",
        "",
    ]
    return "\n".join(lines)


def generate_module_cpp(
    wrapper_names: list[str],
    value_type_names: list[str],
    handle_class_names: list[str],
) -> str:
    """Generate module.cpp content with GDREGISTER_CLASS for all classes."""
    all_classes: list[str] = list(wrapper_names)
    all_classes.extend(value_type_names)
    all_classes.extend(handle_class_names)

    reg_lines: list[str] = []
    for cls in all_classes:
        reg_lines.append(f"    GDREGISTER_CLASS({cls});")

    lines: list[str] = [
        '#include "module.h"',
        "#include <gdextension_interface.h>",
        "#include <godot_cpp/godot.hpp>",
        "#include <godot_cpp/core/class_db.hpp>",
        "#include <godot_cpp/core/defs.hpp>",
        "",
        "void gdext_initialize_module_auto(ModuleInitializationLevel p_level) {",
        "    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {",
        "        return;",
        "    }",
        "",
        "    // Register wrapped classes",
    ]
    lines.extend(reg_lines)
    lines += [
        "}",
        "",
        "void gdext_uninitialize_module_auto(ModuleInitializationLevel p_level) {",
        "    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {",
        "        return;",
        "    }",
        "}",
        "",
        "extern \"C\" {",
        "    GDExtensionBool GDE_EXPORT gdext_library_init_auto(",
        "        GDExtensionInterfaceGetProcAddress p_get_proc_address,",
        "        GDExtensionClassLibraryPtr p_library,",
        "        GDExtensionInitialization *r_initialization",
        "    ) {",
        "        const godot::GDExtensionBinding::InitObject init_obj(",
        "            p_get_proc_address, p_library, r_initialization",
        "        );",
        "",
        "        init_obj.register_initializer(gdext_initialize_module_auto);",
        "        init_obj.register_terminator(gdext_uninitialize_module_auto);",
        "        init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);",
        "",
        "        return init_obj.init();",
        "    }",
        "}",
        "",
    ]
    return "\n".join(lines)
