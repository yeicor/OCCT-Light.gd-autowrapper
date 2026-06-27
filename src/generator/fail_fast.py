import os
import sys
import traceback
from typing import NoReturn


def fail_fast(exception: Exception) -> NoReturn:
    """Terminate immediately with exception details, no cleanup or output buffering.

    Uses os._exit() for instant termination, bypassing normal shutdown procedures.
    This ensures Ctrl+C and errors are truly instant.
    """
    # Print full traceback to stderr immediately
    traceback.print_exception(
        type(exception), exception, exception.__traceback__, file=sys.stderr
    )
    sys.stderr.flush()

    # Exit immediately without cleanup
    os._exit(1)
