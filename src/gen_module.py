"""Generate module.h, module.cpp, and module_part_<N>.cpp for autowrapper.

These files provide the GDExtension entry point that registers all
generated wrapper, value-type, and handle classes with Godot.

To avoid MinGW's "too many sections" assembler error when all 280+
GDREGISTER_CLASS calls live in a single translation unit, the
registrations are split across module_part_0.cpp, module_part_1.cpp,
etc.  module.cpp only contains the outer entry point and delegates
to each part.
"""

_CHUNK_SIZE = 40


def _chunk_list(items: list[str], size: int) -> list[list[str]]:
    """Split *items* into consecutive chunks of at most *size*."""
    return [items[i:i + size] for i in range(0, len(items), size)]


def _dedup(seq: list[str]) -> list[str]:
    """Remove duplicates while preserving order."""
    seen: set[str] = set()
    out: list[str] = []
    for x in seq:
        if x not in seen:
            seen.add(x)
            out.append(x)
    return out


# ------------------------------------------------------------------
# Public API
# ------------------------------------------------------------------

def part_count_for(class_count: int) -> int:
    """Return how many part files are needed for *class_count* classes."""
    if class_count == 0:
        return 1
    return (class_count + _CHUNK_SIZE - 1) // _CHUNK_SIZE


def generate_module_parts_h(
    part_count: int,
) -> str:
    """Generate module_parts.h  --  per-part init/uninit declarations."""
    lines: list[str] = [
        "#ifndef GDEXT_MODULE_PARTS_H",
        "#define GDEXT_MODULE_PARTS_H",
        "",
        "#include <godot_cpp/godot.hpp>",
        "#include <godot_cpp/core/class_db.hpp>",
        "",
        "using namespace godot;",
        "",
    ]
    for i in range(part_count):
        lines.append(
            f"void gdext_initialize_module_part_{i}(ModuleInitializationLevel p_level);"
        )
        lines.append(
            f"void gdext_uninitialize_module_part_{i}(ModuleInitializationLevel p_level);"
        )
    lines += [
        "",
        "#endif // GDEXT_MODULE_PARTS_H",
        "",
    ]
    return "\n".join(lines)


def generate_module_part_cpp(
    part_index: int,
    class_slice: list[str],
) -> str:
    """Generate module_part_<N>.cpp for a subset of classes.

    Each part includes only the headers it needs and registers only
    its own classes, keeping every translation unit well below the
    COFF section-count limit.
    """
    # Collect includes (one per class, deduped)
    all_includes: list[str] = [f'#include "{cls}.h"' for cls in class_slice]
    seen: set[str] = set()
    unique_includes: list[str] = []
    for h in all_includes:
        if h not in seen:
            seen.add(h)
            unique_includes.append(h)

    reg_lines: list[str] = [
        f"    GDREGISTER_CLASS({cls});" for cls in class_slice
    ]

    lines: list[str] = [
        '#include "module_parts.h"',
        "",
    ]
    lines.extend(unique_includes)
    lines += [
        "",
        f"void gdext_initialize_module_part_{part_index}"
        "(ModuleInitializationLevel p_level) {",
        "    (void)p_level;",
    ]
    lines.extend(reg_lines)
    lines += [
        "}",
        "",
        f"void gdext_uninitialize_module_part_{part_index}"
        "(ModuleInitializationLevel p_level) {",
        "    (void)p_level;",
        "}",
        "",
    ]
    return "\n".join(lines)


def generate_module_h(
    wrapper_names: list[str],
    value_type_names: list[str],
    handle_class_names: list[str],
    out_prim_names: list[str] | None = None,
) -> str:
    """Generate module.h  --  entry-point declarations only.

    No longer includes every generated header; the per-class includes
    have moved to the part files.
    """
    lines: list[str] = [
        "#ifndef GDEXT_MODULE_H",
        "#define GDEXT_MODULE_H",
        "",
        "#include <gdextension_interface.h>",
        "#include <godot_cpp/godot.hpp>",
        "#include <godot_cpp/core/class_db.hpp>",
        "",
        "using namespace godot;",
        "",
        "void gdext_initialize_module_auto(ModuleInitializationLevel p_level);",
        "void gdext_uninitialize_module_auto(ModuleInitializationLevel p_level);",
        "",
        'extern "C" {',
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
    part_count: int,
    wrapper_names: list[str],
    value_type_names: list[str],
    handle_class_names: list[str],
    out_prim_names: list[str] | None = None,
) -> str:
    """Generate module.cpp  --  outer entry point that delegates to parts."""
    # Collect all class names (deduped) for the part interface, but
    # the parts themselves are generated from the chunked list.
    all_classes: list[str] = list(wrapper_names)
    all_classes.extend(value_type_names)
    all_classes.extend(handle_class_names)
    all_classes.extend(out_prim_names or [])
    all_classes = _dedup(all_classes)

    chunks = _chunk_list(all_classes, _CHUNK_SIZE)
    actual_part_count = len(chunks)

    init_calls: list[str] = []
    uninit_calls: list[str] = []
    for i in range(actual_part_count):
        init_calls.append(f"    gdext_initialize_module_part_{i}(p_level);")
        uninit_calls.append(f"    gdext_uninitialize_module_part_{i}(p_level);")

    lines: list[str] = [
        '#include "module.h"',
        '#include "module_parts.h"',
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
    ]
    lines.extend(init_calls)
    lines += [
        "}",
        "",
        "void gdext_uninitialize_module_auto(ModuleInitializationLevel p_level) {",
        "    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {",
        "        return;",
        "    }",
    ]
    lines.extend(uninit_calls)
    lines += [
        "}",
        "",
        'extern "C" {',
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
        "        init_obj.set_minimum_library_initialization_level(",
        "            MODULE_INITIALIZATION_LEVEL_SCENE);",
        "",
        "        return init_obj.init();",
        "    }",
        "}",
        "",
    ]
    return "\n".join(lines)
