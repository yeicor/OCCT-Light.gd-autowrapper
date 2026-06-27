import re
from typing import Generator

from rich.console import Console, Group
from rich.panel import Panel
from rich.progress import TimeElapsedColumn, TimeRemainingColumn
from rich.syntax import Syntax
from rich.text import Text

_base_console = Console()
console = Console(width=max(80, _base_console.width - 2))


def _show_message_with_fence(text: str, title: str, border_style: str) -> None:
    cleaned_text = text.replace("\\n", "\n")
    fence_pattern = re.compile(r"```([a-zA-Z0-9_+\-]*)\n(.*?)\n```", re.DOTALL)
    matches = list(fence_pattern.finditer(cleaned_text))

    if not matches:
        stripped = cleaned_text.strip()
        if stripped.startswith("{") and stripped.endswith("}"):
            console.print(
                Panel(
                    Syntax(
                        cleaned_text.replace("\\n", "\n" + " " * 15),
                        "json",
                        theme="ansi_dark",
                        word_wrap=True,
                    ),
                    title="```json",
                    title_align="left",
                    border_style=border_style,
                )
            )
            return

        console.print(
            Panel(
                Text(cleaned_text),
                title=title,
                border_style=border_style,
            )
        )
        return

    contents = []
    last_end = 0

    for match in matches:
        before = cleaned_text[last_end : match.start()]
        if before.strip():
            contents.append(Text(before))

        lang = match.group(1) or "text"
        code = match.group(2)

        if lang == "json":  # Clean \n for printing
            code = code.replace("\\n", "\n" + " " * 15)

        contents.append(
            Panel(
                Syntax(
                    code,
                    lang,
                    theme="ansi_dark",
                    word_wrap=True,
                ),
                title=f"```{lang}",
                title_align="left",
                border_style=border_style,
            )
        )

        last_end = match.end()

    after = cleaned_text[last_end:]
    if after.strip():
        contents.append(Text(after))

    console.print(
        Panel(
            Group(*contents),
            title=title,
            border_style=border_style,
        )
    )


def show_system_message(prompt: str, chunk_label: str | None = None) -> None:
    title = "System Message"
    if chunk_label:
        title = f"System Message [{chunk_label}]"
    _show_message_with_fence(prompt, title, "cyan")


def show_user_message(prompt: str, chunk_label: str | None = None) -> None:
    title = "User Message"
    if chunk_label:
        title = f"User Message [{chunk_label}]"
    _show_message_with_fence(prompt, title, "green")


def show_tool_call(prompt: str, chunk_label: str | None = None) -> None:
    title = "Tool Call"
    if chunk_label:
        title = f"Tool Call [{chunk_label}]"
    _show_message_with_fence(prompt, title, "blue")


def show_tool_output(prompt: str, chunk_label: str | None = None) -> None:
    title = "Tool Output"
    if chunk_label:
        title = f"Tool Output [{chunk_label}]"
    _show_message_with_fence(prompt, title, "blue")


def show_ai_message(prompt: str, chunk_label: str | None = None) -> None:
    title = "AI Message"
    if chunk_label:
        title = f"AI Message [{chunk_label}]"
    _show_message_with_fence(prompt, title, "magenta")


def show_ai_message_streaming(
    workers: int = 1, chunk_label: str | None = None
) -> Generator[None, str | None, None]:
    """Show AI message in streaming mode."""
    from rich.live import Live
    from rich.text import Text

    live_text = Text("")
    title = "AI Message"
    if chunk_label:
        title = f"AI Message [{chunk_label}]"
    live_panel = Panel(live_text, title=title, border_style="magenta")
    raw_text = ""
    with Live(live_panel, console=console, transient=True):
        while True:
            chunk = yield  # Receive token-by-token updates
            if chunk is None:  # End of stream
                break
            raw_text += chunk
            live_text.append(chunk)
            # Keep only the last N lines matching the console height
            live_text_lines = live_text.plain.splitlines()
            max_lines = max(  # Account for panel borders, title, etc.
                1, (console.height - 1) // workers - 2
            )
            if len(live_text_lines) > max_lines:
                live_text = Text("[...]" + "\n".join(live_text_lines[-max_lines:]))
                live_panel.renderable = live_text
            live_panel.height = min(
                len(live_text_lines) + 2, console.height - 2
            )  # Dynamic height
    show_ai_message(
        raw_text, chunk_label=chunk_label
    )  # Proper formatting after streaming


def show_info(message: str) -> None:
    console.print(f"[cyan]{message}[/cyan]")


def show_warning(message: str) -> None:
    console.print(f"[yellow]{message}[/yellow]")


def show_error(message: str) -> None:
    console.print(f"[red]{message}[/red]")


def show_build_failure(
    attempt: int, max_attempts: int, errors: str, chunk_label: str | None = None
) -> None:
    """Show build failure with extracted errors as system feedback."""
    label_suffix = f" [{chunk_label}]" if chunk_label else ""
    if errors:
        console.print(
            Panel(
                errors,
                title=f"Build Errors (attempt {attempt}/{max_attempts}){label_suffix}",
                border_style="yellow",
            )
        )
    else:
        console.print(
            f"[yellow]Build failed (attempt {attempt}/{max_attempts}){label_suffix}[/yellow]"
        )


def show_build_success(chunk_label: str | None = None) -> None:
    """Show build success."""
    title = "Build Success"
    if chunk_label:
        title = f"Build Success [{chunk_label}]"
    console.print(Panel("Build succeeded!", title=title, border_style="green"))


def progress_bar():
    from rich.progress import BarColumn, Progress, SpinnerColumn, TextColumn

    return Progress(
        SpinnerColumn(),
        TextColumn("[progress.description]{task.description}"),
        BarColumn(bar_width=None),
        TextColumn("[progress.percentage]{task.percentage:>3.0f}%"),
        TimeElapsedColumn(),
        TimeRemainingColumn(),
        console=console,
    )
