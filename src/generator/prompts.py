from pathlib import Path

from chunker import Chunk

_SYSTEM_PROMPT_PATH = Path(__file__).with_name("system.md")


def load_system_prompt() -> str:
    return _SYSTEM_PROMPT_PATH.read_text().strip()


def build_user_prompt(chunk: Chunk, wrapper_class_name: str | None = None) -> str:
    prompt_parts = [
        "Translate this chunk to Godot C++ wrapper entries according to your system rules. Please reason extensively about it first.\n"
    ]

    if wrapper_class_name:
        prompt_parts.append(
            f"The wrapper class for this chunk is: `{wrapper_class_name}`\n\n"
        )

    prompt_parts.append(f"```cpp\n{chunk.annotated}\n```")

    return "".join(prompt_parts)
