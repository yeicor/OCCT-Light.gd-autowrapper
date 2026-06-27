import glob
import re
import subprocess
import threading
from dataclasses import dataclass
from pathlib import Path

# Global lock to serialize builds across workers.
# vcpkg install uses file-level locking internally, but sharing the
# same build directory across parallel workers causes confusion.
_BUILD_LOCK = threading.Lock()


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
            r"error:\s*[''`]?(occtl_[A-Za-z_0-9]*)[''`]?",
        ]
        joined = "\n".join(self.extracted_errors) if self.extracted_errors else ""
        for pattern in patterns:
            m = re.search(pattern, joined)
            if m:
                return m.group(1).split("::")[-1]
        return None


def run_build(
    output_dir: Path,
    command: str,
    timeout_seconds: int,
    errors_file: Path | None = None,
) -> BuildResult:
    """Execute a build command and return the result.

    Uses a global lock to serialize builds across all workers
    so that concurrent vcpkg installs do not interfere with each other.
    """
    with _BUILD_LOCK:
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
            stdout = e.stdout or ""
            stderr = e.stderr or ""

            timeout_msg = (
                f"Build timed out after {timeout_seconds} seconds.\n"
                f"Command: {final_command}\n"
                f"Working directory: {output_dir}\n"
                f"Partial stdout: {stdout}\n"
                f"Partial stderr: {stderr}\n"
            )

            if errors_file and not Path(errors_file).exists():
                try:
                    errors_file.write_text(timeout_msg)
                except Exception:
                    pass  # Don't mask the original issue

            return BuildResult(success=False, errors_file=errors_file)

        if proc.returncode != 0 and (not errors_file or not Path(errors_file).exists()):
            error_msg = (
                f"Build failed but no error file was created at {errors_file}. "
                "Please check that the build command is correct and that it creates the expected error file. "
                f"Build command: {final_command}\n"
                f"Working directory: {output_dir}\n"
                f"Stdout: {proc.stdout}\n"
                f"Stderr: {proc.stderr}\n"
            )
            raise RuntimeError(error_msg)

        return BuildResult(success=proc.returncode == 0, errors_file=errors_file)


def _search_vcpkg_buildtrees(output_dir: Path) -> list[str]:
    """Fallback: search vcpkg buildtrees logs for real compiler errors.

    The validate.sh script primarily searches buildtrees logs now, but
    as a defensive fallback this also searches them directly.
    """
    errors: list[str] = []
    buildtrees_dir = output_dir / "vcpkg" / "buildtrees" / "gdext"
    if not buildtrees_dir.is_dir():
        return []
    for logfile in sorted(buildtrees_dir.glob("build-x64-linux-*-out.log")):
        try:
            text = logfile.read_text(encoding="utf-8", errors="ignore")
        except OSError:
            continue
        interesting: list[str] = []
        for line in text.split("\n"):
            if re.search(
                r"""
                (error:\s|fatal\s+error|FAILED:\s|collect2:\s|
                 undefined\s+reference|ld:\s|In\s+file\s+included\s+from|
                 cc1plus:|CMake\s+Error|ninja:\s+build\s+stopped)
                """,
                line,
                re.I | re.X,
            ):
                interesting.append(line)
        if interesting:
            errors.append(
                f"=== From {logfile.name} ===\n" + "\n".join(interesting[-150:])
            )
    return errors


def analyze_build_failure(
    errors_file: Path | None, output_dir: Path | None = None
) -> BuildFailure:
    """Analyze build failure from errors file.

    If the errors file exists, read errors from it.
    If the file is empty or missing, create a placeholder so the AI
    has something to work with.
    Falls back to searching vcpkg buildtrees logs for real compiler errors.

    Args:
        errors_file: Path to file containing extracted errors
        output_dir: The project root directory (to find vcpkg buildtrees logs)

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
        except OSError:
            pass

    # If the error file content was empty or just the fallback "Last 500 lines" msg,
    # it may not have real compiler errors. Try the buildtrees logs as backup.
    if not extracted_errors or _looks_like_fallback(extracted_errors):
        buildtrees_errors = _search_vcpkg_buildtrees(
            output_dir or (errors_file.parent if errors_file else Path())
        )
        if buildtrees_errors:
            extracted_errors = buildtrees_errors

    if not extracted_errors:
        fallback = (
            "Build failed but no structured error lines were captured.\n"
            "This usually means vcpkg/cmake failed before the compiler ran.\n"
            "Check that: the header includes are correct, dependencies are\n"
            "installed, and OCCT-Light is properly configured.\n"
            "Try running GODOT_VERSION=system ./validate.sh manually to see full output."
        )
        if errors_file:
            try:
                errors_file.parent.mkdir(parents=True, exist_ok=True)
                errors_file.write_text(fallback)
            except OSError:
                pass
        extracted_errors = [fallback]

    return BuildFailure(extracted_errors=tuple(extracted_errors))


def _looks_like_fallback(errors: list[str]) -> bool:
    """Check if errors are just the fallback message (not real compiler errors)."""
    fallback_signals = [
        "Build failed but no structured error",
        "Last 500 lines of build output",
        "Build failed but no error file was produced",
        "Build failed with no error details available",
        "Try running GODOT_VERSION=system ./validate.sh",
    ]
    text = " ".join(errors)
    for signal in fallback_signals:
        if signal in text:
            return True
    return False


def _trim(text: str, max_chars: int) -> str:
    """Trim text to max length, showing start and end."""
    if len(text) <= max_chars:
        return text
    half = max_chars // 2
    return text[:half] + "\n...\n" + text[-half:]
