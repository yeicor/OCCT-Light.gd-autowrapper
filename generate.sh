#!/usr/bin/env bash
# generate.sh - Run the deterministic autowrapper to generate godot-cpp bindings
#
# Usage: ./generate.sh
#   Processes all OCCT-Light headers and generates Godot wrapper classes
set -e

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
cd "$SCRIPT_DIR"

# Output to parent OCCT-Light.gd project
OUTPUT_DIR="${SCRIPT_DIR}/.."

# OCCT-Light headers to process
HEADERS_DIR="${SCRIPT_DIR}/../OCCT-Light/include/occtl"

echo "=== OCCT-Light.gd Autowrapper (Deterministic) ==="
echo "Headers: ${HEADERS_DIR}"
echo "Output:  ${OUTPUT_DIR}"
echo ""

# Ensure uv is available
if ! command -v uv &>/dev/null; then
    echo "Installing uv package manager..."
    curl -LsSf https://astral.sh/uv/install.sh | sh
    export PATH="$HOME/.cargo/bin:$HOME/.local/bin:$PATH"
fi

exec uv run src/main.py "${HEADERS_DIR}" -o "${OUTPUT_DIR}" "$@"
