FROM python:3.13-slim

# Install all dependencies in one RUN to reduce layers
RUN apt-get update && apt-get install -y --no-install-recommends \
    git curl wget ca-certificates unzip zip \
    cmake ninja-build pkg-config scons sccache \
    gcc g++ make autoconf automake libtool bison flex nasm yasm \
    xz-utils libssl-dev libffi-dev libxml2-dev zlib1g-dev libbz2-dev \
    libreadline-dev libsqlite3-dev libncursesw5-dev tk-dev libgdbm-dev libc6-dev \
    && pip install --no-cache-dir uv \
    && rm -rf /var/lib/apt/lists/*

# Download Godot once
RUN GODOT_URL=$(curl -s https://api.github.com/repos/godotengine/godot/releases | grep -m 1 '"browser_download_url".*linux.x86_64.zip' | sed 's/.*"browser_download_url": "//;s/".*//') && \
    GODOT_URL=${GODOT_URL:-https://github.com/godotengine/godot/releases/download/4.6.2-stable/Godot_v4.6.2-stable_linux.x86_64.zip} && \
    GODOT_FILENAME=$(echo "$GODOT_URL" | sed 's/.*\///') && \
    GODOT_DIR=$(echo "$GODOT_FILENAME" | sed 's/.zip$//') && \
    mkdir -p /tmp/godot && cd /tmp/godot && \
    wget "$GODOT_URL" -O "$GODOT_FILENAME" && \
    unzip -q "$GODOT_FILENAME" && \
    mv "$GODOT_DIR" /usr/local/bin/godot && \
    chmod +x /usr/local/bin/godot && \
    rm -rf /tmp/godot && \
    godot --version

WORKDIR /app

COPY pyproject.toml uv.lock ./

# Install Python dependencies
RUN uv pip install --no-cache-dir --system -e .

COPY . .

# Create non-root user
RUN groupadd -g 1000 appuser && \
    useradd -m -u 1000 -g 1000 appuser && \
    chown -R appuser:appuser /app

USER appuser

#ENV PYTHONUNBUFFERED=1 \
#    PYTHONDONTWRITEBYTECODE=1 \
#    GODOT_VERSION=system \
#    OPENAI_BASE_URL="http://localhost:8080/v1" \
#    OPENAI_API_KEY="none" \
#    WRAPPER_MODEL="gpt-4.1"

ENTRYPOINT ["uv", "run"]
CMD ["sh", "-c", "uv run src/main.py sqlite3.gd/vcpkg/installed/x64-linux/include/sqlite3.h -o sqlite3.gd/ --workers 1 --model ${WRAPPER_MODEL:-big-pickle}"]
