#!/usr/bin/env bash
# generate.sh - Run the autowrapper to generate godot-cpp bindings for OCCT-Light headers
#
# Usage: ./generate.sh [--workers N] [--model MODEL] [--max-chunk-bytes N]
#        ./generate.sh --include "occtl_status|occtl_uid"  # process only matching chunks
#        ./generate.sh --include "occtl_runtime_version"    # single function test
#
# Environment variables:
#   OPENAI_BASE_URL  - LLM server URL (default: http://127.0.0.1:8081/v1)
#   OPENAI_API_KEY   - API key (default: none)
#   WRAPPER_MODEL    - Model name (default: unsloth/Qwen3.6-35B-A3B-MTP-GGUF:UD-Q6_K)
set -e

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
cd "$SCRIPT_DIR"

# Default LLM configuration (local llama.cpp server)
export OPENAI_BASE_URL="${OPENAI_BASE_URL:-http://127.0.0.1:8081/v1}"
export OPENAI_API_KEY="${OPENAI_API_KEY:-none}"
export WRAPPER_MODEL="${WRAPPER_MODEL:-unsloth/Qwen3.6-35B-A3B-MTP-GGUF:UD-Q6_K}"

# Output to parent OCCT-Light.gd project (the target project)
OUTPUT_DIR="${SCRIPT_DIR}/.."

# OCCT-Light headers to process
HEADERS_DIR="${SCRIPT_DIR}/../OCCT-Light/include/occtl"

echo "=== OCCT-Light.gd Autowrapper ==="
echo "LLM:      ${WRAPPER_MODEL}"
echo "Server:   ${OPENAI_BASE_URL}"
echo "Output:   ${OUTPUT_DIR}"
echo "Workers:  ${WORKERS:-1}"
echo ""

# Process all OCCT-Light public headers (excluding viz and umbrella) in a single invocation
HEADER_GLOBS=()
for h in "${HEADERS_DIR}"/occtl*.h; do
    base=$(basename "$h")
    case "$base" in
        occtl_viz.h|occtl.h) ;;  # Skip viz and umbrella header
        *) HEADER_GLOBS+=("$h") ;;
    esac
done

exec uv run src/main.py \
    "${HEADER_GLOBS[@]}" \
    -o "$OUTPUT_DIR" \
    --workers "${WORKERS:-3}" \
    --model "$WRAPPER_MODEL" \
    --chunk-retry-limit "${CHUNK_RETRY_LIMIT:-2}" \
    --max-chunk-bytes "${MAX_CHUNK_BYTES:-4000}" \
    --reasoning-timeout "${REASONING_TIMEOUT:-45}" \
    --max-output-tokens "${MAX_OUTPUT_TOKENS:-3500}" \
    "$@"
