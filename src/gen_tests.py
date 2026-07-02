"""Generate GDScript test files for autowrapper-generated classes.

Produces test files for wrapped functions (one per parsed header) and
handle classes (via template files in src/templates/).
"""

from pathlib import Path

from gen_handles import _template_path
from gen_wrapper import (
    _wrapper_class_name,
    generate_gdscript_tests,
)
from parser import CStruct, ParsedHeader
from type_map import HANDLE_TYPES, c_type_to_godot_class


def generate_all_tests(
    parsed_headers: list[ParsedHeader],
    output_dir: Path,
) -> list[str]:
    """Generate GDScript test files.

    Writes to output_dir/demo/tests/ (or creates the directory).

    Returns list of filenames written.
    """
    tests_dir = output_dir / "demo" / "tests" / "autowrapper"
    tests_dir.mkdir(parents=True, exist_ok=True)
    tests_parent_dir = output_dir / "demo" / "tests"

    written: list[str] = []
    test_paths: list[str] = []

    for ph in parsed_headers:
        cls = _wrapper_class_name(ph.header_include)
        gdscript = generate_gdscript_tests(ph, cls)
        fname = f"test_{cls}.gd"
        (tests_dir / fname).write_text(gdscript)
        written.append(fname)
        test_paths.append(f"res://tests/autowrapper/{fname}")

    # Clean up orphan test files (no longer generated) — only in autowrapper subdir
    expected_tests = {
        f"test_{_wrapper_class_name(ph.header_include)}" for ph in parsed_headers
    }

    # Generate handle test files from templates (e.g. test_OclGraphHandle.gd)
    for c_type in HANDLE_TYPES:
        cls = c_type_to_godot_class(c_type) + "Handle"
        fname = f"test_{cls}.gd"
        tpath = _template_path(f"test_{cls}", "gd")
        if tpath:
            (tests_dir / fname).write_text(tpath.read_text())
            written.append(fname)
            test_paths.append(f"res://tests/autowrapper/{fname}")
            expected_tests.add(f"test_{cls}")

    # Clean up orphan test files in autowrapper subdirectory only
    for f in tests_dir.iterdir():
        if f.suffix == ".gd":
            if f.stem not in expected_tests:
                f.unlink()
                print(f"  [cleanup] removed orphan test: {f.name}")

    return written
