from dataclasses import dataclass
from pathlib import Path
from xml.sax.saxutils import escape

from generator.schema import (
    FunctionOutWithClass,
    GenerateWithClass,
    HandleOutWithHeader,
)


@dataclass(frozen=True, slots=True)
class GeneratedFiles:
    header: Path
    source: Path
    handles: int
    functions: int


class WrapperWriter:
    def __init__(self, output_dir: Path, header_files: list[Path] | None = None):
        self.bindings_dir = output_dir / "src" / "autowrapper"
        self.doc_dir = output_dir / "doc_classes" / "autowrapper"
        self.test_dir = output_dir / "demo" / "tests"
        self.header_files = header_files or []
        self.bindings_dir.mkdir(parents=True, exist_ok=True)
        self.doc_dir.mkdir(parents=True, exist_ok=True)
        self.test_dir.mkdir(parents=True, exist_ok=True)

    def write(self, outputs: GenerateWithClass) -> GeneratedFiles:
        handles, functions = _collect(outputs)

        # Derive class name from the main header file if available, otherwise fallback
        if self.header_files:
            main_header_stem = self.header_files[0].stem
        else:
            main_header_stem = next(
                (Path(f.header_include).stem for f in functions if f.header_include),
                next(
                    (Path(h.header_include).stem for h in handles if h.header_include),
                    "auto",
                ),
            )
        self.class_name = _to_pascal_case(main_header_stem) + "Wrapper"

        header_path = self.bindings_dir / f"{self.class_name}.h"
        source_path = self.bindings_dir / f"{self.class_name}.cpp"

        # Collect unique header includes from outputs
        header_includes = _collect_header_includes(outputs)

        header_path.write_text(
            self._render_header(handles, functions, header_includes), encoding="utf-8"
        )
        source_path.write_text(
            self._render_source(functions, header_includes), encoding="utf-8"
        )

        self._write_docs(handles, functions)
        self._write_module_registration(handles, functions)
        self._write_gdscript_tests(functions)

        return GeneratedFiles(
            header=header_path,
            source=source_path,
            handles=len(handles),
            functions=len(functions),
        )

    def _render_header(
        self,
        handles: list[HandleOutWithHeader],
        functions: list[FunctionOutWithClass],
        header_includes: set[str],
    ) -> str:
        # Separate user headers and extra C/C++ system headers
        user_headers = {h for h in header_includes if not h.startswith("<")}
        extra_system_headers = sorted({h for h in header_includes if h.startswith("<")})

        lines: list[str] = [
            f"#ifndef {self.class_name.upper()}_H",
            f"#define {self.class_name.upper()}_H",
            "",
            "#include <godot_cpp/classes/object.hpp> // NOLINT(misc-include-cleaner)",
            "#include <godot_cpp/classes/ref.hpp> // NOLINT(misc-include-cleaner)",
            "#include <godot_cpp/core/class_db.hpp> // NOLINT(misc-include-cleaner)",
            "#include <godot_cpp/variant/callable.hpp> // NOLINT(misc-include-cleaner)",
            "#include <godot_cpp/variant/array.hpp> // NOLINT(misc-include-cleaner)",
            "#include <godot_cpp/variant/utility_functions.hpp> // NOLINT(misc-include-cleaner)",
        ]
        # Add extra system headers first (before user headers)
        for header in extra_system_headers:
            lines.append(f"#include {header} // NOLINT(misc-include-cleaner)")
        # Then add user headers
        for header_include in sorted(user_headers):
            lines.append(f'#include "{header_include}" // NOLINT(misc-include-cleaner)')
        lines += [
            "",
            "using namespace godot;",
            "",
        ]

        for handle in handles:
            cls = _handle_name(handle.handle_type)
            handle_code = [
                f"class {cls} : public godot::RefCounted {{ // NOLINT(cppcoreguidelines-special-member-functions)",
                f"    GDCLASS({cls}, godot::RefCounted) // NOLINT",
                "protected:",
                "    static void _bind_methods() {",
                f'        godot::ClassDB::bind_method(godot::D_METHOD("set_handle", "handle"), &{cls}::set_handle);',
                f'        godot::ClassDB::bind_method(godot::D_METHOD("get_handle"), &{cls}::get_handle);',
                f'        godot::ClassDB::bind_method(godot::D_METHOD("is_valid"), &{cls}::is_valid);',
                "    }",
                "public:",
                f"    {handle.handle_type}* handle = nullptr; // NOLINT",
                f"    void set_handle(int64_t _handle) {{ handle = reinterpret_cast<{handle.handle_type}*>(static_cast<uintptr_t>(_handle)); }} // NOLINT",
                "    [[nodiscard]] int64_t get_handle() const { return static_cast<int64_t>(reinterpret_cast<uintptr_t>(handle)); } // NOLINT",
                "    [[nodiscard]] bool is_valid() const { return handle != nullptr; }",
                "};",
                "",
            ]
            if handle.condition_directive and handle.condition_expression:
                handle_code = _wrap_with_condition(
                    "\n".join(handle_code),
                    handle.condition_directive,
                    handle.condition_expression,
                ).split("\n")
            lines.extend(handle_code)

        wrapper_code = [
            f"class {self.class_name} : public godot::RefCounted {{ // NOLINT(cppcoreguidelines-special-member-functions, hicpp-special-member-functions)",
            f"    GDCLASS({self.class_name}, godot::RefCounted) // NOLINT",
            "protected:",
            "    static void _bind_methods();",
            "public:",
        ]
        for f in functions:
            decl = f"    {f.return_type} {f.name}({_args_decl(f)}); // NOLINT(readability-convert-member-functions-to-static)"
            if f.condition_directive and f.condition_expression:
                decl = _wrap_with_condition(
                    decl, f.condition_directive, f.condition_expression
                )
                wrapper_code.extend(decl.split("\n"))
            else:
                wrapper_code.append(decl)
        if not functions:
            wrapper_code.append("    void _unused();")
        wrapper_code += ["};", ""]

        lines.extend(wrapper_code)
        lines.append(f"\n#endif // {self.class_name.upper()}_H\n")
        return "\n".join(lines)

    def _render_source(
        self,
        functions: list[FunctionOutWithClass],
        header_includes: set[str],
    ) -> str:
        # Separate user headers and extra C/C++ system headers
        user_headers = {h for h in header_includes if not h.startswith("<")}
        extra_system_headers = sorted({h for h in header_includes if h.startswith("<")})

        lines = [
            f'#include "{self.class_name}.h" // NOLINT(misc-include-cleaner)',
            "",
            "#include <godot_cpp/classes/ref.hpp> // NOLINT(misc-include-cleaner)",
            "#include <godot_cpp/core/class_db.hpp> // NOLINT(misc-include-cleaner)",
            "#include <godot_cpp/variant/string.hpp> // NOLINT(misc-include-cleaner)",
        ]
        # Add extra system headers first (before user headers)
        for header in extra_system_headers:
            lines.append(f"#include {header} // NOLINT(misc-include-cleaner)")
        # Then add user headers
        for header_include in sorted(user_headers):
            lines.append(f'#include "{header_include}" // NOLINT(misc-include-cleaner)')

        lines += [
            "",
            f"void {self.class_name}::_bind_methods() {{",
        ]
        for f in functions:
            bind = f'    godot::ClassDB::bind_method(godot::D_METHOD("{f.name}"{_method_arg_names(f)}), &{self.class_name}::{f.name});'
            if f.condition_directive and f.condition_expression:
                bind = _wrap_with_condition(
                    bind, f.condition_directive, f.condition_expression
                )
                lines.extend(bind.split("\n"))
            else:
                lines.append(bind)
        lines += ["}", ""]

        if not functions:
            lines += [f"void {self.class_name}::_unused() {{}}", ""]
            return "\n".join(lines)

        for f in functions:
            func_def = "\n".join(
                [
                    f"{f.return_type} {self.class_name}::{f.name}({_args_decl(f)}) {{ // NOLINT(readability-convert-member-functions-to-static)",
                    _indent(_default_body(f)),
                    "}",
                ]
            )
            if f.condition_directive and f.condition_expression:
                func_def = _wrap_with_condition(
                    func_def, f.condition_directive, f.condition_expression
                )
            lines.extend(func_def.split("\n"))
            lines.append("")
        return "\n".join(lines)

    def _write_docs(
        self, handles: list[HandleOutWithHeader], functions: list[FunctionOutWithClass]
    ) -> None:
        # Remove all existing doc files
        for existing_doc in self.doc_dir.glob("*.xml"):
            existing_doc.unlink()

        by_class: dict[str, list[FunctionOutWithClass]] = {}
        for f in functions:
            cls = f.class_name or self.class_name
            by_class.setdefault(cls, [])
            if f not in by_class[cls]:
                by_class[cls].append(f)

        for h in handles:
            by_class.setdefault(_handle_name(h.handle_type), [])

        for cls, cls_funcs in by_class.items():
            doc = _render_doc_xml(cls, cls_funcs)
            (self.doc_dir / f"{cls}.xml").write_text(doc, encoding="utf-8")

    def _write_module_registration(
        self, handles: list[HandleOutWithHeader], functions: list[FunctionOutWithClass]
    ) -> None:
        classes = {self.class_name}
        for h in handles:
            classes.add(_handle_name(h.handle_type))
        for f in functions:
            classes.add(f.class_name or self.class_name)

        # Use unified module file name to avoid duplicate symbols when multiple wrappers exist
        header_path = self.bindings_dir / "module.h"
        source_path = self.bindings_dir / "module.cpp"

        header_lines: list[str] = [
            "#ifndef GDEXT_MODULE_H",
            "#define GDEXT_MODULE_H",
            "",
            "#include <gdextension_interface.h> // NOLINT(misc-include-cleaner)",
            "#include <godot_cpp/godot.hpp> // NOLINT(misc-include-cleaner)",
            "#include <godot_cpp/core/class_db.hpp> // NOLINT(misc-include-cleaner)",
            "",
            f'#include "{self.class_name}.h" // NOLINT(misc-include-cleaner)',
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
        ]
        header_path.write_text("\n".join(header_lines), encoding="utf-8")

        source_lines: list[str] = [
            '#include "module.h" // NOLINT(misc-include-cleaner)',
            f'#include "{self.class_name}.h" // NOLINT(misc-include-cleaner)',
            "#include <gdextension_interface.h> // NOLINT(misc-include-cleaner)",
            "#include <godot_cpp/godot.hpp> // NOLINT(misc-include-cleaner)",
            "#include <godot_cpp/core/class_db.hpp> // NOLINT(misc-include-cleaner)",
            "#include <godot_cpp/core/defs.hpp> // NOLINT(misc-include-cleaner)",
            "",
            "void gdext_initialize_module_auto(ModuleInitializationLevel p_level) {",
            "    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {",
            "        return;",
            "    }",
            "",
            "    // Register wrapped classes",
        ]
        for cls in sorted(classes):
            source_lines.append(f"    GDREGISTER_CLASS({cls});")
        source_lines += [
            "}",
            "",
            "void gdext_uninitialize_module_auto(ModuleInitializationLevel p_level) {",
            "    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {",
            "        return;",
            "    }",
            "    // Teardown logic (if any) goes here.",
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
            "        init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);",
            "",
            "        return init_obj.init();",
            "    }",
            "}",
            "",
        ]
        source_path.write_text("\n".join(source_lines), encoding="utf-8")

    def _write_gdscript_tests(self, functions: list[FunctionOutWithClass]) -> None:
        """Generate a GDScript test file that calls test functions."""
        test_functions = _collect_test_functions(functions)

        gd_lines = [
            "class_name TestAutoWrapper",
            "",
        ]
        for f in test_functions:
            gd_lines.append(f"static func test_{f.name}():")
            # Indent the test_body which is already GDScript code
            # The LLM generates test code using the actual wrapper class name
            test_body_lines = f.test_body.strip().split("\n")
            for line in test_body_lines:
                gd_lines.append(f"\t{line.replace('    ', '\t')}")
            gd_lines.append("")

        test_file = self.test_dir / "test_autowrapper.gd"
        test_file.write_text("\n".join(gd_lines) + "\n", encoding="utf-8")


def _collect(
    outputs: GenerateWithClass,
) -> tuple[list[HandleOutWithHeader], list[FunctionOutWithClass]]:
    handles: list[HandleOutWithHeader] = []
    functions: list[FunctionOutWithClass] = []
    seen_h: set[str] = set()
    seen_f: set[str] = set()

    for item in outputs.to_generate:
        if isinstance(item, HandleOutWithHeader):
            k = item.handle_type.strip()
            if k and k not in seen_h:
                seen_h.add(k)
                handles.append(item)
        elif isinstance(item, FunctionOutWithClass):
            k = item.name.strip()
            if k and k not in seen_f:
                seen_f.add(k)
                functions.append(item)
    return handles, functions


def _collect_test_functions(
    functions: list[FunctionOutWithClass],
) -> list[FunctionOutWithClass]:
    """Return only functions that have a non-empty test_body (GDScript test code)."""
    return [f for f in functions if f.test_body and f.test_body.strip()]


def derive_class_name(header_files: list[Path] | None) -> str:
    """Derive the wrapper class name from header files or return a default."""
    if header_files:
        main_header_stem = header_files[0].stem
    else:
        main_header_stem = "auto"
    return _to_pascal_case(main_header_stem) + "Wrapper"


def _collect_header_includes(outputs: GenerateWithClass) -> set[str]:
    """Extract unique header includes from all outputs."""
    header_includes: set[str] = set()
    for item in outputs.to_generate:
        if isinstance(item, FunctionOutWithClass):
            if item.header_include:
                header_includes.add(item.header_include)
            # Collect extra C/C++ headers needed by function bodies
            for extra_header in item.extra_headers:
                header_includes.add(extra_header)
        elif isinstance(item, HandleOutWithHeader):
            if item.header_include:
                header_includes.add(item.header_include)
    return header_includes


def _render_doc_xml(class_name: str, functions: list[FunctionOutWithClass]) -> str:
    methods = []
    for f in functions:
        methods.append(f'\t\t<method name="{escape(f.name)}">')
        methods.append(f'\t\t\t<return type="{_godot_doc_type(f.return_type)}" />')
        for i, a in enumerate(f.arguments):
            methods.append(
                f'\t\t\t<argument index="{i}" name="{escape(a.name)}" type="{_godot_doc_type(a.type)}" />'
            )
        desc = escape(f.doc.strip() or f"Generated binding for `{f.name}`.")
        methods.append("\t\t\t<description>")
        methods.append(f"\t\t\t\t{desc}")
        methods.append("\t\t\t</description>")
        methods.append("\t\t</method>")

    methods_xml = "\n".join(methods)
    return (
        '<?xml version="1.0" encoding="UTF-8" ?>\n'
        f'<class name="{class_name}" inherits="RefCounted" version="4.0" '
        'xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" '
        'xsi:noNamespaceSchemaLocation="https://raw.githubusercontent.com/godotengine/godot/master/doc/class.xsd">\n'
        "\t<brief_description>\n"
        f"\t\tGenerated docs for {class_name}.\n"
        "\t</brief_description>\n"
        "\t<description>\n"
        f"\t\tAuto-generated documentation for {class_name}.\n"
        "\t</description>\n"
        "\t<tutorials>\n"
        "\t</tutorials>\n"
        "\t<methods>\n"
        f"{methods_xml}\n"
        "\t</methods>\n"
        "</class>\n"
    )


def _args_decl(func: FunctionOutWithClass) -> str:
    args_list = []
    for a in func.arguments:
        t = a.type.strip()
        if t in (
            "String",
            "Variant",
            "Array",
            "Dictionary",
            "PackedByteArray",
        ) or t.startswith("Ref<"):
            args_list.append(f"const {t}& {a.name}")
        else:
            args_list.append(f"{t} {a.name}")
    return ", ".join(args_list) or "void"


def _method_arg_names(func: FunctionOutWithClass) -> str:
    return "".join(f', "{a.name}"' for a in func.arguments)


def _default_body(func: FunctionOutWithClass) -> str:
    body = func.body.strip()
    if body:
        return body
    if func.return_type.strip() == "void":
        return "return;"
    return "return {};"


def _indent(text: str) -> str:
    return "\n".join(f"    {line}" if line else "" for line in text.splitlines())


def _handle_name(handle_type: str) -> str:
    return f"{_to_pascal_case(_valid_name(handle_type.strip()))}Handle"


def _valid_name(s: str) -> str:
    valid = []
    for c in s:
        if c.isalnum():
            valid.append(c)
        else:
            valid.append("_")
    return "".join(valid)


def _to_pascal_case(s: str) -> str:
    words = s.replace("_", " ").replace("-", " ").split()
    return "".join(word.capitalize() for word in words)


def _wrap_with_condition(code: str, directive: str, expression: str) -> str:
    """Wrap generated code with a preprocessor condition."""
    if not (directive and expression):
        return code
    lines = [
        f"{directive} {expression}",
        code,
        "#endif",
    ]
    return "\n".join(lines)


def _godot_doc_type(cpp_type: str) -> str:
    t = cpp_type.strip()
    if t.startswith("Ref<") and t.endswith(">"):
        return t[4:-1].strip()
    mapping = {
        "void": "void",
        "bool": "bool",
        "int": "int",
        "int32_t": "int",
        "int64_t": "int",
        "float": "float",
        "double": "float",
        "String": "String",
        "Variant": "Variant",
        "Array": "Array",
        "Dictionary": "Dictionary",
        "PackedByteArray": "PackedByteArray",
    }
    return mapping.get(t, t)
