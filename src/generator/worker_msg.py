"""Minimal worker interface - just data passed between main and workers."""

from dataclasses import dataclass

from generator.schema import GenerateWithClass


@dataclass(frozen=True, slots=True)
class WorkerOutput:
    """What worker returns: hash for dedup, generated code, success status."""

    chunk_hash: str
    generated: GenerateWithClass
    build_success: bool
