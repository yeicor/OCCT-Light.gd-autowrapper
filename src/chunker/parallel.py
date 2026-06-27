"""Dynamic parallel task scheduling for chunk processing with dependency tracking."""

from dataclasses import dataclass, field
from typing import Optional


@dataclass
class ProcessingTask:
    """A chunk processing task with dependency tracking."""
    chunk_id: int
    remaining_dependencies: set[int] = field(default_factory=set)
    
    def is_ready(self) -> bool:
        """Check if all dependencies are satisfied."""
        return len(self.remaining_dependencies) == 0
    
    def mark_dependency_complete(self, completed_chunk_id: int) -> None:
        """Mark a dependency as complete."""
        self.remaining_dependencies.discard(completed_chunk_id)


class DynamicTaskScheduler:
    """
    Dynamically schedules chunk processing tasks respecting dependencies.
    
    Unlike level-based approaches, this scheduler provides any chunk that's
    ready to be processed immediately, without waiting for other chunks at
    the same dependency level to complete.
    """
    
    def __init__(self, chunk_ids: list[int], dependency_graph) -> None:
        """
        Initialize the scheduler.
        
        Args:
            chunk_ids: List of all chunk IDs to process
            dependency_graph: DependencyGraph object with dependency info
        """
        self.dependency_graph = dependency_graph
        self.tasks: dict[int, ProcessingTask] = {}
        self.completed: set[int] = set()
        self.in_progress: set[int] = set()
        
        # Initialize tasks with their dependencies
        for chunk_id in chunk_ids:
            deps = dependency_graph.get_chunk_dependencies(chunk_id)
            self.tasks[chunk_id] = ProcessingTask(
                chunk_id=chunk_id,
                remaining_dependencies=deps.copy()
            )
    
    def get_ready_tasks(self) -> list[int]:
        """
        Get all tasks that are ready to process (all deps satisfied, not in progress).
        
        Returns:
            List of chunk IDs ready for processing, sorted by ID
        """
        ready: list[int] = []
        for chunk_id, task in self.tasks.items():
            if chunk_id not in self.completed and chunk_id not in self.in_progress:
                if task.is_ready():
                    ready.append(chunk_id)
        return sorted(ready)
    
    def mark_in_progress(self, chunk_id: int) -> None:
        """
        Mark a chunk as currently being processed.
        
        Args:
            chunk_id: The chunk ID to mark as in progress
        """
        if chunk_id not in self.completed:
            self.in_progress.add(chunk_id)
    
    def mark_complete(self, chunk_id: int) -> None:
        """
        Mark a chunk as complete and notify dependent tasks.
        
        Args:
            chunk_id: The chunk ID that completed
        """
        if chunk_id in self.completed:
            return
        
        self.completed.add(chunk_id)
        self.in_progress.discard(chunk_id)
        
        # Notify all tasks that depend on this one
        for other_chunk_id, task in self.tasks.items():
            if other_chunk_id not in self.completed:
                task.mark_dependency_complete(chunk_id)
    
    def is_complete(self) -> bool:
        """
        Check if all tasks are complete.
        
        Returns:
            True if all chunks have been processed
        """
        return len(self.completed) == len(self.tasks)
    
    def get_progress(self) -> tuple[int, int]:
        """
        Get (completed, total) count.
        
        Returns:
            Tuple of (number_completed, total_chunks)
        """
        return (len(self.completed), len(self.tasks))
    
    def get_pending_count(self) -> int:
        """
        Get number of tasks not yet started or completed.
        
        Returns:
            Number of pending chunks
        """
        return len(self.tasks) - len(self.completed) - len(self.in_progress)
    
    def get_in_progress_count(self) -> int:
        """
        Get number of tasks currently being processed.
        
        Returns:
            Number of chunks currently in progress
        """
        return len(self.in_progress)
    
    def get_status_summary(self) -> dict[str, int]:
        """
        Get a summary of all task states.
        
        Returns:
            Dictionary with keys: total, completed, in_progress, pending, ready
        """
        return {
            "total": len(self.tasks),
            "completed": len(self.completed),
            "in_progress": len(self.in_progress),
            "pending": self.get_pending_count(),
            "ready": len(self.get_ready_tasks()),
        }


class RoundRobinWorkQueue:
    """
    A dynamic work queue that continuously provides ready tasks.
    
    Can be used by a worker pool to fetch the next available task
    to process without blocking on level boundaries.
    """
    
    def __init__(self, scheduler: DynamicTaskScheduler) -> None:
        """
        Initialize the work queue.
        
        Args:
            scheduler: DynamicTaskScheduler instance
        """
        self.scheduler: DynamicTaskScheduler = scheduler
    
    def next_task(self) -> Optional[int]:
        """
        Get the next available task to process.
        
        Returns:
            A chunk ID to process, or None if no tasks are ready
        """
        ready = self.scheduler.get_ready_tasks()
        return ready[0] if ready else None
    
    def has_work(self) -> bool:
        """
        Check if there's any work ready to be done.
        
        Returns:
            True if there are ready tasks
        """
        return len(self.scheduler.get_ready_tasks()) > 0
    
    def submit_work(self, chunk_id: int) -> None:
        """
        Mark a task as being worked on.
        
        Args:
            chunk_id: The chunk ID being claimed for processing
        """
        self.scheduler.mark_in_progress(chunk_id)
    
    def complete_work(self, chunk_id: int) -> None:
        """
        Mark a task as complete.
        
        Args:
            chunk_id: The chunk ID that finished processing
        """
        self.scheduler.mark_complete(chunk_id)
    
    def is_all_done(self) -> bool:
        """
        Check if all work is complete.
        
        Returns:
            True if all chunks have been processed
        """
        return self.scheduler.is_complete()
    
    def get_stats(self) -> dict[str, int]:
        """
        Get current queue statistics.
        
        Returns:
            Dictionary with current status summary
        """
        return self.scheduler.get_status_summary()
