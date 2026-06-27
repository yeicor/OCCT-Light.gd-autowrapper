import json
import re
import subprocess
import threading
import time
from dataclasses import dataclass
from pathlib import Path
from typing import Optional

from langchain.agents import create_agent
from langchain_core.language_models import LanguageModelInput
from langchain_core.messages import (
    AIMessage,
    AIMessageChunk,
    BaseMessage,
    HumanMessage,
    SystemMessage,
)
from langchain_core.runnables import Runnable
from langchain_core.tools import tool
from langchain_openai import ChatOpenAI
from langchain_openai.chat_models.base import _DictOrPydantic
from langgraph.graph.state import CompiledStateGraph
from pydantic import SecretStr, ValidationError

from generator.console import (
    show_ai_message_streaming,
    show_info,
    show_system_message,
    show_tool_call,
    show_tool_output,
    show_user_message,
    show_warning,
)
from generator.schema import Generate

SUMMARIZE_PROMPT = """Summarize the following conversation about C++ code generation for Godot bindings.
Keep the summary concise but preserve all important decisions, unsolved errors encountered, and successful patterns.
Focus on what was generated, what worked, and what failed.

Conversation:
{history}

Summary:"""

# Exponential backoff configuration
MAX_BACKOFF_SECONDS = 3600  # Cap backoff at 1 hour to avoid excessively long waits
INITIAL_BACKOFF_SECONDS = 5
BACKOFF_MULTIPLIER = 1.5
MAX_RETRIES = 20

# Global thread-safe flag for manual JSON parsing fallback
_manual_json_parsing_lock = threading.Lock()
_use_manual_json_parsing_global = False


def _is_temporary_error(exception: Exception) -> bool:
    """Check if an exception represents a temporary API error that should be retried."""
    error_str = str(exception).lower()

    # Check for rate limiting (429)
    if "429" in str(exception):
        return True
    if "too many requests" in error_str:
        return True

    # Check for timeouts and connection errors
    if any(
        x in error_str
        for x in ["timeout", "timed out", "connection reset", "temporarily unavailable"]
    ):
        return True

    # Check for specific HTTP status codes that indicate temporary issues
    if any(x in error_str for x in ["503", "502", "500 internal server", "429"]):
        return True

    return False


def _calculate_backoff_delay(attempt: int) -> float:
    """Calculate exponential backoff delay in seconds, capped at MAX_BACKOFF_SECONDS."""
    if attempt < 0:
        attempt = 0
    delay = INITIAL_BACKOFF_SECONDS * (BACKOFF_MULTIPLIER**attempt)
    return min(delay, MAX_BACKOFF_SECONDS)


# Global notes storage and lock for thread safety
_global_notes_lock = threading.Lock()
_global_notes: dict[str, dict] = {}


@dataclass(slots=True)
class LLMConfig:
    model: str
    base_url: str
    api_key: str
    temperature: float = 0.0
    max_completion_tokens: int = 3000
    max_history_bytes: int = 100000
    reasoning_timeout_seconds: float = 60.0


class Translator:
    _global_printed_system_prompt = False

    def __init__(
        self,
        config: LLMConfig,
        system_prompt: str,
        show_console_output: bool = True,
        workers: int = 1,
        header_files: list[Path] | None = None,
        output_dir: Path | None = None,
    ):
        self.system_prompt = system_prompt
        self.show_console_output = show_console_output
        self.max_history_bytes = config.max_history_bytes
        self.reasoning_timeout_seconds = config.reasoning_timeout_seconds
        self._printed_system_prompt = False
        self._chunk_label: str | None = None
        self.model = ChatOpenAI(
            base_url=config.base_url,
            model=config.model,
            api_key=SecretStr(config.api_key),
            temperature=config.temperature,
            max_completion_tokens=config.max_completion_tokens,
        )
        self.stream_workers = workers
        self._message_history: list[BaseMessage] = []
        self.header_files = header_files or []
        self.output_dir = output_dir
        # Remove self._notes, use global notes instead
        self._tools = self._create_tools()
        self._agent_graph = self._create_reasoning_agent()

    def _create_tools(self) -> list:
        """Create tools for the reasoning agent."""
        translator_self = self

        @tool
        def grep_headers(
            pattern: str, context_lines: int = 2, max_total_lines: int = 100
        ) -> str:
            """Search C/C++ header files for patterns.

            Args:
                pattern: Regex or literal pattern to search
                context_lines: Lines before/after match (default: 2)
                max_total_lines: Maximum total output lines (default: 100)
            """
            show_tool_call(
                f"grep_headers(pattern={pattern}, context_lines={context_lines}, max_total_lines={max_total_lines})",
                chunk_label=translator_self._chunk_label,
            )

            try:
                cmd = [
                    "grep",
                    "-n",
                    "-B",
                    str(context_lines),
                    "-A",
                    str(context_lines),
                ]
                cmd.append(pattern)
                for header_file in translator_self.header_files:
                    cmd.append(str(header_file))

                result = subprocess.run(cmd, capture_output=True, text=True, timeout=10)

                if result.returncode == 0:
                    output_lines = result.stdout.split("\n")
                    if len(output_lines) > max_total_lines:
                        output_lines = output_lines[:max_total_lines]
                        output_lines.append(
                            f"\n... (truncated, showing {max_total_lines} lines)"
                        )
                    res = "\n".join(output_lines)
                elif result.returncode == 1:
                    res = f"(No matches for: {pattern})"
                else:
                    res = f"(Grep error: {result.stderr})"
            except subprocess.TimeoutExpired:
                res = "(Grep timed out after 10s)"
            except Exception as e:
                res = f"(Error: {str(e)})"

            show_tool_output(res, chunk_label=translator_self._chunk_label)
            return res

        @tool
        def grep_targets(
            pattern: str, context_lines: int = 2, max_total_lines: int = 100
        ) -> str:
            """Search generated wrapper code for patterns.

            Args:
                pattern: Regex or literal pattern to search
                context_lines: Lines before/after match (default: 2)
                max_total_lines: Maximum total output lines (default: 100)
            """
            show_tool_call(
                f"grep_targets(pattern={pattern}, context_lines={context_lines}, max_total_lines={max_total_lines})",
                chunk_label=translator_self._chunk_label,
            )

            try:
                cmd = [
                    "grep",
                    "-n",
                    "-B",
                    str(context_lines),
                    "-A",
                    str(context_lines),
                ]
                cmd.append(pattern)

                if translator_self.output_dir:
                    for search_dir in [
                        translator_self.output_dir / "src" / "autowrapper",
                        translator_self.output_dir / "src" / "doc_classes",
                    ]:
                        if search_dir.exists():
                            for file_path in search_dir.rglob("*"):
                                if file_path.is_file() and file_path.suffix in [
                                    ".cpp",
                                    ".h",
                                    ".xml",
                                ]:
                                    cmd.append(str(file_path))

                result = subprocess.run(cmd, capture_output=True, text=True, timeout=10)

                if result.returncode == 0:
                    output_lines = result.stdout.split("\n")
                    if len(output_lines) > max_total_lines:
                        output_lines = output_lines[:max_total_lines]
                        output_lines.append(
                            f"\n... (truncated, showing {max_total_lines} lines)"
                        )
                    res = "\n".join(output_lines)
                elif result.returncode == 1:
                    res = f"(No matches for: {pattern})"
                else:
                    res = f"(Grep error: {result.stderr})"
            except subprocess.TimeoutExpired:
                res = "(Grep timed out after 10s)"
            except Exception as e:
                res = f"(Error: {str(e)})"

            show_tool_output(res, chunk_label=translator_self._chunk_label)
            return res

        @tool
        def create_note(key: str, content: str, tags: str = "") -> str:
            """Create or update a note for tracking wrapper/binding decisions and patterns.

            Args:
                key: Unique identifier for the note
                content: The note content
                tags: Comma-separated tags for categorization (e.g., "pattern,tested,important")

            Returns:
                Confirmation message
            """
            show_tool_call(
                f"create_note(key={key}, content_length={len(content)}, tags={tags})",
                chunk_label=translator_self._chunk_label,
            )

            try:
                tag_list = [t.strip() for t in tags.split(",") if t.strip()]
                with _global_notes_lock:
                    _global_notes[key] = {
                        "content": content,
                        "tags": tag_list,
                        "created_at": time.time(),
                    }
                res = f"Note '{key}' created/updated successfully with {len(tag_list)} tags"
            except Exception as e:
                res = f"Error creating note: {str(e)}"

            show_tool_output(res, chunk_label=translator_self._chunk_label)
            return res

        @tool
        def search_notes(query: str, tag_filter: str = "") -> str:
            """Search notes by key or content, optionally filtering by tags.

            Args:
                query: Search query to match against note keys and content
                tag_filter: Comma-separated tags to filter by (all must match)

            Returns:
                List of matching notes
            """
            show_tool_call(
                f"search_notes(query={query}, tag_filter={tag_filter})",
                chunk_label=translator_self._chunk_label,
            )

            try:
                query_lower = query.lower()
                required_tags = set(
                    t.strip() for t in tag_filter.split(",") if t.strip()
                )

                matches = []
                with _global_notes_lock:
                    for key, note_data in _global_notes.items():
                        # Check if query matches key or content
                        key_match = query_lower in key.lower()
                        content_match = query_lower in note_data["content"].lower()

                        if not (key_match or content_match):
                            continue

                        # Check if all required tags are present
                        note_tags = set(note_data.get("tags", []))
                        if required_tags and not required_tags.issubset(note_tags):
                            continue

                        matches.append(
                            f"[{key}] Tags: {', '.join(note_tags) or 'none'}\n{note_data['content'][:200]}"
                        )

                if matches:
                    res = f"Found {len(matches)} matching notes:\n" + "\n---\n".join(
                        matches
                    )
                else:
                    res = "No matching notes found"
            except Exception as e:
                res = f"Error searching notes: {str(e)}"

            show_tool_output(res, chunk_label=translator_self._chunk_label)
            return res

        @tool
        def list_notes(tag_filter: str = "") -> str:
            """List all notes, optionally filtered by tags.

            Args:
                tag_filter: Comma-separated tags to filter by (any tag match)

            Returns:
                Summary of all notes
            """
            show_tool_call(
                f"list_notes(tag_filter={tag_filter})",
                chunk_label=translator_self._chunk_label,
            )

            try:
                with _global_notes_lock:
                    if not _global_notes:
                        res = "No notes found"
                    else:
                        filter_tags = set(
                            t.strip() for t in tag_filter.split(",") if t.strip()
                        )

                        items = []
                        for key, note_data in _global_notes.items():
                            note_tags = set(note_data.get("tags", []))

                            # If filter is specified, only include notes with at least one matching tag
                            if filter_tags and not note_tags.intersection(filter_tags):
                                continue

                            tag_str = ", ".join(note_tags) if note_tags else "no tags"
                            items.append(f"- {key} ({tag_str})")

                        if items:
                            res = f"Total notes: {len(items)}\n" + "\n".join(items)
                        else:
                            res = "No notes match the filter"
            except Exception as e:
                res = f"Error listing notes: {str(e)}"

            show_tool_output(res, chunk_label=translator_self._chunk_label)
            return res

        @tool
        def get_note(key: str) -> str:
            """Retrieve the full content of a specific note.

            Args:
                key: The note identifier

            Returns:
                Full note content or error message
            """
            show_tool_call(
                f"get_note(key={key})",
                chunk_label=translator_self._chunk_label,
            )

            try:
                with _global_notes_lock:
                    if key in _global_notes:
                        note_data = _global_notes[key]
                        tag_str = ", ".join(note_data.get("tags", [])) or "no tags"
                        res = f"[{key}] Tags: {tag_str}\n\n{note_data['content']}"
                    else:
                        res = f"Note '{key}' not found"
            except Exception as e:
                res = f"Error retrieving note: {str(e)}"

            show_tool_output(res, chunk_label=translator_self._chunk_label)
            return res

        @tool
        def delete_note(key: str) -> str:
            """Delete a note by key.

            Args:
                key: The note identifier to delete

            Returns:
                Confirmation message
            """
            show_tool_call(
                f"delete_note(key={key})",
                chunk_label=translator_self._chunk_label,
            )

            try:
                with _global_notes_lock:
                    if key in _global_notes:
                        del _global_notes[key]
                        res = f"Note '{key}' deleted successfully"
                    else:
                        res = f"Note '{key}' not found"
            except Exception as e:
                res = f"Error deleting note: {str(e)}"

            show_tool_output(res, chunk_label=translator_self._chunk_label)
            return res

        return [
            grep_headers,
            grep_targets,
            create_note,
            search_notes,
            list_notes,
            get_note,
            delete_note,
        ]

    def _create_reasoning_agent(self):
        """Create agent graph for reasoning phase."""
        return create_agent(
            self.model,
            self._tools,
            system_prompt=self.system_prompt,
        )

    def translate(self, prompt: str) -> Generate:
        # Add system message to history only once (as placeholder to avoid clutter)
        if not self._printed_system_prompt:
            if self.show_console_output:
                if not Translator._global_printed_system_prompt:
                    show_system_message(
                        self.system_prompt, chunk_label=self._chunk_label
                    )
                    Translator._global_printed_system_prompt = True
                else:
                    show_system_message("(omitted)", chunk_label=self._chunk_label)
            self._message_history.insert(0, SystemMessage("<system_message>"))
            self._printed_system_prompt = True

        # First freeform pass for reasoning with tools
        reasoning_prompt = (
            prompt
            + "\n\nThink through the problem carefully and reason step by step. You may call tools to help you plan your approach as needed. For now, focus on reasoning and tool use. We will ask you to generate the structured JSON response in the next step, so you can use this pass to gather information, analyze patterns, and plan your generation approach. Remember to think out loud and use the tools if you think you might need to look up information in the headers or your previous notes."
        )
        self._invoke_with_streaming(
            reasoning_prompt,
            model_override=self._agent_graph,  # type: ignore
            reasoning_timeout_seconds=self.reasoning_timeout_seconds,
        )

        # Second pass to explicitly request the structured JSON
        json_prompt = "Now, please provide the structured JSON response as specified in the system instructions. Output ONLY valid JSON."
        return self._generate_json_response(json_prompt)

    def regenerate_json(self) -> Generate:
        """Regenerate JSON from existing conversation context with reasoning pass. Used when retrying after build errors."""
        return self.translate(
            "Fix the previous response based on the feedback and try again."
        )

    def _generate_json_response(self, json_prompt: str) -> Generate:
        """Shared logic for generating and parsing JSON response.

        Args:
            json_prompt: The prompt to use for JSON generation

        Returns:
            Parsed Generate object
        """
        global _manual_json_parsing_lock
        global _use_manual_json_parsing_global

        # Try structured output first, fall back to manual JSON parsing
        try:
            # Check if we've already fallen back to manual parsing (thread-safe)
            with _manual_json_parsing_lock:
                if _use_manual_json_parsing_global:
                    raise RuntimeError("Forcing fallback to manual JSON parsing")

            structured_llm = self.model.with_structured_output(Generate)
            result = self._invoke(
                json_prompt,
                model_override=structured_llm,
            )
            # If we got a Generate object, return it
            if isinstance(result, Generate):
                return result
            # If we got a string, try to parse it as JSON
            if isinstance(result, str):
                parsed = self._parse_json_response(result)
                return parsed
            return result  # type: ignore
        except (AssertionError, ValidationError, Exception) as e:
            # Fallback: use plain model and manually parse JSON
            with _manual_json_parsing_lock:
                if not _use_manual_json_parsing_global:
                    _use_manual_json_parsing_global = True
                    if self.show_console_output:
                        show_warning(
                            f"Structured output failed {type(e).__name__}. Falling back to manual JSON parsing for all future structured responses. Error details: {str(e)}"
                        )

            json_response = self._invoke(json_prompt)
            if isinstance(json_response, str):
                return self._parse_json_response(json_response)
            elif isinstance(json_response, Generate):
                return json_response
            else:
                raise ValueError(
                    f"Failed to parse response as Generate object after retry: {type(json_response)}"
                )

    def _parse_json_response(self, response_text: str) -> Generate:
        """Parse JSON response string into Generate object.

        Handles extraction of JSON from markdown code blocks or plain JSON.
        """
        # Try to extract JSON from markdown code blocks first
        json_match = re.search(
            r"```(?:json)?\s*\n?(.*?)\n?```", response_text, re.DOTALL
        )
        if json_match:
            json_text = json_match.group(1).strip()
        else:
            # Look for raw JSON object
            json_match = re.search(r"\{.*\}", response_text, re.DOTALL)
            if json_match:
                json_text = json_match.group(0)
            else:
                json_text = response_text.strip()

        try:
            parsed = json.loads(json_text)
            return Generate(**parsed)
        except (json.JSONDecodeError, ValidationError, TypeError) as e:
            if self.show_console_output:
                show_warning(
                    f"Failed to parse JSON response: {e}\nRaw response: {response_text[:500]}"
                )
            # Add feedback to history and retry
            error_feedback = f"""CRITICAL: The previous JSON response could not be parsed.
Error: {type(e).__name__}: {str(e)}

Raw response received:
{response_text}

Please regenerate the JSON response, ensuring it is:
1. Valid JSON format (properly quoted strings, matched braces/brackets)
2. Matches the Generate schema with 'to_generate' array
3. Each item must have 'type' field and appropriate fields for that type
4. NO markdown code blocks - output ONLY the raw JSON object"""

            self.append_feedback(error_feedback)

            # Retry with feedback
            retry_prompt = "Please try again. Generate ONLY valid JSON matching the schema, with no markdown formatting or extra text."
            retry_response = self._invoke(retry_prompt)

            if isinstance(retry_response, str):
                # Recursive retry on the parsed response
                return self._parse_json_response(retry_response)
            elif isinstance(retry_response, Generate):
                return retry_response
            else:
                raise ValueError(
                    f"Failed to parse response as Generate object after retry: {type(retry_response)}"
                )

    def clear_history(self) -> None:
        """Clear the message history (e.g., between independent generation sessions)."""
        self._message_history = []

    def append_feedback(self, feedback: str) -> None:
        """Append system feedback to message history without invoking the model.

        Used for reporting build results or other feedback that should be part of
        the conversation context but doesn't require a new model response.
        """
        self._message_history.append(SystemMessage(feedback))
        if self.show_console_output:
            show_system_message(feedback, chunk_label=self._chunk_label)

    def append_tool_result(self, tool_name: str, success: bool, details: str) -> None:
        """Inject tool execution result into message history.

        Args:
            tool_name: Name of the tool (e.g., 'build', 'analyze')
            success: Whether the tool execution succeeded
            details: Tool output/result details (errors, logs, etc.)
        """
        status = "success" if success else "failure"
        output = details if details else ("Success" if success else "Failed")
        msg = f"{tool_name}: {status}\n{output}"
        self._message_history.append(SystemMessage(msg))

    def get_history_for_context(self) -> str:
        """Get formatted message history for analysis and context sizing.

        Returns a string representation of the message history without showing
        the full content to console, useful for understanding context usage.
        """
        lines = []
        for i, msg in enumerate(self._message_history):
            msg_type = msg.__class__.__name__
            content = msg.content if isinstance(msg.content, str) else str(msg.content)
            lines.append(f"{i}: [{msg_type}] {len(content)} bytes")
        return "\n".join(lines)

    def _invoke(
        self,
        user_prompt: str,
        model_override: Runnable[LanguageModelInput, _DictOrPydantic] | None = None,
        reasoning_timeout_seconds: float | None = None,
    ) -> str | _DictOrPydantic:
        """Invoke the model with exponential backoff retry logic for temporary errors."""
        last_exception: Optional[Exception] = None

        for attempt in range(MAX_RETRIES):
            try:
                return self._invoke_with_streaming(
                    user_prompt,
                    model_override,
                    reasoning_timeout_seconds,
                )
            except Exception as e:
                last_exception = e

                if not _is_temporary_error(e):
                    # Not a temporary error, raise immediately
                    raise

                if attempt < MAX_RETRIES - 1:
                    backoff_delay = _calculate_backoff_delay(attempt)
                    if self.show_console_output:
                        show_warning(
                            f"Temporary API error (attempt {attempt + 1}/{MAX_RETRIES}): {str(e)}\n"
                            f"Retrying in {backoff_delay:.1f} seconds..."
                        )
                    time.sleep(backoff_delay)
                else:
                    # All retries exhausted
                    if self.show_console_output:
                        show_warning(
                            f"All {MAX_RETRIES} retry attempts exhausted after temporary errors. "
                            f"Last error: {str(last_exception)}"
                        )
                    raise

        # Should not reach here, but re-raise last exception if we do
        if last_exception:
            raise last_exception
        raise RuntimeError("Unexpected error in _invoke retry loop")

    def _invoke_with_streaming(
        self,
        user_prompt: str,
        model_override: Runnable[LanguageModelInput, _DictOrPydantic] | None = None,
        reasoning_timeout_seconds: float | None = None,
    ) -> str | _DictOrPydantic:
        # Show user message immediately for real-time logging
        if self.show_console_output:
            show_user_message(user_prompt, chunk_label=self._chunk_label)

        # Build full message history: system message, accumulated history, then new user message
        self._maybe_summarize_history()
        messages: list[BaseMessage] = [
            SystemMessage(self.system_prompt),
            *[m for m in self._message_history if m.content != "<system_message>"],
            HumanMessage(user_prompt),
        ]

        # Always use streaming for consistency
        output = (
            show_ai_message_streaming(
                workers=self.stream_workers, chunk_label=self._chunk_label
            )
            if self.show_console_output
            else None
        )
        output_ready = False
        response_text = ""
        first_token_time = None
        timeout_end_time = None
        response = None

        for token in (model_override or self.model).stream(
            {"messages": messages}
            if isinstance(model_override, CompiledStateGraph)
            else messages  # type: ignore
        ):
            if isinstance(token, AIMessageChunk):
                # Start timeout timer after first token received
                if first_token_time is None:
                    first_token_time = time.time()
                    if reasoning_timeout_seconds:
                        timeout_end_time = first_token_time + reasoning_timeout_seconds

                # Check if timeout reached
                if timeout_end_time and time.time() > timeout_end_time:
                    response_text += "\n[TRUNCATED - reasoning timeout]"

                    # Add system message about the timeout
                    self._message_history.append(
                        SystemMessage(
                            f"⚠️ Reasoning pass timed out after {reasoning_timeout_seconds} seconds of token generation. "
                            f"Response was truncated. Proceeding with structured JSON generation with available context."
                        )
                    )

                    if self.show_console_output:
                        show_warning(
                            f"Reasoning timeout reached after {reasoning_timeout_seconds} seconds. Proceeding to JSON generation."
                        )
                    break

                response_text += str(token.content)
                if output is not None:
                    if not output_ready:
                        next(output)  # Start the generator
                        output_ready = True
                    output.send(str(token.content))
            elif (
                "tools" in token
            ):  # These are tool responses, but we have better logging including args for them inside, so skip here
                continue
            else:  # Final result
                response = token
                if output is not None:
                    if not output_ready:
                        next(output)  # Start the generator
                        output_ready = True
                    output.send(
                        json.dumps(getattr(response, "model_dump")())
                        if hasattr(response, "model_dump")
                        else response["model"]["messages"][-1].content
                        if "model" in response
                        else str(response)
                    )

        if output is not None:
            try:
                output.send(None)  # Signal end of stream
            except StopIteration:
                pass  # Generator should exit after receiving None

        if response is None:  # Message from streamed tokens (non-pydantic mode)
            response = AIMessage(response_text)

        ret = response
        if isinstance(response, AIMessage):
            response_text = str(response.content)
            ret = response_text
        elif hasattr(response, "model_dump_json"):
            response_text = getattr(response, "model_dump_json")()
        elif "model" in response:
            response_text = response["model"]["messages"][-1].content
        else:
            raise ValueError(
                "Unexpected response type from model: {}".format(type(response))
            )

        # Preserve this exchange in history for future calls
        self._message_history.append(HumanMessage(user_prompt))
        self._message_history.append(AIMessage(response_text))

        return ret

    def _maybe_truncate_history(self, limit: int | None = None) -> None:
        """Truncate history if it exceeds the specified limit (defaults to max_history_bytes)."""
        actual_limit = limit if limit is not None else self.max_history_bytes

        history_size = sum(
            len(msg.content.encode()) if isinstance(msg.content, str) else 0
            for msg in self._message_history
        )

        if history_size > actual_limit:
            if self.show_console_output:
                show_info(
                    f"Truncating conversation history from {history_size} bytes to fit within {actual_limit} bytes."
                )
            # Keep only the most recent messages that fit within the limit
            truncated_history = []
            current_size = 0
            for msg in reversed(self._message_history):
                msg_size = (
                    len(msg.content.encode()) if isinstance(msg.content, str) else 0
                )
                if current_size + msg_size <= actual_limit:
                    truncated_history.append(msg)
                    current_size += msg_size
                else:
                    break
            self._message_history = list(reversed(truncated_history))

    def _maybe_summarize_history(self) -> None:
        """Summarize history if it exceeds max_history_bytes."""
        history_size = sum(
            len(msg.content.encode()) if isinstance(msg.content, str) else 0
            for msg in self._message_history
        )

        if history_size > self.max_history_bytes:
            self._summarize_history(history_size)

    def _summarize_history(self, history_size, keep_messages: int = 3) -> None:
        """Summarize the conversation and replace history with summary."""
        if self.show_console_output:
            show_info(
                f"Summarizing conversation history ({len(self._message_history)} -> {keep_messages} + 2 messages) due to size limit ({history_size} > {self.max_history_bytes} bytes)"
            )

        # Build conversation text from full history (not truncated)
        conversation_lines = []
        for msg in self._message_history:
            content = msg.content if isinstance(msg.content, str) else str(msg.content)
            conversation_lines.append(f"{msg.__class__.__name__}:\n{content}")

        conversation_text = "\n\n".join(conversation_lines)

        # Truncate to avoid token limits
        if len(conversation_text) > self.max_history_bytes:
            conversation_text = conversation_text[-self.max_history_bytes :]

        # Create summarization request
        summary_prompt = SUMMARIZE_PROMPT.format(history=conversation_text)

        try:
            # Use summarization system message instead of code generation prompt
            summarization_system_msg = "You are an expert at summarizing technical conversations. Provide a concise, accurate summary of the following conversation about C++ code generation for Godot bindings. Focus on key decisions, patterns, successes, and unresolved issues. The summary should be clear and informative for someone who has not seen the full conversation."
            summary_response = self.model.invoke(
                [SystemMessage(summarization_system_msg), HumanMessage(summary_prompt)]
            )
            summary_text = str(summary_response.content)

            # Replace history with summary while keeping original system message and recent messages
            kept_messages = (
                self._message_history[-keep_messages:]
                if len(self._message_history) > keep_messages
                else self._message_history
            )
            self._message_history = [
                SystemMessage(self.system_prompt),
                SystemMessage(f"Summary of prior conversation:\n{summary_text}"),
                *kept_messages,
            ]

            # If history still exceeds max size after summarization, reduce kept_messages
            history_size = sum(
                len(msg.content.encode()) if isinstance(msg.content, str) else 0
                for msg in self._message_history
            )

            if self.show_console_output:
                show_info(
                    f"History summarized from {len(conversation_text)} to {history_size} (summary: {len(summary_text)}) characters: {summary_text[:256]}..."
                )
            if history_size > self.max_history_bytes and keep_messages > 0:
                show_warning(
                    f"History still exceeds max size after summarization ({history_size} bytes). Reducing kept messages and summarizing again."
                )
                self._summarize_history(
                    history_size, keep_messages=max(0, keep_messages - 2)
                )

        except Exception as e:
            show_warning(f"Failed to summarize history: {e}")
