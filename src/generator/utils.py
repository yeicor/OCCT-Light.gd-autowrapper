import hashlib
import re
from typing import TypeVar

from chunker import Chunk

T = TypeVar("T")


def filter_chunks(
    chunks: list[Chunk], include_patterns: list[str], exclude_patterns: list[str]
) -> list[Chunk]:
    """Filter chunks based on include and exclude patterns."""
    include_res = [re.compile(pattern, re.I | re.M) for pattern in include_patterns]
    exclude_res = [re.compile(pattern, re.I | re.M) for pattern in exclude_patterns]
    kept: list[Chunk] = []
    for chunk in chunks:
        if include_res and not any(regex.search(chunk.code) for regex in include_res):
            continue
        if any(regex.search(chunk.code) for regex in exclude_res):
            continue
        kept.append(chunk)
    return kept


def get_chunk_label(chunk: Chunk) -> str:
    """Get a descriptive label for a chunk for logging purposes.

    Shows longest line of code, ignoring comments (// or /** / style).
    """
    # Remove single-line comments
    code_no_single = re.sub(r"//.*?$", "", chunk.code, flags=re.MULTILINE)
    # Remove block comments
    code_no_comments = re.sub(r"/\*.*?\*/", "", code_no_single, flags=re.DOTALL)

    lines = code_no_comments.splitlines()
    non_comment_lines = [line.strip() for line in lines if line.strip()]

    if not non_comment_lines:
        return f"Chunk {chunk.index}"
    longest = max(non_comment_lines, key=len)
    return longest.strip()[:60] + ("..." if len(longest) > 60 else "")


def chunk_hash(chunk: Chunk) -> str:
    """Compute SHA256 hash of chunk code to detect changes."""
    return hashlib.sha256(chunk.code.encode()).hexdigest()


def dedupe_keep_order(items: list[T]) -> list[T]:
    """Remove duplicates while preserving order."""
    seen: set[object] = set()
    out: list[T] = []
    for item in items:
        if item in seen:
            continue
        seen.add(item)
        out.append(item)
    return out


def trim(text: str, max_chars: int) -> str:
    """Trim text to max length, showing start and end."""
    if len(text) <= max_chars:
        return text
    half = max_chars // 2
    return text[:half] + "\n...\n" + text[-half:]
