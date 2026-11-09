#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
echo "Building multiplayer server..."
g++ -std=c++17 -pthread multiplayer/src/server.cpp -o multiplayer/echohearts-server
echo "Starting multiplayer server on :7777"
./multiplayer/echohearts-server 7777 &
MP_PID=$!
trap "kill $MP_PID || true" EXIT
echo "Starting web server on :8080"
python3 web/server.py 8080
