import re
import subprocess
from dataclasses import dataclass
from pathlib import Path


@dataclass(frozen=True, slots=True)
class BuildResult:
    success: bool
    errors_file: Path | None = None


@dataclass(frozen=True, slots=True)
class BuildFailure:
    extracted_errors: tuple[str, ...]

    def feedback_for_llm(self, max_chars: int = 12000) -> str:
        sections: list[str] = []
        if self.extracted_errors:
            sections.append(
                "Build and validation errors:\n" + "\n\n".join(self.extracted_errors)
            )
        else:
            raise ValueError("No extracted errors to provide feedback for.")

        return _trim("\n\n".join(sections), max_chars)

    def first_symbol_candidate(self) -> str | None:
        patterns = [
            r"error:\s*[''`]?([A-Za-z_][A-Za-z0-9_:]*)[''`]?\s+was not declared",
            r"undefined reference to\s+[''`]?([A-Za-z_][A-Za-z0-9_:]*)",
            r"no member named\s+[''`]?([A-Za-z_][A-Za-z0-9_:]*)",
        ]
        joined = "\n".join(self.extracted_errors) if self.extracted_errors else ""
        for pattern in patterns:
            m = re.search(pattern, joined)
            if m:
                return m.group(1).split("::")[-1]
        return None


import subprocess
from pathlib import Path


def run_build(
    output_dir: Path,
    command: str,
    timeout_seconds: int,
    errors_file: Path | None = None,
) -> BuildResult:
    """Execute a build command and return the result."""
    final_command = command

    if errors_file:
        errors_file.parent.mkdir(parents=True, exist_ok=True)
        final_command = command.replace("<ERROR_FILE>", str(errors_file))

    try:
        proc = subprocess.run(
            final_command,
            cwd=output_dir,
            shell=True,
            capture_output=True,
            text=True,
            timeout=timeout_seconds,
        )
    except subprocess.TimeoutExpired as e:
        # Prepare useful debug output
        stdout = e.stdout or ""
        stderr = e.stderr or ""

        timeout_msg = (
            f"Build timed out after {timeout_seconds} seconds.\n"
            f"Command: {final_command}\n"
            f"Working directory: {output_dir}\n"
            f"Partial stdout: {stdout}\n"
            f"Partial stderr: {stderr}\n"
        )

        # Optionally write timeout info to errors_file
        if errors_file and not Path(errors_file).exists():
            try:
                errors_file.write_text(timeout_msg)
            except Exception:
                pass  # Don't mask the original issue

    # Existing failure handling
    if proc.returncode != 0 and (not errors_file or not Path(errors_file).exists()):
        error_msg = (
            f"Build failed but no error file was created at {errors_file}. "
            f"Please check that the build command is correct and that it creates the expected error file. "
            f"Build command: {final_command}\n"
            f"Working directory: {output_dir}\n"
            f"Stdout: {proc.stdout}\n"
            f"Stderr: {proc.stderr}\n"
        )
        raise RuntimeError(error_msg)

    return BuildResult(success=proc.returncode == 0, errors_file=errors_file)


def analyze_build_failure(errors_file: Path | None) -> BuildFailure:
    """Analyze build failure from errors file.

    If the errors file exists, read errors from it.
    If the file is empty or missing, create a placeholder so the AI
    has something to work with.

    Args:
        errors_file: Path to file containing extracted errors

    Returns:
        BuildFailure with extracted errors
    """
    extracted_errors: list[str] = []

    if errors_file and errors_file.exists():
        try:
            content = errors_file.read_text(encoding="utf-8", errors="ignore").strip()
            if content:
                # Split by double newline to get individual error blocks
                blocks = content.split("\n\n")
                extracted_errors = [block.strip() for block in blocks if block.strip()]
            else:
                # File exists but is empty — write a fallback message
                fallback = (
                    "Build failed but no structured error lines were captured.\n"
                    "This usually means vcpkg/cmake failed before the compiler ran.\n"
                    "Check that: the header includes are correct, dependencies are\n"
                    "installed, and OCCT-Light is properly configured.\n"
                    "Try running GODOT_VERSION=system ./validate.sh manually to see full output."
                )
                errors_file.write_text(fallback)
                extracted_errors = [fallback]
        except OSError:
            pass
    else:
        # No error file at all — create one with a descriptive message
        if errors_file:
            try:
                errors_file.parent.mkdir(parents=True, exist_ok=True)
                fallback = (
                    "Build failed but no error file was produced.\n"
                    "The build command may not have completed, or the error occurred\n"
                    "before the compiler ran. Check vcpkg configuration and dependencies."
                )
                errors_file.write_text(fallback)
                extracted_errors = [fallback]
            except OSError:
                pass

    if not extracted_errors:
        extracted_errors = ["Build failed with no error details available."]

    return BuildFailure(extracted_errors=tuple(extracted_errors))


def _trim(text: str, max_chars: int) -> str:
    """Trim text to max length, showing start and end."""
    if len(text) <= max_chars:
        return text
    half = max_chars // 2
    return text[:half] + "\n...\n" + text[-half:]
